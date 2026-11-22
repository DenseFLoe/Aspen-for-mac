# cutoff-data.c 的复验说明

本文件提供 RVA 0x22230 起八个 64 位阈值的初始映像和 0x1a970 的零结尾字符串。检查器从独立 COFF .data 和 .rdata 符号取值并与原件比较。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，版本 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 文件 SHA-256 `21bae92dfad59290c6ec3956245230e71a046f0efa3b9848c6f799d1ae59b89a`。

整件覆盖 152/255 个入口，尚余 103 个入口缺口和 26 条未决引用，静态验收未通过。 后续追踪见[本轮回执](../s45-submission.md)。
