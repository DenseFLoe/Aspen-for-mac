# NATIVE-340 s77 裁定

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 858a23f](https://github.com/DenseFLoe/Aspen-for-mac/tree/858a23f9070d0a99555b695082d4dc57a4c13258)。主干基线 6f39d81802e8d60331c0c6706f192ae7d45ac52a。

PEReader 从原件逐 token 核对 167 份完整 IL 指纹、237 条 VTableFixups 及四槽初始 token。0x19608/0x19618 的 0x0A 中 0x08 是 FROM_UNMANAGED_RETAIN_APPDOMAIN，交付误写 CALL_MOST_DERIVED。0x06000057 原生入口已核对 0x5580→0x558A→0x19618 与 0x5584→0x19610，其 arg0 仍无静态生产者证据。实际表流列宽和 MethodImpl 行号还有可复现差异。固定覆盖 v1 实测 1105／354／559／0，退出 2。

裁定 returned。覆盖命令、输入和实测见[复验记录](s77-verifier-notes.md)。交付复验证据 SHA-256 c087a9eddbac41cc80e637036721be33fe0ab391bdc5cda76cdb11bd16a29bb7。

[开工回执](../../inbox/NATIVE-340/s77-started.md) · [交付回执](../../inbox/NATIVE-340/s77-submission.md) · [续领卡](../../assignments/NATIVE-340-s81.md)
