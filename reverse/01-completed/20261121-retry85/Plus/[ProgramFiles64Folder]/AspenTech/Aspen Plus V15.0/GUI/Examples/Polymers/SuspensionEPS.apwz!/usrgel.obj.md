# usrgel.obj

**静态验收通过（`passed`）。** 交付与原件同一示例包附带的可编辑固定格式 Fortran 源码，已按原件的唯一函数、代码分支、静态数据、重定位与异常展开信息复验。验收范围为这一个 COFF 对象。

## 来源与成果

- 产品和版本为 Aspen Plus V15.0。`usrgel.obj` 是该版本 SuspensionEPS 示例的中间目标文件，无独立版本字段。COFF 时间戳为 `0x67be4d1d`（2025-02-25 23:07:09 UTC）。
- 原路径为 `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Polymers/SuspensionEPS.apwz!/usrgel.obj`。从 `codex/reverse-unsuccessful-85` 的固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75` 取用原件。现有 Plus 清单的安装包成员记录与其 5,406 字节及 SHA-256 `e3c4115ceb2c5343152b334c2803783b0818bb898051f7edcaa235ad84457136` 一致。[固定提交原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E5%8E%9F%E7%89%88%E6%96%87%E4%BB%B6/Plus/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Plus%20V15.0/GUI/Examples/Polymers/SuspensionEPS.apwz!/usrgel.obj)
- 已用本机同路径的 `SuspensionEPS.apwz` 打开 ZIP 目录并流式核对其中的 `usrgel.obj`，完整指纹一致。包内 `usrgel.f` 又和现有 Plus 安装包成员清单的 13,438 字节及 SHA-256 一致。包内 `usrgel.dll`（SHA-256 `c6fd6a51929f96e8cf2e6b0824bd1389207775998f1ee18139262fb72507d89a`）只用于解决 COFF 重定位和校验链接边界。
- [usrgel.obj.f](usrgel.obj.f) 是包内源码的逐字节副本，SHA-256 `33b3254499d613982f45ed48754f2d10f67ba477e35ff77bfa9e44078fb5e774`。保留原来的固定格式、制表符、计算精度声明、COMMON 引用及注释。
- [usrgel.obj.static.txt](usrgel.obj.static.txt) 记录自动核验结果，SHA-256 `29cabfa0aa6158c9e177550d49013a64d3e226b9248789ddbd8e254198a28166`。
- 本件正式成果未发现凭据，未引用项目永久本地保护目录中的材料。`usrgel.obj.f` 含示例程序自带的计算表达式。

## 覆盖与工具复验

旧报告中的 `unsupported_non_pe` 源于对 COFF 对象使用了要求 DOS/PE 映像头的解析器。本轮使用 Ghidra 12.2 PUBLIC（JDK 25.0.5.1+2）的 MS COFF loader，语言为 `x86:LE:64:default:windows`。Python 3.12.14 独立核对 COFF 原始字节与链接后 PE，另用 PowerShell 7 的 ZIP 和哈希接口校验输入及成果。[旧逐件报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E6%9C%AA%E6%88%90%E5%8A%9F/Plus/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Plus%20V15.0/GUI/Examples/Polymers/SuspensionEPS.apwz!/usrgel.obj/%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/usrgel.obj.md) · [Microsoft PE/COFF 规范](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format)

| 原件范围 | 复验结果 |
| --- | --- |
| 7 个节、51 个主符号、7 个辅助记录 | `.text` 唯一内部函数符号为 `USRGEL`，位于节偏移 `+0x000`。六个 Ghidra 外部函数条目由 COFF 未定义符号和链接版导入表确认。 |
| `.text` 1,632 字节 | 303 条连续指令至 `RET`，共 1,627 字节，余下 5 字节为一条对齐 NOP。链接版导出 RVA `0x1000`。逐字节比较全部 1,344 个非重定位字节，完全一致；72 个 `REL32` 槽位均映射至对应节内数据、导入地址或导入跳板。 |
| `.rdata` 224 字节 | 和链接版逐字节一致。匹配源码中四个 8 字符字符串和 17 个数值常量；比较用原件先按默认精度表示、再转为双精度的位型。另核对 `1.D0`、传给 `SHS_LCATT` 的整型 1 和浮点符号位掩码。 |
| `.data` 576 字节、`.bss` 8 字节 | 和链接版逐字节一致。源码第 174–183 行的 `ICATYP(2,35)` 共 70 项均对应 8 字节槽位，末尾 16 字节为填充。静态 `IPOL` 是 8 字节零初始化存储，入口在分派前赋值。 |
| `.pdata` 12 字节、`.xdata` 56 字节 | 3 条 `ADDR32NB` 重定位分别得到函数起、止和展开记录 RVA `0x1000/0x1660/0x3678`；链接版的 56 字节展开记录一致，含栈空间及非易失寄存器保存信息。 |
| `.drectve` 187 字节 | 核对 8 条默认库声明，见自动核验结果。无界面、清单资源或独立配置节。同行的 `userfort.dlopt` 指向包内链接版。 |

Ghidra 对节符号的 5 条重定位报 `missing required symbol`。原始 COFF 符号表、重定位项和同包 DLL 的目标位置三方一致，按下表复核 Ghidra 反汇编的操作数。

| COFF 位置 | 符号与用途 | 链接版目标 RVA |
| --- | --- | --- |
| `.text+0x0d0` | `.bss`，存入 `IPOL` | `0x4280` |
| `.text+0x261` | `.rdata`，整型实参 1 的地址 | `0x31a0` |
| `.text+0x268` | `.bss`，`IPOL` 的地址 | `0x4280` |
| `.text+0x26f` | `.data+0x50`，`ICATYP(1,IMWW)` 即 `MWW` 的地址 | `0x4050` |
| `.pdata+0x08` | `.xdata`，函数的展开记录 | `0x3678` |

## 关键行为对照

| 源码行 | COFF `.text` 偏移 | 核对结果 |
| --- | --- | --- |
| 10–14、195–204、228–230 | `+0x000–+0x0d3` | 源码保留 21 个按引用传入的形参。指令访问 `ICORR`、`GPAR`、`GF`、`SOUT`、`NCK`，`ICORR`、`NCK` 等整数为 64 位。先查 `MW`，从 `SOUT(NCK+2)` 取温度并设 `GF=1.D0`，依次查 `NPENTANE/STY/PS`。字符串参数旁传长度 8。 |
| 231–248 | `+0x0d4` 分派、`+0x4f4–+0x613` | 模式 3 读取 n-戊烷的质量分率。原件从 `DMS_PLEX` 依照 `MWoffset+组分号` 取分子量，并用 `DMS_NCOMP` 中的 `NCOMP_NCC` 定位两个总量槽；阈值比较失败时保留初始值。通过时按原源码的三组密度、体积分率及 `GPAR(1)` 算指数并写 `GF`。 |
| 249–295 | `+0x0de–+0x350` | 模式 4 先作聚合物质量分率门槛检查，再计算三个体积分率和临界值。核对 `SHS_LCATT(1,IPOL,ICATYP(1,IMWW))` 的三个地址和之后的 `SOUT(LMWW+1)`。临界比较通过时，`+0x2a0/+0x2d8` 的 `CVTTSD2SI` 对应隐式整型 `MWCRIT`；其为零时先在 `+0x2d2` 按双精度写 `GPAR(4)`，随后转为整型参加后续 `pow/log/exp` 和 `GF` 计算。 |
| 296–322 | `+0x351–+0x4f3` | 模式 5 同样先作聚合物质量分率门槛检查，再汇总三个自由体积分率。确认 `VFTOT <= GPAR(2)` 的比较方向，使用 `GPAR(1)` 和两个倒数的差计算指数；超出门槛时保留初始值。 |
| 231–322、334 | `+0x0d4–+0x0e2`、`+0x351–+0x355`、`+0x614–+0x65a` | 模式 3、4、5 之外及各门槛不成立的路径汇合到同一寄存器恢复和返回序列。源码未被引用的形参和注释保留。 |

运行依赖由实际绑定确认。`atdms.dll` 供给 `DMS_IFCMNC`、`DMS_KCCIDC`、`DMS_NCOMP` 和 `DMS_PLEX`，`zeshs.dll` 供给 `SHS_LCATT`，`libmmd.dll` 供给 `exp/pow/log`。源码所需的 7 个 `.cmn` 来自已安装 V15 的 `APrSystem V15.0/Engine/Commons`，逐件指纹与现有 Plus 安装包清单一致。其中文件 `dms_ncomp.cmn` 的 COMMON 首位字段为 `NCOMP_NCC`，`dms_plex.cmn` 的 COMMON 从 `IB` 开始，与指令访问一致。其余 5 个为 `dms_rglob.cmn`、`dms_global.cmn`、`ppexec_user.cmn`、`dms_ipoff1.cmn`、`dms_errout.cmn`。这些声明由安装环境提供。源码中的 `IPROG` DATA 与未引用的声明保留，原件没有需要为其额外恢复的运行时使用点。

## 复查入口与后续

- 本件隔离目录的 `input/usrgel.obj` 为只读原件。`work/inspect_coff.py` 输出节表、全部符号、重定位及数据（`work/coff.txt`）；`work/ExportUsrgel.java` 输出 Ghidra 指令、重定位索引及静态分析草稿，原生函数入口在 Ghidra 为 `0x2700`。Ghidra 导入、导出记录分别为 `work/ghidra.log`、`work/export.log`。复查时用对应的 `.local/reverse-tools/ghidra-headless.cmd` 打开本件专用工程，可通过 `-process usrgel.obj -noanalysis -scriptPath <work> -postScript ExportUsrgel.java <work>` 重导出。
- 复算附表可运行 `python work/verify_package.py work`（工作目录为本件隔离根，需已有 `input/usrgel.obj`、`work/packaged-usrgel.f`、`work/usrgel.dll` 及 Ghidra 导出的 `work/ghidra-listing.txt`）。按文中的源码行和 COFF 偏移可以逐段复核计算及写入。
- 本轮采用同包源码和静态对照验收。原构建的 Intel Fortran 精确版本和完整命令未取得，本次未回编；V15 附带的 `aspcomp.bat` 给出固定格式、预处理 `/fpp`、静态局部存储 `/Qsave`、64 位默认整数 `/4I8`、`/MD` 及 COMMON 搜索路径，供 Windows 重建核对。Windows 阶段用相同输入对照原版和重建版，覆盖 3、4、5 及默认路径、门槛边界，以及模式 4 对 `GPAR(4)` 的写回。
