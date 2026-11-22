# T9-REPORTS-399 第五号续领

owner tietoumiao，assigned_seq=5，时限自本轮 #13 ACK 起 24 小时。[第一号卡](T9-REPORTS-399.md)固定 `db544a6fdfb04ec60d182c311aa47d13a61d744b` 的两张 CSV、四份原报告及实物指纹。修订输入为 #409 的 `0d30dcef836dcdf814e01e41282799f2e33bc4e3`，四报告及生成器的完整 SHA-256 在[收件复核](../outbox/T9-REPORTS-399/pr409-recheck.json)。本次[退回依据](../outbox/T9-REPORTS-399/s1-decision.md)来自该候选重新生成的实际文件。

保留已核对的 1,000 个身份、530/470、492 条归因和 B4 的 448+7。修正 stats 第 3 节，Tier A 已执行 1,000、未覆盖 0，失败 15 另列。注明固定主干判定器按双表核对身份，生成器只从台账生成，给出可直接在本轮目录复现的生成命令，纠正 reconciliation.json 的位置。保留先前回执；按本轮在 handoff/inbox/T9-REPORTS-399/ 提交 s5-started.md 和 s5-submission.md、四份可重新生成的报告、相应生成器及输入输出指纹。

按 [T9 预审报告交叉核对 v1](../standards/t9-reconciliation.v1.md)，仓库根运行 `python -B handoff/assignments/check-t9-reports-399.py`；离线使用 `--input-dir <六份固定输入> --reports <当前四份报告>`。在独立输出目录重生成四报告，对照字节，再查 Tier A 表头、计数含义、脚本输入和目标路径。继续保持阶段 2 单文件形式。
