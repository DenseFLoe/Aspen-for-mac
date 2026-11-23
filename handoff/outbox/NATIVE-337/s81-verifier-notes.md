# NATIVE-337 s81 验收器复验

原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ 661da2d](https://github.com/DenseFLoe/Aspen-for-mac/tree/661da2d59e2eb20cccdd6932e1dba5c8cde53a16)。主干基线 581aa65bc65667e09760dda9e5b954290d9d7e2b。

复跑 `python -B s81-review.py REVIEW_ROOT BASE ORIGINAL REPORT`。REVIEW_ROOT/fixed 为固定候选，含原 PR 的顶层 tool/、work/ 与 handoff/inbox/NATIVE-337。BASE 为同版本主干，REVIEW_ROOT/fixed-manifest.json 为本页所链的固定清单。Capstone 5.0.6、pefile 2024.8.26，Windows 复跑用了 PYTHONUTF8=1。

- 导入身份配对只在同一候选副本中改 calls.csv 的 0x1357 callee，保留地址及清单。GetUserDefaultLCID 对应槽 0x7060，同一 DLL 的 MultiByteToWideChar 对应 0x7050。以两份 calls.csv 的独立 SHA 核对输入。预期改名版本定位 0x1357。候选预检的 wrong_symbol 对两份均报 0，主干覆盖均退出 2。应从原件复算每站目标槽，再用完整导入身份匹配。
- 跳板对照保持同一 disp32，FF25 是 6 字节 RIP 相对 JMP，FF05 是 6 字节 INC。预期站点解析 0x2000／空值，站枚举器和主分类器仍同报 0x2000／0x2000。候选孤立配对退出 0。延续上一轮已知问题，实测证明修复尚未接入生产调用。 [s77 原记录](s77-verifier-notes.md)
- s69 五项和 s45 六项都在明确 UTF-8 后复跑通过。Windows 默认 CP936 下，s69 子进程文本解码失败。将父子两端编码显式固定，保持带非 ASCII 路径与输出的配对测试。


[逐项输出](s81-recheck.json) · [固定文件及 SHA-256](s81-fixed-manifest.json)
