# 第 20261119-35 轮 · Properties 数据提供组件

`ApedDataProvider.dll`（文件版本 `41.0.0.11`，程序集版本 `41.0.0.1`）通过整件静态逆向验收。Plus、独立 Properties、Enterprise Database Server 的六条包内成员记录与本机安装件匹配，共七条来源。[逐件说明](../../../reverse/01-completed/20261119-35/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/PropertiesDatabase/Bin/ApedDataProvider.dll.selected.md) · [发布清单](../../../reverse/01-completed/20261119-35/publication.csv)

- 核对 257 个类型定义、1,012 个字段、245 个属性、1 个事件、1,900 个方法定义、69,869 条 IL 指令和 749 个异常处理区。36 个隐式实现、10 个显式接口槽及 6 份静态初始化数据通过 Roslyn 静态回编对照。[托管验收](../../../reverse/01-completed/20261119-35/Plus-Properties/evidence/managed-audit.json) · [逐方法索引](../../../reverse/01-completed/20261119-35/Plus-Properties/evidence/methods.csv)
- 恢复 7 份内嵌资源，三个 WinForms 窗体分别核对 4、4、16 个控件及组件，合计 17 次事件注册。Windows 版本资源回编后的 1,002 字节与原件一致。[资源验收](../../../reverse/01-completed/20261119-35/Plus-Properties/evidence/resource-audit.json)
- 完整 C#、带指令字节的 IL、窗体资源和 SQL 资源保存在本机。同步 63 个可发布顶层类型的 C# 选取件，另附原始行号和指纹。[代码选取记录](../../../reverse/01-completed/20261119-35/Plus-Properties/evidence/code-extraction.json)

累计 **40 / 1,397** 个不同原件通过静态验收，覆盖 **121 条不同来源**。Plus、Properties、Properties 重复子表及共用视图分别更新 7, 5, 5, 7 行。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [本地归档指纹](artifacts.csv)

## 下一轮

继续处理 `ApedGateway.dll`。本机安装件指纹与台账一致。补核旧选取源码未覆盖的顶层及嵌套类型、方法和资源。[下一件入口](../../../reverse/01-completed/20261119-35/Plus-Properties/evidence/next.json)
