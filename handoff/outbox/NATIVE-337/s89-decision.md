# NATIVE-337 s89 裁定

原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ 157af57](https://github.com/DenseFLoe/Aspen-for-mac/tree/157af573f9b13fc4744eac14f50c2e9ae373d921)。主干基线 0554621e9ac0d627fad1e399d8868da06d1482e6。

148 个文件按固定 Git blob 和 SHA-256 核验。0x1389 六个参数、0x1444 的后五个栈参数和 FF /4 接入 s65 均已复核。覆盖 v1 实测 307/307/684/0，退出 2，112 条未决。s37 仍关联错误调用行，VariantInit 契约和已验证的 ShowDialog 部署绑定尚未入交付。当前清单 126 项，唯一指纹不符项是其自身，实际 QA 9 pass、1 fail、3 不适用。

裁定 returned。覆盖命令、输入和实测见[复验记录](s89-verifier-notes.md)。交付复验证据 SHA-256 04e3dc0df97ccdb63085eec4457541d3c61abd3ecfb51db38e247191ac21d1a1。

[开工证据](../../outbox/NATIVE-337/s89-started-evidence.md) · [交付回执](../../inbox/NATIVE-337/s89-submission.md) · [续领卡](../../assignments/NATIVE-337-s93.md)
