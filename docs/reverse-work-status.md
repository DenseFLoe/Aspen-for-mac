# 逐文件逆向当前状态

2026-11-20，第 20261119-17 轮。1,397 个不同原件中，**22 件已通过静态验收**，对应 65 条不同来源。另有 20 件未完成、16 件暂存、1,339 件未开始。[累计台账](../inventories/reverse/20261119-17/ledger.csv) · [历轮成果](../reverse/01-completed/README.md)

- **案例视图模型已归档。** `AspenTech.AspenCxs.CxsViewModel.dll` 由 Plus 和 Properties 共用。已核对全部 2,439 个方法定义、46 条显式接口映射及进度窗口的控件和事件。两处委托比较已按原件修正，352 个字符串及版本资源重建后与原件逐字节相符。[本轮验收记录](../inventories/reverse/20261119-17/README.md)
- **流程图宿主继续暂存。** `ApwnShell.dll` 等待三个原版流程图程序集的类型定义或等效接口声明。[第 13 轮恢复条件](../inventories/reverse/20261119-13/README.md)
- **下一件为 `AspenTech.AspenPlus.MMForms.Blocks.Flash_HX.dll`。** 该库的 Flash2 输入及结果页面均使用本轮组件。旧档只单独恢复了 374 个顶层类型中的 3 个，整件代码与界面资源待核对。[下一轮入口](../inventories/reverse/20261119-17/README.md#下一轮)
