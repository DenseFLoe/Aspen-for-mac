# BFDYLD.obj 静态验收说明

**结论：通过静态验收。** 样例附带的固定格式 Fortran 源码覆盖该目标文件唯一的自有过程 `BFDYLD`。同目录 `BFDYLD.obj.f` 是原样复制的源码，未改写算法、注释或换行。

## 来源和指纹

- 产品 Aspen Plus V15.0。原路径 `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Biofuel and Biochemicals/Biomass characterization/Biofeed converter.apwz!/BFDYLD.obj`。
- 原件来自 `DenseFLoe/Aspen-for-mac` 的 `codex/reverse-unsuccessful-85` 固定准备提交 `9559b75390876346c69b185dbaaba18692a7af75`，GitHub 路径加前缀 `原版文件/Plus/`。实测 5,629 字节，SHA-256 `194e88b44801eb787ccd0964ef43f869a7d355a2ea905a0f679d173f91703ec0`，与本机安装样例包中的同名成员流式散列一致。
- 对象清单未记录独立版本。COFF 头时间戳为 `2022-08-31T23:15:36.000Z`，源码注释日期为 2022 年 6 月。Intel Fortran 运行库由链接指令和 DLL 导入确认，精确编译器版本和构建参数待查。
- 源码为同一 `Biofeed converter.apwz` 的成员 `BFDYLD.f`，实测 5,926 字节，SHA-256 `9c4b6d277af6643d2f199656e6aece7e478290368613b0bd9b5002f799b10fb1`，与本机安装包成员清单一致。同包静态对照件 `BFDYLD.dll` 为 11,776 字节，SHA-256 `f80d424238afde109cb1257446f1c0e11914a806f625bad1523cfeb778440216`。原包、原件和对照 DLL 的工作副本只用作输入。

## 结构与重定位核对

旧报告由 `dnfile`、`pefile` 在 DOS 头检查处停止。本轮 Ghidra 12.2 PUBLIC 识别为 MS COFF、`x86:LE:64:default:windows`。COFF 机器值 `0x8664`，可选头长度 0，有 7 个节和 51 个符号表项（含辅助项）。对象文件本身要经链接才可加载。

| 原节 | 大小 | 核对结果 |
| --- | ---: | --- |
| `.text` | 1,792 | 唯一过程从节偏移 0 开始，占 1,780 字节。后 12 字节为两条多字节 NOP。链接版入口 RVA `0x1000`。1,556 个非重定位字节一致，59 处重定位目标吻合。 |
| `.rdata` | 128 | 全字节一致，保有 5 项属性名、诊断常量、浮点阈值及格式所用数据。链接 RVA `0x3190`。 |
| `.bss` | 416 | 原件没有原始数据。链接版 RVA `0x4180` 起的范围由零值文件字节和节虚拟零填充覆盖，包含按 8 字节整数访问的 50 项 `REVBIOP`。 |
| `.data` | 320 | 全字节一致，覆盖格式包和 `IPROG`（偏移 `0x130`）。链接 RVA `0x4000`。 |
| `.xdata` | 184 | 76 个非重定位字节一致，27 处重定位匹配同一过程与展开数据基址。链接 RVA `0x3678`。 |
| `.pdata` | 120 | 10 条运行时函数记录，30 处重定位覆盖起点、终点和展开信息，归属于同一个过程。链接 RVA `0x5000`。 |
| `.drectve` | 187 | 记录 8 项默认链接库指令，原字节及文本见 `evidence/coff.json`。按原节字节保留。DLL 的实际导入与库实现见本表后的对照。 |

Ghidra 导入 COFF 时有 41 处缺少节符号绑定。原始 COFF 表解析得到每处节号、偏移、符号和加数；链接 DLL 的独立核对按 RVA、相对位移、导入表及跳板求得实际目标。所有 41 个地址和重定位类型均与核对结果一致。共核对 2,080 个非重定位字节、116 处重定位。五个在 COFF 分析中列出的外部调用只有外部声明，DLL 证据将其中四个映射到导入跳板，将 `__chkstk` 映射到 RVA `0x1730` 的栈探测实现。其余间接数据访问绑定到 `atdms.dll` 的公共块。

## 源码与指令对照

下表机器码地址为链接 DLL 的 RVA。复查时用 `evidence/BFDYLD.obj.linked.asm.txt`，其显示完整虚拟地址（映像基址 `0x180000000`）。Ghidra 伪代码保留在 `evidence/BFDYLD.obj.linked.c.txt`，变量和类型名为分析器推断，以 Fortran 原稿和指令为准。

| Fortran 源码位置 | 链接指令及对照结果 |
| --- | --- |
| 7–8、20–25、35–47 | 声明 16 参数，正文实际使用前两个数组形参 `SIN`、`SOUT`。`0x1018–0x1072` 保留 RCX/RDX 中的两个指针，读取 `NCOMP_NCC`，为两个按组件数定长的本地数组做栈分配。 |
| 74–101 | `0x1073–0x11b3` 依序调用 `DMS_IFCMNC` 查询 BIOID、BIONO、MW、BIOPOS、BIOCOMP。保留 BIOCOMP 即使返回值未用的调用，清零 `REVBIOP`，复制入口流量、读 MW 和 BIOPOS、判断缺失哨兵并建立逆映射。 |
| 117–131、162–163 | `0x11b4–0x12f8` 按每组件 12 项累加 BIONO，仅在和大于 0 时清掉该组件的出口量；比较两个阈值。原件 double 比较常数为 `0.9900000095367432` 和 `1.0099999904632568`，对应源码默认实数常量提升。调用 `DMS_IRRCHK` 的参数含 3、9002。只有其返回非零才走 `0x15d4–0x1646` 的 `1/SUMBNO`、格式 165 和 `DMS_ERRPRT(2)`。 |
| 132–148、159–160 | `0x1323` 将 BIOID 截断转整数；零 ID 跳过。`0x132a–0x13eb` 为 `ANY(IBIOPOS==BID)` 的向量及尾部扫描。`0x13ed–0x142d` 取 `JBID`，按 `BIONO/SUMBNO` 归一化，执行 `SIN(I)*MW(I)*BNO/MW(JBID)` 并累加。`0x147e` 用 1、9001 检查缺失分支，返回非零时走 `0x164e–0x16cd`，执行格式 160、打印并提前返回。检查返回零时继续处理。 |
| 152–156、166 | `0x14cf–0x15d3` 计算 `STOTAL`，包含向量归约与标量尾部，并写入 `SOUT(NCOMP_NCC+1)` 后经尾声返回。 |

