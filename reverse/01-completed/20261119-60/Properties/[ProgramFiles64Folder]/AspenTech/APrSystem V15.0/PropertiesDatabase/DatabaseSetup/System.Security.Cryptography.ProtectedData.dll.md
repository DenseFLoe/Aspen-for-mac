# System.Security.Cryptography.ProtectedData.dll

独立 Aspen Properties V15.0 x64 的 DatabaseSetup 原件来自 DATABA~4.cab 中的 system.security.cryptography.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D。文件版本 4.6.26515.6，程序集版本 4.0.3.0，大小 25,232 字节，SHA-256 为 `80566f0839ece5946e66bf9f00d723e59e371ba1341a18e00c7c7a7c49298e1d`。原件签名显示有效，签名者为 Microsoft Corporation。原件与 Microsoft NuGet 4.5.0 包的 `lib/netstandard2.0/System.Security.Cryptography.ProtectedData.dll` 逐字节一致。[安装来源](evidence/sources.json) · [Microsoft NuGet 4.5.0](https://www.nuget.org/packages/System.Security.Cryptography.ProtectedData/4.5.0)

**已通过静态验收。** 14 个方法体的规范化 IL、65 条语义元数据记录、托管字符串资源和 PE 版本资源均吻合。 覆盖 5 个类型和 14 个 IL 方法体，逐令牌记录每个方法及其回编位置。程序集只有一项外部引用，即 netstandard 2.0。原件没有原生导入或类型转发。[逐方法核对](evidence/methods.csv) · [验收记录](evidence/acceptance.json)

`Protect` 和 `Unprotect` 在原件里均读取资源字符串后抛出 `PlatformNotSupportedException`。NuGet 包另有不同指纹的 Windows 专用资产，其 IL 声明确实引用 `crypt32.dll` 的两个 DPAPI 入口。本轮限定于 Aspen 安装包指纹匹配的通用 DLL。DatabaseSetup 实际装载哪个文件、是否进入数据保护分支及其行为，留到 Windows 重建对照阶段核实。[包内资产核对](evidence/asset-boundaries.json)

C# 由 ILSpy 导出后校正资源标记类型的限定名，并让编译器再生成调试、模块及声明式安全属性。回编用 Roslyn 2.8.2、C# 7.3、NETStandard.Library 2.0.3 引用、`/optimize+ /debug:portable /debug+ /unsafe+ /deterministic+`。读取原 DLL 的公开强名称键进行延迟签名，用完整程序集原名作为输出名。用 ResourceWriter 从 `Strings.resx` 的两个字符串生成 `FxResources.System.Security.Cryptography.ProtectedData.SR.resources` 并嵌入。Windows 版本资源由程序集属性生成，1,476 字节逐字节吻合。[版本资源核对](evidence/windows-version.json) · [CoreFX 源码](https://github.com/dotnet/corefx/tree/30ab651fcb4354552bd4891619a0bdd81e0ebdbf)

文件 SHA-256 为 `03284f17bcae5372ada8cec7e6925c2470f8bd309b9a4ed089f7c52ad0d8605a`。
