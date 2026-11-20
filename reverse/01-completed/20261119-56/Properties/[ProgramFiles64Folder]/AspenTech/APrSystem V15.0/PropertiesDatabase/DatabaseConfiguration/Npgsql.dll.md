# Npgsql.dll

独立 Aspen Properties V15.0 x64 的 DatabaseConfiguration 使用 DBASEC~4.cab 成员 `npgsql.dll.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`。文件版本和程序集版本均为 8.0.3.0，大小为 1,415,208 字节，SHA-256 为 `50e3a31230c937d9297b75118427e0998da52ef1915aa53d5b08b424d8960818`。AspenTech Authenticode 签名有效。经校验和与证书表归一化，原件剩余字节与 Npgsql 8.0.3 的 net8.0 包成员完全一致。[安装包来源](evidence/sources.json) · [NuGet 包](https://www.nuget.org/packages/Npgsql/8.0.3) · [来源及 PE 对照](evidence/pe-and-provenance.json)

**已通过静态验收。** 逐令牌核对 7,256 个方法定义，7,132 个方法体的规范化 IL 全部匹配，29 条托管字符串及 Windows 版本资源均逐字节复现。 另外 124 个方法为 96 个抽象声明和 28 个由运行时提供实现的委托成员。32,464 条语义元数据记录和 12 份字段初始化数据一致。原件资源只含托管字符串和 PE 版本信息。[方法令牌](evidence/methods.csv) · [验收证据](evidence/acceptance.json)

归档 C# 取自 NuGet 记录的 PostgreSQL 许可上游提交，合并了 .NET 8 活动分支、SDK 程序集属性和两个源生成器的输出。按 PE 调试目录中的 SHA-256 核验原版 Portable PDB，确认原版使用 Roslyn 4.9.2 和 C# 12 Release。归档以同版编译器、Nullable、unsafe、.NET 8.0 引用程序集及 Microsoft.Extensions.Logging.Abstractions 8.0.0 回编。程序集名设为 Npgsql，强名称签名使用上游项目的签名输入，嵌入 RESX 生成的资源并保留逻辑名 `Npgsql.Properties.NpgsqlStrings.resources`。使用 SDK 项目回编时关闭重复程序集属性及目标框架属性生成。归档 C# 已包含源生成器的输出和现有版本属性。[上游提交](https://github.com/npgsql/npgsql/tree/c5aab163a27a328af4cdb2e2285c7dcc46b2d1d8) · [许可](LICENSE.txt)

AspenTech Authenticode 签名、Windows 加载及与 PostgreSQL 的实际交互留到 Windows 重建阶段验证。DatabaseSetup 另有同名同版本文件，清单 SHA-256 不同，另轮核对。

文件 SHA-256 为 `6fe6576f0ac399f488da77ff984e7f41b9784ef3079554704c7ed7c04819bf43`。