## 构建边界与复查

- 六份 `#include` 是 Aspen 安装提供的 Fortran COMMON 声明。使用 `AprSystem V15.0/Engine/Commons/` 下已核验的同名声明，本件的源文件直接引用它们。它们各自的哈希如下。
- 直接调用和公共块数据由 `atdms.dll` 提供；格式化写入由 `libifcoremd.dll` 提供。`__ImageBase` 为链接器定义符号。八条默认库指令及六个 Fortran COMMON 名、尺寸在 COFF 表中保留，链接实测的 DATA 导入为 DMS_NCOMP、PPEXEC_USER、DMS_PLEX 和 DMS_ERROUT。Windows 构建须保存原 64 位整数约定（例如 `NCOMP_NCC` 的 qword 读取和 `REVBIOP` 的 8 字节索引）及默认实数常量转换；总量归约顺序也受编译优化影响。
- 本轮未回编源码或运行 Aspen，静态判定使用同包源码、原件及可逐字节验证的已链接原版对照。Windows 重建阶段对照有/无生物进料、归一化警告、缺少 BIOID 的继续或提前返回、总量及 COMMON ABI。
- `evidence/coff.json`、`evidence/compare-pe.json` 和 `evidence/validation.json` 可复查节、成员和链接核对。导出工具为 Ghidra 12.2 PUBLIC、便携 JDK 25.0.5.1+2、Node.js v24.22.3。正式成果已检查，未发现凭据或项目永久本地保护材料。

| 外部头文件 | SHA-256 |
| --- | --- |
| `ppexec_user.cmn` | `110f36b673c0119239fc097d3ec025d3115f9d4c128fefd8a5c5f364a46360f6` |
| `dms_ncomp.cmn` | `3daad7850be5c6c9ee2ef5a04478a9d103469371bd0ed4688d37d89659dc2bd7` |
| `dms_rglob.cmn` | `9cc66a883105964bc9ec26d20e47dbe9f4635f16cef2db1e54c02aba57526c4b` |
| `dms_plex.cmn` | `26c991773d19a0e5f867f355558bc609e84a078ec5bd994c7b32f9c9b4c8b93e` |
| `dms_maxwrt.cmn` | `e4a52b20957219337e1eaf1656a483aa0b74c47959499ec718a4eab91272ecf7` |
| `dms_errout.cmn` | `07044fad1a69684b58cf7a7b6bb03ef00ea8d0a83e9116444a602222e643d283` |

从本件工作目录复查时，`evidence` 表示本交付里的同名目录。Ghidra 原件项目以 `-import BFDYLD.obj` 正常分析，链接 DLL 项目以 `-import BFDYLD.dll -scriptPath <脚本目录> -postScript ExportBfdyld.java <导出目录>` 分析和导出。关键日志行保存在 `evidence/ghidra-coff.log`。以下命令中的原件、源码和对照件路径可用本机对应文件的绝对路径替换。

```powershell
node evidence/coff.mjs BFDYLD.obj | Set-Content -Encoding utf8NoBOM coff.verify.json
node evidence/compare-pe.mjs BFDYLD.obj BFDYLD.dll coff.verify.json | Set-Content -Encoding utf8NoBOM pe.verify.json
node evidence/check.mjs BFDYLD.obj BFDYLD.dll BFDYLD.obj.f coff.verify.json pe.verify.json evidence/ghidra-coff.log
```

## 证据指纹

```text
6bc0fee0c6673199f4e1c699c34fd513ac77be0e683fe292275a4ad003e72466  evidence/BFDYLD.obj.linked.asm.txt
e99a9776a21b49a3f7ea9c605c3a3e7b1f2e8b8c3a5a54b69bde89d5da9c5b67  evidence/BFDYLD.obj.linked.c.txt
d056c0e6c015b93f8737e00846eaab835f4bcfd8908990b45ecf2857cfd9af06  evidence/check.mjs
a539b8d73e201c8d8ca487f0dc295b988365396efaf8a0a85a110e68304be044  evidence/coff.json
829658ba17d7b4a85a2940ffb1affb53a3dd41cecb6f6e941ef5869e4fc64aa5  evidence/coff.mjs
de9b49f8606d6c9eed055dc293aa97c33543e4be8ef664130aab8c1c24071053  evidence/compare-pe.json
ce99cf10143ec0f610bef2b1d433a42a65f53ed138a3b6386444325e59f6d10b  evidence/compare-pe.mjs
748b0e89303dfb70a9d85efe4293210394a6de49af2584b238e443eb6b8484c8  evidence/ExportBfdyld.java
a980a11b682aa6cbc660cdbe190f11dd26be2ea20cdc22104cba8b7b09ca541d  evidence/ghidra-coff.log
444834de0e6961dda420feaddac61a9445ab753f814398e4170529a4da53577e  evidence/validation.json
```
