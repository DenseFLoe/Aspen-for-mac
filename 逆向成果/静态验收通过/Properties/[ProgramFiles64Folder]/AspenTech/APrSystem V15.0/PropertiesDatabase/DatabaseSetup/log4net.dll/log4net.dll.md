# log4net.dll

独立 Aspen Properties V15.0 x64 的 DatabaseSetup 使用 `DBMGR4~2.cab` 中的 `log4net.dll.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`。文件与程序集版本均为 2.0.17.0，大小为 272,424 字节，SHA-256 为 `2af48761d784d3c3b44eb0cf592e96aa2fee7dbc570c62e05db147198ff8f86c`。Windows 签名检查返回 `Valid`，签名者为 Aspentech Corporation。[安装来源](evidence/sources.json)

**已通过静态验收。** 逐令牌核对 2,152 个方法定义，1,956 个方法体的规范化 IL 全部吻合，Windows 版本资源逐字节一致。 另有 154 个抽象方法、32 个运行时委托方法和 10 个 P/Invoke 声明，均与原件对应。7,878 条语义元数据记录和一个字段的 RVA 数据全部匹配。原件没有托管清单资源。P/Invoke 的入口、库名和标志已核对。[验收证据](evidence/acceptance.json) · [逐方法记录](evidence/methods.csv)

原件与 NuGet 包内的 `lib/netstandard2.0/log4net.dll` 在去掉证书表并将 PE 校验和及 Security Directory 归零后逐字节相同。C# 取自 NuGet 指定的 Apache 发布提交，保留 .NET Standard 2.0 发布构建的生效条件分支，合并源文件并补上构建生成的 TargetFramework 属性。原 `DebugAppender.cs` 的局部 `DEBUG` 通过合并源码顶部的定义保留条件调用，全部方法均在该设置下回编核验。[Apache 发布源码](https://github.com/apache/logging-log4net/tree/6af6316c3f094e8b85da6a8750cba0b3dcf162d3) · [NuGet 2.0.17](https://www.nuget.org/packages/log4net/2.0.17)

静态回编使用 Roslyn 4.0.1、`NETStandard.Library` 2.0.3 的 `build/netstandard2.0/ref` 引用、`System.Configuration.ConfigurationManager` 和 `System.Security.Principal.Windows` 4.5.0 的 `ref/netstandard2.0` 引用，以及 Apache 上游的 `log4net.snk` 强名称输入。编译目标为库，启用优化、确定性输出和 portable PDB，PE 基址 285212672、文件对齐 4096。版本资源由编译器从程序集属性生成。

Windows 加载、第三方和原生依赖绑定、日志行为与 Authenticode 签名处理留到 Windows 重建阶段核对。

文件 SHA-256 为 `e3331c158a93d8b9eaaf83def3c7696c300f98496856d90ba23ff3339f03b41a`。
