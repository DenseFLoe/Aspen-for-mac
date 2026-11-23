# NATIVE-342 s101 交付

upstream，assigned_seq=101，2026-11-23T11:36:16Z，基线 `00af157e13df3eb7f7f0aabadf333589fce7a347`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x36a18,0x36ac8)`，片段 SHA-256 `10f027a5d2a931866854b85dee9e83f9fa8488615fc60cd3c6ee3a8e757ff201`。

回编 176 字节、53 条指令、4 处 REL32、12 字节 .pdata 和 32 字节 .xdata 全部匹配。原件按 MZ、PE 签名、PE32+ 魔数及 e_lfanew 解析当前映像，按节表的 RVA 和 VirtualSize 做半开区间判断。仅落在节内且 Characteristics 位 31 为零时返回 1。SEH 保护范围 [0x36a1f,0x36ac1)，筛选函数 0x3959e 仅匹配 0xC0000005，再转入 0x36ac1 返回 0。0x362e0 经 IAT 0x3a630 绑定 VCRUNTIME140.dll!__C_specific_handler。

1005 个入口中 734 个覆盖、271 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

复跑 `python -B CANDIDATE/s101/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[清单](s101/manifest.sha256) SHA-256 `b09bce54706acd6c9259a7391bbc8c4ae115f23f6353ca80bc8faedc264b698d`。
