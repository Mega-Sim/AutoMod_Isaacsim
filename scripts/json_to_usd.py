"""Generate the configured Isaac Sim layout stage from the AutoMod JSON.

The committed configuration keeps the previously reviewed control-point-dense
region, authors guide paths and control points as batched USD geometry, and
places every classified station as an oriented Xform with a replaceable USD
asset reference.
"""

from __future__ import annotations

import argparse
import json
import math
import os
import re
from collections import Counter
from copy import deepcopy
from pathlib import Path
from typing import Any, Dict, List, Sequence, Tuple


try:
    from scripts.layout_json_to_usda import (
        _as_point,
        _format_array,
        _format_color,
        _format_number,
        _usd_string,
        _valid_identifier,
        select_control_point_region,
    )
except ModuleNotFoundError:  # Direct execution: python3 scripts/json_to_usd.py
    from layout_json_to_usda import (  # type: ignore[no-redef]
        _as_point,
        _format_array,
        _format_color,
        _format_number,
        _usd_string,
        _valid_identifier,
        select_control_point_region,
    )


REPO_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_INPUT = REPO_ROOT / "generated" / "basic_model_layout.json"
DEFAULT_CONFIG = REPO_ROOT / "config" / "layout_assets.json"
DEFAULT_OUTPUT = REPO_ROOT / "generated" / "basic_model_layout.usda"

REQUIRED_STATION_TYPES = {
    "equipment",
    "utb",
    "park",
    "out_station",
    "vehicle_home",
}
FORWARD_AXIS_YAW_CORRECTION_DEGREES = {
    "+X": 0.0,
    "-X": 180.0,
    "+Y": -90.0,
    "-Y": 90.0,
}
URI_PATTERN = re.compile(r"^[A-Za-z][A-Za-z0-9+.-]*://")


def _require_finite_number(value: Any, name: str) -> float:
    try:
        number = float(value)
    except (TypeError, ValueError) as error:
        raise ValueError(f"{name} must be a number") from error
    if not math.isfinite(number):
        raise ValueError(f"{name} must be finite")
    return number


def _require_positive_number(value: Any, name: str) -> float:
    number = _require_finite_number(value, name)
    if number <= 0:
        raise ValueError(f"{name} must be greater than zero")
    return number


def _validate_vector(
    value: Any,
    name: str,
    *,
    positive: bool = False,
    color: bool = False,
) -> List[float]:
    if not isinstance(value, list) or len(value) != 3:
        raise ValueError(f"{name} must be an array of three numbers")
    vector = [
        _require_finite_number(component, f"{name}[{index}]")
        for index, component in enumerate(value)
    ]
    if positive and any(component <= 0 for component in vector):
        raise ValueError(f"{name} components must be greater than zero")
    if color and any(component < 0 or component > 1 for component in vector):
        raise ValueError(f"{name} color components must be between zero and one")
    return vector


def load_asset_config(config_path: Path) -> Dict[str, Any]:
    """Load and validate the layout and station-asset configuration."""

    config = json.loads(config_path.read_text(encoding="utf-8"))
    if config.get("schema_version") != 1:
        raise ValueError("layout asset config schema_version must be 1")

    selection = config.get("selection", {})
    if selection.get("mode") != "control_point_bounds":
        raise ValueError(
            "selection.mode must remain control_point_bounds for the reviewed region"
        )
    margin_m = _require_finite_number(selection.get("margin_m"), "selection.margin_m")
    if margin_m < 0:
        raise ValueError("selection.margin_m must be greater than or equal to zero")

    stage = config.get("stage", {})
    meters_per_unit = _require_positive_number(
        stage.get("meters_per_unit"), "stage.meters_per_unit"
    )
    if not math.isclose(meters_per_unit, 1.0):
        raise ValueError(
            "stage.meters_per_unit must be 1.0 because the JSON coordinates are meters"
        )
    if stage.get("up_axis") != "Z":
        raise ValueError("stage.up_axis must be Z")
    _require_finite_number(stage.get("rail_height_m"), "stage.rail_height_m")
    if not isinstance(stage.get("rail_height_verified"), bool):
        raise ValueError("stage.rail_height_verified must be a boolean")

    guide_paths = config.get("guide_paths", {})
    _require_positive_number(guide_paths.get("width_m"), "guide_paths.width_m")
    _validate_vector(guide_paths.get("color_rgb"), "guide_paths.color_rgb", color=True)

    control_points = config.get("control_points", {})
    _require_positive_number(control_points.get("width_m"), "control_points.width_m")
    _validate_vector(
        control_points.get("color_rgb"), "control_points.color_rgb", color=True
    )

    station_types = config.get("station_types")
    if not isinstance(station_types, dict):
        raise ValueError("station_types must be an object")
    missing_types = REQUIRED_STATION_TYPES - set(station_types)
    if missing_types:
        raise ValueError(f"station_types is missing: {sorted(missing_types)}")

    for station_type, mapping in station_types.items():
        _validate_station_mapping(
            mapping,
            f"station_types.{station_type}",
            require_asset=True,
        )

    overrides = config.get("station_overrides", {})
    if not isinstance(overrides, dict):
        raise ValueError("station_overrides must be an object")
    for station_id, mapping in overrides.items():
        _validate_station_mapping(
            mapping,
            f"station_overrides.{station_id}",
            require_asset=False,
        )

    return config


