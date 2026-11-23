# NATIVE-340 s69 工具复验

原件、候选、主干版本及结果见[逐件裁定](s69-decision.md)。在普通目录解压固定候选及主干覆盖脚本后执行以下命令。独立脚本只在临时副本改动交付证据，JSON 输出的父目录须已存在。

```text
python -B s69-compare.py --original ORIGINAL --fixed CANDIDATE_ROOT --checker MAIN/handoff/assignments/check-native-coverage.py --out RESULTS/s69-recheck.json
```

覆盖 v1 的 SHA-256 为 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。完整表和删一行后重算 71/107 指纹的副本，均返回 2，摘要同为 1105 覆盖行、354 个原生入口、559 个调用、0 个申报缺口。独立检查用 .NET PEReader 解码原件后比对六元组，完整表零差异；删行后只漏 0x0600000B IL_0044 → 0x06000056，ldftn 0x06000006，实参 ldarg.0。应单独核查交付附表的语义。两组文件哈希、预期输入变化与实测结果在 [JSON](s69-recheck.json)。

固定候选 `tool/audit_340_s69.py` 的 SHA-256 为 `a19b517636282ce7820b85022a3712ea6906ce271fdf734772adafd9130ddd6c`。对删行副本执行该审计器会写回 11 站，退出 0，并再次写出与候选字节相同的错误访问表。它将生成的完整表与自身比较，无法独立验证已提交的文件。

候选 `md_reader.py` 只向方法字典提供 token、RVA、flavor、name。s69 审计随后对不存在的 flags、impl_flags 使用默认值 0，并把零值当成访问结论。候选 `cli_tables.py` 保留 MemberRefParent 与 MethodDefOrRef 的原始编码值，但审计直接与完整 MethodDef 令牌比较，且名为「no MemberRef/MethodImpl alias path」的控制项只判断 MemberRef 计数。该原件的零引用统计由独立元数据 API 确认；单靠此控制项无法检出真实非零样本。修复上述候选工具时应以不同可见性的 MethodDef 和含有效 MemberRef/MethodImpl 的独立配对样本验证。覆盖检查器本轮保持原版。
