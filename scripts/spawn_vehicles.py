#!/usr/bin/env python3
"""
Spawn vehicle prims onto the AutoMod layout for Isaac Sim (roadmap step 1).

Reads the fleet metadata (``/World/Vehicles/<type>``) and control points
(``.../Layout/ControlPoints/<cp>``) that ``json_to_usd.py`` wrote into the
layout stage, then places one prim per vehicle at a spawn control point, using
the control point's world position and heading (yaw). Each vehicle is either a
referenced USD asset (``--asset``) or a simple box proxy sized like an AGV.

Two ways to use this file:

1. Standalone (produces a fleet USD you can open directly in Isaac Sim GUI):

       python3 scripts/spawn_vehicles.py \
           --layout generated/basic_model_layout.usd \
           --output generated/basic_model_fleet.usd

   The output stage references the layout under ``/World/AutoModLayout`` and
   adds the fleet under ``/World/Fleet`` — open it with ``File > Open``.

2. Script Editor / standalone inside Isaac Sim (spawn into the live stage):

       from spawn_vehicles import spawn_vehicles
       import omni.usd
       spawn_vehicles(omni.usd.get_context().get_stage())

The layout stage is only *read*; vehicles are written to the session/output
stage, so re-running never mutates the layout USD.
"""

import argparse
import math
import sys
from pathlib import Path
from typing import Any, Dict, List, Optional, Sequence, Tuple

try:
    from pxr import Gf, Sdf, Usd, UsdGeom, UsdPhysics, Vt
except ImportError:  # pragma: no cover
    print("ERROR: the 'pxr' module is required. Install with: pip install usd-core",
          file=sys.stderr)
    raise

# Default AGV proxy box size in meters (length X, width Y, height Z).
DEFAULT_VEHICLE_SIZE_M = (1.2, 0.7, 0.4)


# ---------------------------------------------------------------------------
# Reading layout data back out of a USD stage
# ---------------------------------------------------------------------------

def find_layout_root(stage: Usd.Stage) -> str:
    """Return the prim path that holds the ``Layout`` scope.

    Handles both a directly-opened layout (``/World``) and a layout that was
    referenced in via isaacsim_load_layout.py (``/World/AutoModLayout``).
    """
    for candidate in ("/World/AutoModLayout", "/World"):
        if stage.GetPrimAtPath(f"{candidate}/Layout/ControlPoints").IsValid():
            return candidate
    # Fall back to whichever root exposes a Layout scope at all.
    for candidate in ("/World/AutoModLayout", "/World"):
        if stage.GetPrimAtPath(f"{candidate}/Layout").IsValid():
            return candidate
    return "/World"


def read_control_points(stage: Usd.Stage,
                        layout_root: Optional[str] = None,
                        types: Optional[Sequence[str]] = None
                        ) -> List[Tuple[str, Gf.Vec3d, float, str]]:
    """Return ``(name, world_pos, yaw_rad, cp_type)`` for control points.

    Results are sorted by name for deterministic spawning. ``types`` (if given)
    filters to those ``automod:cpType`` values.
    """
    root = layout_root or find_layout_root(stage)
    cps_prim = stage.GetPrimAtPath(f"{root}/Layout/ControlPoints")
    if not cps_prim.IsValid():
        return []
    type_set = {t for t in types} if types else None
    cache = UsdGeom.XformCache()
    out: List[Tuple[str, Gf.Vec3d, float, str]] = []
    for child in cps_prim.GetChildren():
        cp_type_attr = child.GetAttribute("automod:cpType")
        cp_type = cp_type_attr.Get() if cp_type_attr else ""
        if type_set is not None and cp_type not in type_set:
            continue
        transform = cache.GetLocalToWorldTransform(child)
        position = transform.ExtractTranslation()
        yaw_attr = child.GetAttribute("automod:tangentYawRad")
        yaw = float(yaw_attr.Get()) if yaw_attr and yaw_attr.Get() is not None else 0.0
        out.append((child.GetName(), position, yaw, cp_type))
    out.sort(key=lambda item: item[0])
    return out


def read_fleet(stage: Usd.Stage) -> List[Tuple[str, int]]:
    """Return ``(vehicle_type, num_vehicles)`` from ``/World/Vehicles``.

    Types with a non-positive count are dropped.
    """
    vehicles_prim = stage.GetPrimAtPath("/World/Vehicles")
    if not vehicles_prim.IsValid():
        return []
    fleet: List[Tuple[str, int]] = []
    for child in vehicles_prim.GetChildren():
        type_attr = child.GetAttribute("automod:vehicleType")
        num_attr = child.GetAttribute("automod:numVehicles")
        veh_type = type_attr.Get() if type_attr else child.GetName()
        num = int(num_attr.Get()) if num_attr and num_attr.Get() is not None else 0
        if num > 0:
            fleet.append((str(veh_type), num))
    return fleet


# ---------------------------------------------------------------------------
# Spawn point selection
# ---------------------------------------------------------------------------

