"""Create a focused Isaac Sim USD layout from the AutoMod layout JSON.

The source JSON contains several spatially separated guide-path drawings.  This
module finds the bounding box of the control points, expands it by a configurable
margin, clips guide-path polylines to that box, and writes a dependency-free
ASCII USD (``.usda``) preview.  The output intentionally stops at layout and
marker generation; rail meshes, equipment assets, OHT physics, and routing are
left for the next development stage.
"""

from __future__ import annotations

import argparse
import json
import math
import re
from pathlib import Path
from typing import Any, Dict, Iterable, List, Optional, Sequence, Tuple


Point = Tuple[float, float, float]
Bounds = Tuple[float, float, float, float]
EPSILON = 1.0e-9


STATION_COLORS: Dict[str, Tuple[float, float, float]] = {
    "equipment": (1.0, 0.42, 0.05),
    "utb": (1.0, 0.82, 0.12),
    "park": (0.20, 0.78, 0.28),
    "out_station": (0.72, 0.30, 1.0),
    "vehicle_home": (0.95, 0.95, 0.95),
}


def _as_point(value: Sequence[float]) -> Point:
    if len(value) != 3:
        raise ValueError(f"expected a three-dimensional point, got {value!r}")
    point = (float(value[0]), float(value[1]), float(value[2]))
    if not all(math.isfinite(component) for component in point):
        raise ValueError(f"point contains a non-finite component: {value!r}")
    return point


def _point_inside_bounds(point: Sequence[float], bounds: Bounds) -> bool:
    x, y = float(point[0]), float(point[1])
    min_x, min_y, max_x, max_y = bounds
    return min_x - EPSILON <= x <= max_x + EPSILON and min_y - EPSILON <= y <= max_y + EPSILON


def compute_control_point_bounds(layout: Dict[str, Any], margin_m: float = 5.0) -> Bounds:
    """Return the XY bounds of every control point, expanded by ``margin_m``."""

    if margin_m < 0 or not math.isfinite(margin_m):
        raise ValueError("margin_m must be a finite value greater than or equal to zero")

    control_points = layout.get("control_points", [])
    if not control_points:
        raise ValueError("layout has no control_points from which to determine a region")

    positions = [_as_point(point["position_m"]) for point in control_points]
    min_x = min(point[0] for point in positions) - margin_m
    min_y = min(point[1] for point in positions) - margin_m
    max_x = max(point[0] for point in positions) + margin_m
    max_y = max(point[1] for point in positions) + margin_m
    return (min_x, min_y, max_x, max_y)


def _clip_segment_to_bounds(start: Point, end: Point, bounds: Bounds) -> Optional[Tuple[Point, Point]]:
    """Clip one 3D line segment against an XY rectangle with Liang-Barsky."""

    min_x, min_y, max_x, max_y = bounds
    dx = end[0] - start[0]
    dy = end[1] - start[1]
    dz = end[2] - start[2]
    t_min = 0.0
    t_max = 1.0

    for direction, distance in (
        (-dx, start[0] - min_x),
        (dx, max_x - start[0]),
        (-dy, start[1] - min_y),
        (dy, max_y - start[1]),
    ):
        if abs(direction) <= EPSILON:
            if distance < 0:
                return None
            continue
        ratio = distance / direction
        if direction < 0:
            t_min = max(t_min, ratio)
        else:
            t_max = min(t_max, ratio)
        if t_min - t_max > EPSILON:
            return None

    def interpolate(t: float) -> Point:
        return (
            start[0] + dx * t,
            start[1] + dy * t,
            start[2] + dz * t,
        )

    return interpolate(t_min), interpolate(t_max)


def _points_equal(first: Point, second: Point) -> bool:
    return all(abs(left - right) <= EPSILON for left, right in zip(first, second))


