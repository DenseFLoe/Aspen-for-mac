# NATIVE-340 s97 续领

owner tietoumiao，assigned_seq=97，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 22135b6](https://github.com/DenseFLoe/Aspen-for-mac/tree/22135b6596af10a318fc80483b9c20d3680115bb)。主干基线 263497c50f7a59ea343f2cf80ba41a168dce7af1。

在 `tool/cli_tables.py:read()` 将 TABLES 与 CODED_COLUMNS 合为逐列的位数/目标表定义，行宽累加、字段读取及解码使用同一来源。MemberRefParent/CustomAttributeType 的 8191、8192 对，以及 MethodDefOrRef 的 16383、16384、32767、32768 组都要检查下一列；运行 `python -B s93-width-controls.py CANDIDATE_ROOT` 应 exit 0，现有错列版本应 exit 1 并定位表列。修正 `calls.csv` 最后 19 行与 `code/native.asm` 的关联，按每个站点的真实控制流和原件函数边界给出 caller 或待核依据，明确 0x2BCF 的前缀与位移以及最后三跳板的 site；以 0x2B7A 原属 0x2B74 为正例，只改为 0x3660 为反例，反例须非零并报告 site、owner、listing 行。保留 167 条只读摘要及四组对照。回执更正 CustomAttribute[1].Type 的原值 19；将可运行的 PEReader `.csproj` 与源码给出固定可回读路径（本轮所指 `_t14/pereader` 返回 404），保留 0x06000057 arg0 的静态恢复条件。 补件中的 QA 依赖缺失，请在回执中区分 8 pass/5 error 的原始环境与依赖齐全后 13 pass/0 error 的运行。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-340/s93-decision.md)
