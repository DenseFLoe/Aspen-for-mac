# NATIVE-340 s89 验收器复验

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 05917da](https://github.com/DenseFLoe/Aspen-for-mac/tree/05917da0d1002cc17640c123cf67cd684117863e)。主干基线 54d8dd1dcb8bbbee003535a8270638fb4da6e187。

覆盖复跑 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE`，固定 SHA-256 27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8。开工与交付见原候选及 [#13 7094229742](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7094229742)。

1. 直接运行 `python -B s89-width-controls.py CANDIDATE_ROOT`。固定 cli_tables.py 的 SHA-256 是 fb52352a9c6419229482787de18f9b0bb0b7d123b0a3428b4e115fd4abad9455。实际读表入口仍将 MemberRefParent、MethodDefOrRef、CustomAttributeType 的 tag bits 定义为 2/2/2。保留 [s85 原记录](s85-verifier-notes.md) 的合成表流配对。在 MemberRefParent 8192 行的布局中，预期 Class 65537、Name MethodName、Signature 29，实测 1、空字符串、17。MethodDefOrRef 16384 行的正确 Body/Declaration 2/4 被读为 262146/0。CustomAttributeType 8192 行的正确 Type/Value 65538/29 被读为 2/1。修正表模式并让实际 parser 和阈值检查共用定义。继续用两侧样本核对列值和后继列位置。[本轮实测](s89-width-results.json)

2. `python -B s89-digest-controls.py CANDIDATE_ROOT ORIGINAL`。audit_340_s89.py 的 SHA-256 是 e5ce33401c14f4acf01b7340bc4678b18c2814ea6d2dd077846ba9c3b6792f82。原件固定，只改交付 s89-il-digests.csv 中 0x06000001 的摘要并重新计输入指纹，预期核验报告一个内容差异。实测脚本先覆盖该表，再读取历史 s77 表，仍 exit 0、四类差异全 0。改 s77 的同一摘要才 exit 1，content_diff=1。建议复验入口打开只读的 s89 交付表，与从原件重算的结果逐项比较。原始组预期 exit 0，单改 s89 组预期 exit 1 且 content_diff=1。[成对复跑](s89-digest-controls.json)

3. 原件 19 项原生 IAT 缺项和 QA 的托管同偏移漏报见 [s85 补证](s85-qa-supplement.md)。两类证据均需定位至各自真实站点。

[逐项输出](s89-recheck.json) · [固定文件及 SHA-256](s89-fixed-manifest.json)
