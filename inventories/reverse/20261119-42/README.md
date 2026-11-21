# 第 20261119-42 轮 · NGP 共用基础组件

AspenTech.NGP.Infrastructure.dll 通过整件静态验收。已恢复物性接口、单位换算、属性元数据及输入关键字查找。覆盖三个原版安装包成员和本机共用安装路径。[逐件说明](../../../reverse/01-completed/20261119-42/Plus-Properties/%5BProgramFiles64Folder%5D/AspenTech/APrSystem%20V15.0/Engine/Xeq/AspenTech.NGP.Infrastructure.dll.md) · [发布清单](../../../reverse/01-completed/20261119-42/publication.csv)

- 核对全部 940 个方法定义。其中 189 个方法体包含 121,618 条 IL 指令，751 个为原件的抽象声明。五个直接引用完成静态绑定，已复核 4 个回编差异。[方法验收](../../../reverse/01-completed/20261119-42/Plus-Properties/evidence/managed-audit.json)
- 唯一的 1,138 字节 Windows 版本资源已逐字节复原。强名绑定和行为对照留到 Windows 重建阶段。[资源核验](../../../reverse/01-completed/20261119-42/Plus-Properties/evidence/resources.json)

累计 **47 / 1,397** 件通过静态验收，覆盖 **148 条不同来源**。Plus、Properties、Properties 重复子表及共用视图分别更新 4、3、3、4 行。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

处理直接依赖 AspenTech.APED.Core.dll。已定位 Plus 安装包成员和四条同指纹来源。[下一件入口](../../../reverse/01-completed/20261119-42/Plus-Properties/evidence/next.json)
