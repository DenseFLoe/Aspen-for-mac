# NATIVE-350 s65 交付

upstream，assigned_seq=65，交付 UTC 2026-11-23T01:35:13Z，基线 `7ce64a251d9c5210041903988c016a53b3f85287`。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x18679,0x18690)`，片段 SHA-256 `0bdaee68814590d466bcb16d251d70b6da23ac40874a079c557d4f7bc9d84f47`。

23 字节与原件吻合，含 7 条可达指令、1 字节 INT3 填充和 1 处 REL32。异常表记录 12 字节，展开信息 8 字节，均吻合。0x18682 从 RDX 指向的帧基址偏移 0x40 读取 1 字节到 CL。恢复栈和 RBP 后，0x1868a 尾跳转至 0x15c74。目标保存并检查 CL。0x1868f 为填充。0x1c0c4 的展开信息记录 32 字节栈分配与 RBP 保存。

255 个入口中 157 个有覆盖、98 个缺口，3,567 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s65/replay.py ORIGINAL ZIG`。工具为 Zig 0.13.0、capstone 5.0.6, pefile 2024.8.26, iced-x86 1.21.0。覆盖 v1 返回 2。成对用例的局部回编返回 0 → 1。[清单](s65/manifest.sha256) SHA-256 `cc9e08bf5c83a349be975d5565c00726f20c54900c84f71491fa2a2c8fa7fd27`。
