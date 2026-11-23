# NATIVE-337 s97 提交（单条 variant-vt + 列表单改回归 + VariantInit 契约拆分 + 部署证据入表）

- 固定候选 #445 @ a6f1c16；主干基线 2cb8a177；同一分支 head 前移。
- 保留不重做：s93 的两条真实序号对照、131 项非自引用清单（本轮 137 项）、实际操作数提取。

## ① 一条 `variant-vt` 记录（不是每站一条）
| item | rva | 值 | 说明 |
| --- | --- | --- | --- |
| `variant-vt` | 0x13DD | `vt immediate 8` | `vt` **只是类型标记**（8 = VT_BSTR），来自 0x13DD `MOV EAX,8` / 0x13E2 `MOV word [RSP+0x68],AX`；与 24 字节步幅是两回事 |

表中 `variant-vt` 出现次数 = **1**（自检：`variant-vt count 1`，全表 22 行）。逐站列表 vs 固定原件核对：该行 `listing=b808000000 original=b808000000 listing_matches=yes`。

## ② 两个回归：**只改列表、原件不变**
| 回归 | 列表单改 | 字段变化 |
| --- | --- | --- |
| A `0x13DD` | `B8 08 00 00 00` → `B8 09 00 00 00` | `variant-vt`：`listing_matches=yes` → **`no`**（PASS） |
| B `0x137F` | rip 偏移 `72 6F 00 00` → `62 6F 00 00` | `calls-riid`：`listing_matches=yes` → **`no`**（PASS） |
原件字节全程未改（脚本 `tool/s97_regressions.py` 只改列表副本），证明检测链读的是列表内容而不是原件缓存。`SUITE : ALL PASS`。

## ③ `VariantInit` 契约：两件事分开写
| 项 | 值 | 出处 |
| --- | --- | --- |
| 调用 | OLEAUT32.dll!#8 = VariantInit | 0x13CF `CALL [0x1800070f0]` |
| **vt（类型标记）** | 8 = VT_BSTR，16 位字段 | 0x13DD `MOV EAX,8` → 0x13E2 `MOV word [RSP+0x68],AX` |
| **元素步幅** | **0x18 = 24 字节**（sizeof(VARIANT) on x64），与 vt 无关 | 循环 0x13C0–0x13DB：`LEA RCX,[RAX+RAX*2]` → `LEA RCX,[RSP+0x68+RCX*8]` |
| 数组范围 | 基址 `[RSP+0x68]`，计数 `[RSP+0x60]` 低 dword（cArgs=1） | 0x13AC / 0x13A7 |
| 联合体 | `union.bstrVal = RBP` | 0x13E7 `MOV [RSP+0x70],RBP` |
| 清理 | 0x1457 Release → 0x1463 OLEAUT32!#9 VariantClear(pVarResult) → 0x1469 `MOV EAX,ESI`（int，低 32 位） | 逐址 |

即：**vt 决定“是什么类型”，0x18 决定“下一个元素从哪开始”**；VariantInit 只负责把 24 字节置 VT_EMPTY，不决定类型，也不决定步幅。

## ④ 上游 `s85-registration.json` 作为部署证据入表
已复制为 `handoff/inbox/NATIVE-337/s97-registration.json`（2,767 B，上游原件），并写入交付表三行：
| item | 值 | 来源字段 |
| --- | --- | --- |
| `deploy-clsid` | `{09DC53C4-47A0-4AE0-9422-5675D014F182}` | Registry64.CLSID（server mscoree.dll） |
| `deploy-assembly-sha256` | `04E68B8ECA60B732E661BF322D74B6F042ABEBA9EA801E2E2E410C1BE007B5D5` | PE.sha256（assembly 41.0.0.614） |
| `deploy-signature` | `PublicKeyToken=null`（无强名称签名，PE sha256 即部署签名） | Registry64.assembly |
三者 + ProgID（0x78A8 字节串）共同构成同安装部署证据；动态 DISPID 继续保留为未决。

## 判定
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条未决已申报）

## qa gate 27007e5a
~~~
units: pass=10 fail=0 not-applicable=3 error=0
exit: 2
~~~
逐条 defect **0**；`omitted-sites inputs=363 (prefixed_thunks 10)`；`fingerprint-pathset inputs=137`；无 `[advisory] declared set shrank`。n/a：access-flags（无 CLI 元数据）、clause-semantics、eh-boundary。

## 指纹
- 清单 `s97-fingerprints.json` **139 项**，排除自身与本回执（生成两次哈希稳定）。
- **清单 SHA-256：`209196a383cc67b1cf64d5516f40789382a8638159394c01797fb7b3201a8e84`**
