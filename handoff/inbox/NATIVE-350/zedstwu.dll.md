# zedstwu.dll 静态复核

**截至 s53 已覆盖 154/255 个入口，还有 101 个入口和 26 条引用待核。** 分轮证据见文末。

**首轮保留 125 个入口待修复。** Aspen Plus V15.0 Engine/Xeq 的 AMD64 原件版本为 41.0.0.609，151,080 字节，SHA-256 为 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。旧报告点名的复制片段、相关全局数据、四张分派表和版本资源已提供可编辑来源并与原件比对。[固定原件及来源](../../assignments/NATIVE-350.md) · [本轮检查结果](rebuild.json)

首轮沿用固定主干 `f1ed621740bf27fabf86b4780d9fdcb75df279ca` 的 IDA 9.5 汇编与 Hex-Rays 伪 C，SHA-256 分别为 `fdce8c9db94517169eebc1104dc1a05f595cdf28425ba0027494ed8df0bdda6a`、`1e1e448a9fde6212ba7cbcfccc286f92b77f9e1d85bed92f7ea56bb3615d479b`。254 对入口名及原行号逐项吻合。83 个异常记录、PE 入口及四个代码导出合计 84 个不同的锚点。另确认一处被旧清单漏列的真实分支目标，现有 255 个入口。[旧材料与逐件报告链接](../../assignments/NATIVE-350.md) · [两套源码行号](legacy-functions.csv)

## 复制片段及数据

RVA 0x175cf 从 RDX 读四字节并写入 RCX，随后两个指针均加 4，R8 减 4。三次复制依原顺序保留。RVA 0x17605 跳至 0x16e4a，R8 已减少 12。目标属于 0x16560 的实现，原件向下保留 RAX，继续通过寄存器传递现有状态。独立解码本轮列出的全部直接分支，未见直接调用或跳转以 0x175cf 为目标，其内部片段身份和独立调用契约仍应区分。[可编辑实现](code/zedstwu.c) · [实现说明](code/zedstwu.c.md)

0x16e4a 清零 R9，以有符号大于指令比较 R8 和 0x22238 处的阈值。阈值初值 65,536，在 0x14e1c、0x14ea6 可被写入。超过阈值的路径在 0x17380 开始按 64 字节进行非临时存储，并于尾部分派前执行 SFENCE。另一条路径根据 RDX 的低四位选择对齐或未对齐的复制路径。0x23630 是零填充的四字节模式字段，在 0x14f11 写入，与 0x16e30、0x178f7 处的读取对应。[可编辑数据及指针数组](code/copy-data.c) · [初值与代码引用](copy-data.json)

内存复制共使用四张指针表，位于 0x26000、0x26040、0x26600、0x26680，分别有 8、184、16、9 项。各项均由原件的 DIR64 重定位及所指的代码标签确认。实际编译所得数据对象也含 217 处 ADDR64，每一项绑定到代码符号后与原件八字节一致。从 0x16560 至 0x1760a（不含右端）含 929 个指令标签及对齐字节，共 4,266 字节。应用代码重定位后，整段与原件逐字节一致。[217 项原始对应](copy-tables.csv) · [独立重组程序](verify.py)

## 终止路径和版本资源

0x15bd0 写入 ECX=5，0x15bd5 调用原件 0x15d48 的 `__scrt_fastfail`。该函数经处理器特性检查，可在 0x15d70 执行 INT 29h。备用的异常处理路径在 0x15e8f 含 RET。如果该路径返回，调用后的 0x15bda 执行 INT3（字节 CC）。[原始指令](code/evidence-04.asm)

PE 资源树只有 RT_VERSION，ID 1，语言 1033。0x28060 处 800 字节已按 Windows VERSIONINFO 的层级、类型、字符串、固定值及对齐恢复为可编辑 JSON。重新编码结果的 SHA-256 为 `c8340abd3cf535ddffe9bd79f46dc167df48ee78d02d5378639c7505e67f9ccf`，与整个资源相同。[资源源码](version.json) · [编码实现](version.py)

## 其余代码与恢复条件

128 个六字节独立导入跳板另经实物 COFF 重组，共 768 字节。原件 0x15d08 的条件跳转指向新确认的 0x180c0，该入口通过 0x19150 的 IAT 槽尾跳至 `_crt_at_quick_exit`。0x158c3、0x15f33、0x1815d 则是已有函数内的带前缀指令。[新增位置](code/evidence-05.asm) · [调用和数据引用](calls.csv)

