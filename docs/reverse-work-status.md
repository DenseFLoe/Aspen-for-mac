# 逐文件逆向当前状态

2026-11-19，第 20261119-15 轮。1,397 个不同原件中，**20 件已通过静态验收**，对应 59 条不同来源。其余为 22 件未完成、16 件暂存、1,339 件未开始。[累计台账](../inventories/reverse/20261119-15/ledger.csv) · [历轮成果](../reverse/01-completed/README.md)

- **Plus 与 Properties 共用的基础组件已归档。** `AspenTech.AspenPlus.Infrastructure.dll` 的 1,407 个方法定义均已核对，两个窗口的布局连接已确认。六个动画光标及 Windows 版本资源均可重建，与原资源逐字节一致。嵌入 COM 事件接口的 Import 标志已单独记录，待 Windows 重建时复核。[本轮验收记录](../inventories/reverse/20261119-15/README.md)
- **流程图宿主继续暂存。** `ApwnShell.dll` 等待三个原版流程图程序集的类型定义或等效接口声明。[第 13 轮恢复条件](../inventories/reverse/20261119-13/README.md)
- **下一件为 `AspenTech.AspenCxs.dll`。** 已定位基础组件对它的 18 条直接调用，涉及案例操作和消息读取。旧档单独选取了 164 个顶层类型中的 8 个。[下一轮入口](../inventories/reverse/20261119-15/README.md#下一轮)
