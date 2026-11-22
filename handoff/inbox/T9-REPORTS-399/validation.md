# T9 自检（R1–R6 逐条，机检预审 · 第二轮更正）

生成时间：2026-11-22 ｜ 台账：out/review9/ledger-1000.csv ｜ 结论：pass **530** / fail **470** / partial 0 / blocked 0（2026-11-22 因 tool_nag_tail 重算，R3 同步改写）

| id | 判据 | 实测结果 | 证据 |
| --- | --- | --- | --- |
| R1 | 1,000 行齐全、无遗漏、无重复（item_dir 唯一） | ✅ rows=1000 ｜ unique item_dir=1000 ｜ dup=0 ｜ dup_idx=0 | handoff/inbox/T9-368-RECONCILE/reconciliation.json matched_rows / unique_item_dirs |
| R2 | 每行 verdict ∈ {pass,fail,partial,blocked}、无空值、fail 行必有 fail_codes | ✅ bad_verdict=[] ｜ fail_no_code=[] ｜ fail=470 全带码 | handoff/inbox/T9-368-RECONCILE/reconciliation.json verdicts / code_counts |
| R3 | 每个 fail 有 fail_code 且 failures.md 列全该码的 idx 并给复跑命令 | ✅ 470 件 fail 全带 fail_codes（tool_nag_tail 455、a2_sha_missing 15、a3_report_missing 15、tier_b_incomplete 6、analyze_failed 1；占用 492 次，多码重叠 22 行）；failures.md 每组列全 idx，并给 verify_item.py --idx <idx> --fresh | failures.md / handoff/inbox/T9-368-RECONCILE/reconciliation.json code_counts |
| R4 | Tier B 覆盖率写实数 | ✅ 985/985（CLR 455/455、native 530/530）；另 15 件真非 PE/缺报告只做 Tier A；tier_b 原始字段 PASS 978 / PARTIAL:no_il 6 / PARTIAL:no_claim 1 / NOT_RUN 15 | stats.md §3 |
| R5 | 三档证据逐行单值、不混写 | ✅ 已实测 1000（无未验证/无法判定行） | ledger evidence_level |
| R6 | 分片结果与合并一致（抽 20 行逐字段） | ✅ mismatch fields = 0（合并日志断言；本轮只复核台账，未重跑分片合并） | logs/merge.json r6_mismatch |

## 分片一致性

| 项 | 值 |
| --- | --- |
| 分片文件 | 12 个 shard-<n>.csv（83–84 件/片，合计 1,000；按 idx % 12 重算件数一致） |
| 分片自校验文件 | 12 个 shard-<n>.check.md + 12 个 shard-<n>.summary.md（worker 各自抽 5 行） |
| 首轮 worker 原始结果 | shard-<n>.worker.csv（保留，未删；与终版差异来自判据修订） |
| 合并断言 | python out/review9/merge_ledger.py → rows 1000 / dup 0 / R6 0 mismatch |

## 独立抽查（不与 worker 复用同一实现）

- 我本人用独立 urllib 重取 7 件（5 件 pass + 2 件非 pass）：两侧 SHA-256 逐字符相同 6/6（第 7 件报告缺失，符合 fail），导出计数与 evidence 一致。
- 12 个 worker 各自 5 行抽查，回报全部一致（详见各 shard-<n>.check.md）。
- 本轮（s5）用本目录生成器从 ledger-1000.csv 重生成四份报告，四份逐字节复现；双表身份核对仍由固定 check-t9-368.py 完成，其结果与归档 `handoff/inbox/T9-368-RECONCILE/reconciliation.json` 一致（本目录无同名文件）。

## 本轮（s5）更正说明

