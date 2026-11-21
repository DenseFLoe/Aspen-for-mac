# 第 20261119-38 轮 · Aspen Data Share 数据访问

Aspen Plus 与 Aspen Properties 共用的 AdsAccessor.dll（文件版本 41.0.0.2，程序集版本 41.0.0.0）通过整件静态验收。同一指纹覆盖两份安装包成员和一条本机共用安装来源。[逐件说明](../../../reverse/01-completed/20261119-38/Plus-Properties/%5BCommonFiles64Folder%5D/AspenTech%20Shared/Aspen%20Data%20Share%20V15.0/AdsAccessor.dll.md) · [发布清单](../../../reverse/01-completed/20261119-38/publication.csv)

- 核对 954 个类型、20,069 个方法定义、161,619 条 IL 指令、8 个异常处理区、14 个显式接口槽及唯一的 PE 版本资源。[托管验收](../../../reverse/01-completed/20261119-38/Plus-Properties/evidence/managed-audit.json) · [资源验收](../../../reverse/01-completed/20261119-38/Plus-Properties/evidence/resources.json)
- Roslyn 5 Release 可在内存回编整件 C#。两个迭代器回编后的 Dispose 会重置状态，原版 Dispose 为空。原版状态机和 IL 对照存于本机，供 Windows 重建时复验 COM 激活、共享记录读写及迭代器行为。[逐件说明](../../../reverse/01-completed/20261119-38/Plus-Properties/%5BCommonFiles64Folder%5D/AspenTech%20Shared/Aspen%20Data%20Share%20V15.0/AdsAccessor.dll.md)

累计 **43 / 1,397** 个不同原件通过静态验收，覆盖 **134 条不同来源**。Plus、Properties、Properties 重复子表及共用视图分别更新 3、2、2、3 行。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [本地归档指纹](artifacts.csv)

## 下一轮

处理共用记录模型组件 AdbDataModel.dll。复用已有 Plus 安装包提取件。[下一件入口](../../../reverse/01-completed/20261119-38/Plus-Properties/evidence/next.json)
