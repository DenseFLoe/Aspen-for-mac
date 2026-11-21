# 验收标准镜像（handoff/standards/）

本目录把主干上**当前生效**的验收口径固定成一组带指纹的快照，让双方（含我方批量流水线）执行**同一份文本**，不再靠 issue 里复述。

## 本目录的地位

- **权威副本仍在原路径**（下表「来源」列）。本目录是**只读镜像**，不新增、不改写、不解释任何判定规则；镜像与原文冲突时，**一律以主干原文件为准**。
- **版本固定**：镜像自 `main@f7959f39fd631692f14ecbbdfbf2496f543362b3`，抓取日 2026-11-21。
- **升版方式**：源文件变更后不就地改本目录，另提 PR 生成 `v2`（`v1` 保留），并在 `sources.json` 记录新的提交 SHA 与新指纹。这样任何一件的验收结论都能追溯到当时依据的文本版本。

## 镜像清单

| 镜像文件 | 来源 | 字节 | SHA-256 前 12 位 | 作用 |
| --- | --- | ---: | --- | --- |
| [project-instructions.v1.md](project-instructions.v1.md) | `AGENTS.md` | 6,769 | `d05d86f4b9f0` | 项目指令：核心工作、不可省略约束、仓库工作流、四态目录 |
| [static-acceptance.v1.md](static-acceptance.v1.md) | `docs/static-acceptance.md` | 4,273 | `c898f0807c90` | **静态验收要求**：一件怎么验（4 步）、通过判据、结果放哪里、批量提交 |
| [reverse-execution-workflow.v1.md](reverse-execution-workflow.v1.md) | `docs/reverse-execution-workflow.md` | 4,772 | `b05a122d99c5` | 执行规则：选件 → 孤立/连锁 → 验收归档 → 未完成项 → 清单同步 |
| [reverse-execution-reference.v1.md](reverse-execution-reference.v1.md) | `docs/reverse-execution-reference.md` | 15,373 | `1347ea7f0288` | 详细规则：§3.1 完成判定五条、§3.2 命名、§4 重试/暂存、§5.1 台账 |
| [reverse-work-status.v1.md](reverse-work-status.v1.md) | `docs/reverse-work-status.md` | 1,480 | `43ba0b6a772f` | 阶段报告：现核心工作 + 最近一轮（20261119-61）结果与入口 |
| [acceptance-sop.v1.md](acceptance-sop.v1.md) | 派生（上列五份的综合） | — | — | **一页版操作流程**，供流水线照着跑；派生件，不具裁定力 |
| [sources.json](sources.json) | — | — | — | 机器可读溯源：提交 SHA、路径、字节、SHA-256 |

## 怎么用

1. **执行方**（我方流水线）：逐件按 [acceptance-sop.v1.md](acceptance-sop.v1.md) 的 P0–P4 跑，通过/不通过/暂存三分支只按 [static-acceptance.v1.md](static-acceptance.v1.md) 的判据落，不自行放宽。
2. **裁定方**（上游）：改判定口径就改 `docs/` 原文件并发 PR；镜像随源升版。**镜像不改，就说明口径没变**——这也是我方判断「标准是否已更新」的信号。
3. **机读**：`sources.json` 里有 `commit` 与每份 `sha256`，可用于校验镜像是否漂移。

## 边界

- 本目录**不含**原件、二进制、源码或证据包，只含 Markdown 与一份 JSON。
- 本目录**不取代** `逆向成果/` 的四态目录，也不取代逐件同名 `.md` 说明；验收结论仍写在逐件说明里。
