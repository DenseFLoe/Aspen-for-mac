# NATIVE-340 s73 裁定

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 3b440bf](https://github.com/DenseFLoe/Aspen-for-mac/tree/3b440bf0a4bf207d479eccc148232062a7f1a6a0)。主干基线 581aa65bc65667e09760dda9e5b954290d9d7e2b。

两套交付指纹核对 78/116，最新审计连续两次退出 0。独立 PEReader 确认两方法 Flags 0x4013、ImplFlags 0、Assembly 与同一完整 IL SHA-256，11 个直接 IL 站涉及 8 个方法，35 个 EH 子句吻合。109 条 MemberRef 的父级为 105 TypeRef、4 TypeSpec，原件没有 MethodImpl 行。.NET VTableFixups 目录在 0x16600，四个初值分别绑定两方法，标记为 0x2／0xA 各一组。已确认两个短跳及四条间接入口，未取得 0x06000057 的 arg0 生产者。装载后的时机待 Windows 对照。覆盖 v1 退出 2，1105/354/559/0，13 托管与 15 原生未决。编码表宽度和真实绑定配对存在可复现缺口。

裁定 returned。覆盖命令、输入和实测见[复验记录](s73-verifier-notes.md)。交付复验证据 SHA-256 c836c0650dbfdad06b422d5aeef13171ddf85635b656cd88c086a3d0d0b6eb14。

[开工回执](../../inbox/NATIVE-340/s73-started.md) · [交付回执](../../inbox/NATIVE-340/s73-submission.md) · [续领卡](../../assignments/NATIVE-340-s77.md)
