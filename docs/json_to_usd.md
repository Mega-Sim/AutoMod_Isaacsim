# Configured AutoMod JSON to Isaac Sim USD

`scripts/json_to_usd.py` is the configured JSON-to-USD generation entry point.
It builds on the reviewed control-point-region converter and generates a stage
that can be opened directly in Isaac Sim with station asset references intact.

## Generate

Run from the repository root:

```bash
python3 scripts/json_to_usd.py
```

The defaults are equivalent to:

```bash
python3 scripts/json_to_usd.py \
  --input generated/basic_model_layout.json \
  --config config/layout_assets.json \
  --output generated/basic_model_layout.usda
```

The generator has no external Python dependency. It writes standard ASCII USD
and fails before writing if the configuration is invalid or a mapped local USD
asset is missing.

## Committed configuration

`config/layout_assets.json` controls four independent concerns:

- `selection`: retains the reviewed control-point bounds plus a 5 m margin.
- `stage`: declares meters, Z-up, and the configured rail elevation.
- `guide_paths` and `control_points`: set display widths and colors.
- `station_types`: maps each station classification to a USD asset, forward
  axis, yaw correction, and scale.

`station_overrides` can replace those values for one named AutoMod station
without changing the type-wide mapping.

The current rail height is deliberately:

```json
"rail_height_m": 0.0,
"rail_height_verified": false
```

The AutoMod `upz` value is an up vector, not a physical rail height. Replace
`rail_height_m` only after the actual elevation is verified from a CAD model or
facility specification.

## Station asset mapping

The current branch includes local, replaceable placeholder assets so that USD
composition can be fully validated without inventing actual equipment shapes:

| Station type | Count | Mapped asset |
|---|---:|---|
| `equipment` | 48 | `assets/stations/equipment_placeholder.usda` |
| `utb` | 84 | `assets/stations/utb_placeholder.usda` |
| `park` | 31 | `assets/stations/park_placeholder.usda` |
| `out_station` | 8 | `assets/stations/out_station_placeholder.usda` |
| `vehicle_home` | 2 | `assets/stations/vehicle_home_placeholder.usda` |

All 173 station prims receive:

- their meter-based AutoMod position
- Z rotation calculated from `tangent_yaw_rad`
- configured forward-axis and yaw-offset correction
- a local USD reference under the station's `Model` prim
- AutoMod station, type, path, and graph-node custom properties

When a verified model is available, replace only `asset_path`, `forward_axis`,
`yaw_offset_degrees`, and `scale` in the JSON configuration. The generator and
station placement logic do not need to change.

## Generated stage

`generated/basic_model_layout.usda` contains:

```text
/World
└── /Layout
    ├── /GuidePaths       322 clipped BasisCurves
    ├── /ControlPoints    468 Points
    └── /Stations         173 oriented Xforms with USD references
```

The guide paths contain 1,453 sampled vertices. The other three spatially
separated, control-point-free drawings remain excluded as previously reviewed.

## Open in Isaac Sim

1. Start Isaac Sim.
2. Select **File > Open**.
3. Open `generated/basic_model_layout.usda`.
4. Expand `/World/Layout/Stations` to inspect positions, rotations, and model
   references.

Keep the repository directory structure intact. The generated stage uses
relative references such as `../assets/stations/utb_placeholder.usda`.

## Verification

Run the complete repository test suite:

```bash
python3 -m unittest discover -s tests -v
```

The JSON-to-USD tests verify:

- exact guide-path, vertex, control-point, and station counts
- complete mapping and placement of all 173 stations
- station-type distribution and asset reference counts
- existence of every local mapped asset
- rejection of missing asset paths and invalid configuration
- byte-for-byte reproducibility of `basic_model_layout.usda`

The generated USD is additionally opened with OpenUSD during release
verification to ensure all five asset references compose without errors.

## Next development boundary

This branch stops before physical and behavioral simulation. The next work
requires verified input data for:

- actual equipment, UTB, stocker, rail, and OHT models
- physical overhead-rail elevation and model forward axes
- rail mesh and collider generation
- path-transition repair, OHT routing, animation, and collision avoidance
