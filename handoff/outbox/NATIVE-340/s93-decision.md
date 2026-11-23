# NATIVE-340 s93 裁定

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 22135b6](https://github.com/DenseFLoe/Aspen-for-mac/tree/22135b6596af10a318fc80483b9c20d3680115bb)。主干基线 263497c50f7a59ea343f2cf80ba41a168dce7af1。

226 个固定文件和交付两套 102/150 项指纹一致。对 167 个 IL 摘要的只读复验已通过，单改、漏行、重复均逐 token 拒绝。真实表流的 8 个阈值用例有 4 个错列。新增的 19 个 IAT 站点均可在原件确认字节、槽位和符号，但全部落在所填 caller 的已知范围之外，其中 3 条 note 指向相邻的另一条指令，1 条 RIP 位移文本错误。覆盖 v1 报 1105/354/578/0，exit 2。`_t14/pereader` 在固定提交返回 404；外部指针 arg0 的静态恢复条件仍未满足。

裁定 returned。覆盖命令、输入和实测见[复验记录](s93-verifier-notes.md)。交付复验证据 SHA-256 516adc57aac4c3cb435570e4f506552a66585e2a0e0f5e46c69ea975a3d0e99a。

[开工证据](../../inbox/NATIVE-340/s93-started.md) · [交付回执](../../inbox/NATIVE-340/s93-submission.md) · [续领卡](../../assignments/NATIVE-340-s97.md)
