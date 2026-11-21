# Microsoft.Extensions.Configuration.Abstractions.dll

独立 Aspen Properties V15.0 x64 的 `DBASEC~1.cab` 中的成员为 `microsoft.extensions.configu4.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`，文件版本 `8.0.23.53103`，程序集版本 `8.0.0.0`，27,936 字节。原件 SHA-256 为 `fefcdb267a73099cb90e5af56b5ef2bca59bed974339b3a6810352bde23537a6`。微软 NuGet 8.0.0 的 `lib/net8.0/Microsoft.Extensions.Configuration.Abstractions.dll` 与原件逐字节一致，原件的 Microsoft Authenticode 签名有效。下载包的 SHA-512 符合 NuGet 目录记录，部署清单记录的包级指纹不同。DLL 身份由直接字节比较确认。[来源](evidence/sources.json) · [微软 NuGet 包](https://www.nuget.org/packages/Microsoft.Extensions.Configuration.Abstractions/8.0.0)

状态为**已通过静态验收**。使用 ILSpy 9.1.0.7988 反编译，Mono.Cecil 核对 17 个类型、20 个字段、16 个属性和 68 个方法定义。21 个无方法体的定义都是接口声明。其余 47 个方法体用 Roslyn 4.8、C# 12 Release 回编对照，其中 44 个规范化 IL 一致，3 个差异逐条核对了分支、求值次序和临时变量。覆盖了路径拼接、必需配置节、配置枚举和调试视图。[逐方法令牌](evidence/methods.csv) · [验收证据](evidence/acceptance.json)

反编译稿中同名的 `System.SR` 会遮蔽资源标记类型。已改用类型别名，回编的 `ResourceManager` 构造与原件一致。用 Roslyn 4.8 生成迭代器可保留原件的空 `Dispose`，较新编译器会在其中清空状态和引用。模块的 `RefSafetyRules(11)` 由编译器生成，原件的 `NullablePublicOnly(false)` 记录在源码注释中。

重建时用上游 Microsoft.Extensions.Primitives 8.0.0，嵌入可编辑 RESX 生成的资源以及裁剪替换 XML，并保留对应逻辑名称。两个托管资源与原件逐字节一致，Roslyn 从程序集属性生成的 Windows 版本资源也逐字节一致。C#、资源及所附许可来自 MIT 授权的 .NET 项目。[上游源码](https://github.com/dotnet/runtime/tree/5535e31a712343a63f5d7d796cd874e563e5ac14/src/libraries/Microsoft.Extensions.Configuration.Abstractions)

本轮回编采用本机 .NET 8.0.10 的同标识引用程序集作静态绑定。回编件的签名和模块元数据不同。Windows 重建阶段验证正式依赖绑定、资源加载、枚举和异常行为。

文件 SHA-256 为 `e97735ccebd23abe1085d1f59c6322fb1cd366f8c2009f5eeb00883c4ac14c74`。