已核实 130 个入口，含两个复制入口及 128 个导入跳板。其余 125 个入口的原有伪 C 仍待实现级复核，四个业务导出均在其中。按逐址表继续查各导出的参数、分支、常量、外部调用和引用的状态对象，特别要把复制例程以外的间接分派及其表项绑定完整。复查了 637 条外部转移、2,886 条数据引用和 44 条待绑定的间接转移。705 条内部调用或跨函数直接转移另有目的 RVA 和归属。此处覆盖对两套旧源码与本次新增地址的核对，尚未在 Windows 运行产品。[覆盖及缺口](coverage.csv) · [内部转移](internal-transfers.csv) · [独立解码结果](references-check.json)

## 复跑

在本件目录执行 `python verify.py <zedstwu.dll> <zig>` 编译两份 C，验证入口、数据表、资源和终止调用。使用 Zig 0.13.0、pefile 2024.8.26 和 iced-x86 1.21.0。执行 `python check-references.py <zedstwu.dll> <旧ASM文本> <旧C文本>`，使用 Capstone 5.0.6 从独立解码器核对 14,091 个指令位置、4,583 行提交的原始指令及引用。旧文本从任务卡链接的原目录取得，程序先验证两份指纹。仓库根运行 `python handoff/assignments/check-native-coverage.py NATIVE-350 --original <zedstwu.dll>`，本轮输出 255 行覆盖、255 个原生入口、3,567 行引用、125 项缺口，退出 2。[正式提交回执](s1-submission.md) · [交付指纹](artifacts.sha256)

## 第五号修复

四个业务导出的 13,218 字节已重组核对。消费者从 ppexec 的 PPROY 首字段读双精度数；对应的六字节数据导入桩未见直接调用或跳转。当前 255 个入口中 134 个已核实，121 个待核，另有 44 处未决转移。[逐件提交及复跑入口](s5-submission.md) · [逐导出证据](s5/business-evidence.json)

## 第九号修复

两处由 DSWU_UDL01I 调用的宿主已实现并核对完整指令与引用。0x9c40 和 0x2640 的 28,576 字节、4,601 条指令、1,383 处相对重定位、270 处导入调用和 1,108 处 RIP 数据引用均与原件对应。保留本件的第一轮复制路径及资源、第五号四个业务导出、119 个函数缺口和 44 处未决转移。Windows 展开信息、共享数据定义、相邻例程和整件链接待后续核验。 [第九号提交](s9-submission.md) · [宿主核验](s9/host-evidence.json)

## 第十三号修复

由 0x9c40 调用的 0x1000 与 0xb980 已按原件异常目录限定范围并恢复可编辑实现。两段共 5,217 字节、891 条指令和 364 次 COFF 重定位与原件一致。255 个入口中还有 117 个缺口，调用主表尚有 44 处未决。详见[本轮提交](s13-submission.md)和[回编证据](s13/callee-evidence.json)。

## 第十七号修复

两个无栈调用入口与两个缓存初始化器回编逐字节一致，共 319 字节、92 条指令及 18 次重定位。选择字 RVA 0x22d30 的三套掩码按顺序检查。两个初始化器各有四个候选，原版缓存写入分别为 0xcc9d、0xcd6a。255 个入口中尚有 113 个缺口，调用表保留 42 处未决。[回编与选择证据](s17/dispatch-evidence.json) · [提交说明](s17-submission.md)

## 第二十一号修复

补齐两个取址入口及 0xcd80 的 AVX 复制函数。编译后 6,169 字节与原件完全一致，其中 4,360 字节为三张可编辑符号差值表。四个间接分派均核出取址与目标。255 个入口中 145 个已覆盖，110 个有缺口；38 处引用仍待恢复。详见[本轮交付](s21-submission.md)和[逐址回编核对](s21/rebuild.json)。

## 第二十五号修复

高能力复制体 `[0xe5c0,0x100c2)` 回编 6,914 字节与原件一致。三张表恢复为 704 个可编辑符号差值槽。四处分派共核实 56 对位置与目标，新增 33 处直接分支记录。固定阈值读入 `0xe627 → 0x22238` 已复核；运行期写入者仍待定位。255 个入口已覆盖 146 个，109 个有缺口；34 处引用仍待恢复。详见[本轮交付](s25-submission.md)和[回编记录](s25/rebuild.json)。

## 第二十九号修复

