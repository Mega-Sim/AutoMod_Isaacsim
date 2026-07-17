#!/usr/bin/env python3
"""Tests for spawn_vehicles.py (vehicle placement on a layout USD)."""

import math
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent / "scripts"))

try:
    from pxr import Gf, Sdf, Usd, UsdGeom
    HAS_PXR = True
except ImportError:
    HAS_PXR = False

if HAS_PXR:
    from spawn_vehicles import (find_layout_root, read_control_points,
                                read_fleet, select_spawn_points,
                                spawn_vehicles, valid_prim_name)


def _add_control_point(stage, name, x, y, yaw_rad, cp_type):
    path = f"/World/Layout/ControlPoints/{name}"
    xform = UsdGeom.Xform.Define(stage, path)
    xform.AddTranslateOp().Set(Gf.Vec3d(x, y, 0.0))
    xform.AddRotateZOp().Set(math.degrees(yaw_rad))
    prim = xform.GetPrim()
    prim.CreateAttribute("automod:cpType", Sdf.ValueTypeNames.String,
                         custom=True).Set(cp_type)
    prim.CreateAttribute("automod:tangentYawRad", Sdf.ValueTypeNames.Double,
                         custom=True).Set(yaw_rad)


def _add_vehicle_type(stage, veh_type, numveh):
    path = f"/World/Vehicles/{veh_type}"
    prim = UsdGeom.Xform.Define(stage, path).GetPrim()
    prim.CreateAttribute("automod:vehicleType", Sdf.ValueTypeNames.String,
                         custom=True).Set(veh_type)
    prim.CreateAttribute("automod:numVehicles", Sdf.ValueTypeNames.Int,
                         custom=True).Set(numveh)


def sample_layout_stage(path):
    """Minimal in-memory layout: 4 control points + a small fleet."""
    stage = Usd.Stage.CreateNew(path)
    UsdGeom.SetStageUpAxis(stage, UsdGeom.Tokens.z)
    UsdGeom.SetStageMetersPerUnit(stage, 1.0)
    world = UsdGeom.Xform.Define(stage, "/World")
    stage.SetDefaultPrim(world.GetPrim())
    UsdGeom.Scope.Define(stage, "/World/Layout")
    UsdGeom.Scope.Define(stage, "/World/Layout/ControlPoints")
    _add_control_point(stage, "cp_Park_1", 0.0, 0.0, 0.0, "Park")
    _add_control_point(stage, "cp_Park_2", 10.0, 0.0, math.pi / 2, "Park")
    _add_control_point(stage, "cp_A", 20.0, 5.0, math.pi, "DefaultControlPoint")
    _add_control_point(stage, "cp_B", 30.0, 5.0, 0.0, "steer")
    UsdGeom.Scope.Define(stage, "/World/Vehicles")
    _add_vehicle_type(stage, "EVL", 3)
    _add_vehicle_type(stage, "DefVehicle", 0)
    stage.GetRootLayer().Save()
    return stage


@unittest.skipUnless(HAS_PXR, "pxr (usd-core) not installed")
class TestHelpers(unittest.TestCase):

    def test_select_spawn_points_stride(self):
        pts = ["a", "b", "c", "d"]
        # Fewer than available: even stride, no duplicates.
        self.assertEqual(select_spawn_points(pts, 2), ["a", "c"])
        self.assertEqual(len(set(select_spawn_points(pts, 4))), 4)

    def test_select_spawn_points_cycle(self):
        pts = ["a", "b"]
        # More than available: cycles.
        self.assertEqual(select_spawn_points(pts, 5), ["a", "b", "a", "b", "a"])

    def test_select_spawn_points_empty(self):
        self.assertEqual(select_spawn_points([], 3), [])
        self.assertEqual(select_spawn_points(["a"], 0), [])

    def test_valid_prim_name(self):
        self.assertEqual(valid_prim_name("EVL2"), "EVL2")
        self.assertEqual(valid_prim_name("2fast"), "_2fast")