def clip_polyline_to_bounds(polyline: Iterable[Sequence[float]], bounds: Bounds) -> List[List[Point]]:
    """Return one or more polyline fragments clipped to ``bounds``."""

    points = [_as_point(point) for point in polyline]
    if len(points) < 2:
        return []

    fragments: List[List[Point]] = []
    current: List[Point] = []
    for start, end in zip(points, points[1:]):
        clipped = _clip_segment_to_bounds(start, end, bounds)
        if clipped is None:
            if len(current) >= 2:
                fragments.append(current)
            current = []
            continue

        clipped_start, clipped_end = clipped
        if current and _points_equal(current[-1], clipped_start):
            if not _points_equal(current[-1], clipped_end):
                current.append(clipped_end)
            continue

        if len(current) >= 2:
            fragments.append(current)
        current = [clipped_start]
        if not _points_equal(clipped_start, clipped_end):
            current.append(clipped_end)

    if len(current) >= 2:
        fragments.append(current)
    return fragments


def select_control_point_region(layout: Dict[str, Any], margin_m: float = 5.0) -> Dict[str, Any]:
    """Select and clip the guide paths surrounding the control-point cluster."""

    bounds = compute_control_point_bounds(layout, margin_m)
    curves: List[Dict[str, Any]] = []
    selected_source_path_ids = set()

    for source_path in layout.get("source_paths", []):
        for fragment_index, points in enumerate(
            clip_polyline_to_bounds(source_path.get("polyline_m", []), bounds),
            start=1,
        ):
            selected_source_path_ids.add(source_path["id"])
            curves.append(
                {
                    "id": f"{source_path['id']}__clip_{fragment_index:03d}",
                    "source_path_id": source_path["id"],
                    "geometry_type": source_path.get("geometry_type", "unknown"),
                    "points": points,
                }
            )

    control_points = [
        point
        for point in layout.get("control_points", [])
        if _point_inside_bounds(point["position_m"], bounds)
    ]
    routing_points = [
        point
        for point in layout.get("routing_control_points", [])
        if _point_inside_bounds(point["position_m"], bounds)
    ]
    stations = [
        station
        for station in layout.get("stations", [])
        if _point_inside_bounds(station["position_m"], bounds)
    ]

    return {
        "bounds_m": bounds,
        "margin_m": margin_m,
        "selected_source_path_ids": sorted(selected_source_path_ids),
        "curves": curves,
        "control_points": control_points,
        "routing_control_points": routing_points,
        "stations": stations,
    }


def _format_number(value: float) -> str:
    number = float(value)
    if not math.isfinite(number):
        raise ValueError(f"USD cannot serialize non-finite number {value!r}")
    if abs(number) < EPSILON:
        number = 0.0
    return format(number, ".12g")


def _format_point(point: Sequence[float], z_m: float) -> str:
    return f"({_format_number(point[0])}, {_format_number(point[1])}, {_format_number(z_m)})"


def _format_color(color: Sequence[float]) -> str:
    return f"({_format_number(color[0])}, {_format_number(color[1])}, {_format_number(color[2])})"


def _usd_string(value: Any) -> str:
    return json.dumps(str(value), ensure_ascii=False)


def _valid_identifier(value: str) -> str:
    identifier = re.sub(r"[^A-Za-z0-9_]", "_", value)
    if not identifier:
        return "unnamed"
    if identifier[0].isdigit():
        return "_" + identifier
    return identifier


def _format_array(values: Sequence[str], indent: str = "            ") -> str:
    if not values:
        return "[]"
    return "[\n" + "\n".join(f"{indent}{value}," for value in values) + f"\n{indent[:-4]}]"


