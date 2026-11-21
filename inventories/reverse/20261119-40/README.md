# 第 20261119-40 轮 · Aspen Data Share 对象访问

AspenDataShareCS.dll 通过整件静态验收，覆盖 Aspen Plus 和 Aspen Properties 的两个安装包成员及本机共用安装路径。源码恢复了对象和属性读写、子对象遍历及变更通知。[逐件说明](../../../reverse/01-completed/20261119-40/Plus-Properties/%5BCommonFiles64Folder%5D/AspenTech%20Shared/Aspen%20Data%20Share%20V15.0/AspenDataShareCS.dll.md) · [发布清单](../../../reverse/01-completed/20261119-40/publication.csv)

- 全部 20,069 个方法定义已核对，20,046 个方法体的 161,619 条 IL 指令与原件逐条对应。针对两个迭代器提前释放时的状态差异，源码显式恢复了原件的空 Dispose 实现。[托管核验](../../../reverse/01-completed/20261119-40/Plus-Properties/evidence/managed-audit.json)
- 16,230 个相关方法中的字符串和 AdbComInterfaces 调用顺序与回编件一致。唯一的 954 字节 PE 版本资源可逐字节复原。运行行为留待 Windows 重建对照。[接口调用核验](../../../reverse/01-completed/20261119-40/Plus-Properties/evidence/selector-check.json) · [资源核验](../../../reverse/01-completed/20261119-40/Plus-Properties/evidence/resources.json)

累计 **45 / 1,397** 个不同原件通过静态验收，覆盖 **140 条不同来源**。Plus、Properties、Properties 重复子表及共用视图依次更新 3、2、2、3 行。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

处理 AspenTech.AspenPlus.Engine.Structures.dll，复用已提取的 Plus 安装包成员。该指纹另有独立 Properties、Properties Enterprise Database Server 及本机安装来源。[下一件入口](../../../reverse/01-completed/20261119-40/Plus-Properties/evidence/next.json)
