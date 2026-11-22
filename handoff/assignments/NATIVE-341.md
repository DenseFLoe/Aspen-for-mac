# NATIVE-341 · mmstruct.dll

执行方 tietoumiao，assigned_seq=1。收到 #13 的 ACK 后 24 小时内提交或回报具体阻塞。原路径 Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/mmstruct.dll。已从固定提交取到 530472 字节，SHA-256 为 `bb9a2422bffe3a6aaa6c2a533ef7b4ef25d14092560d519bc93b94e216ce4870`。[原件](https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/341/mmstruct.dll) · [旧报告与归档](https://github.com/DenseFLoe/Aspen-for-mac/issues/341)

旧报告仅覆盖 AssistVw。原件 AMD64 PE 入口为 0x47520，独立读取异常目录、入口和可执行导出，得到 1665 个不同地址锚点，AssistVw 对应 RVA 0x2cb10。逐址核对工具发现的其余函数、原件实际导入调用和重要数据引用，分别列可定位的反汇编、实现和未决项。只写 handoff/inbox/NATIVE-341/。开工及交付回执为 s1-started.md、s1-submission.md，随交付提供 PR/head，证据格式见[标准](../standards/native-coverage-extension.v1.md)。

从仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-341`。0 表示机械检查通过，2 表示有已声明缺口，1 表示输入或材料有误。原件、锚点和引用由上游独立复核。
