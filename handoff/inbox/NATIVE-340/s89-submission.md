# NATIVE-340 s89 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定候选：#450 @ bde39b4630809020fd972211e9b64010e13410d7；主干基线 `2cb8a177`
- 本轮 head：见 #13

## ① 列宽接进真实表流读取

`cli_tables.read` 现在从 `#~`/`#-` **流头**读 `HeapSizes`，并把每张表每列的宽度写进返回值的 `layout`；
解析与校验使用**同一份** layout（不是验证脚本另算一遍）。本件实测：

- stream = `#~`，**HeapSizes = 0x00** → `#Strings`(0x8048) / `#GUID`(0x10) / `#Blob`(0x1558) 均为 **2 字节**索引
  （更正 s81/s85 回执里「HeapSizes=0x01、#Strings 4 字节」的错误读数：那读的是元数据根而非流头）。
- 85 个列宽全部来自该 layout；MethodDef 行宽 14、MemberRef 6、CustomAttribute 10 均等于列宽之和。

三类阈值配对（经 `cli_tables.coded_width` 同一规则）：

| 空间 | tag 位 | 低 | 宽 | 高 | 宽 |
| --- | ---: | ---: | ---: | ---: | ---: |
| MemberRefParent | 3 | 8191 | 2 | 8192 | 4 |
| TypeDefOrRef | 2 | 16383 | 2 | 16384 | 4 |
| MethodDefOrRef | 1 | 32767 | 2 | 32768 | 4 |

## ② IL 摘要表：行身份 + 建字典前查重复

`code/s89-il-digests.csv`：167 行，每行带 `row`（表内行号）、`token`、`name`、`rva`、`il_len`、`sha256`。
构字典前先扫 token 重复（本侧与声明侧都扫）。四类差异：

| 类别 | 数量 |
| --- | ---: |
| 缺失 | 0 |
| 额外 | 0 |
| 重复 | 0 |
| 内容差异 | 0 |

## ③ 依赖清单（可重跑）

见 `code/s89-dependencies.md`：Python 3.13；pefile 2024.8.26（qa gate）；.NET SDK 9.0.302（PEReader，
`System.Reflection.Metadata` 为 .NET 9 内置）；capstone（qa gate 反汇编普查）。命令逐条列出。

## ④ 保留

四槽标志（0x2/0xA/0x2/0xA，token 0x56/0x56/0x57/0x57）、`AspenHelper` 固定样本与 PEReader 对照、
11 站点、35 条 EH 子句；`0x06000057` 的 arg0 恢复条件不变（缺外部调用者/委托表输入，需入口断点或导出清单）。
