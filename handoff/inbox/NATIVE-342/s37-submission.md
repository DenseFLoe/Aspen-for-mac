# ApwnIPShell.dll s37 交付

NATIVE-342，owner upstream，assigned_seq=37。提交 2026-11-23T00:34:50Z。固定基线 d29e63566fa3969bc38837b38fddcb1f9ff5c044，原件 SHA-256 ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b。

0x34df0–0x34e34 的 19 条指令、68 字节和两处 REL32 重定位逐字节复验一致。.pdata 12 字节和 .xdata 8 字节回编一致，含 RBX 保存与 0x20 字节栈分配。

0x34df9 将 0x42a90 写入目标对象头，其首项 DIR64 指向 0x34ee0。源对象 +0x08 的 4 字节和 +0x10 的 8 字节复制到目标，目标 +0x18 的 8 字节清零。源 +0x10 为空则在 0x34e1c 跳至返回；否则 0x34e21 从该对象虚表的 +0x08 读取 RAX。0x34e25 通过装载配置 GuardCFDispatchFunctionPointer 指明的 0x3ac20 槽调用。磁盘中槽的 DIR64 指向 0x36ae0 的 jmp rax，虚调用目标仍需接收对象运行证据。

1,005 个入口中 717 个有覆盖、288 个缺口。7,433 条调用和数据引用中有 636 条未决。整件静态验收未通过。

复跑 python -B handoff/inbox/NATIVE-342/s37/check-com-error-copy.py ORIGINAL ZIG。使用 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[成果指纹](s37/manifest.sha256) SHA-256 b2f8083fd0df621b23d533eb201d86b796436db63743e8245993e07bf20e023d。
