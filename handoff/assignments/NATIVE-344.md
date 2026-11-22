# NATIVE-344 · simdll.dll

执行方 upstream，assigned_seq=1，时限本轮 #13 ACK 后 24 小时。原路径 Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/simdll.dll。[工单及失败报告](https://github.com/DenseFLoe/Aspen-for-mac/issues/344)记录旧成果仅有 sub_109c0 和 submit_proprun 两个按名去重的函数。主干逐件总表仍列静态验收未通过。

已回读提交 64670801de54e990f975aaeda06e89340c0e4e08 的 issue-materials/344/Simdll.dll，373,288 字节，SHA-256 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。AMD64 PE 的入口 RVA 0x3c260；submit_proprun 在 0x39c00。原件异常目录、导出和入口去重后有 911 个原生地址锚点。[固定原件](https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/344/Simdll.dll)

从仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-344`，复用同哈希本地原件时可加 `--original <文件>`。逐址覆盖 911 个锚点与分析器额外识别的函数，核对实际外部调用、间接转移和重要数据；无法解析处给出证据及恢复条件。交付到 handoff/inbox/NATIVE-344/，回执为 s1-started.md 和 s1-submission.md。机械核查和上游逐件审查按[上游原生覆盖补证](../standards/native-coverage-upstream.v1.md)执行。
