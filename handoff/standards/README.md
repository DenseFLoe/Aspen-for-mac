# 验收标准索引

双方交接只执行本目录内已发布的分类标准。同一类别取最高数字版本。由上游在产物 PR 发布并在 #13 给出固定提交。外部路径只供溯源。旧提案、评论、历史流程和派生摘要均不能改变判据。

| 类别 | 生效文本 | 适用范围 |
| --- | --- | --- |
| 原件级静态验收 | [静态验收 v2](static-acceptance.v2.md) | 原件身份、内容、逻辑、证据和归档 |
| 逐件执行 | [执行 v2](reverse-execution-workflow.v2.md)、[详细规则 v2](reverse-execution-reference.v2.md) | 静态验收的操作与分支 |
| CLR 依赖与构建 | [CLR 闭包 v1](clr-closure.v1.md) | 依赖图和配对构建实验 |
| CLR 回环 | [回环 v1](roundtrip-equivalence.v1.md) | 同件重编后的结构与方法对照 |
| 原生及混合程序集覆盖 | [覆盖证据 v1](native-coverage-evidence.v1.md) | #337、#340 的逐地址与元数据补证 |
| 文本尾部修复预检 | [映射预检 v1](nag-preflight.v1.md) | #369 清单与 #370 路径、修订内容的全量对照 |

[快照来源](sources.json)记录 PR #365 的 5 份原文指纹。[v2 来源](sources.v2.json)记录主干上已变更的四份文本。[项目指令 v2](project-instructions.v2.md)和[阶段快照](reverse-work-status.v1.md)供溯源，[SOP](acceptance-sop.v1.md)供操作速查。历史快照内的相对链接沿用原布局，本索引给出生效入口。
