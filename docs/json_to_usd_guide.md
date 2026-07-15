# 레이아웃 JSON → USD → Isaac Sim 적용 가이드

AutoMod `pm.asy`에서 변환한 레이아웃 JSON(`generated/basic_model_layout.json`)을
USD 스테이지로 변환하고, Isaac Sim에 로드하는 방법을 설명합니다.

## 전체 파이프라인

```
pm.asy ──(scripts/pm_asy_to_json.py)──▶ layout.json ──(scripts/json_to_usd.py)──▶ layout.usd ──▶ Isaac Sim
```

## 1. JSON → USD 변환

### 사전 준비

로컬 파이썬 환경에서 실행하려면 `usd-core` 패키지가 필요합니다
(Isaac Sim의 `python.sh`를 쓰면 pxr이 이미 포함되어 있어 설치가 필요 없습니다):

```bash
pip install usd-core
```

### 변환 명령

```bash
python3 scripts/json_to_usd.py \
  --input generated/basic_model_layout.json \
  --output generated/basic_model_layout.usd \
  --ground
```

### 옵션

| 옵션 | 기본값 | 설명 |
|---|---|---|
| `--input` | (필수) | 레이아웃 JSON 파일 |
| `--output` | (필수) | 출력 USD 파일 (`.usda`=텍스트, `.usd`/`.usdc`=바이너리) |
| `--path-width-m` | 0.05 | 가이드패스 커브 표시 폭 (m) |
| `--edge-width-m` | 0.03 | 그래프 엣지 커브 표시 폭 (m) |
| `--cp-radius-m` | 0.15 | 컨트롤포인트 마커(구) 반지름 (m) |
| `--no-edges` | - | 그래프 엣지 프림 생략 (파일 축소) |
| `--ground` | - | 레이아웃 크기에 맞는 바닥 평면 추가 |
| `--z-offset-m` | 0.0 | 레이아웃 Z 높이 (예: OHT 레일 높이) |

OHT처럼 천장 주행 시스템이면 `--z-offset-m 4.5` 등으로 레일 높이를 지정하면 됩니다.

## 2. 생성되는 USD 구조

스테이지는 **Z-up, 미터 단위**(`metersPerUnit = 1.0`)로 생성되며 Isaac Sim
기본 설정과 일치합니다.

```
/World                              (Xform, defaultPrim)
  /Layout
    /GuidePaths/<path_id>           BasisCurves — pm.asy GPATH 원본 지오메트리
                                    (직선=2점, 원호=코드오차 기반 폴리라인)
    /Edges/<edge_id>                BasisCurves — 컨트롤포인트로 분할된 방향성 엣지
                                    (purpose=guide → 기본 렌더링에서 숨김)
    /Nodes                          Points — 그래프 노드 위치 (automod:nodeIds 포함)
    /ControlPoints/<cp_name>        Xform + Sphere — 위치·주행방향(yaw)이 적용된 마커
  /Vehicles/<type>                  Xform — 차량 타입별 메타데이터 (numveh 등)
  /GroundPlane                      Mesh — --ground 옵션 시
```

### AutoMod 의미 정보 (custom attributes)

시뮬레이션 로직에서 활용할 수 있도록 `automod:` 네임스페이스의 커스텀
어트리뷰트로 원본 데이터를 보존합니다:

