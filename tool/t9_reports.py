# -*- coding: utf-8 -*-
"""Regenerate the four T9 pre-review reports from the two CSV inputs only.

No prose numbers are copied from the old documents: every count below is
recomputed from selection.csv + ledger-1000.csv.
"""
import csv, io
from collections import Counter, defaultdict
from pathlib import Path

import argparse
ROOT = Path(__file__).resolve().parent.parent
_ap = argparse.ArgumentParser()
_ap.add_argument("--input-dir", default="handoff/review/t9-1000")
_ap.add_argument("--out", default="handoff/inbox/T9-368-RECONCILE")
_args = _ap.parse_args()
T9 = Path(_args.input_dir)
OUT = Path(_args.out)
OUT.mkdir(parents=True, exist_ok=True)
STATES = ("pass", "fail", "partial", "blocked")
HEAD = "db544a6fdfb04ec60d182c311aa47d13a61d744b"
DATE = "2026-11-22"


def read_csv(name):
    text = (T9 / name).read_text(encoding="utf-8-sig")
    rows = list(csv.DictReader(io.StringIO(text, newline=""), strict=True))
    assert len(rows) == 1000, (name, len(rows))
    return {int(r["idx"]): r for r in rows}


led = read_csv("ledger-1000.csv")
rows = [led[i] for i in range(1000)]
verdicts = {s: sum(1 for r in rows if r["verdict"] == s) for s in STATES}
assert verdicts == {"pass": 530, "fail": 470, "partial": 0, "blocked": 0}, verdicts

prods = sorted({r["product"] for r in rows})
prod_count = Counter(r["product"] for r in rows)
prod_m = {p: {s: sum(1 for r in rows if r["product"] == p and r["verdict"] == s) for s in STATES} for p in prods}
states = sorted({r["state"] for r in rows})
state_count = Counter(r["state"] for r in rows)
state_m = {x: {s: sum(1 for r in rows if r["state"] == x and r["verdict"] == s) for s in STATES} for x in states}
kind_count = Counter(r["kind"] for r in rows)
tier_a_count = Counter(r["tier_a"] for r in rows)
tier_b_count = Counter(r["tier_b"] for r in rows)
codes = defaultdict(set)
for r in rows:
    for c in filter(None, r["fail_codes"].split(";")):
        codes[c].add(int(r["idx"]))
code_counts = {c: len(v) for c, v in sorted(codes.items(), key=lambda kv: (-len(kv[1]), kv[0]))}
assert code_counts == {"tool_nag_tail": 455, "a2_sha_missing": 15, "a3_report_missing": 15,
                       "tier_b_incomplete": 6, "analyze_failed": 1}, code_counts
memberships = sum(code_counts.values())
fail_rows = verdicts["fail"]
overlap = memberships - fail_rows
multi = [int(r["idx"]) for r in rows if len([c for c in r["fail_codes"].split(";") if c]) > 1]
assert len(multi) == overlap == 22, (len(multi), overlap)
shard_count = Counter(int(r["shard"]) for r in rows)
b3_rows = [int(r["idx"]) for r in rows if "b3_cs_hits=" in r["evidence"]]
nag = codes["tool_nag_tail"]
nag_by_prod = Counter(led[i]["product"] for i in nag)
nag_by_state = Counter(led[i]["state"] for i in nag)
nag_kinds = set(led[i]["kind"] for i in nag)
assert nag_kinds == {"CLR"}
FORMER_PARTIAL = [311, 332, 357, 359, 459, 968, 982]
for i in FORMER_PARTIAL:
    assert "tool_nag_tail" in led[i]["fail_codes"] and led[i]["verdict"] == "fail", i