AVX 填充 `[0x11f40,0x12ff8)` 回编逐字节吻合，包括 189 条指令、418 个表槽和 1 处 COFF REL32。四个间接跳转共 51 对可达位置与目标；保留不可达的原件表槽。共享阈值初值和读取已核，运行期写入者仍待查。255 个入口覆盖 147 个，108 个仍缺实现或复核；3,567 条调用与引用中还有 30 个未决。[本轮交付](s29-submission.md) · [回编记录](s29/rebuild.json)

## s33 补充归档

恢复 0x13000–0x148c1 的 6,337 字节，包括 139 条指令、704 个差值槽和 0x148c0 的单字节 RET。四处分派有 56 对位置与可达目标，另核对 33 个直接分支。0xcd1a 对反相能力位与 0x7189d9fee 做 TEST，匹配路径调用 0xccc0 取得 0x13000。0x1306d 从可写节读取 0x22250，64 位磁盘初值为 4,096。该值影响普通写入和非临时写入路径，运行期写入者待证。唯一 COFF REL32 字段为 0x13070。

255 个入口仍有 106 个缺口，3,567 条调用与数据引用中有 26 项未决。下一件核对 0x148d0 的索引与初始化门禁。

[本轮源码](s33/avx512-fill.c) · [回编结果](s33/reassembly.json) · [回执](s33-submission.md)

## s37 补充归档

恢复 0x148d0–0x14902 的 50 字节，16 条指令和 3 处文本 REL32 逐字节吻合。由源码生成的 .pdata 经 3 处 ADDR32NB 重定位匹配，0x1c388 的 8 字节 unwind 信息也匹配。0x148df 的无符号判定允许键 1、2、3，其余直接返回 0。读取 0x235fc 的 32 位就绪字段，值为 0 时调用 0x14910。0x148f9 以 16 字节步长读取 0x23600、0x23610、0x23620 的 32 位首字段。就绪字段与三处首字段位于 .data 的零填充尾部。原件 0x14c80 将就绪字段置 1，初始化器其余实现仍待恢复。

255 个入口中覆盖 150 个，105 个仍有缺口，3,567 条引用中 26 条待解。整件未通过静态验收。

[可编辑源码](s37/capability-query.c) · [回编结果](s37/reassembly.json) · [回执](s37-submission.md)

## s41 补充归档

恢复 0x14910–0x14cab 的 923 字节与 278 条指令，13 处 REL32 与原件一致。.pdata 的 12 字节和 .xdata 的 28 字节均匹配。独立回编还核对 2,056 字节只读 Vendor/描述符数据与 64 字节零初始化存储。原件以 EFLAGS ID 位测试进入 CPUID 路径，Intel 路径比较 EBX/EDX/ECX，按 leaf 4 或 leaf 2 的条件写入 16 字节记录。0x14c80 写入 0x235fc 的 32 位就绪字段，0x148ea 与 0x14cd3 是已核对的直调入口，0x14c91 直调 0x18110 检查栈 cookie。

覆盖 255 个入口中的 151 个，尚余 104 个入口缺口和 26 条未决引用。整件未通过静态验收。

[可编辑源码](s41/initialize-capability-records.c) · [描述符数据](s41/initializer-data.c) · [回编结果](s41/reassembly.json) · [回执](s41-submission.md)

## s45 缓存阈值更新

RVA `[0x14cb0,0x14f6d)`，701 字节，范围 SHA-256 `5728fad0d29bfcee9a0e69875d0c7a3742a17ab40da0b123c3329b2e3fc3b50e`。190 条指令、36 处文本重定位、20 条直接控制转移、12 字节 .pdata 与 16 字节 .xdata 均已对照。64 字节初始阈值和 21 字节环境变量名另从可编辑 C 回编核对。

整件覆盖 152/255 个入口，尚余 103 个入口缺口和 26 条未决引用，静态验收未通过。 [逐址说明](s45/configure-cache-cutoffs.c.md) · [回执](s45-submission.md)

## s49 诊断输出

RVA `[0x15180,0x15220)`，160 字节，范围 SHA-256 `3a7e60ad7c37883a4c047ccd60a1c35881af319f8d2c4bba9154a5d1fb1a92ef`。 42 条指令、10 处文本重定位、9 条直接转移、12 字节 .pdata 和 12 字节 .xdata 均匹配。另回编核对 6 字节输出格式和 512 字节的缓冲区零填充。 [逐址说明](s49/report-diagnostic.c.md) · [回执](s49-submission.md)

## s53 诊断消息选择

