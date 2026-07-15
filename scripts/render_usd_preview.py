#!/usr/bin/env python3
"""
Render a top-down preview PNG from a USD layout stage.

This reads geometry back out of the USD file (not the JSON) to verify that the
stage produced by json_to_usd.py is geometrically correct, and to preview how
the layout will look before opening it in Isaac Sim.

    python3 scripts/render_usd_preview.py \
        --usd generated/basic_model_layout.usd \
        --output generated/basic_model_layout_preview.png

Requires: usd-core, matplotlib.
"""

import argparse
import sys

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.collections import LineCollection

from pxr import Usd, UsdGeom


def collect_curves(stage, scope_path):
    """Return [[(x, y), ...], ...] polylines from BasisCurves under a scope."""
    polylines = []
    scope = stage.GetPrimAtPath(scope_path)
    if not scope.IsValid():
        return polylines
    for prim in Usd.PrimRange(scope):
        if not prim.IsA(UsdGeom.BasisCurves):
            continue
        pts = UsdGeom.BasisCurves(prim).GetPointsAttr().Get()
        if pts:
            polylines.append([(p[0], p[1]) for p in pts])
    return polylines


def collect_control_points(stage):
    """Return (xs, ys) world positions of control point markers."""
    xs, ys = [], []
    cps = stage.GetPrimAtPath("/World/Layout/ControlPoints")
    if not cps.IsValid():
        return xs, ys
    cache = UsdGeom.XformCache()
    for child in cps.GetChildren():
        pos = cache.GetLocalToWorldTransform(child).ExtractTranslation()
        xs.append(pos[0])
        ys.append(pos[1])
    return xs, ys


def main():
    parser = argparse.ArgumentParser(
        description="Render a top-down preview PNG from a USD layout stage.")
    parser.add_argument("--usd", required=True, help="Input USD stage")
    parser.add_argument("--output", required=True, help="Output PNG path")
    parser.add_argument("--dpi", type=int, default=120, help="Image DPI")
    parser.add_argument("--title", default=None, help="Plot title")
    args = parser.parse_args()

    stage = Usd.Stage.Open(args.usd)
    if not stage:
        print(f"ERROR: cannot open {args.usd}", file=sys.stderr)
        return 1

    guide = collect_curves(stage, "/World/Layout/GuidePaths")
    edges = collect_curves(stage, "/World/Layout/Edges")
    cp_xs, cp_ys = collect_control_points(stage)

    fig, ax = plt.subplots(figsize=(14, 13), dpi=args.dpi)
    if guide:
        ax.add_collection(LineCollection(guide, colors="#3b6fd4",
                                         linewidths=0.7, label="Guide paths"))
    if edges:
        ax.add_collection(LineCollection(edges, colors="#e6a020",
                                         linewidths=1.4, alpha=0.7,
                                         label="Graph edges"))
    if cp_xs:
        ax.scatter(cp_xs, cp_ys, s=8, c="#e0522d", zorder=3,
                   label=f"Control points ({len(cp_xs)})")

    ax.set_aspect("equal")
    ax.autoscale()
    ax.set_xlabel("X (m)")
    ax.set_ylabel("Y (m)")
    ax.set_title(args.title or f"USD preview — {args.usd}\n"
                 f"guide paths: {len(guide)}, edges: {len(edges)}, "
                 f"control points: {len(cp_xs)}")
    ax.legend(loc="upper right")
    ax.grid(True, alpha=0.25)
    plt.tight_layout()
    plt.savefig(args.output)
    print(f"Wrote {args.output}")
    print(f"  guide paths: {len(guide)}, edges: {len(edges)}, "
          f"control points: {len(cp_xs)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