def build_usda(
    layout: Dict[str, Any],
    *,
    margin_m: float = 5.0,
    track_z_m: float = 0.0,
    path_width_m: float = 0.08,
    control_point_width_m: float = 0.24,
    station_marker_radius_m: float = 0.28,
) -> Tuple[str, Dict[str, Any]]:
    """Build the focused USDA text and return it with a generation summary."""

    for name, value in (
        ("track_z_m", track_z_m),
        ("path_width_m", path_width_m),
        ("control_point_width_m", control_point_width_m),
        ("station_marker_radius_m", station_marker_radius_m),
    ):
        if not math.isfinite(value):
            raise ValueError(f"{name} must be finite")
    if path_width_m <= 0 or control_point_width_m <= 0 or station_marker_radius_m <= 0:
        raise ValueError("path and marker sizes must be greater than zero")

    region = select_control_point_region(layout, margin_m)
    curves = region["curves"]
    if not curves:
        raise ValueError("control-point region did not intersect any guide paths")

    curve_counts = [str(len(curve["points"])) for curve in curves]
    curve_points = [
        _format_point(point, track_z_m)
        for curve in curves
        for point in curve["points"]
    ]
    curve_source_ids = [_usd_string(curve["source_path_id"]) for curve in curves]
    curve_geometry_types = [_usd_string(curve["geometry_type"]) for curve in curves]

    control_points = region["control_points"]
    control_point_positions = [
        _format_point(point["position_m"], track_z_m) for point in control_points
    ]
    control_point_ids = [_usd_string(point["id"]) for point in control_points]

    min_x, min_y, max_x, max_y = region["bounds_m"]
    source_name = layout.get("metadata", {}).get("source_file", "unknown")
    summary = {
        "bounds_m": [min_x, min_y, max_x, max_y],
        "margin_m": margin_m,
        "selected_source_path_count": len(region["selected_source_path_ids"]),
        "clipped_curve_count": len(curves),
        "curve_vertex_count": len(curve_points),
        "control_point_count": len(control_points),
        "routing_control_point_count": len(region["routing_control_points"]),
        "station_count": len(region["stations"]),
        "track_z_m": track_z_m,
    }

    bounds_text = ",".join(_format_number(value) for value in region["bounds_m"])
    lines = [
        "#usda 1.0",
        "(",
        '    defaultPrim = "World"',
        "    metersPerUnit = 1",
        '    upAxis = "Z"',
        "    customLayerData = {",
        f"        string sourceLayout = {_usd_string(source_name)}",
        '        string selectionMode = "control_point_bounds"',
        f"        string regionBoundsM = {_usd_string(bounds_text)}",
        f"        double controlPointMarginM = {_format_number(margin_m)}",
        f"        int selectedSourcePathCount = {summary['selected_source_path_count']}",
        f"        int clippedCurveCount = {summary['clipped_curve_count']}",
        f"        int controlPointCount = {summary['control_point_count']}",
        f"        int stationCount = {summary['station_count']}",
        "    }",
        ")",
        "",
        'def Xform "World"',
        "{",
        '    def Xform "ControlPointRegion"',
        "    {",
        '        def BasisCurves "GuidePaths"',
        "        {",
        '            uniform token type = "linear"',
        '            uniform token wrap = "nonperiodic"',
        f"            int[] curveVertexCounts = {_format_array(curve_counts)}",
        f"            point3f[] points = {_format_array(curve_points)}",
        f"            float[] widths = [{_format_number(path_width_m)}] (",
        '                interpolation = "constant"',
        "            )",
        f"            string[] primvars:sourcePathId = {_format_array(curve_source_ids)} (",
        '                interpolation = "uniform"',
        "            )",
        f"            string[] primvars:geometryType = {_format_array(curve_geometry_types)} (",
        '                interpolation = "uniform"',
        "            )",
        "            color3f[] primvars:displayColor = [(0.18, 0.48, 1)] (",
        '                interpolation = "constant"',
        "            )",
        "            float3[] extent = [",
        f"                ({_format_number(min_x)}, {_format_number(min_y)}, {_format_number(track_z_m)}),",
        f"                ({_format_number(max_x)}, {_format_number(max_y)}, {_format_number(track_z_m)}),",
        "            ]",
        "        }",
        "",
        '        def Points "ControlPoints"',
        "        {",
        f"            point3f[] points = {_format_array(control_point_positions)}",
        f"            float[] widths = [{_format_number(control_point_width_m)}] (",
        '                interpolation = "constant"',
        "            )",
        f"            string[] primvars:controlPointId = {_format_array(control_point_ids)} (",
        '                interpolation = "vertex"',
        "            )",
        "            color3f[] primvars:displayColor = [(1, 0.16, 0.05)] (",
        '                interpolation = "constant"',
        "            )",
        "            float3[] extent = [",
        f"                ({_format_number(min_x)}, {_format_number(min_y)}, {_format_number(track_z_m)}),",
        f"                ({_format_number(max_x)}, {_format_number(max_y)}, {_format_number(track_z_m)}),",
        "            ]",
        "        }",
        "",
        '        def Xform "Stations"',
        "        {",
    ]

    used_station_identifiers = set()
    for index, station in enumerate(region["stations"], start=1):
        identifier = _valid_identifier(station["id"])
        if identifier in used_station_identifiers:
            identifier = f"{identifier}_{index:03d}"
        used_station_identifiers.add(identifier)

        x, y, _ = _as_point(station["position_m"])
        yaw_degrees = math.degrees(float(station.get("tangent_yaw_rad", 0.0)))
        station_type = station.get("station_type", "unknown")
        color = STATION_COLORS.get(station_type, (0.85, 0.85, 0.85))
        lines.extend(
            [
                f'            def Xform "{identifier}"',
                "            {",
                f"                custom string automod:stationId = {_usd_string(station['id'])}",
                f"                custom string automod:stationType = {_usd_string(station_type)}",
                f"                custom string automod:sourcePathId = {_usd_string(station['source_path_id'])}",
                f"                custom string automod:graphNodeId = {_usd_string(station['graph_node_id'])}",
                f"                custom double automod:tangentYawRad = {_format_number(station.get('tangent_yaw_rad', 0.0))}",
                f"                double3 xformOp:translate = ({_format_number(x)}, {_format_number(y)}, {_format_number(track_z_m)})",
                f"                double3 xformOp:rotateXYZ = (0, 0, {_format_number(yaw_degrees)})",
                '                uniform token[] xformOpOrder = ["xformOp:translate", "xformOp:rotateXYZ"]',
                "",
                '                def Sphere "Marker"',
                "                {",
                f"                    double radius = {_format_number(station_marker_radius_m)}",
                f"                    color3f[] primvars:displayColor = [{_format_color(color)}] (",
                '                        interpolation = "constant"',
                "                    )",
                "                }",
                "            }",
                "",
            ]
        )

    lines.extend(
        [
            "        }",
            "    }",
            "}",
            "",
        ]
    )
    return "\n".join(lines), summary


