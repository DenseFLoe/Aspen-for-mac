# 逐文件逆向当前状态

2026-11-20，第 20261119-18 轮。1,397 个不同原件中，**23 件已通过静态验收**，对应 68 条不同来源。另有 19 件未完成、16 件暂存、1,339 件未开始。[累计台账](../inventories/reverse/20261119-18/ledger.csv) · [历轮成果](../reverse/01-completed/README.md)

- **Flash2 与换热器表单已归档。** `AspenTech.AspenPlus.MMForms.Blocks.Flash_HX.dll` 的 3,386 个方法定义和 188 个页面均已核对。换热器转换窗口的 5 个原版绑定名称待 Windows 实机对照。[本轮验收记录](../inventories/reverse/20261119-18/README.md)
- **流程图宿主继续暂存。** `ApwnShell.dll` 等待三个原版流程图程序集的类型定义或等效接口声明。[第 13 轮恢复条件](../inventories/reverse/20261119-13/README.md)
- **下一件为 `AspenTech.AspenPlus.MMControls.dll`。** Flash2 的输入和结果页均使用它提供的页面基类。本轮表单对它的 48 个直接调用签名已匹配，整件 6,570 个方法定义和相关资源待核对。[下一轮入口](../inventories/reverse/20261119-18/README.md#下一轮)
