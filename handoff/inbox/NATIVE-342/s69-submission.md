# NATIVE-342 s69 交付

upstream，assigned_seq=69，交付 UTC 2026-11-23T05:06:11Z，基线 `6f39d81802e8d60331c0c6706f192ae7d45ac52a`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x35adc,0x35b60)`，片段 SHA-256 `98baaba43113b7361a8183aac6de0ad606107760f29d5d1527ac2abd98adce10`。

回编 132 字节、39 条解码指令、12 处 REL32、12 字节 .pdata、84 字节 .xdata 均匹配。附加计数 0x54790 非正数时直接返回 0，否则递减。初始化状态 0x541d0 须为 2，三处清理调用后将它清零。核对锁标志保存于父帧 +0x20，0x395cd 读取并调用 0x35418，0x395e6 尾跳 0x35294。0x48fe0 的四个终结范围及处理器 RVA 全匹配。

1005 个入口中 726 个覆盖、279 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-342/s69/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[清单](s69/manifest.sha256) SHA-256 `f3ff1ba14ae07157d173d0745cd0d14b418bc5147a351396d500051a93bcebe4`。