def _validate_station_mapping(
    mapping: Any,
    name: str,
    *,
    require_asset: bool,
) -> None:
    if not isinstance(mapping, dict):
        raise ValueError(f"{name} must be an object")
    if require_asset or "asset_path" in mapping:
        asset_path = mapping.get("asset_path")
        if not isinstance(asset_path, str) or not asset_path.strip():
            raise ValueError(f"{name}.asset_path must be a non-empty string")
    if "placeholder" in mapping and not isinstance(mapping["placeholder"], bool):
        raise ValueError(f"{name}.placeholder must be a boolean")
    if (
        "forward_axis" in mapping
        and mapping["forward_axis"] not in FORWARD_AXIS_YAW_CORRECTION_DEGREES
    ):
        raise ValueError(
            f"{name}.forward_axis must be one of {sorted(FORWARD_AXIS_YAW_CORRECTION_DEGREES)}"
        )
    if "yaw_offset_degrees" in mapping:
        _require_finite_number(
            mapping["yaw_offset_degrees"],
            f"{name}.yaw_offset_degrees",
        )
    if "scale" in mapping:
        _validate_vector(mapping["scale"], f"{name}.scale", positive=True)


def resolve_station_mapping(
    config: Dict[str, Any],
    station: Dict[str, Any],
) -> Dict[str, Any]:
    """Resolve a station-type mapping and an optional station-ID override."""

    station_type = station["station_type"]
    base = config["station_types"].get(station_type)
    if base is None:
        raise ValueError(f"station {station['id']} has unmapped type {station_type!r}")
    mapping = deepcopy(base)
    mapping.update(config.get("station_overrides", {}).get(station["id"], {}))
    _validate_station_mapping(
        mapping,
        f"resolved station {station['id']}",
        require_asset=True,
    )
    mapping.setdefault("placeholder", False)
    mapping.setdefault("forward_axis", "+X")
    mapping.setdefault("yaw_offset_degrees", 0.0)
    mapping.setdefault("scale", [1.0, 1.0, 1.0])
    return mapping


def _resolve_asset_reference(
    asset_path: str,
    *,
    output_path: Path,
    repo_root: Path,
) -> Tuple[str, Path | None]:
    """Return the USD reference URI and the local file used for validation."""

    if URI_PATTERN.match(asset_path):
        return asset_path, None

    local_asset = (repo_root / asset_path).resolve()
    try:
        local_asset.relative_to(repo_root.resolve())
    except ValueError as error:
        raise ValueError(f"asset path escapes the repository: {asset_path}") from error
    if not local_asset.is_file():
        raise FileNotFoundError(f"mapped USD asset does not exist: {local_asset}")
    reference = os.path.relpath(
        local_asset,
        output_path.parent.resolve(),
    ).replace(os.sep, "/")
    return reference, local_asset


def _station_yaw_degrees(station: Dict[str, Any], mapping: Dict[str, Any]) -> float:
    tangent_yaw = math.degrees(float(station.get("tangent_yaw_rad", 0.0)))
    forward_correction = FORWARD_AXIS_YAW_CORRECTION_DEGREES[mapping["forward_axis"]]
    return tangent_yaw + forward_correction + float(mapping["yaw_offset_degrees"])


