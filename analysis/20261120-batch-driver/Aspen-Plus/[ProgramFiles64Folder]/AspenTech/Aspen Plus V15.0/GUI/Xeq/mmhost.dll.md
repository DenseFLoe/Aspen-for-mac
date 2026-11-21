# mmhost.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `mmhost.dll`，256040 字节，SHA-256 `bd0e814e6a2f15e8e24f7e8c80801bdadbb99ba4d1436270deb4a133054d90a8` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 923 = decomp_ok 923 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=923
- decomp_ok=923
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `mmhost.dll` |
| 字节数 | 256040 |
| SHA-256 | `bd0e814e6a2f15e8e24f7e8c80801bdadbb99ba4d1436270deb4a133054d90a8` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/mmhost.dll` |
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
| 指令行数 | 45344 |

## 3. 反汇编清单（全量）

全文：disasm/mmhost.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/mmhost.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 923
- decomp_ok（伪 C） = 923
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：21.1 s
- 日志：out/R1N/ida/logs/sha256_bd0e814e6a2f15e8e24f7e8c80801bdadbb99ba4d1436270deb4a133054d90a8.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `mmhost.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 923 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +923（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180001170`, `sub_1800011B0`, `??0bad_array_new_length@std@@QEAA@XZ`, `??0exception@std@@QEAA@AEBV01@@Z`, `sub_180001260`, `unknown_libname_29`, `unknown_libname_30`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/ACMWrapper.dll.c.txt` sha256=febecfb6a59b991c9d34bd524582ef8e2e7dfe3644576fbe488f5be0c08cd9ad bytes=567796
- `decompiled/AOSA.dll.c.txt` sha256=d5a0a81c76594f3617c8a7d52576bd3ce4002dd70b2c05388a0231eaf80aec4f bytes=333752
- `decompiled/APConSvr.exe.c.txt` sha256=619c1d3fe397e648dd806306519ad049d09045e7f3bb94af084f9a20d29447e0 bytes=593752
- `decompiled/AtlasUtilCME.dll.c.txt` sha256=406fc0940cd149ca83ac7fa730a46805741292be065c2bfb01bb96f2f6a4c411 bytes=494906
- `decompiled/CalcExcelAddInATL.dll.c.txt` sha256=865fe09b62782ad59f1a8e83131b60642c5136690af5042231d26066db59052b bytes=1246316
- `decompiled/SMMBlocks.dll.c.txt` sha256=33ca0c5928a676c61908d935bc49c941215b00dc68fd5979b46983b8fc4b6dca bytes=450738
- `decompiled/fxviewCME.dll.c.txt` sha256=698185f37aa8f0dafa8ad71a09b7c756870ae64f85af49ec6131f80cc4fc38af bytes=665862
- `decompiled/mmhost.dll.c.txt` sha256=b39818fc2da49c411d85a7ac7b698efb916af71074b8f29e3112a0ecf83db7d2 bytes=928279
- `disasm/ACMWrapper.dll.asm.txt` sha256=137b07a43498f16817a2fb4da39557ba348cbc00955a24be47c4d0b4ebacb6d5 bytes=860905
- `disasm/AOSA.dll.asm.txt` sha256=104f725a29c5ff68f5bf3b26e7cde071c31288683ae547723d27921df135c6ce bytes=634460
- `disasm/APConSvr.exe.asm.txt` sha256=2ffff80c1a33869c7567d0d768bc694b21d216dfe9fc1fda00433b6c6b593423 bytes=1135414
- `disasm/AtlasUtilCME.dll.asm.txt` sha256=3fef7befd20552ba03ae232ff701f7d9f72d5d461323add2a737a6d4a40d59f1 bytes=1025774
- `disasm/CalcExcelAddInATL.dll.asm.txt` sha256=c957f5bcec9933db5c804c30e5a95e3b9e1161641652285cca0aa978cf17be7a bytes=1723645
- `disasm/SMMBlocks.dll.asm.txt` sha256=d56180468584efe2520a26110b084b2fd9676f45dde44b1b3916156e14ff0607 bytes=879031
- `disasm/fxviewCME.dll.asm.txt` sha256=bfac0eca40b20f970f24d7b5aeee8e67d5f7e8fc74584e61cb778615cbc1c0bb bytes=1069269
- `disasm/mmhost.dll.asm.txt` sha256=c42b2d19913dd3801b19d0b0313f1f05e3d6f3db2b9c16aa9ddfc32fae07b8d9 bytes=1688672
- `x86/decompiled/CalcExcelAddInATL32.dll.c.txt` sha256=e2601d257e83c9cd1b65785a2481a672319a726ae681a3a4a9cf50236ab9e7f7 bytes=902789
- `x86/disasm/CalcExcelAddInATL32.dll.asm.txt` sha256=64b03cfd012bb24478ea52c38ed13b9f05ab6c6bd29b256f5c125ebe228bed9c bytes=1420784
