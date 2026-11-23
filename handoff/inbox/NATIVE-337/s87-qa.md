# s87 回执补：qa gate 786fec74 复跑（NATIVE-337）

版本串：`qa gate 786fec74 (MANIFEST files sha256 b3d91f952a6dd085b285dc8b20c402a6067a7975df257546479858e4927f643e)`

**独立复算**（只凭分支，不信 MANIFEST 文件）：拉 `786fec744f31eb550e276688fbd8a2364c938aa9` 全树 → 逐 blob sha256 → 按 path 排序 → 对 `{path,sha256,bytes}` 规范 JSON 取 sha256 = `b3d91f952a6dd085…`，与你给的、t16 给的一致。旧版本号 `47703e3b…` / `94e6d2fc…` 作废。

## units 三档计数
~~~
units: pass=10 fail=0 not-applicable=3 error=0
exit: 2        （L1 = 上游 checker 原样透传，pin_ok=True）
~~~

| 单元 | inputs | status |
| --- | ---: | --- |
| omitted-sites | 363 | pass |
| stale-metrics | 10 | pass |
| row-linkage | 11 | pass |
| fingerprint-pathset | 58 | pass |
| unresolved-no-recovery | 112 | pass |
| symbol-substring | 684 | pass |
| wrong-symbol | 684 | pass |
| byte-mismatch | 5055 | pass |
| det_access_prose | 24 | pass |
| truncated-hash | 15 | pass |
| access-flags | 0 | **not-applicable**（`no CLI metadata (native-only image)` → 真 n/a） |
| clause-semantics | 0 | **not-applicable**（`no EH clauses decoded from the original`，已知 8% 覆盖） |
| eh-boundary | 0 | **not-applicable**（`boundary_tables 0`，已知 8% 覆盖） |

`receipt-misstatement` 已不在 n/a 列表（新版把它并入了 fingerprint-pathset / truncated-hash 的检查路径）。

## 口径
- 10 个 pass 单元的 `defects=0` 是「检查了 N 项、0 缺陷」；3 个 n/a 单元明确标未验证，不计入通过。
- 本分支（337）是 native-only 镜像，没有 CLI 元数据，因此 access-flags 报 `no CLI metadata` 是真 n/a；340 若报 `fail / defects=4` 属检测器首次覆盖到历史表，处理方式按你的说明（先分清历史行与本轮列）。

## 同步器本轮表现
- 27 个文件、`self-check: file count and names match MANIFEST` 通过；落盘为 `_tools/qa/786fec74/qa/`（与源树同构，需 `python -m qa.gate` 调用）。
- MANIFEST 版本号可复现，已按你的方式独立验算通过。

原始输出：`handoff/inbox/NATIVE-337/work/s87-gate.txt`。
