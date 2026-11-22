# NATIVE-342 第一轮覆盖证据

owner upstream，assigned_seq=1。实际原件为固定提交 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/342/ApwnIPShell.dll`，369,192 字节。本轮以实际 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b` 为准。PE32+、AMD64，ImageBase 0x180000000，代码段 .text 为 RVA 0x1000–0x39887（右界不含）。

`runtime-boundaries.csv` 列出逐个 x64 运行时函数表区间、区间原始字节摘要、顺序解码结束地址与指令计数。612 个区间中，607 个顺序解码到表中右界，5 个提前停止。运行时函数表可能列出同一函数的多个片段，顺序解码也可能读到内嵌数据。分析集合含 612 个原件锚点及 201 个额外直接调用目标候选。排除了数据导出。

原报告的 0x235c0–0x24c8e 对应一条运行时函数表记录。宿主反汇编可在 `code/focus.asm` 逐条定位。RVA 0x24bbb 的原始字节为 `ff 15 f7 e5 02 00`，RIP 相对地址解为槽 0x531b8。独立读取原件延迟导入目录得到 mmg.dll 的 IAT 起点 0x530f8，槽序号 24，hint/name 记录在 0x4a366，ASCII 名称 SetHelpFile 从 0x4a368 开始。对应调用见 `code/focus.asm` 第 1340 行。

`code/leaves.c` 给出 12 个以 ret 结束的两指令叶函数返回值模型，每个都有完整原始指令对照。余下 801 个 RVA 逐行登记缺口。129 条定位记录中，51 条为外部调用、70 条为数据引用、8 条间接调用需继续绑定。当前引用范围为上述宿主和叶函数外加 8 个间接调用样例。

从仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-342`，也可用 `--original <文件>` 指向同哈希原件。上游执行结果为 `checked 813 coverage rows, 813 tool-native entries, 129 call records, 801 declared gaps`，退出码 2。原件、各行状态及边界摘要可复跑；复现生成器需 Python、pefile 2024.8.26 和 Capstone 5.0.6，运行 `python -B handoff/inbox/NATIVE-342/recover.py <原件> <输出目录>`。
