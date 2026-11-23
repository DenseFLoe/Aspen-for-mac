# NATIVE-337 s117 提交（CLSID→class→TypeDef/InterfaceImpl→ShowDialog 全链 + 四组反例）

- 固定候选 #445 @ 7c18f40d；分支沿用 tietoumiao/native-337-s33。
- 保留：s113 的十五项拒绝与两个正组。

## ① 链路核对（`tool/s117_verify.py`）
`CLSID → Registry64.class → TypeDef(namespace+type) → InterfaceImpl → ShowDialog(签名/RVA)`，每级都对独立附件与交付表交叉核对：
| 环节 | 判据 |
| --- | --- |
| CLSID | `Registry64.CLSID == {09DC53C4-47A0-4AE0-9422-5675D014F182}` |
| class | `Registry64.class == AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver`（逐字） |
| 完整类型 | namespace 逐字相等（不是前缀） |
| InterfaceImpl | 边必须**整串且大小写一致**等于 `IFindComponentDriver`（.NET 类型名区分大小写） |
| ShowDialog | 接口签名 `2001080E`/RVA `0`；实现签名 `2001080E`/RVA `0xA848`（数值比较） |
| 交付表 | 签名与 RVA 与附件一致；**CSV 同键重复行拒绝** |

## ② 四组新增反例（各自独立副本，基线 `input_manifest_hash = 8be1e7c0ecc1093a…` 四例一致）
| 组 | object | field | 实测 | rc |
| --- | --- | --- | --- | ---: |
| A 矛盾重复 CSV 行 | `id-sig-impl` | `duplicate_row` | `expected=unique found=duplicate row 'id-sig-impl'` | 3 |
| B 错误注册 class | `Registry64` | `class` | `expected=...FindComponentDriver found=...OtherDriver` | 3 |
| C 裸接口小写 | `...FindComponentDriver` | `InterfaceImpl` | `expected=IFindComponentDriver found=['ifindcomponentdriver']` | 3 |
| D 缺独立签名输入 | `...IFindComponentDriver.ShowDialog` | `signature` | `expected=2001080E found=None`（明确待核，不猜） | 3 |

## ③ 清单项数说明（109 vs 110）
最终 **109 项**，`SHA-256 = 4b01f6046cbb6d8f5e7d606e393a8ed217fd417562c7f3bb9d10e3b4c3995e9e`（与 s113 完全相同）。逐项核对：
```
total 109
pins in manifest: True
audit pages in manifest: []
by dir Counter({'work': 45, '(root)': 34, 'code': 30})
```
原因：`work/s109-audit-pins.txt` **在生成 s113 清单之前就已存在**，因此它早就在那 109 项里，没有新增；而 `s113-substring-audit.md` 被 `s*-audit.md` 规则排除、由 pins 反向固定（不在清单里）。所以「109 → 110」的预期不成立：两轮清单相同，逐键 diff 为空。

## ④ 判定
```
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
```
exit 2（112 条未决已申报）。

## ⑤ qa gate 93bf962c
```
units: pass=11 fail=0 not-applicable=3 error=0
```
exit 2；`det_semantic_rebuild`(337)：inputs_checked=6083 / compared=6083 / entries_total=6083 / ok=6081 / whitelisted=2 / mismatch=0。


## 检验器脚本

| 脚本 | 字节 | sha256 | 作用 |
| --- | ---: | --- | --- |
| `tool/s117_verify.py` | 7577 | `0069dc3a8237f5550ccf9cf4db8715d0832bd4decfaf7de805a9bd739fa6259e` | 交付验签入口（CLSID/class/类型/边/签名/RVA/CSV 重复行） |
| `tool/s117_variants.py` | 3657 | `5629cef61d56b63719ae276b086e0b0e44aa65dab74b1c80fc75a61e0a02fb93` | s117 四组反例回归 |
| `tool/s113_verify.py` | 6672 | `6b426eaf429b0d17babf9f82cab7e7845a63b1335c381d336f2e0bf9079f2175` | s113 验签入口（保留） |
| `tool/ident.py` | 2150 | `e79c0fe572dfaf07c2c24fecb40b1e8dc2777df29f4f68ce14f9c7a94d442878` | 判等唯一入口 |
| `handoff/assignments/check-native-coverage.py` | 15884 | `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8` | 上游覆盖检查器 |

版本 pin：`qa gate 93bf962c (MANIFEST files sha256 0f8be7a96e6dfa528116f28663d182b83ae60481896e1796975d27a398394c81)`；上游 checker pin `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。

```
$ python -B tool/s117_verify.py --listing --signature
listing-check: sites=2 conflicts=0
signature-check: conflicts=0
[exit 0]
```

```
$ python -B tool/s117_variants.py
A duplicate CSV row          rc=3 located=True status=PASS
    CONFLICT file=code/s81-showdialog.csv object=id-sig-impl field=duplicate_row expected=unique found=duplicate row 'id-sig-impl'
B wrong registry class       rc=3 located=True status=PASS
    CONFLICT file=s97-registration.json object=Registry64 field=class expected=AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver found=AspenTech.AspenPlus.WpfFindComponent.OtherDriver
C bare iface lowercase       rc=3 located=True status=PASS
    CONFLICT file=s97-registration.json object=AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver field=InterfaceImpl expected=IFindComponentDriver found=['ifindcomponentdriver']
D missing signature input    rc=3 located=True status=PASS
    CONFLICT file=s97-registration.json object=AspenTech.AspenPlus.WpfFindComponent.IFindComponentDriver.ShowDialog field=signature expected=2001080E found=None
input_manifest_hash identical: True
SUITE : ALL PASS
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
| CLSID / class 身份 | tool/s117_verify.py::verify 第 1、1b 段 |
| 完整类型（namespace 逐字） | 第 3 段 |
| InterfaceImpl 大小写敏感整串 | 第 4 段 |
| 签名与 RVA（数值） | 第 5 段 |
| CSV 同键重复行拒绝 | 第 6 段 |
| 附件重复键拒绝 | tool/s117_verify.py::no_dupes |
## 未决（保留）
动态 DISPID、112 条 indirect 目标，各自按 calls.csv note 的 recovery 条件保留。
