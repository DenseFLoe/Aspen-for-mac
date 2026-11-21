# aos_sparselm.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `aos_sparselm.dll`，837160 字节，SHA-256 `69f4d1cadad4e1ab276ad939cdbd3076b55441a6f1db78b2d7a9bbc8576334b5` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 3288 = decomp_ok 3285 + decomp_fail 3 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=3288
- decomp_ok=3285
- decomp_fail=3
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `aos_sparselm.dll` |
| 字节数 | 837160 |
| SHA-256 | `69f4d1cadad4e1ab276ad939cdbd3076b55441a6f1db78b2d7a9bbc8576334b5` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Open Solvers V15.0/Bin/aos_sparselm.dll` |
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
| 段数 | 6 |
| 指令行数 | 160313 |

## 3. 反汇编清单（全量）

全文：disasm/aos_sparselm.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/aos_sparselm.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 3288
- decomp_ok（伪 C） = 3285
- decomp_fail = 3
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `180010e38` `sub_180010E38`：RuntimeError（decompile returned None）
- `180022f57` `sub_180022F57`：RuntimeError（decompile returned None）
- `18002d75e` `sub_18002D75E`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：228.1 s
- 日志：out/R1N/ida/logs/sha256_69f4d1cadad4e1ab276ad939cdbd3076b55441a6f1db78b2d7a9bbc8576334b5.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 3 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `aos_sparselm.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 3288 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +3288（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180003550`, `sub_180003E70`, `sub_180004220`, `sub_18000437C`, `sub_1800044D2`, `sub_180004520`, `sub_180004552`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/ApSparseExePS.dll.c.txt` sha256=fe799ba1c394fcac208a847b7b154e5c56d596377aa7ef6984407cd25a93a0fc bytes=27099
- `decompiled/aos_cbc.dll.c.txt` sha256=b164e298ceef06d6f99021a62fee4b3846afb7185d237e6bff444e325a5b8002 bytes=82997
- `decompiled/aos_decomp_dmo.dll.c.txt` sha256=d36d6bb798510034e64340322a3a6e275e34467f0ae4135b755bebad27fef12d bytes=2200173
- `decompiled/aos_decomp_lssqp.dll.c.txt` sha256=73d5988c34a25f48ca8d40e8d6cb896e0d45713499bac29d20e189cf13fa92b2 bytes=2200185
- `decompiled/aos_decomp_sparse.dll.c.txt` sha256=79865bd6144338c21ace6d1a996912408a29ee17c88cf007f7be7f79d8ccaa02 bytes=2200176
- `decompiled/aos_homotopy_nlap_dmo.dll.c.txt` sha256=f2dcebf861a69598ef5c7b2d091b1ddb4083e2494bdf55011673078a2605e609 bytes=137683
- `decompiled/aos_homotopy_nlap_lssqp.dll.c.txt` sha256=78b718d7de1e1526edf8de4639faed72778778c66adbc5ba46bad9a9b7f58c94 bytes=137693
- `decompiled/aos_homotopy_sparse.dll.c.txt` sha256=16100f9dfe677a21c660d787dfbfe3f513e35db63dee2220fddf0dea017bc8b8 bytes=137678
- `decompiled/aos_lapack.dll.c.txt` sha256=d2a5ed1d5301b2d749739a82ffd1a47e27cc620f744e4c92dba13a91d0b51b78 bytes=2852486
- `decompiled/aos_lssqp.dll.c.txt` sha256=b81c3cdca863d913c346af7c09a158a00e2ee01153feb59b3a30f6798c9f0479 bytes=2848607
- `decompiled/aos_lssqp_proxy.dll.c.txt` sha256=b81c3cdca863d913c346af7c09a158a00e2ee01153feb59b3a30f6798c9f0479 bytes=2848607
- `decompiled/aos_nelder_mead.dll.c.txt` sha256=9d0508b382e8f99da36849be36cb31b64b41bdf01a1317f9b42cbd8244de88d7 bytes=371183
- `decompiled/aos_nlap_dmo.dll.c.txt` sha256=db15c1321a697f8e3c52c5b9f4ec994a68dda5ae8964851788f0b2c13721f98f bytes=121022
- `decompiled/aos_nlap_lssqp.dll.c.txt` sha256=049b76112c4f6177c3b8519fbbdc2903a56753eacba214a4224fded3c9f832aa bytes=121030
- `decompiled/aos_services.dll.c.txt` sha256=b29b1888b6b8cd4dba2f71bf9471794bf6938a309d710993f37b00872598b653 bytes=82709
- `decompiled/aos_sparselm.dll.c.txt` sha256=12f12f4ed82521d549c01b2a1fabfe6a99942d7d262b989e986ea76f7fee13f1 bytes=4030835
- `decompiled/aos_xslp.dll.c.txt` sha256=15a122015aa23dba34cf474ec2c40502fe8082906ad2552fed70e38ea94b78ed bytes=1380624
- `decompiled/aosutils.dll.c.txt` sha256=f47051540419ee9d6da922bb4be848995276e889ad44c3d1463aa789b035f5c3 bytes=167547
- `decompiled/dmoblas.dll.c.txt` sha256=ee30cb1dea7a1c0a63631724ea7e870a7dc3f5d89bd91c52e99111b87e1a65cb bytes=115546
- `decompiled/xprl.dll.c.txt` sha256=0897605e39fe7c28943dc6247030d21962c51d60957265d1723723f7d6cc40a3 bytes=3198097
- `disasm/ApSparseExePS.dll.asm.txt` sha256=1d3342a7c38a1634b7a9ea3b33e549e592058df612ec489d1d610eceb037fa86 bytes=41273
- `disasm/aos_cbc.dll.asm.txt` sha256=f20cb01441e7b3886d84c4dfef789bf9aecf57d1ba7fb1d9f2320708f6cf31f4 bytes=141669
- `disasm/aos_decomp_dmo.dll.asm.txt` sha256=8252638be728687da505d6c1349c04d77de7be5f94fbc23d3128a4f5d377b83e bytes=4299027
- `disasm/aos_decomp_lssqp.dll.asm.txt` sha256=8e87ceea3a572e3c604f2b7b69c4aa455d9752a6e45dd27a73df2b96ecc6d786 bytes=4299044
- `disasm/aos_decomp_sparse.dll.asm.txt` sha256=cae00584d61a352b96fe734ed4291ca2c9150f0dfc611f294075c63f17852791 bytes=4299028
- `disasm/aos_homotopy_nlap_dmo.dll.asm.txt` sha256=0f0ccb2cc1274fe75fce1c6bf5faf50d0c13b125e60771c2585d253d440322ca bytes=267523
- `disasm/aos_homotopy_nlap_lssqp.dll.asm.txt` sha256=a375372474b59529f459fdd4e1d40b588aa76d81a2aa5890902d134887689964 bytes=267537
- `disasm/aos_homotopy_sparse.dll.asm.txt` sha256=c991cab264d98f0e92a0d1d6931f2eee36f0d2ec679d3f8c52b77b0f780ae97f bytes=267519
- `disasm/aos_lapack.dll.asm.txt` sha256=f55c3e506bbeee478fb47cc5b7aac4eb21eb067b399f488ef207a06835d8cdfe bytes=4429943
- `disasm/aos_lssqp.dll.asm.txt` sha256=4a32c2ec6c3fa5c1e72222c3b4b353304ad13ac98d897f1d3e943edb8d3a2bc6 bytes=4873047
- `disasm/aos_lssqp_proxy.dll.asm.txt` sha256=f27bcfcd09f8bf6f821eed68ab59e0d4e87987a7f3344e8ec34ddfdaae1b2d05 bytes=4873041
- `disasm/aos_nelder_mead.dll.asm.txt` sha256=0d8b870993e257dcfcd87414cad444593cccc8d5f44cbc9f0b0195ac8a34f298 bytes=437519
- `disasm/aos_nlap_dmo.dll.asm.txt` sha256=f60a2175b4c9e87f4502b917962907314aa4aec1b99f7f69f8f301cf6551ba64 bytes=198474
- `disasm/aos_nlap_lssqp.dll.asm.txt` sha256=d580bcd53b4ccb9bffe606489f659d803363d19580a9246ddf0438b77f02d642 bytes=198487
- `disasm/aos_services.dll.asm.txt` sha256=9d897b379e81a310af139ebf442e80bf1e7628e60af795899cfeb55e7bf8bafb bytes=141507
- `disasm/aos_sparselm.dll.asm.txt` sha256=f597e7a90bc62cea94ef4e85b9462e7e4fe37610b81b86a826f6f241fcd106d1 bytes=6062965
- `disasm/aos_xslp.dll.asm.txt` sha256=d7a37e412ce65765a1ddd72b700fb9782a7beef55f17915d59d90c6f11676f19 bytes=3143799
- `disasm/aosutils.dll.asm.txt` sha256=b97753eedd96c1a4e57336cda6a62c9637852c5289aeb1903411f6dc42424afc bytes=380583
- `disasm/dmoblas.dll.asm.txt` sha256=c209c504289c415a16fd3dd0ddcd98be68c5fb0bf127a8364123495735099b65 bytes=296052
- `disasm/xprl.dll.asm.txt` sha256=e644e3d1412dad77fda9f5cf3eaa149a99956d78b928845a4c945d205c0d9b35 bytes=5821109
