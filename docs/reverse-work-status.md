# 逐文件逆向当前状态

2026-11-19，第 20261119-01 轮。当前处于开发总纲第 2 步。首次历史交接已完成，58 个不同原文件均有处置和来源关联，后续按常规台账接续。

- **本轮通过 5 个原文件**，其中 `Interop.Aosapfs.dll` 从 15 份局部导出补到整程序集验收，另 4 个历史完成件逐一通过新规则复核。五件均由 Plus 与 Properties 共用，共对应 15 条去重来源。[本轮记录](../inventories/reverse/20261119-01/README.md)
- **剩余工作**覆盖当前需要逆向清单中的 38 个未完成、15 个暂存及 1,339 个未开始的不同内容。当前没有处理中或待复核项。逐件缺口和恢复条件见[完成台账](../inventories/reverse/20261119-01/ledger.csv)。
- **本机入口**在 `.local/reverse-round-20261119-01/`。`01-completed/` 保存 15 份成果与同名说明，`history/audit.json` 指向保留的历史局部成果，`views/` 为四份完整状态视图，`verification.json` 记录逐行、逐指纹复核结果。[本轮归档指纹](../inventories/reverse/20261119-01/artifacts.csv)
- **下轮首选 `SaveMergeNNFiles.dll`**，版本 `38.0.0.301`，原 SHA-256 为 `a610bfe69f5b86a04d2ace8a8f01fa6048183bd3330ee0e7367a1e6c02671511`。两个产品的安装包载荷可读。现有 IL 已定位 6 个方法，旧 C# 仅按类型导出。先对整程序集的 1 个顶层类型、1 个嵌套类型、方法体和资源建立覆盖对照。`WrapSaveMergeNNFiles.dll` 是调用方，单独保留其混合模式缺口。
