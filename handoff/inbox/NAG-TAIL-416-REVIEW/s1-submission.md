# #416 固定候选预检交付

NAG-TAIL-416-REVIEW，assigned_seq=1，owner upstream。候选 `2c9038f5357801b8ce35c53f43e5d39bb761f144`，主干 `39be5a38e08c3dabe62daf3976660d18fe9a446f`，#369 映射 `584a04a3993eba2546bc6802cf4798f30a8e551d`。[检查脚本](check.py) · [逐项结果与指纹](summary.json)

按完整路径从固定主干读取 504 份原始文本。每一路径的旧 SHA-256、旧大小及删除锚定尾行后的 SHA-256 均与先前核验记录一致。重新构造期望 Git blob，候选内 498 个全部吻合。Release ZIP 的 6 个成员已实际回读，逐字节等于相应原文删除尾行后的结果。共 428 份 CRLF，76 份 LF。没有其他源码字节差异。

与 #369 的 455 行原提案同时核对旧、新 SHA-256，30 行完全吻合，另 424 行只在对结果做 LF 归一后吻合。第 330 行 `Infragistics4.Win.UltraWinListView.v15.1.dll` 的旧表预期单个 LF，新候选由 124 字节严格删到 0 字节，所在原件仍在静态验收未通过。脚本在旧新映射不完整时退出 1，同时保持内容比较的 504 项结果。

复跑时执行 `python -B handoff/inbox/NAG-TAIL-416-REVIEW/check.py inputs.json results.json --refresh`。若 #416 更新，应固定新 head 再复验，原证据保留在本交付。逐路径清单记录原值、期望值、ZIP 成员或候选 blob。