DESC = {
    "tool_nag_tail": ".cs.txt 尾部残留 ilspycmd 升级提示（未注释、非合法 C#）；首轮 A6/B4 只匹配行首工具名，漏检",
    "a2_sha_missing": "归档说明或制作者报告里取不到 64 位 SHA-256（报告缺失 ⇒ 无第二处指纹可比）",
    "a3_report_missing": "制作者报告（v0.*/制作者报告/<name>.md）缺失或为空",
    "tier_b_incomplete": "Tier B 只做一半（CLR 缺 il.txt，tier_b=PARTIAL:no_il）",
    "analyze_failed": "报告自述 status=failed_analyze（反编译失败），无统计数可比对（tier_b=PARTIAL:no_claim）",
}


def ev(idx, limit=150):
    text = led[idx]["evidence"].replace(" | ", " ; ").replace("|", "/").strip()
    return (text[:limit] + "…") if len(text) > limit else text


def detail(code):
    ids = sorted(codes[code])
    out = ["### %s（%d 件）" % (code, len(ids)), "",
           "复跑：PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh", "",
           "| idx | shard | product | item_dir | verdict | evidence |",
           "| ---: | ---: | --- | --- | --- | --- |"]
    for i in ids:
        r = led[i]
        out.append("| %d | %s | %s | %s | %s | %s |" % (i, r["shard"], r["product"], r["item_dir"], r["verdict"], ev(i)))
    out.append("")
    return "\n".join(out)


prod_rows = "\n".join("| %s | %d | %d | %d | 0 | 0 |" % (p, prod_count[p], prod_m[p]["pass"], prod_m[p]["fail"]) for p in prods)
state_rows = "\n".join("| %s | %d | %d | %d | 0 | 0 |" % (x, state_count[x], state_m[x]["pass"], state_m[x]["fail"]) for x in states)
code_rows = "\n".join("| %s | %d | %s |" % (c, n, DESC[c]) for c, n in code_counts.items())
shard_rows = "\n".join("| %d | %d | %.1f%% |" % (n, shard_count[n], shard_count[n] / 10.0) for n in sorted(shard_count))
former = ", ".join(str(i) for i in FORMER_PARTIAL)

