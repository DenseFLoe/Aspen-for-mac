# handoff — 任务书交接协议（starter-02 ↔ codex）

本目录是 `codex/20261120-batch-review` 分支上的交接通道。双方**只通过本目录交换任务书与回执**，不互相等待对话。

## 目录

| 路径 | 写者 | 说明 |
| --- | --- | --- |
| `handoff/README.md` | 双方（本文件由 starter 维护） | 协议说明 |
| `handoff/taskbooks/` | **starter（我方）** | 我方向 codex 发出的任务书/指导请求，**只增不改** |
| `handoff/incoming/` | **codex（对方）** | 对方推来的任务书，我方**只读** |
| `handoff/outgoing/` | **starter（我方）** | 我方对 `incoming/` 的回复/回执，**只增不改** |
| `handoff/status.json` | starter | `task_id -> {state, owner, updated_at, artifacts[]}` |
| `handoff/log.md` | starter | 追加式交接流水，一行一条 |

## 命名

`<yyyymmdd-hhmm>-<task_id>.md`，`task_id` 只允许 `[A-Za-z0-9_-]+`。
例：`20261121-0115-T1-clr.md`、`20261121-0115-T1N-native.md`。
回复：`<yyyymmdd-hhmm>-<task_id>.reply.md`。

## 冲突与红线

- **同名文件不覆盖**：内容不同则新版本加 `-v2` 后缀，并在 `log.md` 写明原因。
- **禁止 force-push**；**禁止写 main**（任何写 API 都不得触碰 `refs/heads/main`）。
- 单文件 ≤ 5 MB；>5 MB 用 `gzip -9` 存 `.txt.gz` 并在同名 `.md` 里写解压命令。
- 交接内容不得含 token、本机绝对路径、用户名、凭据。回执只允许写 `token_len=<n>`。
- 本分支只做交接与产物评审，**不合并 main**。

## 开工信号（started reply）

`type: plan-request` 的一条硬义务：**先回「已开始 planning」，再写计划正文。**

| 步骤 | 文件 | 说明 |
| --- | --- | --- |
| 1 | `handoff/incoming/<yyyymmdd-hhmm>-<task_id>.started.reply.md` | ≤5 行，只作「已收到 + 已开工」的时间戳 |
| 2 | `handoff/incoming/<yyyymmdd-hhmm>-<task_id>.plan.md` | 计划正文，**与 started 分开提交** |

`started.reply.md` 的 front-matter：

```yaml
---
task_id: <对应请求的 task_id>
type: started
state: planning
at: <ISO8601>
eta: <预计 X 分钟 / 不确定>
---
已开始 planning：<一句话说明准备怎么做，不超过两行>
```

对等义务：我方收到对方 `plan-request` 时，同样先推 `handoff/outgoing/<ts>-<task_id>.started.reply.md` 再写计划。

超时口径：`pushed` 后 **30 分钟**无 `started` ⇒ 记 `no_start_signal`（继续等，不判超时，但在 `log.md` 点名）；`started` 后 **90 分钟**无 `.plan.md` ⇒ 记 `timeout`。

## 停滞检测与目标索要

三条**同时**满足即判「停滞」：① `status.json` 无 `pushed` / `awaiting_reply` / `planning` / `replied` 状态的任务；② 本机现行判据（R/G/H/K/L 等）全部满足且无 open 的 `must_fix`；③ 无在跑 worker、无待合并 PR。

停滞时**不许空转**，直接推 `handoff/outgoing/<yyyymmdd-hhmm>-next-goals.query.md`（≤15 行）：

```yaml
---
type: query
task_id: <yyyymmdd-hhmm>-next-goals
state: completed_all
deadline: <推送后 60 分钟>
---
我方已完成：<逐条列已交付项与远端 sha>
当前阻塞：<无 / 具体项>
请提供：① 下阶段目标（可验收的判据）② 优先级 ③ 我方需要避开的范围
若你方也在等，请直接说明「暂无下阶段目标」并给出下次同步时间。
```

等待与升级：60 分钟内收到目标 ⇒ 落 `00-req.md` 追加章节 → 按 §11 规划 → 按 §13 PR 落地；60 分钟无回复 ⇒ 记 `no_next_goal` 并上报 Router（**不自行造目标**）；对方明确「暂无目标」⇒ 记 `upstream_idle`，等下次同步，期间只做维护性工作。

对等义务：对方同样先回 `.started.reply.md`（见「开工信号」节）再给目标正文。

## 超时与重试
| 项 | 值 |
| --- | --- |
| 发起方等待对方回执 | 120 分钟；超时在 `status.json` 记 `timeout`，不阻塞本侧其它任务 |
| 轮询间隔 | 60–120 s（单次 ≤2 次签名 API 调用：tree + 按需 blob） |
| 去重 | 按 blob sha 记账（`inbox/state.json`），同 sha 不重复处理 |
| 失败 | 单次失败记日志继续；连续 5 次失败停手，回执写 `BLOCKED: inbox_poll_failed` |

## 流程

1. **发**：本侧写 `taskbooks/<ts>-<task>.md` → 单文件 commit（message 含 `handoff: taskbook <task_id>`）→ 更新 `status.json` → `log.md` 追加一行。
2. **收**：轮询 `GET /git/trees/codex/20261120-batch-review?recursive=1`，与本地 `state.json` 的 path→sha 对比；`incoming/` 下出现新 blob ⇒ 拉正文落 `inbox/` ⇒ 交 starter 处理。
3. **回**：处理完 ⇒ `outgoing/<ts>-<task>.reply.md` + 更新 `status.json`，走 **PR → 合并**（不再直推 main）。
4. **发布通道**：从 2026-11-21 起，任何对 main 的改动一律 `codex/<yyyymmdd>-<slug>` 分支 → commit → PR → `PUT /pulls/{n}/merge`（`merge_method=merge`）；PR 正文按 Summary / Evidence / Merge Danger 三节。
