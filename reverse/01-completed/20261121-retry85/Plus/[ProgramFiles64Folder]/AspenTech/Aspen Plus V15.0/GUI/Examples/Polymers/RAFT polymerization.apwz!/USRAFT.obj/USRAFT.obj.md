# USRAFT.obj 静态验收

**通过。本件只有一个本地函数，已恢复为可编辑的固定格式 Fortran。**

## 原件与复验来源

- Aspen Plus V15.0，`Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Polymers/RAFT polymerization.apwz!/USRAFT.obj`。对象本身未记录独立文件版本。COFF 时间戳为 2025-03-24 13:46:50 UTC。
- 原件由固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75` 的 `原版文件/` 对应路径获取，长度 6,557 字节。SHA-256 为 `c6f4bd93d68d7177c98f957d0b7b7b49d32b8d6d7d0b5c87fd8dae2be7dd7b10`，与 Plus 清单安装包成员及已安装成员两行相符。
- 从同一固定提交经 GitHub 连接器读取旧入口、归档说明和分支交付原报告。旧报告的 `unsupported_non_pe` 来自要求 DOS 头的两套 PE 读取器。本轮 COFF 文件头、节表、符号表及 Ghidra MS COFF 加载结果共同确认机器类型 `0x8664`，原件为 x64 COFF 可重定位对象。
- 可编辑基准来自安装目录下 `Aspen Plus V15.0/GUI/Examples/Polymers/USRAFT.f`。其 SHA-256 `d424ddf828ad70d63d3666aa9d94b2aae75643b373e8f4bec6b7dd00d79844cb` 与原安装包中独立源码及同一 APWZ 内的源码成员两条清单记录一致。交付保留固定格式、参数顺序、各分支及原有边界行为。改动见下文。

## 整件覆盖

Ghidra 12.2 PUBLIC（Temurin 25.0.5.1+2）以 `MS Common Object File Format (COFF)` 和 Windows x86-64 语言导入，在同一原件上以 PowerShell 7.6.9 读取原始节、符号、重定位与节数据。Ghidra 唯一有本地函数体的符号是 `USRAFT`。地址 `0x2500–0x2e1a` 覆盖 .text 内代码偏移 `0x000–0x91a`，共 455 条指令，含 RET 后跳回主路径的两个短块。剩余 `0x91b–0x91f` 为一条五字节 NOP 对齐。其余六个节覆盖如下。

| 节 | 核对结果 |
| --- | --- |
| .bss | 0x58 字节，11 个槽位，与 Fortran 静态局部变量对应。尤其保留 HOLDUP、JAAR、JRSEG 在缺少对应匹配时沿用静态存储的行为。 |
| .data | 0x90 字节，九组各占 16 字节的属性标识。同源码 DATA 的空格填充和调用顺序一致。 |
| .rdata | 0x80 字节，数值字面量、负号掩码及六组字符参数。常量包括折叠后的 0.785375、-1.986、273.15、3600、1。 |
| .pdata、.xdata | 一条运行函数记录，三条 ADDR32NB 分别指向 USRAFT 起点、USRAFT+0x920 和 .xdata 的展开记录。0x3c 字节的展开数据与函数的寄存器保存和栈框架对应，由 Windows x64 编译器生成。 |
| .drectve | 0xbb 字节，Intel Fortran 与 MSVC 运行库的默认链接指令。无独立资源节。 |

原始 COFF 表有 .text 重定位 103 条、.pdata 重定位 3 条。Ghidra 导入时未能解析 .text 中 54 条指向节符号的 REL32/REL32_4，预分析脚本从原对象按符号位置及 addend 修正 Ghidra 分析工程里的位移。源对象的字节未改动。另有 .pdata+8 的一条 ADDR32NB 未由加载器应用，原表确认其目标是 .xdata+0。证据文件有原件重定位表和修正后的反汇编，反汇编用 Ghidra 分析地址。需要重跑可在本件 `work/` 查 `FixUsraftRelocs.java`、`ExportUsraft.java`、`InspectCoff.ps1` 和 `final-headless.txt`。工程名为 `UsraftFinal`，位于本件指定的 LOCALAPPDATA 隔离工程目录。

## 分支和调用核对

| 原算法位置（随附源码行号） | Ghidra 地址 | 对照 |
| --- | --- | --- |
| 流股量及液相体积，约 150–162 | 0x2575–0x2638 | 从 DMS_NCOMP 和 SOUT 取流量、分子量、密度及液相分数，调用 PPMON_VOLL，核对其 11 个传参位置与调用后 VMXL 的读取。 |
| 反应器持液量，167–173 | 0x263c–0x26f9 | RBAT、RCST、RPLU 三个八字节比较；分别取批式体积、CSTR 体积及小于 1 时的分数乘积、管数与管径平方。其余类型继续读静态 HOLDUP。 |
| 聚合物结构与成分，178–211 | 0x26fa–0x2971 | 两次 DMS_LOCATI，DMS_PLEX 下标换算，MW 和五个成分标识的调用及隐藏字符长度。核到组分向量中 RAFT 的末次匹配，以及无匹配时浓度为零。AA 查询仍执行，未使用的 JAA 结果已被编译器消除。 |
| 属性与矩，217–241 | 0x2971–0x2bd2 | SHS_LCATT 九次调用，第一实参均指向八字节整数 1，九组 ID 与 .data 一致。核对活性和休眠的零至二阶矩的液相体积换算、两类链段的向量化匹配和尾部处理。 |
| 速率、返回槽位，246–284 | 0x2bd3–0x2de6 | REALR(1:4)、温度和指数项与分子量换算对应。核对 RATES 两处及 RATCAT 八处写入、符号和扣除 NCOMP_NVCP 的索引。对象直接将 R1_0 写入休眠链零阶矩，该存储位于另两项休眠链矩之后。 |

外部调用共 20 处，分属 PPMON_VOLL（1）、SHS_FIPOLM（1）、DMS_LOCATI（2）、DMS_IFCMNC（1）、DMS_KCCIDC（5）、SHS_LCATT（9）和 exp（1）。这七个符号在原件中只有未定义记录。七个有代码引用的 COMMON 导入由安装产品提供。观察到默认整数和索引为 8 字节，DMS_NCOMP 的 NCC 位于偏移 0、NVCP 位于偏移 0x28。Windows x64 入口使用源码中 47 个按引用传递的位置，实际使用的栈位包括 IDS（第 9）、NBOPST（第 11）、RATES（第 19）、RATCAT（第 24）、NCOMP（第 30）、IDX（第 31）、X（第 33）及 REALR（第 43）。Ghidra 自动函数原型仅识别了寄存器参数，传参判断依据原汇编和随附源码。

## 交付改动与重编边界

1. 第 48 行 `#include "rbtc_rbatr.cmn"` 删除右引号后多出的 `l`，使其成为正常预处理指令。
2. 删除 `R2_0` 的变量与计算，以 `RATCAT(L_DOR + 1 - NCOMP_NVCP) = R1_0` 直接写回，并对应对象将该写回置于两个高阶槽之后。原机器代码消除了两个相同乘积相减的表达式。这样以后采用保留 NaN 的浮点编译设置时，该槽也不会重新计算已消除的减法。

