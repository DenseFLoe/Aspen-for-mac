# ApwnIPShell.dll s85 裁定

基线 `263497c50f7a59ea343f2cf80ba41a168dce7af1`，候选清单 `fde08bd80f0e0a94e952bb8785fdbeafa6087c0bd7b3c9914462678a03fbf125`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x3633c,0x363e6)`，片段 SHA-256 `f88b5d0135afbb312cfb4a14adb121169f8dfda75fa95cdeb3ff57c48f07c09f`。

回编 170 字节、38 条解码指令、16 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。原件先测试 0x42ce0 的 0x1000 位。置位时根据 0x363e8 的 AL 选择调度槽调用或 PAUSE/CMPXCHG 锁路径，随后递增 0x54858，结果为 1 时以类别 4 和 0x5485c 调用 0x365bc。再次调用 0x363e8 后，在恢复栈帧后经调度槽跳转或将 0x54850 清零。0x3ac20 的磁盘 DIR64 初值为 0x36ae0，沿用两处运行时接收目标待核。

1005 个入口中 730 个覆盖、275 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-342/s85-submission.md) · [回编](../../inbox/NATIVE-342/s85/reassembly.json) · [成对复跑](../../inbox/NATIVE-342/s85/operand-control.json) · [续领](../../assignments/NATIVE-342-s89.md)
