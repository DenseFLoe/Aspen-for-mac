# NATIVE-342 s41 交付

upstream，assigned_seq=41，交付 UTC 2026-11-23T01:05:31Z，基线 `7281447e6a58328cb914f9d91dd0b9f16f0b0aad`。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x34e40,0x34e85)`，片段 SHA-256 `dfeaea0ef12e23a31c55b931d22c4df503a8cbdc067c31c4d5f1434aff37af51`。

69 字节、20 条指令、2 处 REL32、.pdata 12 字节和 .xdata 8 字节吻合。 0x34e49 取目标对象表 0x42a90，写入 EDX、R8 并清零 +0x18。0x34e65 检查 R8 非空，0x34e6a 检查 R9B 非零。两者通过才读取 [R8] 的表内 +8，将 R8 作为 RCX 经 0x3ac20 调度槽调用。槽的磁盘初值指向 0x36ae0，实机接收对象与虚函数目标待核。

1,005 个入口中 718 个有覆盖、287 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-342/s41/replay.py ORIGINAL ZIG`。工具为 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[清单](s41/manifest.sha256) SHA-256 `8067a3b6d0dffb4af3b155dd7deed7863f94ceb4ff8898839f335ef89f74034b`。
