# 第 20261119-23 轮 · 模拟设置表单

Aspen Plus 与 Aspen Properties 共用的 `AspenTech.AspenPlus.MMForms.Setup.dll` 已通过整件静态验收。已归档可编辑 C#、版本资源和 en-US 卫星程序集的 76 份可编辑 XAML。按主库的哈希计为 1 件完成，涉及两套安装包和本机安装件共 3 条来源。[完整 C#](../../../reverse/01-completed/20261119-23/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Setup.dll.cs) · [逐件说明](../../../reverse/01-completed/20261119-23/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Setup.dll.md) · [页面清单](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/ui-pages.csv)

| 设置页 | 从原件恢复的规则 | 可编辑布局 |
| --- | --- | --- |
| 全局设置 | 选择 `Flowsheet` 时，更改流量基准会检查相应的物流报告选项。只有现值与目标不同时，代码才写入该选项。 | [全局设置](../../../reverse/01-completed/20261119-23/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/en-US/AspenTech.AspenPlus.MMForms.Setup.resources.dll/mmsetup_setup_global.xaml) |
| 物流报告 | 摩尔流量、质量流量和标准体积流量对应三个独立开关，可与全局设置的三处写入逐一对应。 | [物流报告](../../../reverse/01-completed/20261119-23/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/en-US/AspenTech.AspenPlus.MMForms.Setup.resources.dll/mmsetup_report_stream.xaml) |
| 闪蒸选项 | `Inside-Out`、`Gibbs`、`User` 分别映射到引擎输入 `INSIDE-OUT`、`GIBBS`、`USER`。本页还声明了温压上下限和最大迭代次数的输入路径。 | [闪蒸选项](../../../reverse/01-completed/20261119-23/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/en-US/AspenTech.AspenPlus.MMForms.Setup.resources.dll/mmsetup_simopt_flashc.xaml) |

三个页面的视图模型方法、原指令偏移及 C# 行号可按同一份索引复查。闪蒸方法的实际计算结果留待 Windows 阶段对照。[设置选项对照](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/setup-options.json)

## 静态验收

- **原件身份。** 两套原版安装包的既有成员与当前安装件同哈希，主库版本为 41.0.0.614。主库和卫星安装件的 Authenticode 签名均通过验证。主库版本资源的可编辑 RC 回编后与原件的 1,102 字节逐字节相同。[主库来源](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/identity.json) · [卫星来源](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/satellite-identity.json) · [签名](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/signing.json) · [版本资源](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/resources.json)
- **代码。** 已按定义令牌核对 1,595 个方法体和 2 项无方法体的 COM 声明，覆盖 37,776 条 IL 指令。四个列表迭代器保留原状态转换及异常清理。Roslyn 静态编译为 0 个错误、7 个警告。 [托管验收](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/managed-audit.json)
- **历史缺口。** 旧稿在 5 份逐类型导出中留有 667 条诊断。已逐条对应至 13 个原始方法内的指令偏移和恢复源码位置。 [旧稿诊断](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/legacy-diagnostics.json)
- **页面。** 原版布局中的 2,429 个对象、878 处字段连接、4 处连接器事件及 2 处构造函数事件均已核对。76 份 XAML 均通过 WPF 静态读取。代码有 267 处直接取串调用，布局有 667 处静态本地化引用。[布局核对](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/ui-audit.json) · [本地化](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/localization.json)
- **Windows 待验。** 原布局中有 2 个标签目标找不到同名控件，另有 4 条绑定路径在相应视图模型继承链中找不到同名属性，归档保留原写法。其实际数据上下文、窗体装载和交互需在宿主中复验。[原版路径记录](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/ui-audit.json)

本轮增量已同步至 Plus、Properties、Properties 重复子清单和共用索引，分别涉及 3、2、2、3 行。累计 28 / 1,397 件不同原件已通过静态验收，覆盖 83 条来源。研究工具的 22 项现有测试及 UI 资源目录校验均通过。[累计台账](ledger.csv) · [归档指纹](artifacts.csv) · [状态变更](status-delta.csv) · [发布清单](../../../reverse/01-completed/20261119-23/publication.csv)

## 下一轮

接续组分表单 `AspenTech.AspenPlus.MMForms.Components.dll`。旧档涉及 59 个按名称去重的 IL 方法，当前原件有 1,314 个方法定义。已定位组分选择、清单选择、分组选择三页及其视图模型静态构造方法。[原件指纹和入口令牌](../../../reverse/01-completed/20261119-23/Plus-Properties/evidence/next.json)
