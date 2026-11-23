# NATIVE-340 s93 验收器复验

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 22135b6](https://github.com/DenseFLoe/Aspen-for-mac/tree/22135b6596af10a318fc80483b9c20d3680115bb)。主干基线 263497c50f7a59ea343f2cf80ba41a168dce7af1。

初次收件 f67341fa2d201f165e1f2f8573b1a7fa114a18ed 改动 10 路径。08:05:37Z 补件 22135b6596af10a318fc80483b9c20d3680115bb 增改 4 路径，含回执、两份 s93 指纹及生成回执脚本。独立固定并复核 226 项 SHA-256；本文复跑全部绑定补件后的 head。真实原件的 #~ 流头 HeapSizes=0，MemberRef[1].Class=17 → TypeRef[2]，CustomAttribute[1].Type=19 → MemberRef[2]；回执将后者原值写成 18。交付时间取 [#13 收件](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7094795608)，[后续说明](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7094808670)明确以最近前序入口归属部分站点。

1. `python -B s93-width-controls.py CANDIDATE_ROOT` 的 SHA-256 为 `26a7eb09e7192fd5340403071c52a7b60bd606a4bfb09e6edfa4675ffb0064ea`。候选 `tool/cli_tables.py` 的 SHA-256 为 `9e9ca1a1ded6d6e1241bccb2864d6fb025b5ccece3ae5105ce5ca088dcd2acf7`。`read()` 第 128、139 行仍据 TABLES 中的 2/2/2 位取列宽，第 147 行才将 CODED_COLUMNS 用于 `_decoded`。8 个有效表流应全匹配、exit 0，固定候选实测 4 个失败、exit 1。MemberRefParent 在 8192 行时正确 Class/Name/Signature 为 65537/MethodName/29，实测 1/空/17；CustomAttributeType 在 8192 行时正确 Type/Value 为 65538/29，实测 2/1；MethodDefOrRef 在 16384 和 32767 行时正确 Body/Declaration 为 2/4，实测 262146/0。四个用例有原始布局、预期和错列位置。[八组实测](s93-width-results.json)

2. `python -B s93-review-controls.py CANDIDATE_ROOT ORIGINAL CHECKER --require-iat` 依赖 pefile 2024.8.26，复跑脚本 SHA-256 `bb51858526b14a91c1e3e278985d71846f1c5e92c47ea6d31f4742bcf0218c7a`。其中以 `python -B tool/verify_il_digests.py --binary ORIGINAL --table TABLE` 执行四组只读试验，验证器 SHA-256 `3693094d52e76e40ba43aee56cbb6d379defde219a43ce10d3a27c654a25aec6`。原表 167 行 exit 0；只改 `row=67/0x06000043`、漏该行、重复该行均 exit 1 且各报一处，同一试验输入执行前后 SHA-256 一致。

3. 上述复跑另逐一按原件字节解码 19 条 RIP 相对 JMP，将计算得到的槽位映射至 PE 导入表。19/19 站点字节、目标符号正确。19/19 位于所报 caller 的清单范围外，`--require-iat` 实测 exit 1。0x2BCF 位于原件 .pdata `[0x2B74,0x2BC5)` 之外；其 `48 FF 25 82 34 00 00` 的位移是 13442，实际槽是 0x6058，清单文本写成 3441189。0x4711–0x4765 的 15 个相邻跳板全填 0x3660，该函数在 0x366D RET。另 3 条的 note/site 分别为 0x4777/0x477D、0x47CB/0x47D1、0x488E/0x4894，前者是各自已经结束的另一条 6 字节跳板。原件调用者或独立入口证据不足时，登记待核、写清恢复条件。[逐站字节、归属与回归对照](s93-recheck.json)

4. 正式命令 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission UNIT`，检查器 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。`verify()` 第 276–286 行检查 owner 存在及 listing 有调用/跳转字样；原封候选包含上述 3 组 note/listing 错配，但仅输出 1105/354/578/0，因 unresolved 退出 2。成对试验取原件 0x2B7A，只将合法 caller 0x2B74 换成 0x3660，其余调用字段与 listing 字节不动，更新输入指纹，实测完全相同的输出。建议以 0x2B7A 作正例，并将只换 owner、只换 note RVA 各作反例；新增核验应标注冲突站点与证据行，给出明确失败或待核。这是主干覆盖 v1 的机械检查限制，本轮没有修改验收器。

5. 补件的 QA 原始输出为 8 pass、5 error，提示缺 pefile。按固定 QA 27007e5a（gate.py SHA-256 5aeb8613c274bf843002bab720d13d2496a155ccb91476d5b9b50f660a1ef6b1），使用 pefile 2024.8.26 与 capstone 5.0.7 执行 python -B qa/gate.py --task NATIVE-340 --item-dir UNIT --original ORIGINAL --l1-path CHECKER。实测 13 pass、0 error，omitted-sites 319 输入、0 缺项，整体仍 exit 2。这个单元确认 67 个原生站点已列出，caller 归属仍须单独核验。[独立 QA 输出](s93-qa-stdout.txt)

[逐项输出](s93-recheck.json) · [固定文件及 SHA-256](s93-fixed-manifest.json)
