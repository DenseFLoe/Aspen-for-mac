# ApwnIPShell.dll s21 交付

NATIVE-342，owner upstream，assigned_seq=21。提交 2026-11-22T22:05:18Z。原件版本 41.0.0.614，基线 `183ec4aeb38f5463a99aadc2fbdbbc3326ce243a`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 0x33a40–0x33ab2 的 32 条指令。五条 AMD64 REL32 回填后，114 字节与原件一致。三条 ADDR32NB 回填后 `.pdata` 的 12 字节一致，两条 ADDR32NB 回填后 `.xdata` 的 24 字节一致。异常记录中的回调指针从 0x36298 跳到导入槽 0x3a688，对应 VCRUNTIME140_1.dll!__CxxFrameHandler4。原件 C++ 异常处理数据位于 0x48e50，本轮核对其引用和原始前缀。

`0x33a71` 先跳过空条目，再以 RCX=0 调用 `[RAX+0x38]`。上下界槽位 0x527b0、0x527b8 可写，初值区间只有一个指针，候选初值链 `0x527b0→0x49310→0x40a90` 的 +0x38 处指向 0x12e0。每次非空调用后重读上界，运行期绑定仍待核。0x33a87 以原 RCX 调用已恢复的 0x33ac0。0x33a8c 检测原 EDX 位 0，0x33a90 在位清零时跳过释放。位设定时 0x33a9a 以原 RCX、EDX=0x48 调用 `0x35134→0x34f80→IAT 0x3a9e0`，绑定 mfc140.dll!#1487。返回 RAX 为原 RCX。

原件共 1,005 个入口，713 个有覆盖，292 个为缺口。7,433 条调用和数据引用仍有 636 条未决。整件静态验收未通过。

从仓库根运行 `python -B handoff/inbox/NATIVE-342/s21/check-release-shell.py ORIGINAL ZIG --evidence-dir OUTPUT`。环境为 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[覆盖检查](s21/coverage-check.txt) · [成果指纹](s21/manifest.sha256)，SHA-256 `002db247bb4ea39a30e860f6ba4bcd8279054a386e0986f2f9e4361bc2f52ab6`。
