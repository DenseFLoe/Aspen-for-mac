# NATIVE-340 s97 裁定

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 38b6814](https://github.com/DenseFLoe/Aspen-for-mac/tree/38b6814d15332a90258f2caa42169b6f52e5bad4)。主干基线 44c22e3daac712802e8a7e865a42c301f70b714b。

s97 修正了三类指定索引的宽度，八组实际表流全过，PEReader 工程已可按 net9.0 重跑，167 条摘要原表及三组异常对照正确。同次合并引入 ImplMap.MemberForwarded 两组解码回归。真实 0x2B7A 的 caller 被改错后，所交脚本仍报 19/19 通过，另有三条跳板错引、一条清单位移错误。正式覆盖 1105/354/578/0，exit 2，仍有 28 条未决。

裁定 returned。覆盖命令、输入和实测见[复验记录](s97-verifier-notes.md)。交付复验证据 SHA-256 5b5b61b2a864d4b34ea080c6f068e802b4867530a40dac53d41411216bd79602。

[开工证据](../../inbox/NATIVE-340/s97-started.md) · [交付回执](../../inbox/NATIVE-340/s97-submission.md) · [续领卡](../../assignments/NATIVE-340-s101.md)
