# Interop.MMLocal.dll 静态验收

- 结论 **静态验收通过**，正式源码为完整可编辑 IL。
- 产品归属 Plus / Properties，安装基准 Aspen V15.0，程序集版本 0.0.0.0。
- 原相对路径 [ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Interop.MMLocal.dll
- 原件 SHA-256 c839a5f398b42f8449c065fe088e2492eade05ae50dabe5100fdf073ec653fde
- 完整 IL 与安装原件的重新导出逐行相等。实际 IL 汇编后核对的 544 项元数据记录一致，涵盖 118 个无体 COM 方法声明及其外部引用。唯一 Win32 版本资源逐字节一致。
- CLR 原始元数据等保留输入随包归档。直接 IL 汇编存在物理布局与签名标志差异，运行行为留待 Windows 重建对照。

[源码及证据包](Interop.MMLocal.dll.source.zip) · [逐件复验证据](evidence/static-review.json)

源码包 SHA-256 7297c8fece9a39fea0aa3d1352dda9c2ba47b08038022cb3ed9358bfab652da4
