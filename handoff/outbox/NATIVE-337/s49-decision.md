# NATIVE-337 s49 裁定

退回补齐固定提交。原件 FindComponent.dll SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。候选 [#445 @ 2c9db565](https://github.com/DenseFLoe/Aspen-for-mac/tree/2c9db5656867da19de3c6b53ee4400220b407fd5)，[交付通知](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7086434998)。

本次提交增补两个回执，PE 读取器新增节头位置字段，实际 SHA-256 `5383333399175b94f3624d5ef95db2fbffdc1d8c0f23b6983ef3cc01e4e87367` 与回执测试输出相同。生成器仍为 `54d8477d9926ce4acf83f69eb10d9389aea688501daf44e049ec8e297c6a09dd`，声明的新版 `a2ed873660620bf468db10f6716c812c9ef207c6972e21622411b7ff00a6c271` 未上传。固定提交读取 `tool/s45_tests.py` 返回 404。

| 对照 | 预期 | 固定候选实测 |
| --- | --- | --- |
| 无旧表 | 161 站 | 退出 1，尝试打开 `code/s33-two-hop.csv` |
| 历史表删 0x106C | 161 站并找回该址 | 退出 0，160 站，未找回 |
| 只变更清单片段 | 0x12DA 的候选宿主 0x12B6，原件宿主 0x11E0 | 候选宿主仍为 0x12bd，原件宿主仍为 0x11E0 |
| 固定输入生成 | 规范化摘要 2ef4b467… | 退出 0，161 站，旧摘要 72918f68… |

覆盖 v1 实测 307 覆盖、307 原生入口、684 调用、0 声明缺口，退出 2，仍有 112 项未决调用。历史附表检查 `check-s33.py` 退出 0。正式台账采用可复核的 #13 通知时间补记本轮开工和提交，原开工回执中的 `06:0x` 原样保留。

[复跑记录](s49-review.json) [验收器对照](s49-verifier-notes.md) [s53 续领卡](../../assignments/NATIVE-337-s53.md)
