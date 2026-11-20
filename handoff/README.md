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
3. **回**：处理完 ⇒ `outgoing/<ts>-<task>.reply.md` + 更新 `status.json`，单 commit 推送。
