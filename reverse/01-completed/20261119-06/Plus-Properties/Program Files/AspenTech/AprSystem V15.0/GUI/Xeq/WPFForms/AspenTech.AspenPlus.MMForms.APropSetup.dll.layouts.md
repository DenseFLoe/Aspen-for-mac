# AspenTech.AspenPlus.MMForms.APropSetup.dll.layouts.zip

第 20261119-06 轮，原版逐文件逆向归档已完成。Aspen Plus 与独立 Aspen Properties 共用本件。

原安装路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.APropSetup.dll`，版本 `41.0.0.614`，原件 SHA-256 为 `6287a414f51e5c0288a096e4614fa892cc76b030fe536b4f43a6ca7331c231e0`。两产品各自 MSI 的 APRS~369.cab 成员与安装件逐字节一致。两个原包的英文卫星均在各自的 APRS~341.cab。轮次根目录 identity.json 记录 MSI、CAB、成员、序号和指纹。

资源卫星 en-US/AspenTech.AspenPlus.MMForms.APropSetup.resources.dll 与主件同版，SHA-256 为 20219eed072f1ddef122750b88e472449d7025f28ba70e023a8f830b60c83fde。主件把默认英文资源委派给该卫星，卫星内有一套托管资源、0 个方法定义。Windows PowerShell 5.1 经 WPF BamlReader 读取 22 个编译布局，重建 22 页可编辑 XAML。每页保存控件树、属性和资源表达式。包内 index.json 的 pages 按页列出源 BAML 指纹、XAML 指纹、原组件 URI、类、连接 ID、字段和 IL 偏移；implicit_content 保存隐式内容所属成员。主件与卫星各有一项 Win32 版本资源。

用 Mono.Cecil 0.11.6 核对页面构造器、加载方法和 Connect 方法，22 页与源码一一对应。243 个控件连接与字段和分支匹配，7 个显式 WPF 绑定和 126 个变量路径定位到当前或继承的属性。账户页还在构造器中连接用户名控件的 LostFocus。三个 SimulationN.Value 表达式由返回 object 的本地属性继续在运行时取 Value；本地化文案和两个外部页签标识按其原接口引用保留。

报告默认页的 lbtuLines_label 指定 lbtuLines 为目标，同页命名字段里只有相邻的 spnLine 控件与此处相关。已回查同一布局的历史读取记录和原件字段，XAML 保留原始 lbtuLines。Windows 对照阶段应实际检查该标签的焦点行为。

本份成果 SHA-256 为 `c52d773e848363e4feaa964cfc20a2368397eb3bea68a5adf898c3a7ecaa5d21`。本轮 signoff.json 关联正式成果、说明和验收证据。当前判定限于静态恢复；实际界面、模型写回和运行行为留待 Windows 重建对照阶段。
