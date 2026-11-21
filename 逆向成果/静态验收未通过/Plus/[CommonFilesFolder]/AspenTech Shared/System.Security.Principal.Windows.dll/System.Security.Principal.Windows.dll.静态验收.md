# System.Security.Principal.Windows.dll 静态验收

状态为**静态验收未通过**。缺链接器替换 XML 和 PE 版本资源重建输入，C# 尾部混入未注释的工具输出。

- 原件来自 Aspen Plus V15.0（64 位）安装介质，原路径为 `[CommonFilesFolder]/AspenTech Shared/System.Security.Principal.Windows.dll`。介质索引为 `DBMGR~21.cab` 的 `system.security.principal.wi.00C8CD4F_F851_484A_A03B_6432F5895243`。从对应已安装位置只读复用，字节数为 18,312，SHA-256 为 `b4d8e15adc235d0e858e39b5133e5d00a4baa8c94f4f39e3b5e791b0f9c0c806`，与介质清单和 GitHub 原件登记一致。
- 文件版本为 `5.0.20.51904`，程序集版本为 `5.0.0.0`，CLR Flags 为 `0x9`，原件强名签名区为 128 字节。
- 使用 dnfile 0.18.0 / pefile 2024.8.26 读取原件。核对 16 条 TypeDef、8 条 Field 和 25 条 MethodDef。发布 IL 的所有 MethodDef 按令牌、名称及 RVA 对应，25 个 IL 方法体按偏移拼接原始指令字节后与 PE 一致。
- ExportedType 中有 12 个转发条目，C# 中的 `TypeForwardedTo` 条数与名称对应，目标类型由 `mscorlib` 提供。
- 用 ILSpy CLI 9.1.0.7988 直接读取同指纹原件输出 C# 和 IL。C# 与发布文本逐行一致，末尾有两行未注释的工具提示，移除前不能直接作为 C# 输入。

## 原件资源与交付缺口

- CLR ManifestResource `ILLink.Substitutions.xml`，538 字节，SHA-256 为 `9885610053db580a4ed3164cde38a48c453afcb3dbeec112824a9139d8298d6d`。当前目录没有相应资源输入。
- PE `RT_VERSION/1/0`，1,160 字节，SHA-256 为 `ebfaeb2ca85b815b5a2a907223c2ad3e00a230e0a573a844495d7b99fe94d771`。C# 版本特性提供了部分字段，归档缺少重建该 PE 资源的输入。

## 交付定位与复验

- [C# 导出](%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/decompiled/System.Security.Principal.Windows.dll.cs.txt)，Git blob 为 `57938dc0c118dfe7337e7a844e276146d90b55fe`。
- [IL 清单](%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/il/System.Security.Principal.Windows.dll.il.txt)，Git blob 为 `5bde080e570218e87db7d51720d88316dc16c6d8`。
- 复核 C# 末尾第 179 至 180 行的提示是否已清理，按原件资源清单和指纹复核资源输入与逻辑。保留原交付文件并给出清理后的可编辑版本。
- Windows 重建阶段验证程序集引用、强名绑定及运行行为。
