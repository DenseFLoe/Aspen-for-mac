# NATIVE-337 s101 提交（产品路径拒绝矛盾列表 + 身份字段三类 + 签名单改反例）

- 固定候选 #445 @ ff5aa8a；主干基线 54d8dd1d；同一分支 head 前移。
- 保留：两站 `listing_matches`、唯一 `variant-vt` 行、同 DLL 两条真实序号；指纹清单本轮 **147 项**（同类口径，仍排除自身与本回执）。
- **清单 SHA-256：`8fb74634766478e0eeb52621f75c3af3dc36e7a266d0c454a9a6ed9b97d75667`**

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
逐条 defect 0；`omitted-sites 363（prefixed_thunks 10）`；`fingerprint-pathset 147`；无 advisory。

## 检验器脚本

> 路径分两类：**分支树内（该 head 可读到）可作证据**；**本地工作区（未入库）不得作证据**，只能作复现说明。本节由 `tool/s101_receipt_section.py` 逐文件向分支树校验后生成，并已删掉此前误列的 12,416 B 本地旧副本（该副本已被分支版替换，本地现为 15,884 B / `27f643b9…`）。

分支树内（该 head 可读到，可作证据）：

| 脚本 | 字节 | sha256 | 作用 |
| --- | ---: | --- | --- |
| `tool/s101_verify.py` | 3091 | `e75b4bc0ec591f8a35f4b3c4cc69c3088d547d90ab94b6ba251ef671a4a9252d` | 交付校验入口：拒绝矛盾列表/签名 |
| `tool/s101_counters.py` | 2559 | `3eb7093b1f945b693b4c597c616ce9427c56e72d457d82eaeb05d970083c623d` | 回归脚本：列表单改 + 签名单改反例 |
| `tool/s97_regressions.py` | 2712 | `889ace2b07508f325ea1e8fa07c1d5f5eca2060ac66b519c1a494b2248123e4f` | 列表单改回归（s97 口径） |
| `tool/s93_counters.py` | 3586 | `e0f099c5927aa434d1e34c392662bbb6d5b9708b89bcff75c12abae80f7af2f6` | 字节单改反例（二进制口径） |
| `tool/s81_showdialog.py` | 9431 | `6eb33d8d00d6fb8efcf83f49be1604102eee5afd4b9532fb729e9cae3ee2abc2` | ShowDialog 绑定/参数表生成器 |
| `tool/s37_two_hop.py` | 6131 | `6edacdbdac9a8a5e851a720f217057c0a34d60b6b00d68a90d1c5a851cf8d4dd` | 161 条二跳表生成器 |
| `tool/s65_counterexamples.py` | 9564 | `26a94ce2c081fe4a2e838354993e2ebcbf74f4be9be98e7ef258aaf921d01cfa` | 四类反例分类器（FF /4 判型入口） |
| `tool/s73_stations.py` | 3200 | `0bc2d114e359ba8d3557071ac10f053be93220eaee2929f2e1af4a239cc8e319` | 原件独立站集导出 |
| `tool/s69_tests.py` | 5828 | `68e6140848e2c9acd73556cbb16e6f7f4bbfc443fa713a5d101e0be29bdc3743` | T1–T6 回归（s65 入口） |
| `tool/s45_tests.py` | 8496 | `4e5a3401d1048b525016aaa13283d3db416e43746fbcd7d4108aaec8f22c0371` | 六场景 + 三布局回归 |
| `handoff/assignments/check-native-coverage.py` | 15884 | `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8` | 上游覆盖检查器（分支内副本） |

本地未入库（只在本机工作区出现，**不参与判据**）：

（无）

**版本 pin**：`qa gate 27007e5a (MANIFEST files sha256 3779de81a322579c91adfbf5b960f8a16543973d87ca97e92eca117d67b65089)`；上游 checker pin `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。

命令与原始输出（stdout 原文，exit 为真实值）：

```
$ python -B tool/s101_verify.py --listing --signature
listing-check: sites=2 conflicts=0
signature-check: conflicts=0
[exit 0]
```

```
$ python -B tool/s101_counters.py
L1 000013DD listing-only : rc=3 named=True status=PASS
    ['CONFLICT site=0x13DD kind=listing-mismatch original=b808000000 listing=b809000000']
