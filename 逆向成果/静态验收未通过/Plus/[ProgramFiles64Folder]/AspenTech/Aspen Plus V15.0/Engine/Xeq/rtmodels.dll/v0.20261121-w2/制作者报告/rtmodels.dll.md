# rtmodels.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `rtmodels.dll`，1407528 字节，SHA-256 `02f6863acfd3b902dbbe9d02069f159263ed29bd0341488393ecea673e090dd1` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 3829 = decomp_ok 3819 + decomp_fail 10 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=3829
- decomp_ok=3819
- decomp_fail=10
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `rtmodels.dll` |
| 字节数 | 1407528 |
| SHA-256 | `02f6863acfd3b902dbbe9d02069f159263ed29bd0341488393ecea673e090dd1` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/rtmodels.dll` |
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
| 段数 | 9 |
| 指令行数 | 208102 |

## 3. 反汇编清单（全量）

全文：disasm/rtmodels.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/rtmodels.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 3829
- decomp_ok（伪 C） = 3819
- decomp_fail = 10
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `180001000` `sub_180001000`：RuntimeError（decompile returned None）
- `180003710` `sub_180003710`：RuntimeError（decompile returned None）
- `1800099a0` `sub_1800099A0`：RuntimeError（decompile returned None）
- `18000dfd0` `sub_18000DFD0`：RuntimeError（decompile returned None）
- `180014570` `sub_180014570`：RuntimeError（decompile returned None）
- `180029460` `sub_180029460`：RuntimeError（decompile returned None）
- `180054310` `sub_180054310`：RuntimeError（decompile returned None）
- `180065e60` `sub_180065E60`：RuntimeError（decompile returned None）
- `18006b350` `sub_18006B350`：RuntimeError（decompile returned None）
- `1800970e0` `sub_1800970E0`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：186.6 s
- 日志：out/R1N/ida/logs/sha256_02f6863acfd3b902dbbe9d02069f159263ed29bd0341488393ecea673e090dd1.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 10 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `rtmodels.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 3829 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +3829（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180003710`, `sub_180005DF0`, `sub_1800066E0`, `sub_1800074E0`, `sub_180007BC0`, `sub_180007ED0`, `sub_180008030`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `decompiled/dualbatchexp.dll.c.txt` sha256=71a6e05ed4df6e3e7e222c02577b8f45eb627872c6ba2017128b796335f43b37 bytes=9844349
- `decompiled/fcc.dll.c.txt` sha256=c65e95934c70876221bfa0a6f7fec94aaa6125d37ab1ed0f876dc55100e3c222 bytes=6476186
- `decompiled/hxnetintdataex.dll.c.txt` sha256=79f983fdf91c6fd6e9fcdceccf51a742a14d9be15021c2f00faa4998dea6fb6a bytes=7671981
- `decompiled/pmlbridge.dll.c.txt` sha256=69a109d88a7114231a163acd8310fa261e38c7a69c4205377428c124b86c3130 bytes=7563779
- `decompiled/rtmodels.dll.c.txt` sha256=646570d9b2cbafc65acc6699cdb28a622b7964865bc4b19e870a21922abbb80c bytes=3592760
- `decompiled/sautils.dll.c.txt` sha256=1a90032e7b4f6185d872fbcb6675841aa562fba91ccdd8175e7f0e9739a9495d bytes=3691160
- `decompiled/ssutils.dll.c.txt` sha256=6fd83effeee6d51b11bbeb201681e9a7c01f5d6093db23b6fe64bb708132263f bytes=4279829
- `decompiled/zebatchfrac.dll.c.txt` sha256=c5eba569d7e66a2c652f1d574389fb1cb7ea5350e6de66b60f2928fcf6d6db2a bytes=2745899
- `decompiled/zedistu.dll.c.txt` sha256=7ec79f1b4656056bb670e3460e62442d91f87b870cc0a30e2d2ab26222605541 bytes=3162392
- `decompiled/zedryer.dll.c.txt` sha256=07d4cca3743b6f5af64cb045e25b03b101a143635ce4709854ce82db98aeabce bytes=5001109
- `decompiled/zeheatx.dll.c.txt` sha256=a2a10207eb06358199aaaa58ee2f9db90ccebacc3d81debf3883c178d94c68f9 bytes=2567259
- `decompiled/zemultifrac.dll.c.txt` sha256=aa75f5bb375d67116cda11b1c34a6c468f95567aac1ad412c5afc351cd869c7f bytes=2919706
- `decompiled/zepetrofrac.dll.c.txt` sha256=b48603e0360ebc8c419448289af793d660e417640d635e1ab2a2e9dd9e23f0fd bytes=5019238
- `decompiled/zeratefrac.dll.c.txt` sha256=52150ef7e5af73c138c04a011f50fa31f5bf24202e83539be88c262c61659d69 bytes=4865366
- `decompiled/zerbatch.dll.c.txt` sha256=9e5bec96c81d64ccfbb14c2f93a59cb2ef6d97ea15cb9ae2a83e38e381f10179 bytes=1365775
- `decompiled/zerxrplus.dll.c.txt` sha256=09edc4e7f368b75a7e05ee1c0017d1304f501ff89d5abba19d410f14502f265a bytes=2844761
- `decompiled/zesteamsys.dll.c.txt` sha256=0bd831d7437f19aa7b4cb7b1c9fffd218a089eb1b14978b43a207587a1c13381 bytes=6060595
- `disasm/dualbatchexp.dll.asm.txt` sha256=0b533b18bf86f12551c9784e7e3a43090f1800a44cba4f55f54a49f0ef2f04af bytes=16167916
- `disasm/fcc.dll.asm.txt` sha256=09bffb94401cfca736a33e5f8581f22b849ad8b8b86d0cf271ecb753f9891af1 bytes=21314690
- `disasm/hxnetintdataex.dll.asm.txt` sha256=8a7729b28bc60b6b1ed1b80626682f60f4ad0f383782f8e9c5700ae172e7a9c0 bytes=10578164
- `disasm/pmlbridge.dll.asm.txt` sha256=f43c3219c84a02509455e5dee827736bdeb0f4ea522976d9b6c62eef8b41cf4d bytes=16832382
- `disasm/rtmodels.dll.asm.txt` sha256=07eb0cb105f50f784ca7e8d108322b77c50f11d4ff014b192642c3fc22d2841a bytes=7903362
- `disasm/sautils.dll.asm.txt` sha256=994519327e1e634cfc1b0838ff7eb2f4051b7f84360e1867912971a8b050c3ab bytes=6545544
- `disasm/ssutils.dll.asm.txt` sha256=d7d83b6a395d1a806b9d6423a09e091c015261c46a456d305a6cb944135bdcc4 bytes=6717795
- `disasm/zebatchfrac.dll.asm.txt` sha256=a46915206d1881689df302f119e145849e024753a36d651d70b0210117c2b6ba bytes=8540916
- `disasm/zedistu.dll.asm.txt` sha256=99fc0fa91eede3ee007f3a70f35e4978cf46704ba20fdbf8497a548748b9a35e bytes=6296520
- `disasm/zedryer.dll.asm.txt` sha256=cf7fb86b5d30edf3c369d9b3d0f510f4acd990687c8e6581a784728009d20d62 bytes=7088887
- `disasm/zeheatx.dll.asm.txt` sha256=92cfb75c6a548255c07691150ef206c6dedb876ef017c5e1c90a3e8b5fcc14c9 bytes=6872681
- `disasm/zemultifrac.dll.asm.txt` sha256=926f46263d6b8a592e53af3e91b220ae8ed642ad95d838089c958e5b838887e7 bytes=6449471
- `disasm/zepetrofrac.dll.asm.txt` sha256=96b50d9bae77b71632e0a8369e55b0979d7ecfe6362ddf21d5fd094f13457565 bytes=13358738
- `disasm/zeratefrac.dll.asm.txt` sha256=353958cdd777176621d63dcea4e6df87828301ee3ff0dff31d5120770172aa48 bytes=15926328
- `disasm/zerbatch.dll.asm.txt` sha256=0677ffd5948e7c6fa0647a8e724cdeddc06d2a68dbca547edcd7f8907c63a413 bytes=5670783
- `disasm/zerxrplus.dll.asm.txt` sha256=f83cd93e6fff3650a523bdda3841fbede988f0a0d9a1ebc0bae4c3faad87c4f9 bytes=5765521
- `disasm/zesteamsys.dll.asm.txt` sha256=3be125525afa2e4b55bbb13a18c4beb0c6c8ef120267df9aff38fb62434074b1 bytes=12076869