@unittest.skipUnless(HAS_PXR, "pxr (usd-core) not installed")
class TestReadLayout(unittest.TestCase):

    def setUp(self):
        self.tmpdir = tempfile.TemporaryDirectory()
        self.layout = str(Path(self.tmpdir.name) / "layout.usda")
        self.stage = sample_layout_stage(self.layout)

    def tearDown(self):
        self.tmpdir.cleanup()

    def test_find_layout_root_direct(self):
        self.assertEqual(find_layout_root(self.stage), "/World")

    def test_find_layout_root_referenced(self):
        ref = str(Path(self.tmpdir.name) / "session.usda")
        session = Usd.Stage.CreateNew(ref)
        UsdGeom.Xform.Define(session, "/World")
        prim = session.DefinePrim("/World/AutoModLayout", "Xform")
        prim.GetReferences().AddReference(str(Path(self.layout).resolve()))
        self.assertEqual(find_layout_root(session), "/World/AutoModLayout")

    def test_read_fleet_drops_empty(self):
        fleet = read_fleet(self.stage)
        self.assertEqual(fleet, [("EVL", 3)])

    def test_read_control_points_sorted(self):
        cps = read_control_points(self.stage)
        names = [c[0] for c in cps]
        self.assertEqual(names, sorted(names))
        self.assertEqual(len(cps), 4)

    def test_read_control_points_type_filter(self):
        cps = read_control_points(self.stage, types=["Park"])
        self.assertEqual({c[0] for c in cps}, {"cp_Park_1", "cp_Park_2"})

    def test_read_control_points_yaw(self):
        cps = {c[0]: c[2] for c in read_control_points(self.stage)}
        self.assertAlmostEqual(cps["cp_Park_2"], math.pi / 2, places=6)


@unittest.skipUnless(HAS_PXR, "pxr (usd-core) not installed")
class TestSpawn(unittest.TestCase):

    def setUp(self):
        self.tmpdir = tempfile.TemporaryDirectory()
        self.layout = str(Path(self.tmpdir.name) / "layout.usda")
        self.stage = sample_layout_stage(self.layout)

    def tearDown(self):
        self.tmpdir.cleanup()

    def test_spawn_from_fleet_metadata(self):
        spawned = spawn_vehicles(self.stage)
        self.assertEqual(spawned, {"EVL": 3})
        for i in range(3):
            prim = self.stage.GetPrimAtPath(f"/World/Fleet/EVL/EVL_{i:04d}")
            self.assertTrue(prim.IsValid())
            self.assertEqual(prim.GetAttribute("automod:vehicleType").Get(), "EVL")
        # DefVehicle (numveh=0) was dropped.
        self.assertFalse(self.stage.GetPrimAtPath("/World/Fleet/DefVehicle").IsValid())

    def test_spawn_num_override(self):
        spawned = spawn_vehicles(self.stage, num_override=2, type_filter="AGV")
        self.assertEqual(spawned, {"AGV": 2})
        self.assertTrue(
            self.stage.GetPrimAtPath("/World/Fleet/AGV/AGV_0000").IsValid())

    def test_spawn_position_matches_control_point(self):
        # Spawn 2 EVL restricted to Park points -> stride picks both Park CPs.
        spawn_vehicles(self.stage, num_override=2, type_filter="EVL",
                       at_types=["Park"], size_m=(1.0, 1.0, 0.4))
        prim = self.stage.GetPrimAtPath("/World/Fleet/EVL/EVL_0000")
        translation = UsdGeom.Xformable(prim).GetLocalTransformation()\
            .ExtractTranslation()
        # First Park CP (cp_Park_1) is at (0,0); box lifts by half height 0.2.
        self.assertAlmostEqual(translation[0], 0.0, places=6)
        self.assertAlmostEqual(translation[1], 0.0, places=6)
        self.assertAlmostEqual(translation[2], 0.2, places=6)
        self.assertEqual(prim.GetAttribute("automod:homeControlPoint").Get(),
                         "cp_Park_1")

    def test_spawn_box_proxy_present(self):
        spawn_vehicles(self.stage, num_override=1, type_filter="EVL")
        body = self.stage.GetPrimAtPath("/World/Fleet/EVL/EVL_0000/body")
        self.assertTrue(body.IsValid())
        self.assertTrue(body.IsA(UsdGeom.Cube))

    def test_spawn_rigid_body_api(self):
        spawn_vehicles(self.stage, num_override=1, type_filter="EVL",
                       rigid_body=True)
        prim = self.stage.GetPrimAtPath("/World/Fleet/EVL/EVL_0000")
        applied = prim.GetAppliedSchemas()
        self.assertIn("PhysicsRigidBodyAPI", applied)
        self.assertIn("PhysicsCollisionAPI", applied)

    def test_spawn_max_cap(self):
        spawned = spawn_vehicles(self.stage, num_override=10, type_filter="EVL",
                                 max_vehicles=2)
        self.assertEqual(sum(spawned.values()), 2)

    def test_spawn_no_control_points_raises(self):
        empty = Usd.Stage.CreateInMemory()
        UsdGeom.Xform.Define(empty, "/World")
        with self.assertRaises(RuntimeError):
            spawn_vehicles(empty, num_override=1, type_filter="EVL")


if __name__ == "__main__":
    unittest.main()