L1 0000137F listing-only : rc=3 named=True status=PASS
    ['CONFLICT site=0x137F kind=listing-mismatch original=488d15726f0000 listing=488d15626f0000']
L2 signature-only  : rc=3 named=True status=PASS
    ['CONFLICT site=FindComponentDriver.ShowDialog kind=implementation expected=2001080E found=20010E0E', 'CONFLICT site=signature disagreement kind=iface-vs-impl expected=2001080E found=20010E0E']
SUITE : ALL PASS
[exit 0]
```

```
$ python -B tool/s97_regressions.py
base  : variant-vt listing_matches=yes | calls-riid listing_matches=yes
A listing-only vt 8->9   : listing_matches=yes -> listing_matches=no status=PASS
B listing-only riid disp : listing_matches=yes -> listing_matches=no status=PASS
SUITE : ALL PASS
[exit 0]
```

```
$ set PYTHONPATH=D:/Lib/site-packages && python -B tool/s65_counterexamples.py
sites 161 categories {'ok': 161}
[exit 0]
```

```
$ python -B tool/s37_two_hop.py --folder handoff/inbox/NATIVE-337 --binary _t13/orig/FindComponent.dll --out work/s101-two-hop.csv
rows 161; discovered_from_listing=161; ambiguous_calls_row=0; missing_listing_ref=0
[exit 0]
```

```
$ python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original _t13/orig/FindComponent.dll --submission handoff/inbox/NATIVE-337
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
[exit 2]
```

```
$ set "PYTHONPATH=D:/Lib/site-packages;D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/tool" && python -B -m qa.gate --task NATIVE-337 --item-dir "D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/handoff/inbox/NATIVE-337" --original "D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/_t13/orig/FindComponent.dll"
       stats: {"skipped": "no EH clauses decoded from the original"}
l2 eh-boundary              l1_covers=no      inputs=0     status=not-applicable defects=0   advisory=0  
       stats: {"boundary_tables": 0, "rows_checked": 0}
l2 det_access_prose         l1_covers=no      inputs=28    status=pass           defects=0   advisory=0  
       stats: {"documents_checked": 28, "mask": "0..6 MemberAccessMask"}
l2 truncated-hash           l1_covers=no      inputs=15    status=pass           defects=0   advisory=0  
       stats: {"files_scanned": 15}
readback: path=calls.csv algo=sha256 value=e473712f657c9b1a
readback: path=coverage.csv algo=sha256 value=3afe1c2a87c9e70c
readback: path=metrics.json algo=sha256 value=72515d6a0d747a62
units: pass=10 fail=0 not-applicable=3 error=0
exit: 2
[exit 2]
```

**判据 → 脚本位置**

| 判据 | 脚本/函数 |
| --- | --- |
| 列表与原件逐字节一致（0x13DD / 0x137F） | `tool/s101_verify.py::verify_listing` |
| 接口/实现/声明签名一致（2001080E） | `tool/s101_verify.py::verify_signature` |
| 绑定依据来自字节（ProgID/名字/IID/vt） | `tool/s81_showdialog.py::binding_rows` |
| 唯一 `variant-vt` 行 + stride 与 vt 分离 | `tool/s81_showdialog.py` 表行 `variant-vt` |
| 161 站与 calls_row 关联 | `tool/s37_two_hop.py::main`（row_for） |
| 四类反例分类 | `tool/s65_counterexamples.py::main` |
| 站集独立导出 | `tool/s73_stations.py::derive` |

## 未决（保留）
动态 DISPID（GetIDsOfNames 运行时结果）、ShowDialog 的实现地址（需断点或类型库）、其余 112 条 indirect 未决，逐行带恢复条件。
