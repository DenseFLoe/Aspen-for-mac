# NATIVE-350 s97 交付

upstream，assigned_seq=97，交付 UTC 2026-11-23T06:31:39Z，基线 `2cb8a177a47da004ddd4b305f8fe31107c2d2afc`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15d20,0x15d37)`，片段 SHA-256 `466a3aba93bfca3396f9f06a0f569bb63706ec4dd0de519a65abb600b8700147`。

回编 23 字节、8 条解码指令、1 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。0x15d24 用原 RCX 调用已回编的 0x15cc4。NEG RAX 的进位区分空指针与非空，SBB/NEG/DEC 将非空映射为 0，将空映射为 -1。0x28 栈空间和共享展开记录均已核。

255 个入口中 166 个覆盖、89 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s97/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[清单](s97/manifest.sha256) SHA-256 `0377bf6611077effbaa1f06ebd0c2a6481be916cb74a7da0448e0eb86d70ae45`。