13 个 COMMON 声明可由本机 Plus 和 AprSystem V15.0 的 `Engine/Commons` 提供，文件路径和指纹已记录在证据中。原安装版 `AprSystem V15.0/Engine/Xeq/aspcomp.bat` 的 Intel 配置包含 `/fpp /Qsave /4I8 /MD` 及对应 include 路径。结合对象的 8 字节整数和静态槽位，Windows 重建时须保留这些 ABI 属性。随附源码的旧 Fortran 语法和整数 DATA 中字符常量按该 Intel 方言处理。本机未找到可用的 ifort/ifx，因此本轮没有回编、链接或运行。Windows 阶段用 V15 RAFT 案例复核 COMMON 链接、跨调用状态及速率差异，并在比较前确定单位与数值容差。

## 成果指纹

- `USRAFT.obj.f` SHA-256 `daffe5d74dc8f8264b2930615af4b0e9fe011be49bb6e47340a076f58b53386a`
- `USRAFT.obj.evidence.txt` SHA-256 `ac1293b159316bfd779ee12d21d024beacf63c39f21675da9fa4b4795ad96f5c`

本件交付只含示例源码及静态证据。检查范围内无凭据、永久本地保护目录内容、安装包、属性数据库或公式提取归档。上述运行库、COMMON 声明及编译器按路径引用。

