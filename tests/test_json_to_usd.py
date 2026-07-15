import json
import tempfile
import unittest
from collections import Counter
from copy import deepcopy
from pathlib import Path

from scripts.json_to_usd import (
    DEFAULT_CONFIG,
    DEFAULT_INPUT,
    DEFAULT_OUTPUT,
    REPO_ROOT,
    REQUIRED_STATION_TYPES,
    build_configured_usda,
    convert_file,
    load_asset_config,
    resolve_station_mapping,
)
from scripts.layout_json_to_usda import select_control_point_region


class JsonToUsdTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.layout = json.loads(DEFAULT_INPUT.read_text(encoding="utf-8"))
        cls.config = load_asset_config(DEFAULT_CONFIG)
        cls.region = select_control_point_region(
            cls.layout,
            cls.config["selection"]["margin_m"],
        )
        cls.usda, cls.summary = build_configured_usda(
            cls.layout,
            cls.config,
            output_path=DEFAULT_OUTPUT,
            config_path=DEFAULT_CONFIG,
        )

    def test_config_preserves_reviewed_region_and_unverified_height(self):
        self.assertEqual("control_point_bounds", self.config["selection"]["mode"])
        self.assertEqual(5.0, self.config["selection"]["margin_m"])
        self.assertEqual(0.0, self.config["stage"]["rail_height_m"])
        self.assertFalse(self.config["stage"]["rail_height_verified"])
        self.assertEqual(REQUIRED_STATION_TYPES, set(self.config["station_types"]))

    def test_every_station_type_maps_to_an_existing_usd_asset(self):
        for station_type, mapping in self.config["station_types"].items():
            asset = REPO_ROOT / mapping["asset_path"]
            self.assertTrue(asset.is_file(), f"missing {station_type} asset: {asset}")
            self.assertTrue(mapping["placeholder"])
            self.assertEqual("+X", mapping["forward_axis"])

    def test_all_173_stations_have_positions_directions_and_references(self):
        self.assertEqual(173, self.summary["station_count"])
        self.assertEqual(173, self.summary["asset_reference_count"])
        self.assertEqual(173, self.summary["placeholder_reference_count"])
        self.assertEqual(5, self.summary["unique_local_asset_count"])
        self.assertEqual(
            {
                "equipment": 48,
                "out_station": 8,
                "park": 31,
                "utb": 84,
                "vehicle_home": 2,
            },
            self.summary["station_type_counts"],
        )
        self.assertEqual(173, self.usda.count("prepend references = @"))
        self.assertEqual(173, self.usda.count("custom string automod:stationId"))
        self.assertEqual(173, self.usda.count("double3 xformOp:translate"))
        self.assertEqual(173, self.usda.count("double3 xformOp:rotateXYZ"))

        expected_references = Counter(
            resolve_station_mapping(self.config, station)["asset_path"]
            for station in self.region["stations"]
        )
        for asset_path, expected_count in expected_references.items():
            reference = "../" + asset_path
            self.assertEqual(
                expected_count,
                self.usda.count(f"prepend references = @{reference}@"),
            )

    def test_layout_geometry_counts_are_preserved(self):
        self.assertEqual(322, self.summary["selected_source_path_count"])
        self.assertEqual(322, self.summary["clipped_curve_count"])
        self.assertEqual(1_453, self.summary["curve_vertex_count"])
        self.assertEqual(468, self.summary["control_point_count"])
        self.assertEqual(295, self.summary["routing_control_point_count"])
        self.assertIn('def BasisCurves "GuidePaths"', self.usda)
        self.assertIn('def Points "ControlPoints"', self.usda)
        self.assertIn('def Xform "Stations"', self.usda)

    def test_committed_basic_model_usda_is_reproducible(self):
        self.assertEqual(self.usda, DEFAULT_OUTPUT.read_text(encoding="utf-8"))

    def test_missing_local_asset_is_rejected(self):
        config = deepcopy(self.config)
        config["station_types"]["park"]["asset_path"] = "assets/stations/missing.usda"
        with self.assertRaises(FileNotFoundError):
            build_configured_usda(
                self.layout,
                config,
                output_path=DEFAULT_OUTPUT,
                config_path=DEFAULT_CONFIG,
            )

    def test_convert_file_writes_a_complete_stage(self):
        with tempfile.TemporaryDirectory(dir=REPO_ROOT) as temporary_directory:
            output = Path(temporary_directory) / "basic_model_layout.usda"
            summary = convert_file(DEFAULT_INPUT, DEFAULT_CONFIG, output)
            generated = output.read_text(encoding="utf-8")
            self.assertTrue(generated.startswith("#usda 1.0\n"))
            self.assertEqual(173, generated.count("prepend references = @"))
            self.assertEqual(173, summary["station_count"])
            self.assertNotIn("nan", generated.lower())
            self.assertNotIn("infinity", generated.lower())


if __name__ == "__main__":
    unittest.main()
