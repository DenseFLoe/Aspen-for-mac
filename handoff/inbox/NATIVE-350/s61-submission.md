# NATIVE-350 s61 交付

upstream，assigned_seq=61，交付 UTC 2026-11-23T01:05:36Z，基线 `7281447e6a58328cb914f9d91dd0b9f16f0b0aad`。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x18620,0x18679)`，片段 SHA-256 `aa193870871de50eecab3943d321eb78b712e74c8633011bf2028630305274f2`。

89 字节、30 条指令、2 处 REL32、.pdata 12 字节和 .xdata 16 字节吻合。 0x1863f 调用 0x158d8，取加载器零填充的选项槽 0x22ca0。0x18647 对读出的选项置位 0，经 0x180de 和 IAT 0x19188 调用 __stdio_common_vsprintf。寄存器传选项、缓冲、容量和格式，栈传 locale 与 va_list。0x1866a 将负值统一为 -1。

255 个入口中 156 个有覆盖、99 个缺口，3,567 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s61/replay.py ORIGINAL ZIG`。工具为 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[清单](s61/manifest.sha256) SHA-256 `01bcdef6717c078efa197def458d720d7968f4241ddf24db832ba4738bc85ec8`。
