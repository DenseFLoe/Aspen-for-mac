# NATIVE-349 · Ikc2Bkp.dll

执行方 upstream，assigned_seq=1，时限为本轮 #13 ACK 后 24 小时。原件为 Plus-Properties 的 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Ikc2Bkp.dll`，提交 `64670801de54e990f975aaeda06e89340c0e4e08` 中的 `issue-materials/349/Ikc2Bkp.dll`。已从该提交取到 217,128 字节，SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。[固定原件](https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/349/Ikc2Bkp.dll) · [旧工单](https://github.com/DenseFLoe/Aspen-for-mac/issues/349)

旧报告只覆盖名为 Ikc2Bkp 的函数。固定原件的导出表将它定位在 RVA 0x44a0，异常目录的右界为 0x4510。原件地址锚点共 220 个。用 Ghidra 等原生分析器核对该导出、其调用和主要数据，将分析器识别出的其他入口与原件锚点逐址关联；按原指令核对编辑后的实现。把仍有差异的地址或间接转移列出，给出可复查的依据与恢复条件。

交付至 `handoff/inbox/NATIVE-349/`，使用 `s1-started.md`、`s1-submission.md`。适用[上游原生覆盖标准](../standards/native-coverage-upstream.v1.md)。自仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-349`，本地复用同哈希原件时可附 `--original <文件>`。整件按原件级静态标准另行裁定。
