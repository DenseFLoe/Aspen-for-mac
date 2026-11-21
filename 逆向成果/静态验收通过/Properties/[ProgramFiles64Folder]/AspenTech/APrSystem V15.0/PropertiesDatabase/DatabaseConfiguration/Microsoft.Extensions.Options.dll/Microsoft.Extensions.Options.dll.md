# Microsoft.Extensions.Options.dll

独立 Aspen Properties V15.0 x64 的 DBASE~12.cab 成员为 `microsoft.extensions.options2.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`。文件版本为 8.0.23.53103，程序集版本为 8.0.0.0，大小为 64,672 字节，原件 SHA-256 为 `5f9b0e589f1ce9ca656588cd92cc0bd53803fdfad258fb2916aaa14aedce682c`。本轮提取的 CAB 成员与微软 NuGet 8.0.0 net8.0 DLL 逐字节一致，原件 Authenticode 签名有效。缓存包的 SHA-512 与 NuGet 目录一致。[来源记录](evidence/sources.json) · [微软 NuGet 包](https://www.nuget.org/packages/Microsoft.Extensions.Options/8.0.0)

**已通过静态验收。** C# 覆盖选项注册与配置、按名创建与缓存、变更通知、启动验证和验证结果。按签名和定义令牌核对 79 个类型、188 个字段、120 个属性、1 个事件和 354 个方法定义。其中 17 项为抽象接口声明，其余 337 个方法体的规范化 IL 全部匹配。独立核对的 1,710 条元数据记录一致，覆盖接口实现、泛型约束、显式方法映射和自定义特性。两项托管资源与一项 Windows 版本资源逐字节复现。原件没有布局资源。[逐方法令牌](evidence/methods.csv) · [验收证据](evidence/acceptance.json) · [PE 对照](evidence/pe-comparison.json)

C# 合并了 NuGet 清单所指向提交的 36 个 MIT 许可源文件，按原件补齐程序集属性和生成的资源入口。用 Roslyn 4.8、Microsoft.NETCore.App.Ref 8.0.0 及与安装包清单指纹一致的 Microsoft.Extensions.Primitives 和 Microsoft.Extensions.DependencyInjection.Abstractions 回编。重建时以 FxResources.Microsoft.Extensions.Options.SR.resources 和 ILLink.Substitutions.xml 为逻辑名嵌入资源。[上游源码](https://github.com/dotnet/runtime/tree/5535e31a712343a63f5d7d796cd874e563e5ac14/src/libraries/Microsoft.Extensions.Options)

回编件未签名。正式签名、Windows 下的程序集绑定、选项配置与验证、回调及裁剪行为留到重建阶段验证。

文件 SHA-256 为 2bb69823954672c20a3fcbed81fd6ab9d0b6cc7b22d6cdcb305468f3a56cc7d1。
