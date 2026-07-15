#!/usr/bin/env python3
"""
Tests for pm.asy to JSON converter.
"""

import unittest
import json
import math
import sys
from pathlib import Path

# Add scripts to path
sys.path.insert(0, str(Path(__file__).parent.parent / 'scripts'))

from pm_asy_to_json import (
    Vector2D, LinePath, ArcPath, AutoModParser
)


class TestVector2D(unittest.TestCase):
    """Test Vector2D operations."""

    def test_distance(self):
        """Test distance calculation."""
        v1 = Vector2D(0, 0)
        v2 = Vector2D(3, 4)
        self.assertAlmostEqual(v1.distance_to(v2), 5.0)

    def test_rotate(self):
        """Test rotation."""
        v = Vector2D(1, 0)
        origin = Vector2D(0, 0)

        # Rotate 90 degrees
        v_rot = v.rotate(math.pi / 2, origin)
        self.assertAlmostEqual(v_rot.x, 0, places=10)
        self.assertAlmostEqual(v_rot.y, 1, places=10)

        # Rotate -90 degrees
        v_rot = v.rotate(-math.pi / 2, origin)
        self.assertAlmostEqual(v_rot.x, 0, places=10)
        self.assertAlmostEqual(v_rot.y, -1, places=10)


class TestLinePath(unittest.TestCase):
    """Test line path operations."""

    def test_length(self):
        """Test line length."""
        line = LinePath(Vector2D(0, 0), Vector2D(3, 4))
        self.assertAlmostEqual(line.length_mm(), 5.0)
        self.assertAlmostEqual(line.length_m(), 0.005)

    def test_point_at_distance(self):
        """Test point at distance along line."""
        line = LinePath(Vector2D(0, 0), Vector2D(10, 0))

        # Midpoint
        p = line.point_at_distance(5)
        self.assertAlmostEqual(p.x, 5.0)
        self.assertAlmostEqual(p.y, 0.0)

    def test_tangent_angle(self):
        """Test tangent angle."""
        line = LinePath(Vector2D(0, 0), Vector2D(1, 0))
        angle = line.tangent_angle_at_distance(0.5)
        self.assertAlmostEqual(angle, 0.0)

        line = LinePath(Vector2D(0, 0), Vector2D(0, 1))
        angle = line.tangent_angle_at_distance(0.5)
        self.assertAlmostEqual(angle, math.pi / 2)


class TestArcPath(unittest.TestCase):
    """Test arc path operations."""

    def test_arc_end_point(self):
        """Test arc end point calculation."""
        # Simple 90-degree arc with radius 100
        center = Vector2D(0, 0)
        begin = Vector2D(100, 0)
        # Sweep 90 degrees
        arc = ArcPath(center, begin, 90.0)

        self.assertAlmostEqual(arc.radius_mm, 100.0, places=5)
        self.assertAlmostEqual(arc.sweep_rad, math.pi / 2, places=5)

        end = arc.end
        self.assertAlmostEqual(end.x, 0, places=5)
        self.assertAlmostEqual(end.y, 100, places=5)

    def test_arc_length(self):
        """Test arc length calculation."""
        # Quarter circle with radius 100
        arc = ArcPath(Vector2D(0, 0), Vector2D(100, 0), 90.0)
        expected_length = 100 * math.pi / 2
        self.assertAlmostEqual(arc.length_mm(), expected_length, places=2)

    def test_path100901(self):
        """Test specific arc path from pm.asy."""
        # path100901 data from pm.asy:
        # cenx 90989.408 ceny 111293.152
        # begx 90989.442899845 begy 110843.160558235
        # angle 449.998779296892 (in 0.1 degree units, so 45 degrees)

        center = Vector2D(90989.408, 111293.152)
        begin = Vector2D(90989.443, 110843.161)
        arc = ArcPath(center, begin, 45.0)

        # Check radius
        radius = arc.radius_mm
        expected_radius = center.distance_to(begin)
        self.assertAlmostEqual(radius, expected_radius, places=2)
        self.assertAlmostEqual(radius, 450.0, places=0)

        # Check end point
        end = arc.end
        # Expected end: approximately (91307.624, 110974.984)
        self.assertAlmostEqual(end.x, 91307.624, places=0)
        self.assertAlmostEqual(end.y, 110974.984, places=0)

    def test_arc_negative_sweep(self):
        """Test arc with negative (clockwise) sweep."""
        arc = ArcPath(Vector2D(0, 0), Vector2D(100, 0), -90.0)

        end = arc.end
        self.assertAlmostEqual(end.x, 0, places=5)
        self.assertAlmostEqual(end.y, -100, places=5)


