# NATIVE-340 s45 复验记录

候选 [c1a0c085](https://github.com/DenseFLoe/Aspen-for-mac/tree/c1a0c0850352360315ab5842cbd00e3ce6f7b7f9)。输入指纹、工具 SHA-256、分支字段、真件 EH、成对结果见 [s45-recheck.json](s45-recheck.json)。

## 已复现的历史检查缺口

从主干 `e3b3049622bbefa9241099561a8fadd35a9b25c1` 运行 `pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original ORIGINAL -Unit CANDIDATE`。工具 SHA-256 为 `dff64661655f764c261e84c6724b1dd602bb2a802ae3aea893b0115ddb3bb68c`。候选原样输出 50 项、5 项不符、退出 0。重出 50 项后无差异、退出 0；保持候选文件不变，只从扁平指纹移除 `code/README.md`，输出 49 项、无差异、退出 0。后者延续 [s41 的缺项发现](s41-verifier-notes.md)，本轮新证据是同一个退出码也被用于已有明确内容差异的交付。

建议用规范定义的相对路径集同时比对路径和内容，将缺项、多项和哈希不符置为失败。回归用例分别保留完整 50 项、遗漏 README、使用当前候选的五个错误摘要，期望退出分别为 0、非零、非零。覆盖 v1 的退出 2 已正确保留整件未决状态。

## 交付修复项

- 在固定候选分别运行 `python -B tool/gen_fingerprints_340.py --unit CANDIDATE --set receipt --out receipt.json` 与 `python -B tool/gen_fingerprints_340.py --unit CANDIDATE --set round --base-head 106eb83d05ac50c9e14e7eb079014857a9117ab3 --out round.json`。路径与数量相符，五个 `code/s{25,33,37,41,45}-unresolved-native.csv` 的声明摘要为 `0100b934…`，固定 GitHub 文件实为 `83b13dd9…`。
- 在候选副本上运行 `python -B tool/audit_340_s45.py --binary ORIGINAL --folder CANDIDATE_COPY`，退出 0，26 条布尔控制通过，原样重现注入 CSV，但 `calls.csv` 从 `c73aea36…` 变成 `91133735…`，同一 `0x20CC` 行进一步追加相同说明。验收时对同一候选运行两次，主表、受影响附表和定稿指纹应完全一致。
- 运行 `python -B handoff/outbox/NATIVE-340/s45-eh-chain.py --candidate CANDIDATE_ROOT`。9 节对照完整返回。10 节预期全部读取，或明确报告限制并停止判定。实测返回 9 节，最后一节仍声明后继，没有报错。依据 [ECMA-335 II.25.4.5](https://www.ecma-international.org/wp-content/uploads/ECMA-335_6th_edition_june_2012.pdf)。
