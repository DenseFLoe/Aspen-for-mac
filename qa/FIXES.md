# 验收门禁修复记录

本地检出根目录是 `D:\qa_fix_run`，没有额外的 `_qa_audit/` 层；源码在 `qa/`。保留了 `qa/selftest.py` 原样，在 `qa/test_audit_fixes.py` 新增九条离线回归。修前运行 `python -B -m unittest qa.test_audit_fixes -v`：`Ran 9 tests`、`FAILED (failures=13)`（含参数化子用例），退出码 `1`。下文的修前输出为关键摘录。

## 1. 跳过 L1 时阻断已确认缺陷

`qa/gate.py:aggregate`：L1 未运行时，任何 L2 `defect` 都阻断；实际运行了 L1 时保留原有权威和分歧警告。

- 命令：`python -B -m unittest qa.test_audit_fixes.AuditFixes.test_01_skipped_l1 -v`
- 修前：`(0, 1, 0) != (0, 1, 2)`（`yes`、`partial` 均为 pass=0/fail=1/exit=0；退出码 `1`）。
- 修后：`test_01_skipped_l1 ... ok`，`OK`，退出码 `0`。也验证 L1 实际运行并通过时仍保留警告。

## 2. 按仓库、完整 SHA、任务隔离并校验缓存

`qa/gate.py:main`、`qa/fetch.py:cache_key/list_item_files/_verify_item_files/fetch_head`：键为 `<cache>/<owner>/<repo>/<40位 SHA>/<task>`。每次从指定仓库和 SHA 读取 Git 树，用它校验实际路径集和 Git blob SHA-1；不再信任 `.fetched`。新下载校验通过才发布，损坏的缓存拒绝使用且不覆盖（可换一个 `--cache`）。

- 命令：`python -B -m unittest qa.test_audit_fixes.AuditFixes.test_02_cache_identity -v`
- 修前：同前缀 SHA `12345678…bbbb` 返回旧内容 `'0' != '1'`；另一仓库返回 `'0' != '2'`（退出码 `1`）。
- 修后：`test_02_cache_identity ... ok`，`OK`，退出码 `0`。验证未改缓存不重下 blob，新增、删除或修改缓存文件均返回 `2`。

## 3. 默认候选路径锚定 ROOT

`qa/gate.py:main`：默认候选为 `ROOT/handoff/inbox/<task>`；在 head 比对和验收前把候选、原件、L1 的绝对路径写到 stderr（包括 `--quiet`）。显式相对路径仍按调用方 CWD 解析。

- 命令：`python -B -m unittest qa.test_audit_fixes.AuditFixes.test_03_default_from_root -v`
- 修前：`(WindowsPath('handoff/inbox/NATIVE-337'), False)`：交给比对的是相对路径，且比对前没输出解析结果（退出码 `1`）。
- 修后：`test_03_default_from_root ... ok`，`OK`，退出码 `0`。

## 4. 不让报告写入候选树

`qa/gate.py:main`、`qa/common.py:path_is_within`：比对前拒绝位于候选树内或经路径链接解析到树内的 `--json`。树外报告原子替换，避免通过已有硬链接改写树内文件。

- 命令：`python -B -m unittest qa.test_audit_fixes.AuditFixes.test_04_report_outside_tree -v`
- 修前：`[0, 2] != [2, 2]`：第一次写报告污染候选，第二次发现多出的路径（退出码 `1`）。
- 修后：`test_04_report_outside_tree ... ok`，`OK`，退出码 `0`。树内路径两次都返回 `2` 且未写文件；树外路径即使原先硬链接到候选文件，两次都返回 `0` 且原文件字节不变。

## 5. 仅从交付元数据确定轮次，缓存只在本次验收有效

`qa/common.py:round_of/current_round/is_current`：以根层 `sN-submission.md` / `sN-receipt.md` 为准；没有回执时，只认根层的标准指纹类 JSON 或约定的 `sN-audit.md`，不扫描 `work/` 取轮次。无元数据时不猜轮次、不丢弃文件。

