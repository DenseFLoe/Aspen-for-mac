# 第 20261119-21 轮 · 物流表单

`AspenTech.AspenPlus.MMForms.Streams.dll` 已通过整件静态逆向验收。物料流股规格页有两个规格输入位置，选项为温度、压力和汽相分率。总流量与计量基准按子流股分别绑定。闪蒸选项页的相数、相态、自由水、容差和最大迭代次数均已定位到原件的字段声明。[完整 C#](../../../reverse/01-completed/20261119-21/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Streams.dll.cs) · [原始指令位置](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/form-paths.json)

Aspen Plus 与 Aspen Properties 原版安装包的成员和安装件均为 201,768 字节，版本 41.0.0.614，SHA-256 为 `8a5f90aa62dc4d00cdc4706ba995a9117cdbf24cf3d4b7929dfc17aaf512f61b`。两套 MSI 的 File 序号分别为 1887 和 1524。[来源记录](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/identity.json)

| 核对范围 | 验收结果 |
| --- | --- |
| 托管代码 | 810 个方法均有原始实现，共 17,874 条指令，含 3 个 catch 和 2 个 finally 区间。697 个方法定位到 C# 可见行，111 个构造或初始化方法逐一展开核对，另有 2 个自动属性访问器与同一后备字段对应。32 条显式接口映射均已核对。[托管验收](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/managed-audit.json) |
| 旧源码缺口 | 混相物料输入、物料结果、物流汇总三份旧源码的 523、65、10 行诊断均已对应到原件指令与恢复代码，涉及 7 个方法。[逐行映射](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/legacy-diagnostics.json) |
| 页面与控件 | 主库的 32 个页面地址均与 en-US 卫星库中的布局对应，核对了 1,019 个布局对象、407 个控件字段连接和 37 个 WPF 绑定。已定位构造函数中挂接的 SizeChanged 事件。逐页清单含原始布局与本机可编辑 XAML 的指纹。[逐页清单](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/ui-pages.csv) · [布局验收](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/ui-audit.json) |
| 字符串和版本 | 24 处固定取值调用涉及 16 个取值器，已定位到三张资源表。流股类型另从第四张表按动态键查询，找不到非空文本时显示传入值。主库唯一内嵌资源是版本信息，RC 回编的 1,102 字节逐字节与原件一致。[字符串取值](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/localization.json) · [版本资源](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/resources.json) |

两款原版宿主的配置都将 AspenCxs 的旧引用重定向到 41.0.0.57，解释了 Roslyn 报出的 8 条 CS1702 版本警告。Windows 重建后需核对实际加载、3 处未找到同页目标控件的标签和动态显示行为。卫星库的可编辑页面留在本机 `.local/work-20261119-21-ui/recovered/`。[程序集绑定证据](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/managed-audit.json) · [逐页待验位置](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/ui-audit.json)

本轮新增 1 件通过验收的原件，对应 3 条不同来源。Plus、Properties、Properties 重复子清单和共用索引分别更新 3、2、2、3 行。累计 26 / 1,397 件通过验收，覆盖 77 条不同来源。[累计台账](ledger.csv) · [归档指纹](artifacts.csv) · [本轮来源变更](status-delta.csv) · [发布清单](../../../reverse/01-completed/20261119-21/publication.csv)

## 下一轮

接续 `AspenTech.AspenPlus.MMForms.Results_Summary.dll` 的结果汇总表单，从物料流和热流的汇总页进入。安装件已与台账指纹匹配，有 1,734 个方法定义。旧档只单独选取了 85 个顶层类型中的 3 个，需按原件补齐其余成员。[下一件身份和两个页面的类型令牌](../../../reverse/01-completed/20261119-21/Plus-Properties/evidence/form-paths.json)
