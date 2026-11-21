# ModelEquations.dll 静态验收

2026-11-21，三组第 4 轮。结论为**静态验收未通过**。

## 原件与交付

- Aspen Plus V15.0，原成员路径 `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/ModelEquations.dll`。安装包索引记录为 `ASPE~357.cab` 中的 `modelequations.dll.D470D1DF_9FE5_4F3E_9EF6_CEAA577688D0`。
- 程序集及文件版本 `7.0.2.0`，326,224 字节，I386 PE，CLR `ILOnly`。原件 SHA-256 为 `0a48d0cf1b6f7f6fb3b45c224a4860b035084b6321ace62e6fec1a4007808ae2`，与三组清单及本机留存原件一致。
- 核对基线为 `950ae6eca319516ab9586c24556c67904cd3f924`。[正式 C#](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/ModelEquations.dll.cs.txt) 的 Git blob 为 `62f0b71ad38e93a2db254e8350e7f2fd3f3e8a22`。[独立 IL](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/ModelEquations.dll.il.txt) 的 Git blob 为 `b706d75238d3e006d2d79f0e5a86f8ced1688731`。[制作者报告](v0.20261121-w2/%E5%88%B6%E4%BD%9C%E8%80%85%E6%8A%A5%E5%91%8A/ModelEquations.dll.md) 随整件保留。正式交付仅有上述两种代码导出。

## 核对结果

- **方法与元数据。** 270 个 TypeDef、620 个字段、328 个属性及 1,828 个 MethodDef。独立 IL 清单逐个匹配令牌与 RVA，其中 1,286 个有 IL 体，3,515 条指令的 8,643 字节逐一吻合。
- **可编辑源码。** W2 C# 有 506 条语法错误。仅移去第 8,446–8,447 行的两行尾部提示后，仍有 497 条错误。第 28 行 `using tj4=;` 触发 CS1031，第 48 行 `internal class <Module>` 触发 CS1001。原 DLL 的 `0x06000001` 调用 `<AgileDotNetRT>` 初始化，`0x06000003` 和 `0x06000004` 各只有 `ldnull; ret`。清单保留了静态占位方法体，交付没有给出这些方法对应的可编辑业务实现。
- **资源与布局。** 原件含三个独立的内嵌托管资源 `{FEA94A50-E5C8-4edd-BE62-F738BC8C043E}`（7,697 字节）、`69bfbd1f-c8f8-4f26-bae7-9486f054fda3`（28,616 字节）和 `05ba51b1-50b5-4637-893d-7077b9ba7d92`（28,902 字节），以及 PE `RT_VERSION`（资源目录 1,096 字节）。W2 目录没有这些资源的可编辑重建输入。

## 复现与通过条件

用 PowerShell 7.6.9 的 `System.Reflection.Metadata` 读取原 DLL 的 `MethodDefinitions` 和 `GetMethodBody().GetILBytes()`。按独立 IL 的 `MD` 令牌读 RVA，拼接其下各 `IL_*` 行的十六进制字节逐项比较。用 Roslyn C# 5.0.0.0 的 `CSharpSyntaxTree.ParseText().GetDiagnostics()` 解析完整交付及移去两行提示的临时副本。读取 `ManifestResources` 及 PE `ResourceTableDirectory` 核对资源名称、大小和类型。IL 字节核对仅针对独立 IL，C# 检查为静态语法与定位检查。

提供语法可解析的源码，逐个说明初始化所涉方法的实际实现与原令牌的对应关系，补齐各相关资源及嵌入配置，复核成员与代码覆盖。 Windows 行为对照留待重建阶段。
