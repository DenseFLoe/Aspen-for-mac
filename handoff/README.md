# Aspen-for-mac 交接协议 v1

双方开工、交付后续接下一件、并发去重、远端等待命令和掉线恢复见[连续工作约定](continuous.md)。每台机器只领取已分配给自己的任务。

上游负责分配、维护标准和裁定，tietoumiao 负责领取已分配的任务、提交证据和回应退回。执行方只监控本仓库的 `handoff/` 和 [issue #13](https://github.com/DenseFLoe/Aspen-for-mac/issues/13)。为完成已领取任务，可以读取任务行明确指定的输入。所有对话集中在 #13，文件通过产物 PR 交付。同一轮可在同一 PR 追加证据。

| 路径 | 写入方 | 记录 |
| --- | --- | --- |
| `README.md`、`standards/` | 上游 | 协议、分类型的版本标准及来源 |
| `assignments/tasks.csv` | 上游 | 每行一个可独立交付的任务，字段见下表 |
| `inbox/<task_id>/` | 该行执行方 | 开工回执、提交物、复跑证据、补件请求。上游作为原件提供方时写入 `inbox/originals/` |
| `outbox/` | 上游 | ACK、裁定、退回原因、问询、材料清单和恢复条件 |
| `ledger/events.csv` | 上游 | 追加状态事件，含 UTC、操作者、证据路径、该证据的完整 SHA-256 |

旧版 `taskbooks/`、`incoming/`、`outgoing/`、`plan/`、`log.md`、`status.json` 作为历史记录保存。从本协议 ACK 起，新任务从 `assignments/` 领取。收到 `HANDOFF-ACK v1 | ref=<40 位提交 SHA> | issue=13` 后，双方以该提交中的协议开工；PR 合入后按主干增量跟进。收到的版本可由 `ref` 回读。

## 分配表

| 列名 | 含义 |
| --- | --- |
| `task_id` | 唯一稳定编号，字母、数字、连字符或下划线 |
| `owner` | 唯一执行方 |
| `input` | 输入范围、文件或固定提交，原件按 SHA-256 区分 |
| `deliverable` | 在 handoff 内应交付的文件或目录 |
| `standard` | standards 内的判据文件和版本 |
| `criterion` | 该任务适用的条款或可观察的完成条件 |
| `check_command` | 从仓库根目录执行的实际判定命令；依赖环境在相应标准中说明。缺命令的行不受理 |
| `due_utc` | ISO 8601 UTC 截止时刻；按 ACK 起算时填写明确的相对时限 |

每个标准以 `<类别>.v<整数>.md` 命名。判定标准只在 `standards/` 发布，同类别冲突以已发布的最高数字版本为准。执行方不能自行放宽。任务行保留原版本以便重放；升版影响在途任务时，上游先在 outbox 说明影响、同步任务行和 #13，再按新版本复核。不同类别分别回答各自的问题。

## 状态和时限

`assigned → started → submitted → accepted | returned | blocked`。上游写分配行并登记 assigned。执行方在 inbox 写开工回执或用 #13 指向已落盘的开工证据，上游据此登记 started。执行方提交产物和指纹后，上游登记 submitted，再运行判定命令并记录裁定。缺输入时可提交含已查范围、缺件身份和恢复条件的阻塞报告，由上游登记 submitted → blocked。

每次状态变化都须有 ledger 行及在本目录可回读的证据。上游接受才记 accepted。returned 或 blocked 恢复时保留原序列，上游写明补正或恢复依据后重新 assigned。旧裁定保留，事件按每个任务的 seq 递增，重试提交同一事件按 task_id 和 seq 去重。执行方不写台账、不自行验收。

回执和裁定建议命名为 `<task_id>/<UTC时间>-<started|submission|decision|query>.md`。相同内容用 SHA-256 去重，修订用新文件或新提交，保留历史。所有时间用 UTC。ACK 后 30 分钟仍无开工信号、到期仍无提交、或提交后 120 分钟仍无裁定时，由上游在 outbox 留问询并同步 #13。超时本身不改变验收状态。无新分配时执行方停在当前批次。
