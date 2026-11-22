# NATIVE-342 · ApwnIPShell.dll

执行方 upstream，ACK+24h。输入为 Plus-Properties/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnIPShell.dll，369,192 字节，SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。[固定原件](https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/342/ApwnIPShell.dll) · [既有缺口](https://github.com/DenseFLoe/Aspen-for-mac/issues/342)

范围为 AMD64 PE 原件代码段、PE 入口、运行时函数表及导出形成的 612 个地址锚点、分析器发现的其他函数、重要数据和外部调用。核对原报告给出的 RVA 0x235c0–0x24c8e 和 SetHelpFile 调用，区分调用指令与宿主函数边界。按 `handoff/standards/native-coverage-evidence.v1.md` 提交实际反汇编、可编辑实现、覆盖表和调用表至 `handoff/inbox/NATIVE-342/`。缺失实现或未决调用逐址登记 gap 和恢复条件。

从仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-342`。以 `--inventory` 可先读取原件锚点；有已校验原件时可加 `--original <文件>`。整件仍依静态验收标准另行裁定。