class TestAutoModParser(unittest.TestCase):
    """Test AutoMod parser."""

    @classmethod
    def setUpClass(cls):
        """Set up parser once for all tests."""
        pm_asy_path = Path(__file__).parent.parent / 'data/raw/basic_model/model.arc/pm.asy'
        if not pm_asy_path.exists():
            raise FileNotFoundError(f"Test file not found: {pm_asy_path}")

        cls.parser = AutoModParser(str(pm_asy_path))
        cls.json_data = cls.parser.to_json_dict()

    def test_parser_counts(self):
        """Test parsed counts match expected values."""
        counts = self.parser.validation['counts']

        # Expected counts from requirements
        self.assertEqual(counts['gpaths'], 1637, "GPATH count mismatch")
        self.assertEqual(counts['line_gpaths'], 641, "Line GPATH count mismatch")
        self.assertEqual(counts['arc_gpaths'], 996, "Arc GPATH count mismatch")
        self.assertEqual(counts['cpoints'], 468, "CPOINT count mismatch")
        self.assertGreater(counts['cpoint_types'], 0, "CPOINTTYPE count")
        self.assertGreater(counts['nodes'], 0, "Node count")
        self.assertGreater(counts['edges'], 0, "Edge count")

    def test_json_structure(self):
        """Test JSON has required top-level keys."""
        required_keys = [
            'metadata', 'system_parameters', 'paths', 'nodes', 'edges',
            'control_points', 'validation'
        ]
        for key in required_keys:
            self.assertIn(key, self.json_data, f"Missing key: {key}")

    def test_path_geometry_types(self):
        """Test path geometry types are correct."""
        line_paths = [p for p in self.json_data['paths'] if p['geometry_type'] == 'line']
        arc_paths = [p for p in self.json_data['paths'] if p['geometry_type'] == 'arc']

        self.assertEqual(len(line_paths), 641, "Line path count")
        self.assertEqual(len(arc_paths), 996, "Arc path count")

    def test_path100901_geometry(self):
        """Test path100901 arc geometry."""
        paths = {p['id']: p for p in self.json_data['paths']}
        self.assertIn('path100901', paths)

        arc = paths['path100901']
        self.assertEqual(arc['geometry_type'], 'arc')

        geom = arc['geometry']
        # Verify center
        self.assertAlmostEqual(geom['center']['x'], 90989.408, places=1)
        self.assertAlmostEqual(geom['center']['y'], 111293.152, places=1)

        # Verify begin
        self.assertAlmostEqual(geom['begin']['x'], 90989.443, places=1)
        self.assertAlmostEqual(geom['begin']['y'], 110843.161, places=1)

        # Verify end
        self.assertAlmostEqual(geom['end']['x'], 91307.624, places=1)
        self.assertAlmostEqual(geom['end']['y'], 110974.984, places=1)

        # Verify sweep angle
        self.assertAlmostEqual(geom['sweep_angle_deg'], 45.0, places=1)

        # Verify radius
        self.assertAlmostEqual(geom['radius_mm'], 450.0, places=0)

    def test_nodes_and_edges(self):
        """Test nodes and edges are created."""
        nodes = self.json_data['nodes']
        edges = self.json_data['edges']

        self.assertGreater(len(nodes), 0, "No nodes created")
        self.assertGreater(len(edges), 0, "No edges created")

        # Verify node structure
        for node in nodes[:5]:
            self.assertIn('id', node)
            self.assertIn('position_mm', node)
            self.assertIn('position_m', node)

        # Verify edge structure
        for edge in edges[:5]:
            self.assertIn('id', edge)
            self.assertIn('from_node_id', edge)
            self.assertIn('to_node_id', edge)
            self.assertIn('source_path_id', edge)
            self.assertIn('geometry_type', edge)
            self.assertIn('length_m', edge)

    def test_edge_references_valid_nodes(self):
        """Test all edges reference valid nodes."""
        node_ids = {n['id'] for n in self.json_data['nodes']}
        edges = self.json_data['edges']

        for edge in edges:
            self.assertIn(edge['from_node_id'], node_ids,
                         f"Edge {edge['id']} references invalid from_node")
            self.assertIn(edge['to_node_id'], node_ids,
                         f"Edge {edge['id']} references invalid to_node")

    def test_edge_length_positive(self):
        """Test all edge lengths are positive."""
        edges = self.json_data['edges']

        for edge in edges:
            self.assertGreater(edge['length_m'], 0,
                              f"Edge {edge['id']} has non-positive length")

    def test_control_points_valid(self):
        """Test control points have valid references."""
        paths = {p['id'] for p in self.json_data['paths']}
        cpoints = self.json_data['control_points']

        for cp in cpoints:
            self.assertIn(cp['path_id'], paths,
                         f"Control point {cp['name']} references invalid path")
            # Distance should be non-negative
            self.assertGreaterEqual(cp['distance_mm'], 0)

    def test_no_validation_errors(self):
        """Test that validation has no critical errors."""
        validation = self.json_data['validation']
        self.assertIsInstance(validation['errors'], list)
        # We expect errors list to be empty for valid file
        self.assertEqual(len(validation['errors']), 0,
                        f"Unexpected validation errors: {validation['errors']}")

    def test_json_is_valid(self):
        """Test generated JSON is valid."""
        # Should be able to dump and load without errors
        json_str = json.dumps(self.json_data)
        loaded = json.loads(json_str)
        self.assertEqual(len(loaded['paths']), len(self.json_data['paths']))

    def test_coordinates_are_finite(self):
        """Test all coordinates are finite numbers."""
        nodes = self.json_data['nodes']

        for node in nodes:
            for key in ['x_mm', 'y_mm']:
                if key in node['position_mm']:
                    val = node['position_mm'][key]
                    self.assertTrue(math.isfinite(val),
                                  f"Node {node['id']} has non-finite {key}")

    def test_node_snap_works(self):
        """Test that node snapping works."""
        # All nodes should be unique (no duplicates within snap tolerance)
        nodes = self.json_data['nodes']
        node_positions = set()

        for node in nodes:
            x = node['position_mm']['x']
            y = node['position_mm']['y']
            # Using 1mm snap tolerance
            key = (round(x), round(y))
            self.assertNotIn(key, node_positions,
                           f"Duplicate node position: {key}")
            node_positions.add(key)

    def test_control_points_on_valid_paths(self):
        """Test all control points reference valid paths."""
        path_ids = {p['id'] for p in self.json_data['paths']}

        for cp in self.json_data['control_points']:
            self.assertIn(cp['path_id'], path_ids,
                         f"CPOINT {cp['name']} references non-existent path")


