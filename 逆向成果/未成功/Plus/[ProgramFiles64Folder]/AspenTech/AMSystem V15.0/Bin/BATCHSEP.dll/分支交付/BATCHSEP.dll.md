# BATCHSEP.dll 缺口报告（Aspen-Plus / 未产出 IL 与反编译）

样本别名：`BATCHSEP.dll`（清单 out/B2/manifest-b2.csv，原件只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜自算 sha256 f93137707679bfc0d39811c26ec47fee9dca6b32b509d0b5123d5fca22472273｜台账 B2-B wave1b
落点：`02-incomplete/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 状态 | `status=unsupported_non_pe` | 〔实测〕 |
| 实际样本 | 133 字节，SHA-256 `f93137707679bfc0d39811c26ec47fee9dca6b32b509d0b5123d5fca22472273` | 〔实测〕自算 |
| 结论 | 本件未产出 IL 清单与 C# 反编译（不伪造产物） | 〔实测〕 |

本件按 `status=unsupported_non_pe` 记缺口，**不伪造** IL 清单 / C# 反编译产物。

已试工具（逐条为实际执行，含原始报错）：

| 工具 | 结果 |
| --- | --- |
| `dnfile.dnPE` | `PEFormatError: 'DOS Header magic not found.'` |
| `pefile.PE` | `PEFormatError: 'DOS Header magic not found.'` |

原始报错：PEFormatError: 'DOS Header magic not found.'

〔待验证〕本件是否需换用其它解析器（如 COFF/静态库解析）才能判定格式；缺该工具的实测才能判。

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `BATCHSEP.dll` | 〔实测〕 |
| 字节数 | 133 | 〔实测〕 |
| SHA-256（本轮自算） | `f93137707679bfc0d39811c26ec47fee9dca6b32b509d0b5123d5fca22472273` | 〔实测〕 |
| 清单声明 SHA-256 | `f93137707679bfc0d39811c26ec47fee9dca6b32b509d0b5123d5fca22472273` | 〔实测〕一致 |

