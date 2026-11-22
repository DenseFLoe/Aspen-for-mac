# NATIVE-337 s53 复验

固定 [#445 @ 32ce7e38](https://github.com/DenseFLoe/Aspen-for-mac/tree/32ce7e38ca2ec72a31007b09c66ec847285e3071) 和 [#13 s53 交付通知](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7086925639)。FindComponent.dll 原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。

s49 的缺件已补齐。生成器、读取器、测试的指纹均与这次回执吻合。回读原件和固定输入执行四项对照，退出 0。无旧表仍得 161 站，删站后找回 0x106C，片段变化后 0x12DA 的候选宿主是 0x12B6、原件宿主是 0x11E0，空目录重放摘要为 `2ef4b467155284f011c9fecd7c457c80cbfb9bff148b0acee7c4a60c5e8a20bf`。固定提交中的实际附表名是 `code/s37-two-hop.csv`，其 SHA-256 与重放结果一致。回执写的 `code/s45-two-hop.csv` 在该 head 无对应文件。

覆盖证据按 v1 §对应关系 4–5 退回。把同一个候选清单里的一个完整函数移到第二个 `native*.asm`，更新主表的路径和行号，161 站仍在。生成器把 `code/native-part.asm#L28` 的 0x12DA 错绑到第 525 行，实际应保持第 528 行。原件、函数字节、RVA 和导入定义未变。两份有效布局的关联应一致。主干 check-s33.py 在固定单文件附表上退出 0，覆盖器报告 307/307/684/0 后退出 2，仍有 112 条未决，整件静态验收未通过。

[四项对照输出](s53-suite.txt) · [两种布局输入与实测](s53-layout.json) · [可复现步骤及建议](s53-verifier-notes.md) · [s57 续领卡](../../assignments/NATIVE-337-s57.md)。
