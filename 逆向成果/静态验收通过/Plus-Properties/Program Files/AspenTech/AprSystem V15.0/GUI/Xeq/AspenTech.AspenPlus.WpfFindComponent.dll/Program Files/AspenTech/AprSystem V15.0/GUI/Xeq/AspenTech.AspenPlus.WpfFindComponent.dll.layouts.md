# AspenTech.AspenPlus.WpfFindComponent.dll.layouts.zip

第 20261119-07 轮，整件静态归档状态为**已完成**。本件由 Aspen Plus 和独立 Aspen Properties 共用。

原件安装路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.WpfFindComponent.dll`，版本为 `41.0.0.614`，SHA-256 为 `04e68b8eca60b732e661bf322d74b6f042abeba9ea801e2e2e410c1be007b5d5`。两套安装介质的主件均来自各自的 `APRS~479.cab`，英文资源卫星来自各自的 `APRS~409.cab`。读取两份 MSI 文件表和介质表，复核当前柜指纹，并按成员键复用了各自原包的已解包成员指纹。来源与行号见本轮 `identity.json`。

ZIP 含 27 份可编辑页面、themes/generic.xaml、6 张 PNG 以及 index.json。资源来源为主程序集相邻的 en-US 卫星（SHA-256 为 7c7a2c502fbf2d967bf169e1b7d46ac6ce04ecc3b189d71d529f347af363f03f）。WPFForms/en-US 的同名异哈希卫星在 identity.json 单独登记。

按资源流恢复 1,146 个对象与 335 个复合属性。主件发出的 27 个页面 URI 与布局逐项匹配，主题独立登记。包内索引列出 229 个控件或样式连接、224 处字段关联、87 条由连接器接入的事件（含 5 条样式事件）及 15 条直接写入布局的事件。已用主件的连接器指令核对分支，再把处理方法的令牌关联到正式 C#。8 处图片引用覆盖全部 6 个 PNG。逐项核对了 ZIP 内容、XAML 语法结构、图片与布局指纹。

布局中有 176 个 Binding、1 个 MultiBinding、1 个框架变量路径及 28 处 TemplateBinding。逐条绑定的上下文、能在原件定位的属性与外部取值边界见 bindings.json。SFEAssistantStep2 的 ChemName、ExistingChemistry 与 ExistChemName 使用继承的数据上下文，Loaded 处理方法另有手工赋值；实际取值和显示顺序留待 Windows 对照。

下一步在 Windows 重建对照阶段复验宿主提供的数据上下文、页面交互、实际加载的程序集版本及联网查询结果。本轮验收依据为原文件静态恢复。

本份成果 SHA-256 为 `9d94c8a025e246088ecf19513d59c7133c63b3ed10684a0dcf40f9d6448c4c5e`。轮次根目录的 `signoff.json` 同时登记成果、同名说明和验收证据的指纹。