def select_spawn_points(spawn_points: Sequence[Any], count: int) -> List[Any]:
    """Pick ``count`` spawn points spread evenly across the available list.

    With fewer requested than available, strides through the list so vehicles
    are distributed across the layout instead of clustered. With more requested
    than available, cycles (vehicles will share control points).
    """
    n = len(spawn_points)
    if n == 0 or count <= 0:
        return []
    if count <= n:
        # Even stride so the selection spans the whole layout.
        return [spawn_points[(i * n) // count] for i in range(count)]
    return [spawn_points[i % n] for i in range(count)]


# ---------------------------------------------------------------------------
# Vehicle prim creation
# ---------------------------------------------------------------------------

def valid_prim_name(name: str) -> str:
    """Sanitize an arbitrary string into a valid USD prim identifier."""
    out = "".join(c if c.isalnum() or c == "_" else "_" for c in name)
    if not out or out[0].isdigit():
        out = "_" + out
    return out


def _make_box_proxy(stage: Usd.Stage, prim_path: str,
                    size_m: Tuple[float, float, float],
                    color: Tuple[float, float, float]) -> None:
    """Create a unit Cube scaled to ``size_m`` as a vehicle body proxy."""
    cube = UsdGeom.Cube.Define(stage, f"{prim_path}/body")
    cube.CreateSizeAttr(1.0)
    UsdGeom.Xformable(cube).AddScaleOp().Set(Gf.Vec3f(*size_m))
    cube.CreateDisplayColorAttr(Vt.Vec3fArray([Gf.Vec3f(*color)]))
    half = Gf.Vec3f(0.5, 0.5, 0.5)
    cube.CreateExtentAttr(Vt.Vec3fArray([-half, half]))


def _vehicle_color(veh_type: str) -> Tuple[float, float, float]:
    """Deterministic distinct color per vehicle type."""
    h = (hash(veh_type) & 0xFFFF) / 0xFFFF
    i = int(h * 6) % 6
    f = h * 6 - int(h * 6)
    v, s = 0.95, 0.75
    p, q, t = v * (1 - s), v * (1 - s * f), v * (1 - s * (1 - f))
    return [(v, t, p), (q, v, p), (p, v, t), (p, q, v), (t, p, v), (v, p, q)][i]


def spawn_vehicles(stage: Usd.Stage, *,
                   fleet: Optional[List[Tuple[str, int]]] = None,
                   num_override: Optional[int] = None,
                   type_filter: Optional[str] = None,
                   at_types: Optional[Sequence[str]] = None,
                   asset: Optional[str] = None,
                   size_m: Tuple[float, float, float] = DEFAULT_VEHICLE_SIZE_M,
                   z_offset_m: float = 0.0,
                   rigid_body: bool = False,
                   fleet_root: str = "/World/Fleet",
                   max_vehicles: Optional[int] = None) -> Dict[str, int]:
    """Spawn vehicle prims at layout control points. Returns per-type counts.

    - ``fleet``: explicit ``[(type, count), ...]``; defaults to reading
      ``/World/Vehicles`` from the stage.
    - ``num_override`` / ``type_filter``: spawn exactly ``num_override`` of a
      single ``type_filter`` instead of the fleet metadata.
    - ``at_types``: only spawn on control points of these ``cpType`` values
      (default: all control points).
    - ``asset``: reference this USD as each vehicle body (else a box proxy).
    - ``rigid_body``: tag each vehicle with RigidBody + Collision APIs so it can
      later be driven by physics (requires a PhysicsScene in the stage).
    - ``max_vehicles``: hard cap across all types (for quick previews).
    """
    if num_override is not None:
        fleet = [(type_filter or "EVL", int(num_override))]
    elif fleet is None:
        fleet = read_fleet(stage)
    elif type_filter is not None:
        fleet = [(t, n) for t, n in fleet if t == type_filter]

    spawn_points = read_control_points(stage, types=at_types)
    if not spawn_points:
        raise RuntimeError(
            "No control points found to spawn on. Check the layout is loaded "
            "and (if used) --at types exist.")

    UsdGeom.Scope.Define(stage, fleet_root)
    spawned: Dict[str, int] = {}
    total = 0
    for veh_type, count in fleet:
        if max_vehicles is not None and total >= max_vehicles:
            break
        if max_vehicles is not None:
            count = min(count, max_vehicles - total)
        chosen = select_spawn_points(spawn_points, count)
        color = _vehicle_color(veh_type)
        type_scope = f"{fleet_root}/{valid_prim_name(veh_type)}"
        UsdGeom.Scope.Define(stage, type_scope)
        for i, (cp_name, pos, yaw, _cp_type) in enumerate(chosen):
            prim_path = f"{type_scope}/{valid_prim_name(veh_type)}_{i:04d}"
            xform = UsdGeom.Xform.Define(stage, prim_path)
            # Box proxy rests on the ground: lift by half its height.
            z = pos[2] + z_offset_m + (0.0 if asset else size_m[2] * 0.5)
            xform.AddTranslateOp().Set(Gf.Vec3d(pos[0], pos[1], z))
            xform.AddRotateZOp().Set(math.degrees(yaw))
            prim = xform.GetPrim()
            prim.CreateAttribute("automod:vehicleType", Sdf.ValueTypeNames.String,
                                 custom=True).Set(veh_type)
            prim.CreateAttribute("automod:homeControlPoint",
                                 Sdf.ValueTypeNames.String, custom=True).Set(cp_name)
            prim.CreateAttribute("automod:spawnIndex", Sdf.ValueTypeNames.Int,
                                 custom=True).Set(i)
            if asset:
                UsdGeom.Xform.Define(stage, f"{prim_path}/body")
                stage.GetPrimAtPath(f"{prim_path}/body").GetReferences()\
                    .AddReference(asset)
            else:
                _make_box_proxy(stage, prim_path, size_m, color)
            if rigid_body:
                UsdPhysics.RigidBodyAPI.Apply(prim)
                UsdPhysics.CollisionAPI.Apply(prim)
            total += 1
        spawned[veh_type] = len(chosen)
    return spawned


def spawn_into_current_stage(**kwargs) -> Dict[str, int]:
    """Convenience wrapper for the Isaac Sim Script Editor.

    Uses ``omni.usd`` to grab the live stage, then calls ``spawn_vehicles``.
    """
    import omni.usd  # noqa: local import so the module imports without Isaac Sim
    stage = omni.usd.get_context().get_stage()
    return spawn_vehicles(stage, **kwargs)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def _build_output_stage(layout_usd: str, output_usd: str,
                        z_offset_m: float) -> Usd.Stage:
    """Create an output stage that references the layout under /World.

    Mirrors isaacsim_load_layout.open_layout() so the saved USD opens the same
    way the standalone loader would build it, plus a PhysicsScene for dynamics.
    """
    Path(output_usd).parent.mkdir(parents=True, exist_ok=True)
    stage = Usd.Stage.CreateNew(output_usd)
    UsdGeom.SetStageUpAxis(stage, UsdGeom.Tokens.z)
    UsdGeom.SetStageMetersPerUnit(stage, 1.0)
    world = UsdGeom.Xform.Define(stage, "/World")
    stage.SetDefaultPrim(world.GetPrim())

    layout_prim = stage.DefinePrim("/World/AutoModLayout", "Xform")
    layout_prim.GetReferences().AddReference(str(Path(layout_usd).resolve()))

    scene = UsdPhysics.Scene.Define(stage, "/World/PhysicsScene")
    scene.CreateGravityDirectionAttr(Gf.Vec3f(0.0, 0.0, -1.0))
    scene.CreateGravityMagnitudeAttr(9.81)
    return stage


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Spawn vehicles onto an AutoMod layout USD for Isaac Sim.")
    parser.add_argument("--layout", required=True,
                        help="Layout USD (from json_to_usd.py) to reference")
    parser.add_argument("--output", required=True,
                        help="Output fleet USD to write (.usd/.usdc/.usda)")
    parser.add_argument("--num", type=int, default=None,
                        help="Spawn exactly N vehicles (overrides fleet metadata)")
    parser.add_argument("--type", default=None,
                        help="Vehicle type name (with --num, or to filter fleet)")
    parser.add_argument("--at", default=None,
                        help="Comma-separated control point types to spawn on "
                             "(default: all). e.g. Park,DefaultControlPoint")
    parser.add_argument("--asset", default=None,
                        help="USD asset to reference as each vehicle body "
                             "(default: a box proxy)")
    parser.add_argument("--size", type=float, nargs=3,
                        metavar=("L", "W", "H"), default=list(DEFAULT_VEHICLE_SIZE_M),
                        help="Box proxy size in meters (length width height)")
    parser.add_argument("--z-offset-m", type=float, default=0.0,
                        help="Extra Z height for vehicles, e.g. OHT rail height")
    parser.add_argument("--rigid-body", action="store_true",
                        help="Apply RigidBody + Collision APIs for physics")
    parser.add_argument("--max", type=int, default=None,
                        help="Cap total spawned vehicles (quick previews)")
    args = parser.parse_args()

    layout_stage = Usd.Stage.Open(args.layout)
    if layout_stage is None:
        print(f"ERROR: could not open layout USD: {args.layout}", file=sys.stderr)
        return 1
    fleet = read_fleet(layout_stage)

    at_types = [t.strip() for t in args.at.split(",")] if args.at else None
    stage = _build_output_stage(args.layout, args.output, args.z_offset_m)

    spawned = spawn_vehicles(
        stage,
        fleet=fleet,
        num_override=args.num,
        type_filter=args.type,
        at_types=at_types,
        asset=args.asset,
        size_m=tuple(args.size),
        z_offset_m=args.z_offset_m,
        rigid_body=args.rigid_body,
        max_vehicles=args.max,
    )
    stage.GetRootLayer().Save()

    total = sum(spawned.values())
    print(f"Wrote {args.output}")
    print(f"  layout reference: {args.layout}")
    print(f"  spawned {total} vehicles across {len(spawned)} type(s):")
    for veh_type, n in spawned.items():
        print(f"    {veh_type}: {n}")
    if not spawned:
        print("  (nothing spawned — no fleet with numveh>0 and no --num given)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
