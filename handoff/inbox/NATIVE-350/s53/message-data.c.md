# message-data.c 的复验说明

默认消息记录各 16 字节，含两个 32 位字段与一个 64 位指针。62 个 COFF ADDR64 与原件的 PE DIR64 逐条核对。另比对空串、文件名和格式串，以及 RVA [0x23a58,0x23c70) 的 536 字节初始零填充。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15000,0x15176)`，374 字节，范围 SHA-256 `e3a5b4ddb8c8dd30d9e7899520b6e29e574c73d09882bf8de1d72dfb7737ca58`。 本文件 SHA-256 `7109f149e77dab690e361882fccee40568dd774032ccdd9e9a8eecaaab3eefc5`。

整件已覆盖 154/255 个入口，仍有 101 个入口及 26 条引用待核，静态验收未通过。 [本轮回执](../s53-submission.md)
