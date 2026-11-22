# #399 千件预审报告修订复验

复验结论为退回补正。固定候选为 `c4f2ff4d126936da46af988ca083bbb9521ed5f0`。#13 首报 `844c7e7e62cfdc318505e13399546970d9716c92` 与候选的四份报告、两份回执及 reconciliation.json 逐个 Git blob 相同。复验基准为主干 `773260c1033e524cebe000699409f5708bebfda0` 的 `handoff/standards/t9-reconciliation.v1.md` 和既有首轮裁定。原件级通过数本项新增 0。

在固定 #368 输入 `db544a6fdfb04ec60d182c311aa47d13a61d744b` 上运行 `python -B handoff/assignments/check-t9-368.py --input-dir <固定六文件目录>`，退出 0。检查器 SHA-256 为 `ff2fbcd5873e5d86d4912417dccdc39eb6d638fef701a80dd8c047f00e9a58b1`，核对了六份输入的完整摘要。输出中的旧矩阵冲突对应 #368 的旧文档。另将候选四报告交由同一对照函数解析，并独立遍历 failures.md 的全部 492 行归因，逐行查 idx、分片、产品、对象路径及 verdict，逐原因集合全等且组内无重复。用 `python -B tool/t9_reports.py --input-dir <固定六文件目录> --out <新目录>` 生成四报告，各与候选逐字节一致。

| 已核项目 | 结果 |
| --- | --- |
| 选择与台账 | 1,000 个逐行身份一致；530 pass、470 fail、0 partial、0 blocked |
| 产品 pass / fail | Plus 519 / 439、Properties 7 / 16、Plus-Properties 4 / 15 |
| 失败行及明细 | 470 行、492 次归因；tool_nag_tail 455、a2 和 a3 各 15、tier_b_incomplete 6、analyze_failed 1；validation.md 的 R3 为 470 |
| 四份成果 SHA-256 | README `8856c51d71541f86a40894fd4dc429e891b0b5840e9e95e88e7c3da470a71198`；stats `4017ce61682f7a6548c6760cdea5678dd0b251e41a46c0ac24dd6d4039fd6ac0`；failures `721af5b39d872112bbe5c08a7790edb0a3ab8cf52de84e8e2a02a9ad6bef5310`；validation `1ce0514ac4d6572cac7928254f535d357175aa7400ea541547dcba74592584c5` |

恢复条件如下。

1. 按 ledger-1000.csv 过滤含 tool_nag_tail 的行，再按 tier_b 分组，得到 448 个 PASS、6 个 PARTIAL:no_il、1 个 PARTIAL:no_claim。validation.md 第 37 行的“假 pass 455 件”须改为 448 个原 pass 和 7 个原 partial。stats.md 第 33–38 行标题写“失败件”，CLR 与合计均列 0，而 README.md 第 16 行的 B4 计入 455 个 CLR 失败。给旧字段明确标记，另列新版 B4 的 455 个失败；继续保留 7 个部分执行项。同步生成器，重生成四份报告。
2. `tool/t9_reports.py` 第 32 行只读 ledger-1000.csv。生成器若继续声称独立从两张表核对身份，需读取 selection.csv 并校验身份；也可在说明中将双表复核准确归于已运行的主干检查器。
3. 上游 T9-368-RECONCILE 首轮已记 accepted。当前 PR 改写该轮同名 s1-started 和 s1-submission，候选 SHA-256 分别为 `90e169fd212327ecdd43c4a9e2d4fe2c4f7ff0d6435dc23af6ad858426ca0906`、`507b69fcc323947f176c7cd985d31663af6d73d924446ffc8f21fc68107f3406`，主干旧事件分别引用 `01a974237ec6023269b04319f0ea1c16294a112d86bda983df019515eddb649b`、`8077eaa6769e8535f478fb62d180999c6ebe4f7a39b74c1b8fd4247269f3235c`。新修订使用独立任务目录和回执，保留既有两个证据。PR 的变更清单另有六个原生及 IL 分析工具，发布时收敛至本项报告、生成器与回执。
