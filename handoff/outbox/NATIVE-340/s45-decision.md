# WrapSaveMergeNNFiles.dll s45 裁定

固定候选 [#450 @ c1a0c085](https://github.com/DenseFLoe/Aspen-for-mac/tree/c1a0c0850352360315ab5842cbd00e3ce6f7b7f9)，基线 `106eb83d05ac50c9e14e7eb079014857a9117ab3`。原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。两次单字节静态注入复验一致：`jge→jl` 使消费端由跳过变为执行，`AL 1→2` 反映到证据表。反向控制退出 1。原件 EH 位于 0x3568，finally handler 为 IL_0025–IL_002C。

覆盖 v1 退出 2，1105 行覆盖、354 个工具入口、559 条引用，未决托管 13、原生 15。两套指纹重跑为 50／74 项，均含 README，分别出现同样的 5 个原生附表指纹差异。PowerShell 历史检查列出了差异，退出码仍为 0。两项交付问题也需要处理：同一调用表重复审计时再次追加说明，合成输入含 10 个有效 EH 节时只读取 9 个且没有提示。

裁定 returned。修复见 [s49](../../assignments/NATIVE-340-s49.md)。[复验步骤与证据](s45-verifier-notes.md) · [提交回执](../../inbox/NATIVE-340/s45-submission.md) · [#13 固定提交回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7087181351)
