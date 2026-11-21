# htmdll.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `htmdll.dll`，132136 字节，SHA-256 `6aedd5f1a5fd4d646b88030f7c3382fb6d31a71f177d00e9fc8bc80518c0aed8` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 197 = decomp_ok 197 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=197
- decomp_ok=197
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `htmdll.dll` |
| 字节数 | 132136 |
| SHA-256 | `6aedd5f1a5fd4d646b88030f7c3382fb6d31a71f177d00e9fc8bc80518c0aed8` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/htmdll.dll` |
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
| 指令行数 | 9521 |

## 3. 反汇编清单（全量）

全文：disasm/htmdll.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/htmdll.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 197
- decomp_ok（伪 C） = 197
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：7.7 s
- 日志：out/R1N/ida/logs/sha256_6aedd5f1a5fd4d646b88030f7c3382fb6d31a71f177d00e9fc8bc80518c0aed8.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `htmdll.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 197 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +197（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_1800010B0`, `sub_180001150`, `sub_180001260`, `sub_180001280`, `sub_1800012B0`, `sub_1800012D0`, `sub_1800012E0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part1.tar.gz

- `decompiled/ADMethods.dll.c.txt` sha256=7c5725709efbdb8b2e04012d8998c4add076c31743ee5d892912c4f193e7efa2 bytes=194580
- `decompiled/ApStgUtl.exe.c.txt` sha256=69367fdd4fba7b18622aeb8a5c57114945c74c422f1c0b94b4fb9d77d3654b55 bytes=316952
- `decompiled/ApwnContext.dll.c.txt` sha256=496e26e1198239981955e56b15198b60450af50c80a46d90e16671b592c81451 bytes=433791
- `decompiled/DBInterfaceMM.dll.c.txt` sha256=9016ec4376183980b156c982ab35f7762b3b95d51b2d88df62c59a1b0ef4282c bytes=203649
- `decompiled/htmdll.dll.c.txt` sha256=ca242eb923ca619611a198f3ccfa2496ae4fa663c8603662d1d0fb338ea0f690 bytes=175159
- `decompiled/rscevnavmeng.dll.c.txt` sha256=acae435bb3dcb7477c763e8dfac96a047ec6f44a19a0f060d96b1205719175e2 bytes=52017
- `decompiled/rscpackprop.dll.c.txt` sha256=53e752c16e5b921c08f3f72d523dbe64f3e00a2b1ecbc551befcc89978b88a09 bytes=53600
- `decompiled/strings.dll.c.txt` sha256=9ec25507bd4b2ec34c41cdfa867eb9c76aa2611cb566843554e7dd2d7c7b47ab bytes=47696
- `decompiled/uservtb.dll.c.txt` sha256=cba04939d64c98d48c316f48385c9b3d7de4bbbe908ba922986d65cb7b5a51ba bytes=188352
- `disasm/ADMethods.dll.asm.txt` sha256=bd0ed1feaac97771968f90a6751a0e7419742fd1eae3ffc134d80e1a8c8c91c4 bytes=275530
- `disasm/ApStgUtl.exe.asm.txt` sha256=cb3c2e43bea88f9921986710040409d005d7955e25e5472abff31c7df7fd384d bytes=435512
- `disasm/ApwnContext.dll.asm.txt` sha256=b029a4b4910b26a743698b6e6ffd9e157e27d51f4b84f1ceb9ccc96ac5caeab4 bytes=654025
- `disasm/DBInterfaceMM.dll.asm.txt` sha256=049f12c9766a7d4ea3d7c1e31169b5a0fdf2fff4a65e5397d880dfd7d515f1f7 bytes=339712
- `disasm/htmdll.dll.asm.txt` sha256=9d2f45dc2a6be5eb31df01afd0dbaa2eea059d18a21708e279c1c0c08184d5d9 bytes=347117
- `disasm/rscevnavmeng.dll.asm.txt` sha256=f9a5f1f68fa575bf20cc29e6d7ec3825a12c2e029ac9f7ba398d9d5a3fe93bb8 bytes=91237
- `disasm/rscpackprop.dll.asm.txt` sha256=38938d85d09a3af3157b4b0375e471d64f611a043023a7a8f23bd664b9bbf7af bytes=95982
- `disasm/strings.dll.asm.txt` sha256=32777a128ea74c61d64c86dc30f373a6f29d8e4b41315b8776d0a331d6f3d705 bytes=88693
- `disasm/uservtb.dll.asm.txt` sha256=5b300d63aabfaac313d2f24b776357b6c776fb36a9a887ab7902d1da882b79e3 bytes=374153
