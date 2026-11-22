# NATIVE-337 s57 提交（清单↔调用表关联收口）

- 基线：#445 @ 32ce7e38；本轮同一 PR，head 前移。
- 回执路径更正：实际附表是 `code/s37-two-hop.csv`（SHA-256 与重放 2ef4b467… 一致）；此前 s53 回执写的 `code/s45-two-hop.csv` 在固定 head 无对应文件，已改。

## 关联修复（本轮主题）
- 旧索引只用「行号」作键；清单拆成 `native.asm` + `native-part.asm` 后第 28 行撞车，0x12DA 被错绑到 525。
- 新索引键为 **(listing 文件名, 行号)**；同键多行时用导入符号（callee/note）消歧，仍歧义则明确置空并计数，不静默挑一个。
- 实测两布局：单文件 0x106C→525 / 0x12DA→528；拆分后 0x106C(native.asm#L28)→525、0x12DA(native-part.asm#L28)→528，161 站不变。

## 两个布局对照（s53-verifier-notes 步骤）
- 单文件布局与拆分布局各跑一次生成器：rows 161/161；rc 0/0。
- 拆分构造：native.asm 199–226 → native-part.asm 19–46，原位换注释，part 前置 18 行注释；calls.csv 指向该区间的引用改为新文件并 -180 行。

## 判定（原始 stdout）
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条 unresolved 已申报）

## cause（进流程）
回执里的路径与实际文件不一致，是「回执路径手写、没有从产物生成」；修法是回执中的每个产物路径与 SHA-256 都由脚本从实际文件生成并回读。

## 工具指纹（本轮）
- tool/s37_two_hop.py  91bacaa9e7a7a75f9e344958b42c6a58b85b6861b9985ed060ac7d679ab62ba5
- tool/pe_reader.py    c0efbbffc93a0331b86dab66f93564a846890c479edad58e1ac59247053c8037
- tool/s45_tests.py    ee3650f8ecfaa00fc87d33b8600528a604ff3ec809e8a34c485e81921626cbb9
