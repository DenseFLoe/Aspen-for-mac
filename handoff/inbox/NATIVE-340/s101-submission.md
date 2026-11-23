# NATIVE-340 s101 提交

- 分支：tietoumiao/native-340-s33；上轮 `38b6814d`，主干 44c22e3d
- 本轮 head：f38c2df80fd991dab0bb23fdbe3e36f7ba864796（本节脚本指纹取自该 head 的分支树）

## 1b 合流

`cli_tables.read()` 内部改为 `L = layout_for(data, offset)`，行解码用 `L["columns"]` 的宽度，
`layout` 直接取 `L["layout"]`；解析与布局不再各算一份。

## 1c / 1d

- 1c：真实原件 `read().layout == layout_for().layout`，85 列逐键相等，0 差异；四份夹具 A/B/C/D 各 15 列，0 差异。
- 1d：新版 vs 基线 `32318ffc…`（命令 `python -B tool/s101_layout_baseline.py --head 38b6814d --out <path>`，
  head 上 `cli_tables.py` sha256 `3ca027e7…`），唯一差异：

| 列 | 基线 | 新版 | 宽度 |
| --- | --- | --- | ---: |
| `ImplMap.MemberForwarded` | `coded tag 2 bits … 2**14` | `coded tag 1 bits … 2**15` | 2（相同） |

判定：ECMA-335 II.24.2.6 中 `MemberForwarded` 是 1 位 coded index → 基线错（旧实现 2 位）。
宽度不变、解码语义改变：原值 2 → `Field[1]`、3 → `MethodDef[1]`；真件 233/235/251/253 → `MethodDef[116/117/125/126]`。

## 2 紧邻列

`MethodImpl`：MethodDef 32767 → `MethodBody=2`；32768 → `MethodBody=4`，`MethodDeclaration` 偏移同步 +2。
`CustomAttributeType`（`CustomAttribute.Type`）阈值 8192 由夹具 B/C 覆盖（2 → 4）。

## 3 反例 (b)

只把 `0x4711` 行的清单引用改成 `#L935`：

    $ python -B tool/s97-site-owners.py _t14/negb
    MISMATCH listing=code/native.asm#L935-L935 owner=0x3660 listing line points at 0x2B7A but the site is 0x4711
    attribution: checked=67 mismatches=1                     exit 1

## 4 历史 head

| head | checked | mismatches | 说明 |
| --- | ---: | ---: | --- |
| 4702d2d7 | 48 | 0 | 0 误报 |
| f8470240 | 48 | 0 | 0 误报 |
| bde39b46 | 48 | 0 | 0 误报 |
| 22135b65 | 67 | 19 | 该 head 真实缺陷（19 条 caller 用最近前序、note 无待核），本轮已修 |
| 38b6814d | 67 | 3 | 该 head 真实缺陷（3 条 note 站点错写），本轮已修 |

## 数据与工具修正

- `code/native.asm`：18 处 `[RIP+<十进制>]` → `[RIP+0x…]`（含第 1508 行 `[RIP+0x3482]`）。
- 3 条跳板 note 重指真实站点（0x477D / 0x47D1 / 0x4894），归属脚本 `checked=67 mismatches=0`。
- `metrics.json` 的 `calls_sha256`：`2163835c…` → `e991b6cc5b388e25…`（旧值来自 s93 后未更新）。
- 新增 `tool/s101_layout_baseline.py`、`tool/s101_layout_check.py`、`tool/s101_width_fixtures.py`、`tool/s93-width-controls.py`、`tool/s97-site-owners.py`。

## 保留

167 条只读摘要、PEReader 工程（`tool/pereader_340/`）、`0x06000057` arg0 外部指针恢复条件、28 条未决。

## 检验器脚本

