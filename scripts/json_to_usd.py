#!/usr/bin/env python3
"""
Isaac Sim layout JSON to USD converter.

Reads the layout JSON produced by pm_asy_to_json.py and generates a USD stage
(Z-up, meters) that can be opened directly in NVIDIA Isaac Sim / USD Composer.

Stage structure:

    /World                          (Xform, defaultPrim)
      /Layout
        /GuidePaths/<path_id>       BasisCurves - source GPATH geometry
        /Edges/<edge_id>            BasisCurves - graph edges (purpose=guide)
        /Nodes                      Points     - graph node positions
        /ControlPoints/<cp_name>    Xform+Sphere - control point markers
      /Vehicles/<type>              Xform      - vehicle fleet metadata
      /GroundPlane                  Mesh       - optional (--ground)

AutoMod semantics (graph connectivity, distances, vehicle counts, ...) are
stored as custom attributes in the "automod:" namespace so that digital twin
logic can query them from the USD stage.
"""

import argparse
import json
import math
import sys
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

try:
    from pxr import Gf, Sdf, Usd, UsdGeom, Vt
except ImportError:  # pragma: no cover
    print("ERROR: the 'pxr' module is required. Install with: pip install usd-core",
          file=sys.stderr)
    raise

MM_TO_M = 0.001


# ---------------------------------------------------------------------------
# Geometry evaluation (mirrors pm_asy_to_json.py conventions)
# ---------------------------------------------------------------------------

def line_point_at(geom: Dict[str, Any], distance_mm: float) -> Tuple[float, float]:
    """Point on a line path at distance from begin (mm in, mm out)."""
    bx, by = geom["begin"]["x"], geom["begin"]["y"]
    ex, ey = geom["end"]["x"], geom["end"]["y"]
    length = math.hypot(ex - bx, ey - by)
    t = 0.0 if length == 0 else max(0.0, min(1.0, distance_mm / length))
    return bx + (ex - bx) * t, by + (ey - by) * t


def line_tangent_at(geom: Dict[str, Any]) -> float:
    """Tangent angle (radians) of a line path."""
    bx, by = geom["begin"]["x"], geom["begin"]["y"]
    ex, ey = geom["end"]["x"], geom["end"]["y"]
    return math.atan2(ey - by, ex - bx)


def arc_point_at(geom: Dict[str, Any], distance_mm: float) -> Tuple[float, float]:
    """Point on an arc path at distance from begin (mm in, mm out)."""
    cx, cy = geom["center"]["x"], geom["center"]["y"]
    bx, by = geom["begin"]["x"], geom["begin"]["y"]
    radius = geom["radius_mm"]
    sweep = geom["sweep_angle_rad"]
    if radius <= 0:
        return bx, by
    angle = math.copysign(min(abs(distance_mm) / radius, abs(sweep)), sweep)
    cos_a, sin_a = math.cos(angle), math.sin(angle)
    dx, dy = bx - cx, by - cy
    return cx + dx * cos_a - dy * sin_a, cy + dx * sin_a + dy * cos_a


def arc_tangent_at(geom: Dict[str, Any], distance_mm: float) -> float:
    """Tangent angle (radians) of an arc path at distance from begin."""
    cx, cy = geom["center"]["x"], geom["center"]["y"]
    px, py = arc_point_at(geom, distance_mm)
    radial = math.atan2(py - cy, px - cx)
    sweep = geom["sweep_angle_rad"]
    return radial + math.copysign(math.pi / 2.0, sweep)


def path_point_and_yaw(path: Dict[str, Any],
                       distance_mm: float) -> Tuple[float, float, float]:
    """Evaluate (x_mm, y_mm, yaw_rad) on a path record at a distance."""
    geom = path["geometry"]
    if path["geometry_type"] == "arc":
        x, y = arc_point_at(geom, distance_mm)
        yaw = arc_tangent_at(geom, distance_mm)
    else:
        x, y = line_point_at(geom, distance_mm)
        yaw = line_tangent_at(geom)
    return x, y, yaw


