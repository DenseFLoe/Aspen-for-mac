# findvariabledlg.xaml

Aspen Plus 与独立 Aspen Properties V15 的英文（美国）配套卫星为 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/en-US/AspenTech.AspenPlus.MMDialogs.resources.dll`，版本 41.0.0.614，SHA-256 为 `a77f3ab9413ee939e7f333a8fd4b971453c51ee5df436774d34469fb66585e73`。布局成员 `findvariabledlg.baml` 位于 `AspenTech.AspenPlus.MMDialogs.g.en-US.resources`，原长 4,222 字节，SHA-256 为 `61a6e82e9406da9874fa6ab04a3ea3a05afedc8855897c988702a70d7219e8f2`。[来源核对](../../../../../../../evidence/satellite-identity.json)

主库 `AspenTech.AspenPlus.MMDialogs.FindVariableDlg.InitializeComponent`（`0x060001E2`）按 URI `/AspenTech.AspenPlus.MMDialogs;component/findvariabledlg.xaml` 加载本页。完整可编辑 XAML 为 5,735 字节，SHA-256 为 `4e6c18e42128730f0c32c21375fb0285b7522a08a6157b3fd25ad1a56652f9fc`。本页通过静态验收。WPF 标记编译器回编后逐对象读回，已对齐 39 个对象、5 个连接号、4 个字段、3 次事件注册、9 个 Binding 和 0 个 MultiBinding。[逐页核对](../../../../../../../evidence/ui-pages.csv) · [控件与事件](../../../../../../../evidence/ui-connections.csv) · [绑定](../../../../../../../evidence/ui-bindings.csv)

常规 XAML 阅读器将列表上的 `ButtonBase.Click` 标为未知成员。原版连接器 `0x060001E3` 在连接号 4 读取 `ButtonBase.ClickEvent`，调用 `UIElement.AddHandler` 注册 `GridViewColumnHeaderClickedHandler`（`0x060001E0`）。WPF 标记编译器生成了相同的路由事件和处理函数。[路由事件核对](../../../../../../../evidence/ui-audit.json)

Windows 重建阶段再对照宿主中的显示、数据取值与操作。
