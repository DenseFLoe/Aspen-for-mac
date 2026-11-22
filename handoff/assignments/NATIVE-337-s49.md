# FindComponent.dll 第四十九号续领

NATIVE-337，owner tietoumiao，assigned_seq=49，自 #13 ACK 起 24 小时。固定原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。输入 [#445@a7acc36](https://github.com/DenseFLoe/Aspen-for-mac/tree/a7acc36c623b8897711bfe88f6e35e0fcb6c53b4) 及 [s45 裁定](../outbox/NATIVE-337/s45-decision.md)。

在 #445 更新 head，提交真正实现独立推导的生成器、依赖和 `tool/s45_tests.py` 或等效可复跑测试。原件字节、IAT、异常目录及候选清单、主表分别核对；在空目录先固定所有输入和工具指纹。生成器本身从现有适用输入发现站点，旧附表可作对照。

`candidate_owner` 统一使用 `0x` 前缀和大写十六进制数字。固定输入的 161 行按字段与历史表核对，地址字段按数值比较，新输出完整记录 SHA-256。历史输出 SHA-256 `72918f68564e24dcb5e6f376bc04deacd0cc3ceece560198cfcba0a519d906bf` 作历史回归；s45 大小写规范化表 SHA-256 `2ef4b467155284f011c9fecd7c457c80cbfb9bff148b0acee7c4a60c5e8a20bf` 作本轮固定布局对照。

重跑不提供旧附表、历史表删站及清单边界变更的对照。缺少 0x106C 的历史表仍应独立取得 161 站；把 0x12DA 纳入从 0x12B6 开始的清单片段时，候选宿主为 0x12B6、原件宿主为 0x11E0。用固定提交实际文件复跑 `python -B handoff/outbox/NATIVE-337/check-s33.py ORIGINAL CANDIDATE` 及 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`，提交回执和实际 head。
