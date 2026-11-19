# 逐文件逆向当前状态

2026-11-19，第 20261119-16 轮。1,397 个不同原件中，**21 件已通过静态验收**，对应 62 条不同来源。另有 21 件未完成、16 件暂存、1,339 件未开始。[累计台账](../inventories/reverse/20261119-16/ledger.csv) · [历轮成果](../reverse/01-completed/README.md)

- **案例操作组件已归档。** `AspenTech.AspenCxs.dll` 由 Plus 和 Properties 共用。已核对全部 1,654 个方法定义、13 个 COM 导入接口和两个下拉编辑器。托管字符串与 Windows 版本资源均已从可编辑文件重建，逐字节一致。[本轮验收记录](../inventories/reverse/20261119-16/README.md)
- **流程图宿主继续暂存。** `ApwnShell.dll` 等待三个原版流程图程序集的类型定义或等效接口声明。[第 13 轮恢复条件](../inventories/reverse/20261119-13/README.md)
- **下一件为 `AspenTech.AspenCxs.CxsViewModel.dll`。** 该库在 132 个方法中直接调用本轮组件 450 次。所用的 52 个成员签名均已核对，旧档只单独恢复了它的 174 个顶层类型中的 7 个。[下一轮入口](../inventories/reverse/20261119-16/README.md#下一轮)
