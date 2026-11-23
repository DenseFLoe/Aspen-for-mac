# NATIVE-350 s85 交付

upstream，assigned_seq=85，交付 UTC 2026-11-23T04:36:59Z，基线 `35b4cb8123a98da798af8d83d42dee674bca8906`。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`，范围 `[0x15c74,0x15c98)`，片段 SHA-256 `601c3b9783b84859e5612bf54a500539f69f2005c8e71d70ba2fdb20992f42cc`。

36 字节、13 条指令、2 处代码 REL32、12 字节 .pdata 和 8 字节 .xdata 与原件吻合。0x15c7a 把入参 CL 保存在 BL；0x15c7c 的被调函数 0x1654c 只读 0x22270 的 DWORD，将是否非零编码为 EAX 0/1。0x15c85 按 EAX 跳转，0x15c89 按 BL 跳转。EAX 非零且 BL 为零时，0x15c8b 用内存 XCHG 将 0x22cb8 原子置零。该 8 字节槽位于 .data 的加载器零填充区，0x159cb 用 LOCK CMPXCHG 竞争写入。可执行原始区间的 RIP 相对操作数扫描复核了这两个已确认的指令边界。间接别名或运行时写入仍需相应证据。

255 个入口中 163 个有覆盖、92 个缺口，3,572 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s85/replay.py ORIGINAL ZIG`。工具为 Zig 0.13.0、Capstone 5.0.6、iced-x86 1.21.0、pefile 2024.8.26。[清单](s85/manifest.sha256) SHA-256 `3acc7ab03e053cc2bc17bb3bd997393b3ae5d76c90b64a015414fff2f290738b`。
