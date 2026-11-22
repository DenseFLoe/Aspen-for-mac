# oomfcorelib.lib

**本轮静态验收通过。6 个原始 COFF 成员分别从可编辑的 AMD64 汇编重建，并按原顺序装入静态库。整库 117,484 字节与原件逐字节相同。** 静态结论覆盖 24 个函数、33 个节和 1,329 条重定位。Windows 行为验证留到重建对照阶段。

## 原件身份

原件为 Aspen Plus V15（OOMF V15.0）安装成员 `Plus/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfcorelib.lib`，117,484 字节，SHA-256 为 `2e293c417b2604a77674790839a418a488ff2f8eba3264ffab1b86d0ebc1c967`。MSI 未登记该文件的独立版本字段。

- 安装来源为 `Process Modeling (Aspen Plus) V15 (64bit).msi`，外置柜为 `libOth~2.cab`，归档成员为 `oomfcorelib.lib.FFB4EB35_331E_4DFD_A406_FAD839196763`。来源清单为 `inventories/2026-11-19/plus/01-needs-reverse/files.csv` 第 3663 行。共用索引也登记了相同指纹。本次逐件交付采用指定的 Plus 原路径。
- 本轮读取本地同指纹副本 `.local/aspen-plus-github-inputs-20261120-225559-578/originals/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfcorelib.lib`，复制到本次 `input/oomfcorelib.lib` 后再次核对。原件准备分支为 `codex/reverse-unsuccessful-85`，提交 `9559b75390876346c69b185dbaaba18692a7af75`，仓库路径为 `原版文件/Plus/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfcorelib.lib`。
- 本轮读取主干旧报告（Git blob `973f104b670f2602190105eb7b1c2cd031a41772`），其中 PE 解析在 DOS 头处失败。后续本地同指纹 Ghidra 核查已定位 24 个入口，并交出 5 个 C 实现。此次复用已核实的 Ghidra 函数区间和重定位表，以独立的可回编汇编替代了对其余 19 个候选 C 签名、局部变量和结构类型的依赖。原局部成果和报告继续保留在 `.local/reverse-unsuccessful-85/items/2e293c417b2604a77674790839a418a488ff2f8eba3264ffab1b86d0ebc1c967`。

## 成员与验收

| 原 COFF 成员 | 函数 | 函数内指令 | 重定位 |
| --- | ---: | ---: | ---: |
| `aechks.obj` | 1 | 595 | 59 |
| `rtanalyzevar.obj` | 9 | 2,061 | 40 |
| `rtcfg_f.obj` | 5 | 9,547 | 1,117 |
| `aosgen_int_f.obj` | 3 | 87 | 20 |
| `rtanalyzeqn.obj` | 4 | 1,144 | 16 |
| `rtsenstvt.obj` | 2 | 1,101 | 77 |

- 成员均为 AMD64 COFF，源码以原函数名和分支标签表达 x64 指令。Capstone 独立解码了 76,949 字节函数体内的 14,535 条指令。另有 7 字节 NOP 填充。`.text` 中全部 727 条跳转均落于本函数的指令边界。696 处调用中含 32 处间接调用。原调用参数位置、栈帧、寄存器使用、数值指令及分支顺序均随函数字节核对。
- 每个函数的开始和结束均由 COFF 函数符号及 `.pdata` 三元组定位，与既有 Ghidra 12.2 PUBLIC 的函数范围吻合。重定位按成员、节内位置、符号与类型复核，1,329 条均与既有 Ghidra 的 APPLIED 记录相符。源码按标签生成 `.pdata` 和 `.xdata`，逐个验证了展开操作与序言长度指向相应代码位置。
- 源码保留只读数据、初始化数据、零初始化节、格式描述符、链接器指令、异常展开记录及相关符号。六个原始成员分别恢复，保留按需链接的选择粒度。两个链接器索引各含 27 项，覆盖 24 个函数及 `OOMF_PLEX`、`OOMF_GLOBAL`、`OOMF_RGLOB` 三个 COMMON 名称，两个索引的符号与成员映射一致。
- Aspen、Intel Fortran 运行库和系统辅助函数在原件中通过外部符号、导入指针或调用方提供的函数指针引用。汇编保留这些边界，支持逐条核对 `__chkstk`、`for_open`、`for_close` 等调用处及其参数。原编译器生成的 Fortran 格式包也在本件数据节内重建。
- 六个对象各自与对应原成员逐字节一致，随后对整份静态库进行字节比较。两个链接器索引、长名表、各成员头、节、符号、重定位及字节填充均包含在比较内。逐项结果和指纹保存在 [静态核验证据](evidence/static-verification.json)。

## 重现

从交付目录运行下列 PowerShell 命令。输出目录可使用新的临时位置。此库可在没有原件、旧 Ghidra 工程及 Aspen 运行库的情况下回编。

```powershell
$root = 'C:/Users/Administrator/Desktop/Aspen'
$python = "$root/.local-tools/research/venv/Scripts/python.exe"
$assembler = "$root/.local-tools/qt/Tools/mingw1310_64/bin/as.exe"
$rebuilt = Join-Path ([IO.Path]::GetTempPath()) ('oomf-rebuild-' + [guid]::NewGuid())
& $python ./oomfcorelib.lib.build.py --assembler $assembler --out $rebuilt
Get-FileHash -Algorithm SHA256 -LiteralPath (Join-Path $rebuilt 'oomfcorelib.lib')
```

本轮使用 GNU Binutils 2.39 的 objdump、as 和 ar，以及 CPython 3.12.14 和 Capstone 5.0 系列（Python 分发包 5.0.9）。预期整库 SHA-256 为 `2e293c417b2604a77674790839a418a488ff2f8eba3264ffab1b86d0ebc1c967`。以 GNU ar 另行回读原件及回编件的六个成员名和顺序。各源文件与核验证据的指纹见 [交付指纹](artifacts.sha256)。

在独立临时副本的 `GENSOLV_FOPEN` 返回前插入一条 NOP 后重新构建，只有 `aosgen_int_f.obj` 发生变化。该成员的代码恰好多出这一条指令，展开表中该函数的长度从 214 变成 215 字节，其他五个原成员的指纹保持一致。正式交付采用与原件一致的源码版本。
