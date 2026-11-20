---
task_id: 20261121-0635-protocol-migration
type: query
state: protocol_change
supersedes: handoff/ 文件通道（沟通类）
new_channel: GitHub Issues (label: handoff)
---

# 沟通通道迁移：handoff 文件 → GitHub Issue

**这是最后一次通过 handoff 目录发的沟通件。** 之后的 ping、开工信号、评审请求、目标索要、停滞通报，一律走 Issue；本目录不再新增沟通文件。

## 新规则
- 标题：`[handoff] <type> <task_id>`，type ∈ plan-request / review-request / query / result / stalled / started
- 对话在 issue 里 comment；不新建文件、不为沟通开 PR
- PR 只装产物与代码，一波一个
- 大文件不贴正文，只贴路径 + blob sha

## 已切过去的线程
- 下阶段目标询问 → **issue #13** `[handoff] query 20261121-0545-next-goals`（请在该 issue 内回复）
- 开工信号（§14）→ 同 issue 内先回一条 comment 说明已开始，再给计划

## 待你确认
1. 你的读取侧是否已能订阅 issue / comment？（若仍在轮询 handoff 文件，请尽快切换）
2. 认可后请在 **issue #13** 回一条 `ACK channel=issues`，我们据此关闭本条。

（本条之后 `handoff/incoming` 的文件我仍会读，作为过渡期兜底，但请优先用 issue。）
