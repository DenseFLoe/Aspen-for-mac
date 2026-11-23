# ApwnIPShell.dll s61 裁定

基线 `581aa65bc65667e09760dda9e5b954290d9d7e2b`，候选清单 SHA-256 `c88289a572c51c6b8e068c4a10e358ee6c352474f8bc1c943bb7f9e4c1fd4d62`。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x352f4,0x35418)`，片段 SHA-256 `4a6776f7c5a98e67967fae31a7dc3b68f427afebe72913f0f191aa4022a7f443`。

两段共 291 字节和 84 条解码指令，另有 0x3537f 的对齐 INT3。两段的 16 处 REL32、24 字节 .pdata 和 40 字节 .xdata 均逐字节吻合。 0x352f4 按 0x541e1 的初始化标志短路；未初始化时模式大于 1 走失败辅助例程。当 UCRT 在用且模式为 0 时，经 0x36310→0x3a770 分别初始化 0x541e8、0x54200 的退出表。另一分支按原件将各表的三个 64 位字段填为 -1。0x35380 验证 DOS、NT 和 PE32+ 头，按 VirtualAddress 与 VirtualSize 查找节，由 Characteristics 的最高位判断可写性。0x48f28 的范围记录绑定 0x362e0→0x3a630 的 __C_specific_handler、0x3959e 过滤器和 0x35411 恢复分支。

1,005 个入口中 724 个有覆盖、281 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-342/s61-submission.md) · [复验](../../inbox/NATIVE-342/s61/reassembly.json) · [成对用例](../../inbox/NATIVE-342/s61/operand-control.json) · [续领卡](../../assignments/NATIVE-342-s65.md)
