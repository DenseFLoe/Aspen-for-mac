# Aspen Excel Add-in Manager 64 Bit.exe 静态验收

- 产品归属 Properties
- 安装基准 Aspen V15.0，原件版本 V15.0
- 原相对路径 [CommonFiles64Folder]/AspenTech Shared/Aspen Excel Add-in Manager 64 Bit.exe
- 原件 SHA-256 475a6475332299a4be0eb1573403cbf88176a81e7fcacfa958f5aa9f596866f0
- 交付路线 C#-source+IL-replay
- 结论 **静态验收通过**。核对安装原件、实际编译输入、代码和必要资源，复现结果与原件逐字节一致。
- 188/188 方法体由源码重编后按配方逐方法回放（含 1 处分支目标 nop_layout 声明）；CLR 元数据/资源/强名/证书表/调试记录按原件保留输入回放。
- Windows 重建与运行对照留待后续阶段。

[可编辑源码、资源及复验证据](<Aspen Excel Add-in Manager 64 Bit.exe.source.zip>) · [逐件证据](evidence/发布复核.json)

发布包 SHA-256 45950220fde62d5d0a0c8a64b44229c1894b719b5e677bf16ce3d067b749bc2c。
