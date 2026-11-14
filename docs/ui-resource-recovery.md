# Aspen Plus V15 静态界面资源恢复

本轮按“批量扫描 → 清单 → 布局恢复 → 外壳比对 → 动态抽查”的顺序处理。扫描对象是本机安装的 Aspen Plus V15.0、AprSystem V15.0、Aspen Properties V15.0，日期为 2026-11-14（Asia/Shanghai）。安装文件只读，未载入或执行原程序程序集中的代码。

## 扫描结果与计数口径

| 项目 | 数量 |
| --- | ---: |
| 安装文件清单 | 4,549 |
| 检查 PE 资源的 EXE / DLL / OCX | 1,069 |
| 原生资源与托管资源条目 | 700,295 |
| 读取的字符串（包括不同语言与共用库） | 663,478 |
| 完整解析的 BAML 布局（包括第三方模板） | 7,966 |
| 接入目录的 Aspen WPF 模块 | 47 |
| 接入目录的 Aspen 布局定义 | 2,947 |
| 其中包含 MMTabItem 的页签容器 | 620 |
| 这些布局中的节点 | 103,532 |
| 按钮类控件出现次数（包括单选按钮） | 3,673 |
| 原生对话框模板 | 289 |
| 原生菜单模板 / WPF 菜单树 | 69 / 37 |
| 扫描解析错误 / 未解析界面文字引用 | 0 / 0 |

**2,947 是布局资源数，不是 2,947 个已验证的完整业务页面。** 它包括页签内容、容器、对话框和部分控件资源；同一业务页面通常引用多份布局。文件存在也不证明该页面在当前案例或许可证下可达。安装目录里的示例、帮助、符号等非 PE 文件只列入文件清单；没有把旧版 `dialog.dat`、流程图符号或引擎数据误算为已恢复页面。

原始完整扫描结果保存在忽略目录 `.local/ui-scan/results/`。仓库只保存解析器、文本化界面定义及核验清单，不含输入二进制、安装包、工具或本地数据库。

## 清单与证据

- `ui/recovered/index.json`：逐布局的类型、名称、中文标题、所属模块、来源资源、SHA-256、搜索文本及容器分类。
- 同目录模块 JSON：原始父子关系、属性槽、控件类型、尺寸、边距、Grid 行列与跨度、页签 ContentType 引用，以及解析后的中文文字。
- `buttons.json`：按钮类控件的页面 ID、节点、类型、名称、文字和运行时绑定。
- `native-dialogs.json`：窗口及控件的 DLU 坐标、字体、样式、ID、语言和文字。
- `native-menus.json` / `menus.json`：原生菜单和合并后的 106 份菜单树，保留层级、分隔符、命令 ID 和静态状态。
- `scan-files.json` / `sources.json`：安装文件范围及来源程序集校验值。
- `summary.json` / `scan-errors.json` / `validation.json`：统计、解析错误清单及全部布局结构/引用检查。
- `coverage.json`：现有外壳与资源清单的比对，包括新增按钮文字和模块覆盖。
- `unresolved.json`：204 个非文字静态引用，主要是图像和框架资源；没有把它们当成已恢复图标。

语言优先级为 zh-Hans → en-US → 中性资源，其他语言仅作最后回退。托管资源按格式中的 UTF-16 名称和 UTF-8 值分别读取。强类型资源属性会把连字符转换为下划线；仅在名称归一化后唯一对应时解析该别名，例如 `SearchPhyPropStep2_2` 对应资源键 `SearchPhyPropStep2-2`。

## 与现有外壳比对

原有实现为 17 个截图核对页面、39 个页签、4 个功能区及 97 个图标。这些页面有空案例状态证据，继续保留。新目录提供原先未接入的设置、物性方法、反应、物流、单元操作、收敛、流程选项、结果和工具等模块；组分模块也补充了完整静态布局索引。

比对采用去除空白、快捷键标记及部分标点后的**精确文字匹配**。结果发现 2,621 次按钮类控件出现，其文字未出现在原有清单中。该计数不是独立命令数：同名按钮可能重复，文字相同也不证明行为相同。逐项结果可由比较脚本重新生成。

## 可恢复与待动态确认的边界

能够静态恢复：文字、控件层级、分组、页签引用、明确尺寸/边距、Grid 行列、静态表头、传统对话框和菜单层级。

