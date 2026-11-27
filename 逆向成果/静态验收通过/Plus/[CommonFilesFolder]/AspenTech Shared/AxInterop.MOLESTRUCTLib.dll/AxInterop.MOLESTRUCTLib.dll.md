# AxInterop.MOLESTRUCTLib.dll 静态验收

- 产品归属 Plus / Properties
- 安装基准 Aspen V15.0，原件版本 V15.0
- 原相对路径 [CommonFilesFolder]/AspenTech Shared/AxInterop.MOLESTRUCTLib.dll
- 原件 SHA-256 df5c39b29daa4892d8f906310ff3e336a1db3ded0a72eaa2d5da60fdd119696f
- 交付路线 IL-source
- 结论 **静态验收通过**。核对安装原件、实际编译输入、代码和必要资源，复现结果与原件逐字节一致。
- IL 源码路线：原件 IL 经 ildasm→ilasm 复编，Cecil 语义令牌重锚，时间戳/MVID/强名槽归零，CLR 元数据/CLR 头/强名/证书表按原件回放；交付为 .il，不是 C# 反编译，不可与 C# 路线件同类比较
- Windows 重建与运行对照留待后续阶段。

[可编辑源码、资源及复验证据](<AxInterop.MOLESTRUCTLib.dll.source.zip>) · [逐件证据](evidence/发布复核.json)

发布包 SHA-256 6d65f2f8630dbc8d8439821291bdbe68d24ec71c2e38fb8167f49d9227a9cc3f。
