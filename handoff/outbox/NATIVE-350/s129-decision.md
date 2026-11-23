# zedstwu.dll s129 裁定

基线 `c30a97f2701d1b70a5cbf3fe67debf3e2ed2086b`，候选清单 `47a350d2d9537bf22687e0d2026a41be9511d99b37fd604de127ea7247dc6d9a`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

范围 `[0x16098,0x160af)`、`[0x160b0,0x160e7)`。回编 78 字节、21 条指令、5 处 REL32、24 字节 .pdata 与 16 字节 .xdata 全部匹配。0x16098 读取 0x194d0，当指针非零时保持传入的参数寄存器并调用 RAX。0x160b0 两界同为 0x1bb00，仅当 RCX 等于该地址才读取 0x22d00。槽非零时，以原 RCX、零 RDX 和基址 R8 经 Guard CF 槽 0x194b8 调用。该槽的 Load Config 及磁盘 DIR64 均已定位，磁盘初值指向 0x18520 的 JMP RAX。0x194d0 和 0x22d00 的磁盘初值均为零，无基址重定位且不在 IAT。运行时提供者和目标仍待核。

255 个入口中 179 个覆盖、76 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

覆盖 v1 返回 2，整件裁定 returned。[交付](../../inbox/NATIVE-350/s129-submission.md) · [成对复跑](../../inbox/NATIVE-350/s129/control.json.md) · [续领](../../assignments/NATIVE-350-s133.md)
