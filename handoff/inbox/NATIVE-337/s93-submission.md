# NATIVE-337 s93 提交（ShowDialog 绑定落三处 + VariantInit 契约 + 单改反例 + s37 精确导入校验）

- 固定候选 #445 @ 157af57；主干基线 0554621e；同一分支 head 前移。
- 沿用不重做：六参映射、Invoke 五栈参、`FF /4` 实现。

## ① ShowDialog 绑定（依据来自字节，落在三处）
| 证据 | RVA | 值 | 来源 |
| --- | --- | --- | --- |
| ProgID 字符串 | 0x78A8 | `AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver.410` | 0x2375 `LEA R8,[rip+0x51xx]` → MultiByteToWideChar(0x2388) |
| 注册解析 | 0x23A0 | `CALL [0x180007648]` = ole32!CLSIDFromProgID | 拿 ProgID 换 CLSID |
| IID | 0x8308 | `00040200-0000-0000-c000-000000000046` = IID_IDispatch | 0x23B4 `LEA R9`；CoCreateInstance 0x23C8 |
| 方法名 | 0x7820 | UTF-16LE `ShowDialog` | 0x1345 `LEA RAX` |
| 调用 riid | 0x82F8 | 全零 = IID_NULL | 0x137F `LEA RDX` |

**绑定依据（可复核的注册键）**：`HKCR\AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver.410\CLSID` → CLSID → `CoCreateInstance(IID_IDispatch)` → `GetIDsOfNames("ShowDialog")` → DISPID → `Invoke`。ProgID 直接来自原件字节，不是文档抄写；CLSID 值需目标机注册表才能展开（本机无快照，故 CLSID 数值仍为未决，但绑定键本身已确定）。
三处已落：**解释**=本回执；**生成器**=`tool/s81_showdialog.py` 新增 `binding_rows()`（从字节读 ProgID/方法名/IID/vt，运行期生成，不写死）；**交付表**=`code/s81-showdialog.csv` 追加 5 行 `binding-*` / `calls-riid` / `variant-vt`（共 20 行）。动态 DISPID 保留（Invoke 的 dispIdMember 来自运行时 GetIDsOfNames）。

## ② VariantInit 契约（按 Microsoft 语义，操作数来自字节）
- 调用点：0x13CF `CALL [0x1800070f0]` = **OLEAUT32.dll!#8 = VariantInit**。
- 操作数：基址 `[RSP+0x68]`（0x13AC `LEA RAX`），**元素步幅 0x18 = 24 字节**（循环 0x13C0–0x13DB：`LEA RCX,[RAX+RAX*2]` → `LEA RCX,[RSP+0x68+RCX*8]`），计数 = `[RSP+0x60]` 低 dword `cArgs=1`。
- `vt` 语义（值取自字节）：0x13DD `MOV EAX,8` → **VT_BSTR**，0x13E2 `MOV word [RSP+0x68],AX` 只写 16 位 vt；VariantInit 先把 24 字节置 `VT_EMPTY(0)`。
- 联合体：0x13E7 `MOV [RSP+0x70],RBP` → `bstrVal`；清理 0x1457 Release → 0x1463 `CALL [0x1800070d0]` = **OLEAUT32!#9 VariantClear** → 0x1469 `MOV EAX,ESI`（int，低 32 位）。

## ③ 两个单改反例（改输入，结论必须变）
| 反例 | 改动 | 结果 |
| --- | --- | --- |
| A `0x13DD` | 二进制 vt 立即数 `8 → 9` | 表 `variant-vt` 从 `vt immediate 8` 变 `vt immediate 9`（PASS） |
| B `0x137F` | riid 的 rip 偏移 `0x6F72 → 0x6F62` | `calls-riid` RVA `0x82F8 → 0x82E8`（PASS） |
脚本 `tool/s93_counters.py` 一条命令跑完，`SUITE : ALL PASS`。

## ④ s37 唯一行的真实导入校验
`tool/s37_two_hop.py` 现在对**绑定到行的每一站**都做整串等值校验：`calls[row].callee` 必须精确等于从原件 IAT 解出的 `DLL!名字/#序号`，否则该行置空（不再因行号撞车而接受同 DLL 的邻近序号）。重放后：`rows 161`、`blank 0`、`0x106C → #2344/525`、`0x12DA → OLEAUT32!#313/528`。
两个固定配对：`#2344 vs #2345`（同 DLL 不同序号）在 s65 入口 `contradiction=1 @0x106C`（T6 PASS）；`#2344 vs #23440`（前缀）同样 `contradiction=1`（T1 PASS）。

## ⑤ 指纹清单自排除 + 独立 SHA-256
- `tool/s93_fingerprints` 生成时**排除自身**（mk_fingerprints 的 SKIP 列表含本轮清单名），避免自引用；本轮清单 131 项（排除自身与本回执，避免自引用）。
- **清单文件独立 SHA-256：`99d40a68d6675ade46a4d33b2e186878c1688c8e3ebb082360fa1a80bf7c1c34`**（`s93-fingerprints.json`，64 位，可在不信任清单内容的前提下校验清单本身）。

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
逐条 defect **0**；`fingerprint-pathset inputs=126`；无 `[advisory] declared set shrank`。n/a：access-flags（无 CLI 元数据）、clause-semantics、eh-boundary。