`qa/det_byte_mismatch.py`、`qa/det_row_linkage.py`、`qa/det_stale_metrics.py`、`qa/det_fingerprint_pathset.py`、`qa/det_truncated_hash.py` 的 `detect`，以及 `qa/det_omitted_sites.py:detect/_csv_cells`，均传递 `qa/gate.py:aggregate` 本次新建的 `ctx`，不再使用进程全局缓存。

- 命令：`python -B -m unittest qa.test_audit_fixes.AuditFixes.test_05_metadata_round_and_snapshot -v`
- 修前：`('pass', 0, 'pass', 0) != ('fail', 2, 'pass', 0)`：`work/s99-gate.txt` 掩盖 s2 短哈希（退出码 `1`）。
- 修后：`test_05_metadata_round_and_snapshot ... ok`，`OK`，退出码 `0`。s2 阻断；同一进程换成 s3 回执再验收，实际检查 s3 的表并通过。

## 6. 旧表不替代本轮指纹

`qa/det_fingerprint_pathset.py:detect`：只校验本轮及无轮次标记的常驻声明；旧轮只用于历史对比。已知本轮或发现本轮指纹表但没有任何指纹声明时，报缺失缺陷。回执给出的本轮摘要声明也可满足要求，单列文件名不算指纹。

- 命令：`python -B -m unittest qa.test_audit_fixes.AuditFixes.test_06_no_historical_fallback -v`
- 修前：`(1, 0, 1) != (0, 1, 0)`（本轮表、历史表、声明路径数；退出码 `1`）。
- 修后：`test_06_no_historical_fallback ... ok`，`OK`，退出码 `0`。只有 s1 表时 s2 报缺失；补上 s2 回执中的正确摘要后通过。

## 7. 按真实路径判断归属

`qa/det_fingerprint_pathset.py:detect/judge`、`qa/common.py:path_is_within`：JSON、回执摘要与文件清单都用 `realpath` + `commonpath` 判断归属；盘符不同时也不会进入校验。树外声明保留记录，但不作为树内文件读取或验证。

- 命令：`python -B -m unittest qa.test_audit_fixes.AuditFixes.test_07_real_containment -v`
- 修前：`AssertionError: True is not false : read a file in a sibling with the same path prefix`，退出码 `1`。
- 修后：`test_07_real_containment ... ok`，`OK`，退出码 `0`。同前缀的兄弟目录不被读取，声明数为 `1`、验证数为 `0`。

## 8. 解析失败带路径阻断，实际比较单独计数

`qa/det_truncated_hash.py:detect`、`qa/det_fingerprint_pathset.py:detect`、`qa/common.py:read_json`、`qa/gate.py:INPUT_KEYS`（供 `unit_status` 使用）：本轮解析错误进入 `stats.error` 并阻断；JSON 严格解码。两个检测器分别报告发现、解析成功、实际比较数；门禁只以实际比较数作为通过计数。

- 命令：`python -B -m unittest qa.test_audit_fixes.AuditFixes.test_08_parse_errors_and_counters -v`
- 修前：两者均为 `'s2-fingerprints.json' not found in ''`；短哈希检测仅报告 `{'files_scanned': 3}`（退出码 `1`）。
- 修后：`test_08_parse_errors_and_counters ... ok`，`OK`，退出码 `0`。两个单元都返回带文件名的 `error`；指纹检测的发现/解析/比较为 `(2, 1, 1)`，短哈希检测为 `(3, 2, 1)`。

## 9. 用全部声明判断集合缩水

`qa/det_fingerprint_pathset.py:_declared_json/_declared_receipt/detect`：`declared_paths` 计去重声明；`verified_paths` 只计摘要比对成功且没有其他未验证声明的路径。缺失、校验不符、短摘要、树外引用、仅列出文件名等仍计入声明；缩水对比的是上个历史轮次与本轮的完整声明集合，不是验证成功的子集。

