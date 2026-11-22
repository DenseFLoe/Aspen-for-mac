# ApwnIPShell.dll 第五轮静态复验材料

本件是 Aspen Plus 与 Aspen Properties 共用的 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnIPShell.dll`。版本 41.0.0.614，369,192 字节。原件固定在 64670801de54e990f975aaeda06e89340c0e4e08 的 issue-materials/342/ApwnIPShell.dll，SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。本轮仍有 306 个入口缺口。

## 本轮覆盖

原件 612 个异常目录锚点、首轮 813 个地址与 Ghidra 12.2 的 898 个函数入口取并集，共 1,005 个地址。新回编的 673 个原生函数体共 50,900 字节，以 Zig 0.13.0 的 Windows AMD64 目标重建，在 2,382 处 COFF 重定位上绑定原 RVA 后全部与原件一致。另有 26 个运行时目录片段以对应宿主的完整回编范围和指令边界核实，故共有 699 个覆盖地址。首轮 12 个叶函数均获回编复核。首轮 801 个缺口本轮核实了 496 个，192 个新增入口中核实了 191 个。

五个宿主 0xdad0、0x12bc0、0x1fe50、0x21b90、0x22ad0 现在有完整的逐指令可编辑实现。五个原始运行时区间包括七张 32 位地址表、四张字节选择表及其对齐。各表 385 个输入值的分派目标由先前独立复查留存。0xe763 和 0x1333e 两处调用 SorResDll.dll!GetSorResStringEx。0x21dda 显示消息框，0x21f0a 调用 ApwnContextSyncCPMessage。0x22bcf 读类 ID，0x22c5b 调用 CoCreateInstance。逐个宿主调用、数据和未决转移见 s5/five-host-references.csv。

本轮在 Ghidra 给出的全部代码范围逐条解码 54,543 条指令，确认普通与延迟导入表的槽位；直接调用导入跳板的调用方单独列入外部调用。7,433 条记录含 4,677 处外部转移、2,117 处 RIP 相对数据和 639 处未决间接转移。另列明 1,713 条内部转移和已核实的分支表目标。0x235c0 宿主在 0x24bbb 经延迟导入槽 0x531b8 调用 mmg.dll!SetHelpFile。PE 面的六个节、16 个导出和六个资源叶已从原件盘点。

## 复跑与缺口

在已取得固定原件的普通目录，先以 `python s5/reassemble.py <原件> <zig路径>` 生成回编结果，逐字段与 s5/reassembly.json 对照。再运行 `python s5/refresh.py <原件> <NATIVE-342 交付目录>`，核对当前 coverage.csv、calls.csv、run.json 与 s5/fifth-round.sha256。可信主干 f1ed621740bf27fabf86b4780d9fdcb75df279ca 的命令 `python handoff/assignments/check-native-coverage.py NATIVE-342 --original <原件>` 输出 1,005 行、7,433 条引用、306 个缺口，退出码 2。

当前仍有 81 个段内入口未满足核实条件，另有 225 个 Ghidra 入口缺少足够的实现或区间核对。应优先核对 coverage.csv 列出的 0x11f0、0x1570 和其段内条目 0x15ab、0x15f6，从异常表、调用者和分支定位完整作用范围。五个宿主中的间接调用仍需逐个绑定接收者及对象布局。全件需继续核实数据类型、资源和导出依赖。首轮原状可从主干 f1ed621740bf27fabf86b4780d9fdcb75df279ca 的同目录回读。Windows 对照处于后续阶段。
