# oomfutilslib.lib 静态复验

返工清单第 3 项，第 1 次处理，2026-11-22。**整件静态验收通过。** 从可编辑 AMD64 汇编独立生成的库与原件逐字节相同，共 118,808 字节。两份文件的 SHA-256 均为 `5b4fdd8b8728e16ba802f472c356613456625f0d400122b3503d03b5e920a23c`。

## 原件身份与范围

- Plus 安装路径为 `[ProgramFiles64Folder]/AspenTech/OOMF V15.0/lib/oomfutilslib.lib`。来源为 Process Modeling (Aspen Plus) V15 (64bit) 安装包 `libOth~2.cab` 的 `oomfutilslib.lib.FFB4EB35_331E_4DFD_A406_FAD839196763`。清单的独立文件版本字段为空，目录和包版本均为 V15。
- 本次从本地 `.local/aspen-plus-github-inputs-20261120-225559-578/originals/` 的对应路径复制到本件 `input`，按 Plus 安装成员的大小和 SHA-256 核实。另一个本地安装成员样本的 SHA-256 也相同。共享清单记有独立 Aspen Properties 安装包 `libOth~3.cab` 的同哈希成员，可用相同 `analysis_key` 关联。本次以 Plus 总表条目为交付对象。
- GitHub 原件准备提交为 `9559b75390876346c69b185dbaaba18692a7af75`，同哈希旧制作者报告 blob 为 `9caeba6e0bec247caebf220d6bf6add19d735528`。旧报告止于 PE 解析失败。此后同件本地分析已找到 16 个 COFF 成员并回编其中 4 个。本次补齐全部成员的可编辑实现、数据、链接指令和异常展开表。[旧报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/逆向成果/未成功/Plus/%5BProgramFiles64Folder%5D/AspenTech/OOMF%20V15.0/lib/oomfutilslib.lib/v0.20261121-w2/制作者报告/oomfutilslib.lib.md)

## 源码和核对结果

`oomfutilslib.lib.asm` 按原顺序列出 16 个 `.member`。按函数名可直接找到入口、调用前的寄存器和栈实参、读写宽度、条件跳转及返回值。分支和异常展开记录引用标签，COFF 重定位引用符号和加数。所有代码节均由指令汇编生成。已初始化数据、字符串、Fortran 格式描述、未初始化区、COMMON 大小以及 `.drectve` 的导出和依赖选项都在源码中。汇编源码为 517,116 字节，SHA-256 为 `8c6d4140978a4ba33631d6f216e8b1f0cff4c32a1182f13d640cc14f0714569c`。

| 核对对象 | 本次结果 |
| --- | --- |
| 两份链接器索引、长名称表和 16 个目标文件 | 92 个索引符号的成员归属及顺序吻合。16 个对象逐件哈希吻合，完整库的每个字节吻合。 |
| 88 个节和 513 个主符号记录 | 节属性及对齐、数据、符号类型与存储类别、辅助记录、字符串表和构建时间戳均随原件完整复现。 |
| 84 个函数 | COFF 定义与 `.pdata` 的起止范围逐个核实。函数体共 69,078 字节、14,696 条指令。整个 `.text` 合计 69,096 字节，另外 18 字节逐个确认为函数范围外的单字节 NOP。 |
| 控制流与调用 | 864 个本地跳转的目标均位于指令起点。361 个直接调用按函数和 COFF 目标列出。参数传递、计算、条件和返回指令都包含在逐字节对照内。 |
| 重定位与异常展开 | 361 个调用和 557 处数据访问形成 918 条代码重定位，另有 252 条 `.pdata` 重定位。84 个函数的展开记录保留序言长度、栈分配、帧指针和非易失寄存器保存位置。 |

独立核验器分别解析原件和回编件，检查两个索引、成员偏移、COFF 符号、各节字节、重定位和展开范围，再比较完整库。另行复用了前轮 Ghidra 12.2 对本哈希成员的输出，逐一核对 84 个入口、14,696 个函数内指令边界、重定位字段以外的指令字节，以及 1,170 个已应用修正位置的符号、类型和原始加数。逐成员与逐函数明细见 [核验记录](oomfutilslib.lib.verification.json)。

## 旧报告中的接口与布局问题

- `rtxfile.obj` 的 `RTXFILE_RESTORE_EXCEPT` 占 `.text` 的 `[0x190a, 0x34aa)`。源码保留 102 个本地跳转和 62 个调用点。首次调用 `RTO_READ_XHDR_F` 时，前四个实参在 RCX、RDX、R8、R9，第五至七个实参写入调用者栈的 `+0x20`、`+0x28`、`+0x30`。其后按原分支取得 `RTOVARLST_*` 表并调用相应更新例程。`RTXFILE_MATCH_MD` 按 8 字节步长比较 16 项，第一处不等返回 0，全部相等返回 1。
- `xfile.obj` 的 `RTO_READ_XHDR_F` 保留 2,048 字节直接读取缓冲区的长度、地址与传给 `for_read_dir` 的参数。读回后把首个有符号 32 位值扩展为 64 位并写给调用方。其余字段的偏移、访问宽度和转换均在该函数的汇编内。
- `rto_getioc.obj` 的 `RTO_GETIOC` 保留 352 字节 COMMON 声明、轮转序号以及 40 个间隔为 8 字节的槽位。调用 `for_inquire` 时，RCX 为局部状态块地址，EDX 为候选单元号，R8 为 `0x801208384ff00`，R9 为只读描述数据地址，第五个参数在 `[rsp+0x20]`。随后检验输出的低位。库内提供方和库外运行时入口列于每个成员的 `cross_member_calls` 与 `external_call_targets`。
- `slatec.obj`、`util.obj`、`oomf_aemap.obj` 等均按原指令操作数恢复了整数与浮点计算、下标换算、寻址比例和访问宽度。汇编交付直接表达 Win64 机器接口。Intel Fortran 运行时等外部定义沿用原 COFF 声明和默认库选项。

## 重现和后续

按 [回编说明](oomfutilslib.lib.build.md) 在单独的工作目录生成库，按 [复验说明](oomfutilslib.lib.verification.md) 重新生成证据并比较。源码、脚本、报告和证据的 SHA-256 见 [指纹表](oomfutilslib.lib.sha256)。

本次仅做静态回编和对照。Windows 链接、文件读写、数值结果与错误路径的实际行为验证留到 Windows 重建对照阶段。主聊天复核后负责发布并同步台账。
