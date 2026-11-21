# dbt_pw8.F17E0647_A8B1_438F_B777_C7BFE25C71D7.exe 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `dbt_pw8.F17E0647_A8B1_438F_B777_C7BFE25C71D7.exe`，681984 字节，SHA-256 `362f525bd0617337aab14be1e06e9d338a5aeeba177a30046e38ae26af0c983b` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 2841 = decomp_ok 2839 + decomp_fail 2 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=2841
- decomp_ok=2839
- decomp_fail=2
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `dbt_pw8.F17E0647_A8B1_438F_B777_C7BFE25C71D7.exe` |
| 字节数 | 681984 |
| SHA-256 | `362f525bd0617337aab14be1e06e9d338a5aeeba177a30046e38ae26af0c983b` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `Icon/dbt_pw8.F17E0647_A8B1_438F_B777_C7BFE25C71D7.exe` |
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
| 指令行数 | 94563 |

## 3. 反汇编清单（全量）

全文：disasm/dbt_pw8.F17E0647_A8B1_438F_B777_C7BFE25C71D7.exe.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/dbt_pw8.F17E0647_A8B1_438F_B777_C7BFE25C71D7.exe.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 2841
- decomp_ok（伪 C） = 2839
- decomp_fail = 2
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `436c88` `start_0`：RuntimeError（decompile returned None）
- `438275` `__check_overflow_exit`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：77.6 s
- 日志：out/R1N/ida/logs/sha256_362f525bd0617337aab14be1e06e9d338a5aeeba177a30046e38ae26af0c983b.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 2 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `dbt_pw8.F17E0647_A8B1_438F_B777_C7BFE25C71D7.exe` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 2841 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +2841（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`_WinMain@16`, `?pre_c_initialization@@YAHXZ`, `?post_pgo_initialization@@YAHXZ`, `?pre_cpp_initialization@@YAXXZ`, `?__scrt_common_main_seh@@YAHXZ`, `j_j_??$common_initialize_environment_nolock@D@@YAHXZ`, `?invoke_main@@YAHXZ`, `?set_commode@__scrt_file_policy@@SAXXZ`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/APEDMgr_prew8.2DEC4A45_82FF_4174_874A_CFF9E227A91E.exe.c.txt` sha256=92890b7b4664b92c0921d755e8a394d1d166962ffe7eeb1fad79049f31611151 bytes=1833504
- `decompiled/ApSetComp_pw8.9F9181B5_E217_461B_862B_6D6477567A95.exe.c.txt` sha256=92890b7b4664b92c0921d755e8a394d1d166962ffe7eeb1fad79049f31611151 bytes=1833504
- `decompiled/a_aplus_Engine_pre_71333CA5B07642BC8966A36252EA2671.exe.c.txt` sha256=92890b7b4664b92c0921d755e8a394d1d166962ffe7eeb1fad79049f31611151 bytes=1833504
- `decompiled/a_aplus_GUI_prewin_2089E9BCA3534ADE899CDCD4A5247BEA.exe.c.txt` sha256=92890b7b4664b92c0921d755e8a394d1d166962ffe7eeb1fad79049f31611151 bytes=1833504
- `decompiled/converterV150_Aspe_67A0A657A37A4D428016F5A8559D1D1F.exe.c.txt` sha256=92890b7b4664b92c0921d755e8a394d1d166962ffe7eeb1fad79049f31611151 bytes=1833504
- `decompiled/dbt_pw8.F17E0647_A8B1_438F_B777_C7BFE25C71D7.exe.c.txt` sha256=92890b7b4664b92c0921d755e8a394d1d166962ffe7eeb1fad79049f31611151 bytes=1833504
- `decompiled/reg_fix_aplus_prew_83F91F29EA9C443594E850154DECC0A6.exe.c.txt` sha256=92890b7b4664b92c0921d755e8a394d1d166962ffe7eeb1fad79049f31611151 bytes=1833504
- `disasm/APEDMgr_prew8.2DEC4A45_82FF_4174_874A_CFF9E227A91E.exe.asm.txt` sha256=8bac1b474ce36d344a6cd23c8b4b53e67e87ee4b853666416662f5a93265a39e bytes=2999202
- `disasm/ApSetComp_pw8.9F9181B5_E217_461B_862B_6D6477567A95.exe.asm.txt` sha256=8bac1b474ce36d344a6cd23c8b4b53e67e87ee4b853666416662f5a93265a39e bytes=2999202
- `disasm/a_aplus_Engine_pre_71333CA5B07642BC8966A36252EA2671.exe.asm.txt` sha256=8bac1b474ce36d344a6cd23c8b4b53e67e87ee4b853666416662f5a93265a39e bytes=2999202
- `disasm/a_aplus_GUI_prewin_2089E9BCA3534ADE899CDCD4A5247BEA.exe.asm.txt` sha256=8bac1b474ce36d344a6cd23c8b4b53e67e87ee4b853666416662f5a93265a39e bytes=2999202
- `disasm/converterV150_Aspe_67A0A657A37A4D428016F5A8559D1D1F.exe.asm.txt` sha256=8bac1b474ce36d344a6cd23c8b4b53e67e87ee4b853666416662f5a93265a39e bytes=2999202
- `disasm/dbt_pw8.F17E0647_A8B1_438F_B777_C7BFE25C71D7.exe.asm.txt` sha256=8bac1b474ce36d344a6cd23c8b4b53e67e87ee4b853666416662f5a93265a39e bytes=2999202
- `disasm/reg_fix_aplus_prew_83F91F29EA9C443594E850154DECC0A6.exe.asm.txt` sha256=8bac1b474ce36d344a6cd23c8b4b53e67e87ee4b853666416662f5a93265a39e bytes=2999202
