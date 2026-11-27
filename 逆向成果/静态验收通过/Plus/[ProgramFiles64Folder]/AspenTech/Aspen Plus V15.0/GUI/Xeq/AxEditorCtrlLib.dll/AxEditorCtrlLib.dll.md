# AxEditorCtrlLib.dll 静态验收

- 产品归属 Plus
- 安装基准 Aspen V15.0，原件版本 V15.0
- 原相对路径 [ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/AxEditorCtrlLib.dll
- 原件 SHA-256 5ca67d4970c4d59533e0a71074dbfd6d66daa43569a71ffbabbc02d5be3de821
- 交付路线 IL-source
- 结论 **静态验收通过**。核对安装原件、实际编译输入、代码和必要资源，复现结果与原件逐字节一致。
- IL 源码路线：原件 IL 经 ildasm→ilasm 复编，按语义键改锚 156 个令牌操作数与 3 个 catch 类型，非确定字段（时间戳/校验和/MVID/强名槽）归零，CLR 元数据/CLR 头/强名/证书表按原件回放（占比约 76.1%）。交付为 .il，不是 C# 反编译，不可与 C# 路线件同类比较
- Windows 重建与运行对照留待后续阶段。

[可编辑源码、资源及复验证据](<AxEditorCtrlLib.dll.source.zip>) · [逐件证据](evidence/发布复核.json)

发布包 SHA-256 3259ba1e90ae94123e21e4c48f4b33deb0d8787d6937c0b82b7cfc8dabf4a3d2。
