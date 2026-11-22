# ppexec.dll 第五轮静态修复

Plus-Properties，原路径为 `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppexec.dll`。版本 41.0.0.605。固定原件提交为 `64670801de54e990f975aaeda06e89340c0e4e08`，SHA-256 为 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。

第五轮的 196 段新增实现已回编，首轮与本轮的 532 段源码共逐字节匹配 80,822 字节。剩余 629 字节均解码为对齐或填充，已核完原版 .text 的完整虚拟长度。20 张表的 2,946 个槽位和 34 处索引转移已登记。当前实现仍有 20 处索引域、14 处回调和调度目标，以及导出数据类型与长度需要进一步确认。整件继续等待静态修复。[第五轮提交及复验步骤](s5-submission.md) · [逐址未决项](control-gaps.csv) · [导出和资源](s5-data/README.md)

以下保留首轮提交时的统计和复验范围。当前正式覆盖和调用表见上述第五轮材料。

# ppexec.dll 静态修复第一轮

原路径为 Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppexec.dll。固定输入在提交 64670801de54e990f975aaeda06e89340c0e4e08 的 issue-materials/346/ppexec.dll。文件 138,280 字节，版本 41.0.0.605，SHA-256 为 d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a。本轮结论为整件静态验收未通过。

## 实现与证据

- 100 条 AMD64 运行时函数记录、21 个代码导出和入口去重得 101 个原件锚点。26 个数据导出和 800 字节 RT_VERSION 资源在 pe-surface.json 按名或资源键定位。
- Ghidra 12.2 与 JDK 25 对原件进行默认 PE 静态分析。在同一项目导出 418 个可执行地址入口、418 份伪 C；decompiler-functions.csv 将各段关联到 code/ghidra-*.c。Capstone 5.0.6 另行从入口跟踪直接分支/调用及已证实的分发表。native-functions.csv 汇合两个分析结果。运行时目录中的一个范围可包含多个代码片段，Ghidra 自身的函数范围和反编译结果仍需逐项验证。
- code/ppexec.c 恢复全部 21 个代码导出及 19 个非导出实现，code/import_thunks.c 恢复 296 个导入跳板。在 Zig 0.13.0 cc 的 Windows x86-64 GNU 目标重新编译，按原 RVA 绑定 COFF 中的 2,691 处 REL32 系列重定位；逐函数比对的 43,702 字节全部相同。逐个入口的长度、字节指纹和重定位目标见 reassembly.json。正向比对还覆盖 21 个代码导出的全部原函数跨度，导出 APCLOSE 用无栈尾跳的 12 个字节定界。独立负控修改 PHCBIO 的减一和一个导入跳板槽位，两个重建检查分别在 RVA 0x2d12 和 0x11344 检出差异。
- PPEXEC_INTPP 的原件区间为 [0x65b0, 0x87cc)。0x6b8d、0x6c16、0x6e7d 的三个直接 CALL 各指向 0x114f8，该处字节 ff 25 52 3d 00 00 解出 IAT RVA 0x15250，对应 atdms.dll!DMS_ASGOPN。Ghidra 对应的三次调用见 code/ghidra-01.c 第 3069、3079、3104 行。独立全代码节扫描指向 0x114f8 的 E8/E9 rel32 字段也只命中上述三处。
- PPEXEC_PHCCIN 在 0x178b 比较索引上界 0xb2，0x1797 得到表基址 0x15dc0，读取有符号 32 位偏移后在 0x17a5 跳转。phccin-switch.csv 列出 179 组键字节及全部 179 个不同 case 入口。code/phcbio-model.c 另给出 PPEXEC_PHCBIO 的高层读写、条件和索引计算。
- calls.csv 按调用者与指令位置给出 803 条外部转移、1,944 条数据引用和 30 条尚需绑定的间接转移。internal-transfers.csv 列出已识别的直接内部调用/跳转以及有分配表证据的 case 目标。control-gaps.csv 记录各条未决控制流。

## 剩余事项

判定器输出为 checked 418 coverage rows, 418 tool-native entries, 2777 call records, 82 declared gaps，退出码 2。coverage.csv 逐行列明 82 个缺口及对应的 Ghidra 源码。优先从 0x8d40、0x8e10、0x8ea0、0xa6c0 和 0xe040 的间接分派入手，将索引值、表和调用者对应，再补余下运行库入口与共享片段。核验 26 个导出数据对象的类型、大小和初始化，以及必要资源、导入、重定位和展开信息。当前未作 Windows 行为测试。

## 复验

1. 在普通目录启动 Ghidra 12.2 的 analyzeHeadless，以固定原件运行默认分析，使用 -max-cpu 2 -analysisTimeoutPerFile 300 -scriptPath <本目录> -postScript ExportPpexec.java <本目录>。ExportPpexec.java 会先验证所选程序的完整 SHA-256。
2. 安装 pefile 2024.8.26、Capstone 5.0.6，执行 python recover.py <原件> <本目录>。code/ppexec.c、反编译索引及相应源码为输入。恢复后的覆盖表、引用、资源和分发表均可复算。
3. 执行 python rebuild.py <原件> <clang 或 zig 路径>。使用 Zig 0.13.0 可逐条复现 reassembly.json。该步骤仅编译和比较源文件，原件和回编对象均不运行。
4. 仓库根执行 python handoff/assignments/check-native-coverage.py NATIVE-346。使用固定原件副本时可加 --original <原件>。本轮全体证据指纹见 SHA256SUMS.txt。

## 第九号复验材料

[本轮回执](s9-submission.md) · [分派索引](s9/selector-evidence.md) · [14 个回调与转发位置](s9/callbacks.json) · [全件导出地址引用](s9/data.json) · [PPROY 的外部使用者](s9/cross-check.json)。当前逐址表保留 15 处待定转移及其恢复条件，源代码与第五轮已有资源共同构成候选。

## 第十三号复验材料

本轮逐址处理前一轮留下的 15 处未决。原件的节属性判据排除可写的 0x22148，正常映像因而不进入 0x11c56。0x121c0 的唯一已定位调用路径把 0x11b24 作为第四入参传入，该内部边已有原件证据。主调用表还保留 13 处未决。

从两处分派入口回查 19 个调用方的 R8 来源。常量和若干元素数乘八的路径已定位，动态计数的完整范围仍需追到声明及生产者。另核对原件中三处 XFG/CF 回退槽和 GuardMemcpy 的导入链。26 个数据导出、已有资源、已回编代码的证据继续适用。[逐址裁定](s13/disposition.csv) · [本轮证据](s13/evidence.json) · [复跑命令](s13-submission.md)
