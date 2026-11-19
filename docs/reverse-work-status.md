# 逐文件逆向当前状态

2026-11-19，第 20261119-14 轮。1,397 个不同原件中，**19 件已完成**，对应 56 条不同来源。其余为 23 件未完成、16 件暂存、1,339 件未开始。[累计台账](../inventories/reverse/20261119-14/ledger.csv) · [历轮成果](../reverse/01-completed/README.md)

- **模拟操作窗口已通过静态验收。** Plus 与 Properties 共用的 `AspenTech.AspenPlus.WpfSimdll.dll` 已恢复完整 C# 及版本资源。848 个方法定义中，831 个有 IL 实现，16 个是抽象方法，1 个是外部声明。24 个页面的布局、连接与绑定已核对。[本轮验收记录](../inventories/reverse/20261119-14/README.md)
- **流程图宿主仍暂存。** 第 13 轮的 `ApwnShell.dll` 等待 `PfsContainer`、`PfsCtrl` 和 `pfslib` 的原版类型定义或等效接口声明，恢复条件见[第 13 轮记录](../inventories/reverse/20261119-13/README.md)。
- **下一件为 `AspenTech.AspenPlus.Infrastructure.dll`。** 模拟窗口的 17 个方法直接用到其中的接口，包括重新初始化事件和窗口刷新。旧档只单独覆盖了 333 个顶层类型中的 5 个。[下一轮入口](../inventories/reverse/20261119-14/README.md#下一轮)
