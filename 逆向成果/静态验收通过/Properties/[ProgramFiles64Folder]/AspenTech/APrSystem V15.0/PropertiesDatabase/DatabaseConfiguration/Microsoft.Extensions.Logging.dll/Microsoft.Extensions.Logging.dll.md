# Microsoft.Extensions.Logging.dll

独立 Aspen Properties V15.0 x64 的 DBASE~11.cab 成员为 `microsoft.extensions.logging5.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`。文件版本为 8.0.23.53103，程序集版本为 8.0.0.0，大小为 50,848 字节，原件 SHA-256 为 `4330a5efe9d110afb7f8e567d5b43eee976e0f7f6802d13a211b65d747529179`。本轮提取的 CAB 成员与微软 NuGet 8.0.0 net8.0 DLL 逐字节一致，原件 Authenticode 签名有效。NuGet 包的 SHA-512 与目录登记一致。此哈希对应独立 Aspen Properties 的 1 条安装包来源。[来源记录](evidence/sources.json) · [微软 NuGet 包](https://www.nuget.org/packages/Microsoft.Extensions.Logging/8.0.0)

**已通过静态验收。** C# 覆盖日志工厂、提供程序注册、过滤规则、作用域及 Activity 追踪。58 个类型（含编译器生成类型）、106 个字段、49 个属性及 230 个方法定义均匹配。230 个方法体的规范化 IL 全部匹配。992 条元数据记录一致，含转发至 Microsoft.Extensions.Logging.Abstractions 的 ILoggingBuilder、类型约束、方法覆盖和程序集属性。两项托管资源和一项 Windows 版本资源均逐字节复现。PE 和托管资源清单均无界面布局。[逐方法令牌](evidence/methods.csv) · [验收证据](evidence/acceptance.json) · [PE 对照](evidence/pe-comparison.json)

可编辑 C# 合并 NuGet 包指向的 MIT 上游实现，并按原件元数据补齐程序集属性、类型转发和字符串资源访问器。使用 ILSpy 9.1.0.7988、Roslyn 4.8、C# 12 Release、.NET 8 引用程序集及第 51 至 54 轮验收过的四个微软依赖程序集验证。重建时从 RESX 生成 `FxResources.Microsoft.Extensions.Logging.SR.resources`，以各自原逻辑名嵌入字符串资源和裁剪 XML。[上游源码](https://github.com/dotnet/runtime/tree/5535e31a712343a63f5d7d796cd874e563e5ac14/src/libraries/Microsoft.Extensions.Logging)

静态回编件未签名。正式签名、Windows 加载、日志过滤、作用域行为和裁剪留到 Windows 重建阶段对照验收。

文件 SHA-256 为 c397ccf15d2b503ae85527c950d9bafbe440a811278b04fc7be638c8ce8aeb9b。
