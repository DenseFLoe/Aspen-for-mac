# 逐文件逆向当前状态

2026-11-19，第 20261119-13 轮。原版逐文件逆向归档共有 1,397 个不同原件，累计 **18 件已完成**，对应 53 条不同来源。其余为 24 件未完成、16 件暂存、1,339 件未开始。处理中和待复核均为 0。[累计台账](../inventories/reverse/20261119-13/ledger.csv) · [已完成逆向成果](../reverse/01-completed/README.md)

- **本轮归档并暂存 `ApwnShell.dll`。** Plus 与 Properties 共用这份流程图宿主。11,595 个有 IL 实现的方法均已在 C# 中定位，全部 427,651 条 IL 指令与原件吻合。112 个页面的布局连接和 5 项 Windows 资源已核验。本机成果位于 `.local/reverse-round-20261119-13/02-incomplete/Plus-Properties/` 下的原安装路径。[本轮验收记录](../inventories/reverse/20261119-13/README.md)
- **恢复条件。** 新版流程图的 `PfsContainer`、`PfsCtrl`、`pfslib` 三个程序集缺少原版类型定义。宿主中的 133 条相关指令已有记录，21 处 C# 类型引用仍无法绑定。取得对应的 1.0.0.0 接口元数据或等效原版声明后，复核类型继承、属性和事件访问器。代码、IL、资源与各自说明可复用。[归档指纹](../inventories/reverse/20261119-13/artifacts.csv)
- **下轮接续 `AspenTech.AspenPlus.WpfSimdll.dll`。** 本轮宿主直接调用它打开模拟重新初始化和报告窗口。旧档仅按名称收录 59 个方法，下一轮从原件定义令牌及相关界面资源入手。原件 SHA-256 为 `0937ef8eb140cbc27ce4a6f06505e81e494e058d396310cd665a5155f09a1720`。[本轮交接](../inventories/reverse/20261119-13/README.md#归档与下一轮)
