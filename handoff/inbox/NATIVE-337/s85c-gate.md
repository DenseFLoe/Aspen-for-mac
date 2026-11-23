# s85c 回执补：空跑缺陷（empty-set pass）与 inputs_checked/status

## 1. 确认：`fingerprint-pathset` 一直是空跑
上轮输出 `stats: {"fingerprint_files": 0, "receipts": 1, "declared_paths": 0}` —— 它**读到了 1 份回执，但一指纹文件都没扫到**。

根因（读检测器源码 `det_fingerprint_pathset`）：它只收集文件名匹配 `fingerprint|receipt|blobs` 且以 `.json` 结尾的文件；我们 337 交付里从来没有这种命名的 JSON（指纹分散在 `metrics.json`、`work/s*-tools.txt`、`s49-inputs.json`、`s61-layouts.json`），所以 `jfiles` 恒为空。

**结论：这个单元此前各轮报的 `defects=0` 都不算数**（不是没问题，是没查）。

## 2. 修复（先修自己这条链）
1. 新增 `qa/mk_fingerprints.py`：从交付目录**脚本生成** `s85-fingerprints.json`（`{相对路径: sha256}`，107 项），让这类检测器有真实输入。
2. 新增 `qa/gate.py`：对每个 detector 输出 **`inputs_checked`** 与 **`status`**（`pass` / `not-applicable` / `fail`），`inputs_checked=0` 一律 `not-applicable` 并打警告，**不得写成通过**。

## 3. 修复后实测（同一候选，`qa gate`）
| detector | inputs | status | defects |
| --- | ---: | --- | ---: |
| omitted_sites | 918（census 363 / matched 363 / iat_slots 192） | pass | 0 |
| stale_metrics | 10 | pass | 0 |
| row_linkage | 11 | pass | 0 |
| fingerprint_pathset | **109**（1 文件 + 107 声明路径 + 1 回执） | pass | 0 |
| unresolved_no_recovery | 112 | pass | 0 |
| symbol_substring | 684 | pass | 0 |
| wrong_symbol | 684 | pass | 0 |
| byte_mismatch | 5055 | pass | 0 |
| access_flags | 1 | pass | 0 |

`summary: detectors=9 fail=0 not-applicable=0 pass=9`，exit 0。
同一检测器在补 `s85-fingerprints.json` **之前**是 `inputs 0 / not-applicable`；补文件后进入 `pass`，说明空跑已消除。

## 4. 口径（写进流程）
- 回执里的 `defects=0` 必须写成「**检查了 N 项，0 缺陷**」或「**无可检输入（not-applicable）**」，后者不得计入通过。
- 版本说明：本次用本地框架版（`_t13/remote_preflight.py`，9 个 detector），**非 t16 的 14 单元规范版**；待 `tietoumiao/preflight` 可拉后按 `qa gate <head8>` 复跑并补一行复核结论。
- 原始输出：`handoff/inbox/NATIVE-337/work/s85c-gate.txt`。
