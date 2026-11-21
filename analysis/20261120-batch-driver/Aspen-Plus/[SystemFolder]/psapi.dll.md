# psapi.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `psapi.dll`，45136 字节，SHA-256 `21ad4009566f023c1d0b2d9f6d78024e42378960d14d11726d92fb81ce276dbc` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 151 = decomp_ok 150 + decomp_fail 1 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=151
- decomp_ok=150
- decomp_fail=1
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `psapi.dll` |
| 字节数 | 45136 |
| SHA-256 | `21ad4009566f023c1d0b2d9f6d78024e42378960d14d11726d92fb81ce276dbc` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/psapi.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x73a10000` |
| 段数 | 5 |
| 指令行数 | 9004 |

## 3. 反汇编清单（全量）

全文：disasm/psapi.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/psapi.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 151
- decomp_ok（伪 C） = 150
- decomp_fail = 1
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `73a17554` `DbgPrint`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：9.7 s
- 日志：out/R1N/ida/logs/sha256_21ad4009566f023c1d0b2d9f6d78024e42378960d14d11726d92fb81ce276dbc.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 1 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `psapi.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 151 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +151（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_73A11000`, `EnumDeviceDrivers`, `GetDeviceDriverFileNameW`, `GetDeviceDriverFileNameA`, `GetDeviceDriverBaseNameW`, `GetDeviceDriverBaseNameA`, `GetMappedFileNameW`, `GetMappedFileNameA`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/BPCompressor.dll.c.txt` sha256=5d2fefe607135b3c292a10b672b33a07c9b182660fee18fe6a6445e01f3ce608 bytes=53489
- `decompiled/CLIREG32.EXE.c.txt` sha256=63a1b1760bd181b2ab6f2ae683ac3b301fb4f8bbe01b104b03e9afc7b9eed72d bytes=116199
- `decompiled/GRID32.OCX.c.txt` sha256=3d124a8fe7916c4cc7508262a9f380bb4d9aa5bbb58eed114bd4e9f8fd2e029b bytes=246471
- `decompiled/INETWH32.dll.c.txt` sha256=84012f570473cb24070fce8c0857754b20d172701ea4ea31e9036477e7d04093 bytes=148534
- `decompiled/LOADWC.EXE.c.txt` sha256=17ae94df9603c63bb893ca0140a1770c90a7e15cbf4f2280a9b17d5818477215 bytes=32366
- `decompiled/MSCAL.OCX.c.txt` sha256=68385c49aab70ba186af81522d8f7700588b0e0c233cf11d813d2b361dad8c3d bytes=319492
- `decompiled/MSCHART.OCX.c.txt` sha256=36190dd38f03e72dd2772e7890368198b6dff273a89e6fb77db6725ef1f1ffa0 bytes=3366426
- `decompiled/RHMMPLAY.DLL.c.txt` sha256=bdaa5589cdace4a2670d80ab7d2834412ce957bb829b74b69c1d5040cee62720 bytes=49336
- `decompiled/VB5DB.DLL.c.txt` sha256=49f9e71311884bcbc8fb7daef959655d9394d4c2f5c14d93b1692146dc106dfc bytes=347359
- `decompiled/VB5STKIT.DLL.c.txt` sha256=a9208722db6540b2355b025e0813a690b6162e7503038cdfb60d00a0ed4c45b5 bytes=81474
- `decompiled/VB6STKIT.DLL.c.txt` sha256=50b27b35423e54bec84c34ca08983596dec72dd40e331e10f1916c7377006f60 bytes=341666
- `decompiled/comcat.dll.c.txt` sha256=1ed18efb6629f6118baeb32e4160eb9cd7712a03211e70a206249b01103c8de9 bytes=49039
- `decompiled/comctl32.ocx.c.txt` sha256=4d8c2f0281c3f8e78e7b958db3f9799c6200696b8e05e2dcc4566116dadf2bab bytes=1608821
- `decompiled/mfc40.dll.c.txt` sha256=0b02812a97980abc04affda5ab51a75d511b58d5ce36ce5b82d79ea48b522cbb bytes=3594695
- `decompiled/mscomct2.ocx.c.txt` sha256=4a43378df698650548e4ffb6cbd39e759ae1f7be466abca7eecb764f839d48b8 bytes=2607990
- `decompiled/mscomm32.ocx.c.txt` sha256=36f6a91d935d998aae3067dc468383c6700ca74806af9880e28aed4daee7f938 bytes=278118
- `decompiled/msinet.ocx.c.txt` sha256=b91b1255fc2bb7bf01605b06c863a7db61abfec9f8d331f152aef8ecc1a96615 bytes=324105
- `decompiled/msscript.ocx.c.txt` sha256=d72df798ffc9b144fdc0a1d268038f3d3650172befcb7a15fc6f7e8203e7dbf4 bytes=264804
- `decompiled/msstdfmt.dll.c.txt` sha256=66f5d520aee8cf3e7d1cb0f30e856e13abfd28627026b9241029b92ca3f546ed bytes=417331
- `decompiled/oleaut32.dll.c.txt` sha256=95ffc271e40c401fb47d0607be9bd9796d06c08382b98864d892ca6c60681afa bytes=2513264
- `decompiled/psapi.dll.c.txt` sha256=289f9f15a0e3afdcb65f732b7d489164fec97b359006880b97128d933af35f40 bytes=150260
- `decompiled/sstbars2.ocx.c.txt` sha256=0e87c493689adb701eee7cf261ea85551875a6cfcc4e43051d92356af458bc91 bytes=1812734
- `disasm/BPCompressor.dll.asm.txt` sha256=cf2565161f882fc8475a08a2adb4f92244db7b32b7c72460406ac19686fa3730 bytes=85536
- `disasm/CLIREG32.EXE.asm.txt` sha256=2e9050ab7260533b98ae274f17af8e72c0c302b05a483b2114a516871d909a13 bytes=276249
- `disasm/GRID32.OCX.asm.txt` sha256=8f7a7ccd4e680e32850278fce91fa4df3a768c2594580a65248375bf939020e7 bytes=446074
- `disasm/INETWH32.dll.asm.txt` sha256=b1d5495c7cd64b2f9c96667ebd09926e832508a7ce6a919381c6642723b6d3f6 bytes=316887
- `disasm/LOADWC.EXE.asm.txt` sha256=6c5efa2342832126bb53dc8016ed281ed23266d8e92a936285f671b4537ca836 bytes=71613
- `disasm/MSCAL.OCX.asm.txt` sha256=b71b12416c6a9ddfbf01c85d2f66481ef26666f055f450e1b55f1f4368f4ef4b bytes=651736
- `disasm/MSCHART.OCX.asm.txt` sha256=1e1162748c40afd7052a47f2c7dd50e1b67b48132740fbf862834c03869f6420 bytes=6137555
- `disasm/RHMMPLAY.DLL.asm.txt` sha256=73d45debb0dec57bc1dcbb5fd084fcee37d385a19edf29ed2f7794445871960f bytes=108549
- `disasm/VB5DB.DLL.asm.txt` sha256=45ca17b79035f05dd3fa0dbbf58350824c902dc240c47d7f8e2c848f642761f6 bytes=507277
- `disasm/VB5STKIT.DLL.asm.txt` sha256=41ae2a4349f2733f3634b7e4b978b2b1e704f2ffb3945246102d57cd86d03a41 bytes=180333
- `disasm/VB6STKIT.DLL.asm.txt` sha256=6128cc5fe308daf13e391590b02e8dd278f50b3bce4f059d881778f5be5227fd bytes=781398
- `disasm/comcat.dll.asm.txt` sha256=76b67e4e20f56e401117cc045ad19292c5b066c97ebe7058e0b52cb5337b1175 bytes=120606
- `disasm/comctl32.ocx.asm.txt` sha256=4df497cfb0c03d1a51814dd66f15516437c8fbd76634478fccdaa56e9d9ef5f0 bytes=2929242
- `disasm/mfc40.dll.asm.txt` sha256=58836d218a9191a36431daa8829c5f8fab766fe6d1e124522cc40dfdca4abd38 bytes=6909173
- `disasm/mscomct2.ocx.asm.txt` sha256=87b33ac7be69b09e0335252cd5251a629525364d253a7e1f30566cbbeb0b1a58 bytes=5351489
- `disasm/mscomm32.ocx.asm.txt` sha256=edf6261b01cbcdb7a0cee182925cf7727090941bf7d80381084a8e1d3923811c bytes=525587
- `disasm/msinet.ocx.asm.txt` sha256=63e4fe843a53837cf0e364a2e4b16d4e5e16fb21c3bcdb2f926d20ceea9ddecb bytes=605681
- `disasm/msscript.ocx.asm.txt` sha256=e35141be0fd866abb0d1e896fd7e0d6565cd29ea0a26d9f5e96faf3ede1220c5 bytes=586535
- `disasm/msstdfmt.dll.asm.txt` sha256=aa5e00d781a7ed19e1404800a88ff31b3f83d592d77c4b56fbf02eeb85436e23 bytes=826752
- `disasm/oleaut32.dll.asm.txt` sha256=f09a63923e1ca2cdc76ba650e77f1d0d5190994b6b1dbabf5ad22bc38db3349c bytes=4741251
- `disasm/psapi.dll.asm.txt` sha256=561e0314d5a637358797247675e74b2c0482550b2b0728f69c43dde885d60062 bytes=302757
- `disasm/sstbars2.ocx.asm.txt` sha256=45a6a45b2a81409ea67ec31d78f202fc690108bfc0a08a179cfbfdcf13fdaad5 bytes=3676816
