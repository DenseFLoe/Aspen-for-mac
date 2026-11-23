# NATIVE-337 s105 提交（VT 三项分离 + 复验入口核三样 + 四个反例）

- 固定候选 #445 @ fa42db6；主干基线 263497c5；分支沿用 tietoumiao/native-337-s33。
- 保留：两站列表核对、实现签名单改、唯一 `variant-vt` 行、同 DLL 两处真实序号。

## ① VariantInit 三项分离（表与说明同口径）
| 项 | 结论 | 原件证据 |
| --- | --- | --- |
| `vt = VT_EMPTY` | **`VariantInit` 唯一保证** | 0x13CF `CALL [0x1800070f0]` = OLEAUT32.dll!#8 |
| **24 字节步幅** | 循环算术给出，与 VariantInit 无关 | 0x13C0–0x13DB：`LEA RCX,[RAX+RAX*2]` → `LEA RCX,[RSP+0x68+RCX*8]`（i*3*8） |
| 后续 `VT_BSTR` | **调用方所为** | 0x13DD `MOV EAX,8` → 0x13E2 `MOV word [RSP+0x68],AX`；0x13E7 `MOV [RSP+0x70],RBP` |

交付表拆成三行（`code/s81-showdialog.csv`，共 28 行）：
- 第 9 行 `variant-init`：`VariantInit guarantees ONLY vt=VT_EMPTY ... it does NOT decide the element type and does NOT decide the stride`
- **第 10 行 `variant-stride`：`element stride = 24 bytes (0x18) from the loop arithmetic at 0x13C0-0x13DB (i*3*8); stride is a property of the array walk, not of VariantInit`**
- 第 11 行 `variant-write`：`the CALLER then writes VT_BSTR (vt=8, 0x13DD/0x13E2) and union.bstrVal=RBP (0x13E7); this is caller code, not VariantInit`

## ② 交付复验入口（`tool/s101_verify.py::verify_signature`）
读三样并交叉核对：**必需附件** `s97-registration.json`、**真实交付表** `code/s81-showdialog.csv`、**独立部署元数据**（附件内的类型/方法/RVA）。按**完整类型名 + 方法名**定位 `AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver.ShowDialog`（接口侧 `...IFindComponentDriver.ShowDialog`），比较 `signature`（期望 `2001080E`）与 `rva`（实现期望 `A848`）。缺件 / 无匹配 / 矛盾 ⇒ exit 3，并输出 `file/type/member/field/expected/found`。

## ③ 四个反例（各自独立、干净输入）
每个用例：复制一份干净基线 → 只改一个字段 → 跑入口 → 记录 → 丢弃；并打印被改文件改动前/后的 sha256。

基线 `input_manifest_hash` = `07869974edd82b3ec38bf091bdf2bef7eed06419bdf77b22b48ca1fe1d7f88aa`（四个用例完全相同，只有 `mutated_file` / `mutated_field` 不同）。

| 反例 | mutated_file | before/after sha256 | 定位输出 | rc |
| --- | --- | --- | --- | ---: |
| 只改实现**名** | `s97-registration.json` | `85cffe1658e99c92` / 同 | `CONFLICT file=s97-registration.json ... member=ShowDialog field=name expected=ShowDialog found=absent` | 3 |
| 只改 **RVA** | `s97-registration.json` | `78051298bd945e47` / 同 | `CONFLICT ... field=rva expected=A848 found=B000` | 3 |
| 只改交付表 **signature** | `code/s81-showdialog.csv` | `2b5e85f24c4a702b` / 同 | `CONFLICT file=code/s81-showdialog.csv ... field=signature expected=2001080E found=20010E0E` | 3 |
| 缺注册附件 | `s97-registration.json`（删除） | – | `CONFLICT ... field=attachment expected=present found=absent` | 3 |

**第三例输出中不再出现 `rva=B000`**（脚本对第三例显式 forbid 该串，出现即判 FAIL）；三例 `input_manifest_hash` 一致、被改文件在运行前后字节不变（`after_sha == before_sha` 为 True）。
## ④ 生成器修正
`tool/s81_showdialog.py` 的 `ITEMS`：`variant-init` 只保留 vt=VT_EMPTY 语义，新增 `variant-stride`（0x13C0，24 字节）与 `variant-write`（0x13E2，调用方写 VT_BSTR）；`code/s81-showdialog.csv` 已重新生成（28 行），回执同步。

## 判定
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条未决已申报）

## qa gate 93bf962c
~~~
units: pass=11 fail=0 not-applicable=3 error=0
exit: 2
~~~
`det_semantic_rebuild`（337）：`inputs_checked=6083`、`compared=6083`、`entries_total=6083`、`skipped_data_bytes=0`、`ok=6081`、`whitelisted=2`、`mismatch=0`、`asm_error=0`。
（口径备注：340 的 `inputs_checked` 应写 **6,035**，`entries_total` 才是 6,513；不用 `total - data` 推导，以免 data 被重复扣。）

## 检验器脚本

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

**版本 pin**：`qa gate 93bf962c (MANIFEST files sha256 0f8be7a96e6dfa528116f28663d182b83ae60481896e1796975d27a398394c81)`；上游 checker pin `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。

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
L2 signature-only  : rc=3 named=False status=FAIL
    ['CONFLICT file=s97-registration.json type=AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver member=ShowDialog field=signature expected=2001080E found=20010E0E']
SUITE : FAILURES PRESENT
[exit 1]
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
$ set "PYTHONPATH=D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/.local/pylibs;D:/Lib/site-packages;D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/tool" && python -B -m qa.gate --task NATIVE-337 --item-dir "D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/handoff/inbox/NATIVE-337" --original "D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/_t13/orig/FindComponent.dll"
l2 det_access_prose         l1_covers=no      inputs=29    status=pass           defects=0   advisory=0  
       stats: {"documents_checked": 29, "mask": "0..6 MemberAccessMask"}
l2 truncated-hash           l1_covers=no      inputs=15    status=pass           defects=0   advisory=0  
       stats: {"files_scanned": 15}
l2 rebuild-semantics        l1_covers=no      inputs=6083  status=pass           defects=0   advisory=0  
       stats: {"libs": {"capstone": "5.0.7 at capstone", "keystone": "0.9.2", "capstone_path": "D:\\deepseekharness workspace\\_work\\wf-20261120-aspen-batch\\.loca
readback: path=calls.csv algo=sha256 value=e473712f657c9b1a
readback: path=coverage.csv algo=sha256 value=3afe1c2a87c9e70c
readback: path=metrics.json algo=sha256 value=72515d6a0d747a62
fingerprint: path=s101-fingerprints.json algo=sha256 note=algo=sha256 declared set shrank: 139 previous vs 109 current; dropped=['s1-submission.md',
units: pass=11 fail=0 not-applicable=3 error=0
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

- 指纹清单 **109 项**（模式排除自身/回执/manifest/gate 日志）；**清单 SHA-256：`1ad838994af62f8c8520f695235986dcb1f540ba971b587ad07e73e84a807064`**。

## 未决（保留）
动态 DISPID（GetIDsOfNames 运行时结果）、ShowDialog 实现地址（需断点/类型库）、112 条 indirect，逐行带恢复条件。
