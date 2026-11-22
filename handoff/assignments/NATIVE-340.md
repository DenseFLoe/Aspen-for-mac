# NATIVE-340 · WrapSaveMergeNNFiles.dll

执行方 tietoumiao。原件来自 Plus/Properties 共用的 AprSystem V15.0/GUI/Xeq，大小 107,048 字节，SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。[固定原件](https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/340/WrapSaveMergeNNFiles.dll) · [原工单及归档入口](https://github.com/DenseFLoe/Aspen-for-mac/issues/340)

这是 AMD64 混合程序集。旧报告记 528 个顶层类型、34 个嵌套类型，527 个顶层类型缺独立选取输出。本件 PE/CLI 实读含模块伪类型的 563 个 TypeDef、188 个 MethodDef，其中 167 个有 IL 实体、19 个有原生实现、2 个无 RVA。55 条 x64 运行时函数记录、入口、原生 MethodDef 与代码导出按地址合并后有 75 个锚点。

按 token 建立完整类型与方法清单，关联 IL/源码和声明，并将原生实现与全量原生反汇编、C/C++ 对照。点明原生入口、托管/原生边界、外部调用和不能唯一绑定的间接目标。分析器发现的额外函数照样纳入，无 RVA 方法须列明声明证据。

交付到 `handoff/inbox/NATIVE-340/`，字段、行号定位及判定结果见[覆盖证据 v1](../standards/native-coverage-evidence.v1.md)。从仓库根执行：

```sh
python handoff/assignments/check-native-coverage.py NATIVE-340
```
