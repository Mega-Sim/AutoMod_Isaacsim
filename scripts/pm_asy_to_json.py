#!/usr/bin/env python3
"""
AutoMod pm.asy to Isaac Sim JSON converter.

Parses AutoMod path/control point definitions and converts to Isaac Sim layout JSON.
"""

import json
import re
import math
import argparse
import sys
from pathlib import Path
from dataclasses import dataclass, field, asdict
from typing import Dict, List, Optional, Tuple, Set, Any
from collections import defaultdict
from enum import Enum


class PathGeometryType(Enum):
    """Type of path segment geometry."""
    LINE = "line"
    ARC = "arc"


@dataclass
class Vector2D:
    """2D vector."""
    x: float
    y: float

    def distance_to(self, other: "Vector2D") -> float:
        """Calculate Euclidean distance."""
        dx = self.x - other.x
        dy = self.y - other.y
        return math.sqrt(dx*dx + dy*dy)

    def rotate(self, angle_rad: float, origin: "Vector2D" = None) -> "Vector2D":
        """Rotate around origin by angle in radians."""
        if origin is None:
            origin = Vector2D(0, 0)

        cos_a = math.cos(angle_rad)
        sin_a = math.sin(angle_rad)

        dx = self.x - origin.x
        dy = self.y - origin.y

        new_x = origin.x + dx * cos_a - dy * sin_a
        new_y = origin.y + dx * sin_a + dy * cos_a

        return Vector2D(new_x, new_y)

    def to_dict_mm(self) -> Dict[str, float]:
        """Convert to dict with mm values."""
        return {"x_mm": self.x, "y_mm": self.y}

    def to_dict_m(self) -> Dict[str, float]:
        """Convert to dict with meter values."""
        return {"x_m": self.x / 1000.0, "y_m": self.y / 1000.0}


@dataclass
class LinePath:
    """Line segment path."""
    begin: Vector2D
    end: Vector2D
    geometry_type: PathGeometryType = field(default=PathGeometryType.LINE, init=False)

    def length_mm(self) -> float:
        """Calculate length in mm."""
        return self.begin.distance_to(self.end)

    def length_m(self) -> float:
        """Calculate length in meters."""
        return self.length_mm() / 1000.0

    def point_at_distance(self, distance_mm: float) -> Vector2D:
        """Get point at distance from begin."""
        length = self.length_mm()
        if length == 0:
            return self.begin
        t = distance_mm / length
        t = max(0, min(1, t))  # Clamp to [0, 1]
        return Vector2D(
            self.begin.x + t * (self.end.x - self.begin.x),
            self.begin.y + t * (self.end.y - self.begin.y)
        )

    def tangent_angle_at_distance(self, distance_mm: float) -> float:
        """Get tangent angle (yaw) at distance from begin."""
        return math.atan2(self.end.y - self.begin.y, self.end.x - self.begin.x)

    def polyline_points(self, chord_error_mm: float) -> List[Tuple[float, float]]:
        """Return polyline points (just start and end for line)."""
        return [(self.begin.x / 1000.0, self.begin.y / 1000.0),
                (self.end.x / 1000.0, self.end.y / 1000.0)]


