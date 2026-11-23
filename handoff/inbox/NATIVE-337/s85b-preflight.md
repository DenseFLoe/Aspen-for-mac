# s85b 回执补：preflight L2 结果（本轮按协调决定用本地版）

按 lead 2026-11-23 决定：规范版由 t16 维护在独立分支 `tietoumiao/preflight`，**不进** 337 交付分支；本轮先用本地版跑，回执注明版本。

- 本轮所用 preflight：**本地合并版，10,866 B，sha256 `fa486947bcdd5dd27322bfad70338ac88473bc56dd0afed8d655d742c50608d2`，14 个 L2 检测单元**（非 t16 最终规范版，`--head` 参数尚未提供）。
- 调用：`python -B tool/preflight.py --task NATIVE-337 --item-dir handoff/inbox/NATIVE-337 --original _t13/orig/FindComponent.dll`
- 结果：**L2 defects = 0（14/14 单元）**；L1（上游 check-native-coverage.py，pin 校验通过）原样透传 `exit 2`，总退出码 2。

| L2 单元 | l1_covers | defects | advisory | stats |
| --- | --- | ---: | ---: | --- |
| omitted-sites | no | 0 | 0 | — |
| stale-metrics | no | 0 | 0 | numeric_keys 10 |
| row-linkage | partial | 0 | 0 | appendix_files 11 |
| fingerprint-pathset | no | 0 | 0 | receipts 1 |
| unresolved-no-recovery | no | 0 | 0 | unresolved_rows 112 / distinct_notes 101 |
| symbol-substring | partial | 0 | 0 | rows 684 |
| wrong-symbol | no | 0 | 0 | — |
| byte-mismatch | partial | 0 | 0 | instructions_checked 5055 |
| access-flags | no | 0 | 0 | — |
| receipt-misstatement | no | 0 | 0 | — |
| clause-semantics | no | 0 | 0 | — |
| eh-boundary | no | 0 | 0 | boundary_tables 0 |
| det_access_prose | no | 0 | 0 | documents_checked 23 |
| truncated-hash | no | 0 | 0 | files_scanned 14 |

原始 stdout 已落盘：`handoff/inbox/NATIVE-337/work/s85b-preflight.txt`（25 行：L1 一行 + 14 个 L2 单元 + exit）。

L1 原文：`checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps`（exit 2，112 条未决已申报）。

## latent 类（我们检出、上游当轮没提）
本轮 L2 全部 0 defect，**没有 latent 项**要单独报。

## 交付分支清理
`tool/preflight.py`（分支上 7,797 B 残版）与 `tool/preflight_backtest.py` 已从 337 交付分支移除：它们是我们自己的 QA 工装，规范版在 `tietoumiao/preflight`（t16 维护），用时由 `tool/sync_preflight.py` 拉到 `_tools/preflight/<head8>/`。回执此后写 `preflight <head8> (MANIFEST sha256 …)`。