def build_configured_usda(
    layout: Dict[str, Any],
    config: Dict[str, Any],
    *,
    output_path: Path,
    config_path: Path,
    repo_root: Path = REPO_ROOT,
) -> Tuple[str, Dict[str, Any]]:
    """Build the final configured USDA stage and its verification summary."""

    margin_m = float(config["selection"]["margin_m"])
    region = select_control_point_region(layout, margin_m)
    curves = region["curves"]
    control_points = region["control_points"]
    stations = region["stations"]
    if not curves:
        raise ValueError("configured region did not intersect any guide paths")
    if not stations:
        raise ValueError("configured region has no stations")

    rail_height_m = float(config["stage"]["rail_height_m"])
    path_width_m = float(config["guide_paths"]["width_m"])
    control_point_width_m = float(config["control_points"]["width_m"])
    path_color = config["guide_paths"]["color_rgb"]
    control_point_color = config["control_points"]["color_rgb"]

    curve_counts = [str(len(curve["points"])) for curve in curves]
    curve_points = [
        f"({_format_number(point[0])}, {_format_number(point[1])}, {_format_number(rail_height_m)})"
        for curve in curves
        for point in curve["points"]
    ]
    curve_source_ids = [_usd_string(curve["source_path_id"]) for curve in curves]
    curve_geometry_types = [_usd_string(curve["geometry_type"]) for curve in curves]
    control_point_positions = [
        "("
        f"{_format_number(point['position_m'][0])}, "
        f"{_format_number(point['position_m'][1])}, "
        f"{_format_number(rail_height_m)}"
        ")"
        for point in control_points
    ]
    control_point_ids = [_usd_string(point["id"]) for point in control_points]

    resolved_stations: List[Tuple[Dict[str, Any], Dict[str, Any], str]] = []
    local_assets = set()
    for station in stations:
        mapping = resolve_station_mapping(config, station)
        reference, local_asset = _resolve_asset_reference(
            mapping["asset_path"],
            output_path=output_path,
            repo_root=repo_root,
        )
        if local_asset is not None:
            local_assets.add(local_asset)
        resolved_stations.append((station, mapping, reference))

    station_type_counts = Counter(station["station_type"] for station in stations)
    placeholder_count = sum(
        bool(mapping["placeholder"])
        for _, mapping, _ in resolved_stations
    )
    min_x, min_y, max_x, max_y = region["bounds_m"]
    config_display_path = config_path.resolve()
    try:
        config_display_path = config_display_path.relative_to(repo_root.resolve())
    except ValueError:
        pass

    summary = {
        "bounds_m": [min_x, min_y, max_x, max_y],
        "selected_source_path_count": len(region["selected_source_path_ids"]),
        "clipped_curve_count": len(curves),
        "curve_vertex_count": len(curve_points),
        "control_point_count": len(control_points),
        "routing_control_point_count": len(region["routing_control_points"]),
        "station_count": len(stations),
        "station_type_counts": dict(sorted(station_type_counts.items())),
        "asset_reference_count": len(resolved_stations),
        "unique_local_asset_count": len(local_assets),
        "placeholder_reference_count": placeholder_count,
        "rail_height_m": rail_height_m,
        "rail_height_verified": config["stage"]["rail_height_verified"],
    }

    bounds_text = ",".join(_format_number(value) for value in region["bounds_m"])
    lines = [
        "#usda 1.0",
        "(",
        '    defaultPrim = "World"',
        "    metersPerUnit = 1",
        '    upAxis = "Z"',
        "    customLayerData = {",
        f"        string sourceLayout = {_usd_string(layout.get('metadata', {}).get('source_file', 'unknown'))}",
        f"        string assetConfig = {_usd_string(config_display_path.as_posix())}",
        '        string selectionMode = "control_point_bounds"',
        f"        string regionBoundsM = {_usd_string(bounds_text)}",
        f"        double railHeightM = {_format_number(rail_height_m)}",
        f"        bool railHeightVerified = {str(config['stage']['rail_height_verified']).lower()}",
        f"        int selectedSourcePathCount = {summary['selected_source_path_count']}",
        f"        int clippedCurveCount = {summary['clipped_curve_count']}",
        f"        int controlPointCount = {summary['control_point_count']}",
        f"        int stationCount = {summary['station_count']}",
        f"        int assetReferenceCount = {summary['asset_reference_count']}",
        "    }",
        ")",
        "",
        'def Xform "World"',
        "{",
        '    def Xform "Layout"',
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
        f"            color3f[] primvars:displayColor = [{_format_color(path_color)}] (",
        '                interpolation = "constant"',
        "            )",
        "            float3[] extent = [",
        f"                ({_format_number(min_x)}, {_format_number(min_y)}, {_format_number(rail_height_m)}),",
        f"                ({_format_number(max_x)}, {_format_number(max_y)}, {_format_number(rail_height_m)}),",
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
        f"            color3f[] primvars:displayColor = [{_format_color(control_point_color)}] (",
        '                interpolation = "constant"',
        "            )",
        "            float3[] extent = [",
        f"                ({_format_number(min_x)}, {_format_number(min_y)}, {_format_number(rail_height_m)}),",
        f"                ({_format_number(max_x)}, {_format_number(max_y)}, {_format_number(rail_height_m)}),",
        "            ]",
        "        }",
        "",
        '        def Xform "Stations"',
        "        {",
    ]

    used_identifiers = set()
    for index, (station, mapping, reference) in enumerate(resolved_stations, start=1):
        identifier = _valid_identifier(station["id"])
        if identifier in used_identifiers:
            identifier = f"{identifier}_{index:03d}"
        used_identifiers.add(identifier)
        x, y, _ = _as_point(station["position_m"])
        yaw_degrees = _station_yaw_degrees(station, mapping)
        scale = mapping["scale"]
        lines.extend(
            [
                f'            def Xform "{identifier}"',
                "            {",
                f"                custom string automod:stationId = {_usd_string(station['id'])}",
                f"                custom string automod:stationType = {_usd_string(station['station_type'])}",
                f"                custom string automod:sourcePathId = {_usd_string(station['source_path_id'])}",
                f"                custom string automod:graphNodeId = {_usd_string(station['graph_node_id'])}",
                "                custom double automod:tangentYawRad = "
                f"{_format_number(station.get('tangent_yaw_rad', 0.0))}",
                f"                custom string isaacsim:assetPath = {_usd_string(mapping['asset_path'])}",
                f"                custom bool isaacsim:placeholder = {str(bool(mapping['placeholder'])).lower()}",
                f"                custom string isaacsim:forwardAxis = {_usd_string(mapping['forward_axis'])}",
                "                double3 xformOp:translate = "
                f"({_format_number(x)}, {_format_number(y)}, "
                f"{_format_number(rail_height_m)})",
                f"                double3 xformOp:rotateXYZ = (0, 0, {_format_number(yaw_degrees)})",
                '                uniform token[] xformOpOrder = ["xformOp:translate", "xformOp:rotateXYZ"]',
                "",
                '                def Xform "Model" (',
                f"                    prepend references = @{reference}@",
                "                )",
                "                {",
                "                    float3 xformOp:scale = "
                f"({_format_number(scale[0])}, {_format_number(scale[1])}, "
                f"{_format_number(scale[2])})",
                '                    uniform token[] xformOpOrder = ["xformOp:scale"]',
                "                }",
                "            }",
                "",
            ]
        )

    lines.extend(["        }", "    }", "}", ""])
    return "\n".join(lines), summary


