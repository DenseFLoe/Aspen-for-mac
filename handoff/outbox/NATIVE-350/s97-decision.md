# zedstwu.dll s97 裁定

基线 `2cb8a177a47da004ddd4b305f8fe31107c2d2afc`，候选清单 `0377bf6611077effbaa1f06ebd0c2a6481be916cb74a7da0448e0eb86d70ae45`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15d20,0x15d37)`，片段 SHA-256 `466a3aba93bfca3396f9f06a0f569bb63706ec4dd0de519a65abb600b8700147`。

回编 23 字节、8 条解码指令、1 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。0x15d24 用原 RCX 调用已回编的 0x15cc4。NEG RAX 的进位区分空指针与非空，SBB/NEG/DEC 将非空映射为 0，将空映射为 -1。0x28 栈空间和共享展开记录均已核。

255 个入口中 166 个覆盖、89 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-350/s97-submission.md) · [回编](../../inbox/NATIVE-350/s97/reassembly.json) · [成对复跑](../../inbox/NATIVE-350/s97/operand-control.json) · [续领](../../assignments/NATIVE-350-s101.md)
