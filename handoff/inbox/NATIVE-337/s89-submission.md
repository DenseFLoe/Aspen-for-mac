# NATIVE-337 s89 提交（六参四处一致 + Invoke/VARIANT 契约 + FF/4 接入分类入口）

- 固定候选：#445 @ fedc23d；主干基线 6f39d818；同一分支 head 前移。

## ① 0x1389 六参，四处一致（源 / 表 / 生成器 / 说明）
| 参数位置 | 值 | 出处 |
| --- | --- | --- |
| RCX | this = RDI（0x2330 工厂返回的接口） | 0x1386 `MOV RCX,RDI` |
| RDX | riid = 0x82F8（IID_NULL，16 字节全零） | 0x137F `LEA RDX,[rip+0x6F72]` |
| R8 | rgszNames = &[RSP+0xD0] | 0x1377 `LEA R8,[RSP+0xD0]` |
| R9 | cNames = 1 | 0x136E `MOV R14D,1` → 0x1374 `MOV R9D,R14D` |
| 栈 5 | lcid = GetUserDefaultLCID() | 0x1357 `CALL [0x180007060]` → 0x136A `MOV [RSP+0x20],EAX` |
| 栈 6 | rgDispId = &[RSP+0xC8] | 0x135D `LEA RCX,[RSP+0xC8]` → 0x1365 `MOV [RSP+0x28],RCX` |

**更正**：s85 把 RDX 写成 rgszNames、R8 写成 cNames、R9 写成 lcid —— 实际 RDX 是 riid（IID_NULL），R8 才是 rgszNames，R9 是 cNames，lcid/rgDispId 在栈上第 5/6 位。
四处已同步：
1. 表：`calls.csv` 第 413–416 行四条间接调用 note 全部改写（脚本 `tool/s89_abi_fix.py` 生成，非手改）；
2. 源：`code/native.asm` 末尾追加 s89 ABI 注释块（append-only，指令行号不变）；
3. 生成器：`tool/s81_showdialog.py` 的 getidsofnames/invoke/variant-init 三条 item 文本；
4. 说明：本回执与 `code/s81-showdialog.csv`。

## ② Invoke 第五至第九参 + VARIANT 契约
| 栈位 | 参数 | 值 |
| --- | --- | --- |
| [RSP+0x20] | wFlags | 1（DISPATCH_METHOD） |
| [RSP+0x28] | pDispParams | &[RSP+0x50] |
| [RSP+0x30] | pVarResult | &[RSP+0x80] |
| [RSP+0x38] | pExcepInfo | 0（RSI 清零后存入） |
| [RSP+0x40] | puArgErr | 0 |
前置寄存器：RCX=this(RDI)、RDX=dispIdMember（0x143A `MOV EDX,[RSP+0xC8]`）、R8=riid 0x82F8、R9=lcid。

**VariantInit 契约**：0x13CF `CALL [0x1800070f0]` = OLEAUT32.dll!#8，作用于 `[RSP+0x68]` 起、stride 0x18 的 VARIANT 数组，计数取 `[RSP+0x60]` 低 dword（cArgs=1）→ 24 字节置为 VT_EMPTY；随后 0x13DD/0x13E2 写 vt=8（VT_BSTR，16 位字段），0x13E7 写 union.bstrVal=RBP。
**结果清理逐址**：0x1449 `CMOVNS ESI,[RSP+0x88]`（成功取结果低 32 位）→ 0x1451/0x1454 取 vtable 与 this → **0x1457 Release** → 0x145B `LEA RCX,[RSP+0x80]` → **0x1463 `CALL [0x1800070d0]` = OLEAUT32!#9 VariantClear(pVarResult)** → 0x1469 `MOV EAX,ESI` 返回 int（仅低 32 位有意义）。

## ③ FF /4 判型接入 s65 分类入口
`tool/s65_counterexamples.py` 的 thunk 识别补上 `reg==4` 条件（`FF /4 mod=00 rm=101` 才是 `jmp [rip+disp32]`，`FF /0` 是 INC）。接入后：`sites 161 categories {'ok': 161}`，站数不变。

## ④ ShowDialog 绑定
**仍未绑定**，且不硬绑：本机没有该组件的注册表快照或类型库（工厂 0x2330 走 `CLSIDFromProgID`→`CoCreateInstance`，ProgID/CLSID 的注册表值不在静态件里）。已证边界：IID_IDispatch、槽位/成员、DISPID 动态获取路径；所需输入：`HKCR\<ProgID>\CLSID` 或组件 IDL/类型库。动态 DISPID（GetIDsOfNames 结果）与其他间接调用继续保留为未决。

## ⑤ 两组对照（两个入口都跑）
| 对照 | s65 入口（s69_tests.py） | s73/s37 入口 |
| --- | --- | --- |
| 同位移 JMP/INC | T4 字节 + T6 序号：PASS | `tool/s81_jmp_pair.py`：`PAIR jmp-vs-inc : jmp=jmp inc=inc PASS` |
| 同 DLL 不同序号 | T6 `mfc140.dll!#2344 → #2345` → contradiction=1 @0x106C：PASS | 分类器整串判等，#2344 vs #23440 亦为 contradiction |

## 判定
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条未决已申报）

## qa gate 3517b5ed
~~~
units: pass=10 fail=0 not-applicable=3 error=0
exit: 2
~~~
逐条 defect：**0**。n/a 三项：access-flags（`no CLI metadata (native-only image)`）、clause-semantics（无 EH 子句）、eh-boundary（`boundary_tables 0`）。`fingerprint-pathset inputs=118`（with_prefix/top_level 拆分），无 `[advisory] declared set shrank`。

## 指纹
- 见 `work/s89-tools.txt`（脚本从产物生成）与 `s89-fingerprints.json`（118 项）
