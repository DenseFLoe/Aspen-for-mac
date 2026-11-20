# 逐文件逆向当前状态

2026-11-20，第 20261119-33 轮。1,397 个不同原件中，**38 件通过静态验收**，覆盖 111 条不同来源。另有 4 件未完成、16 件暂存、1,339 件未开始。[累计台账](../inventories/reverse/20261119-33/ledger.csv) · [历轮成果](../reverse/01-completed/README.md)

- **Aspen Plus 主程序已归档。** 核对 58 个方法定义、应用资源字典及 11 个 PE 资源，已记录启动到共用窗口宿主的调用和六个 COM 接口的原版元数据。实际启动和窗口行为留待 Windows 阶段对照。[本轮记录](../inventories/reverse/20261119-33/README.md)
- **下一件为反应表单组件。** `AspenTech.AspenPlus.MMForms.Reactions.dll` 有 4,166 个方法定义。接续已有的局部反编译，核对其余类型、成员及相关卫星资源。[下一轮](../inventories/reverse/20261119-33/README.md#下一轮)
- **流程图宿主继续暂存。** 取得三个原版流程图程序集的类型定义或等效接口声明后恢复。[恢复条件](../inventories/reverse/20261119-13/README.md)
