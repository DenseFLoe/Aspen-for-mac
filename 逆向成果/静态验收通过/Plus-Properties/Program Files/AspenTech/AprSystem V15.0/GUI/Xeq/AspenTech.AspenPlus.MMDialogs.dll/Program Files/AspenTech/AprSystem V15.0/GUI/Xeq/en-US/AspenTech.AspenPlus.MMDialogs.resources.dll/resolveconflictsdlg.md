# resolveconflictsdlg.xaml

Aspen Plus 与独立 Aspen Properties V15 的英文（美国）配套卫星为 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/en-US/AspenTech.AspenPlus.MMDialogs.resources.dll`，版本 41.0.0.614，SHA-256 为 `a77f3ab9413ee939e7f333a8fd4b971453c51ee5df436774d34469fb66585e73`。布局成员 `resolveconflictsdlg.baml` 位于 `AspenTech.AspenPlus.MMDialogs.g.en-US.resources`，原长 5,083 字节，SHA-256 为 `7da00e77005d042b895621573558fe50f832341d5e46a18ebc291864d22187e3`。[来源核对](../../../../../../../evidence/satellite-identity.json)

主库 `AspenTech.AspenPlus.MMDialogs.ResolveConflictsDlg.InitializeComponent`（`0x0600030D`）按 URI `/AspenTech.AspenPlus.MMDialogs;component/resolveconflictsdlg.xaml` 加载本页。完整可编辑 XAML 为 7,658 字节，SHA-256 为 `00a79bc313b0847d45fa9864aa349bd8fdece9d4b3134d59d315f2f5377e7afb`。本页通过静态验收。WPF 标记编译器回编后逐对象读回，已对齐 57 个对象、13 个连接号、13 个字段、10 次事件注册、15 个 Binding 和 0 个 MultiBinding。[逐页核对](../../../../../../../evidence/ui-pages.csv) · [控件与事件](../../../../../../../evidence/ui-connections.csv) · [绑定](../../../../../../../evidence/ui-bindings.csv)

常规 XAML 阅读器将列表上的 `ButtonBase.Click` 标为未知成员。原版连接器 `0x0600030F` 在连接号 13 读取 `ButtonBase.ClickEvent`，调用 `UIElement.AddHandler` 注册 `ListView_ColumnHeaderClicked`（`0x0600030B`）。WPF 标记编译器生成了相同的路由事件和处理函数。[路由事件核对](../../../../../../../evidence/ui-audit.json)

Windows 重建阶段再对照宿主中的显示、数据取值与操作。
