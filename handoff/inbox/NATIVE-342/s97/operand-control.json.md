# s97 成对复跑

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。 范围 `[0x369b8,0x36a15)`。1005 个入口中 733 个覆盖、272 个缺口，7433 条引用中 636 条未决。整件静态验收未通过。

从主干还原候选目录后，用下列命令分别对原候选及每个单改副本运行。原件和源码之间的独立比较只在第二条命令中完成。

    python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE
    python -B CANDIDATE/s97/replay.py ORIGINAL ZIG

1. 操作数对照只改 `s97/guarded-callback.c` 的 `mov eax, 1` 为 `mov eax, 2` 并重算输入指纹。覆盖检查两次均 exit 2，局部回编从 exit 0 变为 exit 1，首个差异为 0x36a01。
2. 数据引用对照只改 `calls.csv` 内 `native,0x369b8,RVA 0x54868,data,s97/instructions.lst#L14` 的 callee 为 `RVA 0x54860` 并重算表指纹。原指令的 RIP 相对位移独立解得 0x54868。依据覆盖证据 v1 第 5 条，被改行应报目标矛盾并定位 0x369e9。实测 v1 两组均 exit 2，摘要完全相同。覆盖层有文件及行号存在性检查，目标字段与原指令的有效地址仍需人工复核。

可复跑的回归输入为上述原组和第 2 项单改组。若覆盖检查具备原件指令及有效地址的解析能力，原组应保留 exit 2，单改组应定位 0x369e9、报告 0x54860 与 0x54868 的矛盾并 exit 1。原组尚有 272 个申报缺口。
