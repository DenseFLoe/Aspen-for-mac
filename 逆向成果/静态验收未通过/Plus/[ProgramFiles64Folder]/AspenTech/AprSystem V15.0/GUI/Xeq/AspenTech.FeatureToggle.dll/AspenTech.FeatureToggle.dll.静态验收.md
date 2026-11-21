# AspenTech.FeatureToggle.dll 第 3 轮静态验收

**静态验收未通过**。第四组于 2026-11-21 核对原件、交付的 C#、IL 清单和资源覆盖。转静态验收修复组，沿用复验组 4。

## 原件与交付

- Aspen Plus V15.0 原路径 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.FeatureToggle.dll`
- 安装介质成员 `APRS~547.cab` 中的 `aspentech.featuretoggle.dll.01AE6323_4069_4985_B882_1C2F459EE258`。复用已提取件，文件版本 `41.0.0.3`，程序集版本 `41.0.0.3`，SHA-256 `103fb93bb98c1683b8bdfc4b419103ba716dda89592512405d7f240b4e9e1a39`。
- [C# 交付](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/AspenTech.FeatureToggle.dll.cs.txt) SHA-256 `db21690ac1146c6923a11629da3c6e2a7af3403358439bbaeca5a48c4c56a519`
- [IL 清单](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/AspenTech.FeatureToggle.dll.il.txt) SHA-256 `5aacd785739365235c302961c2ea608306afd515055db243b916df41ab070d88`
- [原逐件报告](v0.20261121-w2/%E5%88%B6%E4%BD%9C%E8%80%85%E6%8A%A5%E5%91%8A/AspenTech.FeatureToggle.dll.md)

## 核对记录

用 PowerShell 7.6.9 的 `Get-FileHash` 核对原件并用 `System.Reflection.Metadata.PEReader` 直接枚举 .NET 元数据。原件有 5 项 TypeDef（含 `<Module>`）、16 项 FieldDef、46 项 MethodDef，其中 42 个有方法体、4 个为没有方法体的抽象声明。程序集引用 `mscorlib`、`System.Xml`。原件方法体另外登记了 4 条异常处理区域。

复查时，从交付 IL 清单的 `MD` 行读取方法令牌和 RVA，再按每条 `IL_` 行的偏移拼接十六进制指令，逐件与 `PEReader.GetMethodBody(rva).GetILBytes()` 比对。全部 46 项 MethodDef 的令牌与 RVA 相符，有体项合计 2055 个 IL 指令字节相符。该计数覆盖指令字节，异常处理表单独计数。

## 缺口与复验条件

- C# 交付第 332–333 行是未加注释的 ILSpy 9.1.0.7988 版本提示，直接作为源文件会导致语法错误。
- 原件内嵌 `AspenTech.FeatureToggle.Resources.AspenTech_FeatureToggleData.xml`。C# 第 184 行通过 `GetManifestResourceStream` 读取嵌入内容，本件目录缺该资源的重建输入及嵌入名称配置。
- PE 资源目录含类型 16（`RT_VERSION`），目录数据区长度 1012 字节。本件交付缺对应重建输入。

提供清理后的 C#、内嵌 XML 的可核验重建输入、逻辑资源名及 PE 版本资源输入。复验时核对 XML 名称与原件内容指纹、嵌入配置及方法覆盖。 Windows 运行对照留到后续阶段。
