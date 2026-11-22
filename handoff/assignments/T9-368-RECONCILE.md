# T9-368-RECONCILE · 1,000 行预审报告核对

执行方为 upstream，assigned_seq=1，时限为 ACK+24h。输入固定为 #368 的提交 `db544a6fdfb04ec60d182c311aa47d13a61d744b`、目录 `handoff/review/t9-1000/` 下的 selection.csv、ledger-1000.csv、README.md、stats.md、failures.md 和 validation.md。覆盖清单身份、产品与状态分布、预审结论、失败原因和四份随附报告。原件身份字段仅按台账核对，不改变逐文件验收状态。

按 `handoff/standards/t9-reconciliation.v1.md` 交付到 `handoff/inbox/T9-368-RECONCILE/`。从仓库根执行 `python -B handoff/assignments/check-t9-368.py`。上游独立重算后在 outbox 给出复核任务结论及 #368 的恢复条件。
