# azeotropesearch.lib

## 必填字段（T0 口径，逐项可按名检索）

- tool=dnfile.dnPE 0.18.0 / pefile 2024.8.26（均不支持该格式，见原始报错）
- functions=N/A（nonPE：未产出 native 函数统计，见 md 内 reason）
- decomp_ok=N/A（nonPE：无函数级反编译统计）
- decomp_fail=N/A（nonPE：无函数级反编译统计）


## 0. 摘要
- status=unsupported_non_pe
- kind=nonPE / ext=lib
- reason=COFF 静态库归档（.lib），成员为 .obj，需先解包并重定位
- sha256=2d899bf19778990ef879b9c8dfaf07b57ed65cff287ad56bf722f15fefb0c2e2
- size=87990
- 已试工具: dnfile.dnPE / pefile.PE
- 原始报错: PEFormatError: DOS Header magic not found.
- 偏离仓库 AGENTS：本件仅记录缺口，无逆向正文。

## 1. 缺口与待验证
- 若需处理，须先解包/重定位（本轮未做）〔待验证〕

## dumps

dumps: 无（unsupported_non_pe：无 PE 头，不产出 dump）