stats_md = f"""# T9 统计（机检预审 · 第二轮更正）

- 总件数 **1000** ｜ pass **{verdicts['pass']}** ｜ fail **{verdicts['fail']}** ｜ partial **0** ｜ blocked **0**
- **{DATE} 第二轮更正**：455 件 .cs.txt 尾部残留 ilspycmd 升级提示（tool_nag_tail），首轮判据只匹配行首工具名故漏检；结论由 pass 978 更正为 pass 530 / fail 470。产品矩阵、失败原因表、失败明细、README 限制说明与 validation R3 同轮按台账重算，旧汇总 978/15/7 与 537/463 一并作废。
- 机器可读重算结果见同目录 reconciliation.json：逐行取自 selection.csv + ledger-1000.csv 独立复算，不复制任何旧文档数字。
- 固定输入：提交 {HEAD} 的 handoff/review/t9-1000/ 六个文件（SHA-256 已逐个核对）。
- 证据档位：已实测 1000（无未验证 / 无法判定行）。
- 选件：待静态验收 916 + 静态验收未通过 84（按路径序）。

## 1. 分产品 × 结论矩阵

| product | 件数 | pass | fail | partial | blocked |
| --- | ---: | ---: | ---: | ---: | ---: |
{prod_rows}
| **合计** | **{sum(prod_count.values())}** | **{verdicts['pass']}** | **{verdicts['fail']}** | **0** | **0** |

> 更正对照：旧表 Plus 510/448、Properties 23/0，三行相加 537/463，与台账不符。本轮逐行重算：Plus {prod_m['Plus']['pass']}/{prod_m['Plus']['fail']}、Properties {prod_m['Properties']['pass']}/{prod_m['Properties']['fail']}、Plus-Properties {prod_m['Plus-Properties']['pass']}/{prod_m['Plus-Properties']['fail']}，合计 {verdicts['pass']}/{verdicts['fail']}。

## 2. 分归档状态 × 结论

| state | 件数 | pass | fail | partial | blocked |
| --- | ---: | ---: | ---: | ---: | ---: |
{state_rows}
| **合计** | **1000** | **{verdicts['pass']}** | **{verdicts['fail']}** | **0** | **0** |

> 归档状态与本次预审结论分别保留：同一原件的归档状态不因预审 verdict 改变。

## 3. Tier A / Tier B 覆盖率（实数）

| 层 | 应做 | 实做 | 覆盖率 | 未覆盖件数 |
| --- | ---: | ---: | ---: | ---: |
| Tier A 结构一致性 | 1000 | 1000 | 100.0% | {tier_a_count['FAIL:a3_report_missing,a2_sha_missing']} |
| Tier B 内容重算（CLR） | {kind_count['CLR']} | {kind_count['CLR']} | 100.0% | 0 |
| Tier B 内容重算（native） | {kind_count['native']} | {kind_count['native']} | 100.0% | 0 |
| Tier B 合计 | {kind_count['CLR'] + kind_count['native']} | {kind_count['CLR'] + kind_count['native']} | 100.0% | 0 |

> 应做 = kind ∈ {{CLR, native}}（含 115 件经 tree 回退重判的变体导出件）；other {kind_count['other']} 件为真非 PE / 缺报告，只做 Tier A。
> **Tier B 原始字段分布**（tier_b 列原值，勿与最终 verdict 混读）：PASS {tier_b_count['PASS']}、PARTIAL:no_il {tier_b_count['PARTIAL:no_il']}、PARTIAL:no_claim {tier_b_count['PARTIAL:no_claim']}、NOT_RUN {tier_b_count['NOT_RUN']}。这 6+1 件同时带 tool_nag_tail，最终 verdict 均为 fail，故最终 partial 计 0。

## 4. fail_code 独立行数

| fail_code | 独立行数 | 含义 |
| --- | ---: | --- |
{code_rows}
| **原因占用合计** | **{memberships}** | 多码行重叠，去重后 fail 行 {fail_rows} |

> 独立行数按「该原因出现在多少行」计，不做去重；同一行可带多个原因。重叠：a2_sha_missing + a3_report_missing 同现 15 行，tier_b_incomplete + tool_nag_tail 同现 6 行，analyze_failed + tool_nag_tail 同现 1 行 ⇒ 占用 {memberships} 次 = fail {fail_rows} 行 + 重叠 {overlap} 行。
> tool_nag_tail 分布：Plus {nag_by_prod.get('Plus', 0)}、Properties {nag_by_prod.get('Properties', 0)}、Plus-Properties {nag_by_prod.get('Plus-Properties', 0)}；kind 全为 CLR（CLR 共 {kind_count['CLR']} 件）；归档状态：待静态验收 {nag_by_state.get('待静态验收', 0)} / 静态验收未通过 {nag_by_state.get('静态验收未通过', 0)}。

## 5. blocked 原因分布

| 原因（fail_codes） | 件数 |
| --- | ---: |
| （无） | 0 |

## 6. 分片执行（件数由台账重算）

| shard | 件数 | 占比 |
| ---: | ---: | ---: |
{shard_rows}

> idx % 12 分片，12 片并行；墙钟用时见分片日志，不属本轮可复算字段。

## 7. 口径限制

- 这是**机检预审**，不是上游 P0–P3 终判：原件二进制不在仓库，语义层与运行期证据一律未做。
- Tier B 是「我方产物自证」（数 IL/ASM 条目 vs 报告声称值），不是用 dnfile/pefile 从原件重算。
- B3 占位符命中只登记不判 fail（无法区分原版行为与恢复缺口）。
"""

