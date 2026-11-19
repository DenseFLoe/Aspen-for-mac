# 逐文件逆向当前状态

2026-11-19，第 20261119-11 轮。原版逐文件逆向归档阶段共有 1,397 个不同原件，累计 **17 件已完成**，对应 51 条不同来源。其余为 26 件未完成、15 件暂存、1,339 件未开始，处理中和待复核均为 0。[累计台账](../inventories/reverse/20261119-11/ledger.csv)

- **本轮完成 Aspen Plus 的流程图控件互操作程序集 `PFSCtrlLib.dll`。** 安装包成员和安装件同哈希。已核对 48 个类型、774 个方法定义以及 41 个控件事件的订阅和解绑。C# 无法原样表达的 COM 声明与清理指令已单独保存，控件运行留待 Windows 重建对照。[本轮验收记录](../inventories/reverse/20261119-11/README.md)
- **本机归档**位于 `.local/reverse-round-20261119-11/`。整件 C#、互操作元数据、版本资源 ZIP 及各自的说明在 `01-completed/`，`signoff.json` 和 `verification.json` 记录签收与两条 Plus 来源的状态变更。[归档指纹](../inventories/reverse/20261119-11/artifacts.csv)
- **下轮首选 Aspen Plus 的 Windows 窗体封装 `AxPFSCtrlLib.dll`。** 该文件直接引用本轮的 `PFSCtrlLib, Version=1.0.0.0`。旧档只覆盖 66 个顶层类型中的 1 个。本机原件 SHA-256 为 `de5a2f3a135b8c37f24d3151c21a0869e9c9366c20f743f5e87e851cf4c04c7f`，清单关联 2 条来源。可按原件的 508 个方法定义和 41 个事件核对窗体与控件之间的转发，其中 380 个方法有 IL。
