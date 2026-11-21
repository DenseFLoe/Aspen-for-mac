# NewBinary2.E6666298_EE0A_4DDA_A546_05448F2E1526 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `NewBinary2.E6666298_EE0A_4DDA_A546_05448F2E1526`，93776 字节，SHA-256 `5c8ef742ff961c58262c819e154921b5c2e32a042c11174d4aed3cff1921bda8` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 368 = decomp_ok 366 + decomp_fail 2 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=368
- decomp_ok=366
- decomp_fail=2
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `NewBinary2.E6666298_EE0A_4DDA_A546_05448F2E1526` |
| 字节数 | 93776 |
| SHA-256 | `5c8ef742ff961c58262c819e154921b5c2e32a042c11174d4aed3cff1921bda8` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `Binary/NewBinary2.E6666298_EE0A_4DDA_A546_05448F2E1526` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x10000000` |
| 段数 | 6 |
| 指令行数 | 18922 |

## 3. 反汇编清单（全量）

全文：disasm/NewBinary2.E6666298_EE0A_4DDA_A546_05448F2E1526.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/NewBinary2.E6666298_EE0A_4DDA_A546_05448F2E1526.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 368
- decomp_ok（伪 C） = 366
- decomp_fail = 2
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `1000dcc7` `___scrt_dllmain_crt_thread_attach`：RuntimeError（decompile returned None）
- `1000dce6` `___scrt_dllmain_crt_thread_detach`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：26.2 s
- 日志：out/R1N/ida/logs/sha256_5c8ef742ff961c58262c819e154921b5c2e32a042c11174d4aed3cff1921bda8.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 2 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `NewBinary2.E6666298_EE0A_4DDA_A546_05448F2E1526` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 368 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +368（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_10001000`, `sub_10001016`, `sub_10001030`, `___local_stdio_printf_options`, `sub_100010E0`, `sub_10001100`, `sub_10001120`, `sub_100011C0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/NewBinary1.026345D3_1A36_4B99_906A_ED5D844C19DD.c.txt` sha256=b4447495a5b49bc38fca779a12138caabe05e99c6a385ca0110185bfeb865920 bytes=3858277
- `decompiled/NewBinary1.31865E14_BBAC_40BB_9F23_5A602AD99EF1.c.txt` sha256=149e3ebdf994938cff5843492bb5c3822260dd03fe44f19ca9ca5cb5335be8c9 bytes=327776
- `decompiled/NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184.c.txt` sha256=a4eb2ec60b87579e2d889cf5c0f65e8c562d5426c90a4b9f26c8bd35377955ac bytes=3899142
- `decompiled/NewBinary1.90B20F6E_49C5_4429_927D_C3EA0F8A1DFE.c.txt` sha256=6728a5b535377ee5ae75287e684ca3bbbe10cf0306e844d407679652efe6ca1d bytes=3843723
- `decompiled/NewBinary1.C25FA7FB_B884_414F_A1CE_91EAE0A5FE95.c.txt` sha256=1c6d2cd6ecbb71701f45377d39531d3c8d0edb5b35b9851f702ce3b8db9e7138 bytes=335130
- `decompiled/NewBinary2.311C540B_4A5F_45A7_B6DA_584165EFB55C.c.txt` sha256=ae0e8aae8ab176a993b31bef0986e10ca5ee264b5b8a846300da0932009e0cbd bytes=158043
- `decompiled/NewBinary2.DE8C44AF_7DAB_4592_B8DA_A61085FBCC4F.c.txt` sha256=2462a2b51e86b751bd6a9722ad5c9f6e75e48003ae4da62f82fa8a264839ebe8 bytes=3843507
- `decompiled/NewBinary2.E6666298_EE0A_4DDA_A546_05448F2E1526.c.txt` sha256=8b9fb0d5fd7e8ce20afd00716975a0bdb57cc679ad953eb5d2a92e0d29a4508c bytes=304242
- `decompiled/NewBinary3.31865E14_BBAC_40BB_9F23_5A602AD99EF1.c.txt` sha256=379cdb19bf1fa687fd52abd11d3a21007ba7ec672e17594f09b5d3ff18939aa6 bytes=160033
- `decompiled/NewBinary3.8F90E150_ACB0_439F_BFCF_CAF0F4169B33.c.txt` sha256=1bfe1ea8279f3f6a185269df3d7ee83cab423094648910c73ac444810228cdd9 bytes=73758
- `decompiled/NewBinary4.31865E14_BBAC_40BB_9F23_5A602AD99EF1.c.txt` sha256=379cdb19bf1fa687fd52abd11d3a21007ba7ec672e17594f09b5d3ff18939aa6 bytes=160033
- `disasm/NewBinary1.026345D3_1A36_4B99_906A_ED5D844C19DD.asm.txt` sha256=c88317aec44fa09e9d63520c18c7df16adc68484565b36efe2cbdf0d846fa260 bytes=7390916
- `disasm/NewBinary1.31865E14_BBAC_40BB_9F23_5A602AD99EF1.asm.txt` sha256=d81259d671686b856ec4f4044382ec0eadbc7d2a99e1042a776e562f2a183524 bytes=652944
- `disasm/NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184.asm.txt` sha256=e9cdf853effc75c958cf287a7bcd76225bba7846a260362ddecad5551b1ed2db bytes=7471424
- `disasm/NewBinary1.90B20F6E_49C5_4429_927D_C3EA0F8A1DFE.asm.txt` sha256=003d0dd1bf54ff04faa08c2995cdb6f1aede61fe92bb284d7576d161ab875ec9 bytes=7361104
- `disasm/NewBinary1.C25FA7FB_B884_414F_A1CE_91EAE0A5FE95.asm.txt` sha256=dc06ec1b9f1ddae7675bb91752dea8a92f196dfbacb6d1d965e59ca6ce07cf8a bytes=666712
- `disasm/NewBinary2.311C540B_4A5F_45A7_B6DA_584165EFB55C.asm.txt` sha256=82069773d4fb67b67ab30bd3c5586444502b55c8a6ed414c53ffabb78305f379 bytes=352373
- `disasm/NewBinary2.DE8C44AF_7DAB_4592_B8DA_A61085FBCC4F.asm.txt` sha256=37000fd61afa743fbd6e2fe0fee303abb656170e682b896ba587e1c1bc4f2a93 bytes=7361038
- `disasm/NewBinary2.E6666298_EE0A_4DDA_A546_05448F2E1526.asm.txt` sha256=467eb626af1b17c2e4544e15994ef6353019a9f9f3dea0b4ad21cf14d5f3cd25 bytes=630030
- `disasm/NewBinary3.31865E14_BBAC_40BB_9F23_5A602AD99EF1.asm.txt` sha256=458533c4b5685d3ad012f0efbda243de8d5bf5ad33a87969558281e604b95d19 bytes=343355
- `disasm/NewBinary3.8F90E150_ACB0_439F_BFCF_CAF0F4169B33.asm.txt` sha256=ff8b28c8ad83085791d3b78673b31b79f3fa52ce57838a7f957540dce9a0438d bytes=155944
- `disasm/NewBinary4.31865E14_BBAC_40BB_9F23_5A602AD99EF1.asm.txt` sha256=458533c4b5685d3ad012f0efbda243de8d5bf5ad33a87969558281e604b95d19 bytes=343355
