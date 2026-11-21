# 我方技能库精简版（给上游参考）

## 地位：这不是标准

- 这里是**我方内部操作规范**，用来解释"我们的交付物是怎么产出、怎么自检的"，方便你方判断该退回哪一步。
- 与 `docs/static-acceptance.md`、`AGENTS.md` 冲突时，**一律以上游为准**；本目录不新增、不放宽任何验收判据。
- 已按你方口径对齐的部分在 [`handoff/standards/`](../standards/)（PR #365）；本目录是"做法"，那里是"判据"。

## 选了哪五份，为什么

| 文件 | 来自 | 对本次任务的作用 |
| --- | --- | --- |
| [pr.v1.md](pr.v1.md) | `pr` | PR 正文固定三节（Summary / Evidence / Merge Danger），省掉"这个 PR 到底改了什么"的来回 |
| [pr-body-template.v1.md](pr-body-template.v1.md) | `pr/references` | 上面那份的骨架与示例 |
| [code-review.v1.md](code-review.v1.md) | `code-review` | 两轴评审：**仓库既有标准** + **原始工单要求**，两轴都过才算过；我方提交前自己先跑一遍 |
| [upstream-pr-readiness.v1.md](upstream-pr-readiness.v1.md) | `upstream-pr-readiness` | 六道闸门 + 交叉循环检验 + **Windows 平台语义清单**（我方历史 5 类缺陷全部来自"用 POSIX 直觉写 Windows 代码"） |
| [supervision-gates.v1.md](supervision-gates.v1.md) | `supervision-gates` | 交付前五门禁，以及"一次批处理到底算不算成功"的唯一判据（避免把退出码 0 当成功） |

## 没传的部分

- 其余 88 条技能与静态验收无关（Office 文档、量化回测、GUI 交互、数据库等），传了只会增加噪音。
- `flowntier-pipeline`（我方八阶段代码闸门，22 KB）没传：它是我方内部编排细节，与验收口径无关；需要时可以单独摘要。

## 我方批次纪律（本次实践，非标准，供参考）

| 项 | 我方实测值 |
| --- | --- |
| 批次规模 | 210 文件/PR（单次推送上限） |
| 吞吐 | IDA 6 并发 ≈ 3 s/件；ILSpy 4 并发 ≈ 2.7 s/件；全检 1,315 件 ≈ 3 分钟 |
| 证据 | 每件标〔已实测〕/〔未验证〕/〔无法判定〕三档，混写即返工 |
| 抽样 | 每批至少 3 件人工复核；缺陷率 > 0 整批退回，不"边补边发" |
| 进程管理 | 只按 **pid 文件** kill（曾按进程名批量 kill，打死了宿主进程） |
| 自我重算 | 同一结论至少独立重算一次——293 件同 SHA-256 的 join 漏项就是这么发现的 |

## 怎么用

- 你方退单/退修时可以直接引用条目（例：`upstream-pr-readiness §1 第二道闸门`、`code-review 两轴`），我方按条目自查后回帖，避免"到底哪一步不合格"的反复。
- 若你方希望某条改成硬要求，写进 `docs/` 即可，我方按 `handoff/standards/` 升版跟随。
