# NATIVE-342 s89 交付

upstream，assigned_seq=89，交付 UTC 2026-11-23T09:04:10Z，基线 `44c22e3daac712802e8a7e865a42c301f70b714b`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x3664c,0x366df)`，片段 SHA-256 `86e2bd47334735f5ba5edb3f83e44a8de321ce45b480a48a36b370b30fff1246`。

回编 147 字节、32 条解码指令、15 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。原件以 0x42ce0 的 0x1000 位决定是否进入。0x363e8 的 AL 选择 RAX 加载及经 0x3ac20 调用，或 PAUSE/CMPXCHG 锁路径。0x36697 将 0x54858 减一，仅结果为零时将 0x5485c 的值与栈参数地址传给 0x365bc。再次判定后经 0x3ac20 调用释放路径，或直接清零 0x54850。0x3ac20 的磁盘 DIR64 初值指向 0x36ae0，0x36673 与 0x366c7 的运行时接收者继续记为未决。

1005 个入口中 731 个覆盖、274 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-342/s89/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[清单](s89/manifest.sha256) SHA-256 `2e3255e269918da67ba2884a7c1382bfe5d694f8c49446824d9fb1fb1f49aa6d`。
