# ApwnIPShell.dll s73 裁定

基线 `39be673b1ba7376b9987ed501c9387b5860ed422`，候选清单 `8afb5044aeb60121b068a50756ff262d53e1bee33a5288af4403eb466a932c04`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x35b60,0x35c91)`，片段 SHA-256 `0285fdb7ca2cf80f7f3e90e73077a87cbc4fe350e4c47466e8855ac6abe290df`。

回编 305 字节、97 条解码指令、12 处 REL32、12 字节 .pdata、40 字节 .xdata 均匹配。reason 0 且附加计数不大于零时直接返回 0；reason 1/2 先过可选回调与 CRT 分派，失败即返回。入口回调失败的 reason 1 走 reason 0 回滚。reason 0/3 在 CRT 分派返回非零后再调回调，有回调时返回其结果，无回调时返回 1。三处间接调用的磁盘初值均走 0x42c48→0x369b8 与 0x3ac20→0x36ae0，两个槽均有 DIR64，调度体跳转 RAX；运行时替换后目标仍未决。范围 [0x35b95,0x35c7b) 的异常过滤器为 0x395fa，接续点 0x35c7b 将结果清零。

1005 个入口中 727 个覆盖、278 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-342/s73-submission.md) · [回编](../../inbox/NATIVE-342/s73/reassembly.json) · [成对复跑](../../inbox/NATIVE-342/s73/operand-control.json) · [续领](../../assignments/NATIVE-342-s77.md)
