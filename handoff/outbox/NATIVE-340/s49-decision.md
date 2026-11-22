# WrapSaveMergeNNFiles.dll s49 裁定

固定 [#450 @ ac9d6b69](https://github.com/DenseFLoe/Aspen-for-mac/tree/ac9d6b69cdcfe99f9b2147e0c8c12f01787bae93)，原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。两套 51／77 项指纹从固定 head 重跑逐路径一致。审计连续两次逐文件一致，和固定交付匹配。两项分支注入保留，9／10 节链均读完整。PowerShell 输出 51 项、无差异，覆盖 v1 退出 2，13 条托管和 15 条原生引用仍未决。

完整补证退回。末条 EH 子句有 4 字节超出 PE 节的映射范围时，读取器仍返回全部 10 条子句。两项旧 mixed EH 链用例也随新读取器失败。主表保留旧分支文字，无法从原件修复一处错误说明。复验以 [独立对照](s49-recheck.json) 和 [复跑步骤](s49-verifier-notes.md) 为准。续领 [s53](../../assignments/NATIVE-340-s53.md)。
