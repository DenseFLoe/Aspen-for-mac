# 第 20261119-24 轮 · 组分表单

Aspen Plus 与 Aspen Properties 共用的 `AspenTech.AspenPlus.MMForms.Components.dll` 通过整件静态验收。本轮归档整库 C#、76 份可编辑 XAML、版本资源及各自的同名说明。两套原版安装包与本机安装件共 3 条来源，按主库哈希计 1 件。[完整 C#](../../../reverse/01-completed/20261119-24/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Components.dll.cs) · [逐件说明](../../../reverse/01-completed/20261119-24/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Components.dll.md) · [发布清单](../../../reverse/01-completed/20261119-24/publication.csv)

| 页面 | 从原件核实的行为 |
| --- | --- |
| [组分选择](../../../reverse/01-completed/20261119-24/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/en-US/AspenTech.AspenPlus.MMForms.Components.resources.dll/specifications/mmcomp_spec_input_selection.xaml) | 查找按钮和定义区域的双击都调用 `Find()`。搜索返回 2 且确认结果为 1 时，代码把 `RUN_CLASS` 设为 `PCES`，打开物性估算节点，并发布运行事件。 |
| [组分清单](../../../reverse/01-completed/20261119-24/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/en-US/AspenTech.AspenPlus.MMForms.Components.resources.dll/comp-lists/mmcomplst_input_selection.xaml) | 首次更新时读取当前对象 ID。`GLOBAL` 将 `GCOMP_LIST` 设为 1，其他 ID 将其设为 0。选择器读取 `@main.Input.CID`。 |
| [组分分组](../../../reverse/01-completed/20261119-24/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/en-US/AspenTech.AspenPlus.MMForms.Components.resources.dll/comp-groups/mmcompgrp_input_selection.xaml) | 子物流选择驱动组内成员列表 `@main.Input.L1.@choice`，该列表的排序开关关闭。 |

各项操作可沿同一索引查到 XAML、C# 行号、方法令牌和原始指令偏移。[选择操作对照](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/selection.json)

## 静态验收

- 核对 1,314 个方法体、28,744 条 IL 指令、28 个异常处理区和 83 条显式接口映射，含选择迭代器的 9 个方法。静态编译有 0 个错误、6 项依赖版本警告。旧稿覆盖的 59 个不同方法均已对上当前原件。[托管验收](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/managed-audit.json) · [旧稿核对](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/legacy-il.json)
- 76 页的 1,454 个对象、598 处字段连接及 2 个连接器事件已按原布局核实，76 份 XAML 均通过 WPF 静态读取。有 4 处绑定需在宿主确认：3 个外部结果状态页的 `status_var` 及 1 个列头模板的 `IsMMEnabled`。 [页面清单](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/ui-pages.csv) · [布局验收](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/ui-audit.json) · [本地化](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/localization.json)
- 主库及卫星的两份既有安装包成员均与各自的安装件同哈希。两个安装件的 Authenticode 签名有效。可编辑 RC 回编所得 1,134 字节版本块与原件相同。[主库身份](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/identity.json) · [卫星身份](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/satellite-identity.json) · [签名](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/signing.json) · [资源](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/resources.json)

本轮在 Plus、Properties、Properties 重复子清单及共用索引分别同步 3、2、2、3 行。累计 29 / 1,397 件原件通过静态验收，覆盖 86 条不同来源。Windows 宿主的实际查找、交互和估算结果留待后续对照。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

接续物性表单 `AspenTech.AspenPlus.MMForms.PhysicalProperties.dll`。原件有 4,955 个方法定义，旧稿选取 496 个顶层类型中的 28 个，13 份类型稿留有诊断。已定位 NRTL 二元交互参数、二元分析方法、二元参数结果三处页面和视图模型入口。[原件与入口令牌](../../../reverse/01-completed/20261119-24/Plus-Properties/evidence/next.json)
