# AutoMod_Isaacsim
- Using AutoMod to do a discrete level simulation 
  (AutoMod를 활용해 이산 시뮬레이션을 진행)
- Implementing digital twin with Isaacsim based on AutoMod models
  (AutoMod 모델의 레이아웃, 로직을 활용해 디지털 트윈을 구현)

AutoMod의 레이아웃을 json파일로 변환하여 isaacsim 모델링 재료에 활용할 개발 방향의 메인 Branch입니다.
- 2개 버전으로 개발

## Control-point region USD preview

The repository includes a focused Isaac Sim preview of the control-point-dense
area in the SDI basic model. The other spatially separated layout drawings are
excluded. Regenerate the committed ASCII USD with:

```bash
python3 scripts/layout_json_to_usda.py \
  --input generated/basic_model_layout.json \
  --output generated/basic_model_control_point_region.usda
```

The result contains clipped guide-path curves, all control-point markers, and
individually addressable station markers. See
[`docs/control_point_region_usd.md`](docs/control_point_region_usd.md) for the
selection rule, Isaac Sim loading steps, and the boundary of this development
stage.

## Configured JSON to USD layout

`scripts/json_to_usd.py` is the configured generation entry point. It keeps the
reviewed control-point region, reads rail and station-asset settings from
`config/layout_assets.json`, places all 173 stations with their AutoMod tangent
directions, and generates `generated/basic_model_layout.usda`.

```bash
python3 scripts/json_to_usd.py
```

The committed station mappings reference five local placeholder USD assets, so
the stage opens without missing references before verified equipment models are
available. See [`docs/json_to_usd.md`](docs/json_to_usd.md) for configuration,
Isaac Sim loading, and verification details.
