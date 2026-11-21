# AspenTech.HtmlHelp.StrongNameInvoke.dll 静态验收

2026-11-21，验收四组第 1 轮。**静态验收未通过**，转失败修复组，复验组为 4。

交付的 C# 末尾混入两行工具更新提示，Roslyn 无法将整份文件解析为 C#。

## 原件身份

- 产品和原路径为 `Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.HtmlHelp.StrongNameInvoke.dll`。
- 来源为 Aspen Plus V15 64 位 MSI 的 `APRS~258.cab` 的 `aspentech.htmlhelp.strongnam.01AE6323_4069_4985_B882_1C2F459EE258`。本轮复用已提取成员，复算完整原件指纹。
- 文件版本 `2023.15.0.2`，原件共 20,632 字节。SHA-256 为 `02826aae6dfd55ee302126d19925cd9cc9660dd701a8679ec301a1dbc6aa5c8a`。

## 证据与修复条件

ILSpy 9.1.0.7988 导出的 [C#](%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/decompiled/AspenTech.HtmlHelp.StrongNameInvoke.dll.cs.txt)（Git blob `a7852d8e6d4088ce0200c46a64ee8d49949a59f6`）第 282 行是最后一个闭括号，第 283 至 284 行是两行未注释的 ILSpy 更新通知。用 Roslyn 5.0.0.0 的 `CSharpSyntaxTree.ParseText` 解析整篇得到 10 个语法错误，含第 283 行的 CS8803 与 CS1003。用同一工具解析前 282 行，语法错误为 0。

用 System.Reflection.Metadata 10.0.0 的 `PEReader` 对照 [交付 IL](%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/il/AspenTech.HtmlHelp.StrongNameInvoke.dll.il.txt)（Git blob `1f36a14cf1c42b3907ce7177f81aec4d08d37f6a`）。18 个方法体的 440 条指令、1,314 字节及相应偏移均匹配，原件另含 10 个异常区域。第 19 个方法 `0x0600000F` 为抽象接口声明 `ILogWriter.WriteToLog`，RVA 为 0。原件有 5 个业务类型、15 个字段、1 个属性，托管资源表为空。唯一 PE 资源为版本资源 `16/1/0`，长 1,116 字节，SHA-256 为 `870291a75c17ae8d1077107cb2f03f5d6359c1f79e77b913146a5cdb96257805`。外部边界为 `mscorlib 4.0.0.0` 与运行时 COM 标识 `HtmlHelpLauncher.6`。

修复时保留旧交付，另归档清除更新提示的可编辑 `.cs`，核对源码中的方法、异常处理和原版版本声明，再交第四组复验。

[既有成果和制作者报告](AspenTech.HtmlHelp.StrongNameInvoke.dll.%E5%BD%92%E6%A1%A3%E8%AF%B4%E6%98%8E.md)
