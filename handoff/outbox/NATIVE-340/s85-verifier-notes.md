# NATIVE-340 s85 验收器复验

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ bde39b4](https://github.com/DenseFLoe/Aspen-for-mac/tree/bde39b4630809020fd972211e9b64010e13410d7)。主干基线 2cb8a177a47da004ddd4b305f8fe31107c2d2afc。

本轮按固定原件和主干覆盖证据 v1 复验。

1. 固定 cli_tables.py SHA-256 f38128cacd62908dd41ba37ff0b768a6d5d4d30173a1fee5ba66367f6f78fd08 与 s81 相同。用 `python -B s85-width-controls.py CANDIDATE` 重放三类合法元数据。MemberRefParent 8192、MethodDefOrRef 16384、CustomAttributeType 8192 继续错列，低侧配对正确。建议在实际表流逐列选择宽度。回归在边界两边保留等价有效输入，两侧的逻辑值都要吻合。[s81 原记录](s81-verifier-notes.md) · [本轮输出](s85-width-results.json)
2. audit_340_s85.py SHA-256 416924906c448a1aae3b95a5545341bd4649975e29c06b1ff73df11f982087d4。用 `python -B s85-replay.py COVERAGE CANDIDATE ORIGINAL NATIVE-340 s85-pereader-original.json s85-pereader-sample.json`。候选实际读取 BSJB+6 的值 1，真实 #~ 起点 0x4bdc 加 6 的原件字节为 0。差异对照函数接受字典，两个相同键在比较前折叠。单添第二条同键输入预期 duplicate=1，实际仍为 0。它比较的是索引端点，167 个 IL 在审计中只重算并数行。建议从真实流头取 HeapSizes，并在字典转换前检查重复和双向比较 IL 清单，分别报告重复、额外、缺失及摘要差异。回归应包括一条原始记录及只追加同键行的同一证据，预期后一组报出重复键。
3. 原件的四槽原值和修正后位名、同 SHA 的安装样本及 PEReader 实值已核。[运行时头文件](https://github.com/dotnet/runtime/blob/main/src/coreclr/inc/corhdr.h#L131-L136)

[逐项输出](s85-recheck.json) · [固定文件及 SHA-256](s85-fixed-manifest.json)