def convert_file(
    input_path: Path,
    config_path: Path,
    output_path: Path,
) -> Dict[str, Any]:
    layout = json.loads(input_path.read_text(encoding="utf-8"))
    config = load_asset_config(config_path)
    usda, summary = build_configured_usda(
        layout,
        config,
        output_path=output_path,
        config_path=config_path,
    )
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(usda, encoding="utf-8", newline="\n")
    return summary


def _build_argument_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Generate the configured Isaac Sim layout USD from the AutoMod JSON."
    )
    parser.add_argument("--input", type=Path, default=DEFAULT_INPUT)
    parser.add_argument("--config", type=Path, default=DEFAULT_CONFIG)
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT)
    return parser


def main() -> int:
    args = _build_argument_parser().parse_args()
    summary = convert_file(args.input, args.config, args.output)
    print(f"Created: {args.output}")
    print(
        "Layout: "
        f"{summary['clipped_curve_count']} curves, "
        f"{summary['curve_vertex_count']} vertices, "
        f"{summary['control_point_count']} control points"
    )
    print(
        "Stations: "
        f"{summary['station_count']} placed, "
        f"{summary['asset_reference_count']} USD references, "
        f"{summary['unique_local_asset_count']} unique assets"
    )
    if not summary["rail_height_verified"]:
        print(
            "Rail height is intentionally unverified; "
            f"the configured preview height is {summary['rail_height_m']} m."
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
