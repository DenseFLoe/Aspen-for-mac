# 逐文件逆向当前状态

2026-11-19，第 20261119-08 轮。当前处于原版逐文件逆向归档阶段。1,397 个不同原件中，累计 **14 件已完成**，对应 42 条去重来源。其余为 29 件未完成、15 件暂存、1,339 件未开始，处理中和待复核均为 0。[累计台账](../inventories/reverse/20261119-08/ledger.csv)

- **本轮完成起始页控件 `AspenTech.Visualisation.Controls.StartPage.Wpf.dll`。** 两套原包的主件均与安装件匹配。14 个顶层类型、3 个嵌套类型及 245 个方法实现已核对。已恢复 5 个界面布局、10 张图片和 4 套文本。宿主样式、实际交互及 RSS 刷新留待 Windows 重建对照。[本轮验收记录](../inventories/reverse/20261119-08/README.md)
- **本机归档**位于 `.local/reverse-round-20261119-08/`。整件 C#、布局与资源 ZIP 和同名说明在 `01-completed/`。轮次根目录的 `signoff.json` 登记验收证据，`verification.json` 记录四份状态视图的增量。[归档指纹](../inventories/reverse/20261119-08/artifacts.csv)
- **下轮首选文件菜单控件 `AspenTech.Engineering.Controls.FileMenu.dll`。** 两产品共用此件，当前为未完成。安装件 SHA-256 为 `db81bd19b9a31b5a560fe0c91ef62ce66d79e768a8d17809e32f618da5814b2f`，程序集有 23 个顶层类型、124 个方法定义。旧档仅单独选取 3 个类型。下一轮可复用两套 MSI 的既有成员记录核对来源，补齐 `AspenPlusTemplatesSelector` 等类型和所用资源。
