# operand-control.json

同原件仅将 0x34f1e 的 DIL 检查从掩码 1 改为 2，再刷新输入指纹。覆盖 v1 退出 2→2，局部回编 0→1，首差 0x34f21。

ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x34ee0,0x34f3f)`，片段 SHA-256 `5605be7ff7427d7b14a0069c4176e9090765233cb7fbffbdee14555282bd0bcc`。

1,005 个入口中 720 个有覆盖、285 个缺口，7,433 条引用中 636 条未决。0x34f09 的实机接收者和最终虚调用目标仍待 Windows 对照。整件静态验收未通过。 [交付回执](../s49-submission.md)
