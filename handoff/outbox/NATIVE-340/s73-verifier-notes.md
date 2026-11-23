# NATIVE-340 s73 验收器复验

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 3b440bf](https://github.com/DenseFLoe/Aspen-for-mac/tree/3b440bf0a4bf207d479eccc148232062a7f1a6a0)。主干基线 581aa65bc65667e09760dda9e5b954290d9d7e2b。

复跑 `pwsh -File s73-clr.ps1 -Original ORIGINAL -Fixture FIXTURE`，写为 REVIEW_ROOT/s73-clr.json；FIXTURE 指向 REVIEW_ROOT/CliBindingFixture.dll。按 [s65 IL/EH 证据](../NATIVE-340/s65-verifier-notes.md)用同一原件输出 s73-il.json，随后执行 `python -B s73-review.py REVIEW_ROOT BASE ORIGINAL`。REVIEW_ROOT/fixed 为固定候选，REVIEW_ROOT/fixed-manifest.json 为本页所链的清单。

- cli_tables 对 MemberRefParent 用 2 个标记位计算列宽，8191 项通过、8192 项误读父索引和后续列。MethodImpl 两列也用 2 个标记位，项数 16383／16384／32768 时通过／失败／通过。前者需要 3 位，后者需要 1 位。应由同一 ECMA-335 编码定义派生宽度及解码；所附小型表流逐例输出输入哈希、预期及实测。
- 编译独立显式接口实现。同一类型里两个 Private 方法，一个有 MethodImpl、另一个无绑定，PEReader 给出真／假。候选审计的模块级 bool(impl_rows) 给出真／真。应将 MethodBody 和 MethodDeclaration 分别规范化到具体行再关联，每个方法单独判定。
- 候选预检访问表读取 MethodDef Flags 的正例通过。只修改 0x06000056 的 64 字符 IL SHA 首位并记录两份输入的 SHA 时，访问检测均报 0。所交付真实摘要与原件相符。建议按 token 从原件方法体重新哈希，成对结果为 0→1，并定位该 token。

[逐项输出](s73-recheck.json) · [固定文件及 SHA-256](s73-fixed-manifest.json)
