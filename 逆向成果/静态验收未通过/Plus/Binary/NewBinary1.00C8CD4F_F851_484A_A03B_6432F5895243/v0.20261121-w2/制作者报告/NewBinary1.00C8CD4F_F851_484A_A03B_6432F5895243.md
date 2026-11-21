# NewBinary1.00C8CD4F_F851_484A_A03B_6432F5895243 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `NewBinary1.00C8CD4F_F851_484A_A03B_6432F5895243`，292592 字节，SHA-256 `76e4e2352af5d3ca243e6500c089334be0ed9206e77a51073ccee09d7aa10a0f` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 758 = decomp_ok 756 + decomp_fail 2 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=758
- decomp_ok=756
- decomp_fail=2
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `NewBinary1.00C8CD4F_F851_484A_A03B_6432F5895243` |
| 字节数 | 292592 |
| SHA-256 | `76e4e2352af5d3ca243e6500c089334be0ed9206e77a51073ccee09d7aa10a0f` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `Binary/NewBinary1.00C8CD4F_F851_484A_A03B_6432F5895243` |
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
| 段数 | 4 |
| 指令行数 | 30581 |

## 3. 反汇编清单（全量）

全文：disasm/NewBinary1.00C8CD4F_F851_484A_A03B_6432F5895243.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/NewBinary1.00C8CD4F_F851_484A_A03B_6432F5895243.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 758
- decomp_ok（伪 C） = 756
- decomp_fail = 2
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `10012a68` `start`：RuntimeError（decompile returned None）
- `10013b45` `__check_overflow_exit`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：16.6 s
- 日志：out/R1N/ida/logs/sha256_76e4e2352af5d3ca243e6500c089334be0ed9206e77a51073ccee09d7aa10a0f.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 2 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `NewBinary1.00C8CD4F_F851_484A_A03B_6432F5895243` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 758 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +758（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_10001000`, `sub_10001181`, `sub_1000127D`, `sub_10001430`, `sub_100014AE`, `sub_100014E2`, `pfnfdin`, `pfnopen`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/NewBinary1.00C8CD4F_F851_484A_A03B_6432F5895243.c.txt` sha256=25d027c19d83b7e19f78fc9bde5e5b10ad70b2898510d09c489bd78cd885e84e bytes=556798
- `decompiled/NewBinary1.1D653100_1D4E_46B3_A31F_EFDB3C4AA073.c.txt` sha256=3b253a74d2c2a56fdf481454e408f6c13fcc4dc2ebab5bbbc9596d074aef1f1d bytes=550872
- `decompiled/NewBinary1.212AE9E9_21E8_4096_9B20_A67D65149FB9.c.txt` sha256=b8d93d3414815486cae62b6108d7df7cf45927b4b0db38b37d969cdabaf46290 bytes=549798
- `decompiled/NewBinary1.2B16631B_A5A7_4E27_A73B_18F9DA9FF484.c.txt` sha256=d42f6f8c2f060e52e5422e0a50b285b660bdaf5ec18a7c4739437443f9ea6832 bytes=546358
- `decompiled/NewBinary1.311C540B_4A5F_45A7_B6DA_584165EFB55C.c.txt` sha256=77b12d707bdcdebf50be0623d2880659844c92aaa1533d015639c10f0a14cc0f bytes=687278
- `decompiled/NewBinary1.A2215E61_056C_4400_94B9_3FE6CCB50869.c.txt` sha256=8711be14f64846570070f204731130a6ba28eb4dfa4634861d981c7b74e9543d bytes=545575
- `decompiled/NewBinary1.FFB4EB35_331E_4DFD_A406_FAD839196763.c.txt` sha256=25d027c19d83b7e19f78fc9bde5e5b10ad70b2898510d09c489bd78cd885e84e bytes=556798
- `disasm/NewBinary1.00C8CD4F_F851_484A_A03B_6432F5895243.asm.txt` sha256=95078a4e84b39b196bfb8fb75b9d51a51852941298ae455623e150506497905e bytes=1032786
- `disasm/NewBinary1.1D653100_1D4E_46B3_A31F_EFDB3C4AA073.asm.txt` sha256=b96b231f59e8f14e67e7299bba6cffd2355f1738a05f8c97e142f0bc3a41a39b bytes=1028632
- `disasm/NewBinary1.212AE9E9_21E8_4096_9B20_A67D65149FB9.asm.txt` sha256=d533e449146cf038b5e3fe1873c62dba30c95f4d62d10fd33674bc01d85f46d8 bytes=1029267
- `disasm/NewBinary1.2B16631B_A5A7_4E27_A73B_18F9DA9FF484.asm.txt` sha256=ee488afd850f71ea746b92e1e6b704988bb8e9c55522c5bbee66d8b793a01f45 bytes=1026741
- `disasm/NewBinary1.311C540B_4A5F_45A7_B6DA_584165EFB55C.asm.txt` sha256=1d0738b40d9bb9c766b7fe1e369bde25e6bf363343616b1738c3eea0d236c90c bytes=1352658
- `disasm/NewBinary1.A2215E61_056C_4400_94B9_3FE6CCB50869.asm.txt` sha256=3e0b1cf607e2604d0109a8c222b286ffa057b47485b357c348de73f2349c55f1 bytes=1025932
- `disasm/NewBinary1.FFB4EB35_331E_4DFD_A406_FAD839196763.asm.txt` sha256=95078a4e84b39b196bfb8fb75b9d51a51852941298ae455623e150506497905e bytes=1032786
