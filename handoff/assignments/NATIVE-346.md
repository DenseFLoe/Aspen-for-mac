# NATIVE-346 · ppexec.dll

执行方 upstream，assigned_seq=1，本轮 #13 ACK 起 24 小时。该件位于 Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppexec.dll。主干总表按 SHA-256 列为静态验收未通过，旧报告仅核对一处包含 DMS_ASGOPN 调用的范围（RVA 0x65b0–0x87cc）。[原工单与错误报告](https://github.com/DenseFLoe/Aspen-for-mac/issues/346)

已回读提交 64670801de54e990f975aaeda06e89340c0e4e08 的 issue-materials/346/ppexec.dll，138,280 字节，SHA-256 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。AMD64 PE 入口 RVA 为 0x11e58；异常目录、代码导出和入口去重后得到 101 个原件地址锚点。[固定原件](https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/346/ppexec.dll)

优先核对 DMS_ASGOPN 的实际调用点与所属函数。以函数边界、实现、必要数据和调用引用逐项覆盖全部原件锚点及工具额外识别的函数；不能唯一绑定的目标与待恢复实现逐址说明。从仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-346`。交付到 handoff/inbox/NATIVE-346/，开工、交付使用 s1-started.md 和 s1-submission.md。[验收标准](../standards/native-coverage-upstream.v1.md)
