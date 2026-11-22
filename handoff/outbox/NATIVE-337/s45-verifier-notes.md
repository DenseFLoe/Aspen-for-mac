# NATIVE-337 s45 验收器复验

复验对象是 [#445 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/a7acc36c623b8897711bfe88f6e35e0fcb6c53b4/handoff/inbox/NATIVE-337)。原件 FindComponent.dll SHA-256 为 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。任务卡要求复现当前交付生成器与附件，并以固定原件和当前布局验证二跳宿主。

[check-s33.py 固定版本](https://github.com/DenseFLoe/Aspen-for-mac/blob/b04042ca387010579df70bbfccbf882460435824/handoff/outbox/NATIVE-337/check-s33.py) 的 Git blob 为 28bb7a850bd88dddd84d35c1fcb2efd8eb6d1201，SHA-256 为 467c949dd92d04db4d92dc248c8d3690d282ec9e54eb7929ec97cee21f30e58f。执行命令如下。

    python -B handoff/outbox/NATIVE-337/check-s33.py ORIGINAL CANDIDATE

保持原件、主表和候选清单固定。只将当前附件 code/s37-two-hop.csv 内 0x12DA 的 candidate_owner 从 0x12BD 改成 0x12B6，并同步回执内的附件 SHA-256。正确附件为 2ef4b467155284f011c9fecd7c457c80cbfb9bff148b0acee7c4a60c5e8a20bf，错误附件为 a32e458f6df112781eaf5714606cfac903b76e5ee656be2caa7bb2f899c7bbb4。[对照原始输出](s45-review.json)

当前清单的片段起点为 0x12BD，错误附件把站点归到在 0x12BD 结束的前一个片段。两次运行均退出 0，所有字段、历史 161 行计数和完整输出一致。该脚本固定读取 code/s33-two-hop.csv，并只对 coverage.csv、calls.csv 和 native-functions.csv 比较 metrics 中的指纹。调用者仍需单独验证当前交付附件和生成器。

建议把本轮附件路径与回执摘要作为明确输入。用当前原件和候选片段范围验证数值宿主，以附件实际字节验证回执指纹。回归可复用上述成对输入。大小写不同且数值、指纹均吻合的附件应有同样的宿主结论，错误的 0x12B6 应报该站点的宿主不符。生成器仍需独立通过删站与片段变更两项任务卡对照。
