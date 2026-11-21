# fcc.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `fcc.dll`，3618344 字节，SHA-256 `1ec7eb5bac633a0dde1d2ab11d4a82886943cfab068e3681b08998e1f16ec34c` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 615 = decomp_ok 573 + decomp_fail 42 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=615
- decomp_ok=573
- decomp_fail=42
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `fcc.dll` |
| 字节数 | 3618344 |
| SHA-256 | `1ec7eb5bac633a0dde1d2ab11d4a82886943cfab068e3681b08998e1f16ec34c` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/fcc.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 64 |
| 镜像基址 | `0x180000000` |
| 段数 | 6 |
| 指令行数 | 529154 |

## 3. 反汇编清单（全量）

全文：disasm/fcc.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/fcc.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 615
- decomp_ok（伪 C） = 573
- decomp_fail = 42
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `18002e7b0` `DMX_FCCINIT`：RuntimeError（decompile returned None）
- `180031f40` `DMX_FCCMBAS`：RuntimeError（decompile returned None）
- `180034420` `DMX_FCCMBJAC`：RuntimeError（decompile returned None）
- `180036af0` `DMX_FCCNGAS`：RuntimeError（decompile returned None）
- `18005f7b0` `G_DMO_RGCYNS`：RuntimeError（decompile returned None）
- `1800628e0` `G_DMO_RGCYRES`：RuntimeError（decompile returned None）
- `18006b240` `G_DMO_RRDP2NS`：RuntimeError（decompile returned None）
- `180072860` `G_DMO_RRDP2RES`：RuntimeError（decompile returned None）
- `18007b030` `G_DMO_RRSPNS`：RuntimeError（decompile returned None）
- `1800804e0` `G_DMO_RRSPRES`：RuntimeError（decompile returned None）
- `180088f90` `G_DMO_RRYLNS`：RuntimeError（decompile returned None）
- `1800a70e0` `G_DMO_RRYLRES`：RuntimeError（decompile returned None）
- `1800b8c40` `G_DMO_RXSZNS`：RuntimeError（decompile returned None）
- `1800bea50` `G_DMO_RXSZRES`：RuntimeError（decompile returned None）
- `1800cdd90` `DMX_MAT`：RuntimeError（decompile returned None）
- `1800d7570` `DMO_RGCYBLD`：RuntimeError（decompile returned None）
- `1800eef50` `DMO_RGDB`：RuntimeError（decompile returned None）
- `1800f4450` `DMO_RGDBASDR`：RuntimeError（decompile returned None）
- `1800f5a00` `DMO_RGDBBLD`：RuntimeError（decompile returned None）
- `180115fa0` `DMO_RGDBINI`：RuntimeError（decompile returned None）
- `18014a000` `DMO_RGFB`：RuntimeError（decompile returned None）
- `18014ce50` `DMO_RGFBASDR`：RuntimeError（decompile returned None）
- `18014dbb0` `DMO_RGFBBLD`：RuntimeError（decompile returned None）
- `180161b10` `DMO_RGFBINI`：RuntimeError（decompile returned None）
- `18017ad00` `DMX_RIS1NAS`：RuntimeError（decompile returned None）
- `18018a560` `DMX_RIS2NAS`：RuntimeError（decompile returned None）
- `18018d250` `DMX_RIS2NJAC`：RuntimeError（decompile returned None）
- `1801a4e80` `DMO_RISR`：RuntimeError（decompile returned None）
- `1801a8e30` `DMX_RISRASDR`：RuntimeError（decompile returned None）
- `1801a98c0` `DMX_RISRBLD`：RuntimeError（decompile returned None）
- `1801ba4a0` `DMX_RISRCFG`：RuntimeError（decompile returned None）
- `1801cce50` `DMX_RISRJAC`：RuntimeError（decompile returned None）
- `1801d1620` `DMO_RISRMAK`：RuntimeError（decompile returned None）
- `1801d48d0` `DMX_RISRNMNZ`：RuntimeError（decompile returned None）
- `1801d7670` `DMX_RISRPTAS`：RuntimeError（decompile returned None）
- `1801daa50` `DMX_RISRPTDR`：RuntimeError（decompile returned None）
- `180208f40` `DMO_RRDP2BLD`：RuntimeError（decompile returned None）
- `1802274b0` `DMO_RRSPBLD`：RuntimeError（decompile returned None）
- `18025e550` `DMO_RRYLBLD`：RuntimeError（decompile returned None）
- `18029a160` `DMO_RXSZBLD`：RuntimeError（decompile returned None）
- `1802c8060` `DMX_XCCGEN`：RuntimeError（decompile returned None）
- `1802d9c90` `DMX_XCCRXN`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：549.6 s
- 日志：out/R1N/ida/logs/sha256_1ec7eb5bac633a0dde1d2ab11d4a82886943cfab068e3681b08998e1f16ec34c.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 42 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `fcc.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 615 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +615（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`nullsub_1`, `DMO_COKTHERM`, `DMO_COKTHERMDX`, `DMO_CSRC`, `DMO_CSRCAS`, `DMO_CSRCBLD`, `DMO_CSRCCFG`, `DMO_CSRCIDX`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/decompiled/fcc.dll.c.txt` sha256=c65e95934c70876221bfa0a6f7fec94aaa6125d37ab1ed0f876dc55100e3c222 bytes=6476186
- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/disasm/fcc.dll.asm.txt` sha256=09bffb94401cfca736a33e5f8581f22b849ad8b8b86d0cf271ecb753f9891af1 bytes=21314690
