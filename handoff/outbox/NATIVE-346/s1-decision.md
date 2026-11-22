# ppexec.dll 第一轮复验

**returned**。上游复验的 `assigned_seq=1` 候选提交为 `c2caf377a8b15f04c1baf6e80f61a65e14b7194c`。33 份交付材料与该提交的 blob 指纹逐件相符，整件仍为静态验收未通过。[逐件报告](../../inbox/NATIVE-346/ppexec.dll.md)

原件为 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/346/ppexec.dll`，SHA-256 为 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。运行受信主干 `e7f800d9aecad9cab1f14f3bec4852d36ee3ca3f` 的 `python handoff/assignments/check-native-coverage.py NATIVE-346 --original <原件>` 得到 418 行覆盖、2,777 条引用、82 项申报缺口，退出 2。30 个间接转移仍待绑定。

上游用 Zig 0.13.0 重跑 `rebuild.py <原件> <zig路径>`，结果与提交的 reassembly.json 全部字段相同。21 个具名代码导出、19 个非导出实现及 296 个导入跳板共 336 段，应用 2,691 个重定位后，43,702 字节与原件一致。PPEXEC_INTPP 的三处调用位于 0x6b8d、0x6c16、0x6e7d，跳板和 IAT 将其绑定到 atdms.dll!DMS_ASGOPN。PPEXEC_PHCCIN 的分派表列出了 179 路。Ghidra 12.2 的 418 个函数导出可供其余入口继续比对。[回编记录](../../inbox/NATIVE-346/reassembly.json) · [逐址缺口](../../inbox/NATIVE-346/coverage.csv)

恢复时先核实 0x8d40、0x8e10、0x8ea0、0xa6c0、0xe040 的实现与控制流，对照已定位的导出数据布局，逐项补上剩余 82 个入口的静态证据，在同一原件上重做回编及引用核验。提交回执 SHA-256 为 `16973c051d26508209ea955ef5b03adc694884b1d5b0f14b87cb9e51a77908cf`，回编记录为 `76d6b30765dacdf185f0c2b111c348659e796bb30c579a5c2abaf7fab03410d4`，全套指纹表为 `dd2a8c0125a2ec0b604b9a71d60dbf4fac0edb780556fd6e5d7d33af2ae068ff`。