@dataclass
class ArcPath:
    """Arc segment path."""
    center: Vector2D
    begin: Vector2D
    sweep_angle_deg: float  # 0.1 degree units in raw file, converted to degrees here
    geometry_type: PathGeometryType = field(default=PathGeometryType.ARC, init=False)

    def __post_init__(self):
        """Validate and compute derived values."""
        self._radius = None
        self._end = None
        self._sweep_rad = None
        self._arc_length = None

    @property
    def radius_mm(self) -> float:
        """Calculate radius."""
        if self._radius is None:
            self._radius = self.center.distance_to(self.begin)
        return self._radius

    @property
    def sweep_rad(self) -> float:
        """Convert sweep angle to radians."""
        if self._sweep_rad is None:
            self._sweep_rad = math.radians(self.sweep_angle_deg)
        return self._sweep_rad

    @property
    def end(self) -> Vector2D:
        """Calculate end point."""
        if self._end is None:
            # Rotate begin point around center by sweep angle
            self._end = self.begin.rotate(self.sweep_rad, self.center)
        return self._end

    def length_mm(self) -> float:
        """Calculate arc length in mm."""
        if self._arc_length is None:
            self._arc_length = self.radius_mm * abs(self.sweep_rad)
        return self._arc_length

    def length_m(self) -> float:
        """Calculate arc length in meters."""
        return self.length_mm() / 1000.0

    def point_at_distance(self, distance_mm: float) -> Vector2D:
        """Get point at distance from begin."""
        length = self.length_mm()
        if length == 0:
            return self.begin

        # Calculate angle to rotate
        fraction = distance_mm / length
        fraction = max(0, min(1, fraction))
        angle_to_rotate = self.sweep_rad * fraction

        # Rotate begin point around center
        return self.begin.rotate(angle_to_rotate, self.center)

    def tangent_angle_at_distance(self, distance_mm: float) -> float:
        """Get tangent angle (yaw) at distance from begin."""
        # Tangent is perpendicular to radius vector
        point = self.point_at_distance(distance_mm)
        radius_angle = math.atan2(point.y - self.center.y,
                                   point.x - self.center.x)

        # Tangent is 90 degrees ahead of radius (for CCW rotation)
        if self.sweep_rad >= 0:
            return radius_angle + math.pi / 2
        else:
            return radius_angle - math.pi / 2

    def polyline_points(self, chord_error_mm: float) -> List[Tuple[float, float]]:
        """Generate polyline points for arc using chord error."""
        # Use chord error to determine number of segments
        radius = self.radius_mm
        if chord_error_mm <= 0 or radius == 0:
            return [(self.begin.x / 1000.0, self.begin.y / 1000.0),
                    (self.end.x / 1000.0, self.end.y / 1000.0)]

        # Calculate max angle per segment based on chord error
        # chord = 2 * r * sin(θ/2)
        # error = r - r*cos(θ/2) = r*(1 - cos(θ/2))
        # For small θ: error ≈ r*θ²/8, so θ ≈ sqrt(8*error/r)
        half_angle = math.asin(min(1.0, chord_error_mm / (2 * radius))) if chord_error_mm < 2 * radius else math.pi / 2
        max_angle_per_segment = 2 * half_angle

        # Number of segments needed
        num_segments = max(2, int(math.ceil(abs(self.sweep_rad) / max_angle_per_segment)))

        points = []
        for i in range(num_segments + 1):
            t = i / num_segments
            angle = self.sweep_rad * t
            point = self.begin.rotate(angle, self.center)
            points.append((point.x / 1000.0, point.y / 1000.0))

        return points


