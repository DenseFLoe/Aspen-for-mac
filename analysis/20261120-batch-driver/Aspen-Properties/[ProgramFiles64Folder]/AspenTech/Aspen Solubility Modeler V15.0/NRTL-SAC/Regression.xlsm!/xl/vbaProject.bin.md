# vbaProject.bin

## 0. 摘要
- status=unsupported_non_pe
- kind=nonPE / ext=bin
- reason=无标准 PE 头的二进制块，缺少可解析结构
- sha256=248e460a2ca979b61e9b76b3b660841957af4386d7a4af85a4a18f029fe8658c
- size=532992
- 已试工具: dnfile.dnPE / pefile.PE
- 原始报错: PEFormatError: DOS Header magic not found.
- 偏离仓库 AGENTS：本件仅记录缺口，无逆向正文。

## 1. 缺口与待验证
- 若需处理，须先解包/重定位（本轮未做）〔待验证〕

## dumps

dumps: v0.20261121-w2#dumps-w2-part4.tar.gz

- （本件无 dump 产物：failed_analyze / unsupported_non_pe）

- tool=pefile 2024.8.26
