# zedstwu.dll s53 交付

NATIVE-350，owner upstream，assigned_seq=53。交付 UTC 2026-11-23T00:07:06Z。基线 `2d13d4e28bffd770252e8e0c4bb491bdf256a4f6`。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15000,0x15176)`，374 字节，范围 SHA-256 `e3a5b4ddb8c8dd30d9e7899520b6e29e574c73d09882bf8de1d72dfb7737ca58`。 83 条指令、24 处文本重定位、15 条直接转移、12 字节 .pdata 和 12 字节 .xdata 均匹配。另核对 62 条默认消息记录和指针、7 个导入调用点及 536 字节初始零填充。

整件已覆盖 154/255 个入口，仍有 101 个入口及 26 条引用待核，静态验收未通过。 下一段可查本件在 0x15054 调用的资源路径格式化例程。

[逐址说明](s53/select-diagnostic-message.c.md) · [覆盖复跑](s53/coverage-check.txt) · [成对对照](s53/record-control.json) · [成果指纹](s53/manifest.sha256) `86eb6d74f3d87d85824fa26fff0f456bed0a02f8f3558916d7a7d00eb3990e3e`。
