# NATIVE-342 s21 裁定

原件 ApwnIPShell.dll SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。上游从主干 `183ec4aeb38f5463a99aadc2fbdbbc3326ce243a` 的固定原件与任务卡复跑，核对交付清单 SHA-256 `002db247bb4ea39a30e860f6ba4bcd8279054a386e0986f2f9e4361bc2f52ab6`。

[回编脚本](../../inbox/NATIVE-342/s21/check-release-shell.py)重跑退出 0。`0x33a40–0x33ab2` 的 114 字节、32 条指令和 5 条 REL32 一致。`.pdata` 12 字节和 `.xdata` 24 字节一致。异常处理回调转到 `VCRUNTIME140_1.dll!__CxxFrameHandler4`，语言数据引用为 0x48e50。

已核实 0x33a71 使用 RCX=0 调用描述符的 +0x38 槽，运行期绑定仍待核。0x33a87 以原 RCX 调用 0x33ac0。0x33a8c 测试原 EDX 的位 0，为 1 时由 0x33a9a 调用释放函数，参数为原 RCX 和长度 72。

局部回编证据通过。覆盖检查退出 2，1,005 个入口仍有 292 个缺口，7,433 条调用及数据引用中仍有 636 条未决。整件退回续补。[s25 续领卡](../../assignments/NATIVE-342-s25.md)
