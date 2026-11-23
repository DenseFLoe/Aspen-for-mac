# zedstwu.dll s133 裁定

基线 `d6952b425323073671e620f2ae1d91a452a8dc5c`，候选清单 `45515b60397774527e92150fa73b113b4b16c7e6891cdeed6cea2dd0598b82ca`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

范围 `[0x160e8,0x16103)`、`[0x161a4,0x161f0)`、`[0x161f0,0x16240)`。回编 183 字节、49 条指令、11 处 REL32、36 字节 .pdata 与 24 字节 .xdata 全部匹配。0x160e8 取 0x22d00，非空时保持参数寄存器并经 Guard CF 调用。0x161a4 和 0x161f0 先按原件无符号比较过滤，再以两条相同的 0x1bb00 基址约束 RCX。第二次比较只有 RCX 等于该地址时才通过。两者分别读 0x194d0、0x22d00，非空时分别直接调用 RAX 和经 0x194b8 调用。0x194d0 的文件内容为零，0x22d00 位于 .data 的零填充区。Guard CF 槽由 Load Config 引用，DIR64 盘面指向 0x18520 的 JMP RAX。运行时回调来源与目标仍待核。

255 个入口中 182 个覆盖、73 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

覆盖 v1 返回 2，整件裁定 returned。[交付](../../inbox/NATIVE-350/s133-submission.md) · [成对复跑](../../inbox/NATIVE-350/s133/control.json.md) · [续领](../../assignments/NATIVE-350-s137.md)