class AutoModParser:
    """Main parser for AutoMod files."""

    def __init__(self, filepath: str, snap_tolerance_mm: float = 1.0,
                 arc_chord_error_mm: float = 5.0):
        self.filepath = filepath
        self.snap_tolerance_mm = snap_tolerance_mm
        self.arc_chord_error_mm = arc_chord_error_mm

        # Parsed structures
        self.raw_records: Dict[str, List[Dict[str, Any]]] = defaultdict(list)
        self.paths: Dict[str, Dict[str, Any]] = {}
        self.control_points: List[Dict[str, Any]] = []
        self.control_point_types: Dict[str, Dict[str, Any]] = {}
        self.name_lists: Dict[str, Dict[str, Any]] = {}
        self.nodes: Dict[str, Dict[str, Any]] = {}
        self.edges: List[Dict[str, Any]] = []
        self.stations: List[Dict[str, Any]] = []
        self.routing_points: List[Dict[str, Any]] = []
        self.vehicles: Dict[str, Dict[str, Any]] = {}

        self.validation = {
            'errors': [],
            'warnings': [],
            'counts': {}
        }

        # Parse file
        self._parse_file()
        self._process_records()

    def _parse_file(self):
        """Parse the pm.asy file."""
        with open(self.filepath, 'r', encoding='utf-8', errors='ignore') as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith('#'):
                    continue

                # Parse record
                record_type, attrs = self._parse_line(line)
                if record_type:
                    self.raw_records[record_type].append(attrs)

    def _parse_line(self, line: str) -> Tuple[Optional[str], Dict[str, Any]]:
        """Parse a single line into record type and attributes."""
        # Normalize whitespace
        line = re.sub(r'[\t\s]+', ' ', line).strip()
        if not line:
            return None, {}

        tokens = line.split()
        record_type = tokens[0]
        attrs = {}

        i = 1
        while i < len(tokens):
            key = tokens[i]

            # Skip 'piece' if it's a separator
            if key == 'piece':
                i += 1
                continue

            # Collect value(s) for this key
            values = []
            i += 1

            # Collect all values until next key
            while i < len(tokens):
                token = tokens[i]

                # Check if this looks like a key
                if self._is_key(token):
                    break

                values.append(token)
                i += 1

            # Store value(s)
            if len(values) == 1:
                try:
                    # Try to parse as float
                    attrs[key] = float(values[0])
                except ValueError:
                    attrs[key] = values[0]
            elif len(values) > 1:
                # Try to parse all as floats
                try:
                    attrs[key] = [float(v) for v in values]
                except ValueError:
                    attrs[key] = values

        return record_type, attrs

    @staticmethod
    def _is_key(token: str) -> bool:
        """Check if token looks like a key."""
        keywords = {
            'type', 'name', 'piece', 'item', 'at', 'vel', 'nav', 'color',
            'begx', 'begy', 'endx', 'endy', 'cenx', 'ceny', 'angle', 'upz',
            'cap', 'release', 'distance', 'align', 'limit', 'scale', 'nrot', 'nscale',
            'pickup', 'setdown', 'secname', 'one', 'attach', 'minang', 'maxang',
            'timeout', 'confname', 'numveh', 'start', 'accel', 'decel', 'crvvel',
            'sprvel', 'rvel', 'rcrvvel', 'rsprvel', 'crabvel', 'rotate', 'brakedist',
            'stopdist', 'trx', 'try', 'trz', 'scx', 'scy', 'scz'
        }
        return token.lower() in keywords

    def _process_records(self):
        """Process parsed records."""
        # Parse paths first
        self._process_paths()

        # Parse control point types
        self._process_control_point_types()

        # Parse control points
        self._process_control_points()

        # Parse name lists
        self._process_name_lists()

        # Parse vehicles
        self._process_vehicles()

        # Build graph
        self._build_graph()

        # Record counts
        self.validation['counts'] = {
            'gpaths': len(self.paths),
            'line_gpaths': sum(1 for p in self.paths.values() if p['geometry_type'] == 'line'),
            'arc_gpaths': sum(1 for p in self.paths.values() if p['geometry_type'] == 'arc'),
            'cpoints': len(self.control_points),
            'cpoint_types': len(self.control_point_types),
            'nodes': len(self.nodes),
            'edges': len(self.edges),
            'stations': len(self.stations),
            'vehicles': len(self.vehicles),
        }

    def _process_paths(self):
        """Process GPATH records."""
        for record in self.raw_records.get('GPATH', []):
            name = record.get('name')
            if not name:
                continue

            path_type = record.get('type', 'DefaultGuidePath')

            # Determine geometry type
            geometry = None
            geom_type = None

            # Try line
            if 'begx' in record and 'endx' in record:
                try:
                    begin = Vector2D(float(record['begx']), float(record['begy']))
                    end = Vector2D(float(record['endx']), float(record['endy']))
                    geometry = LinePath(begin, end)
                    geom_type = 'line'
                except (ValueError, TypeError, KeyError):
                    pass

            # Try arc
            if geometry is None and 'cenx' in record and 'begx' in record and 'angle' in record:
                try:
                    center = Vector2D(float(record['cenx']), float(record['ceny']))
                    begin = Vector2D(float(record['begx']), float(record['begy']))
                    # Angle is in 0.1 degree units
                    angle_deg = float(record['angle']) / 10.0
                    geometry = ArcPath(center, begin, angle_deg)
                    geom_type = 'arc'
                except (ValueError, TypeError, KeyError):
                    pass

            if geometry is None:
                self.validation['warnings'].append(
                    f"Failed to parse GPATH {name}: insufficient geometry attributes"
                )
                continue

            # Store path
            path_dict = {
                'name': name,
                'type': path_type,
                'geometry': geometry,
                'geometry_type': geom_type,
                'length_mm': geometry.length_mm(),
                'length_m': geometry.length_m(),
                'raw_attributes': record,
            }

            self.paths[name] = path_dict

    def _process_control_point_types(self):
        """Process CPOINTTYPE records."""
        for record in self.raw_records.get('CPOINTTYPE', []):
            name = record.get('name')
            if not name:
                continue

            self.control_point_types[name] = record

    def _process_control_points(self):
        """Process CPOINT records."""
        for record in self.raw_records.get('CPOINT', []):
            name = record.get('name')
            if not name:
                continue

            # Re-parse line to find path and distance
            with open(self.filepath, 'r', encoding='utf-8', errors='ignore') as f:
                for line in f:
                    if f'name {name}' in line and 'CPOINT' in line:
                        # Extract path and distance using regex
                        match = re.search(r'at\s+(\S+)\s+([\d.]+)', line)
                        if match:
                            path_name = match.group(1)
                            distance_mm = float(match.group(2))
                        else:
                            continue
                        break
                else:
                    continue

            # Validate path exists
            if path_name not in self.paths:
                self.validation['warnings'].append(
                    f"CPOINT {name} references non-existent path {path_name}"
                )
                continue

            path_info = self.paths[path_name]
            path_length = path_info['length_mm']

            # Check distance is within path
            if distance_mm > path_length + 0.001:
                self.validation['warnings'].append(
                    f"CPOINT {name} distance {distance_mm:.1f}mm exceeds path {path_name} "
                    f"length {path_length:.1f}mm"
                )

            cpoint_type = record.get('type', 'DefaultControlPoint')

            cp_dict = {
                'name': name,
                'type': cpoint_type,
                'path_id': path_name,
                'distance_mm': distance_mm,
                'raw_attributes': record,
            }

            self.control_points.append(cp_dict)

    def _process_name_lists(self):
        """Process NAMELST records."""
        for record in self.raw_records.get('NAMELST', []):
            name = record.get('name')
            if not name:
                continue

            items = record.get('item', [])
            if not isinstance(items, list):
                items = [items] if items else []

            self.name_lists[name] = {
                'name': name,
                'members': items,
                'raw_attributes': record,
            }

    def _process_vehicles(self):
        """Process AGVSVEH records."""
        for record in self.raw_records.get('AGVSVEH', []):
            vtype = record.get('type', 'Unknown')
            numveh = record.get('numveh', 0)

            try:
                numveh = int(numveh) if numveh else 0
            except (ValueError, TypeError):
                numveh = 0

            self.vehicles[vtype] = {
                'type': vtype,
                'numveh': numveh,
                'start': record.get('start'),
                'raw_attributes': record,
            }

    def _build_graph(self):
        """Build graph nodes and edges."""
        # Group control points by path
        cp_by_path = defaultdict(list)
        for cp in self.control_points:
            cp_by_path[cp['path_id']].append(cp)

        # Sort control points by distance
        for path_id in cp_by_path:
            cp_by_path[path_id].sort(key=lambda x: x['distance_mm'])

        # Create nodes and edges
        nodes_by_location = {}
        next_node_id = 0

        for path_name, path_info in self.paths.items():
            geometry = path_info['geometry']
            path_length = path_info['length_mm']

            # Get control points on this path
            cps = cp_by_path.get(path_name, [])

            # Determine all positions
            positions = []
            positions.append((0, 'path_start', None))

            for cp in cps:
                positions.append((cp['distance_mm'], 'cpoint', cp))

            positions.append((path_length, 'path_end', None))

            # Remove duplicates and sort
            positions.sort(key=lambda x: x[0])

            # Create nodes and track positions
            path_nodes = []

            for dist, pos_type, cp_obj in positions:
                point = geometry.point_at_distance(dist)
                # Snap to grid
                location_key = (round(point.x / self.snap_tolerance_mm),
                               round(point.y / self.snap_tolerance_mm))

                if location_key not in nodes_by_location:
                    node_id = f"node_{next_node_id:06d}"
                    next_node_id += 1

                    node = {
                        'id': node_id,
                        'position_mm': {'x': point.x, 'y': point.y},
                        'position_m': {'x': point.x / 1000.0, 'y': point.y / 1000.0},
                        'source_paths': set(),
                        'control_points': set(),
                    }

                    nodes_by_location[location_key] = (node_id, node)
                    self.nodes[node_id] = node

                node_id, node = nodes_by_location[location_key]

                if pos_type in ['path_start', 'path_end']:
                    node['source_paths'].add(path_name)
                elif pos_type == 'cpoint' and cp_obj:
                    node['control_points'].add(cp_obj['name'])

                path_nodes.append((dist, node_id, point))

            # Create edges
            edge_count = 0
            for i in range(len(path_nodes) - 1):
                dist_start, node_start_id, start_point = path_nodes[i]
                dist_end, node_end_id, end_point = path_nodes[i + 1]

                # Skip edges with same start and end node (zero length)
                if node_start_id == node_end_id:
                    continue

                edge_geom = geometry
                edge_length = geometry.point_at_distance(dist_end).distance_to(
                    geometry.point_at_distance(dist_start)
                )

                # Skip zero-length edges
                if edge_length <= 0.0001:
                    continue

                edge = {
                    'id': f"edge_{path_name}_{edge_count:04d}",
                    'from_node_id': node_start_id,
                    'to_node_id': node_end_id,
                    'source_path_id': path_name,
                    'source_distance_start_mm': dist_start,
                    'source_distance_end_mm': dist_end,
                    'length_m': edge_length / 1000.0,
                    'length_mm': edge_length,
                    'geometry_type': path_info['geometry_type'],
                    'direction': 'forward',
                    'one_way': True,
                    'polyline_m': edge_geom.polyline_points(self.arc_chord_error_mm),
                }

                edge_count += 1
                self.edges.append(edge)

        # Convert sets to lists in nodes
        for node in self.nodes.values():
            node['source_paths'] = list(node['source_paths'])
            node['control_points'] = list(node['control_points'])

    def to_json_dict(self) -> Dict[str, Any]:
        """Convert to JSON-serializable dictionary."""
        return {
            'metadata': {
                'source_file': Path(self.filepath).name,
                'source_units': 'Millimeters',
                'output_units': 'Meters',
                'up_axis': 'Z',
                'snap_tolerance_mm': self.snap_tolerance_mm,
                'arc_chord_error_mm': self.arc_chord_error_mm,
            },
            'system_parameters': self.raw_records.get('SYSDEF', [{}])[0] if self.raw_records.get('SYSDEF') else {},
            'paths': self._serialize_paths(),
            'nodes': list(self.nodes.values()),
            'edges': self.edges,
            'control_points': self.control_points,
            'stations': self.stations,
            'name_lists': list(self.name_lists.values()),
            'vehicles': list(self.vehicles.values()),
            'validation': self.validation,
        }

    def _serialize_paths(self) -> List[Dict[str, Any]]:
        """Serialize paths for JSON."""
        result = []
        for name, path_info in self.paths.items():
            geom = path_info['geometry']

            path_dict = {
                'id': name,
                'name': name,
                'type': path_info['type'],
                'geometry_type': path_info['geometry_type'],
                'length_mm': path_info['length_mm'],
                'length_m': path_info['length_m'],
            }

            if isinstance(geom, LinePath):
                path_dict['geometry'] = {
                    'type': 'line',
                    'begin': {'x': geom.begin.x, 'y': geom.begin.y},
                    'end': {'x': geom.end.x, 'y': geom.end.y},
                }
            else:  # ArcPath
                path_dict['geometry'] = {
                    'type': 'arc',
                    'center': {'x': geom.center.x, 'y': geom.center.y},
                    'begin': {'x': geom.begin.x, 'y': geom.begin.y},
                    'end': {'x': geom.end.x, 'y': geom.end.y},
                    'radius_mm': geom.radius_mm,
                    'sweep_angle_deg': geom.sweep_angle_deg,
                    'sweep_angle_rad': geom.sweep_rad,
                }

            result.append(path_dict)

        return result


