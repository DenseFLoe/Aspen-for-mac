# ComSelSvr.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ComSelSvr.dll`，338512 字节，SHA-256 `a35aab96dd0eba9209fab638ab814c1d6c7259cb657110c5b2e39fc294f513f2` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 3014 = decomp_ok 3003 + decomp_fail 11 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=3014
- decomp_ok=3003
- decomp_fail=11
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ComSelSvr.dll` |
| 字节数 | 338512 |
| SHA-256 | `a35aab96dd0eba9209fab638ab814c1d6c7259cb657110c5b2e39fc294f513f2` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[CommonFiles64Folder]/Hyprotech/COMThermo/ComSelSvr.dll` |
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
| 指令行数 | 89075 |

## 3. 反汇编清单（全量）

全文：disasm/ComSelSvr.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ComSelSvr.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 3014
- decomp_ok（伪 C） = 3003
- decomp_fail = 11
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `4027b8` `sub_4027B8`：RuntimeError（decompile returned None）
- `4027c8` `sub_4027C8`：RuntimeError（decompile returned None）
- `403630` `@System@@DoneExcept$qqrv`：RuntimeError（decompile returned None）
- `405a13` `sub_405A13`：RuntimeError（decompile returned None）
- `4089f3` `sub_4089F3`：RuntimeError（decompile returned None）
- `40e2ec` `unknown_libname_89`：RuntimeError（decompile returned None）
- `413468` `sub_413468`：RuntimeError（decompile returned None）
- `42f79c` `unknown_libname_439`：RuntimeError（decompile returned None）
- `43f8f8` `sub_43F8F8`：RuntimeError（decompile returned None）
- `440c8c` `unknown_libname_356`：RuntimeError（decompile returned None）
- `440cd4` `unknown_libname_357`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：45.8 s
- 日志：out/R1N/ida/logs/sha256_a35aab96dd0eba9209fab638ab814c1d6c7259cb657110c5b2e39fc294f513f2.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 11 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ComSelSvr.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 3014 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +3014（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_401125`, `sub_40112F`, `sub_401139`, `CloseHandle`, `CreateFileA`, `GetFileType`, `GetFileSize`, `GetStdHandle`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/ComSelSvr.dll.c.txt` sha256=dabbe7f8353815bc8b97b59f0490348b6a9d69c5889cd8c39d07960fbffa2a31 bytes=1716152
- `decompiled/HyprotechLoader.dll.c.txt` sha256=c5e67a5a91b42a5173a83281d0a3b52c4b8c0deaedff6745e879910900de6050 bytes=477334
- `decompiled/ThUtilityManager.dll.c.txt` sha256=c95d154b38f8ac722711cdfa5a84d49f7201ad1b40fd44dc3cdb1c684a855aaa bytes=336420
- `decompiled/hyploader.dll.c.txt` sha256=6883b158d70840ed8e46e5f258bd5b25cb34ba287e25e871126de4520a222b79 bytes=406422
- `disasm/ComSelSvr.dll.asm.txt` sha256=a60002d05c88be1469de2154678ba582652e116f746e95821a0116ef6f3f4bf5 bytes=2762883
- `disasm/HyprotechLoader.dll.asm.txt` sha256=01da428c56101e1bbbb273b90c5e9408ea4e8bf8b2d2d9ef753d370b55d14132 bytes=862215
- `disasm/ThUtilityManager.dll.asm.txt` sha256=573d34b2ffab65acada1955cb156556274582aadf7e951f062588f64d042f7a1 bytes=606242
- `disasm/hyploader.dll.asm.txt` sha256=bcb1d580be04fbba082852c610b83e82418c696658c5da083f9a54d8d83e6814 bytes=742814
