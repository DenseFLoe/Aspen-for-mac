# Infragistics4.Win.UltraWinListView.v15.1.dll

## 必填字段（T0 口径，逐项可按名检索）

- functions=N/A（CLR 托管程序集，无 native 函数概念；methods=未在本件报告中记录）
- decomp_ok=N/A（CLR：无函数级反编译统计）
- decomp_fail=N/A（CLR：无函数级反编译统计）


## 0. 摘要
- status=failed_analyze
- reason=ilspy_rc70
- tool=ILSpy 9.1.0.7988
- sha256=e1baedbb779efec2186337c3d0dd156adca718737dcee41c554d90e776c70a60
- size=378920
- 原始报错（ILSpy stderr/stdout 前 600 字符，未删改）:
```
You are not using the latest version of the tool, please update.
Latest version is '11.2.0.10050' (yours is '9.1.0.7988')
```
- 偏离仓库 AGENTS：本件仅记录失败与原始报错，未伪造反编译正文。

## 1. 缺口与待验证
- ILSpy 9.1.0.7988 对该程序集返回 rc=70；未改用其他反编译器〔待验证〕

## dumps

dumps: v0.20261121-w2#dumps-w2-part4.tar.gz

- `clr/e1baedbb779e-Infragistics4.Win.UltraWinListView.v15.1.dll/Infragistics4.Win.UltraWinListView.v15.1.dll.il.txt` sha256=4c2574c9d0683740a56b1cfa067d9f03ef3e27731d81df703f904e2946dd296b bytes=3326706
- 失败记录（不计为产物）：`clr/e1baedbb779e-Infragistics4.Win.UltraWinListView.v15.1.dll/Infragistics4.Win.UltraWinListView.v15.1.dll.cs.txt` bytes=124，内容为 ILSpy 版本告警原文，非反编译正文；本件 status=failed_analyze