RVA `[0x15000,0x15176)`，374 字节，范围 SHA-256 `e3a5b4ddb8c8dd30d9e7899520b6e29e574c73d09882bf8de1d72dfb7737ca58`。83 条指令、24 处文本重定位、15 条直接转移、12 字节 .pdata 和 12 字节 .xdata 均匹配。另核对 62 条默认消息记录和指针、7 个导入调用点及 536 字节初始零填充。 [逐址说明](s53/select-diagnostic-message.c.md) · [回执](s53-submission.md)

## s57 资源路径格式化

RVA `[0x18550,0x185a6)`，86 字节，片段 SHA-256 `48838f1e44a19a9df9b6312e94bc9c7a4fc6acaaac53037e3a59289946d53351`。86 字节、23 条指令、3 处 REL32、2 处直接调用及 .pdata 12B／.xdata 8B 回编一致。 整件覆盖 155/255 个入口，仍缺 100 个入口和 26 条引用，静态验收未通过。 [逐址说明](s57/format-resource-path.c.md) · [回执](s57-submission.md)

## s61 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x18620,0x18679)`，片段 SHA-256 `aa193870871de50eecab3943d321eb78b712e74c8633011bf2028630305274f2`。

89 字节、30 条指令、2 处 REL32、.pdata 12 字节和 .xdata 16 字节吻合。 0x1863f 调用 0x158d8，取加载器零填充的选项槽 0x22ca0。0x18647 对读出的选项置位 0，经 0x180de 和 IAT 0x19188 调用 __stdio_common_vsprintf。寄存器传选项、缓冲、容量和格式，栈传 locale 与 va_list。0x1866a 将负值统一为 -1。

255 个入口中 156 个有覆盖、99 个缺口，3,567 条引用中 26 条未决。整件静态验收未通过。 [回执](s61-submission.md) · [复验](s61/reassembly.json)

## s65 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x18679,0x18690)`，片段 SHA-256 `0bdaee68814590d466bcb16d251d70b6da23ac40874a079c557d4f7bc9d84f47`。

23 字节与原件吻合，含 7 条可达指令、1 字节 INT3 填充和 1 处 REL32。异常表记录 12 字节，展开信息 8 字节，均吻合。0x18682 从 RDX 指向的帧基址偏移 0x40 读取 1 字节到 CL。恢复栈和 RBP 后，0x1868a 尾跳转至 0x15c74。目标保存并检查 CL。0x1868f 为填充。0x1c0c4 的展开信息记录 32 字节栈分配与 RBP 保存。

255 个入口中 157 个有覆盖、98 个缺口，3,567 条引用中 26 条未决。整件静态验收未通过。 [回执](s65-submission.md) · [复验](s65/reassembly.json)

## s69 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x18690,0x186a9)`，片段 SHA-256 `a54e4ac5b75e2d5ec0f89911437c11b2337c7e57f480b9eff0b262da1f5c3a7f`。

25 字节与原件吻合，含 9 条可达指令、1 字节 INT3 填充和 1 处 REL32。异常表记录 12 字节，展开信息 8 字节，均吻合。0x18699 从 RDX 指向的帧基址偏移 0x20 读取 1 字节到 CL，0x1869c 调用 0x15c74。目标保存并检查 CL，调用返回后恢复栈和 RBP。0x186a8 为填充。0x1c120 的展开信息记录 32 字节栈分配与 RBP 保存。

255 个入口中 158 个有覆盖、97 个缺口，3,567 条引用中 26 条未决。整件静态验收未通过。 [回执](s69-submission.md) · [复验](s69/reassembly.json)

## s73 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x186a9,0x186f3)`，片段 SHA-256 `aa7c30e248012be77ecefdc2b6d6a0935f7bd5b1e442a705eec07623bde18aab`。

两个相邻例程的 74 字节均吻合，各末尾一字节 INT3，共 22 条可达指令。两处直接转移及一处 RIP 引用的 REL32 均已核对，两条 .pdata 共 24 字节，两条 .xdata 共 16 字节。0x186b7 恢复栈和 RBP 后尾跳 0x15b00。0x186e6 调用 0x15a70，前四参来自帧字段 0x60/0x68/0x70 和原件内部回调 0x1540c，后两参来自入口 RCX 间接指向的四字节及该入口 RCX 指针。目标在恢复栈前读取两项栈参数，随后经 0x18096 转至 CRT 的 _seh_filter_dll 导入。

255 个入口中 160 个有覆盖、95 个缺口，3,567 条引用中 26 条未决。整件静态验收未通过。 [回执](s73-submission.md) · [复验](s73/reassembly.json)

