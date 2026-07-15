import json
import math
import tempfile
import unittest
from pathlib import Path

from scripts.pm_asy_to_json import build_layout, convert_file, parse_pm_asy


REPO_ROOT = Path(__file__).resolve().parents[1]
PM_ASY = REPO_ROOT / "data" / "raw" / "basic_model" / "model.arc" / "pm.asy"


class PmAsyConversionTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.parsed = parse_pm_asy(PM_ASY)
        cls.layout = build_layout(cls.parsed)

    def test_source_record_counts(self):
        paths = self.parsed["paths"]
        self.assertEqual(1_637, len(paths))
        self.assertEqual(641, sum(path["geometry_type"] == "line" for path in paths))
        self.assertEqual(996, sum(path["geometry_type"] == "arc" for path in paths))
        self.assertEqual(468, len(self.parsed["control_points"]))
        self.assertEqual(8, len(self.parsed["control_point_types"]))
        self.assertEqual(3, len(self.parsed["vehicles"]))
        self.assertEqual(4, len(self.parsed["name_lists"]))

    def test_reference_and_distance_validation(self):
        self.assertEqual([], self.layout["validation"]["errors"])
        paths = {path["id"]: path for path in self.parsed["paths"]}
        for point in self.parsed["control_points"]:
            self.assertIn(point["source_path_id"], paths)
            self.assertGreaterEqual(point["distance_from_path_start_mm"], 0.0)
            self.assertLessEqual(
                point["distance_from_path_start_mm"],
                paths[point["source_path_id"]]["length_mm"] + 1e-6,
            )

    def test_known_arc_endpoint(self):
        path = next(path for path in self.parsed["paths"] if path["id"] == "path100901")
        self.assertEqual("arc", path["geometry_type"])
        self.assertAlmostEqual(45.0, path["sweep_degrees"], delta=0.001)
        self.assertAlmostEqual(91_307.624, path["end"][0], places=2)
        self.assertAlmostEqual(110_974.984, path["end"][1], places=2)
        self.assertGreater(path["length_mm"], 350.0)

    def test_cp_at_path_end_reuses_endpoint_node(self):
        point = next(
            point for point in self.layout["control_points"] if point["id"] == "cp_a_324"
        )
        path = next(path for path in self.layout["source_paths"] if path["id"] == "path30")
        self.assertAlmostEqual(1.0, point["normalized_distance"], places=9)
        node = next(
            node for node in self.layout["nodes"] if node["id"] == point["graph_node_id"]
        )
        self.assertEqual(path["end_m"], node["position_m"])

    def test_station_and_routing_classification(self):
        self.assertEqual(173, len(self.layout["stations"]))
        self.assertEqual(295, len(self.layout["routing_control_points"]))
        station_ids = {station["id"] for station in self.layout["stations"]}
        routing_ids = {point["id"] for point in self.layout["routing_control_points"]}
        self.assertIn("cp_UTB_1_20", station_ids)
        self.assertNotIn("cp_UTB_1_20", routing_ids)
        self.assertIn("cp_out_1", routing_ids)
        self.assertIn("cp_Out_1", station_ids)

    def test_edges_are_directed_and_references_resolve(self):
        node_ids = {node["id"] for node in self.layout["nodes"]}
        self.assertGreater(len(self.layout["edges"]), len(self.layout["source_paths"]))
        for edge in self.layout["edges"]:
            self.assertIn(edge["from_node_id"], node_ids)
            self.assertIn(edge["to_node_id"], node_ids)
            self.assertEqual("forward", edge["direction"])
            self.assertTrue(edge["one_way"])
            self.assertGreater(edge["length_m"], 0.0)
            self.assertGreaterEqual(len(edge["polyline_m"]), 2)

    def test_name_lists_are_merged_and_nested_members_resolved(self):
        lists = {item["id"]: item for item in self.layout["name_lists"]}
        self.assertEqual({"NAME_ALL", "line5_6", "EQ11_12", "aa"}, set(lists))
        self.assertIn("line5_6", lists["NAME_ALL"]["nested_name_lists"])
        self.assertIn("cp_A01001", lists["NAME_ALL"]["resolved_control_point_members"])

    def test_vehicle_motion_profile(self):
        vehicles = {vehicle["id"]: vehicle for vehicle in self.layout["vehicle_definitions"]}
        self.assertEqual(150, vehicles["EVL"]["vehicle_count"])
        self.assertEqual("Random", vehicles["EVL"]["start"])
        self.assertAlmostEqual(0.3, vehicles["EVL"]["motion_profiles"]["Default"]["accel"]["value"])
        self.assertAlmostEqual(1.0, vehicles["EVL"]["motion_profiles"]["Default"]["vel"]["value"])
        self.assertAlmostEqual(1.7, vehicles["EVL"]["motion_profiles"]["Default"]["brakedist"]["value"])
        segment = self.layout["vehicle_segments"][0]
        self.assertEqual([0.0, 0.0, 0.0], segment["pickup_attachment_point"]["translation_mm"])

    def test_json_output_is_valid_and_finite(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            output = Path(temp_dir) / "layout.json"
            layout = convert_file(PM_ASY, output)
            loaded = json.loads(output.read_text(encoding="utf-8"))
            self.assertEqual(layout["validation"]["summary"], loaded["validation"]["summary"])
            self.assertNotIn("NaN", output.read_text(encoding="utf-8"))
            self.assertNotIn("Infinity", output.read_text(encoding="utf-8"))
            for station in loaded["stations"]:
                self.assertTrue(math.isfinite(station["tangent_yaw_rad"]))


if __name__ == "__main__":
    unittest.main()