| 프림 | 어트리뷰트 |
|---|---|
| GuidePaths/* | `automod:pathType`, `automod:geometryType`, `automod:lengthM` |
| Edges/* | `automod:fromNode`, `automod:toNode`, `automod:sourcePath`, `automod:lengthM`, `automod:oneWay`, `automod:direction` |
| Nodes | `automod:nodeIds` (포인트 순서와 동일한 string[]) |
| ControlPoints/* | `automod:cpType`, `automod:sourcePath`, `automod:distanceMm`, `automod:tangentYawRad` |
| Vehicles/* | `automod:vehicleType`, `automod:numVehicles`, `automod:start` |

컨트롤포인트 위치는 JSON의 `path_id` + `distance_mm`을 경로 지오메트리
(직선/원호)에 대해 평가해 계산하며, 해당 지점의 접선 방향(yaw)이 Xform의
`rotateZ`로 적용됩니다. AGV/OHT가 정지했을 때의 차체 방향으로 그대로 사용할
수 있습니다.

## 3. Isaac Sim에서 열기

### 방법 A: GUI에서 직접 열기

1. Isaac Sim 실행 → `File > Open` → `generated/basic_model_layout.usd` 선택
2. 또는 기존 씬에 합성: Stage 패널에서 `/World` 우클릭 →
   `Add > Reference` → USD 파일 선택 (레이아웃 원본을 수정하지 않고 참조)

### 방법 B: 스탠드얼론 스크립트

Isaac Sim 설치 디렉토리에서:

```bash
./python.sh /path/to/AutoMod_Isaacsim/scripts/isaacsim_load_layout.py \
    --usd /path/to/AutoMod_Isaacsim/generated/basic_model_layout.usd
```

`--headless`(GUI 없이), `--frames N`(N프레임 후 종료) 옵션을 지원합니다.
스크립트는 레이아웃을 `/World/AutoModLayout` 아래에 **레퍼런스**로 추가하고
DomeLight와 PhysicsScene을 세팅합니다. 레퍼런스 방식이므로 차량·센서·물리
설정을 세션 스테이지에 자유롭게 추가해도 레이아웃 파일은 변경되지 않습니다.

### 방법 C: Script Editor (GUI 내부)

`Window > Script Editor`에서 `scripts/isaacsim_load_layout.py`의
`open_layout()` 함수 본문을 붙여넣어 실행하면 됩니다 (SimulationApp 불필요).

## 4. 디지털 트윈 로직에서 활용

`scripts/isaacsim_load_layout.py`에 예제 헬퍼가 포함되어 있습니다:

- `iter_control_points(stage)` — 모든 컨트롤포인트의 (이름, 월드좌표, 타입) 순회
  → 스테이션 배치, 디스패칭 지점 정의에 사용
- `build_edge_graph(stage)` — `{from_node: [(to_node, length_m, prim), ...]}`
  형태의 방향 그래프 복원 → AGV/OHT 경로 탐색(Dijkstra/A*)에 사용

```python
import omni.usd
from isaacsim_load_layout import iter_control_points, build_edge_graph

stage = omni.usd.get_context().get_stage()
for name, pos, cp_type in iter_control_points(stage):
    print(name, pos, cp_type)

graph = build_edge_graph(stage)  # 경로 탐색용 인접 리스트
```

## 5. 검증

```bash
# 단위 테스트 (지오메트리 평가 + USD 스테이지 구조)
python3 -m unittest discover -s tests -v

# 스테이지 내용 확인 (usd-core 포함 도구)
usdcat generated/basic_model_layout.usd | head -50
```

## basic_model 변환 결과

| 항목 | 개수 |
|---|---|
| GuidePaths (BasisCurves) | 1,637 |
| Edges (BasisCurves, guide) | 2,101 |
| Nodes (Points) | 2,524 |
| ControlPoints (Xform+Sphere) | 468 |
| Vehicles (메타데이터) | 3 |

레이아웃 범위: 약 289m × 280m (X: -166.7 ~ 122.2, Y: -96.2 ~ 183.7)

## 다음 단계 (로드맵)

1. **차량 스폰**: `vehicles[].numveh`에 따라 컨트롤포인트/파크 지점에 차량
   프림(참조 에셋) 인스턴싱
2. **주행 로직**: `build_edge_graph()` 기반 경로 탐색 + 엣지 폴리라인을 따라
   차량 이동 (one_way/direction 제약 반영)
3. **스테이션 분류**: `control_points[].type` 기반 분류 규칙을 정의해
   `stations` 채우기 (현재 0개)
4. **AutoMod 로직 연동**: model.dir의 이산 이벤트 로직과 Isaac Sim 물리
   시뮬레이션 동기화