def tessellate_path(path: Dict[str, Any],
                    chord_error_mm: float) -> List[Tuple[float, float]]:
    """Polyline approximation of a path (mm). Lines yield two points."""
    geom = path["geometry"]
    if path["geometry_type"] != "arc":
        return [(geom["begin"]["x"], geom["begin"]["y"]),
                (geom["end"]["x"], geom["end"]["y"])]

    radius = geom["radius_mm"]
    sweep = geom["sweep_angle_rad"]
    if radius <= 0 or sweep == 0:
        return [(geom["begin"]["x"], geom["begin"]["y"]),
                (geom["end"]["x"], geom["end"]["y"])]

    # Max angle per segment so the chord sagitta stays under chord_error_mm.
    err = max(min(chord_error_mm, radius), 1e-6)
    max_angle = 2.0 * math.acos(max(-1.0, min(1.0, 1.0 - err / radius)))
    segments = max(1, math.ceil(abs(sweep) / max_angle))
    length = radius * abs(sweep)
    return [arc_point_at(geom, length * i / segments) for i in range(segments + 1)]


# ---------------------------------------------------------------------------
# USD helpers
# ---------------------------------------------------------------------------

def valid_prim_name(name: str) -> str:
    """Sanitize an arbitrary string into a valid USD prim identifier."""
    out = "".join(c if c.isalnum() or c == "_" else "_" for c in name)
    if not out or out[0].isdigit():
        out = "_" + out
    return out


def set_automod_attr(prim: Usd.Prim, name: str, value: Any) -> None:
    """Create a custom attribute in the automod: namespace."""
    if isinstance(value, bool):
        type_name = Sdf.ValueTypeNames.Bool
    elif isinstance(value, int):
        type_name = Sdf.ValueTypeNames.Int
    elif isinstance(value, float):
        type_name = Sdf.ValueTypeNames.Double
    else:
        type_name = Sdf.ValueTypeNames.String
        value = str(value)
    attr = prim.CreateAttribute(f"automod:{name}", type_name, custom=True)
    attr.Set(value)


def make_curve(stage: Usd.Stage, prim_path: str,
               points_m: List[Tuple[float, float]],
               width_m: float,
               color: Tuple[float, float, float],
               z_m: float = 0.0) -> UsdGeom.BasisCurves:
    """Create a linear BasisCurves prim from a 2D polyline (meters)."""
    curves = UsdGeom.BasisCurves.Define(stage, prim_path)
    curves.CreateTypeAttr(UsdGeom.Tokens.linear)
    vt_points = Vt.Vec3fArray([Gf.Vec3f(x, y, z_m) for x, y in points_m])
    curves.CreatePointsAttr(vt_points)
    curves.CreateCurveVertexCountsAttr(Vt.IntArray([len(points_m)]))
    curves.CreateWidthsAttr(Vt.FloatArray([width_m]))
    curves.SetWidthsInterpolation(UsdGeom.Tokens.constant)
    curves.CreateDisplayColorAttr(Vt.Vec3fArray([Gf.Vec3f(*color)]))
    extent = UsdGeom.PointBased(curves).ComputeExtent(vt_points)
    curves.CreateExtentAttr(extent)
    return curves


def cp_type_color(cp_type: str) -> Tuple[float, float, float]:
    """Deterministic distinct color per control point type."""
    h = (hash(cp_type) & 0xFFFF) / 0xFFFF
    # Simple HSV(h, 0.65, 0.9) to RGB
    i = int(h * 6) % 6
    f = h * 6 - int(h * 6)
    v, s = 0.9, 0.65
    p, q, t = v * (1 - s), v * (1 - s * f), v * (1 - s * (1 - f))
    return [(v, t, p), (q, v, p), (p, v, t), (p, q, v), (t, p, v), (v, p, q)][i]


# ---------------------------------------------------------------------------
# Stage building
# ---------------------------------------------------------------------------

