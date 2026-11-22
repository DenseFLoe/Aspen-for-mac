# NAG-GENERATOR-373-FIX · 修正两处 ILSpy 输出及扫描门禁

owner 为 tietoumiao，assigned_seq=1，时限为本轮 #13 ACK 起 24 小时。输入为 [#373](https://github.com/DenseFLoe/Aspen-for-mac/pull/373) 原代码提交 `8f5034f02722916e442881a6bd112baef419d1a7` 和[上游 Windows 复验](../inbox/NAG-GENERATOR-373/review.md)。两个写入入口和扫描器的原始 SHA-256 依次为：

| 文件 | 原版 SHA-256 |
| --- | --- |
| tool/b2_wave.py | 627fc3becb7cd89f2bf90027b68047f28fa5f20e06514c0a1f274b3fbb4956b3 |
| tool/batch_reverse.py | 2a33353dbb07e24f15b2a4f30c8d69883ef29688f849ad327d723f1102c6534e |
| tool/check_cs_clean.py | f6989df348c2d3052337f9483b40489dd7512eb20afeb98a83b15eb15c291b85 |

按 [generator-revision.v1](../standards/generator-revision.v1.md) 修正生成端和门禁。范围为新生成文件及其扫描。存量 455 份单文件交付另案处理。允许在原 PR 更新代码，或提交另一个明确取代原 head 的产物 PR。若引入共享助手，将其路径和指纹一并提交。

在 `handoff/inbox/NAG-GENERATOR-373-FIX/` 写 `s1-started.md`。先固定实际被测试的代码提交，再给出 fixtures.json、results.json、run.log、review.md 及 s1-submission.md。回执列代码提交、PR、三份新源指纹、原始 stdout 来源及两个真实写入口调用位置。#13 报任务号、assigned_seq、代码 PR/head 和交付 PR/head。允许独立的证据提交，最终代码树中的受验字节须可由上游复核。

在受信判定器版本所在普通目录放入该件 inbox，运行 `python handoff/assignments/check-generator-revision.py`。给定输入为固定十组、两个生产写入口、两次实际写入、写前写后门禁。核对新代码提交中至少三个源文件的实际字节。上游收到后，另用 `--expected-head` 指定从连接器刚回读的代码 PR head，复跑并审阅变更。原始输入、真实写入结果或代码无法取得时，回报最小缺口、固定身份及恢复条件。
