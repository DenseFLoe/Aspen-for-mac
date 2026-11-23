# NATIVE-340 s101 提交

- 分支：tietoumiao/native-340-s33；上轮 `38b6814d`，主干 44c22e3d
- 本轮 head：见 #13

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

版本 pin：qa gate 93bf962c (MANIFEST files sha256 0f8be7a96e6dfa528116f28663d182b83ae60481896e1796975d27a398394c81)。
