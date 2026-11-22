# FindComponent.dll 第四十五号续领

NATIVE-337，owner tietoumiao，assigned_seq=45，自 #13 ACK 起 24 小时。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。固定输入 [#445@6af6837](https://github.com/DenseFLoe/Aspen-for-mac/tree/6af68379cb5b512e42fe64ec72ebb623f5e23282/handoff/inbox/NATIVE-337) 和 [s41 裁定](../outbox/NATIVE-337/s41-decision.md)。

从当前主表、候选清单及原件调用指令独立得到适用的二跳站点。先按原件验证首跳和 IAT，再以清单的片段范围求候选宿主、以异常目录求原件宿主、以引用位置求主表行。删除 `0x12da` 的固定宿主覆盖。可保留历史附表作回归基准，并记录完整的输入及工具指纹。

在空目录运行生成器和回执命令。固定输入应重放 161 行与既有摘要 `72918f68564e24dcb5e6f376bc04deacd0cc3ceece560198cfcba0a519d906bf`。旧附表删除一站时应独立找回该站或报告输入缺项。在指令不变、候选清单将 0x12DA 归到实际范围 0x12B6 的对照中，输出候选宿主 0x12B6、原件宿主 0x11E0。若格式保留特殊历史大小写，只能由统一格式规则或兼容输出层处理，不得赋予偶然地址语义。

执行 `python -B handoff/outbox/NATIVE-337/check-s33.py ORIGINAL CANDIDATE` 与 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`。提交可复跑生成器、输入指纹、例子、回执和新的固定 PR head。
