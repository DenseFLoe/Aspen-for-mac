# BFDYLD.obj

**静态验收通过。** 同一 Aspen Plus V15.0 示例归档同时交付 AMD64 COFF 对象和固定格式 Fortran 源码。本轮以原对象的机器指令、重定位及必要数据复核配套源码，将原始 Fortran 按字节归档为 `BFDYLD.obj.f`。Windows 回编、链接与运行对照待后续阶段。

## 身份与来源

| 项目 | 核验结果 |
| --- | --- |
| 产品与版本 | Aspen Plus V15.0 安装载荷。原对象无独立文件版本。COFF 时间戳为 2022-08-31 19:59:34 UTC，不据此推定版号或构建日期。 |
| 原路径 | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Biofuel and Biochemicals/Bioethanol from Corn Stover/Lignocellulosic biomass to ethanol.apwz!/BFDYLD.obj` |
| 固定准备提交 | `9559b75390876346c69b185dbaaba18692a7af75`，分支 `codex/reverse-unsuccessful-85`。从 `原版文件/Plus/` 下同路径读取原对象。 |
| 原对象 | 5,629 字节，SHA-256 `3caaf37f068d6fa7c36ae8d1600055e236002a2538baa2a15f377769a1c1620a`。固定提交取回件与本机已安装示例 APWZ 的同名成员指纹一致。 |
| 源码 | 同一 APWZ 根成员 `BFDYLD.f` 与安装目录旁的 `BFDYLD.f` 以及 Plus 安装包源清单记录一致。5,926 字节，SHA-256 `9c4b6d277af6643d2f199656e6aece7e478290368613b0bd9b5002f799b10fb1`。交付文件保持原字节，只改归档文件名。 |
| 旧报告 | 固定提交对象目录下 `分支交付/BFDYLD.obj.md`。此前用 PE 解析器读取并报告缺 DOS 标头。本次核实文件头为 `IMAGE_FILE_MACHINE_AMD64`（0x8664）、可选头长度为零的可重定位 COFF。 |

## 源码与对象对照

下表地址全部是对象的 `.text` 相对偏移，可在 [instruction-map.txt](evidence/instruction-map.txt) 定位。Ghidra 映射的 `.text` 起点为 `0x2700`。源码行号以交付的 [BFDYLD.obj.f](BFDYLD.obj.f) 为准。

| 源码位置 | 对象证据 |
| --- | --- |
| 7–68，入口、声明、COMMON 和 IPROG | 唯一自有函数 `BFDYLD` 位于 0x000，Windows x64 的 RCX、RDX 传入 SIN、SOUT。其余 14 个形参保留在源声明中，对象实现未读取。0x025–0x072 根据 `NCOMP_NCC` 为两张动态表分配空间，调用两次 `__chkstk`。8 字节整数访问与 Aspen 编译脚本的 `/4I8` 一致。0x2a8、0x44a 引用 `.data+0x130` 的两项 `USRP`、`YR`。 |
| 74–78，查询属性位置 | 0x073–0x0df 共五次 `DMS_IFCMNC`，`.rdata+0x58/60/68/6c/74` 分别保存 BIOID、BIONO、MW、BIOPOS、BIOCOMP；传入字符长度依次为 5、5、2、6、7。最后一次返回值未被使用，外部调用保留。 |
| 86–98，构建反查、复制流量和读取分子量 | 0x0df–0x121 五次 16 字节写配合循环，清零 400 字节，即 50 个 8 字节表项。0x156–0x1b4 复制 SIN、读 MW、比较 RMISS、截断转换有效 BIOPOS，并写一基下标反查表。0x6d5–0x6de 将 IMISS 写入当前位置表后返回循环。 |
| 117–130，检测和告警 | 0x216–0x26d 展开读取并合计 12 个 BIONO。0x26e–0x29d 检查正值、清零目标流并比较上下界。阈值是源码默认 REAL 常量 `0.99`、`1.01` 经单精度舍入再扩宽后的二进制值。0x29e–0x2f7 调用消息检查，等级 3、代码 9002；只有返回非零时才到 0x5d4–0x646，计算归一化因子并调用内部格式写入与 `DMS_ERRPRT` 后继续。 |
| 131–149，按 BIOID 分配和缺失处理 | 0x31f–0x32d 转换 ID 并跳过零；0x333–0x3f2 是 `ANY(IBIOPOS==BID)` 的向量主循环和标量尾部。0x3f3–0x437 读取反查索引、先除以 SUMBNO，再按 SIN 和两项分子量换算并累加。0x439–0x49f 的缺失路径检查等级 1、代码 9001，返回零继续处理；非零去 0x64e–0x6cd 写消息、调用 `DMS_ERRPRT` 并直接走函数尾声，不写总流量。内层循环上限 12。 |
| 152–164，总流量和格式 | 0x4cf–0x5b9 实现总流量，包含对齐检查、原编译器的 SIMD 多路累加和标量余项，最后写 `SOUT(NCOMP_NCC+1)`。0x6df–0x6e7 是无正组件计数时存零的入口。`.data+0x000` 和 `.data+0x090` 是两个 Intel 格式串数据块，消息文本、换行记录及两处字段宽度可从对象实测。F8.5 记录在 `.data+0x080`，宽度 8、精度 5；I3 记录在 `.data+0x0c0`，宽度 3。两处写入参数分别为实数归一化因子与整数 BID。 |

## 整件覆盖与证据

- [coff.txt](evidence/coff.txt) 列出七节、44 个主要符号及七条辅助符号记录的索引关系、全部 116 个重定位的目标和原值，以及 Intel Fortran、C 运行库默认链接指令。正文只有一个自有函数。4 个 `__imp_*`、宿主调用、Intel I/O、`__chkstk`、`__ImageBase`、`_fltused` 和 6 个 COMMON 声明均由对象记录界定。没有独立界面、托管方法或其他需恢复的对象内实现。
- [coverage.txt](evidence/coverage.txt) 记录所有有原始数据的节指纹、`.bss` 未初始化尺寸、常量、完整代码覆盖和展开关系。375 条合法 x64 指令连续覆盖 1,792 字节，结尾两条是对齐 NOP。59 条代码重定位均落在对应指令内。10 条 `.pdata` 覆盖完整代码范围，与 `.xdata` 中一个主展开记录和九条链式记录对应。主记录的 8 次非易失寄存器压栈、0x118 固定栈空间、RBP 帧设置，以及第二条记录列出的 XMM13/14/15 保存位置已对照指令。
- Ghidra 12.2 PUBLIC 用 `MSCoffLoader`、`x86:LE:64:default`、`windows` 完成加载与静态分析。[ghidra-relocations.txt](evidence/ghidra-relocations.txt) 留存重定位状态。加载器应用 75 条，未应用 41 条本地节符号记录。分别为 `.text` 引用 `.rdata` 11 条、`.data` 4 条、`.bss` 7 条，以及 `.pdata`、`.xdata` 引用 `.xdata` 10 条和 9 条。用原始节、符号索引、重定位类型和加数重新核对全部目标。`.bss` 的负加数和基于 1 的运行时下标共同确定有效地址。Ghidra 自动伪代码对这些位置的地址及外部原型存在误判，实际验收使用标注重定位的指令、原始 COFF 和同包源码。
- [verify_coverage.py](evidence/verify_coverage.py) 在 Python 3.12 和 iced-x86 1.22.0 下接受原对象路径和证据输出目录两个参数，可重生成 `coverage.txt` 与 `instruction-map.txt`。归档同时带 COFF 记录读取器。Ghidra 可复查命令为 `ghidra-headless.cmd <工程目录> BFDYLD -import <BFDYLD.obj> -loader MSCoffLoader -processor x86:LE:64:default -cspec windows`。
- [SHA256SUMS.txt](SHA256SUMS.txt) 记录源码、说明及证据文件的 SHA-256。本件没有发现凭据，也没有从项目永久保护的数据库或公式目录提取任何文件。

## 外部依赖和后续验证

Fortran 需要本机 AprSystem V15.0 `Engine/Commons` 中的六份宿主头文件。它们也对应对象中标明大小的 COMMON 边界，实际运行使用宿主导入。

| 头文件 | 本机 SHA-256 |
| --- | --- |
| ppexec_user.cmn | `110f36b673c0119239fc097d3ec025d3115f9d4c128fefd8a5f364a46360f6` |
| dms_ncomp.cmn | `3daad7850be5c6c9ee2ef5a04478a9d103469371bd0ed4688d37d89659dc2bd7` |
| dms_rglob.cmn | `9cc66a883105964bc9ec26d20e47dbe9f4635f16cef2db1e54c02aba57526c4b` |
| dms_plex.cmn | `26c991773d19a0e5f867f355558bc609e84a078ec5bd994c7b32f9c9b4c8b93e` |
| dms_maxwrt.cmn | `e4a52b20957219337e1eaf1656a483aa0b74c47959499ec718a4eab91272ecf7` |
| dms_errout.cmn | `07044fad1a69684b58cf7a7b6bb03ef00ea8d0a83e9116444a602222e643d283` |

Windows 重建阶段使用 Aspen 的 `aspcomp.bat` 配合 Intel Fortran，保持固定格式、预处理及 64 位 INTEGER 约定。原始 Intel 编译器细版和优化开关未确认，当前会话 PATH 未发现 `ifort` 或 `ifx`，本轮未回编或运行。机器码对 STOTAL 的 SIMD 归约改变了浮点加法结合顺序。届时按原对象的指令顺序或预定数值容差，核对总流量，以及消息检查两种结果下的行为。

