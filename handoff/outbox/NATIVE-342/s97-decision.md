# ApwnIPShell.dll s97 裁定

基线 `c8ec21865e2a9afc48873757ec1da993ceaf2f26`，候选清单 `46fb9c65847182929e63d6e2f4af2aba266a33c7dd35cb7703aeefa06909855c`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x369b8,0x36a15)`，片段 SHA-256 `a734bfdc8815088d4621896161f2496e4eb73b6f3e08e987dfbf29ee61e67d32`。

回编 93 字节、25 条解码指令、5 处 REL32、12 字节 .pdata、16 字节 .xdata 均匹配。0x54868 位于可写 .data 的加载器零填充区。槽为空时返回 1。槽非空时将槽的地址交给 0x36a18，返回 0 时跳过分派，否则重新取槽值到 RAX，恢复 RCX、EDX、R8 并经 0x3ac20 间接调用。该分派槽的原件 DIR64 初值指向 0x36ae0（JMP RAX）。动态回调值和实际分派目标仍待核。同模块直接调用 0x369e0→0x36a18 单列于回编报告，外部调用、重要数据与待决引用的表内计数不变。

1005 个入口中 733 个覆盖、272 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

覆盖 v1 返回 2，整件裁定 returned。 [回执](../../inbox/NATIVE-342/s97-submission.md) · [回编](../../inbox/NATIVE-342/s97/reassembly.json) · [成对复跑](../../inbox/NATIVE-342/s97/operand-control.json.md) · [续领](../../assignments/NATIVE-342-s101.md)
