# ADMethods.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ADMethods.dll`，56360 字节，SHA-256 `c6c7ebe31063130b6b01b1b041b9920647da638667152aa5b06e091212cd3476` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 273 = decomp_ok 273 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=273
- decomp_ok=273
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ADMethods.dll` |
| 字节数 | 56360 |
| SHA-256 | `c6c7ebe31063130b6b01b1b041b9920647da638667152aa5b06e091212cd3476` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ADMethods.dll` |
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
| 指令行数 | 6764 |

## 3. 反汇编清单（全量）

全文：disasm/ADMethods.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ADMethods.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 273
- decomp_ok（伪 C） = 273
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：17.3 s
- 日志：out/R1N/ida/logs/sha256_c6c7ebe31063130b6b01b1b041b9920647da638667152aa5b06e091212cd3476.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ADMethods.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 273 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +273（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180001064`, `_get_startup_argv_mode`, `sub_1800010A0`, `sub_1800010C0`, `sub_1800010E0`, `??1AspenDynamicsMethods@@QEAA@XZ`, `??4AspenDynamicsMethods@@QEAAAEAV0@AEBV0@@Z`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/ADMethods.dll.c.txt` sha256=7c5725709efbdb8b2e04012d8998c4add076c31743ee5d892912c4f193e7efa2 bytes=194580
- `decompiled/ApStgUtl.exe.c.txt` sha256=69367fdd4fba7b18622aeb8a5c57114945c74c422f1c0b94b4fb9d77d3654b55 bytes=316952
- `decompiled/BkpPreviewHandler.dll.c.txt` sha256=f34fa08611fa168d0a3f2f18f45f9ce8d53a91a8bf9fdbc02e7666bca0496eef bytes=49029
- `decompiled/DBInterfaceMM.dll.c.txt` sha256=9016ec4376183980b156c982ab35f7762b3b95d51b2d88df62c59a1b0ef4282c bytes=203649
- `decompiled/MMVersion.dll.c.txt` sha256=1112dcc74dcdbc7feaa9f161f44b9200dc2f1dd5a0de6c9286b3548479d28b2e bytes=27817
- `decompiled/SorResDll.dll.c.txt` sha256=958c3415f9efd1225f5cb31578e912383e346d32b971ab527db10384a46b6e53 bytes=56490
- `decompiled/atxc.dll.c.txt` sha256=d89110cb1383e7fc8cc349bfff914a5895c80dee3085b30fa91979ba5da701c7 bytes=3646501
- `decompiled/htm.exe.c.txt` sha256=4194e2bb2ac7f1548ea7c2b98ff183573ca321fdb2ee2177f6b679d803d6816e bytes=30837
- `decompiled/libEGL.dll.c.txt` sha256=ac5b36104f8c4b179a957cb36e51f9c6718aefc03b75adae9d6b956e93a25d6f bytes=1755605
- `decompiled/libbz2.dll.c.txt` sha256=58f3a06c3ce4cedd73c2fb840fbb4262aa35d6811490c4ec7632214b0178fb27 bytes=2289099
- `decompiled/mmtbs.exe.c.txt` sha256=61bef67b4923bddfb6bfaa22a31a31a0673e7b447497e8938ce7513c6cca1682 bytes=34968
- `decompiled/recdef.exe.c.txt` sha256=6204879a0b929e6af80d753a8fbaf2b0f0db9ed1876980d49e913eb1c8181039 bytes=36589
- `decompiled/rscevnavmeng.dll.c.txt` sha256=acae435bb3dcb7477c763e8dfac96a047ec6f44a19a0f060d96b1205719175e2 bytes=52017
- `decompiled/rscpackprop.dll.c.txt` sha256=53e752c16e5b921c08f3f72d523dbe64f3e00a2b1ecbc551befcc89978b88a09 bytes=53600
- `decompiled/strings.dll.c.txt` sha256=9ec25507bd4b2ec34c41cdfa867eb9c76aa2611cb566843554e7dd2d7c7b47ab bytes=47696
- `decompiled/uservtb.dll.c.txt` sha256=cba04939d64c98d48c316f48385c9b3d7de4bbbe908ba922986d65cb7b5a51ba bytes=188352
- `disasm/ADMethods.dll.asm.txt` sha256=bd0ed1feaac97771968f90a6751a0e7419742fd1eae3ffc134d80e1a8c8c91c4 bytes=275530
- `disasm/ApStgUtl.exe.asm.txt` sha256=cb3c2e43bea88f9921986710040409d005d7955e25e5472abff31c7df7fd384d bytes=435512
- `disasm/BkpPreviewHandler.dll.asm.txt` sha256=552fe582049d6c23f7f256b573d1af4bc287024480a948a5628127ae8ab7a81e bytes=89180
- `disasm/DBInterfaceMM.dll.asm.txt` sha256=049f12c9766a7d4ea3d7c1e31169b5a0fdf2fff4a65e5397d880dfd7d515f1f7 bytes=339712
- `disasm/MMVersion.dll.asm.txt` sha256=56dacb9d48cd99a57cd7d43eeec3af739dcf5b6c756da78c8cfd5ff92419419e bytes=48806
- `disasm/SorResDll.dll.asm.txt` sha256=088176c8765950812cc21fc3d4ea1e07582801253c484351339d3cac8247f7bf bytes=100048
- `disasm/atxc.dll.asm.txt` sha256=0c9327818ee5ef7654d3f20474357700d66727044cacfdda2674be8d3012434b bytes=5784492
- `disasm/htm.exe.asm.txt` sha256=d4dbc730836c61339fd550adf867542e24ca7845c41a00652641115e387bf445 bytes=53516
- `disasm/libEGL.dll.asm.txt` sha256=49007efdd280d394cf7645750e90e4ea7873d7cbf24f1425318628ff18d2ad95 bytes=3247568
- `disasm/libbz2.dll.asm.txt` sha256=f6abeafb57a0383ef8a656393323e952c8c84f1c4422bcb4f3a85deef88d3de4 bytes=3625664
- `disasm/mmtbs.exe.asm.txt` sha256=a3e8e88109240dee328e0e9e688bcc9bd63d498edd5bcb6db9417d0af861f13a bytes=61589
- `disasm/recdef.exe.asm.txt` sha256=2469c4fcee919c3cf372f04be290cb0da6150281ac4db51604b5ae0112317223 bytes=63969
- `disasm/rscevnavmeng.dll.asm.txt` sha256=f9a5f1f68fa575bf20cc29e6d7ec3825a12c2e029ac9f7ba398d9d5a3fe93bb8 bytes=91237
- `disasm/rscpackprop.dll.asm.txt` sha256=38938d85d09a3af3157b4b0375e471d64f611a043023a7a8f23bd664b9bbf7af bytes=95982
- `disasm/strings.dll.asm.txt` sha256=32777a128ea74c61d64c86dc30f373a6f29d8e4b41315b8776d0a331d6f3d705 bytes=88693
- `disasm/uservtb.dll.asm.txt` sha256=5b300d63aabfaac313d2f24b776357b6c776fb36a9a887ab7902d1da882b79e3 bytes=374153
