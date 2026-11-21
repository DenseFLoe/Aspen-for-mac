# 第 20261119-25 轮 · 物性表单

Aspen Plus 和 Aspen Properties 共用的 `AspenTech.AspenPlus.MMForms.PhysicalProperties.dll` 通过整件静态逆向验收。两套原版安装包和本机安装件共覆盖 3 条来源。本机已归档完整 C#、237 份可编辑 XAML、版本资源及图片包。[逐件说明](../../../reverse/01-completed/20261119-25/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.PhysicalProperties.dll.md) · [发布清单](../../../reverse/01-completed/20261119-25/publication.csv)

| 页面 | 已核实的原版行为 |
| --- | --- |
| [NRTL 二元交互参数](../../../reverse/01-completed/20261119-25/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/en-US/AspenTech.AspenPlus.MMForms.PhysicalProperties.resources.dll/parameters/binary%2520interaction/t-dependent/mmparam_bi_cor_nrtl.xaml) | 确认按钮调用 `SMDechema`。返回 0 时显示错误消息，随后仍执行刷新、将当前选择的温度单位标签写为 K 并关闭窗口。取消按钮直接关闭。 |
| [二元分析方法](../../../reverse/01-completed/20261119-25/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/en-US/AspenTech.AspenPlus.MMForms.PhysicalProperties.resources.dll/analysis/binary/mmanalysis_bi_inp_methods.xaml) | 物性方法选择器绑定 `@main.Input.OPSETNAME`。真实组分与表观组分分别对应 `TRUE_COMPS` 的 YES 和 NO。首次更新按产品代码选择计算方式或模拟方式标签。 |
| [二元参数结果](../../../reverse/01-completed/20261119-25/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/en-US/AspenTech.AspenPlus.MMForms.PhysicalProperties.resources.dll/parameters/results/binary%2520interaction/mmresults_binary.xaml) | 首次更新把 `NotNeedName` 和 `NotNeedType` 均设为 `NotNull`。页面模板连接标量与温度相关参数两个结果子页，并包含通用信息页。 |

页面、绑定、原始方法令牌、IL 偏移和本地完整 C# 行号可在同一份索引查到。实际查询、数值结果和界面交互留待 Windows 宿主对照。[三页入口](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/binary-pages.json)

## 整件核验

- 逐令牌核对 4,955 个方法体、106,490 条原始 IL 指令、74 个异常处理区和 259 条显式接口映射。Roslyn 静态编译有 0 个错误、20 项警告。历史选取 IL 的 77 个不同方法及旧 C# 诊断位置已复核。[托管核验](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/managed-audit.json) · [旧稿诊断](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/legacy-summary.json)
- 237 页全部通过 WPF 静态读回。核对 7,699 个布局对象、23,873 个序列化属性、2,578 个连接号、2,576 处字段连接、6 处连接器事件和 136 处内部页面引用。外部本地化表核实了 1,710 个字符串访问器。[布局核验](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/ui-audit.json) · [页面清单](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/ui-pages.csv) · [本地化](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/localization.json)
- 两个安装包内的主库和卫星文件分别与其安装件同哈希，两个安装件签名均有效。主库版本资源经 RC 回编后，1,198 字节与原件一致。[主件来源](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/identity.json) · [卫星来源](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/satellite-identity.json) · [签名](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/signing.json) · [版本资源](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/resources.json)

原版有两个标签在同页找不到声明的目标控件，其余 416 个目标在本页均唯一匹配。NRTL 常数标签状态与二元分析方法页的亨利组分启用状态均保留原绑定名，实际解析留待 Windows 宿主对照。[布局核验](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/ui-audit.json)

已按原始指令修复一处事件处理程序缓存。原件在首次访问时创建委托，后续访问复用同一对象。另核对了迭代器的释放路径、静态字段初始化顺序和字符串格式化调用。最终编译的 20 项警告包括 17 项依赖版本警告、2 项原版使用旧 API 的警告和 1 项原版不可达分支。[托管修复依据](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/managed-audit.json)

## 本机与 GitHub 成果

完整 C# 含回归计算公式。本机归档保存完整代码及全部原始显示内容。GitHub 收录 337 个经核验可发布的完整顶层类型、235 份完整 XAML，以及 NRTL 和 Wilson 两份布局的可公开部分。两份布局分别省略一个物理常数标签的文本，保留原控件及绑定。另有 4,356 个 PNG 键，对应 3,736 种不同内容，原图按键名打包保存在本机。发布的图片索引仅含键名、尺寸、模式、字节数和指纹。[可公开 C#](../../../reverse/01-completed/20261119-25/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.PhysicalProperties.dll.01.cs) · [代码对应](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/code-extraction.json) · [布局对应](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/ui-publication.json) · [图片索引](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/resource-asset-index.csv) · [逐件发布范围](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/publication-scope.csv)

累计 30 / 1,397 个原件通过静态验收，覆盖 89 条不同来源。Plus、Properties、Properties 重复子清单和共用索引本轮分别更新 3、2、2、3 行。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

接续网格表单控件库 `AspenTech.AspenPlus.MMForms.GridForms.Controls.dll`。旧稿只选取 41 个顶层类型中的 2 个。已核实原件含 542 个方法定义，并定位路径导航、变量列表和工作表命名三处入口。[下一件来源与方法令牌](../../../reverse/01-completed/20261119-25/Plus-Properties/evidence/next.json)
