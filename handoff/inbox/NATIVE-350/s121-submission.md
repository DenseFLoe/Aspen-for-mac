# NATIVE-350 s121 交付

upstream，assigned_seq=121，2026-11-23T11:36:21Z，基线 `00af157e13df3eb7f7f0aabadf333589fce7a347`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15fd8,0x16014)`，片段 SHA-256 `094a457256f9a9eeae0d6eb948a0ff7c2216b3d9828deea475aac9d6a440ef1f`。

回编 60 字节、17 条指令、3 处 REL32、12 字节 .pdata 和 12 字节 .xdata 全部匹配。0x15fe2 与 0x15fe9 均取 0x1bf88，严格无符号小于的循环初次判断即退出。若通用区间非空，按 8 字节步长跳过空槽，将回调值放入 RAX 后经 0x194b8 调度。Load Config 标记该槽为 GuardCFDispatchFunctionPointer，磁盘 DIR64 初值指向 0x18520 的 JMP RAX。对应运行时回调目标仍待核。

255 个入口中 172 个覆盖、83 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B CANDIDATE/s121/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[清单](s121/manifest.sha256) SHA-256 `5696cf0c050f487c30ea2e72b341fd54ae5ae1aa86780887ea46a2a47c2eec34`。
