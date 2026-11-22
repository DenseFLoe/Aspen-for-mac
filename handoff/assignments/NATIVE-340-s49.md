# WrapSaveMergeNNFiles.dll 第四十九号续领

NATIVE-340，owner tietoumiao，assigned_seq=49，自 #13 ACK 起 24 小时。原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。固定输入 [#450 @ c1a0c085](https://github.com/DenseFLoe/Aspen-for-mac/tree/c1a0c0850352360315ab5842cbd00e3ce6f7b7f9)、[s45 裁定](../outbox/NATIVE-340/s45-decision.md)和 [s45 复验证据](../outbox/NATIVE-340/s45-verifier-notes.md)。

保留已复现的两项分支注入。使用解码事实生成主表和附表，重复运行不再追加相同口径；用成对测试检查 9／10 个 EH 节，读完整链或明确报错。整理真正受影响的附表，完成所有修改后生成两套指纹，从提交的固定 head 重跑及逐项对照，消除全部差异。验收命令沿用 [s41 卡](NATIVE-340-s41.md) 的覆盖 v1 与 PowerShell 命令；逐项检查 PowerShell JSON 的 `fingerprint_mismatches`，同时核对指纹路径集。按 [s45 卡](NATIVE-340-s45.md)的范围提交固定 head、命令输出和缺口。