def convert_file(
    input_path: Path,
    output_path: Path,
    *,
    margin_m: float = 5.0,
    track_z_m: float = 0.0,
) -> Dict[str, Any]:
    layout = json.loads(input_path.read_text(encoding="utf-8"))
    usda, summary = build_usda(layout, margin_m=margin_m, track_z_m=track_z_m)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(usda, encoding="utf-8", newline="\n")
    return summary


def _build_argument_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Create an Isaac Sim USDA preview of the control-point-dense layout region."
    )
    parser.add_argument("--input", required=True, type=Path, help="Input layout JSON")
    parser.add_argument("--output", required=True, type=Path, help="Output .usda file")
    parser.add_argument(
        "--margin-m",
        type=float,
        default=5.0,
        help="Margin around the control-point bounds in meters (default: 5.0)",
    )
    parser.add_argument(
        "--track-z-m",
        type=float,
        default=0.0,
        help="Preview elevation in meters; the AutoMod input has no rail elevation",
    )
    return parser


def main() -> int:
    args = _build_argument_parser().parse_args()
    summary = convert_file(
        args.input,
        args.output,
        margin_m=args.margin_m,
        track_z_m=args.track_z_m,
    )
    print(f"Created: {args.output}")
    print(
        "Region: "
        f"{summary['bounds_m']} m, "
        f"{summary['selected_source_path_count']} source paths, "
        f"{summary['clipped_curve_count']} clipped curves"
    )
    print(
        "Markers: "
        f"{summary['control_point_count']} control points, "
        f"{summary['station_count']} stations"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
