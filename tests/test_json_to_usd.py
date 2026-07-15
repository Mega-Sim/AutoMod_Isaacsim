#!/usr/bin/env python3
"""Tests for json_to_usd.py (layout JSON -> USD stage)."""

import math
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent / "scripts"))

try:
    from pxr import Usd, UsdGeom
    HAS_PXR = True
except ImportError:
    HAS_PXR = False

if HAS_PXR:
    from json_to_usd import (arc_point_at, arc_tangent_at, build_stage,
                             line_point_at, tessellate_path, valid_prim_name)


def sample_layout():
    """Minimal layout: one line path, one arc path, one CP, one vehicle."""
    return {
        "metadata": {"source_file": "test.asy", "arc_chord_error_mm": 5.0},
        "paths": [
            {
                "id": "path1", "name": "path1", "type": "DefaultGuidePath",
                "geometry_type": "line", "length_mm": 1000.0, "length_m": 1.0,
                "geometry": {
                    "type": "line",
                    "begin": {"x": 0.0, "y": 0.0},
                    "end": {"x": 1000.0, "y": 0.0},
                },
            },
            {
                "id": "path2", "name": "path2", "type": "DefaultGuidePath",
                "geometry_type": "arc",
                "length_mm": 1000.0 * math.pi / 2,
                "length_m": math.pi / 2,
                "geometry": {
                    "type": "arc",
                    "center": {"x": 1000.0, "y": 1000.0},
                    "begin": {"x": 1000.0, "y": 0.0},
                    "end": {"x": 2000.0, "y": 1000.0},
                    "radius_mm": 1000.0,
                    "sweep_angle_deg": 90.0,
                    "sweep_angle_rad": math.pi / 2,
                },
            },
        ],
        "nodes": [
            {"id": "node_0", "position_m": {"x": 0.0, "y": 0.0},
             "source_paths": ["path1"], "control_points": []},
            {"id": "node_1", "position_m": {"x": 1.0, "y": 0.0},
             "source_paths": ["path1", "path2"], "control_points": []},
        ],
        "edges": [
            {"id": "edge_path1_0000", "from_node_id": "node_0",
             "to_node_id": "node_1", "source_path_id": "path1",
             "length_m": 1.0, "geometry_type": "line",
             "direction": "forward", "one_way": True,
             "polyline_m": [[0.0, 0.0], [1.0, 0.0]]},
        ],
        "control_points": [
            {"name": "cp_A", "type": "DefaultControlPoint",
             "path_id": "path1", "distance_mm": 500.0, "raw_attributes": {}},
        ],
        "vehicles": [
            {"type": "EVL", "numveh": 150, "start": None, "raw_attributes": {}},
        ],
    }


@unittest.skipUnless(HAS_PXR, "pxr (usd-core) not installed")
class TestGeometry(unittest.TestCase):

    def test_line_point_at(self):
        geom = {"begin": {"x": 0.0, "y": 0.0}, "end": {"x": 1000.0, "y": 0.0}}
        self.assertEqual(line_point_at(geom, 500.0), (500.0, 0.0))
        # Clamped beyond path length
        self.assertEqual(line_point_at(geom, 2000.0), (1000.0, 0.0))

    def test_arc_point_at_quarter(self):
        geom = {"center": {"x": 0.0, "y": 0.0}, "begin": {"x": 1000.0, "y": 0.0},
                "radius_mm": 1000.0, "sweep_angle_rad": math.pi / 2}
        # Full sweep distance lands on (0, 1000) for CCW quarter arc
        x, y = arc_point_at(geom, 1000.0 * math.pi / 2)
        self.assertAlmostEqual(x, 0.0, places=6)
        self.assertAlmostEqual(y, 1000.0, places=6)

    def test_arc_tangent_ccw_start(self):
        geom = {"center": {"x": 0.0, "y": 0.0}, "begin": {"x": 1000.0, "y": 0.0},
                "radius_mm": 1000.0, "sweep_angle_rad": math.pi / 2}
        # At begin of a CCW arc starting at +X, tangent points to +Y
        self.assertAlmostEqual(arc_tangent_at(geom, 0.0), math.pi / 2, places=6)

    def test_tessellate_arc_endpoints(self):
        path = sample_layout()["paths"][1]
        pts = tessellate_path(path, 5.0)
        self.assertGreater(len(pts), 2)
        self.assertAlmostEqual(pts[0][0], 1000.0, places=3)
        self.assertAlmostEqual(pts[0][1], 0.0, places=3)
        self.assertAlmostEqual(pts[-1][0], 2000.0, places=3)
        self.assertAlmostEqual(pts[-1][1], 1000.0, places=3)

    def test_tessellate_chord_error(self):
        path = sample_layout()["paths"][1]
        pts = tessellate_path(path, 5.0)
        cx, cy = 1000.0, 1000.0
        # Midpoints of chords stay within chord error of the true radius
        for (x0, y0), (x1, y1) in zip(pts, pts[1:]):
            mx, my = (x0 + x1) / 2, (y0 + y1) / 2
            dist = math.hypot(mx - cx, my - cy)
            self.assertGreaterEqual(dist, 1000.0 - 5.0 - 1e-6)

    def test_valid_prim_name(self):
        self.assertEqual(valid_prim_name("cp_Park_1"), "cp_Park_1")
        self.assertEqual(valid_prim_name("123abc"), "_123abc")
        self.assertEqual(valid_prim_name("a-b.c"), "a_b_c")


