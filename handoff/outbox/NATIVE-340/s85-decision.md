# NATIVE-340 s85 裁定

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ bde39b4](https://github.com/DenseFLoe/Aspen-for-mac/tree/bde39b4630809020fd972211e9b64010e13410d7)。主干基线 2cb8a177a47da004ddd4b305f8fe31107c2d2afc。

209 条候选路径及 96/140 条声明指纹已核。四槽位名修正、真实 MethodImpl 的 Body RID 4 和 Declaration RID 15 均与 PEReader 匹配，167 个 IL 摘要对照吻合。覆盖 v1 是 1105/354/559/0，退出 2，13 项托管与 15 项原生仍待核。生产表流宽度、审计 HeapSizes 位置和双向 IL 摘要差异仍有缺口。

裁定 returned。覆盖命令、输入和实测见[复验记录](s85-verifier-notes.md)。交付复验证据 SHA-256 1299d711b906a72682b1649d8078fa9c369b2ab24b7defde80139d6d314b2733。

[开工证据](../../inbox/NATIVE-340/s85-started.md) · [交付回执](../../inbox/NATIVE-340/s85-submission.md) · [续领卡](../../assignments/NATIVE-340-s89.md)
