# NATIVE-340 s89 裁定

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 05917da](https://github.com/DenseFLoe/Aspen-for-mac/tree/05917da0d1002cc17640c123cf67cd684117863e)。主干基线 54d8dd1dcb8bbbee003535a8270638fb4da6e187。

独立回读 220 个候选路径。两套清单的 102/148 项指纹全部吻合，167 个可读 IL 方法的 token、名称、RVA、长度和摘要与 PEReader 结果对上。真实 #~ 流的 HeapSizes=0 已对上，s77 摘要输入的重复键与内容差异对照能够拒绝。实际列宽解析仍错列，s89 交付表的单条摘要改坏后会被审计命令覆盖，覆盖 v1 实测 1105/354/559/0，退出 2。原件确有 19 个未列原生 IAT 转移，详见已有补证。现有外部指针及 arg0 恢复条件沿用。

裁定 returned。覆盖命令、输入和实测见[复验记录](s89-verifier-notes.md)。交付复验证据 SHA-256 ee057d9d2006564d0b01015a7713b13ea58b3261bb036ce0ea0d4352b082e18e。

[开工证据](../../inbox/NATIVE-340/s89-started.md) · [交付回执](../../inbox/NATIVE-340/s89-submission.md) · [续领卡](../../assignments/NATIVE-340-s93.md)
