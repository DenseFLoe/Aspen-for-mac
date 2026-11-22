# zedstwu.dll s49 交付

NATIVE-350，owner upstream，assigned_seq=49。交付 UTC 2026-11-22T23:05:25Z。基线 `e3b3049622bbefa9241099561a8fadd35a9b25c1`。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15180,0x15220)`，160 字节，范围 SHA-256 `3a7e60ad7c37883a4c047ccd60a1c35881af319f8d2c4bba9154a5d1fb1a92ef`。 42 条指令、10 处文本重定位、9 条直接转移、12 字节 .pdata 和 12 字节 .xdata 均匹配。另核对 6 字节字符串、512 字节初始零填充和 CRT 导入链。

整件覆盖 153/255 个入口，仍有 102 个入口缺口和 26 条未决引用，静态验收未通过。 下一段可查 0x151a3 调用的消息选择例程 RVA `[0x15000,0x15176)`。

[参数与路径](s49/report-diagnostic.c.md) · [复验命令](s49/check-diagnostic.py.md) · [覆盖复跑](s49/coverage-check.txt) · [成对对照](s49/capacity-control.json) · [成果指纹](s49/manifest.sha256) `de4be29d45293f6823a8ce7971ad59f107ae96a37d13ae0baa8044aab3acc47a`。
