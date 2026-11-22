# NATIVE-340 s41 验收器复验

[#450 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/106eb83d05ac50c9e14e7eb079014857a9117ab3) 的两类指纹均漏列 `code/README.md`。主干 `f31ed0ae4a2fa19584f5be0f17e96d0a07556f09` 中的 `check-s29-446.ps1` SHA-256 `dff64661655f764c261e84c6724b1dd602bb2a802ae3aea893b0115ddb3bb68c`。

    pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original ORIGINAL -Unit CANDIDATE

保持原件和交付内容固定，在 receipt 清单中只补 `code/README.md` 和已独立计算的正确 SHA-256。补列前后该脚本都退出 0、零项不匹配，计数由 45 变成 46。它逐项核对清单已有条目，任务要求的覆盖范围仍需人工或独立的清单生成命令比较。[成对输出和指纹](s41-receipt-control.json)

建议显式接收当轮预期清单范围，与固定提交的实件路径做集合比较，再核对共同路径的指纹。回归使用上述双输入。完整清单应通过，缺项清单应报告 `code/README.md`。生成器的分支常量、越界样本及审计退出码另按交付缺陷处理。
