# NATIVE-340 s81 验收器复验

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ f847024](https://github.com/DenseFLoe/Aspen-for-mac/tree/f8470240a320318bd82ef58f9f0e84e311022be1)。主干基线 0554621e9ac0d627fad1e399d8868da06d1482e6。

1. 0x19608 和 0x19618 的 0x08 位是 FROM_UNMANAGED_RETAIN_APPDOMAIN，CALL_MOST_DERIVED 是 0x10。候选把两个原值 0x0A 的槽均误标，且自检沿用同一错误常量。原件和逐槽对照见 [独立实测](s81-independent-results.json)。[ECMA-335 II.25.3.3.3](https://www.ecma-international.org/wp-content/uploads/ECMA-335_6th_edition_june_2012.pdf) · [运行时 corhdr.h](https://github.com/dotnet/runtime/blob/main/src/coreclr/inc/corhdr.h#L131-L136)
2. 候选自报的两段原始编码 8/31 解出 MethodDef RID 4 和 MemberRef RID 15。候选读成 5/16，逆编码同步减一，往返自检无法发现。本机同布局 AspenHelper.dll 的 PEReader 独立结果两个名称均为 Finalize。候选没有给出其外部样本的内容或 SHA-256，该样本身份仍待核。
3. 原件文件偏移 0x4BE2 的真实 #~ HeapSizes=0，三堆索引皆 2 字节。0x4B70 的 BSJB+6 是版本字段，候选从该处误读为 1。用 `python -B handoff/outbox/NATIVE-340/s81-width-controls.py CANDIDATE` 跑生产 cli_tables.py，固定 SHA-256 `f38128cacd62908dd41ba37ff0b768a6d5d4d30173a1fee5ba66367f6f78fd08`。MemberRefParent 8191/8192、MethodDefOrRef 16383/16384、CustomAttributeType 8191/8192 的上界三个错误均复现。配对同一字段以合法宽度编码，应得到相同逻辑列。CustomAttributeType 8192 行预期 Type 65538、Value 29，实际 2/1。
4. 固定候选 `tool/audit_340_s81.py` SHA-256 `820ce8ad881a948a6e8f1587d0dba0d73ee533023c34b24ffebc200be0132ddd`。同原件上保留原表、仅改 token 0x06000056 摘要首位、仅加原件无此方法的 0x0600FFFF，三次退出 0/1/0。建议按 token 集合双向核对后比较每个摘要。预期 0/1/1，失败项定位具体 token，Markdown 也输出同一裁定。
5. 固定 QA 3517b5ed 的 27 文件版本 SHA-256 `66be66b5812579ba30d4eb391472bff2c5d8524a4d0592670c7251a671f5ac70`。候选实测 L1 exit 2，QA 12 pass、1 不适用，指纹单元实核 130/132。运行 `python -B handoff/outbox/NATIVE-340/s81-qa-controls.py TOOL ORIGINAL ITEM`，需 pefile。L1 固定为 0 以隔离检测单元。只改已声明的 code/types.cs 或 code/s73-il-bodies.bin，原有摘要未更新，两项仍 exit 0。只改已声明的 coverage.csv 可正确报一项差异、exit 2。建议按逐件交付清单及路径安全规则核验文件，用这三个逐项变更作回归，预期均报指纹不符。检测器抛错与未绑定 MethodDef 的两项已知反例在 3517b5ed 亦复现。[输入指纹与结果](s81-qa-controls.json)

[逐项输出](s81-recheck.json) · [固定文件及 SHA-256](s81-fixed-manifest.json)
