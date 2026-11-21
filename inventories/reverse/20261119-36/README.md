# 第 20261119-36 轮 · Properties 数据网关

`ApedGateway.dll`（文件版本 `41.0.0.11`，程序集版本 `41.0.0.1`）通过整件静态逆向验收。Plus、独立 Properties、Enterprise Database Server 的六个包内成员与本机安装件指纹一致，共七条来源。[逐件说明](../../../reverse/01-completed/20261119-36/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/PropertiesDatabase/Bin/ApedGateway.dll.selected.md) · [发布清单](../../../reverse/01-completed/20261119-36/publication.csv)

- 核对 132 个类型定义、958 个方法定义、8,263 条 IL 指令和 46 个异常处理区。以 Roslyn 静态回编核对 14 个隐式实现、24 个隐式声明、4 个 P/Invoke 接口和 8 个显式接口槽。[托管验收](../../../reverse/01-completed/20261119-36/Plus-Properties/evidence/managed-audit.json) · [逐方法索引](../../../reverse/01-completed/20261119-36/Plus-Properties/evidence/methods.csv)
- 原件唯一的 PE 版本资源回编后与原件 974 字节一致。[资源验收](../../../reverse/01-completed/20261119-36/Plus-Properties/evidence/resources.json)
- 完整 C# 和带指令字节的 IL 保存在本机。发布 126 个可同步的顶层类型、可编辑版本资源和静态验收证据。旧版传递依赖、签名、绑定和数据库运行行为留待 Windows 重建对照。[选取记录](../../../reverse/01-completed/20261119-36/Plus-Properties/evidence/code-extraction.json)

累计 **41 / 1,397** 个不同原件通过静态验收，覆盖 **128 条不同来源**。Plus、Properties、Properties 重复子表与共用视图分别更新 7、5、5、7 行。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [本地归档指纹](artifacts.csv)

## 下一轮

继续处理 `AdsDataMap.dll`。复用指纹一致的 Plus 安装包提取件，按定义令牌复查历史局部成果之外的类型、方法和资源。[下一件入口](../../../reverse/01-completed/20261119-36/Plus-Properties/evidence/next.json)
