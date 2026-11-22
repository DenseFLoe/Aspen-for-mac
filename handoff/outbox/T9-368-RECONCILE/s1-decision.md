# T9-368-RECONCILE 首轮裁定

上游交叉复核任务 accepted。固定 #368 提交 `db544a6fdfb04ec60d182c311aa47d13a61d744b` 的预审报告需退回修订。复核只涉及这 1,000 行预审和随附文档，原件验收仍按各自记录办理。

| 产品 | 条目 | 台账 pass | 台账 fail | stats.md 第 16–18 行 pass / fail |
| --- | ---: | ---: | ---: | --- |
| Plus | 958 | 519 | 439 | 510 / 448 |
| Properties | 23 | 7 | 16 | 23 / 0 |
| Plus-Properties | 19 | 4 | 15 | 4 / 15 |
| 合计 | 1,000 | 530 | 470 | 三行相加为 537 / 463 |

两张 CSV 的 1,000 个身份一一对应。916 条来自待静态验收目录（470 pass、446 fail），84 条来自静态验收未通过目录（60 pass、24 fail）。累计 530 pass、470 fail、0 partial、0 blocked。同一个原件的归档状态和本次预审结论分别保留。Tier B 原始字段为 978 PASS、6 PARTIAL:no_il、1 PARTIAL:no_claim、15 NOT_RUN；455 个带工具提示的 CLR 记录最终均为 fail。

- stats.md 第 36–39 行和 failures.md 第 15–18 行的原因表遗漏了全部 455 条 tool_nag_tail。其余原因按行计为 a2_sha_missing 15、a3_report_missing 15、tier_b_incomplete 6、analyze_failed 1，多码行有重叠。
- failures.md 第 5 行仍报 978 pass、15 fail、7 partial。第 72–77、85 行涉及的 7 个 idx 均有 tool_nag_tail 并已变为 fail。README.md 第 3 行总数正确，第 45 行仍称这 7 个记录为 partial；validation.md 第 3 行总数正确，第 9 行 R3 仍按 15 个失败件叙述。
- Properties 的 idx=893（Aspen Excel Add-in Manager 64 Bit.exe，原件登记 SHA-256 `475a6475332299a4be0eb1573403cbf88176a81e7fcacfa958f5aa9f596866f0`）为 tool_nag_tail、fail。Plus 的 idx=311 同时有 tier_b_incomplete 和 tool_nag_tail，idx=982 同时有 analyze_failed 和 tool_nag_tail。完整对象路径在同轮 reconciliation.json。

恢复条件为从一致的逐行输入重新生成产品矩阵、失败分组及明细、R3 和 README 的限制说明，说明旧 Tier 字段与最终 verdict 的关系，并同步 PR 正文的旧汇总。提交新 head 后，上游逐项重核。455 份单文件资产不需为本项改动。
