# AspenTech.AspenCxs.dll 静态复核报告（Aspen-Plus / 全程序集 IL + C# 反编译）

样本别名：`AspenTech.AspenCxs.dll`（清单 out/B2/manifest-b2.csv，原件只读、未上传）
来源：分支 codex/waiting-for-tietoumao｜自算 sha256 8e5089cad02fdd61939012de6be3ec3da67b17e0d6696ff3850ab4ee36af8a28｜台账 B2-B wave1b
落点：`01-completed/Aspen-Plus/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/`（相对 `out/R1`）｜定位规则：`local-rel`

标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据。

## 0. 摘要

| 项目 | 结果 | 依据 |
| --- | --- | --- |
| 实际样本 | 265,256 字节，SHA-256 `8e5089cad02fdd61939012de6be3ec3da67b17e0d6696ff3850ab4ee36af8a28` | 〔实测〕自算 |
| IL 清单 | `il/AspenTech.AspenCxs.dll.il.txt`，42453 行（il_dump.py 全量 stdout） | 〔实测〕 |
| 反编译 | `decompiled/AspenTech.AspenCxs.dll.cs.txt`，21713 行（ILSpy ilspycmd 全量 stdout） | 〔实测〕 |
| 状态 | `status=processed` | 〔实测〕 |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

## 1. 样本与哈希

| 项 | 值 | 标签 |
| --- | --- | --- |
| 文件名 | `AspenTech.AspenCxs.dll` | 〔实测〕 |
| 字节数 | 265,256 | 〔实测〕 |
| SHA-256（本轮自算） | `8e5089cad02fdd61939012de6be3ec3da67b17e0d6696ff3850ab4ee36af8a28` | 〔实测〕 |
| 清单声明 SHA-256 | `8e5089cad02fdd61939012de6be3ec3da67b17e0d6696ff3850ab4ee36af8a28` | 〔实测〕一致 |
| 产品映射 | `Plus` → `Aspen-Plus` | 〔实测〕 |

## 2. 产物

- `il/AspenTech.AspenCxs.dll.il.txt`（42453 行）
- `decompiled/AspenTech.AspenCxs.dll.cs.txt`（21713 行）

## 3. 缺口

- 运行期行为、强名/签名有效性未验证〔待验证〕；本轮仅静态 IL 与 C# 反编译。