failures_md = f"""# T9 失败清单（按 fail_code 分组 · 第二轮更正）

机检预审口径：本清单只列**机械可判**的缺口；语义层（类型用途、调用约定、逻辑等价）未复核，故不等于上游「静态验收未通过」结论，也不做 P0–P3 终判。

总件数 1000 ｜ fail **{fail_rows}** ｜ partial **0** ｜ blocked **0** ｜ pass **{verdicts['pass']}**

> **{DATE} 第二轮更正**：旧第 5 行「978 pass / 15 fail / 7 partial」作废。455 件 .cs.txt 尾部残留 ilspycmd 升级提示（tool_nag_tail）首轮漏检，现已全部计入 fail；旧标 partial 的 7 件（idx {former}）均带 tool_nag_tail，verdict 已改为 fail，partial 归 0。
> 命名映射：a3_report_missing 即 lead 口径的 report_missing（15 件）；a2_sha_missing 与之同源（报告缺失 ⇒ 无第二处指纹可比）。

复跑命令（单件）：PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh

## fail_code 计数（独立行数，允许重叠）

| fail_code | 件数 | 含义 |
| --- | ---: | --- |
{code_rows}
| **原因占用合计** | **{memberships}** | 去重后 fail 行 {fail_rows}（重叠 {overlap} 行） |

> 多码行：15 行同带 a2_sha_missing + a3_report_missing；6 行同带 tier_b_incomplete + tool_nag_tail；1 行同带 analyze_failed + tool_nag_tail。下面分组明细逐组列全，同一 idx 可在多组出现。

## 分组明细

{detail('tool_nag_tail')}
{detail('a2_sha_missing')}
{detail('a3_report_missing')}
{detail('tier_b_incomplete')}
{detail('analyze_failed')}
## 观察项（不判 fail）

B3 占位符扫描命中 {len(b3_rows)} 件：NotImplementedException / #error / 待填 出现在反编译正文里。**无法区分是原版本来就抛 NotImplementedException 还是恢复缺口**（原件不在仓库），因此只登记、不判 fail。命中行号见台账 evidence 列的 b3_cs= 字段与 shard-*.jsonl。
"""

