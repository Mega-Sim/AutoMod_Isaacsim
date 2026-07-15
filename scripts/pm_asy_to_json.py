#!/usr/bin/env python3
"""Convert an AutoMod AGVS ``pm.asy`` layout into Isaac Sim friendly JSON.

The converter keeps the exact AutoMod source geometry while also producing a
directed graph in meters.  AutoMod control points are preserved separately from
operational station candidates so routing-only points are not mistaken for
load/unload stations.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import math
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, Iterable, List, Mapping, MutableMapping, Optional, Sequence, Tuple


Point = Tuple[float, float]
EPSILON = 1e-9
AUTOMOD_UNBOUNDED_CAPACITY = 2_147_483_647

STATION_RULES: Sequence[Tuple[re.Pattern[str], str]] = (
    (re.compile(r"^cp_A\d+", re.IGNORECASE), "equipment"),
    (re.compile(r"^cp_Can_", re.IGNORECASE), "equipment"),
    (re.compile(r"^cp_Cap_", re.IGNORECASE), "equipment"),
    (re.compile(r"^cp_UTB_", re.IGNORECASE), "utb"),
    (re.compile(r"^cp_Park", re.IGNORECASE), "park"),
    (re.compile(r"^cp_EVL_Home_", re.IGNORECASE), "vehicle_home"),
    # Deliberately case-sensitive: cp_Out_* are operational outputs in the SDI
    # model, while cp_out_* are high_out routing control points.
    (re.compile(r"^cp_Out_"), "out_station"),
)

ROUTING_TYPES = {
    "avoid",
    "dummy",
    "steer",
    "high_in",
    "high_out",
    "reroute",
    "route_check",
}


def _number(value: str) -> Any:
    """Return an int/float when possible, otherwise preserve the token."""
    try:
        number = float(value)
    except ValueError:
        return value
    if number.is_integer() and not any(ch in value.lower() for ch in (".", "e")):
        return int(number)
    return number


def _value_after(tokens: Sequence[str], key: str, default: Any = None) -> Any:
    try:
        return tokens[tokens.index(key) + 1]
    except (ValueError, IndexError):
        return default


def _float_after(tokens: Sequence[str], key: str, default: Optional[float] = None) -> Optional[float]:
    value = _value_after(tokens, key)
    return float(value) if value is not None else default


def _point_mm(point: Point) -> List[float]:
    return [point[0], point[1], 0.0]


def _point_m(point: Point) -> List[float]:
    return [point[0] / 1000.0, point[1] / 1000.0, 0.0]


def _distance(a: Point, b: Point) -> float:
    return math.hypot(b[0] - a[0], b[1] - a[1])


def _rotate(point: Point, center: Point, radians: float) -> Point:
    dx = point[0] - center[0]
    dy = point[1] - center[1]
    cos_a = math.cos(radians)
    sin_a = math.sin(radians)
    return (
        center[0] + dx * cos_a - dy * sin_a,
        center[1] + dx * sin_a + dy * cos_a,
    )


def _natural_key(text: str) -> List[Any]:
    return [int(piece) if piece.isdigit() else piece.lower() for piece in re.split(r"(\d+)", text)]


def _top_level_blocks(lines: Sequence[str]) -> Iterable[Tuple[str, List[str]]]:
    """Yield top-level AutoMod records with their indented continuation lines."""
    index = 0
    while index < len(lines):
        line = lines[index].rstrip()
        if not line.strip():
            index += 1
            continue
        if line[0].isspace():
            # A continuation without a recognized top-level record is retained
            # by the caller as an unparsed record.
            yield "", [line]
            index += 1
            continue
        if line.startswith("AGVVEHSEG "):
            # AutoMod display templates contain unindented numeric payload lines
            # followed by an unindented ``end`` marker.  They are still part of
            # AGVVEHSEG and must not be mistaken for top-level records.
            block = [line]
            index += 1
            while index < len(lines) and not lines[index].startswith("AGVSVEH "):
                block.append(lines[index].rstrip())
                index += 1
            yield "AGVVEHSEG", block
            continue
        block = [line]
        index += 1
        while index < len(lines) and (not lines[index].strip() or lines[index][0].isspace()):
            block.append(lines[index].rstrip())
            index += 1
        yield line.split()[0], block


def _parse_path_type(line: str) -> Dict[str, Any]:
    tokens = line.split()
    name = str(_value_after(tokens, "name"))
    direction = "reverse" if "reverse" in tokens else "normal"
    one_way = "one" in tokens and "two" not in tokens
    speed = None
    if "vel" in tokens:
        index = tokens.index("vel")
        if index + 2 < len(tokens):
            speed = float(tokens[index + 2])
    return {
        "id": name,
        "one_way": one_way,
        "source_direction": direction,
        "attach": "rigid" if "rigid" in tokens else None,
        "automod_color_index": _number(str(_value_after(tokens, "color", "-1"))),
        "navigation_value": _number(str(_value_after(tokens, "nav", "1"))),
        "speed_limit_mps": speed,
        "raw_tokens": tokens[1:],
    }


def _parse_gpath(line: str, path_types: Mapping[str, Mapping[str, Any]]) -> Dict[str, Any]:
    tokens = line.split()
    path_id = str(_value_after(tokens, "name"))
    path_type = str(_value_after(tokens, "type"))
    begin = (float(_value_after(tokens, "begx")), float(_value_after(tokens, "begy")))
    explicit: Dict[str, Any] = {}
    for key in ("color", "nav", "upz"):
        value = _value_after(tokens, key)
        if value is not None:
            explicit[key] = _number(str(value))

    speed_limit = None
    speed_profile = None
    if "vel" in tokens:
        vel_index = tokens.index("vel")
        if vel_index + 2 < len(tokens):
            speed_profile = _number(tokens[vel_index + 1])
            speed_limit = float(tokens[vel_index + 2])
            explicit["vel"] = {
                "profile_index": speed_profile,
                "value_mps": speed_limit,
                "raw_tokens": tokens[vel_index + 1 : vel_index + 5],
            }

    inherited = dict(path_types.get(path_type, {}))
    color = explicit.get("color", inherited.get("automod_color_index"))
    nav = explicit.get("nav", inherited.get("navigation_value"))
    effective_speed = speed_limit if speed_limit is not None else inherited.get("speed_limit_mps")

    if "endx" in tokens:
        kind = "line"
        end = (float(_value_after(tokens, "endx")), float(_value_after(tokens, "endy")))
        center = None
        radius = None
        sweep_degrees = None
        sweep_radians = None
        length = _distance(begin, end)
    else:
        kind = "arc"
        center = (float(_value_after(tokens, "cenx")), float(_value_after(tokens, "ceny")))
        raw_angle = float(_value_after(tokens, "angle"))
        sweep_degrees = raw_angle / 10.0
        sweep_radians = math.radians(sweep_degrees)
        radius = _distance(center, begin)
        end = _rotate(begin, center, sweep_radians)
        length = radius * abs(sweep_radians)

    if length <= EPSILON:
        raise ValueError(f"GPATH {path_id} has zero length")

    return {
        "id": path_id,
        "path_type": path_type,
        "geometry_type": kind,
        "begin": begin,
        "end": end,
        "center": center,
        "radius_mm": radius,
        "sweep_degrees": sweep_degrees,
        "sweep_radians": sweep_radians,
        "length_mm": length,
        "direction": "reverse" if inherited.get("source_direction") == "reverse" else "forward",
        "source_direction": inherited.get("source_direction", "normal"),
        "one_way": bool(inherited.get("one_way", True)),
        "automod_color_index": color,
        "navigation_value": nav,
        "speed_limit_mps": effective_speed,
        "up_vector": [0.0, 0.0, float(explicit.get("upz", 1.0))],
        "explicit_attributes": explicit,
        "effective_attributes": {
            "automod_color_index": color,
            "navigation_value": nav,
            "speed_limit_mps": effective_speed,
        },
    }


def _parse_control_point_type(line: str) -> Dict[str, Any]:
    tokens = line.split()
    name = str(_value_after(tokens, "name"))
    result: Dict[str, Any] = {
        "id": name,
        "parent_type": _value_after(tokens, "type"),
        "raw_tokens": tokens[1:],
    }
    for key in ("cap", "limit", "scale", "color", "nrot", "nscale", "align"):
        value = _value_after(tokens, key)
        if value is not None:
            result[key] = _number(str(value))
    if "release" in tokens:
        index = tokens.index("release")
        if index + 3 < len(tokens) and tokens[index + 1] == "distance":
            result["release_distance"] = {
                "value": _number(tokens[index + 2]),
                "unit": tokens[index + 3],
            }
    return result


def _resolve_type_attributes(
    name: str,
    types: Mapping[str, Mapping[str, Any]],
    trail: Optional[Tuple[str, ...]] = None,
) -> Dict[str, Any]:
    trail = trail or ()
    if name in trail:
        raise ValueError(f"CPOINTTYPE inheritance cycle: {' -> '.join(trail + (name,))}")
    current = dict(types.get(name, {}))
    parent = current.get("parent_type")
    resolved: Dict[str, Any] = {}
    if parent:
        resolved.update(_resolve_type_attributes(str(parent), types, trail + (name,)))
    for key, value in current.items():
        if key not in {"id", "parent_type", "raw_tokens"}:
            resolved[key] = value
    return resolved


def _parse_control_point(line: str, types: Mapping[str, Mapping[str, Any]]) -> Dict[str, Any]:
    tokens = line.split()
    name = str(_value_after(tokens, "name"))
    point_type = str(_value_after(tokens, "type", "DefaultControlPoint"))
    try:
        at_index = tokens.index("at")
        path_id = tokens[at_index + 1]
        distance_mm = float(tokens[at_index + 2])
    except (ValueError, IndexError) as exc:
        raise ValueError(f"CPOINT {name} has no valid 'at PATH DISTANCE' clause") from exc

    explicit: Dict[str, Any] = {}
    for key in ("cap", "color", "scale", "nrot", "nscale"):
        value = _value_after(tokens, key)
        if value is not None and tokens.index(key) < at_index:
            explicit[key] = _number(str(value))

    effective = _resolve_type_attributes(point_type, types)
    effective.update(explicit)
    capacity = effective.get("cap")
    return {
        "id": name,
        "name": name,
        "cpoint_type": point_type,
        "source_path_id": path_id,
        "distance_from_path_start_mm": distance_mm,
        "explicit_attributes": explicit,
        "effective_attributes": effective,
        "capacity": {
            "value": capacity,
            "is_unbounded": isinstance(capacity, (int, float)) and capacity >= AUTOMOD_UNBOUNDED_CAPACITY,
        },
        "automod_color_index": effective.get("color"),
    }


def _parse_name_list(block: Sequence[str]) -> Tuple[str, List[str]]:
    tokens = " ".join(line.strip() for line in block if line.strip()).split()
    name = str(_value_after(tokens, "name"))
    items = [tokens[index + 1] for index, token in enumerate(tokens[:-1]) if token == "item"]
    return name, items


def _parse_agvsdef(block: Sequence[str]) -> Dict[str, Any]:
    header = block[0].split()
    result: Dict[str, Any] = {
        "section_path": _value_after(header, "secname"),
        "control_point": _value_after(header, "name"),
        "user_id": _number(str(_value_after(header, "UserId", "0"))),
        "raw_header_tokens": header[1:],
    }
    for raw_line in block[1:]:
        tokens = raw_line.strip().split()
        if not tokens:
            continue
        if tokens[0] == "NEXTPATH":
            result["next_path"] = _value_after(tokens, "name")
            result["next_path_type"] = _value_after(tokens, "type")
        elif tokens[0] == "NEXTCP":
            result["next_control_point"] = _value_after(tokens, "name")
            result["next_control_point_type"] = _value_after(tokens, "type")
        elif tokens[0] == "ALTERNATE":
            result["alternate"] = tokens[1:]
    return result


def _parse_vehicle_segment(block: Sequence[str]) -> Dict[str, Any]:
    header = block[0].split()
    segment: Dict[str, Any] = {
        "id": _value_after(header, "name"),
        "capacity": _number(str(_value_after(header, "cap", "0"))),
        "pickup_seconds": float(_value_after(header, "pickup", "0")),
        "setdown_seconds": float(_value_after(header, "setdown", "0")),
    }
    pap: Optional[Dict[str, Any]] = None
    for raw_line in block[1:]:
        tokens = raw_line.strip().split()
        if not tokens:
            continue
        if tokens[0] in {"figcurspeed", "figmaxspeed"} and len(tokens) > 1:
            segment[tokens[0]] = _number(tokens[1])
        elif tokens[0] == "display":
            display: Dict[str, Any] = {}
            for key in ("begx", "begy", "begz", "endx", "endy", "endz", "scx", "scy", "scz"):
                value = _value_after(tokens, key)
                if value is not None:
                    display[key] = _number(str(value))
            segment["display"] = display
            if all(key in display for key in ("scx", "scy", "scz")):
                segment["source_display_scale_mm"] = [display["scx"], display["scy"], display["scz"]]
                segment["collision_extent_candidate_m"] = [
                    float(display["scx"]) / 1000.0,
                    float(display["scy"]) / 1000.0,
                    float(display["scz"]) / 1000.0,
                ]
                segment["interpretation_warning"] = (
                    "AutoMod display scale is preserved as a collision-extent candidate, not asserted as an exact collider."
                )
        elif tokens[0] == "PAP" and len(tokens) > 2:
            pap = {"index": _number(tokens[2])}
        elif tokens[0] == "trx" and pap is not None:
            pap["translation_mm"] = [
                float(_value_after(tokens, "trx", "0")),
                float(_value_after(tokens, "try", "0")),
                float(_value_after(tokens, "trz", "0")),
            ]
    if pap is not None:
        segment["pickup_attachment_point"] = pap
    return segment


def _parse_vehicle(block: Sequence[str]) -> Dict[str, Any]:
    header = block[0].split()
    vehicle: Dict[str, Any] = {
        "id": _value_after(header, "type"),
        "vehicle_count": int(_value_after(header, "numveh", "0")),
        "segments": [],
        "motion_profiles": {},
    }
    current_load: Optional[str] = None
    motion_keys = {
        "accel",
        "decel",
        "vel",
        "crvvel",
        "sprvel",
        "rvel",
        "rcrvvel",
        "rsprvel",
        "crabvel",
        "rotate",
        "brakedist",
        "stopdist",
    }
    for raw_line in block[1:]:
        tokens = raw_line.strip().split()
        if not tokens:
            continue
        if tokens[0] == "vehsegs":
            vehicle["segments"].extend(
                tokens[index + 1] for index, token in enumerate(tokens[:-1]) if token == "item"
            )
        elif tokens[0] == "start" and len(tokens) > 1:
            vehicle["start"] = tokens[1]
        elif tokens[0] == "Stacking":
            vehicle["stacking"] = tokens[1:]
        elif tokens[0] == "picpos":
            vehicle["picture_position"] = tokens[1:]
        elif tokens[0] == "load" and len(tokens) > 1:
            current_load = tokens[1]
            vehicle["motion_profiles"].setdefault(current_load, {})
        elif tokens[0] in motion_keys and current_load is not None and len(tokens) >= 3:
            vehicle["motion_profiles"][current_load][tokens[0]] = {
                "profile_index": _number(tokens[1]),
                "value": float(tokens[2]),
                "units": tokens[3:],
            }
    return vehicle


def _point_at_distance(path: Mapping[str, Any], distance_mm: float) -> Point:
    length = float(path["length_mm"])
    distance_mm = min(max(distance_mm, 0.0), length)
    begin: Point = path["begin"]
    if path["geometry_type"] == "line":
        end: Point = path["end"]
        ratio = distance_mm / length
        return (
            begin[0] + (end[0] - begin[0]) * ratio,
            begin[1] + (end[1] - begin[1]) * ratio,
        )
    radius = float(path["radius_mm"])
    sweep = float(path["sweep_radians"])
    partial = math.copysign(distance_mm / radius, sweep)
    return _rotate(begin, path["center"], partial)


def _tangent_yaw(path: Mapping[str, Any], distance_mm: float) -> float:
    if path["geometry_type"] == "line":
        begin: Point = path["begin"]
        end: Point = path["end"]
        yaw = math.atan2(end[1] - begin[1], end[0] - begin[0])
    else:
        point = _point_at_distance(path, distance_mm)
        center: Point = path["center"]
        radial_yaw = math.atan2(point[1] - center[1], point[0] - center[0])
        yaw = radial_yaw + math.copysign(math.pi / 2.0, float(path["sweep_radians"]))
    if path["direction"] == "reverse":
        yaw += math.pi
    return math.atan2(math.sin(yaw), math.cos(yaw))


def _sample_interval(
    path: Mapping[str, Any],
    start_mm: float,
    end_mm: float,
    chord_error_mm: float,
) -> List[Point]:
    interval = max(0.0, end_mm - start_mm)
    if interval <= EPSILON:
        return [_point_at_distance(path, start_mm)]
    if path["geometry_type"] == "line":
        return [_point_at_distance(path, start_mm), _point_at_distance(path, end_mm)]

    radius = float(path["radius_mm"])
    interval_angle = interval / radius
    if chord_error_mm <= 0.0 or chord_error_mm >= radius:
        max_step = math.radians(5.0)
    else:
        max_step = 2.0 * math.acos(max(-1.0, min(1.0, 1.0 - chord_error_mm / radius)))
    segment_count = max(1, int(math.ceil(interval_angle / max(max_step, EPSILON))))
    return [
        _point_at_distance(path, start_mm + interval * index / segment_count)
        for index in range(segment_count + 1)
    ]


@dataclass
class _NodeBuilder:
    tolerance_mm: float

    def __post_init__(self) -> None:
        self.nodes: List[Dict[str, Any]] = []
        self._grid: Dict[Tuple[int, int], List[int]] = {}

    def _cell(self, point: Point) -> Tuple[int, int]:
        size = max(self.tolerance_mm, EPSILON)
        return (math.floor(point[0] / size), math.floor(point[1] / size))

    def add_endpoint(self, point: Point) -> str:
        cell_x, cell_y = self._cell(point)
        best_index: Optional[int] = None
        best_distance = math.inf
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                for index in self._grid.get((cell_x + dx, cell_y + dy), []):
                    node_point = tuple(self.nodes[index]["_position"])  # type: ignore[arg-type]
                    distance = _distance(point, node_point)
                    if distance <= self.tolerance_mm and distance < best_distance:
                        best_index = index
                        best_distance = distance
        if best_index is not None:
            return self.nodes[best_index]["id"]
        return self.add_internal(point)

    def add_internal(self, point: Point) -> str:
        node_id = f"node_{len(self.nodes) + 1:06d}"
        index = len(self.nodes)
        self.nodes.append(
            {
                "id": node_id,
                "_position": point,
                "position_mm": _point_mm(point),
                "position_m": _point_m(point),
                "source_path_ids": [],
                "control_point_ids": [],
                "station_ids": [],
            }
        )
        self._grid.setdefault(self._cell(point), []).append(index)
        return node_id

    def get(self, node_id: str) -> Dict[str, Any]:
        return self.nodes[int(node_id.rsplit("_", 1)[1]) - 1]

    def finalize(self) -> List[Dict[str, Any]]:
        result: List[Dict[str, Any]] = []
        for node in self.nodes:
            clean = {key: value for key, value in node.items() if key != "_position"}
            for key in ("source_path_ids", "control_point_ids", "station_ids"):
                clean[key] = sorted(set(clean[key]), key=_natural_key)
            result.append(clean)
        return result


def _classify_control_point(point: Mapping[str, Any]) -> Tuple[str, Optional[str], str]:
    name = str(point["name"])
    for pattern, station_type in STATION_RULES:
        if pattern.search(name):
            return "station", station_type, f"name:{pattern.pattern}"
    point_type = str(point["cpoint_type"]).lower()
    if point_type in ROUTING_TYPES or re.match(r"^cp_[ads]_|^cp_(?:in|out)_", name):
        return "routing", None, f"type:{point['cpoint_type']}"
    return "control", None, "unclassified"


def _resolve_name_lists(
    name_lists: Mapping[str, Sequence[str]], control_point_ids: set[str]
) -> List[Dict[str, Any]]:
    def resolve(name: str, trail: Tuple[str, ...]) -> Tuple[List[str], List[str], List[str]]:
        if name in trail:
            return [], [name], [f"cycle:{'->'.join(trail + (name,))}"]
        points: List[str] = []
        nested: List[str] = []
        unresolved: List[str] = []
        for item in name_lists.get(name, []):
            if item in control_point_ids:
                points.append(item)
            elif item in name_lists:
                nested.append(item)
                sub_points, sub_nested, sub_unresolved = resolve(item, trail + (name,))
                points.extend(sub_points)
                nested.extend(sub_nested)
                unresolved.extend(sub_unresolved)
            else:
                unresolved.append(item)
        return points, nested, unresolved

    result: List[Dict[str, Any]] = []
    for name in sorted(name_lists, key=_natural_key):
        points, nested, unresolved = resolve(name, ())
        result.append(
            {
                "id": name,
                "direct_members": list(name_lists[name]),
                "resolved_control_point_members": list(dict.fromkeys(points)),
                "nested_name_lists": list(dict.fromkeys(nested)),
                "unresolved_members": list(dict.fromkeys(unresolved)),
            }
        )
    return result


def parse_pm_asy(path: Path) -> Dict[str, Any]:
    raw_bytes = path.read_bytes()
    text = raw_bytes.decode("utf-8-sig")
    lines = text.splitlines()

    metadata: Dict[str, Any] = {
        "source_file": str(path),
        "source_sha256": hashlib.sha256(raw_bytes).hexdigest(),
    }
    system_parameters: Dict[str, Any] = {}
    path_types: Dict[str, Dict[str, Any]] = {}
    paths: List[Dict[str, Any]] = []
    control_point_types: Dict[str, Dict[str, Any]] = {}
    control_points: List[Dict[str, Any]] = []
    name_lists: Dict[str, List[str]] = {}
    vehicle_segments: List[Dict[str, Any]] = []
    vehicles: List[Dict[str, Any]] = []
    system_initial_state: Dict[str, Any] = {}
    unparsed_records: List[str] = []

    # Types must be known before CPOINT inheritance is resolved. In the source
    # format, type definitions precede instances, but use two passes so the
    # parser remains tolerant of reordered records.
    blocks = list(_top_level_blocks(lines))
    for record, block in blocks:
        if record == "GPATHTYPE":
            parsed = _parse_path_type(block[0])
            path_types[parsed["id"]] = parsed
        elif record == "CPOINTTYPE":
            parsed = _parse_control_point_type(block[0])
            control_point_types[parsed["id"]] = parsed

    for record, block in blocks:
        if not record:
            if block[0].strip():
                unparsed_records.append(block[0].strip())
        elif record == "VERSION":
            metadata["automod_version"] = block[0].split(maxsplit=1)[1]
        elif record == "SYSTYPE":
            metadata["system_type"] = block[0].split(maxsplit=1)[1]
        elif record == "UNITS":
            tokens = block[0].split()
            metadata["source_distance_unit"] = tokens[1] if len(tokens) > 1 else None
            metadata["source_time_unit"] = tokens[2] if len(tokens) > 2 else None
        elif record == "SYSDEF":
            system_parameters["sysdef_tokens"] = block[0].split()[1:]
        elif record == "AGVSTOL":
            tokens = block[0].split()
            system_parameters["agvs_tolerance"] = {
                "minang_raw": _number(str(_value_after(tokens, "minang", "0"))),
                "maxang_raw": _number(str(_value_after(tokens, "maxang", "0"))),
            }
        elif record == "AGVSDEF":
            system_initial_state = _parse_agvsdef(block)
        elif record == "GPATH":
            paths.append(_parse_gpath(block[0], path_types))
        elif record == "CPOINT":
            control_points.append(_parse_control_point(block[0], control_point_types))
        elif record == "NAMELST":
            name, items = _parse_name_list(block)
            target = name_lists.setdefault(name, [])
            for item in items:
                if item not in target:
                    target.append(item)
        elif record == "AGVVEHSEG":
            vehicle_segments.append(_parse_vehicle_segment(block))
        elif record == "AGVSVEH":
            vehicles.append(_parse_vehicle(block))
        elif record not in {"FLAGS", "GPATHTYPE", "CPOINTTYPE", "AGVVEHSEG", "AGVSVEH"}:
            unparsed_records.append(block[0])

    return {
        "metadata": metadata,
        "system_parameters": system_parameters,
        "path_types": path_types,
        "paths": paths,
        "control_point_types": control_point_types,
        "control_points": control_points,
        "name_lists": name_lists,
        "vehicle_segments": vehicle_segments,
        "vehicles": vehicles,
        "system_initial_state": system_initial_state,
        "unparsed_records": unparsed_records,
    }


def build_layout(
    parsed: Mapping[str, Any],
    snap_tolerance_mm: float = 1.0,
    arc_chord_error_mm: float = 5.0,
) -> Dict[str, Any]:
    paths: List[Dict[str, Any]] = [dict(path) for path in parsed["paths"]]
    control_points: List[Dict[str, Any]] = [dict(point) for point in parsed["control_points"]]
    path_by_id = {path["id"]: path for path in paths}
    validation_errors: List[str] = []
    validation_warnings: List[str] = []

    duplicate_path_ids = len(paths) - len(path_by_id)
    if duplicate_path_ids:
        validation_errors.append(f"duplicate GPATH ids: {duplicate_path_ids}")

    point_ids = [point["id"] for point in control_points]
    if len(point_ids) != len(set(point_ids)):
        validation_errors.append("duplicate CPOINT ids found")

    node_builder = _NodeBuilder(snap_tolerance_mm)
    endpoint_nodes: Dict[Tuple[str, str], str] = {}
    for path in paths:
        start_node = node_builder.add_endpoint(path["begin"])
        end_node = node_builder.add_endpoint(path["end"])
        endpoint_nodes[(path["id"], "start")] = start_node
        endpoint_nodes[(path["id"], "end")] = end_node
        for node_id in {start_node, end_node}:
            node_builder.get(node_id)["source_path_ids"].append(path["id"])

    points_by_path: Dict[str, List[Dict[str, Any]]] = {}
    stations: List[Dict[str, Any]] = []
    routing_points: List[Dict[str, Any]] = []
    for point in control_points:
        path = path_by_id.get(point["source_path_id"])
        if path is None:
            validation_errors.append(
                f"CPOINT {point['id']} references missing GPATH {point['source_path_id']}"
            )
            continue
        distance_mm = float(point["distance_from_path_start_mm"])
        if distance_mm < -snap_tolerance_mm or distance_mm > float(path["length_mm"]) + snap_tolerance_mm:
            validation_errors.append(
                f"CPOINT {point['id']} distance {distance_mm} is outside {path['id']} length {path['length_mm']}"
            )
        clamped_distance = min(max(distance_mm, 0.0), float(path["length_mm"]))
        position = _point_at_distance(path, clamped_distance)
        point["normalized_distance"] = clamped_distance / float(path["length_mm"])
        point["position_mm"] = _point_mm(position)
        point["position_m"] = _point_m(position)
        point["tangent_yaw_rad"] = _tangent_yaw(path, clamped_distance)

        if clamped_distance <= snap_tolerance_mm:
            node_id = endpoint_nodes[(path["id"], "start")]
        elif float(path["length_mm"]) - clamped_distance <= snap_tolerance_mm:
            node_id = endpoint_nodes[(path["id"], "end")]
        else:
            existing = next(
                (
                    candidate
                    for candidate in points_by_path.get(path["id"], [])
                    if abs(float(candidate["distance_from_path_start_mm"]) - clamped_distance)
                    <= snap_tolerance_mm
                ),
                None,
            )
            node_id = existing["graph_node_id"] if existing else node_builder.add_internal(position)
        point["graph_node_id"] = node_id
        point["distance_from_path_start_mm"] = clamped_distance
        node = node_builder.get(node_id)
        node["source_path_ids"].append(path["id"])
        node["control_point_ids"].append(point["id"])
        points_by_path.setdefault(path["id"], []).append(point)

        category, station_type, source = _classify_control_point(point)
        point["classification"] = category
        point["classification_source"] = source
        if category == "station":
            station = {
                "id": point["id"],
                "name": point["name"],
                "station_type": station_type,
                "source_control_point_id": point["id"],
                "source_control_point_type": point["cpoint_type"],
                "source_path_id": point["source_path_id"],
                "distance_from_path_start_mm": point["distance_from_path_start_mm"],
                "position_mm": point["position_mm"],
                "position_m": point["position_m"],
                "tangent_yaw_rad": point["tangent_yaw_rad"],
                "graph_node_id": node_id,
                "capacity": point["capacity"],
                "classification_source": source,
            }
            stations.append(station)
            node["station_ids"].append(station["id"])
        elif category == "routing":
            routing_points.append(
                {
                    "id": point["id"],
                    "source_control_point_id": point["id"],
                    "routing_type": point["cpoint_type"],
                    "source_path_id": point["source_path_id"],
                    "position_m": point["position_m"],
                    "graph_node_id": node_id,
                }
            )

    edges: List[Dict[str, Any]] = []
    for path in paths:
        path_points = sorted(
            points_by_path.get(path["id"], []),
            key=lambda point: (float(point["distance_from_path_start_mm"]), _natural_key(point["id"])),
        )
        split_points: List[Tuple[float, str]] = [
            (0.0, endpoint_nodes[(path["id"], "start")])
        ]
        for point in path_points:
            distance_mm = float(point["distance_from_path_start_mm"])
            node_id = point["graph_node_id"]
            if abs(distance_mm - split_points[-1][0]) <= snap_tolerance_mm:
                if split_points[-1][1] != node_id:
                    validation_warnings.append(
                        f"near-duplicate split nodes on {path['id']} at {distance_mm} mm"
                    )
                continue
            split_points.append((distance_mm, node_id))
        path_length = float(path["length_mm"])
        end_node = endpoint_nodes[(path["id"], "end")]
        if path_length - split_points[-1][0] <= snap_tolerance_mm:
            split_points[-1] = (path_length, end_node)
        else:
            split_points.append((path_length, end_node))

        for segment_index, ((start_mm, from_node), (end_mm, to_node)) in enumerate(
            zip(split_points, split_points[1:]), start=1
        ):
            if end_mm - start_mm <= EPSILON:
                continue
            sampled = _sample_interval(path, start_mm, end_mm, arc_chord_error_mm)
            edge_id = f"{path['id']}__{segment_index:03d}"
            edges.append(
                {
                    "id": edge_id,
                    "from_node_id": from_node,
                    "to_node_id": to_node,
                    "source_path_id": path["id"],
                    "source_distance_start_mm": start_mm,
                    "source_distance_end_mm": end_mm,
                    "length_m": (end_mm - start_mm) / 1000.0,
                    "geometry_type": path["geometry_type"],
                    "direction": path["direction"],
                    "one_way": path["one_way"],
                    "speed_limit_mps": path["speed_limit_mps"],
                    "navigation_value": path["navigation_value"],
                    "automod_color_index": path["automod_color_index"],
                    "polyline_m": [_point_m(point) for point in sampled],
                }
            )

    source_paths: List[Dict[str, Any]] = []
    for path in paths:
        sampled = _sample_interval(path, 0.0, float(path["length_mm"]), arc_chord_error_mm)
        source_path: Dict[str, Any] = {
            key: value
            for key, value in path.items()
            if key not in {"begin", "end", "center", "sweep_radians"}
        }
        source_path["begin_mm"] = _point_mm(path["begin"])
        source_path["end_mm"] = _point_mm(path["end"])
        source_path["begin_m"] = _point_m(path["begin"])
        source_path["end_m"] = _point_m(path["end"])
        if path["center"] is not None:
            source_path["center_mm"] = _point_mm(path["center"])
            source_path["center_m"] = _point_m(path["center"])
        source_path["polyline_m"] = [_point_m(point) for point in sampled]
        source_paths.append(source_path)

    control_point_ids = set(point_ids)
    resolved_name_lists = _resolve_name_lists(parsed["name_lists"], control_point_ids)
    for name_list in resolved_name_lists:
        for item in name_list["unresolved_members"]:
            validation_warnings.append(f"NAMELST {name_list['id']} unresolved member: {item}")

    nodes = node_builder.finalize()
    node_ids = {node["id"] for node in nodes}
    for edge in edges:
        if edge["from_node_id"] not in node_ids or edge["to_node_id"] not in node_ids:
            validation_errors.append(f"edge {edge['id']} references a missing node")

    metadata = dict(parsed["metadata"])
    metadata.update(
        {
            "generator": "scripts/pm_asy_to_json.py",
            "output_distance_unit": "Meters",
            "source_record_counts": {
                "gpath": len(paths),
                "gpath_line": sum(path["geometry_type"] == "line" for path in paths),
                "gpath_arc": sum(path["geometry_type"] == "arc" for path in paths),
                "cpoint": len(control_points),
                "cpoint_type": len(parsed["control_point_types"]),
                "vehicle_segment": len(parsed["vehicle_segments"]),
                "vehicle_definition": len(parsed["vehicles"]),
            },
        }
    )

    return {
        "metadata": metadata,
        "coordinate_system": {
            "source_plane": "AutoMod XY",
            "output_plane": "Isaac Sim XY",
            "up_axis": "Z",
            "source_units": "millimeters",
            "output_units": "meters",
            "origin_offset_mm": [0.0, 0.0, 0.0],
            "note": "GPATH upz is stored as an up vector and is not interpreted as track elevation.",
        },
        "system_parameters": parsed["system_parameters"],
        "path_types": [parsed["path_types"][key] for key in sorted(parsed["path_types"], key=_natural_key)],
        "source_paths": source_paths,
        "nodes": nodes,
        "edges": edges,
        "control_point_types": [
            parsed["control_point_types"][key]
            for key in sorted(parsed["control_point_types"], key=_natural_key)
        ],
        "control_points": control_points,
        "routing_control_points": routing_points,
        "stations": stations,
        "name_lists": resolved_name_lists,
        "vehicle_segments": parsed["vehicle_segments"],
        "vehicle_definitions": parsed["vehicles"],
        "system_initial_state": parsed["system_initial_state"],
        "validation": {
            "errors": validation_errors,
            "warnings": validation_warnings,
            "unparsed_top_level_records": parsed["unparsed_records"],
            "summary": {
                "node_count": len(nodes),
                "edge_count": len(edges),
                "control_point_count": len(control_points),
                "routing_control_point_count": len(routing_points),
                "station_count": len(stations),
            },
        },
    }


def convert_file(
    input_path: Path,
    output_path: Path,
    snap_tolerance_mm: float = 1.0,
    arc_chord_error_mm: float = 5.0,
) -> Dict[str, Any]:
    parsed = parse_pm_asy(input_path)
    layout = build_layout(parsed, snap_tolerance_mm, arc_chord_error_mm)
    if layout["validation"]["errors"]:
        raise ValueError("Conversion validation failed: " + "; ".join(layout["validation"]["errors"]))
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(
        json.dumps(layout, ensure_ascii=False, indent=2, allow_nan=False) + "\n",
        encoding="utf-8",
    )
    return layout


def _build_argument_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Convert AutoMod AGVS pm.asy geometry and control points to Isaac Sim JSON."
    )
    parser.add_argument("--input", required=True, type=Path, help="Input pm.asy file")
    parser.add_argument("--output", required=True, type=Path, help="Output JSON file")
    parser.add_argument("--snap-tolerance-mm", type=float, default=1.0)
    parser.add_argument("--arc-chord-error-mm", type=float, default=5.0)
    return parser


def main() -> int:
    args = _build_argument_parser().parse_args()
    if args.snap_tolerance_mm <= 0:
        raise SystemExit("--snap-tolerance-mm must be greater than zero")
    if args.arc_chord_error_mm <= 0:
        raise SystemExit("--arc-chord-error-mm must be greater than zero")
    layout = convert_file(
        args.input,
        args.output,
        snap_tolerance_mm=args.snap_tolerance_mm,
        arc_chord_error_mm=args.arc_chord_error_mm,
    )
    summary = layout["validation"]["summary"]
    counts = layout["metadata"]["source_record_counts"]
    print(f"Converted: {args.input} -> {args.output}")
    print(
        "Source: "
        f"{counts['gpath']} GPATH ({counts['gpath_line']} line, {counts['gpath_arc']} arc), "
        f"{counts['cpoint']} CPOINT"
    )
    print(
        "Graph: "
        f"{summary['node_count']} nodes, {summary['edge_count']} directed edges, "
        f"{summary['station_count']} stations, "
        f"{summary['routing_control_point_count']} routing control points"
    )
    print(
        f"Validation: {len(layout['validation']['errors'])} errors, "
        f"{len(layout['validation']['warnings'])} warnings"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
