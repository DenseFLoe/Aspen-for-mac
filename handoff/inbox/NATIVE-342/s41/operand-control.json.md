# operand-control.json

0x34e67 从检查 R9B 改为检查 R9D。当 R9D=0x100 时应跳过虚调用。只改这一项并刷新指纹，覆盖 v1 为 2→2，局部回编为 0→1。

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x34e40,0x34e85)`，片段 SHA-256 `dfeaea0ef12e23a31c55b931d22c4df503a8cbdc067c31c4d5f1434aff37af51`。

1,005 个入口中 718 个有覆盖、287 个缺口，7,433 条引用中 636 条未决。整件静态验收未通过。 [交付回执](../s41-submission.md)
