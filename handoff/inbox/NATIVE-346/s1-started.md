# NATIVE-346 第一轮开工回执

owner upstream，assigned_seq=1。输入固定为提交 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/346/ppexec.dll`，138,280 字节，已读回的 SHA-256 为 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。

原件为 AMD64 PE32+。异常目录、可执行导出与 PE 入口去重得 101 个地址锚点。导出表把 PPEXEC_INTPP 定位至 RVA 0x65b0，异常目录的对应区间为 [0x65b0, 0x87cc)。已在 0x6b8d、0x6c16、0x6e7d 读到指向同一跳板 0x114f8 的 CALL，跳板经 IAT 0x15250 调用 atdms.dll!DMS_ASGOPN。

本轮按卡复查其余原件锚点、分析器补出的函数及调用与数据引用，逐址核对可编辑实现、直接与间接控制流。判定命令为 `python handoff/assignments/check-native-coverage.py NATIVE-346`。工作范围为静态验收。

