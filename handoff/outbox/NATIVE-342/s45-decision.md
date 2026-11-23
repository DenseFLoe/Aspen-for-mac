# ApwnIPShell.dll s45 裁定

ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 基线 `7ce64a251d9c5210041903988c016a53b3f85287`，候选清单 SHA-256 `3d4acd60b85ee2f01ebdb60403660d6f99afbb23b8ec72dd133e3ed4ef16c23b`。范围 `[0x34e90,0x34ed4)`，片段 SHA-256 `83775a03ae2ae71bffd68eec65a47da50fe4e46b9805833aa6062f1a1c73d913`。

68 字节、20 条指令、3 处 REL32、.pdata 12 字节和 .xdata 8 字节逐字节吻合。 1,005 个入口中 719 个有覆盖、286 个缺口，7,433 条引用中 636 条未决。0x34eb3 的实时接收对象和虚调用目标待核。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-342/s45-submission.md) · [复验](../../inbox/NATIVE-342/s45/reassembly.json) · [成对用例](../../inbox/NATIVE-342/s45/operand-control.json) · [续领卡](../../assignments/NATIVE-342-s49.md)