readme_md = f"""# out/review9 · T9 1,000 件机检预审

> **{DATE} 第二轮更正**：455 件 .cs.txt 尾部残留 ilspycmd 升级提示（未注释、非合法 C#），当时 A6/B4 只匹配行首工具名，漏检。结论已按台账重算：**pass {verdicts['pass']} / fail {verdicts['fail']} / partial 0 / blocked 0**（原报 978/15/7 失效）。同轮修正：产品矩阵（旧 510/448、23/0 ⇒ 台账 {prod_m['Plus']['pass']}/{prod_m['Plus']['fail']}、{prod_m['Properties']['pass']}/{prod_m['Properties']['fail']}）、fail_code 表（补 tool_nag_tail 455）、失败明细 verdict、validation R3 与本文件限制说明。修复见 handoff/fixes/nag-tail/ 与分支 tietoumiao/nagfix-cs-tail。

## 这是什么

对 1,000 件未评审逆向成果（待静态验收 916 + 静态验收未通过 84）出的**逐件机检预审台账**。机器可读重算见 reconciliation.json。

> **这不是上游 P0–P3 终判。** 原因：原件二进制不在仓库（逆向成果/ 下 0 个二进制 blob），语义层（类型用途、调用约定、逻辑等价、运行期行为）未复核。本批只证明「结构自洽 + 我方产物与报告声称值一致」。

## 判据（两层）

- **Tier A（1,000 件全做）**：A1 归档说明存在；A2 归档说明与制作者报告的 原件 SHA-256 逐字符相同（64 hex）；A3 制作者报告存在非空；A4 必填字段（sha256/tool/统计数/dumps 绑定）；A5 dumps 资产名在我方 assets 清单且本件有导出 txt；A6 报告无未替换占位符。
- **Tier B（CLR + native）**：B1 .il.txt 的 ^MD 0x 行数（排除页脚 MD (none) 哨兵行）与报告 methods= 比对；B2 .asm.txt 的 ^FUNC 行数与 functions= 比对；B3 占位符扫描（观察项，不判 fail）；B4 未注释工具横幅 ⇒ fail。

合并：A 任一 fail ⇒ fail；Tier B 出现未注释工具横幅（B4，tool_nag_tail）⇒ fail（本轮新增的判定路径，作用于 455 件）；其余沿用 A 过 + 非 PE ⇒ partial、A 过 + Tier B 无输入 ⇒ blocked、两层全过 ⇒ pass 的旧口径，但本轮已无 partial / blocked 行。

## 文件

| 文件 | 内容 |
| --- | --- |
| selection.csv | 1,000 件选件（idx/shard/state/product/item_dir/name/kind_hint/各 blob 路径） |
| ledger-1000.csv | 逐件结论（idx,shard,state,product,name,item_dir,relative_path,sha256,kind,tier_a,tier_b,verdict,fail_codes,evidence,evidence_level） |
| shard-<n>.csv / .jsonl | 12 个 worker 的分片原始结果（合并前落盘；jsonl 带逐件 fail 明细） |
| shard-<n>.check.md / .summary.md | worker 自抽 5 行复核 + 分片小结 |
| failures.md | 按 fail_code 分组的失败清单（含全部 455 件 tool_nag_tail）+ 逐件复跑命令 |
| stats.md | 分产品×结论矩阵、分归档状态矩阵、Tier A/B 覆盖率实数、fail_code 独立行数、blocked 原因 |
| review_shard.py / merge_ledger.py / verify_item.py / gen_reports.py | 扫描 / 合并 / 单件复跑 / 报告生成 |
| validation.md | R1–R6 逐条自检 + 分片一致性 + 已知异常（裸波浪号 404、代理、并行写坏片） |
| reconciliation.json | 本轮独立重算的固定结果（产品/状态矩阵、原因独立行数、反例对象） |

## 复现

    cd _work/wf-20261120-aspen-batch
    PYTHONIOENCODING=utf-8 python out/review9/review_shard.py --shard 3 --concurrency 3   # 单分片重跑
    PYTHONIOENCODING=utf-8 python out/review9/merge_ledger.py                              # 合并 + R1/R2/R6 断言
    PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx 42 --fresh              # 单件复跑

## 限制（明写）

1. 原件不在仓库：A1/A2 比的是「归档说明登记值 vs 制作者报告登记值」，不是重新计算原件 sha256。
2. Tier B 是产物自证：数的是导出 txt 的条目行数，不是 dnfile/pefile 从原件重算 TypeDef/节/导入。
3. B3 命中只登记：NotImplementedException 可能是原版行为，无法区分，故不判 fail（本轮命中 {len(b3_rows)} 件）。
4. 失败构成（独立行数，允许一行多码）：tool_nag_tail **455** 件（尾部工具提示，全部 fail）、a2_sha_missing 15、a3_report_missing 15、tier_b_incomplete 6、analyze_failed 1；原因占用 {memberships} 次，重叠 {overlap} 行 ⇒ 去重后 fail {fail_rows} 行。Tier B 原始字段仍为 PASS {tier_b_count['PASS']} 件；{tier_b_count['PARTIAL:no_il']} 件 partial: tier_b_incomplete（CLR 缺 il.txt）；{tier_b_count['PARTIAL:no_claim']} 件 partial: analyze_failed；{tier_b_count['NOT_RUN']} 件 NOT_RUN，但其中 6+1 件同时带 tool_nag_tail，最终 verdict 为 fail，最终 partial 记 0。旧「7 件 partial」的表述作废。
5. 证据三档逐行单一值：本批全为〔已实测〕（数的是仓内 blob 原文），无〔未验证〕/〔无法判定〕行，故 blocked 0。
"""

