# oomfcorelib.lib

## 0. 摘要
- status=unsupported_non_pe
- kind=nonPE / ext=lib
- reason=COFF 静态库归档（.lib），成员为 .obj，需先解包并重定位
- sha256=2e293c417b2604a77674790839a418a488ff2f8eba3264ffab1b86d0ebc1c967
- size=117484
- 已试工具: dnfile.dnPE / pefile.PE
- 原始报错: PEFormatError: DOS Header magic not found.
- 偏离仓库 AGENTS：本件仅记录缺口，无逆向正文。

## 1. 缺口与待验证
- 若需处理，须先解包/重定位（本轮未做）〔待验证〕

## dumps

dumps: v0.20261121-w2#dumps-w2-part4.tar.gz

- （本件无 dump 产物：failed_analyze / unsupported_non_pe）

- tool=pefile 2024.8.26
