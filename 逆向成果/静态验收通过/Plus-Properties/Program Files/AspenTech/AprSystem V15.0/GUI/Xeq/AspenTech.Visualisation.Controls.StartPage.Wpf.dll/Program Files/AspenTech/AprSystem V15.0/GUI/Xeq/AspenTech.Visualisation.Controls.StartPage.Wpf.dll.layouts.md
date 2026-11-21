# AspenTech.Visualisation.Controls.StartPage.Wpf.dll 布局与资源

第 20261119-08 轮。Aspen Plus 与独立 Aspen Properties 共用此件。静态资源恢复与连接核验通过。原路径为 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Visualisation.Controls.StartPage.Wpf.dll`，文件版本和程序集版本均为 `31.0.0.5`，PE 产品版本字段为 `V14.0`。主件 SHA-256 为 `73193ded5722619da8d661035129f6a38968acad4ce371de83f0cc8158950b34`。两个产品的原包记录和同哈希安装件见本轮根目录 `identity.json`。

同目录 `AspenTech.Visualisation.Controls.StartPage.Wpf.dll.layouts.zip` 的 SHA-256 为 `f6d3d3fb1fb6e269029322583f6729f63326c466061fda7761d477d1cb544732`。包内有 5 个 XAML、10 张原始 PNG，以及中性、日语、俄语和简体中文共 4 份 RESX。各套有相同的 20 个文本键。中性文本读取自主件，另三套来自相邻 `ja-JP`、`ru-RU` 和 `zh-Hans` 的卫星程序集。文本值逐项核对；原始清单名、主件和卫星的指纹、各输出指纹见轮次根目录 `bindings.json`。

| 页面 | 连接号 | 其中链接单击事件 | 布局绑定 |
| --- | ---: | ---: | ---: |
| GetStartedSidebar | 2 | 1 | 7 |
| LinkGroupSidebar | 2 | 1 | 7 |
| MRUSidebar | 3 | 2 | 13 |
| RssFeedView | 5 | 1 | 16 |
| StartPage | 4 | 1 | 8 |

使用 Windows PowerShell 5.1、.NET Framework PresentationFramework 4.0 的 BamlReader 和 Mono.Cecil 0.11.6。在每个 BAML 的 EndDocument 核对流已读至末尾，用各页面 InitializeComponent 中含程序集版本的 URI 回连代码。16 个连接号对应 10 个命名字段和 6 个模板内 Hyperlink.Click 订阅，按 IL 分支、字段、处理方法令牌核对。代码另外订阅页面加载与卸载、密码更改、按键和定时器事件。51 项布局绑定逐项关联元素名、模板数据类型或 DataContext 和属性 getter。StartPage.AddRssFeed 另建立一项从 RssFeed.Title 到选项卡标题的 OneWay 绑定。ImageResources 的 9 个图像属性及 RssFeedView 的刷新按钮覆盖全部 10 张图片。20 个文本键分别对应 Resources 的属性和 GetString 参数。

5 个页面合并外部的 AspenCommonResources 和 AspenCommonStyles。StartPage 中的 AspenTabControlStyle 保留原资源键，由 WPF 查找。Windows 重建时再对照宿主样式、文化回退、链接与命令、RSS 显示与刷新、输入及绑定的实际效果。本轮只做静态核验。布局与代码都保留连接依据，重建时应协调 XAML 所生成的连接代码与已恢复的连接方法。

逐页字段与事件令牌、绑定路径、图片调用点、资源清单和工具指纹位于 `bindings.json`。局部工作目录 `.local/reverse-work-20261119-08-layout/` 中的 `read-framework.ps1`、`read-ui.ps1` 和 `package.py` 分别读取 .NET 资源流、提取受查方法 IL、生成布局和核对关系。
