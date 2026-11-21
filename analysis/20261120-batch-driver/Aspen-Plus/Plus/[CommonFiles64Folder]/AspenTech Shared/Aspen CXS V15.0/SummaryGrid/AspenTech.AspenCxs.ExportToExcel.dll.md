# AspenTech.AspenCxs.ExportToExcel.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

## 必填字段（T0 口径，逐项可按名检索）

- tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
- functions=N/A（CLR 托管程序集，无 native 函数概念；methods=未在本件报告中记录）
- decomp_ok=N/A（CLR：无函数级反编译统计）
- decomp_fail=N/A（CLR：无函数级反编译统计）


样本别名：`AspenTech.AspenCxs.ExportToExcel.dll`（清单 out/B2/manifest-b2.csv，原件只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜自算 sha256 8dd8fce8dfa9e9cdbe42c053a593e1d3066a75f7e29471ea4f42aaeab3320750｜台账 B2-B wave1b
落点：`01-completed/Aspen-Plus/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 215,592 字节，SHA-256 `8dd8fce8dfa9e9cdbe42c053a593e1d3066a75f7e29471ea4f42aaeab3320750` | 〔实测〕自算 |
| IL 清单 | `il/AspenTech.AspenCxs.ExportToExcel.dll.il.txt`，13232 行（il_dump.py 全量 stdout） | 〔实测〕 |
| 反编译 | `decompiled/AspenTech.AspenCxs.ExportToExcel.dll.cs.txt`，7660 行（ILSpy ilspycmd 全量 stdout） | 〔实测〕 |
| 状态 | `status=processed` | 〔实测〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `AspenTech.AspenCxs.ExportToExcel.dll` | 〔实测〕 |
| 字节数 | 215,592 | 〔实测〕 |
| SHA-256（本轮自算） | `8dd8fce8dfa9e9cdbe42c053a593e1d3066a75f7e29471ea4f42aaeab3320750` | 〔实测〕 |
| 清单声明 SHA-256 | `8dd8fce8dfa9e9cdbe42c053a593e1d3066a75f7e29471ea4f42aaeab3320750` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |

## 2. 产物

- `il/AspenTech.AspenCxs.ExportToExcel.dll.il.txt`（13232 行）
- `decompiled/AspenTech.AspenCxs.ExportToExcel.dll.cs.txt`（7660 行）

## 3. 缺口

- 运行期行为、强名/签名有效性未验证〔待验证〕；本轮仅静态 IL 与 C# 反编译。

## dumps

dumps: v0.20261121-w2#dumps-w2-part4.tar.gz

- `clr/8dd8fce8dfa9-AspenTech.AspenCxs.ExportToExcel.dll/AspenTech.AspenCxs.ExportToExcel.dll.cs.txt` sha256=6c32ad23ec857ee63de2792f62f06e9f299f4dc5b0f7a601b572cbebc4c18764 bytes=189537
- `clr/8dd8fce8dfa9-AspenTech.AspenCxs.ExportToExcel.dll/AspenTech.AspenCxs.ExportToExcel.dll.il.txt` sha256=e887e097161a695ce11179684521dad00fc244965f2c6eba8533053ae5a0c905 bytes=836271
