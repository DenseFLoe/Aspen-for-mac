# AspenDataShareCS.dll 静态验收

- 产品归属 Plus
- 安装基准 Aspen V15.0，原件版本 V15.0
- 原相对路径 [CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenDataShareCS.dll
- 原件 SHA-256 d1b62813294a5cd6c2a6f7e06f9982ce1b407feba10708373db9f0e39344e89d
- 交付路线 C#-source+IL-replay
- 结论 **静态验收通过**。核对安装原件、实际编译输入、代码和必要资源，复现结果与原件逐字节一致。
- 20046 条带 CIL 方法体由源码重编后逐方法重发（配方 verified_methods 校验），23 条无体方法按原件保留；CLR 元数据/调试/证书/PE 头与段布局按原件输入回放；非纯源码重建。
- Windows 重建与运行对照留待后续阶段。

[可编辑源码、资源及复验证据](<AspenDataShareCS.dll.source.zip>) · [逐件证据](evidence/发布复核.json)

发布包 SHA-256 686018961b406cdcf742c128c2cbed6fad1e0ac0fed39e4b528f63255bab2939。
