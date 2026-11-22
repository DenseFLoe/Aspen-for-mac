# ppexec.dll 第十三号续领

NATIVE-346，owner upstream，assigned_seq=13，本轮 #13 ACK 后 24 小时。沿用[固定原件](NATIVE-346-s9.md)，SHA-256 为 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。从第九号候选 `e1dbdeedbac8413bce795bcc7f3bdaabf7bd4791` 及[复验记录](../outbox/NATIVE-346/s9-decision.md)续接。此前 532 个已重组范围可直接复用。

按[新证据](../outbox/NATIVE-346/s13-input.md)在原件上核查 `0x121c0` 的回调目标、作用范围及最终类别，同步推进 `0x20a80` 的注册来源。把 15 个未决位置逐址补录进展和恢复条件。优先确认 `0x22148` 是否有可证写入者，以及从 `0x14c60` 分派时函数目标和加载器槽各由哪里提供。若只能证明分派路径，保留最终目标的待补条件。五个表的长度须从调用方证据补齐，数据导出保留原件已证实的类型和边界。

沿用[上游原生补证标准](../standards/native-coverage-upstream.v1.md)。从仓库根运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-346 --original <固定原件>`，交 s13 开工、提交回执、实际更新的逐址记录与同名说明。通过 #13 指向固定候选提交。
