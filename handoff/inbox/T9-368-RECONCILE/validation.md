# T9 自检（R1–R6 逐条，机检预审 · 第二轮更正）

生成时间：2026-11-22 ｜ 台账：out/review9/ledger-1000.csv ｜ 结论：pass **530** / fail **470** / partial 0 / blocked 0（2026-11-22 因 tool_nag_tail 重算，R3 同步改写）

| id | 判据 | 实测结果 | 证据 |
| --- | --- | --- | --- |
| R1 | 1,000 行齐全、无遗漏、无重复（item_dir 唯一） | ✅ rows=1000 ｜ unique item_dir=1000 ｜ dup=0 ｜ dup_idx=0 | reconciliation.json matched_rows / unique_item_dirs |
| R2 | 每行 verdict ∈ {pass,fail,partial,blocked}、无空值、fail 行必有 fail_codes | ✅ bad_verdict=[] ｜ fail_no_code=[] ｜ fail=470 全带码 | reconciliation.json verdicts / code_counts |
| R3 | 每个 fail 有 fail_code 且 failures.md 列全该码的 idx 并给复跑命令 | ✅ 470 件 fail 全带 fail_codes（tool_nag_tail 455、a2_sha_missing 15、a3_report_missing 15、tier_b_incomplete 6、analyze_failed 1；占用 492 次，多码重叠 22 行）；failures.md 每组列全 idx，并给 verify_item.py --idx <idx> --fresh | failures.md / reconciliation.json code_counts |
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
- 本轮另用 _t13/recompute.py 从两张 CSV 独立复算全部数字（不读旧文档），结果与 reconciliation.json 完全一致。

## 已知异常（已定位，不影响结论）

1. **e1 GitHub raw 对裸 ~ 返回 404**：变体导出（<name>~<hash>.asm.txt）必须先编码为 %7E；已在 fetch 层修。
2. **http.client 绕过系统代理**（本机 127.0.0.1:65533）⇒ 直连整片 404；终轮改回 urllib（走代理）。
3. **shard-5.csv 曾半写损坏**：worker 与我方重跑并发写同一文件；已停 worker（interrupt w9）并重跑 shard 5/9，合并前逐片解码校验通过。
4. **^MD 把页脚哨兵行 MD (none) body=none 计入** ⇒ 12 件假 fail；改 ^MD 0x 后归零。
5. **A6 曾把 IL_XXXX 误判占位符**（30 件假 fail）；收窄后归零。
6. **A4/A5 曾对表格模板报告、分支交付件误报**（149 件假 a5）；按「字段在即算在 + 无 dumps 行时看目录内导出 blob」修正。
7. **A6/B4 漏检尾部工具提示**：只匹配行首工具名，455 件 .cs.txt 尾部残留 ilspycmd 升级提示未计入 ⇒ 假 pass 455 件；第二轮按尾部扫描重算，全部转 fail（见 stats.md §4、failures.md）。

## 复跑

    cd _work/wf-20261120-aspen-batch
    PYTHONIOENCODING=utf-8 python out/review9/review_shard.py --shard all --threads 96   # 全量重算（缓存命中时 ~45 s）
    PYTHONIOENCODING=utf-8 python out/review9/merge_ledger.py                             # 合并 + R1/R2/R6 断言
    PYTHONIOENCODING=utf-8 python out/review9/gen_reports.py                              # stats/failures/README/11-report
    PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx 916 --fresh            # 单件复跑
