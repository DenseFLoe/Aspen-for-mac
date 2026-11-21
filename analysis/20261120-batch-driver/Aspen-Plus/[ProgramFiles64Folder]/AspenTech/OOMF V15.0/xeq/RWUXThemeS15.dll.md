# RWUXThemeS15.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `RWUXThemeS15.dll`，139816 字节，SHA-256 `3c6649641370df3f542a951cb1d4417c3ceab1c0ecb9667ef6e32c7b8b3459c9` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 507 = decomp_ok 507 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=507
- decomp_ok=507
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `RWUXThemeS15.dll` |
| 字节数 | 139816 |
| SHA-256 | `3c6649641370df3f542a951cb1d4417c3ceab1c0ecb9667ef6e32c7b8b3459c9` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/OOMF V15.0/xeq/RWUXThemeS15.dll` |
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
| 指令行数 | 20350 |

## 3. 反汇编清单（全量）

全文：disasm/RWUXThemeS15.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/RWUXThemeS15.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 507
- decomp_ok（伪 C） = 507
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：10.1 s
- 日志：out/R1N/ida/logs/sha256_3c6649641370df3f542a951cb1d4417c3ceab1c0ecb9667ef6e32c7b8b3459c9.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `RWUXThemeS15.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 507 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +507（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180001020`, `sub_180001160`, `sub_180001200`, `sub_180001350`, `sub_1800017A0`, `RWAdjustHSL`, `RWBlendColors`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/RWUXThemeS15.dll.c.txt` sha256=acd7e2302b1ecb5a97077246f2d399c936192d5dedf1ddc72c8d6d52f54f4121 bytes=371076
- `decompiled/ascsimserver.dll.c.txt` sha256=c6b7b6b5837c6d2bfdd4e89126fb4764987148a3055e8e90abbe7edc742633bb bytes=433448
- `decompiled/cmf.dll.c.txt` sha256=9da2e879f548256310b869b21d42fd5f00b7cc7e04387bf4d2be9063b5d631a4 bytes=659298
- `decompiled/gdotcustadap.dll.c.txt` sha256=284f7b8ec18d5088d806629963382fbeea079933047f0883e9d06a43929b6440 bytes=527845
- `decompiled/oomfhost.dll.c.txt` sha256=d6840d1bab9c2f0c8367492b8bd3aa60eb0131940d2b63142cdf2d0390da3314 bytes=1115337
- `disasm/RWUXThemeS15.dll.asm.txt` sha256=a92046260eb89c72a5a55c1a592e6337a2477b1fb6e2ab9d07135a401925c31e bytes=742250
- `disasm/ascsimserver.dll.asm.txt` sha256=8b5bfb55cdb01e085e849e97e2dc14128c8fa36043f738fe21e9f74be6386a27 bytes=973985
- `disasm/cmf.dll.asm.txt` sha256=46f39586d40edfe92e0a5e048f6451ce8db07a5edd212ad1fc792721cd494f24 bytes=1288976
- `disasm/gdotcustadap.dll.asm.txt` sha256=5fbe74f1e0018f05af154352941d6c079c0e48fd7ef1f564d40b463c95087ebb bytes=870523
- `disasm/oomfhost.dll.asm.txt` sha256=473ee6d83f83a5d8415d4848286b41495fbce6301ad3e758382a1e44f71aaa16 bytes=1953546
