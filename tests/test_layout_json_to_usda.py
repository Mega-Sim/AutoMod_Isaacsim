import json
import tempfile
import unittest
from pathlib import Path

from scripts.layout_json_to_usda import (
    build_usda,
    clip_polyline_to_bounds,
    compute_control_point_bounds,
    convert_file,
    select_control_point_region,
)


REPO_ROOT = Path(__file__).resolve().parents[1]
LAYOUT_JSON = REPO_ROOT / "generated" / "basic_model_layout.json"
COMMITTED_USDA = REPO_ROOT / "generated" / "basic_model_control_point_region.usda"


class LayoutJsonToUsdaTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.layout = json.loads(LAYOUT_JSON.read_text(encoding="utf-8"))
        cls.region = select_control_point_region(cls.layout)

    def test_control_point_region_matches_dense_lower_left_layout(self):
        bounds = compute_control_point_bounds(self.layout)
        expected = (-118.51592522378684, -96.24273, -7.82, -11.894719)
        for actual, target in zip(bounds, expected):
            self.assertAlmostEqual(target, actual, places=9)

        self.assertEqual(322, len(self.region["selected_source_path_ids"]))
        self.assertEqual(322, len(self.region["curves"]))
        self.assertEqual(468, len(self.region["control_points"]))
        self.assertEqual(295, len(self.region["routing_control_points"]))
        self.assertEqual(173, len(self.region["stations"]))

    def test_every_clipped_curve_vertex_is_inside_region(self):
        min_x, min_y, max_x, max_y = self.region["bounds_m"]
        for curve in self.region["curves"]:
            self.assertGreaterEqual(len(curve["points"]), 2)
            for x, y, _ in curve["points"]:
                self.assertGreaterEqual(x, min_x - 1.0e-9)
                self.assertLessEqual(x, max_x + 1.0e-9)
                self.assertGreaterEqual(y, min_y - 1.0e-9)
                self.assertLessEqual(y, max_y + 1.0e-9)

    def test_polyline_clipping_interpolates_boundary_points(self):
        fragments = clip_polyline_to_bounds(
            [(-2.0, 0.5, 0.0), (0.5, 0.5, 0.0), (2.0, 0.5, 0.0)],
            (0.0, 0.0, 1.0, 1.0),
        )
        self.assertEqual(1, len(fragments))
        self.assertEqual((0.0, 0.5, 0.0), fragments[0][0])
        self.assertEqual((1.0, 0.5, 0.0), fragments[0][-1])
        self.assertEqual(
            [],
            clip_polyline_to_bounds(
                [(-2.0, -2.0, 0.0), (-1.0, -1.0, 0.0)],
                (0.0, 0.0, 1.0, 1.0),
            ),
        )

    def test_usda_contains_layout_markers_and_generation_counts(self):
        usda, summary = build_usda(self.layout)
        self.assertTrue(usda.startswith("#usda 1.0\n"))
        self.assertIn('def BasisCurves "GuidePaths"', usda)
        self.assertIn('def Points "ControlPoints"', usda)
        self.assertIn('def Xform "Stations"', usda)
        self.assertIn('custom string automod:stationId = "cp_Park_1"', usda)
        self.assertIn("int selectedSourcePathCount = 322", usda)
        self.assertIn("int controlPointCount = 468", usda)
        self.assertEqual(322, summary["clipped_curve_count"])
        self.assertEqual(468, summary["control_point_count"])
        self.assertEqual(173, summary["station_count"])
        self.assertNotIn("nan", usda.lower())
        self.assertNotIn("infinity", usda.lower())

    def test_committed_usda_is_reproducible(self):
        expected, _ = build_usda(self.layout)
        self.assertEqual(expected, COMMITTED_USDA.read_text(encoding="utf-8"))

        with tempfile.TemporaryDirectory() as temporary_directory:
            output = Path(temporary_directory) / "region.usda"
            summary = convert_file(LAYOUT_JSON, output)
            self.assertEqual(expected, output.read_text(encoding="utf-8"))
            self.assertEqual(322, summary["selected_source_path_count"])


if __name__ == "__main__":
    unittest.main()
