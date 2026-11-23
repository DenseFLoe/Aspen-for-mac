# s86 回执补：qa gate 13fe04a5 复跑（NATIVE-337）

版本串：`qa gate 13fe04a5 (MANIFEST sha256 47703e3beb39eb59a24780fb1a8e7aca28b79aa1c8bb115fd4a280bc865aa63f)`
（我本地 `qa/sync.py` 落盘得到的 MANIFEST sha256 是 `94e6d2fc69e07115…`，差异原因见文末「同步器两个问题」。）

## units 三档计数
~~~
units: pass=10 fail=0 not-applicable=4 error=0
exit: 2        （L1 = 上游 check-native-coverage.py，pin 校验通过，原样透传）
~~~

## 逐单元（inputs / status / defects）
| 单元 | inputs | status | defects |
| --- | ---: | --- | ---: |
| omitted-sites | 363 | pass | 0 |
| stale-metrics | 10 | pass | 0 |
| row-linkage | 11 | pass | 0 |
| fingerprint-pathset | 109 | pass | 0 |
| unresolved-no-recovery | 112 | pass | 0 |
| symbol-substring | 684 | pass | 0 |
| wrong-symbol | 684 | pass | 0 |
| byte-mismatch | 5055 | pass | 0 |
| det_access_prose | 24 | pass | 0 |
| truncated-hash | 15 | pass | 0 |
| **access-flags** | **0** | **not-applicable** | 0（t16 已知有效覆盖 0%，未验证访问级别） |
| **receipt-misstatement** | **0** | **not-applicable** | 0（已知 3%，将撤并） |
| **clause-semantics** | **0** | **not-applicable** | 0（已知 8%：`no EH clauses decoded from the original`） |
| **eh-boundary** | **0** | **not-applicable** | 0（已知 8%：`boundary_tables 0`） |

**口径**：上表 defects=0 只在 status=pass 的 10 个单元上成立；4 个 not-applicable 单元的 defects=0 **不算通过**，按你的清单它们是已知低覆盖（access-flags 0% / receipt-misstatement 3% / eh 8%）。

## 我这侧的 4 个 N/A 原因（供 t16 参考）
1. access-flags：`skipped: methoddef reader unavailable: RVA 0x0 outside` —— 它去读 methoddef 的 RVA，但我们的 TypeDef/MethodDef 需要 `tool/md_reader.py`；放进 PYTHONPATH 后报的是 RVA 0x0 越界，说明它读的是另一种卡片表（340 的 methods.il），对 337 不适用。
2. receipt-misstatement：`bound_rows: 0` —— 它靠回执里的绑定表行，而我们的回执是散文+表格，没被它识别。
3. clause-semantics / eh-boundary：`no EH clauses decoded from the original` / `boundary_tables 0` —— 需要从原件解 `.pdata`/EH 子句，当前版本没接。

## 同步器两个问题（实测）
1. **文件名被截断后重复落盘**：第一次 `qa/sync.py` 后 `_tools/qa/13fe04a5/` 里既有 `det_*.py` 被写成 `et_*.py`、`README.md`→`EADME.md`，同时又有 `qa/` 子目录的正确副本（疑似 `path[len('qa/'):]` 用成了 `[3:]` 又重复写一次）。后续一次 sync 变成 flatten 正确布局，所以现在能跑。
2. **MANIFEST sha256 不可复现**：manifest 里带 `generated_at`，直接对文件字节取 sha256 → 每次 sync 都不同（你给的 `47703e3b…`，我这里是 `94e6d2fc…`）。建议只对 `files`（path+sha256+bytes，排序）取哈希，版本串才可复现。

原始输出：`handoff/inbox/NATIVE-337/work/s86-gate.txt`。
