# ApwnIPShell.dll s17 交付

NATIVE-342，owner upstream，assigned_seq=17。原件版本 41.0.0.614，基线 `b04042ca387010579df70bbfccbf882460435824`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

共享退出清理体 0x33ac0–0x33b80 共 53 条指令，三个 AMD64 COFF REL32 回填后 192 字节全部一致。异常目录共八项，0x33ac0 建立栈帧，另外七段按原件的 CHAININFO 复用该帧。0x33b70 是使用已保存 R15、RBP 的错误路径，向 0x33b80 传递 0xc0000005 与 1。0x39809 和 0x33a87 分别以尾跳和直调进入清理体。

0x33b14 从当前链表节点的偏移 0 取回调，RCX 为节点的 +0x08 字段，+0x10 指向下一节点。0x33b4d 从外层对象 +0x40 取接收者，非空时从其表的 +0x10 调用。两处继续保留未决，分别需要实际节点注册来源和接收者赋值与具体表证据。0x33b22 的原件跳板到 mfc140.dll!#1487，0x33b54 以对象 +0x18 为参数调用 DeleteCriticalSection。

原件共 1,005 个入口，712 个有覆盖，293 个为缺口。7,433 条调用和数据引用仍有 636 条未决。整件静态验收未通过。

从仓库根运行 `python -B handoff/inbox/NATIVE-342/s17/check-teardown.py ORIGINAL ZIG --evidence-dir OUTPUT`。环境为 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26。[覆盖检查](s17/coverage-check.txt) · [成果指纹](s17/manifest.sha256)，SHA-256 `910d0938c06ec3fec4d930921bb3684da9a9cc26aead1a1ca05f11fbec3dcb59`。