## s77 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x186f3,0x1870b)`，片段 SHA-256 `515c04e0ba3bb82e249e1f52765ba9c74cf63305116d4e5c2393eb92ba558686`。

24 字节逐字节吻合。9 条可执行指令与 0x1870a 的单字节 INT3，代码无重定位，.pdata 12 字节与 0x1c1cc 的 .xdata 8 字节吻合。0x186f8 经 RCX 取异常记录指针，0x186fd 比较记录开头的 DWORD 与 0xc0000005。ECX 先清零，SETZ 写 CL，EAX 在相等时返回 1，其余返回 0。0x15bdc 宿主的 0x1c1bc 范围记录指向该过滤器，0x15c6d 为接续地址，展开处理经 0x18066 绑定 VCRUNTIME140.dll!__C_specific_handler。

255 个入口中 161 个有覆盖、94 个缺口，3,568 条引用中 26 条未决。整件静态验收未通过。 [回执](s77-submission.md) · [复验](s77/reassembly.json)

## s81 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x15bdc,0x15c74)`，片段 SHA-256 `81780160b17c32a33bbbc2558815727294f8c1e334451a70b9c2bfeec2c823e7`。

152 字节、48 条指令、3 处代码 REL32、12 字节 .pdata 及 32 字节 .xdata 均吻合。展开数据包括 5 处已绑定的 ADDR32NB 重定位。0x15be8、0x15bf1、0x15bf8 分别访问 DOS 签名、e_lfanew 和映像基址。验证 PE 签名和 PE32+ 魔数后按 40 字节节表项查找输入地址，按 VirtualAddress 和 VirtualSize 确定范围。0x15c5b 对 Characteristics 做有符号比较，最高位 IMAGE_SCN_MEM_WRITE 为零时返回 AL=1。无匹配节、头校验失败或进入 0x15c6d 异常接续时返回 AL=0。0x1c1ac 的展开范围记录连接 0x18066 的 __C_specific_handler 跳板和 s77 过滤器 0x186f3。

255 个入口中 162 个有覆盖、93 个缺口，3,572 条引用中 26 条未决。整件静态验收未通过。 [回执](s81-submission.md) · [复验](s81/reassembly.json)

## s85 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`，范围 `[0x15c74,0x15c98)`，片段 SHA-256 `601c3b9783b84859e5612bf54a500539f69f2005c8e71d70ba2fdb20992f42cc`。

36 字节、13 条指令、2 处代码 REL32、12 字节 .pdata 和 8 字节 .xdata 与原件吻合。0x15c7a 把入参 CL 保存在 BL；0x15c7c 的被调函数 0x1654c 只读 0x22270 的 DWORD，将是否非零编码为 EAX 0/1。0x15c85 按 EAX 跳转，0x15c89 按 BL 跳转。EAX 非零且 BL 为零时，0x15c8b 用内存 XCHG 将 0x22cb8 原子置零。该 8 字节槽位于 .data 的加载器零填充区，0x159cb 用 LOCK CMPXCHG 竞争写入。可执行原始区间的 RIP 相对操作数扫描复核了这两个已确认的指令边界。间接别名或运行时写入仍需相应证据。

255 个入口中 163 个有覆盖、92 个缺口，3,572 条引用中 26 条未决。整件静态验收未通过。

[回执](s85-submission.md) · [复验](s85/reassembly.json)

## s89 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15c98,0x15cc1)`，片段 SHA-256 `1288ab854e40c127977a18655e781a4fc0e5dc84feb93677bd678af3e1ea5938`。

回编 41 字节、14 条解码指令、3 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。0x22cc0 为零或 DL 为零时两次调用 0x184f8，之间从 BL 恢复 CL。被调体只写 AL=1；包装函数也只声明 AL 的布尔返回。标志是可写节的零填充，0x15b1c 在 ECX 为零时置 1；可执行原始区域的 RIP 相对扫描只找到该写点及 0x15c9e 读点，计算地址和运行时写入有待相应证据。

255 个入口中 164 个覆盖、91 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

[回执](s89-submission.md) · [复验](s89/reassembly.json)

## s93 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15cc4,0x15cfe)`，片段 SHA-256 `22f4dfa6d1add55d959e2ab6d2e7f0b7192c75d500d2b3ae08b0e971e5d042f9`。

