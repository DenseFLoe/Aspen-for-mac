# NATIVE-342 s65 交付

upstream，assigned_seq=65，交付 UTC 2026-11-23T04:34:40Z，基线 `35b4cb8123a98da798af8d83d42dee674bca8906`。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x359c4,0x35ada)`，片段 SHA-256 `b800253ad5cbaf49cc76bae0c845822204ad369d8d006ab2e2f10f386153102a`。

回编的 278 字节、22 处 REL32、12 字节 .pdata 和 60 字节 .xdata 均与原版一致。 0x359fc 要求状态槽 0x541d0 为 0，其他值走 0x35ace。0x35a09 写入 1，0x35a39 调用 _initterm_e(0x3acc0,0x3acc8)，其失败路径释放启动锁并返回 0。0x35a59 调用 _initterm(0x3ac48,0x3acb8)，0x35a5e 写入 2。展开记录将两段终结范围绑定到 0x395b6，从父帧 +0x40 读取锁标志并转入 0x35418。0x35aa6 的 R9 来源是 CFG 调度槽 0x3ac20，磁盘初值 0x36ae0 再跳转 RAX。RAX 来自 0x54870；该槽初值为零，原件节属性为可写，不能据此给出动态回调目标。成功后递增 0x54790 并返回 1。

1,005 个入口中 725 个有覆盖、280 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-342/s65/replay.py ORIGINAL ZIG`。工具为 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[清单](s65/manifest.sha256) SHA-256 `3906cbe371284e95c93621b1dd83dc8efa8a94cc69020a52b53399660c818299`。
