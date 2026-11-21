# VBEXAMP.xlsm

## 0. 摘要
- status=unsupported_non_pe
- kind=nonPE / ext=xlsm
- reason=Office 宏文件，不属 PE 二进制
- sha256=8cfb7e1340f37d5a8344b28188591c5f419de1ecf4d1c071e05934974343faee
- size=47572
- 已试工具: dnfile.dnPE / pefile.PE
- 原始报错: PEFormatError: DOS Header magic not found.
- 偏离仓库 AGENTS：本件仅记录缺口，无逆向正文。

## 1. 缺口与待验证
- 若需处理，须先解包/重定位（本轮未做）〔待验证〕

## dumps

dumps: v0.20261121-w2#dumps-w2-part4.tar.gz

- （本件无 dump 产物：failed_analyze / unsupported_non_pe）

- tool=pefile 2024.8.26
