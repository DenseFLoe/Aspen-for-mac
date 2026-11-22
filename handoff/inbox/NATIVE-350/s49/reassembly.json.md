# reassembly.json 的复验说明

以 COFF 比较 160 字节代码、12 字节 .pdata、12 字节 .xdata、6 字节格式和 512 字节初始零填充，同时核对 10 条文本重定位、9 条转移与 CRT 导入链。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15180,0x15220)`，160 字节，范围 SHA-256 `3a7e60ad7c37883a4c047ccd60a1c35881af319f8d2c4bba9154a5d1fb1a92ef`。 本文件 SHA-256 `f1017ea63dd2c705a1b924056823f104d55c94d96fe50324e5f3f760d6f98853`。

整件覆盖 153/255 个入口，仍有 102 个入口缺口和 26 条未决引用，静态验收未通过。 [本轮回执](../s49-submission.md)
