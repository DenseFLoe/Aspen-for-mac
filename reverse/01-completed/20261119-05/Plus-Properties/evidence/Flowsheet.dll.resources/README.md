# Flowsheet.dll：三页资源及界面接线（20261119-05）
 
**结论：主件没有 CLR 资源，但不等于没有界面定义。** 三个页面都在同目录的 en-US 卫星中；11 个 BAML 接线 ID 均与同一主件内的字段/分支匹配，无遗失、重复、空接或未解释分支。结论仅限这两个安装件哈希对应的资源与静态接线，不是整件验收。验收方法先记于 ACCEPTANCE.md。
 
## 原件和无窗口查找
 
- 主件：AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Flowsheet.dll，42,024 字节，SHA-256 aba9d5c58c1cbe4d0ee5584ea7c36ee8dd8be4196816c919151895adfe8b2bac。CLI Resources RVA 与 Size 均为 0，#~ 表掩码第 40 位为 0，无 ManifestResource 行；.NET GetManifestResourceNames() 也为空。
- 卫星：同目录下 en-US/AspenTech.AspenPlus.MMForms.Flowsheet.resources.dll，24,104 字节，SHA-256 d5edd484ef669276c47b41b867595027211ce07dd9da04147070eb481c09cab4。CLR 资源目录 RVA 8272、长度 9682；4 字节长度前缀后是唯一内嵌清单项 AspenTech.AspenPlus.MMForms.Flowsheet.g.en-US.resources（9678 字节，SHA-256 da3ecf16fb4ec082d88878d47394c7df4c8deabb7ac4ebfda06ccfcea226146c）。两个安装件的程序集版本均为 41.0.0.614；清单/MSI 来源由主任务核对。
- 两个 PE 的 Win32 资源各只有 RT_VERSION / 1 / LANGID 0。主件偏移 0x7458、1118 字节；卫星偏移 0x2e58、1088 字节。PE 目录与 Win32 datafile 模式枚举逐叶一致；每棵 VS_VERSION_INFO 树（含固定字段、字符串和翻译项）完整遍历到 EOF，详见 index.json。没有 Win32 对话框、图标或其他叶子。
- 主件显式 NeutralResourcesLanguage(en-US, Satellite)。无窗口 .NET GetSatelliteAssembly(en-US) 命中上述文件；ResourceManager 从主件的 .g 基名按 en-US 取集合（tryParents=false），得到下列三个键，载荷哈希与 PE 直接切片、dnfile、ResourceReader 均一致。这个读取实验没有调用 Application.LoadComponent，也不是实际宿主页面渲染。
 
## 资源键与接线
 
三个 InitializeComponent 的同型指令序列：已加载则返回；否则置 _contentLoaded、以 UriKind.Relative (2) 创建 /AspenTech.AspenPlus.MMForms.Flowsheet;component/<页名>.xaml，然后以视图本身和该 URI 调用 Application.LoadComponent。每个 Connect 都按“连接 ID 减 1”跳表，默认分支单纯置 _contentLoaded，不是匿名控件。各页独立编号。
 
| 卫星中的键 | 原 BAML 字节 / SHA-256 | BAML 记录 / 元素对象（含 Binding 等） | Initialize / Connect 方法令牌 | ID → 字段 |
|---|---|---|---|---|
| mmflowsh_input.baml | 2041 / 123540d1e89f626847c3fa2d44b36b59a205022af5cdb330854864ae4f9ae04b | 62 / 4 | 0600000E / 0600000F | 1 MMSSTab1；2 tab0；3 tabInfo |
| mmflowsh_input_flowsh.baml | 3302 / 46640826ccf43f611ee4428e878ac8abc92d29856811ebac436d9c0c0dae7e32 | 157 / 16 | 06000023 / 06000024 | 1 grdFlowsheet；2 btnExpandAll；3 btnCollapseAll |
| mmflowsh_objman.baml | 3971 / f60e3efe94f70f6d0d1db901d5eb1d300d8a0063611efdc06e8354c7c48946c6 | 226 / 26 | 0600003F / 06000040 | 1 cmdAdd；2 cmdExport；3 cmdEdit；4 cmdCurrent；5 grdChild |
 
