# NATIVE-337 s113 提交（独立部署证据身份 + 重复键拒绝 + 四个证据变体）

- 固定候选 #445 @ 3f789d66；主干基线 c8ec2186；分支沿用 tietoumiao/native-337-s33。
- 被审证据树 head：`7c18f40da2b6ef2d74a897b0983d9d5175ca20af`；本回执为随后一次提交（仅回执与脚本节变更），最终 head 见 #13 回报。
- 保留：s109 已通过的十一项拒绝与等价布局。

## ① 重复键拒绝（不许后者覆盖）
`tool/s113_verify.py` 用 `json.loads(..., object_pairs_hook=no_dupes)`：同一对象里同名键出现两次且值不同 → 立即 `DuplicateKey`，不构造字典。实测：
```
CONFLICT file=s97-registration.json object=attachment field=duplicate_key expected=unique found=duplicate key 'signature': '2001080E' vs '20010E0E'
signature-check: conflicts=1      exit 3
```

## ② 四个新增证据变体（各自独立副本，基线 input_manifest_hash 四例一致 `2d746d3b31e45053…`）
| 变体 | object | field | 实测 | rc |
| --- | --- | --- | --- | ---: |
| InterfaceImpl 改为 `IFindComponentDriver2` | `...FindComponentDriver` | `InterfaceImpl` | `expected=IFindComponentDriver found=['IFindComponentDriver2']` | 3 |
| 单改实现命名空间 | `Other.Namespace.FindComponentDriver` | `namespace` | `expected=AspenTech.AspenPlus.WpfFindComponent found=Other.Namespace` | 3 |
| 单改 `Registry64.CLSID` | `Registry64` | `CLSID` | `expected={09DC53C4-47A0-4AE0-9422-5675D014F182} found={00000000-0000-0000-0000-000000000000}` | 3 |
| 正确行前加同键相反签名行 | `attachment` | `duplicate_key` | `expected=unique found=duplicate key 'signature': '2001080E' vs '20010E0E'` | 3 |

接口身份不再用子串：接口实现边按**完整类型名整串**比对（`ident.same_ident` 负责末段，命名空间必须逐字相等）；类型身份要求 `namespace == AspenTech.AspenPlus.WpfFindComponent`。

## ③ 独立部署输入缺失时留待核
附件 `s97-registration.json` 不存在时：`CONFLICT file=s97-registration.json object=...FindComponentDriver field=attachment expected=present found=absent`，exit 3，明确「待核」而非通过。

## ④ 活动清单与排除规则
- 清单由 `qa/mk_fingerprints.py` 重算（排除规则六条，见 `work/s109-exclusions.txt`，每条含 pattern/reason/compens）；
- `s*-audit.md` 由 `work/s109-audit-pins.txt` 反向固定（pins 在清单内）。

## ⑤ 静态审计扩展
`tool/s113_substring_audit.py` 的模式现在同时覆盖 `X in str(...)`（上一版只扫 `startswith/endswith`，被上游指出漏查 `IFACE_TYPE in str(x)`）。当前：
```
behaviour: pairs=10 conflations=0
statics: allowlisted=3 hits=0
SUITE : PASS      exit 0
```

## 判定
```
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
```
exit 2（112 条未决已申报）

## qa gate 93bf962c
```
units: pass=11 fail=0 not-applicable=3 error=0
```
exit 2；`det_semantic_rebuild`(337)：inputs_checked=6083 / compared=6083 / entries_total=6083 / ok=6081 / whitelisted=2 / mismatch=0。


## 检验器脚本

| 脚本 | 字节 | sha256 | 作用 |
| --- | ---: | --- | --- |
| `tool/s113_verify.py` | 6672 | `6b426eaf429b0d17babf9f82cab7e7845a63b1335c381d336f2e0bf9079f2175` | 交付验签入口（身份/重复键/边/签名/RVA） |
| `tool/s113_variants.py` | 3073 | `4e828c9ad5b64f85c179a15216db6c9558326c7ee2ea9a5bd2321a9417d986d6` | 四个证据变体回归 |
| `tool/s113_substring_audit.py` | 2681 | `ccfbefd094f3ba99ebfaebd6de55465aa4284dc483e2c7d85acc37976da1a61f` | 子串判等静态审计 |
| `tool/ident.py` | 2150 | `e79c0fe572dfaf07c2c24fecb40b1e8dc2777df29f4f68ce14f9c7a94d442878` | 判等唯一入口 |
| `handoff/assignments/check-native-coverage.py` | 15884 | `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8` | 上游覆盖检查器 |

版本 pin：`qa gate 93bf962c (MANIFEST files sha256 0f8be7a96e6dfa528116f28663d182b83ae60481896e1796975d27a398394c81)`；上游 checker pin `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。

```
$ python -B tool/s113_verify.py --listing --signature
listing-check: sites=2 conflicts=0
signature-check: conflicts=0
[exit 0]
```

```
$ python -B tool/s113_variants.py
impl namespace               rc=3 located=True status=PASS
    CONFLICT file=s97-registration.json object=Other.Namespace.FindComponentDriver field=namespace expected=AspenTech.AspenPlus.WpfFindComponent found=Other.Namespace
Registry64.CLSID             rc=3 located=True status=PASS
    CONFLICT file=s97-registration.json object=Registry64 field=CLSID expected={09DC53C4-47A0-4AE0-9422-5675D014F182} found={00000000-0000-0000-0000-000000000000}
duplicate signature key      rc=3 located=True status=PASS
    CONFLICT file=s97-registration.json object=attachment field=duplicate_key expected=unique found=duplicate key 'signature': '2001080E' vs '20010E0E'
input_manifest_hash identical: True
SUITE : ALL PASS
[exit 0]
```

```
$ python -B tool/s113_substring_audit.py
behaviour: pairs=10 conflations=0
statics: allowlisted=3 hits=0
SUITE : PASS
[exit 0]
```

```
$ python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original _t13/orig/FindComponent.dll --submission handoff/inbox/NATIVE-337
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
[exit 2]
```

判据 → 脚本位置：

| 判据 | 位置 |
| --- | --- |
| 完整类型身份（命名空间逐字相等） | tool/s113_verify.py::verify 第 3 段 |
| InterfaceImpl 接口实现边 | tool/s113_verify.py::verify 第 4 段 |
| 双方签名 2001080E / RVA 0 与 0xA848 | tool/s113_verify.py::verify 第 5 段 |
| 重复键拒绝 | tool/s113_verify.py::no_dupes |
| 交付表与附件一致 | tool/s113_verify.py::verify 第 6 段 |
| 子串判等回归 | tool/s113_substring_audit.py |
| 判等语义 | tool/ident.py 顶部 docstring |
## 未决（保留，逐项恢复条件）
- 动态 DISPID：GetIDsOfNames 运行时结果；恢复条件＝断点或对象实例。
- ShowDialog 实现地址：需目标机注册表展开 CLSID 或组件类型库。
- 112 条 indirect 目标：逐行按 calls.csv 的 note 中 recovery 列保留。
