# AspenTech.ActivationDashboard.EnergyAnalysis.dll 静态验收

2026-11-21，三组第 2 轮。结论为**静态验收未通过**，交入修复清单，复验组为 3。

原路径为 `Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/Modules/AspenTech.ActivationDashboard.EnergyAnalysis.dll`。原件 SHA-256 为 `02c6189882943dedf7f1fb3877e86b07b6297dd87c57d02a99649dbd8a1e1a5c`。

原件来自 Aspen Plus V15 安装包 `ASPE~293.cab` 的成员 `aspentech.activation2.D470D1DF_9FE5_4F3E_9EF6_CEAA577688D0`，共 256,552 字节。原件为 I386 IL-only，程序集和文件版本均为 41.0.0.19。复用已有安装包提取件，按 SHA-256 核对到本组清单。

## 核对结果

- 用 PowerShell 7.6.9 的 `System.Reflection.Metadata` 和 `PEReader` 从原件逐项读取 MethodDef、RVA 和方法体。与 W2 IL 清单逐条对照，122 个定义和 5,142 个 IL 指令字节一致。121 个定义有方法体，`IEALanding.OnOpen`（`0x0600000F`）为原件的抽象声明。原件还有 15 个 TypeDef（包含模块项）、30 个 FieldDef。
- 用 ILSpy 9.1.0.7988 重新导出 C#。统一换行后，正式导出仅在文件末尾多了两行 ILSpy 版本更新提示。C# 的 SHA-256 为 `3e4c95a6774dba8265a878ec52f20cbc370c1413cf48fa4e19555ee930ebfe8b`，IL 清单为 `a339b909df4258dea2ac1c31b80e4d4dbd206837c7afdc0ef8bd18eccdcd7d0d`。
- 原件的 `AspenTech.ActivationDashboard.EnergyAnalysis.g.resources` 为 212,024 字节，SHA-256 为 `3dbc7143b4be5995063daaab78ca0f9da94333a83ffcc6794722507f1b5f27c2`。其条目为 `activationform.baml`、`dashboarditem.baml`、`images/energy_compressed_panel.png` 和 `images/energy_expanded_panel.png`。C# 中两个 `InitializeComponent`（`0x06000007`、`0x0600003E`）仍通过 `Application.LoadComponent` 引用对应的 `.xaml` 路径。交付中没有对应的布局和图片。
- 原件的 `AspenTech.ActivationDashboard.EnergyAnalysis.Properties.Resources.resources` 为 4,213 字节，SHA-256 为 `4f6949cc735217900cd772a699e729e5b8b82c516bd1fa6ba1a9f3ac5bc6ee9c`。其中 34 个键包括 `DashboardItem_Title`，由导出的 `get_DashboardItem_Title`（`0x0600005F`）调用 `ResourceManager.GetString` 读取。交付包含访问器，缺少对应本地化资源定义。

## 复查与修复

从原件的 CLR 资源目录按 `ManifestResource.Offset` 读取嵌入项，先读四字节长度，再用 `ResourceReader` 枚举键。修复时恢复两个可编辑布局及其中的控件、事件和绑定，补齐图像引用和本地化资源，并去掉 C# 末尾的工具提示。Windows 界面与交互对照留待后续阶段。
