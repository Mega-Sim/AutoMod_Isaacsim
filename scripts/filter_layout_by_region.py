#!/usr/bin/env python3
"""Filter layout JSON to keep only elements in a geographic region."""

import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from json_to_usd import path_point_and_yaw


def filter_layout_by_region(data, x_min, x_max, y_min, y_max):
    """Filter layout JSON to region, keeping related geometry coherent."""
    paths_by_id = {p["id"]: p for p in data.get("paths", [])}

    # Step 1: Filter control points by region (meters)
    filtered_cps = []
    for cp in data.get("control_points", []):
        p = paths_by_id.get(cp.get("path_id"))
        if not p:
            continue
        x, y, _ = path_point_and_yaw(p, float(cp.get("distance_mm", 0)))
        x_m, y_m = x / 1000, y / 1000
        if x_min <= x_m <= x_max and y_min <= y_m <= y_max:
            filtered_cps.append(cp)

    # Step 2: Collect all paths that CPs reference (even if CP position is outside)
    cp_paths = {cp.get("path_id") for cp in filtered_cps}

    # Step 3: Keep ALL nodes that touch any CP path
    nodes_with_cp_paths = set()
    for node in data.get("nodes", []):
        for src_path in node.get("source_paths", []):
            if src_path in cp_paths:
                nodes_with_cp_paths.add(node["id"])
                break

    # Step 4: Keep ALL edges between those nodes
    filtered_edges = [
        e for e in data.get("edges", [])
        if e.get("from_node_id") in nodes_with_cp_paths
        and e.get("to_node_id") in nodes_with_cp_paths
    ]

    # Step 5: Paths = CP paths + edge paths
    path_ids_used = cp_paths | {e.get("source_path_id") for e in filtered_edges}
    filtered_paths = [p for p in data.get("paths", []) if p["id"] in path_ids_used]

    # Step 6: Nodes = those with CP paths
    filtered_nodes = [n for n in data.get("nodes", []) if n["id"] in nodes_with_cp_paths]

    result = {
        "metadata": data.get("metadata", {}),
        "system_parameters": data.get("system_parameters", {}),
        "paths": filtered_paths,
        "nodes": filtered_nodes,
        "edges": filtered_edges,
        "control_points": filtered_cps,
        "stations": data.get("stations", []),
        "name_lists": data.get("name_lists", []),
        "vehicles": data.get("vehicles", []),
        "validation": {
            "errors": [],
            "warnings": [],
            "counts": {
                "gpaths": len(filtered_paths),
                "cpoints": len(filtered_cps),
                "nodes": len(filtered_nodes),
                "edges": len(filtered_edges),
            }
        }
    }
    return result


if __name__ == "__main__":
    with open("generated/basic_model_layout.json") as f:
        data = json.load(f)

    # 빨간색 영역 (미터)
    x_min, x_max = -120, -50
    y_min, y_max = -80, 20

    filtered = filter_layout_by_region(data, x_min, x_max, y_min, y_max)

    output = "generated/layout_red_region.json"
    with open(output, "w") as f:
        json.dump(filtered, f, indent=2)

    print(f"Wrote {output}")
    print(f"  Original: paths={len(data['paths'])}, nodes={len(data['nodes'])}, "
          f"edges={len(data['edges'])}, cpoints={len(data['control_points'])}")
    print(f"  Filtered: paths={filtered['validation']['counts']['gpaths']}, "
          f"nodes={filtered['validation']['counts']['nodes']}, "
          f"edges={filtered['validation']['counts']['edges']}, "
          f"cpoints={filtered['validation']['counts']['cpoints']}")