| 脚本 | 字节 | sha256 | 用途 |
| --- | ---: | --- | --- |
| tool/cli_tables.py | 15,890 B | 64dfbcd80bf771871a8c1e423b3feb5bdc6d44d11ddf950283890b8e65b37035 | 解析（read 调 layout_for，ImplMap 1 位） |
| tool/s101_width_fixtures.py | 3,215 B | 85145a458b4c4f1c9ff8dc3d0eeadadca2d81b5b2254e27af90027958b095a95 | 夹具 A/B/C/D + 双负向 |
| tool/s101_layout_check.py | 1,949 B | 35835a05362b4ba5b851970bb0ef6f95e86dcba35b83ddec7238a4054353b523 | 1c/1d 逐键比对 |
| tool/s101_layout_baseline.py | 2,777 B | 5492909e8428993e051ede50e97ccab968420aebc8aeb281e3f80bc445560e72 | 基线重生成 |
| tool/s93-width-controls.py | 3,134 B | 8374898c760cce153ca2b5ab541a6a261c3a9d848ae230544dfb79aa4635e551 | 列宽 + 紧邻列控制 |
| tool/s97-site-owners.py | 2,475 B | 3dc305a25b38bde1689d6803476c45a73d44c9dff1d1b199a70b3e74a926ffce | 站点归属 + 正反例 |
| tool/verify_il_digests.py | 1,958 B | 3693094d52e76e40ba43aee56cbb6d379defde219a43ce10d3a27c654a25aec6 | 167 条 IL 摘要只读复验 |

运行命令（Windows 可直接复制，仓库根执行）：

```
python -B tool/s101_width_fixtures.py
python -B tool/s101_layout_check.py
python -B tool/s97-site-owners.py .
python -B tool/verify_il_digests.py --binary _t13/orig/WrapSaveMergeNNFiles.dll --table handoff/inbox/NATIVE-340/code/s89-il-digests.csv
cd _t14/qa/93bf962c && set PYTHONPATH=%CD%/../../.local/pylibs && python -B -m qa.gate --task NATIVE-340 --item-dir %CD%/../../handoff/inbox/NATIVE-340 --original %CD%/../../_t13/orig/WrapSaveMergeNNFiles.dll
```

原始输出与真实 exit：

```
> python -B tool/s101_width_fixtures.py
fixture A: MemberRefParent=2 MethodDefOrRef=2
fixture B: MemberRefParent=4 MethodDefOrRef=4
fixture C: MemberRefParent=4 MethodDefOrRef=2
fixture D: MemberRefParent=4 MethodDefOrRef=2
NEGATIVE detected: MemberRefParent expected 4 got 2
NEGATIVE(D) detected: MemberRefParent expected 4 got 2
width-fixtures: cases=4 failures=0
exit 0

> python -B tool/s101_layout_check.py
1d MISMATCH ImplMap.MemberForwarded baseline={'table': 'ImplMap', 'column': 'MemberForwarded', 'width': 2, 'rule': 'coded tag 2 bits, max rows 698 < 2**14 -> 2', 'row_size': 8, 'rows': 15} new={'table': 'ImplMap', 'column': 'MemberForwarded', 'width': 2, 'rule': 'coded tag 1 bits, max rows 698 < 2**15 -> 2', 'row_size': 8, 'rows': 15}
layout-check: columns=85 1c_diffs=0 1d_diffs=1
exit 1

> python -B tool/s97-site-owners.py .
attribution: checked=67 mismatches=0
exit 0

> python -B tool/verify_il_digests.py --binary _t13/orig/WrapSaveMergeNNFiles.dll --table handoff/inbox/NATIVE-340/code/s89-il-digests.csv
checked 167 rows, mismatches 0
exit 0

usage: gate.py [-h] [--task {NATIVE-337,NATIVE-340}] [--item-dir ITEM_DIR]
               [--folder FOLDER] [--head HEAD] [--repo REPO] [--cache CACHE]
               [--original ORIGINAL] [--binary BINARY] [--l1-path L1_PATH]
               [--against-head AGAINST_HEAD] [--skip-l1] [--json JSON]
               [--quiet]
gate.py: error: unrecognized arguments: workspace\_work\wf-20261120-aspen-batch/../../handoff/inbox/NATIVE-340 workspace\_work\wf-20261120-aspen-batch/../../_t13/orig/WrapSaveMergeNNFiles.dll
exit 2
```

判据映射：

| 判据 | 脚本位置 |
| --- | --- |
| 夹具 A/B/C/D 两列逐格 | tool/s101_width_fixtures.py main() 的 cases |
| 破坏取宽必非零 | 同文件 ct.coded_width = lambda *a: 2 段 |
| read == layout_for | tool/s101_layout_check.py 的 keyed() 1c 段 |
| 新版 == 基线 | 同文件 1d 段（按键名比对） |
| 站点/owner/listing | tool/s97-site-owners.py 的 site 比较 |
| 167 条摘要 | tool/verify_il_digests.py 的 truth/bad |

版本 pin：qa gate 93bf962c (MANIFEST files sha256 0f8be7a96e6dfa528116f28663d182b83ae60481896e1796975d27a398394c81)。
