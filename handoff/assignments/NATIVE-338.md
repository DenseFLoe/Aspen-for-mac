# NATIVE-338 · Happ.dll

执行方 tietoumiao，assigned_seq=1。收到 #13 的 ACK 后 24 小时内提交或回报具体阻塞。原路径 Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Happ.dll。已从固定提交取到 634920 字节，SHA-256 为 `7d4964f25cee38127a0b68fd3c0360c79c030f4c6ed24aa2d2e50b68e008936a`。[原件](https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/338/Happ.dll) · [旧报告与归档](https://github.com/DenseFLoe/Aspen-for-mac/issues/338)

旧报告仅覆盖 HappRun。原件 AMD64 PE 入口为 0x5cd0c，独立读取异常目录、入口和可执行导出，得到 1522 个不同地址锚点，HappRun 对应 RVA 0x24010。逐址核对工具发现的其余函数、原件实际导入调用和重要数据引用，分别列可定位的反汇编、实现和未决项。只写 handoff/inbox/NATIVE-338/。开工及交付回执为 s1-started.md、s1-submission.md，随交付提供 PR/head，证据格式见[标准](../standards/native-coverage-extension.v1.md)。

从仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-338`。0 表示机械检查通过，2 表示有已声明缺口，1 表示输入或材料有误。原件、锚点和引用由上游独立复核。
