# 逐文件逆向当前状态

2026-11-19，第 20261119-02 轮。当前处于开发总纲第 2 步。需要逆向的 1,397 个不同原文件中，累计 8 个已通过逐文件归档验收，对应 24 条去重来源。

- **本轮新增 3 个完成件。** 核清 `SaveMergeNNFiles.dll` 的附件合并行为，补回纯组分数据库表单的视图类型，修正节点树 4 个 COM 访问器的参数。每件均从 Plus、Properties 的安装包和本机安装文件三方核对。[本轮验收记录](../inventories/reverse/20261119-02/README.md)
- **剩余工作**为 35 个未完成、15 个暂存、1,339 个未开始。处理中和待复核均为 0。累计台账保留每个已处理原件的轮次、来源、证据及未完成项的恢复条件。[完成台账](../inventories/reverse/20261119-02/ledger.csv)
- **本机入口**为 `.local/reverse-round-20261119-02/`。本轮的 9 份成果及 9 份同名说明位于 `01-completed/`，四份完整清单在 `views/`，逐项验收和视图核验在 `signoff.json`、`verification.json`。[累计归档指纹](../inventories/reverse/20261119-02/artifacts.csv) · [首次历史交接](../inventories/reverse/20261119-01/README.md)
- **下轮首选 `AspenTech.AspenPlus.Printing.dll`**，版本 `41.0.0.614`，SHA-256 为 `3507b2bfcfbc3a885944a15291b827fdc0d7cc941c51b913659acd84a069e683`。旧 C# 仅选取 6 个顶层类型中的 3 个。安装件元数据显示 3 个嵌套类型、44 个方法和 1 个嵌入资源集，两产品的 CAB 均已定位。可从打印模块注册、生成打印元素的迭代器及预览窗口布局开始逐项核对。
