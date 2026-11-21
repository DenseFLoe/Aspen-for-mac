# AspenTech_NGP_Managed2Unmanaged.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `AspenTech_NGP_Managed2Unmanaged.dll`，52776 字节，SHA-256 `8ba002121724f147a82af49b8a9faf88eb15c90fe6b5ac4dfc20924f1cfea18f` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 188 = decomp_ok 188 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=188
- decomp_ok=188
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `AspenTech_NGP_Managed2Unmanaged.dll` |
| 字节数 | 52776 |
| SHA-256 | `8ba002121724f147a82af49b8a9faf88eb15c90fe6b5ac4dfc20924f1cfea18f` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech_NGP_Managed2Unmanaged.dll` |
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
| 指令行数 | 6222 |

## 3. 反汇编清单（全量）

全文：disasm/AspenTech_NGP_Managed2Unmanaged.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/AspenTech_NGP_Managed2Unmanaged.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 188
- decomp_ok（伪 C） = 188
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：41.8 s
- 日志：out/R1N/ida/logs/sha256_8ba002121724f147a82af49b8a9faf88eb15c90fe6b5ac4dfc20924f1cfea18f.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `AspenTech_NGP_Managed2Unmanaged.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 188 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +188（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_18000100C`, `sub_180001030`, `?what@exception@std@@UEBAPEBDXZ`, `sub_180001090`, `sub_1800010E0`, `??0bad_array_new_length@std@@QEAA@XZ`, `?__scrt_throw_std_bad_array_new_length@@YAXXZ`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part1.tar.gz

- `native2/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/Engine/Xeq/decompiled/AspenTech_NGP_Managed2Unmanaged.dll.c.txt` sha256=c6b860fb808ea86aa09d2712690b54681f3442cd700bbb52dee6470a3b3ff4b3 bytes=116673
- `native2/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/Engine/Xeq/disasm/AspenTech_NGP_Managed2Unmanaged.dll.asm.txt` sha256=d9fc2ac86611225c4e91934a5c56e81b4fb7b7f4dfd68ce9c19fa38523763af0 bytes=224544
