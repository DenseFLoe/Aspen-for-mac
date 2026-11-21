# BFDYLD.obj 缺口报告（Aspen-Plus / 未产出 IL 与反编译）

样本别名：`BFDYLD.obj`（清单 read-test-waiting.csv（schema B），原件目录只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜git_blob 7c457648b688｜自算 sha256 3caaf37f068d6fa7c36ae8d1600055e236002a2538baa2a15f377769a1c1620a｜台账 20261119-61 缺失〔待验证〕
落点：`02-incomplete\Aspen-Plus\[ProgramFiles64Folder]\AspenTech\Aspen Plus V15.0\GUI\Examples\Biofuel and Biochemicals\Bioethanol from Corn Stover\Lignocellulosic biomass to ethanol.apwz!/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 状态 | `status=unsupported_non_pe` | 〔实测〕 |
| 实际样本 | 5,629 字节，SHA-256 `3caaf37f068d6fa7c36ae8d1600055e236002a2538baa2a15f377769a1c1620a` | 〔实测〕自算 |
| 清单声明 | 字节数 5629，SHA-256 `3caaf37f068d6fa7c36ae8d1600055e236002a2538baa2a15f377769a1c1620a` | 〔实测〕 |
| 结论 | 本件未产出 IL 清单与 C# 反编译（不伪造产物） | 〔实测〕 |

本件按 `status=unsupported_non_pe` 记缺口，**不伪造** IL 清单 / C# 反编译产物。

已试工具（逐条为实际执行，含原始报错）：

| 工具 | 结果 |
| --- | --- |
| `dnfile.dnPE` | 原始报错 `PEFormatError: 'DOS Header magic not found.'` |
| `pefile.PE` | 原始报错 `PEFormatError: 'DOS Header magic not found.'` |

原始报错：PEFormatError: 'DOS Header magic not found.'

〔待验证〕本件是否需换用其它解析器（如 COFF/静态库解析）才能判定格式；缺该工具的实测才能判。

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `BFDYLD.obj` | 〔实测〕 |
| 字节数 | 5,629 | 〔实测〕 |
| SHA-256（本轮自算） | `3caaf37f068d6fa7c36ae8d1600055e236002a2538baa2a15f377769a1c1620a` | 〔实测〕 |
| 清单声明 SHA-256 | `3caaf37f068d6fa7c36ae8d1600055e236002a2538baa2a15f377769a1c1620a` | 〔实测〕 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |
| 清单 | `read-test-waiting.csv` | 〔实测〕 |
| 归并首见 | `B` | 〔实测〕 |

## 2. 缺口与待验证

1. `BFDYLD.obj` 的具体格式与来源需人工判定〔待验证〕——缺该格式规范/厂商文档才能判。
2. 若它其实是可解析的 PE（如 COFF 目标文件、静态库），需换 PE/COFF 解析器重跑〔待验证〕。
3. 台账 20261119-61 缺失〔待验证〕。

## 3. 结论

- 本件记 `status=unsupported_non_pe`，未产出 IL/反编译产物，报错原文见 §0〔实测〕。
