# Ikc2Bkp.dll 逐件静态核验

本轮补证仍有 23 个入口缺口，整件静态验收未通过。固定原件为 Plus-Properties 的 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Ikc2Bkp.dll`，版本 41.0.0.614，217,128 字节。输入取自提交 `64670801de54e990f975aaeda06e89340c0e4e08` 中的 `issue-materials/349/Ikc2Bkp.dll`，SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。

## 已对照的范围

Ghidra 12.2 从原件找到 202 个函数并导出 202 份伪 C。原件 PE 入口、异常目录和唯一代码导出去重得 220 个锚点，两者的并集为 265 行。`decompiler-functions.csv` 对照 Ghidra 代码行，`body-ranges.csv` 列出原始 Ghidra 函数区间，`runtime-ranges.csv` 列出异常目录及实际展开记录中的 CHAININFO 父地址。

`code/verified.c` 与其同目录的 `verified-*.h` 保存可编辑的 AMD64 实现。Zig 0.13.0 编译后，把每个 COFF REL32 系列重定位应用到原 RVA。183 个实现的 144,024 个字节全部与原件相同，共核对 5,294 处重定位。另有 59 个展开记录入口沿 CHAININFO 归属到已重组函数，在该函数的已解码指令边界核实。覆盖表共 242 个已核对条目。部分业务函数被分析器划为不连续区间，已复核区间之间的不可达直接 JMP 并一同重组，例如 0x4210 的两条缝隙指令位于 0x4296、0x42a2。重组覆盖函数逐个列在 `reassembly.json`。负控在临时源码中将导出内 0x44ca 的目标由 0x22da0 改为 0x8a30，再运行相同比对。其余 182 个实现仍相同，0x44a0 单件检出差异。

## 导出函数

导出表和异常目录共同定位 `Ikc2Bkp` 为 [0x44a0, 0x4510)。高级 C 在 `code/Ikc2Bkp.c`。精确回编实现位于 `code/verified-01.h` 第 3617–3651 行。0x44c0 传入 -1 调 0x21a60。0x44ca 以第一个路径参数调用 0x22da0，0x44d8 以有符号数判断结果，负值直接返回。0x44e9 将第二个路径参数和原第三参数传入 0x8a30，0x44f7 以相同标准处理负值。两步均成功时 0x4504 再传 -1 调 0x21a60 并返回零。0x22dd2 经 IAT 0x261c8 调用 fopen，模式字符串是 RVA 0x26660 的 `r`。0x8a60 和 0x8a9e 的 fopen 调用读 RVA 0x2886c 的 `w`。0x8a30 的 706 字节已独立重组。

0x21a60 对输入加一并检查上界 12，在 0x21a83 通过位于 0x21f50 的 13 个 DWORD RVA 跳转。输入 -1 进入 0x21bf0。0xa694 的另一处分派从 0xd6f0 取 16 项，其中末六项共用 0xd1e4。两张表的原始值和默认出口见 `dispatch-tables.csv`，各表的不同目标集合与 Ghidra 数据库一致。

## 其余缺口

`calls.csv` 按归属记录 3,947 项，含 1,052 个外部转移、2,880 个数据引用和 15 个待绑定的间接转移。展开片段和父函数可能引用同一指令，按地址、类别和目标去重共 3,720 项。`direct-transfers.csv` 另存已解析的直接调用、分支和两个分派表。`imports.csv` 列出 64 个固定导入槽，`pe.json` 记录代码节、导出、848 字节版本资源和 381 字节清单资源的身份。

优先处理输入解析函数 0x22da0 及其展开片段 0x22df6、0x2300a，核对实际读取、错误路径与末尾同一函数的展开链，并完成与指令一致的回编。0x2ee0 及片段 0x2f05、0x302b 同样需逐段核对。其他 17 行的入口在 `coverage.csv`，包括 0x2448e 等间接转移。0x2459b 一类站点虽可确认其内存间接槽，最终被调用的函数仍取决于相应实参或寄存器。每行应继续补充原始调用者、实际目标、数据归属和可编辑实现，经同一判定器复验。当前记录覆盖静态证据。

## 复验

1. Ghidra 12.2 默认 Windows x86-64 PE 分析，用 JDK 25 运行 `analyzeHeadless <project-dir> Ikc349 -import <原件> -max-cpu 2 -scriptPath <本目录> -postScript ExportIkc.java <本目录>`。随后在同一项目执行 `-process Ikc2Bkp.dll -noanalysis -scriptPath <本目录> -postScript ExportIkcFlow.java <本目录>`。两份导出脚本均校验原件 SHA-256。
2. 安装 pefile 2024.8.26、Capstone 5.0.6。运行 `python reassemble.py <原件> <Zig 0.13.0 可执行文件>` 后将 JSON 与 `reassembly.json` 解析对比。重组仅编译源码并静态比较对象文件。
3. 运行 `python recover.py <原件>` 重建 PE 清单、分派表、覆盖与引用。再从仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-349 --original <原件>`。本轮结果为 `checked 265 coverage rows, 265 tool-native entries, 3947 call records, 23 declared gaps`，退出 2。交付文件 SHA-256 见 `SHA256SUMS.txt`。
