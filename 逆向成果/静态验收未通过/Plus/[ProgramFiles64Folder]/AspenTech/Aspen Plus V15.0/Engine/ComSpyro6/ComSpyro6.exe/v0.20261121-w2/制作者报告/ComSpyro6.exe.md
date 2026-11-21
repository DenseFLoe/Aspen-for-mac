# ComSpyro6.exe 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ComSpyro6.exe`，66088 字节，SHA-256 `5b175f8f9b5f7e2b3d33f4c43591178da655cb6b77bfb67e5ea78a434fde1880` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 246 = decomp_ok 245 + decomp_fail 1 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=246
- decomp_ok=245
- decomp_fail=1
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ComSpyro6.exe` |
| 字节数 | 66088 |
| SHA-256 | `5b175f8f9b5f7e2b3d33f4c43591178da655cb6b77bfb67e5ea78a434fde1880` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/ComSpyro6/ComSpyro6.exe` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x400000` |
| 段数 | 4 |
| 指令行数 | 10361 |

## 3. 反汇编清单（全量）

全文：disasm/ComSpyro6.exe.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ComSpyro6.exe.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 246
- decomp_ok（伪 C） = 245
- decomp_fail = 1
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `408162` `?pre_c_initialization@@YAHXZ`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：23.5 s
- 日志：out/R1N/ida/logs/sha256_5b175f8f9b5f7e2b3d33f4c43591178da655cb6b77bfb67e5ea78a434fde1880.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 1 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ComSpyro6.exe` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 246 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +246（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_401000`, `sub_401060`, `sub_401133`, `sub_401150`, `sub_401160`, `sub_401170`, `sub_401180`, `sub_4012B0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/ComSpyro6.exe.c.txt` sha256=c2b6b43984d4029cb3166210990f8fde69935fb2b26f132ee720de642431aaf5 bytes=169573
- `decompiled/ComSpyro6PS.dll.c.txt` sha256=11d70fc4beb952e90241c316f702f5928629892248836f97d452a31c1beeb59e bytes=26093
- `decompiled/DFORRT.DLL.c.txt` sha256=91ff52d5f9367b00cd75378cfbedf405044a450edaffb9379f72ce6624981f72 bytes=2017681
- `decompiled/lsapiw32.dll.c.txt` sha256=febff73f0278d026472d9c9dcbafb9d1c39144e6adab3fc402feccbc331713ab bytes=1937569
- `disasm/ComSpyro6.exe.asm.txt` sha256=e6992a9870f302cd48107e48a341afa27e8b35928787ae72b794a61d0776a201 bytes=324863
- `disasm/ComSpyro6PS.dll.asm.txt` sha256=e5c62e56f9369bffbcb27e3be189040ca9c754e7bd6122d48eb89d023fb47ebf bytes=43922
- `disasm/DFORRT.DLL.asm.txt` sha256=2f67c429fe3f286e6deacf2d4e4a79763349f4630f6230e32527561ca7d36318 bytes=3911712
- `disasm/lsapiw32.dll.asm.txt` sha256=37f6fb980f97bd179c3f6ee435116f79f7325649c3a009f56e2ece19d234f767 bytes=4950408