@unittest.skipUnless(HAS_PXR, "pxr (usd-core) not installed")
class TestBuildStage(unittest.TestCase):

    def setUp(self):
        self.tmpdir = tempfile.TemporaryDirectory()
        self.output = str(Path(self.tmpdir.name) / "layout.usda")
        build_stage(sample_layout(), self.output, include_ground=True)
        self.stage = Usd.Stage.Open(self.output)

    def tearDown(self):
        self.tmpdir.cleanup()

    def test_stage_metadata(self):
        self.assertEqual(UsdGeom.GetStageUpAxis(self.stage), UsdGeom.Tokens.z)
        self.assertEqual(UsdGeom.GetStageMetersPerUnit(self.stage), 1.0)
        self.assertEqual(self.stage.GetDefaultPrim().GetName(), "World")

    def test_guide_path_prims(self):
        for name in ("path1", "path2"):
            prim = self.stage.GetPrimAtPath(f"/World/Layout/GuidePaths/{name}")
            self.assertTrue(prim.IsValid())
            self.assertTrue(prim.IsA(UsdGeom.BasisCurves))
        arc = UsdGeom.BasisCurves(
            self.stage.GetPrimAtPath("/World/Layout/GuidePaths/path2"))
        self.assertGreater(len(arc.GetPointsAttr().Get()), 2)

    def test_edge_prim_attributes(self):
        prim = self.stage.GetPrimAtPath("/World/Layout/Edges/edge_path1_0000")
        self.assertTrue(prim.IsValid())
        self.assertEqual(prim.GetAttribute("automod:fromNode").Get(), "node_0")
        self.assertEqual(prim.GetAttribute("automod:toNode").Get(), "node_1")
        self.assertTrue(prim.GetAttribute("automod:oneWay").Get())

    def test_edges_scope_is_guide_purpose(self):
        scope = self.stage.GetPrimAtPath("/World/Layout/Edges")
        self.assertEqual(UsdGeom.Imageable(scope).GetPurposeAttr().Get(),
                         UsdGeom.Tokens.guide)

    def test_nodes_points(self):
        points = UsdGeom.Points(
            self.stage.GetPrimAtPath("/World/Layout/Nodes"))
        self.assertEqual(len(points.GetPointsAttr().Get()), 2)
        ids = points.GetPrim().GetAttribute("automod:nodeIds").Get()
        self.assertEqual(list(ids), ["node_0", "node_1"])

    def test_control_point_position_computed(self):
        prim = self.stage.GetPrimAtPath("/World/Layout/ControlPoints/cp_A")
        self.assertTrue(prim.IsValid())
        translation = UsdGeom.Xformable(prim).GetLocalTransformation()\
            .ExtractTranslation()
        # cp_A at 500 mm along path1 (0,0)->(1000,0) => (0.5 m, 0)
        self.assertAlmostEqual(translation[0], 0.5, places=6)
        self.assertAlmostEqual(translation[1], 0.0, places=6)
        self.assertAlmostEqual(
            prim.GetAttribute("automod:distanceMm").Get(), 500.0)
        marker = self.stage.GetPrimAtPath(
            "/World/Layout/ControlPoints/cp_A/marker")
        self.assertTrue(marker.IsA(UsdGeom.Sphere))

    def test_vehicle_metadata(self):
        prim = self.stage.GetPrimAtPath("/World/Vehicles/EVL")
        self.assertTrue(prim.IsValid())
        self.assertEqual(prim.GetAttribute("automod:numVehicles").Get(), 150)

    def test_ground_plane(self):
        prim = self.stage.GetPrimAtPath("/World/GroundPlane")
        self.assertTrue(prim.IsValid())
        self.assertTrue(prim.IsA(UsdGeom.Mesh))

    def test_no_edges_option(self):
        output = str(Path(self.tmpdir.name) / "no_edges.usda")
        build_stage(sample_layout(), output, include_edges=False)
        stage = Usd.Stage.Open(output)
        self.assertFalse(
            stage.GetPrimAtPath("/World/Layout/Edges/edge_path1_0000").IsValid())


if __name__ == "__main__":
    unittest.main()
