# ApwnIPShell.dll s69 裁定

基线 `6f39d81802e8d60331c0c6706f192ae7d45ac52a`，候选清单 `f3ff1ba14ae07157d173d0745cd0d14b418bc5147a351396d500051a93bcebe4`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x35adc,0x35b60)`，片段 SHA-256 `98baaba43113b7361a8183aac6de0ad606107760f29d5d1527ac2abd98adce10`。

回编 132 字节、39 条解码指令、12 处 REL32、12 字节 .pdata、84 字节 .xdata 均匹配。附加计数 0x54790 非正数时直接返回 0，否则递减。初始化状态 0x541d0 须为 2，三处清理调用后将它清零。核对锁标志保存于父帧 +0x20，0x395cd 读取并调用 0x35418，0x395e6 尾跳 0x35294。0x48fe0 的四个终结范围及处理器 RVA 全匹配。

1005 个入口中 726 个覆盖、279 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-342/s69-submission.md) · [回编](../../inbox/NATIVE-342/s69/reassembly.json) · [成对复跑](../../inbox/NATIVE-342/s69/operand-control.json) · [续领](../../assignments/NATIVE-342-s73.md)
