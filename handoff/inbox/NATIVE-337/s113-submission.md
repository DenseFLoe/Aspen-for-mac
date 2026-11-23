# NATIVE-337 s113 提交（独立部署证据身份 + 重复键拒绝 + 四个证据变体）

- 固定候选 #445 @ 3f789d66；主干基线 c8ec2186；分支沿用 tietoumiao/native-337-s33。
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

## 未决（保留，逐项恢复条件）
- 动态 DISPID：GetIDsOfNames 运行时结果；恢复条件＝断点或对象实例。
- ShowDialog 实现地址：需目标机注册表展开 CLSID 或组件类型库。
- 112 条 indirect 目标：逐行按 calls.csv 的 note 中 recovery 列保留。
