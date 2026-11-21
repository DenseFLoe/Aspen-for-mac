# 第 20261119-37 轮 · Aspen Data Share 数据映射

Aspen Plus 与 Aspen Properties 共用的 AdsDataMap.dll（文件版本 41.0.0.2，程序集版本 41.0.0.0）通过整件静态验收。同指纹对应两个安装包成员及一条本机安装来源。[逐件说明](../../../reverse/01-completed/20261119-37/Plus-Properties/%5BCommonFiles64Folder%5D/AspenTech%20Shared/Aspen%20Data%20Share%20V15.0/AdsDataMap.dll.md) · [发布清单](../../../reverse/01-completed/20261119-37/publication.csv)

- 对照 110 个类型定义、1,016 个方法定义、19,232 条 IL 指令、96 个异常处理区和 90 个显式接口槽。Roslyn 内存编译核对自动访问器、事件与构造方法。[托管验收](../../../reverse/01-completed/20261119-37/Plus-Properties/evidence/managed-audit.json) · [逐方法索引](../../../reverse/01-completed/20261119-37/Plus-Properties/evidence/methods.csv)
- 发布完整可编辑 C# 及可回编的 PE 版本资源。带指令字节的 IL 和编译器生成成员的展开视图保留在本机。Windows 绑定、映射读写及运行行为留待重建对照。[资源验收](../../../reverse/01-completed/20261119-37/Plus-Properties/evidence/resources.json)

累计 **42 / 1,397** 个不同原件通过静态验收，覆盖 **131 条不同来源**。Plus、Properties、Properties 重复子表及共用视图分别更新 3、2、2、3 行。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [本地归档指纹](artifacts.csv)

## 下一轮

处理 Aspen Data Share 的 AdsAccessor.dll。复用已有 Plus 安装包提取件，先核对原件格式及内部资源。[下一件入口](../../../reverse/01-completed/20261119-37/Plus-Properties/evidence/next.json)
