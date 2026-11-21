# out/review9 · T9 1,000 件机检预审

## 这是什么

对 1,000 件未评审逆向成果（待静态验收 916 + 静态验收未通过前 84）出的**逐件机检预审台账**。

> **这不是上游 P0–P3 终判。** 原因：原件二进制不在仓库（`逆向成果/` 下 0 个二进制 blob），语义层（类型用途、调用约定、逻辑等价、运行期行为）未复核。本批只证明「结构自洽 + 我方产物与报告声称值一致」。

## 判据（两层）

- **Tier A（1,000 件全做）**：A1 归档说明存在；A2 归档说明与制作者报告的 原件 SHA-256 逐字符相同（64 hex）；A3 制作者报告存在非空；A4 必填字段（sha256/tool/统计数/dumps 绑定）；A5 dumps 资产名在我方 assets 清单且本件有导出 txt；A6 报告无未替换占位符。
- **Tier B（CLR + native）**：B1 `.il.txt` 的 `^MD 0x` 行数（排除页脚 `MD (none)` 哨兵行）与报告 `methods=` 比对；B2 `.asm.txt` 的 `^FUNC ` 行数与 `functions=` 比对；B3 占位符扫描（观察项，不判 fail）；B4 未注释工具横幅 ⇒ fail。

合并：A 任一 fail ⇒ fail；A 过 + 非 PE ⇒ partial；A 过 + Tier B 无输入 ⇒ blocked；两层全过 ⇒ pass。

## 文件

| 文件 | 内容 |
| --- | --- |
| `selection.csv` | 1,000 件选件（idx/shard/state/product/item_dir/name/kind_hint/各 blob 路径） |
| `ledger-1000.csv` | 逐件结论（idx,shard,state,product,name,item_dir,relative_path,sha256,kind,tier_a,tier_b,verdict,fail_codes,evidence,evidence_level） |
| `shard-<n>.csv` / `.jsonl` | 12 个 worker 的分片原始结果（合并前落盘；jsonl 带逐件 fail 明细） |
| `shard-<n>.check.md` / `.summary.md` | worker 自抽 5 行复核 + 分片小结 |
| `failures.md` | 按 fail_code 分组的失败清单 + 逐件复跑命令 |
| `stats.md` | 分产品×结论矩阵、Tier A/B 覆盖率实数、fail_code top、blocked 原因、分片耗时 |
| `review_shard.py` / `merge_ledger.py` / `verify_item.py` / `gen_reports.py` | 扫描 / 合并 / 单件复跑 / 报告生成 |
| `validation.md` | R1–R6 逐条自检 + 分片一致性 + 已知异常（裸波浪号 404、代理、并行写坏片） |

## 复现

```
cd _work/wf-20261120-aspen-batch
PYTHONIOENCODING=utf-8 python out/review9/review_shard.py --shard 3 --concurrency 3   # 单分片重跑
PYTHONIOENCODING=utf-8 python out/review9/merge_ledger.py                              # 合并 + R1/R2/R6 断言
PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx 42 --fresh              # 单件复跑
```

## 限制（明写）

1. 原件不在仓库：A1/A2 比的是「归档说明登记值 vs 制作者报告登记值」，不是重新计算原件 sha256。
2. Tier B 是产物自证：数的是导出 txt 的条目行数，不是 dnfile/pefile 从原件重算 TypeDef/节/导入。
3. B3 命中只登记：`NotImplementedException` 可能是原版行为，无法区分，故不判 fail。
4. 缺制作者报告的 15 件判 `fail: a3_report_missing`（= report_missing）；只有 cs 无 il 的 6 件 CLR 判 `partial: tier_b_incomplete`；报告自述 failed_analyze 的 1 件判 `partial: analyze_failed`。
5. 证据三档逐行单一值：本批几乎全为〔已实测〕（数的是仓内 blob 原文），blocked 行为〔无法判定〕。
