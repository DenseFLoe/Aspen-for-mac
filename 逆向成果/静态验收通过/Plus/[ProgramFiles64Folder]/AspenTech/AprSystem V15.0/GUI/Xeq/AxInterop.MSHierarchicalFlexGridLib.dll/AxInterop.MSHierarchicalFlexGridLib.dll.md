# AxInterop.MSHierarchicalFlexGridLib.dll 静态验收

- 产品归属 Plus / Properties
- 安装基准 Aspen V15.0，原件版本 V15.0
- 原相对路径 [ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AxInterop.MSHierarchicalFlexGridLib.dll
- 原件 SHA-256 b68e44120f4d2010148706d1dc981312be3e9a7d15ed705ac2fb38a03ebe3d38
- 交付路线 IL-source
- 结论 **静态验收通过**。核对安装原件、实际编译输入、代码和必要资源，复现结果与原件逐字节一致。
- IL 源码路线：原件 IL 经 ildasm→ilasm 复编，Cecil 语义令牌重锚，时间戳/MVID/强名槽归零，CLR 元数据/CLR 头/强名/证书表按原件回放；交付为 .il，不是 C# 反编译。
- Windows 重建与运行对照留待后续阶段。

[可编辑源码、资源及复验证据](<AxInterop.MSHierarchicalFlexGridLib.dll.source.zip>) · [逐件证据](evidence/发布复核.json)

发布包 SHA-256 313af54b54ba9b52cb5580fd5cfa9afb5e4a86cee12a2015cdb4e612aa0c43c4。
