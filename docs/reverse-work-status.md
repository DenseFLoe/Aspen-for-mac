# 逐文件逆向当前状态

2026-11-19，第 20261119-09 轮。当前处于原版逐文件逆向归档阶段。1,397 个不同原件中，累计 **15 件已完成**，对应 45 条去重来源。其余为 28 件未完成、15 件暂存、1,339 件未开始，处理中和待复核均为 0。[累计台账](../inventories/reverse/20261119-09/ledger.csv)

- **本轮完成文件菜单控件 `AspenTech.Engineering.Controls.FileMenu.dll`。** 两套安装包中的原件都与安装件匹配。已恢复 23 个顶层类型和 124 个方法实现，核对 3 个控件页面、2 个资源字典及 17 个内置菜单模板。实际菜单交互留待 Windows 重建对照。[本轮验收记录](../inventories/reverse/20261119-09/README.md)
- **本机归档**位于 `.local/reverse-round-20261119-09/`。整件 C#、布局与资源 ZIP 及各自的同名说明在 `01-completed/`，`signoff.json` 和 `verification.json` 记录签收与清单增量。[归档指纹](../inventories/reverse/20261119-09/artifacts.csv)
- **下轮首选流程图叠加层 `AspenTech.Engineering.FlowsheetOverlay.dll`。** 同一哈希关联两个产品的安装包成员和两个安装位置，共 4 条来源。程序集有 18 个顶层类型、1 个嵌套类型和 107 个方法定义，旧档只选取 2 个顶层类型。可从 `ActivateOverlaysType` 等未覆盖类型继续，核对原件 SHA-256 `7f8a50243d4ca57fefe9c438912e324e0f9a6a8e21ad287eb709644c217a5907` 后按四条来源同步结果。
