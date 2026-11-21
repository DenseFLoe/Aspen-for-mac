# AspenTech.Engineering.Controls.FileMenu.dll · 布局与资源

第 20261119-09 轮，布局与资源已通过静态归档验收。Aspen Plus 和独立 Aspen Properties 均安装此程序集。原路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Engineering.Controls.FileMenu.dll`，文件与程序集版本均为 `15.0.0.0`，原件 SHA-256 为 `db81bd19b9a31b5a560fe0c91ef62ce66d79e768a8d17809e32f618da5814b2f`。轮次根目录的 `identity.json` 记录两套 MSI 和各自 `APRS~610.cab` 的主件来源。

## 布局与资源

同目录 `AspenTech.Engineering.Controls.FileMenu.dll.layouts.zip` 的 SHA-256 为 `9c60c6d0a1f6e32349f04235767bd295f414eabb109675273e2bf4f4b4ccf983`。包内有 5 份 XAML 和 1 份 RESX。三个页面可由代码中的 `InitializeComponent` 加载地址定位，两个字典保留原名。

| XAML | 用途及验收依据 |
| --- | --- |
| `filemenucontrol.xaml` | 菜单的滚动容器与 `ContentPanel` 字段相连。页面引入同一程序集的 `TemplatesResource.xaml`。 |
| `filemenuitem.xaml` | 单项控件原布局包含空字典和空 Grid。构造方法安装模板选择器，宿主提供的数据通过 `Content` 交给该控件。 |
| `aspenplustemplatesselector.xaml` | 模板分类、模板列表及单位制控件分别对应 `CatagoryList`、`TemplateListView` 和 `MetC`。BAML 直接声明的 `SelectionChanged` 已定位到方法令牌 `0x06000009`。 |
| `templatesresource.xaml` | 包含 17 组可由 `ItemTemplateType` 选择的内置数据模板，以及关联的样式、转换器和嵌套模板。按同名资源键及枚举数值，将每组模板与注册和选择方法对应。 |
| `ribbon.xaml` | 独立的颜色字典，含 324 个有名颜色。主件另外四份布局和代码字符串中均未找到指向本字典的 URI。 |

原件另有空的中性清单资源 `AspenTech.Engineering.Controls.FileMenu.Properties.Resources.resources`。`ResourceManager` 的基名与此清单匹配，按原始零键导出 RESX。已检查两个产品的安装包成员清单和安装目录，相邻文件中无同名区域性卫星。

## 核验方法和边界

使用 Windows PowerShell 5.1.20348.5756、.NET Framework 4 的 ResourceReader 和 WPF BamlReader 读取主件的两项资源清单。五个 BAML 均读到 EndDocument 和流尾。按读取的对象、复杂属性、集合内容、构造参数和文本恢复 XAML，再使用带本程序集上下文的 System.Xaml.XamlXmlReader 静态读取五个输出，均可解析对象类型与成员。以 Mono.Cecil 0.11.6 读取连接方法和字段令牌。ZIP 条目已读回核验。

四个连接号分别对应四个命名字段，另核对布局声明的一个事件与构造函数中的四处事件订阅。对 236 个 Binding 和 5 个 MultiBinding 逐项记录其目标和数据来源，核对命名元素的模板作用域、祖先控件和菜单数据模型，并记录多重绑定的输入及转换器。90 处 StaticResource 查找可在相应作用域内定位到资源，53 处 TemplateBinding 指向模板化父控件属性，5 处 DynamicResource 指向 WPF 系统颜色键。

轮次根目录 `bindings.json` 按页面登记输入和输出指纹、原对象节点、方法与字段令牌、命名控件、绑定来源、模板注册与资源键。该证据的 SHA-256 为 `a23bcf7a7f145a21c54e7ecc130ae1a0bcc399ddaa276d635450211f08bf70cd`。

本件的菜单输入是 `FileMenuItemData`。宿主可设置条目、命令参数、图像及自定义模板。后续 Windows 重建时对照实际菜单渲染、命令执行、单位制选择、滚动响应及系统颜色取值。
