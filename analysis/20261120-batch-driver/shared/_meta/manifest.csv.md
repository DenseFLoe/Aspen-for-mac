# manifest.csv

## 0. 摘要
- status=unsupported_non_pe
- kind=nonPE / ext=csv
- reason=非 PE 文件（扩展名 csv），不适用 PE 工具链
- sha256=59d107470d6999fb8f4672eb6206dc59d5b4e524b7952fb7cad24e45e1d1edcf
- size=389466
- 已试工具: dnfile.dnPE / pefile.PE
- 原始报错: PEFormatError: DOS Header magic not found.
- 偏离仓库 AGENTS：本件仅记录缺口，无逆向正文。

## 1. 缺口与待验证
- 若需处理，须先解包/重定位（本轮未做）〔待验证〕

## dumps

dumps: v0.20261121-w2#dumps-w2-part4.tar.gz

- （本件无 dump 产物：failed_analyze / unsupported_non_pe）

- tool=pefile 2024.8.26
