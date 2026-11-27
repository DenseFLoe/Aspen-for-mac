# AxAdvancedFileDialogLib.dll 静态验收

- 产品归属 Plus / Properties
- 安装基准 Aspen V15.0，原件版本 V15.0
- 原相对路径 [ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AxAdvancedFileDialogLib.dll
- 原件 SHA-256 69334416181b76a02518adb46666fd891102d4d754bb4aa2eb44930482267531
- 交付路线 C# 声明层（原件无 CIL 方法体）
- 结论 **静态验收通过**。核对安装原件、实际编译输入、代码和必要资源，复现结果与原件逐字节一致。
- AxHost 包装件（23 个 CIL 方法，非 no-IL）：代码区由 editable/ 源码独立复编；元数据/强名/CLR 头/证书表按原件回放；Win32 资源按原件编入。不是“元数据亦由源码生成”。
- Windows 重建与运行对照留待后续阶段。

[可编辑源码、资源及复验证据](<AxAdvancedFileDialogLib.dll.source.zip>) · [逐件证据](evidence/发布复核.json)

发布包 SHA-256 638495b38be878dcb762b732e96e1c9c25c039196de1b46dc5b2435e574697f2。
