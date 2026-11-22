# diagnostic-data.c 的复验说明

保存两个零结尾的原件输出格式和 RVA 0x23850 处至少 0x200 字节的初始零填充。0x200 来自 0x151da 的参数设置，PE 虚拟区检查仅要求这个被引用范围处于数据节的零填充尾部。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15180,0x15220)`，160 字节，范围 SHA-256 `3a7e60ad7c37883a4c047ccd60a1c35881af319f8d2c4bba9154a5d1fb1a92ef`。 本文件 SHA-256 `6afdced1183f63023055826549e02a957c9cbe5f55cf022913ab8ed4db2527e9`。

整件覆盖 153/255 个入口，仍有 102 个入口缺口和 26 条未决引用，静态验收未通过。 [本轮回执](../s49-submission.md)
