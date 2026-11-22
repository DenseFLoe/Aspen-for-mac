# NATIVE-337 s45 裁定

**退回补上传并复跑。** 固定原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。候选 [#445 @ a7acc36](https://github.com/DenseFLoe/Aspen-for-mac/tree/a7acc36c623b8897711bfe88f6e35e0fcb6c53b4)，来件见 [#13](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7086171091)。

- 接受 `candidate_owner` 统一大写十六进制的输出约定。独立逐列核实 161 行，唯一变化是 0x12DA 的候选宿主显示从 `0x12bd` 变成 `0x12BD`，数值不变。历史表保留 `72918f68…`，规范化输出记录 `2ef4b467…`。
- 固定提交内 `tool/s37_two_hop.py` 实际 SHA-256 是 `54d8477d9926ce4acf83f69eb10d9389aea688501daf44e049ec8e297c6a09dd`，回执声明 `a2ed873660620bf468db10f6716c812c9ef207c6972e21622411b7ff00a6c271`。相对上轮五个变更路径中缺新版生成器，`tool/s45_tests.py` 在该 head 返回 404。
- 空目录复跑固定生成器得到旧摘要 `72918f68…`。仅删旧表 0x106C 后仍以退出 0 产出 160 行，未找回该站。只改清单布局后旧程序仍给 `candidate_owner=0x12bd`，`original_host=0x11E0`。覆盖 v1 为 307/307/684/0，退出 2，112 未决。任务卡独立推导与复跑条件仍待证明。

[复验记录](s45-review.json) [验收器对照](s45-verifier-notes.md) [s49 任务卡](../../assignments/NATIVE-337-s49.md)。