回编 58 字节、17 条解码指令、4 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。0x22cc8 的 8 字节加载初值为零。比较完整 qword 的 -1 哨兵，成立则以原 RCX 调用 _crt_atexit，否则以 RCX=表地址、RDX=回调调用 _register_onexit_function。两跳板与实际 IAT 0x19158/0x19168 对应；返回 EAX 为 0 时返回原回调指针，其余返回空指针。原件 0x15ba3 向表首写 16 字节，另两处取地址；完整运行时表内容待证。

255 个入口中 165 个覆盖、90 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

[回执](s93-submission.md) · [复验](s93/reassembly.json)

## s97 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15d20,0x15d37)`，片段 SHA-256 `466a3aba93bfca3396f9f06a0f569bb63706ec4dd0de519a65abb600b8700147`。

回编 23 字节、8 条解码指令、1 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。0x15d24 用原 RCX 调用已回编的 0x15cc4。NEG RAX 的进位区分空指针与非空，SBB/NEG/DEC 将非空映射为 0，将空映射为 -1。0x28 栈空间和共享展开记录均已核。

255 个入口中 166 个覆盖、89 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

[回执](s97-submission.md) · [复验](s97/reassembly.json)

## s101 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15d48,0x15e90)`，片段 SHA-256 `6cf4d365502a8f011c563b22a8b2188a9e00ca7861d0305c8ea100750a554939`。

回编 328 字节、71 条解码指令、11 处 REL32、12 字节 .pdata、16 字节 .xdata 均匹配。以 0x17 查询 IsProcessorFeaturePresent，非零路径以原入参触发 int 0x29；其余路径捕获 CONTEXT，按查得的函数表项选择是否展开，并构造状态 0x40000015、标志 1 的异常记录。清除异常筛选器后，仅当 UnhandledExceptionFilter 返回 0 且 IsDebuggerPresent 的返回值不等于 1 时再调用 0x15d40。0x1807e 经 IAT 0x190d0 绑定 memset；0x5c0 栈帧以及 RBX、RBP 恢复与展开记录吻合。

255 个入口中 167 个覆盖、88 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

[回执](s101-submission.md) · [复验](s101/reassembly.json)

## s105 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15e90,0x15eca)`，片段 SHA-256 `06e4fb35ab14c9fe4c5e1bd9b106ce05a66e5b36f27cd04c8441446ffdb831b8`。

回编 58 字节、12 条解码指令、2 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。原件经 0x1807e 和 IAT 0x190d0 调用 memset 将 0x68 字节清零，经 IAT 0x19078 调用 GetStartupInfoW，由 STARTUPINFOW.dwFlags 的低位决定返回 wShowWindow 或 SW_SHOWDEFAULT（10）。Win32 布局见 [Microsoft STARTUPINFOW](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow)。

255 个入口中 168 个覆盖、87 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

[回执](s105-submission.md) · [复验](s105/reassembly.json)

## s109 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15ed8,0x15f29)`，片段 SHA-256 `a770ffd4b25132856e7686d08700a557db24cefb90fa4304ff455f11e1b8c714`。

回编 81 字节、23 条解码指令、1 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。原件经 IAT 0x19088 调用 GetModuleHandleW(NULL)，取进程主模块。返回空、DOS 或 PE 签名不匹配、可选头非 PE32+，或 NumberOfRvaAndSizes 不大于 14 时返回 false。其他路径以索引 14 的 CLR 目录 RVA 是否非零决定 AL。保持 e_lfanew 的有符号扩展、目录数的无符号比较和 0x28 字节栈帧。[Microsoft PE 格式](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#optional-header-data-directories-image-only)

255 个入口中 169 个覆盖、86 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

[回执](s109-submission.md) · [复验](s109/reassembly.json)

## s113 局部回编

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15f40,0x15f9b)`，片段 SHA-256 `8585200104557f7b6cb9f862521c227b0d4f37278a44eecde7e5ad32bc5dd2e9`。

回编 91 字节、27 条解码指令、3 处 REL32、12 字节 .pdata、12 字节 .xdata 均匹配。读取 EXCEPTION_POINTERS 中的记录指针。代码为 0xe06d7363、参数数为 4，且第一个参数在 0x19930520–0x19930522 或为 0x1994000 时进入 C++ 终止路径。0x18072 与 0x18078 提供异常记录和上下文的线程局部槽地址，写入后转 0x180cc。其他分支返回 EAX=0，并恢复 RBX、RDI。

255 个入口中 170 个覆盖、85 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

[回执](s113-submission.md) · [复验](s113/reassembly.json)
