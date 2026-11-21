# Microsoft.Extensions.Configuration.dll

独立 Aspen Properties V15.0 x64 的 Micros~2.cab 中的成员为 microsoft.extensions.configu6.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D，文件版本为 8.0.23.53103，程序集版本为 8.0.0.0，大小为 43,800 字节。原件 SHA-256 为 b5cd9da2c3364a5b201cecb0c80e25227d27ba44d96343d2894ff8ef3fd81550。微软 NuGet 8.0.0 的 lib/net8.0/Microsoft.Extensions.Configuration.dll 与原件逐字节一致，原件 Authenticode 签名有效。所下载包的 SHA-512 与 NuGet 目录一致。部署清单记录了另一包级指纹，DLL 身份由直接比较确认。[来源](evidence/sources.json) · [微软 NuGet 包](https://www.nuget.org/packages/Microsoft.Extensions.Configuration/8.0.0)

**已通过静态验收。** C# 覆盖配置构建、内存和流提供者、配置链、配置键排序、变更回调、调试视图和提供者引用计数。用 ILSpy 9.1.0.7988、Roslyn 4.8 和 Mono.Cecil 核对 34 个类型、55 个字段、56 个属性和 220 个方法定义。7 个定义为抽象声明。213 个方法体中，194 个规范化 IL 一致，19 个差异已核对分支、局部变量、异常区间和调用顺序。[逐方法令牌](evidence/methods.csv) · [验收证据](evidence/acceptance.json)

资源管理器显式引用原件的 FxResources 标记类型。复用确切上游提交中的配置键比较器后，两个局部函数的生成名称和比较器全部 7 个方法体与原件一致。两个托管资源和 Windows 版本资源均逐字节复现。原件没有窗体或布局资源。源码和资源随 MIT 许可及第三方声明归档。[上游源码](https://github.com/dotnet/runtime/tree/5535e31a712343a63f5d7d796cd874e563e5ac14/src/libraries/Microsoft.Extensions.Configuration)

重建时用 Microsoft.NETCore.App.Ref 8.0.0、Microsoft.Extensions.Configuration.Abstractions 8.0.0 和 Microsoft.Extensions.Primitives 8.0.0 编译。使用 Roslyn 4.8 的 C# 12 Release 和 nullablePublicOnly 选项，以 FxResources.Microsoft.Extensions.Configuration.SR.resources 和 ILLink.Substitutions.xml 为逻辑名嵌入资源。本轮采用未签名的静态回编件核对。内部 System.SR 的可空注解有 6 处编译器元数据放置差异，记录在验收证据中。程序集签名和 Windows 下的加载、配置重载、回调及释放行为留到重建阶段验证。

文件 SHA-256 为 bde8c7f07f48e8e17cd085daa311b8d645fdff663376fbc8e6b7f54aee1a4507。
