# Interop.SECSERVEROBJECTLib.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

## 必填字段（T0 口径，逐项可按名检索）

- tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
- functions=N/A（CLR 托管程序集，无 native 函数概念；methods=未在本件报告中记录）
- decomp_ok=N/A（CLR：无函数级反编译统计）
- decomp_fail=N/A（CLR：无函数级反编译统计）


样本别名：`Interop.SECSERVEROBJECTLib.dll`（清单 out/B2/manifest-b2.csv，原件只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜自算 sha256 a1b19af66ce615764eec35d8a5489e426aa2a62cfb2a1f551c13b88b5258e5c1｜台账 B2-B wave1b
落点：`01-completed/Aspen-Plus/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 31,608 字节，SHA-256 `a1b19af66ce615764eec35d8a5489e426aa2a62cfb2a1f551c13b88b5258e5c1` | 〔实测〕自算 |
| IL 清单 | `il/Interop.SECSERVEROBJECTLib.dll.il.txt`，299 行（il_dump.py 全量 stdout） | 〔实测〕 |
| 反编译 | `decompiled/Interop.SECSERVEROBJECTLib.dll.cs.txt`，1333 行（ILSpy ilspycmd 全量 stdout） | 〔实测〕 |
| 状态 | `status=processed` | 〔实测〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `Interop.SECSERVEROBJECTLib.dll` | 〔实测〕 |
| 字节数 | 31,608 | 〔实测〕 |
| SHA-256（本轮自算） | `a1b19af66ce615764eec35d8a5489e426aa2a62cfb2a1f551c13b88b5258e5c1` | 〔实测〕 |
| 清单声明 SHA-256 | `a1b19af66ce615764eec35d8a5489e426aa2a62cfb2a1f551c13b88b5258e5c1` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |

## 2. 产物

- `il/Interop.SECSERVEROBJECTLib.dll.il.txt`（299 行）
- `decompiled/Interop.SECSERVEROBJECTLib.dll.cs.txt`（1333 行）

## 3. 缺口

- 运行期行为、强名/签名有效性未验证〔待验证〕；本轮仅静态 IL 与 C# 反编译。

## dumps

dumps: v0.20261121-w2#dumps-w2-part4.tar.gz

- `clr/a1b19af66ce6-Interop.SECSERVEROBJECTLib.dll/Interop.SECSERVEROBJECTLib.dll.cs.txt` sha256=bab9097c2da5ac34a42f68797b6f50cfcaa273ed12c71e2f8182dcd3608db3f0 bytes=81002
- `clr/a1b19af66ce6-Interop.SECSERVEROBJECTLib.dll/Interop.SECSERVEROBJECTLib.dll.il.txt` sha256=481e5b4f84073f77c4311c68c89548ef19b2d28ca655a9a61f2d236bbd7bb669 bytes=45584
