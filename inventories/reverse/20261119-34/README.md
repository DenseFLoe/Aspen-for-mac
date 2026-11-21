# 第 20261119-34 轮 · 反应表单组件

`AspenTech.AspenPlus.MMForms.Reactions.dll`（`41.0.0.614`）通过整件静态逆向验收。Plus 与 Properties 两套 V15 安装包成员及共用安装件的 SHA-256 一致，合计一个原件、三条来源。[逐件说明](../../../reverse/01-completed/20261119-34/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Reactions.dll.selected.md) · [发布清单](../../../reverse/01-completed/20261119-34/publication.csv)

- 核对 488 个类型定义、4,128 个字段、2,405 个属性、16 个事件、4,166 个方法、108,427 条指令、60 个异常处理区及 183 个显式接口槽。330 个折叠构造方法的有序调用、字段操作和常量与静态回编结果一致。旧稿 10 条诊断定位到原版 IL 偏移及新稿行号。完整 C# 的 Roslyn 静态检查为零错误，另有 3 条未使用局部变量警告。[托管验收](../../../reverse/01-completed/20261119-34/Plus-Properties/evidence/managed-audit.json) · [逐方法索引](../../../reverse/01-completed/20261119-34/Plus-Properties/evidence/methods.csv) · [旧诊断](../../../reverse/01-completed/20261119-34/Plus-Properties/evidence/legacy-diagnostics.json)
- en-US 卫星有 148 个页面、72 个 PNG。核对了 5,819 个元素、1,506 个控件字段连接和 1 次事件注册，记录 381 个绑定声明及 1,648 项静态路径属性。218 个外部本地化访问器均已定位。主库的 Windows 版本资源经回编后 1,146 字节与原件相同。[逐页核验](../../../reverse/01-completed/20261119-34/Plus-Properties/evidence/ui-pages.csv) · [控件及事件](../../../reverse/01-completed/20261119-34/Plus-Properties/evidence/ui-connections.csv) · [绑定](../../../reverse/01-completed/20261119-34/Plus-Properties/evidence/ui-bindings.csv) · [本地化](../../../reverse/01-completed/20261119-34/Plus-Properties/evidence/localization.json) · [版本资源](../../../reverse/01-completed/20261119-34/Plus-Properties/evidence/resources.json)
- 完整 C#、带指令字节的 IL、页面节点和原图留在本机。发布选取件保留原行号，涉及公式和反应表达式拼接的区段附有令牌、行号和指纹。页面加载、输入校验、绑定与事件行为留待 Windows 对照。[代码选取记录](../../../reverse/01-completed/20261119-34/Plus-Properties/evidence/code-extraction.json)

累计 **39 / 1,397** 个不同原件通过静态验收，覆盖 **114 条不同来源**。Plus、Properties、Properties 重复子表和共用视图分别更新 3、2、2、3 行。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [本地归档指纹](artifacts.csv)

## 下一轮

接续 Aspen Plus 与 Aspen Properties 共用的 `ApedDataProvider.dll`。本机安装件的指纹与台账一致，有 257 个类型定义、1,900 个方法定义和 7 个内嵌托管资源。补核历史局部源码未覆盖的类型及资源。[下一件入口](../../../reverse/01-completed/20261119-34/Plus-Properties/evidence/next.json)