1. **Tier A 口径**：原第 3 节写作「应做 1,000、实做 1,000、覆盖率 100%、未覆盖 15」。按固定台账，Tier A 是 **PASS 985 + FAIL 15 = 1,000，全部有执行结果**，故 **未覆盖 = 0**，失败的 15 件在 §4 单列（a2_sha_missing + a3_report_missing）。生成器已改，四份报告按新口径重生成。
2. **谁核对什么**：两张 CSV 的 1,000 个身份逐行比对由固定的 `handoff/assignments/check-t9-368.py` 完成（SHA-256 `ff2fbcd5873e5d86d4912417dccdc39eb6d638fef701a80dd8c047f00e9a58b1`）；本目录生成器 **只读 ledger-1000.csv** 生成四份报告，不读 selection.csv。实测：移走 selection.csv 后重跑，四份报告逐字节相同。
3. **输出路径**：生成器 `--out` 默认值已改为 `handoff/inbox/T9-REPORTS-399`（原默认写的是旧任务目录 T9-368-RECONCILE）。完整命令见 README「复现」。
4. **reconciliation.json 位置**：本候选目录**没有**该文件；固定结果归档在 `handoff/inbox/T9-368-RECONCILE/reconciliation.json`（标准 §3 指定位置，check-t9-368.py 的 RESULT 常量同样指向它）。stats.md、README.md 与本表的引用已全部改指该路径，不再写「同目录」。
5. **三个数不混**：`455` 是 Tier B 的 B4 失败件数（CLR 455 = 合计 455），构成是 **448 件原 pass + 7 件原 partial**；`492` 是 fail_code 的**归因占用次数**（允许一行多码）；`470` 是 **fail 身份行数**。三处分别标注，互不替代。

## 已知异常（已定位，不影响结论）

1. **e1 GitHub raw 对裸 ~ 返回 404**：变体导出（<name>~<hash>.asm.txt）必须先编码为 %7E；已在 fetch 层修。
2. **http.client 绕过系统代理**（本机 127.0.0.1:65533）⇒ 直连整片 404；终轮改回 urllib（走代理）。
3. **shard-5.csv 曾半写损坏**：worker 与我方重跑并发写同一文件；已停 worker（interrupt w9）并重跑 shard 5/9，合并前逐片解码校验通过。
4. **^MD 把页脚哨兵行 MD (none) body=none 计入** ⇒ 12 件假 fail；改 ^MD 0x 后归零。
5. **A6 曾把 IL_XXXX 误判占位符**（30 件假 fail）；收窄后归零。
6. **A4/A5 曾对表格模板报告、分支交付件误报**（149 件假 a5）；按「字段在即算在 + 无 dumps 行时看目录内导出 blob」修正。
7. **A6/B4 漏检尾部工具提示**：只匹配行首工具名，455 件 .cs.txt 尾部残留 ilspycmd 升级提示未计入 ⇒ 旧称「假 pass 455 件」，已更正为 448 件原 pass + 7 件原 partial（见 stats.md §4、failures.md）。

## 复跑

    cd _work/wf-20261120-aspen-batch
    PYTHONIOENCODING=utf-8 python out/review9/review_shard.py --shard all --threads 96   # 全量重算（缓存命中时 ~45 s）
    PYTHONIOENCODING=utf-8 python out/review9/merge_ledger.py                             # 合并 + R1/R2/R6 断言
    PYTHONIOENCODING=utf-8 python out/review9/gen_reports.py                              # stats/failures/README/11-report
    PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx 916 --fresh            # 单件复跑

# 原判定与现判定分列（第二轮更正）

| 原 Tier B 判定 | 件数 | 现在 | 去向 |
| --- | ---: | --- | --- |
| PASS | 978 | pass 530 / fail 448 | 448 件尾部残留 ilspycmd 提示（B4 tool_nag_tail）转 fail |
| PARTIAL | 7 | fail 7 | 7 件原 partial（no_il 6 / no_claim 1）全部转 fail |
| NOT_RUN | 15 | fail 15 | a2/a3/tier_b/analyze_failed 等既有失败 |
| 合计 | 1000 | pass 530 / fail 470 | B4 的 455 个失败 = 原 PASS 448 + 原 PARTIAL 7；本表保留旧回执口径，不覆盖 |

更正口径：原 978 pass 中 **448 件**因尾部工具提示转 fail；原 **7 partial**（no_il 6 / no_claim 1）全部转 fail；另有 15 件 NOT_RUN 维持 fail。旧称「455 件假 pass」作废，应为「448 件原 pass + 7 件原 partial」。
