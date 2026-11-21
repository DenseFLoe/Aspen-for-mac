# 网格表单控件库

Aspen Plus V15 和独立 Aspen Properties V15 共用 `AspenTech.AspenPlus.MMForms.GridForms.Controls.dll`，版本 `41.0.0.614`。两套 MSI 中的 `APRS~457.cab` 成员与安装目录 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq` 中的主库 SHA-256 均为 `9ebf2c982799bf58d7408f28056d35ce0488344be272212b285b518463582266`。同版本 en-US 卫星提供布局和图标。[主库来源](../../../../../evidence/identity.json) · [卫星来源](../../../../../evidence/satellite-identity.json)

第 26 轮通过整件静态逆向验收。旧稿覆盖多选组合框和范围选择器两个顶层类型。完整 C# 现覆盖 41 个顶层类型与 16 个嵌套类型，文件为 `AspenTech.AspenPlus.MMForms.GridForms.Controls.dll.cs`，SHA-256 为 `72526a413ea808ec6a6f4b60e5e2a69b2d69104c77fdabc7fad4111a63c5c536`。[逐方法索引](../../../../../evidence/methods.csv)

ILSpy 9.1.0.7988 导出托管代码，按原件方法令牌核查 542 个实现。433 项有活动源码映射，61 项折叠方法另附展开并核对操作，48 项为已核对的自动访问器。共核对 7,377 条 IL 指令、23 个异常处理区和 17 条显式接口映射。用原版引用作 Roslyn 静态编译，0 个错误、1 项警告，对应原版 `DataRow` 使用的旧构造函数。[托管核验](../../../../../evidence/managed-audit.json)

字符串数组的 XML 枚举器保留原版释放路径和异常清理顺序。路径导航、工作表改名和变量列表合计核对 14 个方法，逐项记录原始方法体哈希、IL 偏移和 C# 行号。[入口及分支](../../../../../evidence/control-entrypoints.json)

另归档可编辑版本资源、12 份可编辑 XAML 及其同名说明。11 个图标以原键名和原始字节保存在本机。布局的 35 个连接号、35 个字段与 12 处事件订阅已与原件核对。外部本地化程序集提供的 36 个字符串键均已核实。[布局核验](../../../../../evidence/ui-audit.json) · [图标清单](../../../../../evidence/resource-asset-index.csv) · [本地化核验](../../../../../evidence/localization.json)

下一阶段在 Windows 宿主中对照路径重选、名称校验提示、变量筛选与行选择、动态主题及图标显示。
