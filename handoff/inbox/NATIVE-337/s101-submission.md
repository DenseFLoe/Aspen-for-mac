# NATIVE-337 s101 提交（产品路径拒绝矛盾列表 + 身份字段三类 + 签名单改反例）

- 固定候选 #445 @ ff5aa8a；主干基线 54d8dd1d；同一分支 head 前移。
- 保留：两站 `listing_matches`、唯一 `variant-vt` 行、同 DLL 两条真实序号；指纹清单本轮 **145 项**（同类口径，仍排除自身与本回执）。
- **清单 SHA-256：`c841851c0e9f4b7f87980886a7a7c092e15b2f4fc7ca907d0e0e6684c0b52037`**

## ① 产品路径拒绝矛盾列表（不是测试脚本）
新增正式复验入口 **`tool/s101_verify.py`**（交付产物用它校验，`s97_regressions.py` 只是回归脚本）：
~~~
python -B tool/s101_verify.py --folder handoff/inbox/NATIVE-337 --binary _t13/orig/FindComponent.dll --listing --signature
listing-check: sites=2 conflicts=0
signature-check: conflicts=0
~~~
单改列表后（原件不变）实际输出：
~~~
CONFLICT site=0x13DD kind=listing-mismatch original=b808000000 listing=b809000000
CONFLICT site=0x137F kind=listing-mismatch original=488d15726f0000 listing=488d15626f0000
~~~
两条都 exit 3 并点名站点（`tool/s101_counters.py` L1 两条 PASS）。

## ② `VariantInit` 契约再收窄（表与回执同口径）
| 项 | 结论 |
| --- | --- |
| `VariantInit` 保证什么 | **仅 `vt = VT_EMPTY`**（把 `[RSP+0x68]` 起 24 字节清零） |
| 不保证什么 | 不决定类型、不决定步幅 |
| 原件实际步幅 | **24 字节（0x18）**，来自 0x13C0–0x13DB 的循环算术 |
| 后续写入 | **`VT_BSTR`**（0x13E2 vt=8）与 `union.bstrVal=RBP`（0x13E7） |

## ③ 三类身份字段（分开列）
| 类别 | 值 |
| --- | --- |
| PE 身份指纹 | 原件 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`；部署程序集 `04E68B8ECA60B732E661BF322D74B6F042ABEBA9EA801E2E2E410C1BE007B5D5` |
| 强名称字段 | `PublicKeyToken=null`（无强名称签名） |
| 接口/实现 `int32 ShowDialog(string)` 签名 | **`2001080E`**（二元签名：1 个参数、返回 int32） |

RVA 核对：接口 `IFindComponentDriver.ShowDialog` = **rva 0**（abstract，无实现体）；实现 `FindComponentDriver.ShowDialog` = **rva 0xA848**；类 `FindComponentDriver`（TypeDef，registration 未给类级 RVA）、接口 `IFindComponentDriver`（TypeDef）。签名与 RVA 均来自 `s97-registration.json` 的元数据字段。
交付表新增 4 行：`id-pe-assembly-sha256` / `id-strong-name` / `id-sig-interface` / `id-sig-impl`（表共 26 行）。

## ④ 只改实现签名的反例
原件与部署程序集都不动，只把 registration 副本里 `FindComponentDriver.ShowDialog.signature` 改成 `20010E0E`，并更新受影响指纹：
~~~
CONFLICT site=FindComponentDriver.ShowDialog kind=implementation expected=2001080E found=20010E0E
CONFLICT site=signature disagreement kind=iface-vs-impl expected=2001080E found=20010E0E
~~~
exit 3 —— 定位到实现并标记接口/实现不一致，**不是静默通过**（`tool/s101_counters.py` L2 PASS）。

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
逐条 defect 0；`omitted-sites 363（prefixed_thunks 10）`；`fingerprint-pathset 145`；无 advisory。

## 未决（保留）
动态 DISPID（GetIDsOfNames 运行时结果）、ShowDialog 的实现地址（需断点或类型库）、其余 112 条 indirect 未决，逐行带恢复条件。