- 命令：`python -B -m unittest qa.test_audit_fixes.AuditFixes.test_09_declared_vs_verified -v`
- 修前：`(2, None, 5) != (6, 1, 1)`（声明、验证、缩水计数；退出码 `1`）。
- 修后：`test_09_declared_vs_verified ... ok`，`OK`，退出码 `0`。六条路径仍声明、一条通过摘要校验、只有真正移除声明的 `dropped.txt` 被标为缩水。

## 最终验证

### `python -B -m unittest qa.test_audit_fixes -v`

```text
test_01_skipped_l1 (qa.test_audit_fixes.AuditFixes.test_01_skipped_l1) ... ok
test_02_cache_identity (qa.test_audit_fixes.AuditFixes.test_02_cache_identity) ... ok
test_03_default_from_root (qa.test_audit_fixes.AuditFixes.test_03_default_from_root) ... ok
test_04_report_outside_tree (qa.test_audit_fixes.AuditFixes.test_04_report_outside_tree) ... ok
test_05_metadata_round_and_snapshot (qa.test_audit_fixes.AuditFixes.test_05_metadata_round_and_snapshot) ... ok
test_06_no_historical_fallback (qa.test_audit_fixes.AuditFixes.test_06_no_historical_fallback) ... ok
test_07_real_containment (qa.test_audit_fixes.AuditFixes.test_07_real_containment) ... ok
test_08_parse_errors_and_counters (qa.test_audit_fixes.AuditFixes.test_08_parse_errors_and_counters) ... ok
test_09_declared_vs_verified (qa.test_audit_fixes.AuditFixes.test_09_declared_vs_verified) ... ok

----------------------------------------------------------------------
Ran 9 tests in 0.190s

OK
```

退出码：`0`。

### `python qa/selftest.py`

```text
l1-missing-blocks                    PASS
l1-pin-mismatch-blocks               PASS
detector-import-failure-blocks       PASS
detector-exception-blocks            PASS
detector-error-result-blocks         PASS
registry-empty-entry-blocks          PASS
all-units-na-blocks                  PASS
invalid-l1-covers-blocks             PASS
missing-counter-is-error             PASS
bool-counter-not-int                 PASS
original-sha-mismatch-blocks         PASS
check-head-truncated-error           PASS
resolve-ref-containment              PASS
asm-line-rva-single-byte             PASS
current-round-consistent             PASS
rebuild-no-comparison-error          FAIL  <- FileNotFoundError: [Errno 2] No such file or directory: 'D:\\qa_fix_run\\_t13\\orig\\FindComponent.dll'
rebuild-whitelist-missing-error      PASS
16/17 passed
```

退出码：`1`。修前基线同为 `16/17 passed`，唯一失败项与错误相同：当前检出缺少测试所需的 `_t13/orig/FindComponent.dll`。未改动原自测或补入替代原件。

### `python -B -m qa.gate --help`

```text
usage: gate.py [-h] [--task {NATIVE-337,NATIVE-340}] [--item-dir ITEM_DIR]
               [--folder FOLDER] [--head HEAD] [--repo REPO] [--cache CACHE]
               [--original ORIGINAL] [--binary BINARY] [--l1-path L1_PATH]
               [--against-head AGAINST_HEAD] [--skip-l1] [--json JSON]
               [--quiet]

L1 (pinned oracle) + L2 detectors

options:
  -h, --help            show this help message and exit
  --task {NATIVE-337,NATIVE-340}
  --item-dir ITEM_DIR
  --folder FOLDER       alias of --item-dir
  --head HEAD           full 40-character repository head SHA; fetch the task
                        inbox first
  --repo REPO
  --cache CACHE
  --original ORIGINAL
  --binary BINARY       alias of --original
  --l1-path L1_PATH
  --against-head AGAINST_HEAD
  --skip-l1
  --json JSON
  --quiet
```

退出码：`0`。
