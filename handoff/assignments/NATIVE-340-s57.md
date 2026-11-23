# WrapSaveMergeNNFiles.dll 第五十七号续领

NATIVE-340，owner tietoumiao，assigned_seq=57，自 #13 ACK 起 24 小时。原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`，固定 [#450 @ 53bdbfa4](https://github.com/DenseFLoe/Aspen-for-mac/tree/53bdbfa4685c80e41ed90a0f08e3528608ea0265)。

按 [s53 复验步骤](../outbox/NATIVE-340/s53-verifier-notes.md) 核对每个 EH 数据节的头、整节的 raw RVA 范围及文件字节长度。运行独立回归，确认 full raw/virtual 夹具成功，raw、虚拟、物理文件截短及后继越界分别明确报错。更新旧混排断言，后继用例应只测试 MoreSects 后续边界并核对实际错误。更正分支说明的立即数／地址顺序和固定跳过措辞，在主表、附表分别断言原件和两项单变量注入的完整分支事实。

更正原件 25 节表的单子句宽度列，回读 35 条子句和类型。保留 9／10 节链、连续两次审计和两套交付摘要的固定 head 证明。沿用 [s49 卡](NATIVE-340-s49.md) 的覆盖 v1 与 PowerShell，回 [#13](https://github.com/DenseFLoe/Aspen-for-mac/issues/13) 贴新提交 SHA 和复跑结果。