def build_stage(data: Dict[str, Any], output: str, *,
                path_width_m: float = 0.05,
                edge_width_m: float = 0.03,
                cp_radius_m: float = 0.15,
                node_size_m: float = 0.08,
                include_edges: bool = True,
                include_ground: bool = False,
                z_paths_m: float = 0.0) -> Usd.Stage:
    """Build and save a USD stage from layout JSON data."""
    stage = Usd.Stage.CreateNew(output)
    UsdGeom.SetStageUpAxis(stage, UsdGeom.Tokens.z)
    UsdGeom.SetStageMetersPerUnit(stage, 1.0)

    world = UsdGeom.Xform.Define(stage, "/World")
    stage.SetDefaultPrim(world.GetPrim())

    meta = data.get("metadata", {})
    set_automod_attr(world.GetPrim(), "sourceFile", meta.get("source_file", ""))

    layout = UsdGeom.Scope.Define(stage, "/World/Layout")
    chord_error_mm = float(meta.get("arc_chord_error_mm", 5.0))

    # --- Guide paths (source GPATH geometry) ------------------------------
    paths_by_id: Dict[str, Dict[str, Any]] = {}
    UsdGeom.Scope.Define(stage, "/World/Layout/GuidePaths")
    for path in data.get("paths", []):
        paths_by_id[path["id"]] = path
        pts_mm = tessellate_path(path, chord_error_mm)
        pts_m = [(x * MM_TO_M, y * MM_TO_M) for x, y in pts_mm]
        prim_path = f"/World/Layout/GuidePaths/{valid_prim_name(path['id'])}"
        curve = make_curve(stage, prim_path, pts_m, path_width_m,
                           (0.25, 0.45, 0.85), z_paths_m)
        prim = curve.GetPrim()
        set_automod_attr(prim, "pathType", path.get("type", ""))
        set_automod_attr(prim, "geometryType", path.get("geometry_type", ""))
        set_automod_attr(prim, "lengthM", float(path.get("length_m", 0.0)))

    # --- Graph edges (navigation graph, hidden guide geometry) ------------
    if include_edges:
        edges_scope = UsdGeom.Scope.Define(stage, "/World/Layout/Edges")
        UsdGeom.Imageable(edges_scope.GetPrim()).CreatePurposeAttr(
            UsdGeom.Tokens.guide)
        for edge in data.get("edges", []):
            polyline = edge.get("polyline_m") or []
            if len(polyline) < 2:
                continue
            prim_path = f"/World/Layout/Edges/{valid_prim_name(edge['id'])}"
            curve = make_curve(stage, prim_path,
                               [(p[0], p[1]) for p in polyline],
                               edge_width_m, (0.9, 0.6, 0.1), z_paths_m)
            prim = curve.GetPrim()
            set_automod_attr(prim, "fromNode", edge.get("from_node_id", ""))
            set_automod_attr(prim, "toNode", edge.get("to_node_id", ""))
            set_automod_attr(prim, "sourcePath", edge.get("source_path_id", ""))
            set_automod_attr(prim, "lengthM", float(edge.get("length_m", 0.0)))
            set_automod_attr(prim, "oneWay", bool(edge.get("one_way", True)))
            set_automod_attr(prim, "direction", edge.get("direction", "forward"))

    # --- Graph nodes as a single Points prim -------------------------------
    nodes = data.get("nodes", [])
    if nodes:
        points = UsdGeom.Points.Define(stage, "/World/Layout/Nodes")
        vt_points = Vt.Vec3fArray([
            Gf.Vec3f(n["position_m"]["x"], n["position_m"]["y"], z_paths_m)
            for n in nodes])
        points.CreatePointsAttr(vt_points)
        points.CreateWidthsAttr(Vt.FloatArray([node_size_m] * len(nodes)))
        points.CreateDisplayColorAttr(Vt.Vec3fArray([Gf.Vec3f(0.2, 0.8, 0.3)]))
        extent = UsdGeom.PointBased(points).ComputeExtent(vt_points)
        points.CreateExtentAttr(extent)
        ids_attr = points.GetPrim().CreateAttribute(
            "automod:nodeIds", Sdf.ValueTypeNames.StringArray, custom=True)
        ids_attr.Set(Vt.StringArray([n["id"] for n in nodes]))

    # --- Control points as oriented Xform markers --------------------------
    UsdGeom.Scope.Define(stage, "/World/Layout/ControlPoints")
    skipped_cps = []
    for cp in data.get("control_points", []):
        pos = cp.get("position_m")
        yaw = cp.get("tangent_yaw_rad")
        if pos is not None:
            x_m, y_m = pos["x"], pos["y"]
            yaw = yaw if yaw is not None else 0.0
        else:
            path = paths_by_id.get(cp.get("path_id"))
            if path is None:
                skipped_cps.append(cp["name"])
                continue
            x_mm, y_mm, yaw = path_point_and_yaw(path, float(cp["distance_mm"]))
            x_m, y_m = x_mm * MM_TO_M, y_mm * MM_TO_M

        prim_path = f"/World/Layout/ControlPoints/{valid_prim_name(cp['name'])}"
        xform = UsdGeom.Xform.Define(stage, prim_path)
        xform.AddTranslateOp().Set(Gf.Vec3d(x_m, y_m, z_paths_m))
        xform.AddRotateZOp().Set(math.degrees(yaw))
        prim = xform.GetPrim()
        set_automod_attr(prim, "cpType", cp.get("type", ""))
        set_automod_attr(prim, "sourcePath", cp.get("path_id", ""))
        set_automod_attr(prim, "distanceMm", float(cp.get("distance_mm", 0.0)))
        set_automod_attr(prim, "tangentYawRad", float(yaw))

        marker = UsdGeom.Sphere.Define(stage, prim_path + "/marker")
        marker.CreateRadiusAttr(cp_radius_m)
        color = cp_type_color(cp.get("type", ""))
        marker.CreateDisplayColorAttr(Vt.Vec3fArray([Gf.Vec3f(*color)]))
        r = cp_radius_m
        marker.CreateExtentAttr(Vt.Vec3fArray(
            [Gf.Vec3f(-r, -r, -r), Gf.Vec3f(r, r, r)]))

    # --- Vehicle fleet metadata --------------------------------------------
    vehicles = data.get("vehicles", [])
    if vehicles:
        UsdGeom.Scope.Define(stage, "/World/Vehicles")
        for veh in vehicles:
            prim_path = f"/World/Vehicles/{valid_prim_name(veh['type'])}"
            xform = UsdGeom.Xform.Define(stage, prim_path)
            prim = xform.GetPrim()
            set_automod_attr(prim, "vehicleType", veh.get("type", ""))
            set_automod_attr(prim, "numVehicles", int(veh.get("numveh", 0)))
            if veh.get("start"):
                set_automod_attr(prim, "start", veh["start"])

    # --- Optional ground plane ---------------------------------------------
    if include_ground and nodes:
        xs = [n["position_m"]["x"] for n in nodes]
        ys = [n["position_m"]["y"] for n in nodes]
        margin = 5.0
        x0, x1 = min(xs) - margin, max(xs) + margin
        y0, y1 = min(ys) - margin, max(ys) + margin
        mesh = UsdGeom.Mesh.Define(stage, "/World/GroundPlane")
        pts = Vt.Vec3fArray([Gf.Vec3f(x0, y0, -0.01), Gf.Vec3f(x1, y0, -0.01),
                             Gf.Vec3f(x1, y1, -0.01), Gf.Vec3f(x0, y1, -0.01)])
        mesh.CreatePointsAttr(pts)
        mesh.CreateFaceVertexCountsAttr(Vt.IntArray([4]))
        mesh.CreateFaceVertexIndicesAttr(Vt.IntArray([0, 1, 2, 3]))
        mesh.CreateDisplayColorAttr(Vt.Vec3fArray([Gf.Vec3f(0.35, 0.35, 0.35)]))
        mesh.CreateExtentAttr(UsdGeom.PointBased(mesh).ComputeExtent(pts))

    if skipped_cps:
        print(f"WARNING: skipped {len(skipped_cps)} control points with "
              f"unknown paths: {skipped_cps[:5]}...", file=sys.stderr)

    stage.GetRootLayer().Save()
    return stage


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main() -> int:
    parser = argparse.ArgumentParser(
        description="Convert AutoMod layout JSON to a USD stage for Isaac Sim.")
    parser.add_argument("--input", required=True, help="Layout JSON file")
    parser.add_argument("--output", required=True,
                        help="Output USD file (.usda text / .usd or .usdc binary)")
    parser.add_argument("--path-width-m", type=float, default=0.05,
                        help="Guide path curve width in meters (default: 0.05)")
    parser.add_argument("--edge-width-m", type=float, default=0.03,
                        help="Edge curve width in meters (default: 0.03)")
    parser.add_argument("--cp-radius-m", type=float, default=0.15,
                        help="Control point marker radius in meters (default: 0.15)")
    parser.add_argument("--no-edges", action="store_true",
                        help="Skip graph edge prims (smaller file)")
    parser.add_argument("--ground", action="store_true",
                        help="Add a ground plane sized to the layout")
    parser.add_argument("--z-offset-m", type=float, default=0.0,
                        help="Z height of the layout, e.g. OHT rail height (default: 0)")
    args = parser.parse_args()

    with open(args.input, encoding="utf-8") as f:
        data = json.load(f)

    Path(args.output).parent.mkdir(parents=True, exist_ok=True)
    stage = build_stage(
        data, args.output,
        path_width_m=args.path_width_m,
        edge_width_m=args.edge_width_m,
        cp_radius_m=args.cp_radius_m,
        include_edges=not args.no_edges,
        include_ground=args.ground,
        z_paths_m=args.z_offset_m,
    )

    counts = {
        "guide_paths": len(data.get("paths", [])),
        "edges": 0 if args.no_edges else len(data.get("edges", [])),
        "nodes": len(data.get("nodes", [])),
        "control_points": len(data.get("control_points", [])),
        "vehicles": len(data.get("vehicles", [])),
    }
    print(f"Wrote {args.output}")
    for key, value in counts.items():
        print(f"  {key}: {value}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
