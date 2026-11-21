# SetupAPEDPostgreSQLDatabases.dll

独立 Aspen Properties V15.0 x64 的 DatabaseSetup 原件来自 `DATABA~5.cab` 的 `setupapedpostgresqldatabases1.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`。文件和程序集版本均为 1.0.0.0，大小 31,784 字节，SHA-256 为 `23b8382cb0cdeaef90ed631d4542fbd018a9100bc33ed7d436deff594ffeda3f`。[安装来源](evidence/sources.json)

**已通过静态验收。** 37 个方法体的规范化 IL、171 条语义元数据记录和两项 PE 资源均吻合。 覆盖 3 个用户类型、22 个字段、1 个属性及入口点 `06000001`。9 个程序集引用和 106 个外部成员引用均静态解析成功，其中 14 个成员来自同目录的 Npgsql 和 log4net。PE 入口是标准 CLR 引导，托管实现无 P/Invoke。两项 PE 资源为版本信息与应用清单。[逐方法核对](evidence/methods.csv) · [验收记录](evidence/acceptance.json) · [绑定证据](evidence/binding-audit.json) · [资源证据](evidence/pe-resources.json)

用 ILSpy 9.1 导出 C# 和原 IL。依照原 IL 恢复 `String.Format` 调用及分支顺序，并由编译器生成模块属性。Roslyn 4.8 用 C# 12、.NET 8.0.0 引用和原安装依赖生成临时比对 DLL。

完整 C# 和原 IL 含硬编码凭据，仅本地保留。GitHub 归档包括应用清单、说明及验收证据。Windows 启动链、注册表访问、数据库连接及恢复行为留到重建阶段对照。[发布范围与指纹](evidence/publication-scope.json)

对应文件 SHA-256 为 `04283237feaef5c71a7b737883e7aa51a3781c5076bdcfdc034266c1bf4c827e`。
