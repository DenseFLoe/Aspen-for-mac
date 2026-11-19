# 逐文件逆向当前状态

2026-11-19，第 20261119-10 轮。当前处于原版逐文件逆向归档阶段。1,397 个不同原件中，累计 **16 件已完成**，对应 49 条不同来源。其余为 27 件未完成、15 件暂存、1,339 件未开始，处理中和待复核均为 0。[累计台账](../inventories/reverse/20261119-10/ledger.csv)

- **本轮完成流程图叠加层 `AspenTech.Engineering.FlowsheetOverlay.dll`。** 原件的 4 条来源同哈希。已核对全部 19 个类型、107 个方法定义、两张图例 PNG，以及画布绑定、事件和宿主接口。窗口显示与拖动留待 Windows 重建对照。[本轮验收记录](../inventories/reverse/20261119-10/README.md)
- **本机归档**位于 `.local/reverse-round-20261119-10/`。整件 C#、资源 ZIP 及各自的同名说明在 `01-completed/`，`signoff.json` 和 `verification.json` 记录签收与清单增量。[归档指纹](../inventories/reverse/20261119-10/artifacts.csv)
- **下轮首选 Aspen Plus 的流程图控件互操作程序集 `PFSCtrlLib.dll`。** 旧档仅覆盖 48 个顶层类型中的 2 个。本机原件 SHA-256 为 `5073b8f277f687758a9d064a1508d6ae3439b648f5f4787455efcaf6e4133303`，清单关联 2 条来源。核对安装包成员后，可按原定义恢复 774 个方法和 82 个事件，分别核实 128 个有 IL 的方法与其余声明的实现方式。
