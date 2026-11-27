# AxPFSPlotLib.dll 静态验收

- 产品归属 Plus / Properties
- 安装基准 Aspen V15.0，原件版本 V15.0
- 原相对路径 [ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AxPFSPlotLib.dll
- 原件 SHA-256 c805c462b3433783c27a55105a8f212a2e2fe2409f8685d16dc50cdf2be3ec26
- 交付路线 IL-source
- 结论 **静态验收通过**。核对安装原件、实际编译输入、代码和必要资源，复现结果与原件逐字节一致。
- IL 源码路线：原件 IL 经 ildasm→ilasm 复编，按语义键改锚 624 个令牌操作数与 3 个 EH 类型，非确定字段归零，CLR 元数据/CLR 头/强名/证书表按原件回放（占比约 71.9%）。交付为 .il，不是 C# 反编译，不可与 C# 路线件同类比较
- Windows 重建与运行对照留待后续阶段。

[可编辑源码、资源及复验证据](<AxPFSPlotLib.dll.source.zip>) · [逐件证据](evidence/发布复核.json)

发布包 SHA-256 981a34c551d3b587d45a9c02ea9195a2b752d95c532d1240b87f33f8d4645e7e。
