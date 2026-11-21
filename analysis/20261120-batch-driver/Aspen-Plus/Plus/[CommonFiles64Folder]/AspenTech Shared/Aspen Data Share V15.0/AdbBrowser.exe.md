# AdbBrowser.exe 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

## 必填字段（T0 口径，逐项可按名检索）

- tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
- functions=N/A（CLR 托管程序集，无 native 函数概念；methods=未在本件报告中记录）
- decomp_ok=N/A（CLR：无函数级反编译统计）
- decomp_fail=N/A（CLR：无函数级反编译统计）


样本别名：`AdbBrowser.exe`（清单 out/B2/manifest-b2.csv，原件只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜自算 sha256 0979d891b8650f19a1362c8740a9de4b2abd35ee54448421d2be144a20ff0ab9｜台账 B2-B wave1b
落点：`01-completed/Aspen-Plus/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 125,480 字节，SHA-256 `0979d891b8650f19a1362c8740a9de4b2abd35ee54448421d2be144a20ff0ab9` | 〔实测〕自算 |
| IL 清单 | `il/AdbBrowser.exe.il.txt`，4549 行（il_dump.py 全量 stdout） | 〔实测〕 |
| 反编译 | `decompiled/AdbBrowser.exe.cs.txt`，1252 行（ILSpy ilspycmd 全量 stdout） | 〔实测〕 |
| 状态 | `status=processed` | 〔实测〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `AdbBrowser.exe` | 〔实测〕 |
| 字节数 | 125,480 | 〔实测〕 |
| SHA-256（本轮自算） | `0979d891b8650f19a1362c8740a9de4b2abd35ee54448421d2be144a20ff0ab9` | 〔实测〕 |
| 清单声明 SHA-256 | `0979d891b8650f19a1362c8740a9de4b2abd35ee54448421d2be144a20ff0ab9` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |

## 2. 产物

- `il/AdbBrowser.exe.il.txt`（4549 行）
- `decompiled/AdbBrowser.exe.cs.txt`（1252 行）

## 3. 缺口

- 运行期行为、强名/签名有效性未验证〔待验证〕；本轮仅静态 IL 与 C# 反编译。

## dumps

dumps: v0.20261121-w2#dumps-w2-part4.tar.gz

- `clr/0979d891b865-AdbBrowser.exe/AdbBrowser.exe.cs.txt` sha256=660fdc7c323762e6a8e3c72e8b5055839fa8bbdf3e50ace698bff7cc5fefb940 bytes=37655
- `clr/0979d891b865-AdbBrowser.exe/AdbBrowser.exe.il.txt` sha256=f7468ba6fb854953e7209b1d85fc6b4a6feada0e0059dfcfe3f9968c224e34ad bytes=239927
