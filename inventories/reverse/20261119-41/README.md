# 第 20261119-41 轮 · Aspen Plus 引擎结构

AspenTech.AspenPlus.Engine.Structures.dll 通过整件静态验收，覆盖三个安装包成员和本机共用安装路径。恢复了 Gensen 输入定义、变量转换、报表与工厂分派。[逐件说明](../../../reverse/01-completed/20261119-41/Plus-Properties/%5BProgramFiles64Folder%5D/AspenTech/APrSystem%20V15.0/Engine/Xeq/AspenTech.AspenPlus.Engine.Structures.dll.md) · [发布清单](../../../reverse/01-completed/20261119-41/publication.csv)

- 全部 1,342 个方法定义已核对。1,328 个方法体含 386,249 条原始 IL 指令。最长构造器的 31,086 条指令与回编结果一致。已核对生成名称、闭包及分支差异。[方法核验](../../../reverse/01-completed/20261119-41/Plus-Properties/evidence/managed-audit.json)
- 唯一的 1,182 字节 Windows 版本资源已逐字节复原。强名绑定与运行行为留到 Windows 重建对照。[资源核验](../../../reverse/01-completed/20261119-41/Plus-Properties/evidence/resources.json)

累计 **46 / 1,397** 件通过静态验收，覆盖 **144 条不同来源**。Plus、Properties、Properties 重复子表及共用索引分别更新 4、3、3、4 行。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

处理 AspenTech.NGP.Infrastructure.dll。它是本轮核对的直接依赖，已定位 Plus 安装包成员及四条同指纹来源。[下一件入口](../../../reverse/01-completed/20261119-41/Plus-Properties/evidence/next.json)
