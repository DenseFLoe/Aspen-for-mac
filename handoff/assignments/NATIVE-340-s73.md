# NATIVE-340 s73 续领

owner tietoumiao，assigned_seq=73，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll 的 SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`，从 [#450 @ 5ca17f4](https://github.com/DenseFLoe/Aspen-for-mac/tree/5ca17f4987251f32be4772955c8b9be3185b9c62) 续办。[上轮独立裁定](../outbox/NATIVE-340/s69-decision.md)

1. 从原件 MethodDef 表读取 0x06000056 和 0x06000057 的 Flags 与 ImplFlags，修正访问表、主表和报告。原件两条 Flags 均为 0x4013（Assembly、Static、HasSecurity），ImplFlags 为 0。写出完整 64 位十六进制字符的 IL SHA-256。修正 0x0600001F IL_0087 的文字说明，ldloca.s 0x4 取局部 4 的地址。
2. 按 CLI 元数据表定义将 MemberRefParent、MethodDefOrRef 解码成表及行号，独立检查 MethodImpl 的声明和实现列。用不同可见性的 MethodDef，以及存在和缺少有效 MemberRef、MethodImpl 绑定的样本配对，记录预期、实测和输入指纹。
3. 按原件追查 0x06000057 的 RVA 0x5584、0x558A 到修补槽 0x19610、0x19618 的来路，对照 0x06000056 的两条入口。记录可证实的入口、调用者及 arg0 来源；动态或缺少输入的生产者留作未决，写明查找范围及恢复条件。行为测试留到 Windows 阶段。
4. 复核 8 个方法的 11 个调用站、主表的指针目标、35 个 EH 子句；复跑删一站并重算指纹的对照。刷新两套交付指纹，记录实际覆盖 v1 退出码及未决数，在 #13 报告固定 head。[覆盖证据 v1](../standards/native-coverage-evidence.v1.md) · [独立复现命令及工具反馈](../outbox/NATIVE-340/s69-verifier-notes.md)
