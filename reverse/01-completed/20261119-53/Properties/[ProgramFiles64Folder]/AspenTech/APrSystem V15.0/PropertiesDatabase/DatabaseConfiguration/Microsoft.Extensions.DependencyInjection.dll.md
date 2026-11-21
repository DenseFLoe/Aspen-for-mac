# Microsoft.Extensions.DependencyInjection.dll

独立 Aspen Properties V15.0 x64 的 DBASEC~9.cab 成员为 `microsoft.extensions.depende5.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`。文件版本为 8.0.23.53103，程序集版本为 8.0.0.0，大小为 92,320 字节，原件 SHA-256 为 `8d6e7b64cce554f0a0fbdb2ba80745895fa0b4e6cc378b9fedfe8ce86f0d8ae4`。本轮提取的 CAB 成员与微软 NuGet 8.0.0 net8.0 DLL 逐字节一致，原件 Authenticode 签名有效。NuGet 包的 SHA-512 与目录登记一致。此哈希对应独立 Aspen Properties 的 1 条清单来源。[来源记录](evidence/sources.json) · [微软 NuGet 包](https://www.nuget.org/packages/Microsoft.Extensions.DependencyInjection/8.0.0)

**已通过静态验收。** C# 覆盖服务容器、按键解析、作用域、释放逻辑和服务调用引擎。逐项核对 68 个类型、173 个字段、106 个属性和 418 个方法定义。409 个方法体的规范化 IL 全部匹配，另有 9 个原版抽象方法声明。1,672 条元数据记录一致，包括泛型约束、接口实现及 ServiceCollection 向 Abstractions 程序集的类型转发。两项托管资源和一项 Windows 版本资源逐字节复现。PE 与资源清单中均无布局资源。[逐方法令牌](evidence/methods.csv) · [验收证据](evidence/acceptance.json) · [PE 对照](evidence/pe-comparison.json)

可编辑 C# 合并了微软包所指向的 MIT 源码，并补齐程序集属性和资源访问器。按上游项目先合入 ParameterDefaultValue.netcoreapp.cs，再合入 ParameterDefaultValue.cs，以复现本地函数的生成成员名称。复核使用 ILSpy 9.1.0.7988、Roslyn 4.8、C# 12 Release、.NET 8 引用程序集和第 52 轮核实的 Abstractions.dll。重建时用 RESX 生成 FxResources.Microsoft.Extensions.DependencyInjection.SR.resources，并以原逻辑名称嵌入该资源及 ILLink.Substitutions.xml。[上游源码](https://github.com/dotnet/runtime/tree/5535e31a712343a63f5d7d796cd874e563e5ac14/src/libraries/Microsoft.Extensions.DependencyInjection)

静态回编件未签名。正式签名、Windows 加载、服务解析、实际释放顺序及裁剪行为留到重建阶段验证。

文件 SHA-256 为 e7725d6bf2ae1e8000158fe63df4b3137e51c319893811f1a1417da6029e912b。