静态资源包含 15,164 个 `VariablePath` 引用。数值、列表项目、表格数据、部分单位选择、可见性和启用状态需要运行时上下文。外壳不会把绑定名称填充成业务值，也不会执行原程序命令。11 个 ContentType 引用没有对应独立 BAML，逐项列在 `validation.json`；COM ContentProgId 和自定义绘图/复杂控件同样需要单独处理。

通用 Qt 渲染是布局预览，不能等同于逐像素复刻。自定义控件采用对应的只读 Qt 输入框、下拉框、表格等；不能恢复的控件显示说明。Windows DLU 到像素随当前字体换算，WPF 样式、绑定、事件、模板与绘图逻辑不执行。

同一 Grid 位置存在多个绑定可见性的分组时，预览用额外标签分别展示，并优先显示内容较多的一组。这些标签属于预览器，不是原程序新增的业务标签，也不代表已确认原程序的显示条件。静态声明为 Hidden / Collapsed 的内容默认不显示，原始属性仍完整保留在目录中。

## 外壳接入与验证

左侧增加“全部资源”导航，按模块搜索页面、按钮和菜单；保留原先的“已核对”导航及页面状态。“设置、方法、物性组”入口接到恢复布局，“组分/绘制结构”可切回原有实现。模块 JSON 按需载入，页面切换释放前一份预览控件。

Windows Qt 6.8.3 / MinGW 13.1 编译验证，Qt 测试覆盖全部 2,947 份布局、289 个传统对话框、106 份菜单的创建，47 模块导航、搜索、主要入口、无效页面 ID、窄窗口，以及原有页面状态和弹窗。组分、设置、单位、Henry 组分、物性方法、RCSTR、RadFrac 代表页面另做渲染检查；为条件分组、带复选框标题的分组和长页面滚动增加回归检查。6 项 Python 测试覆盖 BAML 层级/截断、Unicode 资源、标准/扩展对话框及嵌套菜单；目录核验遍历全部节点和页面引用。macOS Actions 同时运行解析检查、目录校验、构建和 Qt 测试，远端结果以对应提交的运行记录为准。

## 原程序动态抽查状态

本轮定位到了正在运行的 `Simulation 2 - Aspen Plus V15 - aspenONE`，但无法完成动态观察：激活窗口报 `GetCursorPos` / `0x80070005`，重新枚举窗口后的截图报 `IGraphicsCaptureItemInterop.CreateForMonitor` / `0x80070057`。没有继续使用旧坐标或声称观察到新的动态行为。

待桌面恢复后，仅需抽查空案例下的页签启用条件、表格/下拉内容、ContentProgId 页面和上述 11 个缺失引用。旧有 31 张参考图来自先前已完成的采集，不算本轮新增动态证据。

## 复现

Python 3.10+，依赖 `pefile==2024.8.26`、`dnfile==0.18.0`。可在独立虚拟环境安装。解析不依赖 Windows UI；有合法安装文件副本时，也可在其他平台运行。下面的输出目录必须留在本机忽略目录。

```sh
python tools/scan_aspen_ui.py --root "C:/Program Files/AspenTech" --output .local/ui-scan/results
python tools/build_ui_catalog.py --scan .local/ui-scan/results --output ui/recovered
python tools/verify_ui_catalog.py ui/recovered --report ui/recovered/validation.json
python tools/compare_ui_shell.py
python -m unittest discover -s tests -p test_ui_resources.py -v
```

`--retry-errors` 可在已有扫描结果上重读失败文件和原生对话框。没有原版安装的 Mac 构建直接使用仓库中的 JSON，不需要重新扫描。

格式依据：[Microsoft WPF BAML records](https://github.com/dotnet/wpf/blob/main/src/Microsoft.DotNet.Wpf/src/PresentationFramework/System/Windows/Markup/BamlRecords.cs)、[ResourceReader](https://github.com/microsoft/referencesource/blob/main/mscorlib/system/resources/resourcereader.cs)、[DLGITEMTEMPLATE](https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-dlgitemtemplate)、[DLGTEMPLATEEX](https://learn.microsoft.com/en-us/windows/win32/dlgbox/dlgtemplateex)。类型编号表的上游许可见 `tools/baml-known-NOTICE.txt`。原产品界面文字、图像和布局归原权利人所有。
