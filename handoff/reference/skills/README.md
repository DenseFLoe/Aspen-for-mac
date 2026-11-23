# 我方技能库精简版（给上游参考）

## 地位：这不是标准

- 这里是**我方内部操作规范**，用来解释我们的交付物怎么产出、怎么自检，方便你方判断该退回哪一步。
- 与 docs/static-acceptance.md、AGENTS.md 冲突时，**一律以上游为准**；本目录不新增、不放宽任何验收判据。
- 判据在 [handoff/standards/](../standards/)（PR #365）；本目录是做法，那里是判据。

## 第一批：交付与门禁（我方自建）

| 文件 | 来自 | 对本次任务的作用 |
| --- | --- | --- |
| [pr.v1.md](pr.v1.md) | pr | PR 正文固定三节（Summary / Evidence / Merge Danger），省掉「这个 PR 到底改了什么」的来回 |
| [pr-body-template.v1.md](pr-body-template.v1.md) | pr/references | 上面那份的骨架与示例 |
| [code-review.v1.md](code-review.v1.md) | code-review | 两轴评审：**仓库既有标准** + **原始工单要求**，两轴都过才算过 |
| [upstream-pr-readiness.v1.md](upstream-pr-readiness.v1.md) | upstream-pr-readiness | 六道闸门 + 交叉循环检验 + **Windows 平台语义清单** |
| [supervision-gates.v1.md](supervision-gates.v1.md) | supervision-gates | 交付前五门禁，以及「一次批处理算不算成功」的唯一判据 |

## 第二批：通用工作法（Matt Pocock 那套，我方逐字快照在用）

这 5 条来自公开技能集 mattpocock/skills，我方库中是逐字快照（未改写），这次整批任务在用。grilling（交互式盘问）与夜跑不合，已剔除。

| 文件 | 干什么 | 在这次任务里的对应物 |
| --- | --- | --- |
| [to-tickets.v1.md](to-tickets.v1.md) | 把计划/spec/对话拆成 **tracer-bullet 工单**，每张显式声明**被谁阻塞** | 你方那 313 张工单的形态，和我方 A1–A5 的拆工 |
| [triage.v1.md](triage.v1.md) | 工单走状态机：分类 → 核实 → 必要时 grill → 写成可执行的 brief | 我方对 313 张做的分诊（C1–C6 分类、290/313 同 SHA 的更正） |
| [diagnosing-bugs.v1.md](diagnosing-bugs.v1.md) | 硬 bug 的诊断循环：先复现、再二分，禁止「改到不报错为止」 | #353 脏行这类「某件输出里混了怪行」的定位 |
| [implement-spec.v1.md](implement-spec.v1.md) | 按 spec + tickets 在集成分支实现，ticket 关闭即完工 | 我方 worker 的执行方式 |
| [wait-what.v1.md](wait-what.v1.md) | 异步收到看不懂的回复就要求重讲（简化技术英语 + 术语表） | 退回时说人话，不许含糊 |

### 本地化差异（照抄会卡住的地方）

上述 5 条原文假设有 /setup-matt-pocock-skills 配好的 tracker、GLOSSARY.md 术语表、/to-spec 产物。我方实际映射：

| 原文假设 | 我方实际 |
| --- | --- |
| 配置好的 issue tracker | GitHub issue #13（沟通）+ 你方逐件工单 |
| GLOSSARY.md | 你方 docs/ 术语（静态验收通过 / 未通过 / 待静态验收 / 未成功） |
| /to-spec 的 spec 文件 | 我方 00-req.md（含 §19 执行基准）+ taskbooks/T*.md |
| disable-model-invocation 等工具旗标 | 不适用，纯人工/agent 混合执行 |

## 没传的部分

- 其余 77 条技能与静态验收无关（Office、量化、GUI、数据库、渗透等），传了只是噪音。
- flowntier-pipeline（我方八阶段代码闸门，22 KB）没传：属于内部编排细节，与验收口径无关。

## 我方批次纪律（本次实践，非标准，供参考）

| 项 | 我方实测值 |
| --- | --- |
| 批次规模 | 210 文件/PR（单次推送上限） |
| 吞吐 | IDA 6 并发 ≈ 3 s/件；ILSpy 4 并发 ≈ 2.7 s/件；全检 1,315 件 ≈ 3 分钟 |
| 证据 | 每件标〔已实测〕/〔未验证〕/〔无法判定〕三档，混写即返工 |
| 抽样 | 每批至少 3 件人工复核；缺陷率 > 0 整批退回，不边补边发 |
| 进程管理 | 只按 **pid 文件** kill（曾按进程名批量 kill，打死了宿主进程） |
| 自我重算 | 同一结论至少独立重算一次——293 件同 SHA-256 的 join 漏项就是这么发现的 |

## 怎么用

- 你方退单/退修时可以直接引用条目（例：upstream-pr-readiness §1 第二道闸门、code-review 两轴、to-tickets 阻塞边），我方按条目自查后回帖。
- 若你方希望某条改成硬要求，写进 docs/ 即可，我方按 handoff/standards/ 升版跟随。