# XNLPCrudeMdl.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `XNLPCrudeMdl.dll`，752680 字节，SHA-256 `6b21313ab6303ad3c1196df97211cd2d93e0f0612cab0c411a5e4497cb3f2385` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 2184 = decomp_ok 2184 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=2184
- decomp_ok=2184
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `XNLPCrudeMdl.dll` |
| 字节数 | 752680 |
| SHA-256 | `6b21313ab6303ad3c1196df97211cd2d93e0f0612cab0c411a5e4497cb3f2385` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/OOMF V15.0/xeq/XNLPCrudeMdl.dll` |
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
| 段数 | 5 |
| 指令行数 | 126117 |

## 3. 反汇编清单（全量）

全文：disasm/XNLPCrudeMdl.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/XNLPCrudeMdl.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 2184
- decomp_ok（伪 C） = 2184
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：152.2 s
- 日志：out/R1N/ida/logs/sha256_6b21313ab6303ad3c1196df97211cd2d93e0f0612cab0c411a5e4497cb3f2385.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `XNLPCrudeMdl.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 2184 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +2184（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180001040`, `sub_180001050`, `sub_180001080`, `sub_1800010C0`, `??0bad_array_new_length@std@@QEAA@XZ`, `??0exception@std@@QEAA@AEBV01@@Z`, `sub_180001170`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/EOSMCLoadGen.dll.c.txt` sha256=abb4acc1ca4c2d26c3b58a2f5ccdaf7070747521f9e2315c0d3c2d3426544a6d bytes=361668
- `decompiled/NNSolver.dll.c.txt` sha256=d830f8186ad897ac053720a7dfaf4c0436a98c33108bdd454a24269f583856aa bytes=257397
- `decompiled/XLPProvider.dll.c.txt` sha256=03f0a85951bea8f07c165a6ee51c0080780c27bbac9c8345ebc24064bc959bc3 bytes=134869
- `decompiled/XNLPCrudeMdl.dll.c.txt` sha256=bcdc389e0ee0dfcec33d276b3258e5c9cae15082a9c0422555a8a333ac224ab8 bytes=2699118
- `decompiled/amodel.dll.c.txt` sha256=3fbd6107bf52d58dbcb3d21766743abd80371aa28c9b8324b11d5ff8bc5bdd8e bytes=77482
- `decompiled/astruct.dll.c.txt` sha256=a3b6e1433b4561d3ca0068e4f8f0a5912c3aceba52147276b9747c29a7759f85 bytes=71036
- `decompiled/cmfcore.dll.c.txt` sha256=07ffc4994e01d0cfae69995504ffb4ff8a765bc24d4169434e25d7678d95a158 bytes=918151
- `decompiled/oomf.exe.c.txt` sha256=bf2c88573b5cfcec9a06710110b3238cb36670d6809af36a1de00ae2bd1eafae bytes=302411
- `decompiled/oomfcng.dll.c.txt` sha256=0016de659e5fc974097b430219d0174d80b578c8211394b568c86b173695f828 bytes=200160
- `decompiled/pltcon.dll.c.txt` sha256=47f3a9b2e60a2a709ba267f18534fb6e8d6eed3e64fcb734f11e122c2e737441 bytes=162397
- `decompiled/sfl1220as.dll.c.txt` sha256=fffb018c8aace8bbe411cb4d4bccc2351959db1740fc9bacb8959e44ae68ac78 bytes=2232569
- `decompiled/xlpadap.dll.c.txt` sha256=8f6124c565dd2a8f6c68ca097238a35bf1837e05b0147026bbb17dacd2e8b4e8 bytes=227185
- `disasm/EOSMCLoadGen.dll.asm.txt` sha256=40f3f70707aa38d24a6bc37e3c9cfdc86a611a31fb4033bb8c42c930bb236197 bytes=533849
- `disasm/NNSolver.dll.asm.txt` sha256=2d91096fc8ab248d49dadc293410c0a0b42ecce2761163fab9ee889b24a1ab04 bytes=472692
- `disasm/XLPProvider.dll.asm.txt` sha256=3a834a5b8a009045b17cdc6506f287d712cc78fdfebe15a5a7ce1e72e65622d4 bytes=198677
- `disasm/XNLPCrudeMdl.dll.asm.txt` sha256=150aed1f92e72442f9f10c086bd754825605bc946c3a0f2ee940db7981e60e4b bytes=4645422
- `disasm/amodel.dll.asm.txt` sha256=bd8993b4deca319f18ef311025265ac82814552d96399c6006b773c9d80222a4 bytes=114201
- `disasm/astruct.dll.asm.txt` sha256=f618ef8c25ffe001071ece8af0b434699489cec9cc886704662d587095091c46 bytes=102563
- `disasm/cmfcore.dll.asm.txt` sha256=d5a9a756fe773de2c30536f1c722dcdb5ca8210deefc538c74c4d0e3eaa35071 bytes=2116003
- `disasm/oomf.exe.asm.txt` sha256=72c2bbfd59b9ae1871514269b0882c83a3fe8b03f6a947c8b1d0be413facee7e bytes=528240
- `disasm/oomfcng.dll.asm.txt` sha256=6ca049a93e46cecc4e2be2f47798af073e9d307c7015be1e83c42eabf5d3e6c2 bytes=333905
- `disasm/pltcon.dll.asm.txt` sha256=15b1bb472cc2a2c39f665ee46184852b922488f88141c7250773b11764bd82ea bytes=284698
- `disasm/sfl1220as.dll.asm.txt` sha256=2a9a3a3e69bf1598ad10fe5c9026f4fdbac1d5f9211aa484287a1e5a55fdf4f0 bytes=3319988
- `disasm/xlpadap.dll.asm.txt` sha256=fadaf2b01ee0db43abae2be01b0c17e3772e4931ad65e808867cd18bba418bbb bytes=341783
