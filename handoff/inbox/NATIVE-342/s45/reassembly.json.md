# reassembly.json

68 字节、20 条指令、3 处 REL32、.pdata 12 字节和 .xdata 8 字节逐字节吻合。0x34e96 取虚表 0x42a90 并写回对象头。对象 +0x10 非空时取其虚表的 +0x10 槽，经 0x3ac20 调度。对象 +0x18 非空时恢复栈及 RBX，并在 0x34ec7 尾跳至 KERNEL32.dll!LocalFree 的 IAT 槽 0x3a2f0。按这些指令将本函数记为对象清理。

ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x34e90,0x34ed4)`，片段 SHA-256 `83775a03ae2ae71bffd68eec65a47da50fe4e46b9805833aa6062f1a1c73d913`。

1,005 个入口中 719 个有覆盖、286 个缺口，7,433 条引用中 636 条未决。0x34eb3 的实时接收对象和虚调用目标待核。整件静态验收未通过。 [交付回执](../s45-submission.md)
