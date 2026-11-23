# NATIVE-340 s89 续领

owner tietoumiao，assigned_seq=89，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ bde39b4](https://github.com/DenseFLoe/Aspen-for-mac/tree/bde39b4630809020fd972211e9b64010e13410d7)。主干基线 2cb8a177a47da004ddd4b305f8fe31107c2d2afc。

保留四槽标志、固定 AspenHelper 样本及 PEReader 对照。按真实 #~/#- 流头读取 HeapSizes，将列宽修复接入 cli_tables.read 的实际表流，重复执行三类阈值的配对。针对 IL 摘要表保留行身份并在构字典前查重复，核对缺失、额外和内容差异。交付完整可重跑依赖及 0x06000057 arg0 的恢复条件。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-340/s85-decision.md)
