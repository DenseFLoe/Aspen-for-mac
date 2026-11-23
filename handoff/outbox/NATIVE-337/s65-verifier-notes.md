# NATIVE-337 s65 固定交付复验

固定 [#445 @ 25ecf964](https://github.com/DenseFLoe/Aspen-for-mac/tree/25ecf96494ed0c27ba46b4181dec2cd526053a77)、原件 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`、主干 `d29e63566fa3969bc38837b38fddcb1f9ff5c044`。逐文件核对 71 个沿用 blob 和 7 个新增 blob。按 [任务卡](../../assignments/NATIVE-337-s65.md) 和 [覆盖证据 v1](../../standards/native-coverage-evidence.v1.md) 第 4、5 项复跑。

    python -B s65-recheck.py --fixed FIXED --original ORIGINAL --output s65-recheck.json

基线重放逐字节匹配候选逐站明细，输出 SHA-256 `b1e1922955747464a680140189407c2dfe6426e5ade2872c8ee64e64c647acd2`。六场景和自检均退出 0，自检三类各命中一处。单文件、同目录拆分、子目录拆分均保留 161 站、0x106C→525、0x12DA→528。覆盖 v1 退出 2，307 个覆盖项、307 个原生条目、684 个调用、0 个已申报覆盖缺口，另有 112 个已申报未决调用。延续整件未通过状态。

## 本轮新对照

候选 `tool/s65_counterexamples.py` SHA-256 `914bb22aef00292d20ab13f36bb15c3fb7d88c185db53b58ff74efe4d206c783`。原件 0x106C 经 0x4AA3 和 IAT 0x75E8 绑定到 `mfc140.dll!#2344`。只改 `calls.csv` 第 525 行的 callee 为 `mfc140.dll!#23440`，重算交付输入指纹。预期该站分类为 `contradiction`，实测脚本退出 0、161 站均 `ok`，CSV SHA-256 与基线相同。把同一字段改为 `OLEAUT32.dll!#313` 时，本版已能定位 0x106C 的矛盾。分类器当前按子串核验。按 PE 导入库、符号名或完整序号解析并核对该字段，在同一原件上验证有效目标、不同目标和带共同前缀的不同序号。

只将 `code/native.asm` 第 28 行指令换成注释并重算指纹，原件和主表保持原样。候选退出 0，0x106C 从逐站表消失，剩余 160 站均 `ok`。覆盖 v1 正确退出 1，报 `call site reference lacks instruction`。建议将独立从原件及固定反汇编核验得出的 161 站地址作为对照清单，逐站关联候选布局。单站失去清单证据时应显式保留 0x106C 及其缺口，或明确报错。正常布局保留相同站集。

覆盖 v1 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。沿用 [s61](s61-verifier-notes.md) 的导入目标检查痛点，两份仅改 callee 的输入仍同报退出 2，计数一致。完整输入指纹、逐站字段和命令输出见 [复跑记录](s65-recheck.json)。下一张卡可复用本轮对照，要求原件目标身份与证据站集两项均明确核验。
