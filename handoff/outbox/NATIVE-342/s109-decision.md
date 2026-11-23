# ApwnIPShell.dll s109 裁定

基线 `c30a97f2701d1b70a5cbf3fe67debf3e2ed2086b`，候选清单 `9718af7d926aced61290c615903a66b98645c8f38328f74d1cc7b5c5859dc38c`。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

范围 `[0x36d30,0x36d58)`、`[0x36d70,0x36db3)`、`[0x36dc0,0x36dfd)`。回编 168 字节、46 条指令、8 处 REL32、36 字节 .pdata 与 32 字节 .xdata 全部匹配。三个入口把传入的 RDX 保存在 RBP，并从帧槽装入 RCX、RDX、R8。0x36d30 从 +0x60、+0x78、+0x68 取参调用 0x1d570。0x36d70 依次从 +0x20、+0x30、+0x80 和 +0x80、+0x28、+0x98 取参调用 0x7020、0x1d5c0。0x36dc0 依次从 +0x78、+0x20、+0x70 和 +0x70、+0x28、+0x88 取参调用 0x7060、0x1d610。三者均清零 ECX、EDX，经 0x362c2 和 IAT 0x3a640 调用 VCRUNTIME140.dll!_CxxThrowException。后两个入口共用原件的 0x46ba8 展开布局。帧槽的源码类型待核。

1005 个入口中 739 个覆盖、266 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

覆盖 v1 返回 2，整件裁定 returned。[交付](../../inbox/NATIVE-342/s109-submission.md) · [成对复跑](../../inbox/NATIVE-342/s109/control.json.md) · [续领](../../assignments/NATIVE-342-s113.md)
