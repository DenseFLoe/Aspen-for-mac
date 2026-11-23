# NATIVE-342 s81 交付

upstream，assigned_seq=81，交付 UTC 2026-11-23T07:12:51Z，基线 `1545d5c6a8082855c5d577c1017ea7d717e47fa8`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x36110,0x3614c)`，片段 SHA-256 `e36318e0d5411b79b2dc3b873af30708f04dab919c8c35fc17c898251a70e10a`。

回编 60 字节、17 条解码指令、3 处 REL32、12 字节 .pdata、12 字节 .xdata 均匹配。两条 LEA 均指向 0x445b0，严格无符号比较在边界相等时直接退出；循环按 8 字节推进，空值跳过，非空值通过 0x3ac20 分派。原件磁盘槽 DIR64 指向 0x36ae0 的 jmp rax；实际运行时目标保留未决。该段与前一段共享 0x44e68 展开记录。

1005 个入口中 729 个覆盖、276 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-342/s81/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[清单](s81/manifest.sha256) SHA-256 `0baec9e2fc8d3d046a1ab9e3fe90a90d7c239ea2523ecf13249ca254fcd267e7`。
