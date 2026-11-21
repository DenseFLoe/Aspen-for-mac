# Microsoft.Bcl.HashCode.dll 第 3 轮静态验收

**静态验收未通过**。第四组于 2026-11-21 核对原件、交付的 C#、IL 清单和资源覆盖。转静态验收修复组，沿用复验组 4。

## 原件与交付

- Aspen Plus V15.0 原路径 `[CommonFilesFolder]/AspenTech Shared/Microsoft.Bcl.HashCode.dll`
- 安装介质成员 `DBMGRC~2.cab` 中的 `microsoft.bcl.hashcode.dll.00C8CD4F_F851_484A_A03B_6432F5895243`。复用已提取件，文件版本 `4.700.20.56604`，程序集版本 `1.0.0.0`，SHA-256 `76b1260ce747a317e9b514433b89a81b038411fcabddc6f9c7dbabb0742d8b81`。
- [C# 交付](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/Microsoft.Bcl.HashCode.dll.cs.txt) SHA-256 `0d79f624e4e5e5d4bbb922db754060a0f29fb1898c31903ad6e7e656d4083638`
- [IL 清单](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/Microsoft.Bcl.HashCode.dll.il.txt) SHA-256 `248e17d429bb83cae2ce72408ebc768de9b83fbc60a0ae76ca0c4c822246ab1a`
- [原逐件报告](v0.20261121-w2/%E5%88%B6%E4%BD%9C%E8%80%85%E6%8A%A5%E5%91%8A/Microsoft.Bcl.HashCode.dll.md)

## 核对记录

用 PowerShell 7.6.9 的 `Get-FileHash` 核对原件并用 `System.Reflection.Metadata.PEReader` 直接枚举 .NET 元数据。原件有 11 项 TypeDef（含 `<Module>`）、19 项 FieldDef、48 项 MethodDef，其中 48 个有方法体。程序集引用 `mscorlib`、`System`。原件方法体另外登记了 2 条异常处理区域。

复查时，从交付 IL 清单的 `MD` 行读取方法令牌和 RVA，再按每条 `IL_` 行的偏移拼接十六进制指令，逐件与 `PEReader.GetMethodBody(rva).GetILBytes()` 比对。全部 48 项 MethodDef 的令牌与 RVA 相符，有体项合计 2912 个 IL 指令字节相符。该计数覆盖指令字节，异常处理表单独计数。

## 缺口与复验条件

- C# 交付第 578–579 行是未加注释的 ILSpy 9.1.0.7988 版本提示，直接作为源文件会导致语法错误。
- 原件内嵌 `FxResources.Microsoft.Bcl.HashCode.SR.resources`。C# 第 447–451 行创建 ResourceManager 并读取 `HashCode_EqualityNotSupported` 和 `HashCode_HashCodeNotSupported`，本件目录缺该资源的重建输入及嵌入名称配置。
- PE 资源目录含类型 16（`RT_VERSION`），目录数据区长度 1188 字节。本件交付缺对应重建输入。

提供清理后的 C#、资源的可核验重建输入、逻辑资源名及 PE 版本资源输入。复验时核对资源名、键与原件内容指纹、嵌入配置及方法覆盖。 Windows 运行对照留到后续阶段。
