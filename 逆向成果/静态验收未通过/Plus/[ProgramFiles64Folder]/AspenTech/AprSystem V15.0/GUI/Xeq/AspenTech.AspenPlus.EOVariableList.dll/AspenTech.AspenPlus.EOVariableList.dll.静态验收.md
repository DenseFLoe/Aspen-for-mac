# AspenTech.AspenPlus.EOVariableList.dll 静态验收

2026-11-21，三组第 4 轮。结论为**静态验收未通过**。

## 原件与交付

- Aspen Plus V15.0，原成员路径 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.EOVariableList.dll`。安装包索引记录为 `APRS~440.cab` 中的 `aspentech.aspenplus.51.01AE6323_4069_4985_B882_1C2F459EE258`。
- 程序集及文件版本 `41.0.0.614`，36,392 字节，I386 PE，CLR `ILOnly`。原件 SHA-256 为 `1028d3dd171c630b8d47ac994e7ec77baa9b840b32ce4f5e162ae9681cbb1ae7`，与三组清单及本机留存原件一致。
- 核对基线为 `950ae6eca319516ab9586c24556c67904cd3f924`。[正式 C#](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/AspenTech.AspenPlus.EOVariableList.dll.cs.txt) 的 Git blob 为 `3bdedf0988fd2fe49299ef2b9d3458541cda9fa8`。[独立 IL](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/AspenTech.AspenPlus.EOVariableList.dll.il.txt) 的 Git blob 为 `3fb4a034206da799b89bf899c502fbe9ce6f8b10`。[制作者报告](v0.20261121-w2/%E5%88%B6%E4%BD%9C%E8%80%85%E6%8A%A5%E5%91%8A/AspenTech.AspenPlus.EOVariableList.dll.md) 随整件保留。正式交付仅有上述两种代码导出。

## 核对结果

- **方法与元数据。** 12 个 TypeDef、33 个字段、19 个属性及 90 个 MethodDef。独立 IL 清单逐个匹配令牌与 RVA，其中 79 个有 IL 体，2,069 条指令的 5,581 字节逐一吻合。
- **可编辑源码。** 正式 C# 的第 1,165–1,166 行是 ILSpy 版本提示，Roslyn 报 10 条语法错误，首条为 CS8803。仅从临时副本移去这两行后，语法诊断归零。`OpenDialog`（`0x0600000B`）仍带有 ILSpy 类型解析提示，须用对应依赖核对类型和绑定。
- **资源与布局。** 原件托管清单资源数为 0，PE 含 `RT_VERSION`（资源目录 1,212 字节）。W2 未交付可编辑的版本资源及构建配置。`0x0600000B` 从 `AspenTech.AspenPlus.MMForms.GridForms.Controls` 调用 `VariableListDialog` 构造函数，源码第 280–301 行设置窗口属性和事件，布局由该外部对话框提供。

## 复现与通过条件

用 PowerShell 7.6.9 的 `System.Reflection.Metadata` 读取原 DLL 的 `MethodDefinitions` 和 `GetMethodBody().GetILBytes()`。按独立 IL 的 `MD` 令牌读 RVA，拼接其下各 `IL_*` 行的十六进制字节逐项比较。用 Roslyn C# 5.0.0.0 的 `CSharpSyntaxTree.ParseText().GetDiagnostics()` 解析完整交付及移去两行提示的临时副本。读取 `ManifestResources` 及 PE `ResourceTableDirectory` 核对资源名称、大小和类型。IL 字节核对仅针对独立 IL，C# 检查为静态语法与定位检查。

提交无工具输出的 C#、可编辑的版本资源和构建配置，核对 C# 对应的成员与方法实现。用一致版本的 `GridForms` 等依赖复核 `OpenDialog` 的事件、属性与绑定。 Windows 行为对照留待重建阶段。
