# com-error-deleting-destructor.c

可编辑 Windows AMD64 源文件，采用带符号引用的内联汇编与 SEH 指令。例程写入对象首槽 0x42a90。0x34f09 经 0x3ac20 GuardCF 槽调度 [对象+0x10] 的虚表 +0x10，0x34f18 在缓冲指针非零时用 LocalFree 释放 [对象+0x18]。0x34f22 检查 DIL 位 0，位为 1 时用 RCX 传对象、EDX 传 0x20，经 0x35134 和 0x34f80 到 IAT 0x3a9e0 对应的 mfc140.dll!#1487。

ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x34ee0,0x34f3f)`，片段 SHA-256 `5605be7ff7427d7b14a0069c4176e9090765233cb7fbffbdee14555282bd0bcc`。

1,005 个入口中 720 个有覆盖、285 个缺口，7,433 条引用中 636 条未决。0x34f09 的实机接收者和最终虚调用目标仍待 Windows 对照。整件静态验收未通过。 [交付回执](../s49-submission.md)
