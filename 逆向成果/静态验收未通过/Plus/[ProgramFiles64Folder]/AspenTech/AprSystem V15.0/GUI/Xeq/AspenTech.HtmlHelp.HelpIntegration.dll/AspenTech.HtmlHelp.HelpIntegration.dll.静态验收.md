# AspenTech.HtmlHelp.HelpIntegration.dll 静态验收

2026-11-21，静态验收三组第 3 轮。结论为**静态验收未通过**。

## 原件与交付

- Aspen Plus V15，安装相对路径为 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.HtmlHelp.HelpIntegration.dll`。来自 `APRS~255.cab`，成员 `aspentech.htmlhelp.h1.01AE6323_4069_4985_B882_1C2F459EE258`。
- 原件 25,240 字节，SHA-256 为 `061d5a3a8409b5886baa8ae984b7fbcbcfe09d85c2d8c2444e88a101c3ab2e46`。程序集版本为 `2023.15.0.2`，公钥标记为 `b05689b39deefbcd`，AMD64，IL-only，目标为 .NET Framework 4.8。
- [正式 C# 导出](v0.20261121-w2/正式导出/AspenTech.HtmlHelp.HelpIntegration.dll.cs.txt)的 Git blob 为 `42e2b72fdde3d4ef94d6ccd7ebb23569603d6b2b`，SHA-256 为 `c4f9729656898d7b1b32ed59e413ef9e46f9c05ef8fdd790d4a4998fd7240151`。
- [正式 IL 导出](v0.20261121-w2/正式导出/AspenTech.HtmlHelp.HelpIntegration.dll.il.txt)的 Git blob 为 `00242e62df68f7235410b01531899f044982bd4d`，SHA-256 为 `42b6c853b42c3970db8c915b4fedec52b35a364eb0da0c44c2c2f59cebf41997`。

## 核对结果

- 用 Mono.Cecil 0.11.6.0 和 .NET 8 的 PE 元数据读取原件，计得 7 条 TypeDef（含模块与闭包）、22 个字段、13 个属性和 59 条 MethodDef。用 Python 3.12 以 MethodDef 令牌配对正式 IL 导出和原件，59 个 RVA 一致，41 个方法体的 475 条指令字节及顺序一致。其余 18 个令牌为原件接口声明。原件方法体另有 3 个异常处理区域，复验可直接由方法体头和异常表读取。
- 用 Roslyn 直接解析正式 C# 正文，第 427、428 行的两行 ILSpy 更新提示触发 10 条语法错误，含 `CS1002`、`CS1003`、`CS1012`。仅在临时文本中去掉这两行，再解析得到 0 条语法错误。用 ILSpy 9.1.0.7988 读取原件并核对成员和源码映射，覆盖到 92 个直接标注的令牌。隐式成员包括自动属性字段、`Settings` 构造与静态初始化、由 `ExtHelpLinkForExchange` lambda 产生的闭包。
- C# 第 340–342 行的 ILSpy 类型提示落在 `HtmlHelpIntegrationModule.Initialize`（`0x06000020`）。原 IL 在 `IL_0006` 构造 `ContainerControlledLifetimeManager`，在 `IL_0010` 调用第一项 Unity 注册，`IL_0015` 弹出该调用的返回值。独立导出能够展开为带强类型参数的注册调用。复验时按原件核对两项注册使用的重载及 `CHtmlHelpHelper` 对事件聚合器的解析。
- 原件有一项托管清单资源 `AspenTech.HtmlHelp.HelpIntegration.Properties.Resources.resources`。用 `ResourceReader` 枚举得到 0 个键。容器为 180 字节，SHA-256 为 `e13ed2c59366d0eea74863fd71a81f0cb977cce1edfde304fc538690a4f6ac89`。正式交付缺少能以该逻辑名称重建资源的材料。原件没有 BAML 或 WPF 布局资源。用 pefile 2024.8.26 另确认 PE 中只有版本资源 `16/1/0`，共 1,116 字节，其常规版本字段可见于 C# 程序集属性。

## 复验条件

提交可解析的 C#，处理 Unity 反编译警告并核对上述三个调用的静态绑定。补齐可编辑的空资源定义及嵌入配置，复验时确认逻辑资源名和 0 个资源键。继续核对方法、成员与原件一致性。运行、强名称绑定及界面行为留待 Windows 对照阶段。
