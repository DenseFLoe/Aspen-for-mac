# Microsoft.Practices.Composite.Presentation.dll 静态验收

**静态验收未通过**。缺字符串资源和 PE 版本资源重建输入。发布 IL 缺已定位的异常处理区段，C# 文本末尾混入两行未注释的工具提示。

- 原件来自 Aspen Plus V15.0（64 位）。原路径为 `[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Microsoft.Practices.Composite.Presentation.dll`，介质记录为 `PSVLRS~5.cab` 中的 `microsoft.practices.composit1.2B16631B_A5A7_4E27_A73B_18F9DA9FF484`。复用与介质清单同指纹的本地原件，大小为 69,576 字节，SHA-256 为 `57fad9ec5183b73d94e6cd565e5effa6d6edb2db939579c2b70256debccee269`。
- 文件版本为 `2.0.1.0`，程序集版本为 `2.0.1.0`。PE 为 I386，CLR 标志为 `ILOnly, StrongNameSigned`。
- 用 .NET 8.0.100 SDK 的 `System.Reflection.Metadata` 读取 PE 与 CLR 元数据。原件有 56 条 TypeDef。发布 IL 的 368 个 `MD` 令牌与原件 MethodDef 一一对应。将各段 `IL_` 记录的十六进制指令按顺序拼接，与 `PEReader.GetMethodBody(rva).GetILBytes()` 比较，355 个方法体全部相同；另有 13 条原件 MethodDef 无方法体。
- 以 `dotnet ilspycmd.dll <同指纹原件>` 运行 ILSpy CLI 9.1.0.7988。统一换行、去掉文件末尾空白及版本提示后，重新导出的 C# 与发布 C# 一致。发布 C# 第 2631、2632 行是未注释的版本提示。

## 原件资源与交付缺口

C# 的 `Properties.Resources` 通过 `ResourceManager` 读取字符串。

交付目录中只有 C#、IL 与报告。以下原件资源的内容和重建输入缺失。CLR 资源按 ManifestResource 记录和 CLR 资源目录读取，PE 资源用 pefile 2024.8.26 读取。

| 原件资源 | 字节数 | SHA-256 |
| --- | ---: | --- |
| `Microsoft.Practices.Composite.Presentation.Properties.Resources.resources` | 4,540 | `e93124fbd5cba8d39c655b43e5a17bc2e4aa72341021677674a0e78d7ea2e6a8` |
| PE `RT_VERSION (16) / 1 / 0` | 1,112 | `c32e9cb27627d918c91b07943d798d260b88778323a264f6d2d854aa270fff8b` |

原件有 33 个异常处理区段。用 `PEReader.GetMethodBody(rva).ExceptionRegions` 可以复查。例如 `RegisterCommand`（`0x06000012`）有 1 个区段，首段类型为 `Finally`。发布 IL 的该方法记录给出指令，缺用于恢复该区段的边界和处理信息。

## 交付指纹与复验

- [发布 C#](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/Microsoft.Practices.Composite.Presentation.dll.cs.txt)的 SHA-256 为 `0e00c99a4a3bfe8f6f6725b2ab6377c4d8f96a37cea5f8217d90208beba39c26`。
- [发布 IL](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/Microsoft.Practices.Composite.Presentation.dll.il.txt)的 SHA-256 为 `f0b21a28a748f0cff1afbdebb78c72f87087ec9cfcd6650af7564e80e9a8c408`。

修复时提供上述 CLR 资源及 PE 版本资源的重建输入，清除 C# 尾部工具提示，并在 IL 证据中补齐异常处理区段。随后按同一原件 SHA-256 复核成员、方法体、异常区段及资源内容。Windows 运行对照留到后续重建阶段。
