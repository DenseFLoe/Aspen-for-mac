# 第 20261119-27 轮 · 网格表单主库

`AspenTech.AspenPlus.MMForms.GridForms.dll` 通过整件静态逆向验收。两套安装包与安装件的主库哈希一致，版本为 41.0.0.614。旧稿只选取 173 个顶层类型中的 1 个。本轮恢复了整件可编辑 C#、30 份 XAML 及 Windows 版本资源。[逐件说明](../../../reverse/01-completed/20261119-27/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.GridForms.dll.md) · [发布清单](../../../reverse/01-completed/20261119-27/publication.csv)

| 原版操作 | 由代码、IL 和布局核实的行为 |
| --- | --- |
| 查询变量 | 没有活动表时直接返回。有活动表时，用已有查询文本、候选字段和默认字段打开对话框。变量模式决定两个匹配选项。用户确认后才写回查询文本。 |
| 复制物流报表路径 | 复制端把物流和所选物性的信息写入 XML 元数据。读取端先核实元数据标记和路径前段，再解析物流标识与物性项。解析成功后把两者交给引擎，返回解析出的路径。 |
| 解析失败 | 元数据损坏导致 XML 解析抛出异常时，代码记录异常并返回空结果。预处理调用保留传入路径并返回失败。 |

查询、组分选择和限定条件窗口的入口有原始方法体指纹与分支偏移。另列 5 个报表路径方法的 IL 操作、C# 行号及方法体指纹。运行时的窗口、引擎结果与剪贴板留待 Windows 对照。[操作入口](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/control-entrypoints.json) · [报表路径](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/report-paths.json)

## 验收和发布范围

- 3,084 个方法定义中，3,012 个有 IL 方法体，63 个是抽象声明，9 个由运行时实现。按令牌核对了 63,237 条指令、346 个异常处理区、22 个迭代器及 213 个显式接口槽。7 个内嵌 COM 类型已与原件对照。完整源码静态编译为 0 个错误、26 项警告。[托管核验](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/managed-audit.json) · [逐方法索引](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/methods.csv)
- 30 份 XAML 全部经 WPF 静态回编，逐页比对 955 个对象、2,032 个属性、172 个连接号、167 个字段和 44 次事件订阅。另核对了 197 条非空绑定或变量路径，以及代码和布局引用的 512 个不同本地化键。[布局](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/ui-pages.csv) · [绑定](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/ui-bindings.csv) · [本地化](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/localization.json)
- 1,134 字节的版本资源回编后与原件逐字节一致。卫星中的 14 个图像键对应 11 种不同内容，均已解码。代码另引用的 7 个图标已在依赖资源表中定位。[版本资源](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/resources.json) · [图像](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/resource-asset-index.csv) · [外部图标](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/external-image-references.json)
- 完整源码共 34,781 行。本机保留全部源码及原图，GitHub 选取件逐段保留 34,606 行。去除的物性预置表、换算实现及相应展开段均有行号和指纹。[代码选取记录](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/code-extraction.json) · [成果去向](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/publication-scope.csv)

累计 32 / 1,397 个不同原件通过静态验收，覆盖 95 条不同来源。Plus、Properties、Properties 重复子清单及共用索引已同步本件的 3 条来源。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

接续调用本库的 `AspenTech.AspenPlus.MMForms.CustomForms.dll`。原件有 413 个方法定义，旧档仅覆盖 3 个方法。本轮已把其中 6 个调用方的 10 处调用定位到网格表单主库，覆盖报表路径识别、模板属性读写和引擎调度。[下一件和调用位置](../../../reverse/01-completed/20261119-27/Plus-Properties/evidence/next.json)
