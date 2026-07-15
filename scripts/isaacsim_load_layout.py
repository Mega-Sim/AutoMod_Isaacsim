#!/usr/bin/env python3
"""
Load the AutoMod layout USD into NVIDIA Isaac Sim.

Two ways to use this file:

1. Standalone (headless or GUI), from the Isaac Sim install directory:

       ./python.sh /path/to/AutoMod_Isaacsim/scripts/isaacsim_load_layout.py \
           --usd /path/to/AutoMod_Isaacsim/generated/basic_model_layout.usd

2. Script Editor inside the Isaac Sim GUI (Window > Script Editor):
   copy the `open_layout()` body and run it directly (SimulationApp not needed).

The layout USD is referenced (not opened in place), so vehicles, sensors, and
physics can be added to the session stage without modifying the layout file.
"""

import argparse
import sys


def parse_args():
    parser = argparse.ArgumentParser(
        description="Load AutoMod layout USD into Isaac Sim.")
    parser.add_argument("--usd", required=True, help="Layout USD file path")
    parser.add_argument("--headless", action="store_true",
                        help="Run without the Isaac Sim GUI")
    parser.add_argument("--frames", type=int, default=0,
                        help="Render N frames then exit (0 = keep running)")
    return parser.parse_args()


def open_layout(usd_path: str):
    """Reference the layout USD into the current stage and add light/ground.

    This function only uses omni.usd / pxr and can be pasted into the
    Isaac Sim Script Editor as-is.
    """
    import omni.usd
    from pxr import Gf, Sdf, Usd, UsdGeom, UsdLux, UsdPhysics

    context = omni.usd.get_context()
    stage = context.get_stage()

    UsdGeom.SetStageUpAxis(stage, UsdGeom.Tokens.z)
    UsdGeom.SetStageMetersPerUnit(stage, 1.0)

    # Reference the layout under /World/AutoModLayout
    layout_prim = stage.DefinePrim("/World/AutoModLayout", "Xform")
    layout_prim.GetReferences().AddReference(usd_path)

    # Dome light so curves and markers are visible
    if not stage.GetPrimAtPath("/World/DomeLight"):
        dome = UsdLux.DomeLight.Define(stage, "/World/DomeLight")
        dome.CreateIntensityAttr(1000.0)

    # Physics scene (needed once vehicles are simulated)
    if not stage.GetPrimAtPath("/World/PhysicsScene"):
        scene = UsdPhysics.Scene.Define(stage, "/World/PhysicsScene")
        scene.CreateGravityDirectionAttr(Gf.Vec3f(0.0, 0.0, -1.0))
        scene.CreateGravityMagnitudeAttr(9.81)

    return layout_prim


def iter_control_points(stage, layout_root="/World/AutoModLayout"):
    """Yield (name, position, cp_type) for every control point in the layout.

    Example of reading AutoMod semantics back out of the USD stage
    for digital twin logic (dispatching, station handling, ...).
    """
    from pxr import UsdGeom

    cps_path = f"{layout_root}/Layout/ControlPoints"
    cps_prim = stage.GetPrimAtPath(cps_path)
    if not cps_prim.IsValid():
        return
    cache = UsdGeom.XformCache()
    for child in cps_prim.GetChildren():
        transform = cache.GetLocalToWorldTransform(child)
        position = transform.ExtractTranslation()
        cp_type_attr = child.GetAttribute("automod:cpType")
        cp_type = cp_type_attr.Get() if cp_type_attr else ""
        yield child.GetName(), position, cp_type


def build_edge_graph(stage, layout_root="/World/AutoModLayout"):
    """Reconstruct the navigation graph {from_node: [(to_node, length_m, edge_prim)]}.

    Useful for AGV/OHT path planning on top of the imported layout.
    """
    graph = {}
    edges_prim = stage.GetPrimAtPath(f"{layout_root}/Layout/Edges")
    if not edges_prim.IsValid():
        return graph
    for edge in edges_prim.GetChildren():
        from_node = edge.GetAttribute("automod:fromNode").Get()
        to_node = edge.GetAttribute("automod:toNode").Get()
        length_m = edge.GetAttribute("automod:lengthM").Get()
        graph.setdefault(from_node, []).append((to_node, length_m, edge))
    return graph


def main():
    args = parse_args()

    # SimulationApp must be created before importing omni.* modules
    from isaacsim import SimulationApp  # Isaac Sim >= 4.0
    app = SimulationApp({"headless": args.headless})

    import omni.usd
    open_layout(args.usd)

    stage = omni.usd.get_context().get_stage()
    cps = list(iter_control_points(stage))
    graph = build_edge_graph(stage)
    print(f"Loaded layout: {len(cps)} control points, "
          f"{sum(len(v) for v in graph.values())} graph edges")

    if args.frames > 0:
        for _ in range(args.frames):
            app.update()
        app.close()
    else:
        while app.is_running():
            app.update()
        app.close()
    return 0


if __name__ == "__main__":
    sys.exit(main())