def main():
    """Main entry point."""
    parser = argparse.ArgumentParser(
        description='Convert AutoMod pm.asy to Isaac Sim JSON'
    )
    parser.add_argument('--input', required=True, help='Input pm.asy file')
    parser.add_argument('--output', required=True, help='Output JSON file')
    parser.add_argument('--snap-tolerance-mm', type=float, default=1.0,
                       help='Node snap tolerance in mm')
    parser.add_argument('--arc-chord-error-mm', type=float, default=5.0,
                       help='Arc chord error for polyline in mm')

    args = parser.parse_args()

    try:
        converter = AutoModParser(args.input,
                                 snap_tolerance_mm=args.snap_tolerance_mm,
                                 arc_chord_error_mm=args.arc_chord_error_mm)

        json_data = converter.to_json_dict()

        output_path = Path(args.output)
        output_path.parent.mkdir(parents=True, exist_ok=True)

        with open(output_path, 'w', encoding='utf-8') as f:
            json.dump(json_data, f, indent=2, ensure_ascii=False)

        print(f"✓ Converted {args.input}")
        print(f"✓ Generated {args.output}")
        print(f"  - Paths: {converter.validation['counts']['gpaths']}")
        print(f"  - Line paths: {converter.validation['counts']['line_gpaths']}")
        print(f"  - Arc paths: {converter.validation['counts']['arc_gpaths']}")
        print(f"  - Control points: {converter.validation['counts']['cpoints']}")
        print(f"  - Nodes: {converter.validation['counts']['nodes']}")
        print(f"  - Edges: {converter.validation['counts']['edges']}")

        if converter.validation['warnings']:
            print(f"\nWarnings: {len(converter.validation['warnings'])}")
            for w in converter.validation['warnings'][:5]:
                print(f"  ⚠ {w}")
            if len(converter.validation['warnings']) > 5:
                print(f"  ... and {len(converter.validation['warnings']) - 5} more")

        return 0

    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        import traceback
        traceback.print_exc()
        return 1


if __name__ == '__main__':
    sys.exit(main())
