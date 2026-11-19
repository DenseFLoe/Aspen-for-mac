# 逐文件逆向当前状态

2026-11-19，第 20261119-07 轮。当前处于原版逐文件逆向归档阶段。1,397 个不同原件中，累计 **13 件已完成**，对应 39 条去重来源。其余为 30 件未完成、15 件暂存、1,339 件未开始，处理中和待复核均为 0。[累计台账](../inventories/reverse/20261119-07/ledger.csv)

- **本轮完成组分查找组件 `AspenTech.AspenPlus.WpfFindComponent.dll`。** 两套原包和安装件指纹相同。903 个方法定义已逐一核对，旧档中 HTTP 客户端初始化的四条诊断已解决；27 个页面、1 份主题字典及 6 张图片已从主件相邻的英文资源卫星恢复。页面取值及联网查询留待 Windows 重建对照。[本轮验收记录](../inventories/reverse/20261119-07/README.md)
- **本机归档**位于 `.local/reverse-round-20261119-07/`。整件 C#、布局 ZIP 和同名说明在 `01-completed/`。轮次根目录的 `signoff.json` 登记验收证据，`verification.json` 记录四份状态视图的增量。[归档指纹](../inventories/reverse/20261119-07/artifacts.csv)
- **下轮首选 `AspenTech.Visualisation.Controls.StartPage.Wpf.dll`。** 此件为两产品共用，台账状态为未完成。已核对安装件 SHA-256 为 `73193ded5722619da8d661035129f6a38968acad4ce371de83f0cc8158950b34`。旧档仅单独选取 14 个顶层类型中的 1 个。先核对两套原包的既有成员指纹，再恢复整件，补核 `GetStartedSidebar` 等未选取类型、3 个嵌套类型及其实际使用的资源。
