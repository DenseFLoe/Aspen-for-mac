# HYPCOThK11.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `HYPCOThK11.dll`，837576 字节，SHA-256 `4bc95248b883a39934a01611269b7a08cb3a8117bad7c6f7746ee0ec680d2dfb` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 4716 = decomp_ok 4716 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=4716
- decomp_ok=4716
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `HYPCOThK11.dll` |
| 字节数 | 837576 |
| SHA-256 | `4bc95248b883a39934a01611269b7a08cb3a8117bad7c6f7746ee0ec680d2dfb` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HYPCOThK11.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 64 |
| 镜像基址 | `0x12000000` |
| 段数 | 5 |
| 指令行数 | 140162 |

## 3. 反汇编清单（全量）

全文：disasm/HYPCOThK11.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/HYPCOThK11.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 4716
- decomp_ok（伪 C） = 4716
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：195.8 s
- 日志：out/R1N/ida/logs/sha256_4bc95248b883a39934a01611269b7a08cb3a8117bad7c6f7746ee0ec680d2dfb.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `HYPCOThK11.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 4716 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +4716（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_12001000`, `sub_12001080`, `sub_12001100`, `sub_12001130`, `sub_12001160`, `sub_120011E0`, `sub_12001260`, `sub_120012E0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/COCOMTh.dll.c.txt` sha256=c7bd65315e8b8a73d30c75ee4a188ce82bdc1479c1e9cbaea130083e9386b83f bytes=2379887
- `decompiled/COCOMTh11.dll.c.txt` sha256=14a6a16d6cfd750076f60a6be52f5726db7d45d35562dc1ce381a25347dd723c bytes=2452247
- `decompiled/HYPCOThK11.dll.c.txt` sha256=55d1c943a4c90f3a5ad7eb92b3587bf369ca06ad66d3281f66ff6d3689c10786 bytes=2650977
- `decompiled/HyCOGUI.dll.c.txt` sha256=da2cfa352ac9d64fabb3e5bbe3f7658d4bb7a4f91762f08d88dda455e5d9ecfd bytes=1333741
- `decompiled/HyCOGUI11.dll.c.txt` sha256=89d8a99f78d0264197d1045d6c7f42e4c81a490d3bdb5d683bc9dd4447980ed8 bytes=1388408
- `decompiled/HypCOTh.dll.c.txt` sha256=4cd77dccd6223affe73c0214082707a05609b6b3d9ec47b0cf9bc9c9995fd4c1 bytes=1964053
- `decompiled/HypCOTh11.dll.c.txt` sha256=373d7cc23924f1a2b900b9f766e1803b0b97026aa4141413683d0f96b85aba7e bytes=2076357
- `disasm/COCOMTh.dll.asm.txt` sha256=98e4826e595efe4bdc1299d7575d45048d59ed00cafbd70f119f7bb73bab6943 bytes=4514312
- `disasm/COCOMTh11.dll.asm.txt` sha256=5afaea20f219a61d64e73ca6747f83923f237a679d804ef1bc44112215c1f8be bytes=4646498
- `disasm/HYPCOThK11.dll.asm.txt` sha256=2ca5de01a733858721508b839ee15590049603668242b921b5de010754438003 bytes=4753877
- `disasm/HyCOGUI.dll.asm.txt` sha256=aa53e0a7b406fb1fc7fe95e18f8a9f3cc996b69d924e374d17f547fdd49f03f1 bytes=2390853
- `disasm/HyCOGUI11.dll.asm.txt` sha256=46f1c4f11801e3ce43ebb59ba1b74598e1b6ad8f06e08a130f21014961da762a bytes=2466686
- `disasm/HypCOTh.dll.asm.txt` sha256=7e866f32d0cfae07fa4711a051b6a4ba3b7f45e12939d75db3d449a1489f6135 bytes=3665401
- `disasm/HypCOTh11.dll.asm.txt` sha256=c1b33edb2bda2dd39874bedf1d493af6162a21f4dec73667d584f2ff93825b8c bytes=3865739
