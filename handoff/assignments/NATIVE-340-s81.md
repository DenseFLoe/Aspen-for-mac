# NATIVE-340 s81 续领

owner tietoumiao，assigned_seq=81，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 858a23f](https://github.com/DenseFLoe/Aspen-for-mac/tree/858a23f9070d0a99555b695082d4dc57a4c13258)。主干基线 6f39d81802e8d60331c0c6706f192ae7d45ac52a。

更正 0x08 与 0x10 标志名，保持四槽原值和 token。用真实含 MethodImpl 的显式接口样本核对 Body 和 Declaration 的一基 RID，从 ECMA 编码定义修正实际表流列宽。预检读取 s77 指纹表并逐 token 从原件重算。保留 11 站、35 EH 与对 arg0 的恢复条件。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-340/s77-decision.md)
