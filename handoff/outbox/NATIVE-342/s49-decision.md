# ApwnIPShell.dll s49 裁定

ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 基线 `85a00df048174880027d84a5cb4a2d006f78f82c`，候选清单 SHA-256 `0e7f032525d691fd5760d5da37ca8c35ad8130a6581afa15042a3e022e71bb82`。范围 `[0x34ee0,0x34f3f)`，片段 SHA-256 `5605be7ff7427d7b14a0069c4176e9090765233cb7fbffbdee14555282bd0bcc`。

95 字节、27 条指令、4 处 REL32、.pdata 12 字节和 .xdata 12 字节逐字节吻合。 1,005 个入口中 720 个有覆盖、285 个缺口，7,433 条引用中 636 条未决。0x34f09 的实机接收者和最终虚调用目标仍待 Windows 对照。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-342/s49-submission.md) · [复验](../../inbox/NATIVE-342/s49/reassembly.json) · [成对用例](../../inbox/NATIVE-342/s49/operand-control.json) · [续领卡](../../assignments/NATIVE-342-s53.md)
