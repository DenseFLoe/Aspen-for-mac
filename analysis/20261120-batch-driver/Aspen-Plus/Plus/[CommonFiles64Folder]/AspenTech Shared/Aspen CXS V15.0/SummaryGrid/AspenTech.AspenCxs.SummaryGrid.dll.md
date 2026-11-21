# AspenTech.AspenCxs.SummaryGrid.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

## 必填字段（T0 口径，逐项可按名检索）

- tool=ILSpy 9.1.0.7988 + dnfile 0.18.0
- functions=N/A（CLR 托管程序集，无 native 函数概念；methods=未在本件报告中记录）
- decomp_ok=N/A（CLR：无函数级反编译统计）
- decomp_fail=N/A（CLR：无函数级反编译统计）


样本别名：`AspenTech.AspenCxs.SummaryGrid.dll`（清单 out/B2/manifest-b2.csv，原件只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜自算 sha256 9d9540d6958e9a34307f3da75fd527ff5c69e077fdefd7161d7e7c70f7ba6ba4｜台账 B2-B wave1b
落点：`01-completed/Aspen-Plus/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 381,480 字节，SHA-256 `9d9540d6958e9a34307f3da75fd527ff5c69e077fdefd7161d7e7c70f7ba6ba4` | 〔实测〕自算 |
| IL 清单 | `il/AspenTech.AspenCxs.SummaryGrid.dll.il.txt`，30589 行（il_dump.py 全量 stdout） | 〔实测〕 |
| 反编译 | `decompiled/AspenTech.AspenCxs.SummaryGrid.dll.cs.txt`，14333 行（ILSpy ilspycmd 全量 stdout） | 〔实测〕 |
| 状态 | `status=processed` | 〔实测〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `AspenTech.AspenCxs.SummaryGrid.dll` | 〔实测〕 |
| 字节数 | 381,480 | 〔实测〕 |
| SHA-256（本轮自算） | `9d9540d6958e9a34307f3da75fd527ff5c69e077fdefd7161d7e7c70f7ba6ba4` | 〔实测〕 |
| 清单声明 SHA-256 | `9d9540d6958e9a34307f3da75fd527ff5c69e077fdefd7161d7e7c70f7ba6ba4` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |

## 2. 产物

- `il/AspenTech.AspenCxs.SummaryGrid.dll.il.txt`（30589 行）
- `decompiled/AspenTech.AspenCxs.SummaryGrid.dll.cs.txt`（14333 行）

## 3. 缺口

- 运行期行为、强名/签名有效性未验证〔待验证〕；本轮仅静态 IL 与 C# 反编译。

## dumps

dumps: v0.20261121-w2#dumps-w2-part4.tar.gz

- `clr/9d9540d6958e-AspenTech.AspenCxs.SummaryGrid.dll/AspenTech.AspenCxs.SummaryGrid.dll.cs.txt` sha256=ecba7e82f209031005ecb93f32bd2c84592c99dc0dfc93c89236681af432effc bytes=410333
- `clr/9d9540d6958e-AspenTech.AspenCxs.SummaryGrid.dll/AspenTech.AspenCxs.SummaryGrid.dll.il.txt` sha256=01c568ffb30a3b10ab44623ff98b849b8b30f98f854881c1ec7ca9a6dde06395 bytes=1969919