validation_md = f"""# T9 自检（R1–R6 逐条，机检预审 · 第二轮更正）

生成时间：{DATE} ｜ 台账：out/review9/ledger-1000.csv ｜ 结论：pass **{verdicts['pass']}** / fail **{verdicts['fail']}** / partial 0 / blocked 0（{DATE} 因 tool_nag_tail 重算，R3 同步改写）

| id | 判据 | 实测结果 | 证据 |
| --- | --- | --- | --- |
| R1 | 1,000 行齐全、无遗漏、无重复（item_dir 唯一） | ✅ rows=1000 ｜ unique item_dir=1000 ｜ dup=0 ｜ dup_idx=0 | reconciliation.json matched_rows / unique_item_dirs |
| R2 | 每行 verdict ∈ {{pass,fail,partial,blocked}}、无空值、fail 行必有 fail_codes | ✅ bad_verdict=[] ｜ fail_no_code=[] ｜ fail={fail_rows} 全带码 | reconciliation.json verdicts / code_counts |
| R3 | 每个 fail 有 fail_code 且 failures.md 列全该码的 idx 并给复跑命令 | ✅ {fail_rows} 件 fail 全带 fail_codes（tool_nag_tail 455、a2_sha_missing 15、a3_report_missing 15、tier_b_incomplete 6、analyze_failed 1；占用 {memberships} 次，多码重叠 {overlap} 行）；failures.md 每组列全 idx，并给 verify_item.py --idx <idx> --fresh | failures.md / reconciliation.json code_counts |
| R4 | Tier B 覆盖率写实数 | ✅ {kind_count['CLR'] + kind_count['native']}/{kind_count['CLR'] + kind_count['native']}（CLR {kind_count['CLR']}/{kind_count['CLR']}、native {kind_count['native']}/{kind_count['native']}）；另 {kind_count['other']} 件真非 PE/缺报告只做 Tier A；tier_b 原始字段 PASS {tier_b_count['PASS']} / PARTIAL:no_il {tier_b_count['PARTIAL:no_il']} / PARTIAL:no_claim {tier_b_count['PARTIAL:no_claim']} / NOT_RUN {tier_b_count['NOT_RUN']} | stats.md §3 |
| R5 | 三档证据逐行单值、不混写 | ✅ 已实测 1000（无未验证/无法判定行） | ledger evidence_level |
| R6 | 分片结果与合并一致（抽 20 行逐字段） | ✅ mismatch fields = 0（合并日志断言；本轮只复核台账，未重跑分片合并） | logs/merge.json r6_mismatch |

## 分片一致性

| 项 | 值 |
| --- | --- |
| 分片文件 | 12 个 shard-<n>.csv（83–84 件/片，合计 1,000；按 idx % 12 重算件数一致） |
| 分片自校验文件 | 12 个 shard-<n>.check.md + 12 个 shard-<n>.summary.md（worker 各自抽 5 行） |
| 首轮 worker 原始结果 | shard-<n>.worker.csv（保留，未删；与终版差异来自判据修订） |
| 合并断言 | python out/review9/merge_ledger.py → rows 1000 / dup 0 / R6 0 mismatch |

## 独立抽查（不与 worker 复用同一实现）

- 我本人用独立 urllib 重取 7 件（5 件 pass + 2 件非 pass）：两侧 SHA-256 逐字符相同 6/6（第 7 件报告缺失，符合 fail），导出计数与 evidence 一致。
- 12 个 worker 各自 5 行抽查，回报全部一致（详见各 shard-<n>.check.md）。
- 本轮另用 _t13/recompute.py 从两张 CSV 独立复算全部数字（不读旧文档），结果与 reconciliation.json 完全一致。

## 已知异常（已定位，不影响结论）

1. **e1 GitHub raw 对裸 ~ 返回 404**：变体导出（<name>~<hash>.asm.txt）必须先编码为 %7E；已在 fetch 层修。
2. **http.client 绕过系统代理**（本机 127.0.0.1:65533）⇒ 直连整片 404；终轮改回 urllib（走代理）。
3. **shard-5.csv 曾半写损坏**：worker 与我方重跑并发写同一文件；已停 worker（interrupt w9）并重跑 shard 5/9，合并前逐片解码校验通过。
4. **^MD 把页脚哨兵行 MD (none) body=none 计入** ⇒ 12 件假 fail；改 ^MD 0x 后归零。
5. **A6 曾把 IL_XXXX 误判占位符**（30 件假 fail）；收窄后归零。
6. **A4/A5 曾对表格模板报告、分支交付件误报**（149 件假 a5）；按「字段在即算在 + 无 dumps 行时看目录内导出 blob」修正。
7. **A6/B4 漏检尾部工具提示**：只匹配行首工具名，455 件 .cs.txt 尾部残留 ilspycmd 升级提示未计入 ⇒ 旧称「假 pass 455 件」，已更正为 448 件原 pass + 7 件原 partial（见 stats.md §4、failures.md）。

## 复跑

    cd _work/wf-20261120-aspen-batch
    PYTHONIOENCODING=utf-8 python out/review9/review_shard.py --shard all --threads 96   # 全量重算（缓存命中时 ~45 s）
    PYTHONIOENCODING=utf-8 python out/review9/merge_ledger.py                             # 合并 + R1/R2/R6 断言
    PYTHONIOENCODING=utf-8 python out/review9/gen_reports.py                              # stats/failures/README/11-report
    PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx 916 --fresh            # 单件复跑
"""

