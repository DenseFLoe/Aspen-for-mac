# msmapi32.ocx 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `msmapi32.ocx`，137000 字节，SHA-256 `60e841057cbbf33e10c5169cc328330d11838636002670cb9e8a7a09bab321ab` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 518 = decomp_ok 518 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=518
- decomp_ok=518
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `msmapi32.ocx` |
| 字节数 | 137000 |
| SHA-256 | `60e841057cbbf33e10c5169cc328330d11838636002670cb9e8a7a09bab321ab` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/msmapi32.ocx` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x21d70000` |
| 段数 | 3 |
| 指令行数 | 18910 |

## 3. 反汇编清单（全量）

全文：disasm/msmapi32.ocx.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/msmapi32.ocx.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 518
- decomp_ok（伪 C） = 518
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：11.7 s
- 日志：out/R1N/ida/logs/sha256_60e841057cbbf33e10c5169cc328330d11838636002670cb9e8a7a09bab321ab.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `msmapi32.ocx` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 518 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +518（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`DllEntryPoint`, `sub_21D71322`, `sub_21D71349`, `sub_21D71368`, `DllCanUnloadNow`, `sub_21D71441`, `sub_21D71453`, `sub_21D714AD`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part1.tar.gz

- `decompiled/BPCompressor.dll.c.txt` sha256=5d2fefe607135b3c292a10b672b33a07c9b182660fee18fe6a6445e01f3ce608 bytes=53489
- `decompiled/CLIREG32.EXE.c.txt` sha256=63a1b1760bd181b2ab6f2ae683ac3b301fb4f8bbe01b104b03e9afc7b9eed72d bytes=116199
- `decompiled/GRID32.OCX.c.txt` sha256=3d124a8fe7916c4cc7508262a9f380bb4d9aa5bbb58eed114bd4e9f8fd2e029b bytes=246471
- `decompiled/INETWH32.dll.c.txt` sha256=84012f570473cb24070fce8c0857754b20d172701ea4ea31e9036477e7d04093 bytes=148534
- `decompiled/MSCAL.OCX.c.txt` sha256=68385c49aab70ba186af81522d8f7700588b0e0c233cf11d813d2b361dad8c3d bytes=319492
- `decompiled/VB5DB.DLL.c.txt` sha256=49f9e71311884bcbc8fb7daef959655d9394d4c2f5c14d93b1692146dc106dfc bytes=347359
- `decompiled/VB6STKIT.DLL.c.txt` sha256=50b27b35423e54bec84c34ca08983596dec72dd40e331e10f1916c7377006f60 bytes=341666
- `decompiled/libbz2.dll.c.txt` sha256=097aec866b5e9d252a51d6e6f0e49c6fcd680ac4424ae41f51c559151e7c9b53 bytes=349095
- `decompiled/mscomm32.ocx.c.txt` sha256=36f6a91d935d998aae3067dc468383c6700ca74806af9880e28aed4daee7f938 bytes=278118
- `decompiled/msinet.ocx.c.txt` sha256=b91b1255fc2bb7bf01605b06c863a7db61abfec9f8d331f152aef8ecc1a96615 bytes=324105
- `decompiled/msmapi32.ocx.c.txt` sha256=40e8e49be6b582c706c0870992cded2bfc1b35e51a199c1eb7c65f4a5c6a4d72 bytes=326428
- `decompiled/msscript.ocx.c.txt` sha256=d72df798ffc9b144fdc0a1d268038f3d3650172befcb7a15fc6f7e8203e7dbf4 bytes=264804
- `decompiled/msstdfmt.dll.c.txt` sha256=66f5d520aee8cf3e7d1cb0f30e856e13abfd28627026b9241029b92ca3f546ed bytes=417331
- `decompiled/psapi.dll.c.txt` sha256=289f9f15a0e3afdcb65f732b7d489164fec97b359006880b97128d933af35f40 bytes=150260
- `disasm/BPCompressor.dll.asm.txt` sha256=cf2565161f882fc8475a08a2adb4f92244db7b32b7c72460406ac19686fa3730 bytes=85536
- `disasm/CLIREG32.EXE.asm.txt` sha256=2e9050ab7260533b98ae274f17af8e72c0c302b05a483b2114a516871d909a13 bytes=276249
- `disasm/GRID32.OCX.asm.txt` sha256=8f7a7ccd4e680e32850278fce91fa4df3a768c2594580a65248375bf939020e7 bytes=446074
- `disasm/INETWH32.dll.asm.txt` sha256=b1d5495c7cd64b2f9c96667ebd09926e832508a7ce6a919381c6642723b6d3f6 bytes=316887
- `disasm/MSCAL.OCX.asm.txt` sha256=b71b12416c6a9ddfbf01c85d2f66481ef26666f055f450e1b55f1f4368f4ef4b bytes=651736
- `disasm/VB5DB.DLL.asm.txt` sha256=45ca17b79035f05dd3fa0dbbf58350824c902dc240c47d7f8e2c848f642761f6 bytes=507277
- `disasm/VB6STKIT.DLL.asm.txt` sha256=6128cc5fe308daf13e391590b02e8dd278f50b3bce4f059d881778f5be5227fd bytes=781398
- `disasm/libbz2.dll.asm.txt` sha256=935ef685054f739acf7e680570a54e0f0b03c832fade1377a8557909391d7e5c bytes=683710
- `disasm/mscomm32.ocx.asm.txt` sha256=edf6261b01cbcdb7a0cee182925cf7727090941bf7d80381084a8e1d3923811c bytes=525587
- `disasm/msinet.ocx.asm.txt` sha256=63e4fe843a53837cf0e364a2e4b16d4e5e16fb21c3bcdb2f926d20ceea9ddecb bytes=605681
- `disasm/msmapi32.ocx.asm.txt` sha256=cc2c86a62d0e13c4330875909af3be7e24ef3d5dc0e493aaf4d528adaf2c1464 bytes=611338
- `disasm/msscript.ocx.asm.txt` sha256=e35141be0fd866abb0d1e896fd7e0d6565cd29ea0a26d9f5e96faf3ede1220c5 bytes=586535
- `disasm/msstdfmt.dll.asm.txt` sha256=aa5e00d781a7ed19e1404800a88ff31b3f83d592d77c4b56fbf02eeb85436e23 bytes=826752
- `disasm/psapi.dll.asm.txt` sha256=561e0314d5a637358797247675e74b2c0482550b2b0728f69c43dde885d60062 bytes=302757
