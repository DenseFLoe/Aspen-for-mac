# s88 回执补：qa gate 3517b5ed 复跑（NATIVE-337）

版本串：`qa gate 3517b5ed (MANIFEST files sha256 66be66b5812579ba30d4eb391472bff2c5d8524a4d0592670c7251a671f5ac70)`
独立复算：拉分支 `3517b5ed` 全树（27 blob）→ 逐 blob sha256 → path 排序 → `{path,sha256,bytes}` 规范 JSON → sha256 = `66be66b5812579ba…`，与 t16 给的一致。

## units 三档计数
~~~
units: pass=10 fail=0 not-applicable=3 error=0
exit: 2        （L1 = 上游 checker 原样透传）
~~~

| 单元 | inputs | status |
| --- | ---: | --- |
| omitted-sites | 363 | pass |
| stale-metrics | 10 | pass |
| row-linkage | 11 | pass |
| fingerprint-pathset | **114**（with_prefix 59 + top_level 55） | pass |
| unresolved-no-recovery | 112 | pass |
| symbol-substring | 684 | pass |
| wrong-symbol | 684 | pass |
| byte-mismatch | 5055 | pass |
| det_access_prose | 24 | pass |
| truncated-hash | 15 | pass |
| access-flags | 0 | not-applicable（`no CLI metadata (native-only image)`） |
| clause-semantics | 0 | not-applicable（无 EH 子句，8% 覆盖） |
| eh-boundary | 0 | not-applicable（`boundary_tables 0`，8% 覆盖） |

## R7（声明集收缩 advisory）
`shrank_paths: 0`，输出中**没有** `[advisory] declared set shrank` 行 → 本轮声明集相对上一轮**没有减少**；`previous_tables: 2`（s86/s87 两份历史表参与对比），`dropped=[]`。这条现在是检测器算的，不再靠人肉核对。

## inputs 拆分（消除 109 vs 58 的误读）
`fingerprint-pathset` 的 `inputs` 现在拆成 `with_prefix=59` + `top_level=55` = **114**（本轮 s87-fingerprints.json 全部条目）；上一轮 58 是「s87-qa.md 尚未生成时的 with_prefix 数」，与 109（旧口径把顶层键一并计数）不是一个量。

## readback 收窄后的覆盖来源（按你的要求注明）
| 产物 | 覆盖来源 |
| --- | --- |
| `calls.csv` | `readback:` 行，值 `d6f82133e5187d15` |
| `coverage.csv` | `readback:` 行，值 `3afe1c2a87c9e70c` |
| `metrics.json` | `readback:` 行，值 `1c1c888130a1abf8` |
| `run.json` | **L1 provenance**（不是 readback） |
| `native-functions.csv` | **L1 的 `checked 307 tool-native entries`**（不是 readback） |

原始输出：`handoff/inbox/NATIVE-337/work/s88-gate.txt`。
