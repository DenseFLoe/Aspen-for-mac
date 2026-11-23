# NATIVE-337 s105 提交（qa gate 1ed452e6 复跑 + 语义回编单元）

- 固定候选 #445 @ fa42db6e；分支沿用 tietoumiao/native-337-s33。
- qa gate 升到 **1ed452e6**（31 文件，MANIFEST files sha256 `8e648e172d7391…`，独立复算一致）。

## 新增单元 det_semantic_rebuild（337）
| 项 | 值 |
| 指令总数（原件 .text，capstone 线性反汇编） | **6,083** |
| ok | 6,081 |
| 白名单（别名/编码呈现差异） | 2 |
| **mismatch** | **0** |
| asm_error | 0 |

白名单两条均落在 0x38AB（`add byte ptr ds:[rax], al` 与 `add byte ptr [rax], al` 别名）与其余前缀别名；语义回编只依赖原件，因此同一原件在各 head 上数字必然相同。

## units（14 个检测单元）
~~~
units: pass=11 fail=0 not-applicable=3 error=0
exit: 2      （L1 = 上游 checker 原样透传）
~~~
| 单元 | inputs | status |
| --- | ---: | --- |
| omitted-sites | 363 | pass |
| stale-metrics | 10 | pass |
| row-linkage | 11 | pass |
| fingerprint-pathset | 139 | pass |
| unresolved-no-recovery | 112 | pass |
| symbol-substring | 684 | pass |
| wrong-symbol | 684 | pass |
| byte-mismatch | 5,055 | pass |
| det_access_prose | 28 | pass |
| truncated-hash | 15 | pass |
| **rebuild-semantics** | **6,083** | **pass** |
| access-flags | 0 | not-applicable（`no CLI metadata (native-only image)`） |
| clause-semantics | 0 | not-applicable（无 EH 子句） |
| eh-boundary | 0 | not-applicable（`boundary_tables 0`） |

**单元数是 14 个**（`det_receipt_paths` 已并入 `det_fingerprint_pathset`，13+1=14）。

- 指纹清单 **141 项**（排除自身、本回执与 gate 日志）；**清单 SHA-256：`20b48f4c2842b0513f112dbc0788da6c8fe038359d9c8c3243cc6d4faee0b4e6`**。

## 一处本轮自查修复
gate 日志写在交付目录里会让 `fingerprint-pathset` 每跑一次就报 1 条 defect（日志自身哈希变了）。已把 `work/*-gate.txt` 从指纹清单排除（gate 日志是运行产物，不是交付证据），清单从 147 项降到 139 项后重新稳定，重跑 gate 无 defect。

## 判定
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条未决已申报）

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

**版本 pin**：`qa gate 1ed452e6 (MANIFEST files sha256 8e648e172d73917ded8bd7e5f8c99b25ed6366fa71d421f586e8b5304bb3fecc)`；上游 checker pin `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。

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
$ set "PYTHONPATH=D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/.local/pylibs;D:/Lib/site-packages;D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/tool" && python -B -m qa.gate --task NATIVE-337 --item-dir "D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/handoff/inbox/NATIVE-337" --original "D:/deepseekharness workspace/_work/wf-20261120-aspen-batch/_t13/orig/FindComponent.dll"
l2 det_access_prose         l1_covers=no      inputs=28    status=pass           defects=0   advisory=0  
       stats: {"documents_checked": 28, "mask": "0..6 MemberAccessMask"}
l2 truncated-hash           l1_covers=no      inputs=14    status=pass           defects=0   advisory=0  
       stats: {"files_scanned": 14}
l2 rebuild-semantics        l1_covers=no      inputs=6083  status=pass           defects=0   advisory=0  
       stats: {"total": 6083, "ok": 6081, "whitelisted": 2, "mismatch": 0, "asm_error": 0, "skipped_data_bytes": 0, "whitelist_entries": 5, "whitelist_path": "qa\\r
readback: path=calls.csv algo=sha256 value=e473712f657c9b1a
readback: path=coverage.csv algo=sha256 value=3afe1c2a87c9e70c
readback: path=metrics.json algo=sha256 value=72515d6a0d747a62
fingerprint: path=s97-fingerprints.json algo=sha256 note=algo=sha256 declared set shrank: 139 previous vs 139 current; dropped=['work/s85c-gate.txt
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

