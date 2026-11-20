# Microsoft.Extensions.Primitives.dll

独立 Aspen Properties V15.0 x64 的 DBASE~10.cab 成员为 `microsoft.extensions.primiti2.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`。文件版本为 8.0.23.53103，程序集版本为 8.0.0.0，大小为 43,680 字节，原件 SHA-256 为 `446ff16e903e7479558816e213a3adee9a1c1adad65a56d853801b10933e29d7`。本轮提取的 CAB 成员与已缓存的微软 NuGet 8.0.0 net8.0 DLL 逐字节一致，原件 Authenticode 签名有效。缓存包的 SHA-512 与 NuGet 目录一致。部署清单记录的包级指纹不同，DLL 身份由 CAB 成员直接比对确认。[来源记录](evidence/sources.json) · [微软 NuGet 包](https://www.nuget.org/packages/Microsoft.Extensions.Primitives/8.0.0)

**已通过静态验收。** C# 覆盖变更通知和回调注册、组合令牌、字符串切片、分词、多值字符串、固定指针追加和异常资源。按签名和定义令牌核对了 29 个类型、76 个字段、36 个属性和 227 个方法定义，其中 3 项为接口声明。其余 224 个方法体的规范化 IL 全部匹配，869 个元数据位置的自定义特性也一致。两项托管资源与一项 Windows 版本资源逐字节复现。原件没有布局资源。[逐方法令牌](evidence/methods.csv) · [验收证据](evidence/acceptance.json)

C# 合并了 NuGet 清单所指向提交的 15 个 MIT 许可源文件，并根据原件恢复程序集属性和生成的资源入口。用 Roslyn 4.8 与 Microsoft.NETCore.App.Ref 8.0.0 静态回编，使用 C# 12、`-optimize+`、`-unsafe+`、`-debug:portable`、`-debug+` 和 `-features:nullablePublicOnly`。同时启用优化和 `-debug+` 后，固定指针追加、哈希组合和异常构造四个方法的局部变量与指令也完全匹配。编译时以 `FxResources.Microsoft.Extensions.Primitives.SR.resources` 和 `ILLink.Substitutions.xml` 为逻辑名嵌入资源。[上游源码](https://github.com/dotnet/runtime/tree/5535e31a712343a63f5d7d796cd874e563e5ac14/src/libraries/Microsoft.Extensions.Primitives)

本轮回编件未签名。程序集签名、Windows 下的程序集加载、变更回调、字符串处理及裁剪行为留到重建阶段验证。

文件 SHA-256 为 553e3a15c62eb40f268f9bf08459b3e73ebf00a46e377f230401925e4b5f1a48。
