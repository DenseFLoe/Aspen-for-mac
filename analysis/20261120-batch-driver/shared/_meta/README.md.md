# README.md

## 必填字段（T0 口径，逐项可按名检索）

- tool=pefile 2024.8.26
- functions=N/A（nonPE：未产出 native 函数统计，见 md 内 reason）
- decomp_ok=N/A（nonPE：无函数级反编译统计）
- decomp_fail=N/A（nonPE：无函数级反编译统计）




## 0. 摘要

- status=unsupported_non_pe

- kind=nonPE / ext=md

- reason=非 PE 文件（扩展名 md），不适用 PE 工具链

- sha256=8d832166a324bc85295fbfa81a7d8c1f122ecdd30f732d7755458917ad4b5e0b

- size=392

- 已试工具: dnfile.dnPE / pefile.PE

- 原始报错: PEFormatError: DOS Header magic not found.

- 偏离仓库 AGENTS：本件仅记录缺口，无逆向正文。



## 1. 缺口与待验证

- 若需处理，须先解包/重定位（本轮未做）〔待验证〕

## dumps

dumps: 无（unsupported_non_pe：无 PE 头，不产出 dump）
