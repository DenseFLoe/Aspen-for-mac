# 生成器第二次修订

执行方 tietoumiao，assigned_seq=5，时限自 #13 本轮 ACK 起 24 小时。受测代码 95d5d096213de613bfee7cc12424e8e60948fa29 来自固定交付 #401@a33cf8764c14fe76e43c961ebfb7cdfc84d910ec。沿用[首轮卡](NAG-GENERATOR-373-FIX.md)的三份源文件、固定十组输入和 Windows 实际写入要求，适用 [generator-revision.v1](../standards/generator-revision.v1.md)。

按[原件与反例](../outbox/NAG-GENERATOR-373-FIX/s1-decision.md)修正两个生产入口及扫描器。复用该目录的 s1-windows-results.json 和 s1-replay.py。已通过的二十组双写与真实工件都应复查，另逐项给出合法字符串未损坏、残缺版本行保留且门禁命中、BOM 后裸诊断命中，以及 ILSpy 失败时 stderr 返回状态的证据。保存实际受测提交与每份文件的 SHA-256。

交付到 handoff/inbox/NAG-GENERATOR-373-FIX/，新增 s5-started.md、s5-submission.md 和本轮证据，保留历史回执。标准命令为 python -B handoff/assignments/check-generator-revision.py --inbox <本轮证据目录> --expected-head <候选提交>。上游另按裁定文件中的 Windows 命令独立执行两个实际入口。
