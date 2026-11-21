# usrny6.obj

## 0. 摘要
- status=unsupported_non_pe
- kind=nonPE / ext=obj
- reason=COFF 目标文件（未链接），无 PE 头，无法直接反汇编/反编译
- sha256=92efb7c09dffeb1ef3cbb0798ca65d9469725ec66d328b18fe0bbb3bb9cbba25
- size=1953
- 已试工具: dnfile.dnPE / pefile.PE
- 原始报错: PEFormatError: DOS Header magic not found.
- 偏离仓库 AGENTS：本件仅记录缺口，无逆向正文。

## 1. 缺口与待验证
- 若需处理，须先解包/重定位（本轮未做）〔待验证〕

## dumps

dumps: v0.20261121-w2#dumps-w2-part4.tar.gz

- （本件无 dump 产物：failed_analyze / unsupported_non_pe）

- tool=pefile 2024.8.26
