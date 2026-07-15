# AutoMod pm.asy to Isaac Sim JSON

`scripts/pm_asy_to_json.py` converts an AutoMod AGVS plant-model layout into a
meter-based, Z-up JSON representation for Isaac Sim.

## Usage

```bash
python3 scripts/pm_asy_to_json.py \
  --input data/raw/basic_model/model.arc/pm.asy \
  --output generated/basic_model_layout.json
```

Optional geometry controls:

- `--snap-tolerance-mm`: endpoint merge tolerance, default `1.0` mm.
- `--arc-chord-error-mm`: maximum arc-to-polyline chord error, default `5.0` mm.

The `generated/*.json` files remain ignored by Git. Generate them locally from
the committed converter and AutoMod source model.

## Output sections

- `metadata`: AutoMod version, units, source checksum, and source-record counts.
- `coordinate_system`: AutoMod XY millimeters to Isaac Sim XY meters mapping.
- `path_types`: inherited direction, color, navigation, and velocity defaults.
- `source_paths`: exact straight/arc geometry plus sampled meter-based polylines.
- `nodes`: merged guide-path endpoints and control-point locations.
- `edges`: directed graph segments split at control points.
- `control_point_types`: AutoMod type definitions and inherited attributes.
- `control_points`: every source `CPOINT`, with computed position and tangent yaw.
- `routing_control_points`: Avoid/dummy/steer/high-in/high-out routing locations.
- `stations`: operational station candidates selected by explicit name rules.
- `name_lists`: merged and recursively resolved AutoMod `NAMELST` groups.
- `vehicle_segments`: display scale, pickup/setdown time, and attachment point.
- `vehicle_definitions`: fleet count, start group, speed, acceleration, and braking.
- `system_initial_state`: `AGVSDEF`, `NEXTPATH`, and `NEXTCP` information.
- `validation`: reference, geometry, and parsing diagnostics.

## Geometry rules

AutoMod arc `angle` values use tenths of a degree. The converter divides the
value by ten, rotates the begin point around `cenx/ceny`, and retains the exact
center, radius, sweep, calculated endpoint, and length.

`CPOINT ... at PATH DISTANCE` is interpreted as a millimeter distance from the
path start. A control point on an arc is positioned by its partial sweep. Its
`tangent_yaw_rad` can orient an Isaac Sim station or OHT along the travel
direction.

Guide paths use `GPATHTYPE ... one normal ...` in the SDI model, so graph edges
are emitted as one-way `beg -> end` edges. Planar crossings are not connected
unless they share a path endpoint; this avoids inventing junctions from visual
overlap alone.

## Station classification

AutoMod does not provide a separate `STATION` record in this file. All named
locations are `CPOINT` records, including routing-only locations. The converter
therefore preserves all control points and separately classifies station
candidates using the following name families:

- `cp_A*`, `cp_Can_*`, `cp_Cap_*`: equipment
- `cp_UTB_*`: UTB
- `cp_Park*`: park
- `cp_EVL_Home_*`: vehicle home
- `cp_Out_*`: output station

The `cp_Out_*` rule is intentionally case-sensitive because the SDI model also
contains lowercase `cp_out_*` high-out routing points.

## Verification

```bash
python3 -m unittest discover -s tests -v
```

The SDI basic model expectations are:

- 1,637 guide paths: 641 lines and 996 arcs
- 468 control points and 8 control-point types
- 173 station candidates and 295 routing control points
- zero missing path references and zero out-of-range control-point distances

The test suite also verifies the known `path100901` arc endpoint, the
`cp_a_324`/`path30` endpoint merge, directed-edge integrity, name-list
resolution, vehicle motion values, and finite JSON serialization.
