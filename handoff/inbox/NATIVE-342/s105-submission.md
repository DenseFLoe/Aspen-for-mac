# NATIVE-342 s105 交付

upstream，assigned_seq=105，2026-11-23T12:15:09Z，基线 `bf56228e572bc5656e4b526750a0f6f9ac95eda9`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

范围 `[0x36ae0,0x36ae2)`、`[0x36b00,0x36b06)`。回编 8 字节、2 条指令、1 处 REL32、24 字节 .pdata 与 8 字节 .xdata 全部匹配。0x36ae0 直接跳 RAX，0x36b00 尾跳经 0x3ac20。Load Config 指明该槽为 GuardCFDispatchFunctionPointer，原件 DIR64 与磁盘初值均指向 0x36ae0。两个入口分别具有零展开码的独立 UNWIND_INFO。实际加载后分派目标及调用者赋给 RAX 的值仍待核。

1005 个入口中 736 个覆盖、269 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

复跑 `python -B CANDIDATE/s105/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[清单](s105/manifest.sha256) SHA-256 `3670af5efe63f54dced9a1c5c2ed79ca6daae6fa1beaa1596aaebc569346b0cc`。
