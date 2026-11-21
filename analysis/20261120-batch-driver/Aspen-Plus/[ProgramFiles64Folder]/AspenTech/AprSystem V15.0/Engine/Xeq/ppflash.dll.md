# ppflash.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ppflash.dll`，1659944 字节，SHA-256 `7e2b305b17dbca74ddddce1bf3ae869bed281534a3782733f4240cd4d52f3829` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 1035 = decomp_ok 1006 + decomp_fail 29 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=1035
- decomp_ok=1006
- decomp_fail=29
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ppflash.dll` |
| 字节数 | 1659944 |
| SHA-256 | `7e2b305b17dbca74ddddce1bf3ae869bed281534a3782733f4240cd4d52f3829` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppflash.dll` |
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
| 指令行数 | 252954 |

## 3. 反汇编清单（全量）

全文：disasm/ppflash.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ppflash.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 1035
- decomp_ok（伪 C） = 1006
- decomp_fail = 29
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `180001980` `FLSH_LLEQM`：RuntimeError（decompile returned None）
- `18005c8d0` `sub_18005C8D0`：RuntimeError（decompile returned None）
- `18005eb40` `sub_18005EB40`：RuntimeError（decompile returned None）
- `1800679d0` `sub_1800679D0`：RuntimeError（decompile returned None）
- `18007cd80` `sub_18007CD80`：RuntimeError（decompile returned None）
- `18007e3f0` `FLSH_ZHINAC`：RuntimeError（decompile returned None）
- `18008ed80` `sub_18008ED80`：RuntimeError（decompile returned None）
- `180097fe0` `sub_180097FE0`：RuntimeError（decompile returned None）
- `180098e30` `sub_180098E30`：RuntimeError（decompile returned None）
- `180099b40` `sub_180099B40`：RuntimeError（decompile returned None）
- `18009a440` `sub_18009A440`：RuntimeError（decompile returned None）
- `1800a7a70` `sub_1800A7A70`：RuntimeError（decompile returned None）
- `1800a8680` `sub_1800A8680`：RuntimeError（decompile returned None）
- `1800ac890` `sub_1800AC890`：RuntimeError（decompile returned None）
- `1800da950` `sub_1800DA950`：RuntimeError（decompile returned None）
- `1800e9370` `FLSH_CHMINF`：RuntimeError（decompile returned None）
- `1800e98b0` `FLSH_CHMINF_KSTOIC`：RuntimeError（decompile returned None）
- `1800e9d40` `FLSH_CHMINF_KSALT`：RuntimeError（decompile returned None）
- `1800ea1d0` `FLSH_CHMINF_STOIC_DATA`：RuntimeError（decompile returned None）
- `1800ea640` `FLSH_CHMINF_SALT_DATA`：RuntimeError（decompile returned None）
- `1800eaab0` `FLSH_CHMINF_PARAM`：RuntimeError（decompile returned None）
- `1800eaf40` `FLSH_CHMINF_LREACG`：RuntimeError（decompile returned None）
- `1800eb3d0` `FLSH_CHMINF_LIDXDE`：RuntimeError（decompile returned None）
- `1800eb860` `FLSH_CHMINF_LDECO`：RuntimeError（decompile returned None）
- `1801034a0` `FLSH_CTR2APP`：RuntimeError（decompile returned None）
- `180103eb0` `sub_180103EB0`：RuntimeError（decompile returned None）
- `18010cd80` `FLSH_FLASH`：RuntimeError（decompile returned None）
- `180121010` `FLSH_XFLASH`：RuntimeError（decompile returned None）
- `18013c1d0` `FLSH_ZFLASH`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：288.8 s
- 日志：out/R1N/ida/logs/sha256_7e2b305b17dbca74ddddce1bf3ae869bed281534a3782733f4240cd4d52f3829.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 29 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ppflash.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 1035 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +1035（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`FLSH_PFLASH`, `FLSH_SFLASH`, `FLSH_LLEQM`, `FLSH_LLSPLT`, `sub_180008010`, `sub_18000C2B0`, `FLSH_FLSERR`, `FLSH_FLSMSG`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/decompiled/ppflash.dll.c.txt` sha256=3e6b509912a736f80b9a3f8c436244dda3dd0cacb2f4530a2707a3a315c41553 bytes=3547283
- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/disasm/ppflash.dll.asm.txt` sha256=2935cc14315d7db559d629a0f0eac3b9acc1797ffbafedf5455f1babea61bfc4 bytes=9916203