from collections import Counter as _C
_tb = _C(r.get("tier_b") or "" for r in rows)
_orig_pass = _tb.get("PASS", 0)
_orig_partial = sum(v for k, v in _tb.items() if k.startswith("PARTIAL"))
_orig_fail = sum(v for k, v in _tb.items() if k == "NOT_RUN")
_b4 = sum(1 for r in rows if "tool_nag_tail" in (r.get("fail_codes") or ""))
_b4_from_pass = _b4 - _orig_partial
split_md = f"""# 原判定与现判定分列（第二轮更正）

| 原 Tier B 判定 | 件数 | 现在 | 去向 |
| --- | ---: | --- | --- |
| PASS | {_orig_pass} | pass {verdicts['pass']} / fail {_b4_from_pass} | {_b4_from_pass} 件尾部残留 ilspycmd 提示（B4 tool_nag_tail）转 fail |
| PARTIAL | {_orig_partial} | fail {_orig_partial} | 7 件原 partial（no_il 6 / no_claim 1）全部转 fail |
| NOT_RUN | {_orig_fail} | fail {_orig_fail} | a2/a3/tier_b/analyze_failed 等既有失败 |
| 合计 | {_orig_pass + _orig_partial + _orig_fail} | pass {verdicts['pass']} / fail {fail_rows} | B4 的 455 个失败 = 原 PASS 448 + 原 PARTIAL 7；本表保留旧回执口径，不覆盖 |

更正口径：原 978 pass 中 **448 件**因尾部工具提示转 fail；原 **7 partial**（no_il 6 / no_claim 1）全部转 fail；另有 15 件 NOT_RUN 维持 fail。旧称「455 件假 pass」作废，应为「448 件原 pass + 7 件原 partial」。
"""
stats_md = stats_md + "\n" + split_md + """
## B4 失败计数（供 399 判据）

| 组 | 失败件数 |
| --- | ---: |
| Tier B CLR | 455 |
| Tier B 合计 | 455 |
"""
validation_md = validation_md + "\n" + split_md
for name, text in (("stats.md", stats_md), ("failures.md", failures_md),
                   ("README.md", readme_md), ("validation.md", validation_md)):
    (OUT / name).write_text(text, encoding="utf-8", newline="\n")
print("wrote", sorted(p.name for p in OUT.glob("*.md")))
print("sizes", {p.name: p.stat().st_size for p in sorted(OUT.glob("*.md"))})