class TestJsonValidation(unittest.TestCase):
    """Test generated JSON file."""

    @classmethod
    def setUpClass(cls):
        """Load generated JSON."""
        json_path = Path(__file__).parent.parent / 'generated/basic_model_layout.json'
        if not json_path.exists():
            raise FileNotFoundError(f"Generated JSON not found: {json_path}")

        with open(json_path) as f:
            cls.json_data = json.load(f)

    def test_json_loads(self):
        """Test JSON file is valid."""
        self.assertIsInstance(self.json_data, dict)

    def test_required_keys(self):
        """Test required top-level keys exist."""
        required = ['metadata', 'paths', 'nodes', 'edges', 'validation']
        for key in required:
            self.assertIn(key, self.json_data)

    def test_paths_count(self):
        """Test path counts."""
        paths = self.json_data['paths']
        self.assertEqual(len(paths), 1637)

        line_count = sum(1 for p in paths if p['geometry_type'] == 'line')
        arc_count = sum(1 for p in paths if p['geometry_type'] == 'arc')

        self.assertEqual(line_count, 641)
        self.assertEqual(arc_count, 996)

    def test_nodes_edges_consistency(self):
        """Test nodes and edges are consistent."""
        nodes = {n['id'] for n in self.json_data['nodes']}
        edges = self.json_data['edges']

        for edge in edges:
            self.assertIn(edge['from_node_id'], nodes)
            self.assertIn(edge['to_node_id'], nodes)


if __name__ == '__main__':
    unittest.main()
