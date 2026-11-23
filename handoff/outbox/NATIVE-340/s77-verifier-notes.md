# NATIVE-340 s77 验收器复验

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 858a23f](https://github.com/DenseFLoe/Aspen-for-mac/tree/858a23f9070d0a99555b695082d4dc57a4c13258)。主干基线 6f39d81802e8d60331c0c6706f192ae7d45ac52a。

主干覆盖命令 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE`。独立复核命令 `pwsh -File s77-oracle.ps1 -Original ORIGINAL -Delivery CANDIDATE`，见[复跑输出](s77-oracle.json)。[CLR 标志定义](https://github.com/dotnet/runtime/blob/main/src/coreclr/inc/corhdr.h#L131-L136)

- `audit_340_s77.py` SHA-256 `c751ba77579b44568b7040c828cdefdef9187bf5db3bb462deb7ae0b6dad8140` 的 `(v >> 1) + 1` 使已按一基编号编码的 MethodImpl RID 再加 1。真实构建的显式接口样本原始两列 4、2，预期 RID 2、1，按候选表达式得到 3、2。提供逐项绑定而非预置真值，正反例均经过生产解析。
- `cli_tables.py` SHA-256 `f38128cacd62908dd41ba37ff0b768a6d5d4d30173a1fee5ba66367f6f78fd08` 与 [s73](s73-verifier-notes.md) 一致。沿用真实表流的 8191／8192 及 16383／16384／32768 对照，实测对／错及对／错／对，错误宽度连带错读后续列。候选孤立宽度样例通过，需将规则接入生产表读取。
- `preflight.py` SHA-256 `23963f3fd370524bffb0536dcd31572e7199b91d0e9298bc44935c11d86a21ea` 未读取 s77 IL 指纹表。只改同一原件 token 0x06000056 的摘要并重算双输入指纹，预期 0→1 个问题，实测 0→0、扫描 0→0 行。复用 [s73](s73-verifier-notes.md) 同类用例，并将新表接入由 PE 方法体重算 SHA 的调用路径。
- 复现表流和摘要配对使用 `python -B .local/patrol-0457/review340/independent/replay.py`，引用本机 s73 夹具与只读复核。配对输入哈希和输出在逐项记录中。

[逐项输出](s77-recheck.json) · [固定文件及 SHA-256](s77-fixed-manifest.json)
