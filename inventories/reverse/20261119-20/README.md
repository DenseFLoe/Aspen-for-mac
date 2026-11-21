# 第 20261119-20 轮 · 混合、分流与分离表单

`AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.dll` 已通过整件静态逆向验收。本轮恢复了 Mixer、Fsplit、Ssplit、Sep 和 Sep2 的表单代码。Mixer 的闪蒸选项将相态选择对应到输入变量。Fsplit 的规格表按出口流股读取分流比或流量，并关联流量的计量基准。两个类型初始化器中的变量名和 IL 位置已列入核对记录。[完整 C# 与版本资源](../../../reverse/01-completed/20261119-20/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/) · [规格字段取值位置](../../../reverse/01-completed/20261119-20/Plus-Properties/evidence/form-paths.json)

原件版本为 41.0.0.614，大小为 235,560 字节。Aspen Plus 和 Aspen Properties 原版 MSI 的 File 序号分别为 1872、1509。两个包内成员和共用安装件的 SHA-256 均为 `d8009b165090c48196d9939d7f2f1f120c694e1cb95bc634021108cbebb72517`。[来源记录](../../../reverse/01-completed/20261119-20/Plus-Properties/evidence/identity.json)

| 核对范围 | 结果 |
| --- | --- |
| 托管代码 | 110 个顶层类型、19 个嵌套类型及模块定义均已核对。834 个方法都有 IL 实现，共 20,343 条指令。54 条显式接口映射已按签名匹配。139 个由 C# 语法折叠的构造函数或类型初始化器另按原件核对了有序操作。最终 Roslyn 静态检查为零诊断。[托管验收](../../../reverse/01-completed/20261119-20/Plus-Properties/evidence/managed-audit.json) |
| 旧源码诊断 | Fsplit 分流规格表有 137 行旧诊断，Mixer 闪蒸选项有 232 行，均已定位到原始指令及恢复的 C#。[逐行映射](../../../reverse/01-completed/20261119-20/Plus-Properties/evidence/legacy-diagnostics.json) |
| 页面布局 | 主库的 54 个页面地址全部定位到 en-US 卫星资源库。54 个布局共含 1,106 个对象，已核对 417 个控件字段连接和 70 个 WPF 绑定。54 个 Connect 方法中没有事件挂接。卫星另有一张文件名含 cmdfind 的 PNG，页面里未见直接引用其地址。[逐页清单](../../../reverse/01-completed/20261119-20/Plus-Properties/evidence/ui-pages.csv) · [布局核对](../../../reverse/01-completed/20261119-20/Plus-Properties/evidence/ui-audit.json) |
| 字符串与版本 | 26 个方法通过 101 次调用取得界面字符串，73 个取值器均已定位到四张外部资源表的相应键。主库的唯一内嵌资源为 Windows 版本信息，RC 重建得到的 1,182 字节与原件完全一致。[字符串调用](../../../reverse/01-completed/20261119-20/Plus-Properties/evidence/localization.json) · [版本资源](../../../reverse/01-completed/20261119-20/Plus-Properties/evidence/resources.json) |

Mixer 高级端口页隐藏控件的变量路径 `MMAdvCombo1_var1`、Sep 的 EO 模型表格浏览命令 `cmdBrowse_Command` 均沿用原件写法。对应模型和继承类型中未找到同名属性。Windows 重建时分别复验该控件取值及表格浏览命令。卫星库中的页面属于主库的外部布局证据，全套可编辑 XAML 留在本机 `.local/work-20261119-20-ui/recovered/`。[待实机对照的位置](../../../reverse/01-completed/20261119-20/Plus-Properties/evidence/ui-audit.json)

本轮新增 1 个通过验收的原件，覆盖 3 条不同来源。Plus、Properties、Properties 重复子表、共用索引分别更新 3、2、2、3 行。累计 25 / 1,397 个不同原件通过静态验收，对应 74 条不同来源。[累计台账](ledger.csv) · [归档指纹](artifacts.csv) · [来源变更](status-delta.csv) · [发布清单](../../../reverse/01-completed/20261119-20/publication.csv)

## 下一轮

接续物流表单 `AspenTech.AspenPlus.MMForms.Streams.dll`，从物料流股输入规格和闪蒸选项两个页面入手。上版只单独选取了 66 个顶层类型中的 3 个，三份旧源码都有待复核的诊断。本机原件有 810 个方法定义。已记录两个页面类型令牌、基类、版本和 SHA-256，供下轮逐件核对。[原件与入口](../../../reverse/01-completed/20261119-20/Plus-Properties/evidence/form-paths.json)