- **输入页**：最小 530×343，一个 MMTabStrip、两个 MMTabItem。tab0 用本件 MMFlowsh_Input_Flowsh 作 ContentType，VariablePath 为本地 tab0_var；tabInfo 使用外部 ProgID MMGeneric.MMGeneric_Input_Info、继承的 MMTabPageViewModel.info_var。两页签分别引用 flowsheet.chm / 2 与 plotwiz.chm / 7；不是内嵌帮助正文。
- **流程表页**：最小 520×340，两行网格。grdFlowsheet 声明 grdFlowsheet_GridData、层级 Inner、四个进/出口流与端口选择字段；ReorderRowCommand 的 Binding 用构造参数 Reorder_Command，而非普通 Path 属性。两个按钮在 Connect 的分支中订阅 Click，分别到 btnExpandAll_Click / btnCollapseAll_Click，继而调用 Records.ExpandAll / CollapseAll。grdFlowsheet.Loaded 则由构造器接线，不在 Connect 中；Loaded 内确认 DataGrid 非空后订阅筛选、编辑结束和 MouseLeftButtonUp（handledEventsToo=true）；OnClosing 有对应的三处解除。_recordToBeExpandedIndex 是编辑相关状态字段，不是漏接的控件。
- **对象管理页**：最小 520×340。外层未命名 MMFlatButton 是容器，没有接线 ID；内层四按钮以 Binding 分别指向 Add、Export、Edit、Current 的命令属性，不是四个 Click 处理器。grdChild 另有 SelectedRowIds → SelectedRowIndexes（TwoWay）、RowDoubleClickCommand 和 DeleteRowCommand。删除列还有字符串选择器 cmdDelete_Command / txtName_var1.Value，它不是第八个 Binding。字段路径、列宽、掩码、帮助引用 flowsheet.hlp / 1、透明画刷 #00FFFFFF 均保存在可读树中。
 
## 可复核证据
 
- pages/ 内每页一份 .view.xml（只读投影，不可作为原始 XAML）和 .json（每条记录的偏移/终点、原字节、类型表、转换器、元素/父级/复杂属性、ConnectionId 位置）。一个类型表条目不一定对应一个可视对象。全部 445 条记录逐段解码、字节回拼，三页分别对齐微软 WPF BamlReader 的 12 / 46 / 75 个逻辑节点及 29 / 71 / 100 个属性。位于 EndComplexProperty 上的 ContentProperty 仍归属原对象；未舍去延迟出现的属性。总计 46 个对象、8 个 Binding。
- relationships.json 将每个连接号关联到页、BAML 字节偏移、CLR 类型、字段名/令牌及 switch、stfld、ret 的 IL 偏移；列出两个 Click 的委托/处理器及代码订阅/解除的位置。另列三页 ViewModel 构造接线、每个 Binding/FieldPath 的属性 getter 以及引用的外部接口。ui-il.json 仅含三种视图类的方法体和相关类型的成员签名，不是全方法反编译。
- materials/ 按安装路径和原程序集名区分两件的原始资源叶子、卫星容器及其三个 BAML。index.json 给出每个载荷在原 DLL 中的绝对字节偏移、长度、SHA-256、带流长度前缀的 wire SHA-256、版号树和相应说明路径；SHA256SUMS 覆盖脚本、证据、产物及配套说明。
- framework.json 是未创建业务视图的 .NET/WPF 节点读取证据；lookup.json 是无窗口资源查找；contracts.json 仅以元数据验证外部 MMControls 的继承 getter 和 Localization 的 20 个静态字符串 getter，记录实际依赖文件哈希及令牌；没有调用 getter、反编译依赖或认证其整件。
 
## 明确边界及恢复条件
 
- 没有恢复作者原始 XAML 文本、注释或设计器工程；XML 是可搜索的解码树，字节级真值为原始 BAML。没有发现未解析的 BAML 记录、未匹配的控件 ID 或未定位的本地命令 Binding。字段上的 Value 选择器面向运行时对象（若干本地 getter 返回 System.Object），不是本件内可静态核验的属性；HeiFields 是控件字段标识。
- MMControls/Infragistics 的交互与视觉实现、宿主分配的实际 DataContext/动态值、ProgID 激活、帮助文件跳转、资源键最终显示文字、其他文化的回落和运行时事件时序不在本次验收内。要验这些行为，需要相应依赖/语言资源或受控原版宿主对照；不能把 en-US 资源读取当成原 GUI 已运行。
- 未核验安装包；未重建、未开 GUI、未改 Git 或共享台账，未将卫星或主件标为整件完成。主任务可引用本目录做静态资源子项证据。
 
## 只读复跑
 
在仓库根目录 PowerShell 运行（不要使用 -O 或省略 -B）。四个读取器和 Python 验证均逐字节比较已有成果；无 -Verify / --verify 的生成模式仅准写入尚不存在的文件。
 
```powershell
$part = '.local/reverse-round-20261119-05/flowsheet-resources'
powershell.exe -NoProfile -NonInteractive -File "$part/read-framework.ps1" -Verify
powershell.exe -NoProfile -NonInteractive -File "$part/read-lookup.ps1" -Verify
& "$part/read-ui-il.ps1" -Verify
& "$part/read-contracts.ps1" -Verify
& .local-tools/research/venv/Scripts/python.exe -B "$part/audit.py" --verify
```

