# ppexec.dll 第九号续领

NATIVE-346，upstream，assigned_seq=9，时限自本轮 #13 ACK 起 24 小时。固定输入为 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/346/ppexec.dll`，SHA-256 为 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。[原始来源与产品路径](NATIVE-346.md) · [第五轮候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/fa54788674fb9deebde754613d9e30ae3c306463/handoff/inbox/NATIVE-346) · [第五轮裁定](../outbox/NATIVE-346/s5-decision.md)

新证据已从原版三段初始化代码中核出 30 个八字节写入，分别写入十个导出标签 PPEXEC_WNC1 至 PPEXEC_WNC10。每条路径的写入值可由原始两个寄存器及序号计算。先执行 `python handoff/outbox/NATIVE-346/check-wnc-stores.py <固定原件>`，与[全部指令位置与系数](../outbox/NATIVE-346/s9-wnc-stores.json)对照。从这些导出及其实际读写者核验全局数据的类型、用途和长度。按已确定的证据区分可确认的八字节字段、导出符号间距与仍缺外部声明的部分。

依第五轮逐址表核对 20 处索引的上下界和 14 处回调或间接转移，说明每个剩余位置的原件依据和恢复条件。保留已回编的 532 段及版本资源。按[适用标准](../standards/native-coverage-upstream.v1.md)运行 `python handoff/assignments/check-native-coverage.py NATIVE-346`，在本件 inbox 提交 `s9-started.md`、`s9-submission.md`、源码及证据，通过 #13 指向完整候选 head。
