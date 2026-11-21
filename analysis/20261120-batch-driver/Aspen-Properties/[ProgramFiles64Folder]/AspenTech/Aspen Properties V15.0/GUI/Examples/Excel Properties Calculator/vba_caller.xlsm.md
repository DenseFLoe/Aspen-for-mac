# vba_caller.xlsm

## 必填字段（T0 口径，逐项可按名检索）

- tool=pefile 2024.8.26
- functions=N/A（nonPE：未产出 native 函数统计，见 md 内 reason）
- decomp_ok=N/A（nonPE：无函数级反编译统计）
- decomp_fail=N/A（nonPE：无函数级反编译统计）




## 0. 摘要

- status=unsupported_non_pe

- kind=nonPE / ext=xlsm

- reason=Office 宏文件，不属 PE 二进制

- sha256=10b51a5d9521fb78e6d1d90ad9ec3a46e9afa2e397a7f91ba8dddc9ab8f43dc0

- size=58277

- 已试工具: dnfile.dnPE / pefile.PE

- 原始报错: PEFormatError: DOS Header magic not found.

- 偏离仓库 AGENTS：本件仅记录缺口，无逆向正文。



## 1. 缺口与待验证

- 若需处理，须先解包/重定位（本轮未做）〔待验证〕

## dumps

dumps: 无（unsupported_non_pe：无 PE 头，不产出 dump）
