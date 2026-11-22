# zedstwu.dll s45 交付

NATIVE-350，owner upstream，assigned_seq=45。交付 UTC 2026-11-22T22:34:51Z。基线 `08fce6abe7ef487a6b72e3f8974b0d4f8cb999e3`。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，版本 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x14cb0,0x14f6d)`，701 字节，范围 SHA-256 `5728fad0d29bfcee9a0e69875d0c7a3742a17ab40da0b123c3329b2e3fc3b50e`。190 条指令、36 处文本重定位、20 条直接控制转移、12 字节 .pdata 与 16 字节 .xdata 均已对照。64 字节初始阈值和 21 字节环境变量名另从可编辑 C 回编核对。

整件覆盖 152/255 个入口，尚余 103 个入口缺口和 26 条未决引用，静态验收未通过。 下一处可接续调试路径三次直接调用的辅助例程 `[0x15180,0x15220)`。

[就绪、缓存、阈值和退出路径说明](s45/configure-cache-cutoffs.c.md) · [复验命令](s45/check-cutoffs.py.md) · [覆盖复跑](s45/coverage-check.txt) · [成果指纹](s45/manifest.sha256) `36d1ff902fe4dbf04817991b615cb9c5cbb206df93ed868af6865686c26b0b5b`。
