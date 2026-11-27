# AspenTech.AspenPlus.MMForms.Utility.dll 静态验收

- 产品归属 Plus / Properties
- 安装基准 Aspen V15.0，原件版本 V15.0
- 原相对路径 [ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Utility.dll
- 原件 SHA-256 9d0c82742e6ae4bfa6e6927e1e8d3151b34af636d4e7dd6542ff1badac06a188
- 交付路线 C#-source(Roslyn3.8)+IL-replay
- 结论 **静态验收通过**。核对安装原件、实际编译输入、代码和必要资源，复现结果与原件逐字节一致。
- 方法体由 Roslyn 3.8.0 重编候选逐方法重发（278/278 配方、13 条 localsig token 重定位），CLR 元数据/调试记录/证书表按原件保留输入回放；非源码完整重建；工具链 csc 3.8.0 与 framework-4.8 引用已入归档。
- Windows 重建与运行对照留待后续阶段。

[可编辑源码、资源及复验证据](<AspenTech.AspenPlus.MMForms.Utility.dll.source.zip>) · [逐件证据](evidence/发布复核.json)

发布包 SHA-256 2466f4d533bfb0a96e50fc8ea0c7145360bd401292ed0823936db064b7d664d0。
