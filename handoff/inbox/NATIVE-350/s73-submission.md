# NATIVE-350 s73 交付

upstream，assigned_seq=73，交付 UTC 2026-11-23T02:34:37Z，基线 `88690cceb657353eab88f4e84e73dba90a31acba`。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x186a9,0x186f3)`，片段 SHA-256 `aa7c30e248012be77ecefdc2b6d6a0935f7bd5b1e442a705eec07623bde18aab`。

两个相邻例程的 74 字节均吻合，各末尾一字节 INT3，共 22 条可达指令。两处直接转移及一处 RIP 引用的 REL32 均已核对，两条 .pdata 共 24 字节，两条 .xdata 共 16 字节。0x186b7 恢复栈和 RBP 后尾跳 0x15b00。0x186e6 调用 0x15a70，前四参来自帧字段 0x60/0x68/0x70 和原件内部回调 0x1540c，后两参来自入口 RCX 间接指向的四字节及该入口 RCX 指针。目标在恢复栈前读取两项栈参数，随后经 0x18096 转至 CRT 的 _seh_filter_dll 导入。

255 个入口中 160 个有覆盖、95 个缺口，3,567 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s73/replay.py ORIGINAL ZIG`。工具为 Zig 0.13.0、capstone 5.0.6, pefile 2024.8.26, iced-x86 1.21.0。覆盖 v1 返回 2。成对用例的局部回编返回 0 → 1。[清单](s73/manifest.sha256) SHA-256 `7649817b281a06d24c32f23e2555dfc9cc699c973d75ff1d7ba0d6f3517bdb57`。
