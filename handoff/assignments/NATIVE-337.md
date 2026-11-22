# NATIVE-337 · FindComponent.dll

执行方 tietoumiao。原件来自 Plus/Properties 共用的 AprSystem V15.0/GUI/Xeq，大小 82,984 字节，SHA-256 为 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。[固定原件](https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/337/FindComponent.dll) · [原工单及归档入口](https://github.com/DenseFLoe/Aspen-for-mac/issues/337)

旧成果按名称去重后只覆盖 11 个原生函数。先从 AMD64 PE 建立代码段、入口与函数边界，再交 Ghidra 等分析器的全部发现及 editable C/C++ 和反汇编对照。原件的 113 条运行时函数记录、代码导出和 PE 入口去重后有 115 个地址锚点。用 `gxElectrolyteWizard` RVA `0x31d0` 和 `gxReorderComp` RVA `0x3bf0` 对照旧符号，列出其余地址、外部调用和重要数据引用；工具发现的其他入口一并纳入。按实际证据标记无法恢复的项。

交付到 `handoff/inbox/NATIVE-337/`，字段、行号定位及判定结果见[覆盖证据 v1](../standards/native-coverage-evidence.v1.md)。从仓库根执行：

```sh
python handoff/assignments/check-native-coverage.py NATIVE-337
```
