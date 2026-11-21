# apcommands.dll 静态验收记录

**静态验收未通过**。验收一组第 5 轮，2026-11-21。转入 `repair.csv`，复验组为 1。

## 原件与交付

- Aspen Plus V15.0，`[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/apcommands.dll`。文件版本 `41.0.0.609`，原版版本资源显示 `41.0 Build 609`。
- 安装包为 `Process Modeling (Aspen Plus) V15 (64bit).msi`，`ASPEN~51.cab` 内的 `apcommands.dll.D470D1DF_9FE5_4F3E_9EF6_CEAA577688D0`。对照 `inventories/2026-11-19/plus/01-needs-reverse/files.csv` 安装包成员记录和本机只读提取件。实测 116,264 字节，SHA-256 为 `0c1ea40455f64d2f3199e825ecb37b3fbdffd6cb825af100f8946c60e1c46dc9`。
- 交付来自 W2 的 IDA 9.5 / Hex-Rays。以 `b403a5554b1ed6adede761b6c874470dde71ba1f` 的归档树读取全部 4 份导出和制作者报告，逐个校验 Git blob。制作者报告中的指纹列表含其他原件，验收使用下列实际文件。历史报告和两套导出随目录保存。

| 交付 | SHA-256 |
| --- | --- |
| 正式 ASM | `63b2e1983640e8a823aa0f4f18ab129ceca52761be124b5799714fbac628527c` |
| 正式伪 C | `e87985ecdb3abfd7ba375454acadafe81c6bd31c18bb63a84d446650978e542b` |
| 阶段 ASM | `779e6043743b5fb2319b7b5e204f6f4c5b3e689cecca673a656cfd2c597b669d` |
| 阶段伪 C | `bc1fdafe97405d0dea95cc58e45c6640a94a053aa833df41c30482b124065890` |

## 原件结构与覆盖

| 检查 | 结果 |
| --- | --- |
| PE 头和代码区 | AMD64 PE32+，基址 `0x180000000`，PE 实际有 6 节。代码节 `.text` 的 RVA 为 `0x1000`，虚拟大小 `0xBFBA`。入口 `0x18000BDCC` 在两份正式导出均对应 `DllEntryPoint`。 |
| 导出 | 5 个有名导出均有同址函数头。序号 1–5 依次为 `amfdll_identity` `0x180009A30`、`amfdll_init` `0x180007410`、`amfdll_interface` `0x1800073C0`、`amfdll_unload` `0x180009250`、`amfdll_version` `0x180007300`。 |
| 函数与展开记录 | 正式 ASM 和伪 C 的 673 个唯一函数头按地址和名称一一对应。`.pdata` 有 202 条记录，171 条起址是函数头，其他 31 条均为带链式展开标志 `0x4` 的子区间。202 条起址均能定位到正式 ASM 的指令行。 |
| ASM 地址覆盖 | 正式 ASM 的 11,333 个唯一带地址行均在 `.text` 内，原件字节均可解码。按原件指令大小覆盖 46,645 / 49,082 字节。相异助记符为别名或表示差别。3 条展开区间合计有 8 个字节未列出。其中 `0x18000B692` 至 `0x18000B697` 是 `__report_rangecheckfailure` 中调用失败处理函数后的 `nop; add rsp, 28h; ret`。其余代码节中也有未列出的原版字节，尚未逐段确认用途。 |
| 外部依赖 | 普通导入 27 个 DLL、403 个符号，未见延迟导入或 TLS 目录。ASM 第 11784 行从 `0x18000C3F4` 条件跳到 `0x18000CD70`，该目标没有单列指令行。原件 `FF 25 0A 06 00 00` 经 IAT `0x18000D380` 跳往 `api-ms-win-crt-runtime-l1-1-0.dll!_crt_at_quick_exit`。正式伪 C 第 9892 行保留了调用，复验时核对外部绑定。 |
| 失败占位检查 | 正式伪 C 第 9803 行唯一的 `JUMPOUT` 位于 `__scrt_initialize_onexit_tables` 的 `_scrt_fastfail(5)` 调用之后。目标 `0x18000C2C6` 在原件为 `CC`（`int3`），ASM 第 11680 行保留该字节。 |
| 资源 | 唯一资源叶为 `RT_VERSION (16) / 1 / 1033`，数据 RVA `0x1C060`、816 字节，SHA-256 为 `487d761ad88f076c4a38c1b3d7c5da5911949cfd94c5d8ff140b5e84454443b6`。归档交付中缺可编辑版本资源，例如 `.rc`。 |

## 已确认的交付缺口

1. **正式伪 C 有七处字符串被替换。** 阶段版行数一致，第 726、730、4464、4497、4528、4693、4724 行保留原版文字。原件 `.rdata` 可核对下列内容，正式版在对应位置出现 `<abs-path>`。正式 ASM 与阶段 ASM 仅第 1101 行的字符串注释不同。应从原件复核字符串及其调用，再提交统一修正版本。

   | 伪 C 行 | 原件 RVA | 原版文本的识别内容 |
   | ---: | --- | --- |
   | 726 | `0xE9D8` | `PLTCON unavailable to process the following:\n` |
   | 730 | `0xEA38` | ` Defn:\n%s` |
   | 4464、4497 | `0xF408` | `Examples:\n` 与 `DISABLE STREAMS` |
   | 4528 | `0xF497` | `Examples:\n` 与 `ENABLE STREAMS` |
   | 4693 | `0xFA33` | `Examples:\n` 与 `DISABLE HXFLUXS` |
   | 4724 | `0xFAD2` | `Examples:\n` 与 `ENABLE HXFLUXS` |

2. **两套代码导出都缺少被引用的静态数据定义。** 首个函数 `sub_180001000` 的伪 C 第 8 行引用 `unk_180010E40`，两套 ASM 从 `0x18000101B` 对应到同一 `.rdata` 地址。原件 RVA `0x10E40` 开始的 16 字节为 `08 00 00 00 00 00 00 00 02 00 00 00 00 00 00 00`。交付中该符号只有引用，缺少保留字节、大小和用法的可编辑定义。第 8 行同次调用还引用 `.data` 零初始化区 RVA `0x19C30`，需要在交付中表达相应数据生命周期。
3. **版本资源缺少可编辑输入。** 按原件的资源类型、编号、语言、固定版本字段和字符串表补齐。复验时同时核对静态数据、代码缺段和外部绑定。

## 复查方法

用 PowerShell `Get-FileHash -Algorithm SHA256` 对只读提取件和四份导出核对上表。用 Python 的 pefile 2024.8.26 读取 `OPTIONAL_HEADER`、`sections`、`DIRECTORY_ENTRY_EXPORT.symbols`、`DIRECTORY_ENTRY_IMPORT`、`DIRECTORY_ENTRY_EXCEPTION` 和 `DIRECTORY_ENTRY_RESOURCE`。以 `^FUNC ([0-9A-Fa-f]+) (\\S+)$` 和带 `// ` 前缀的同式扫描两份正式导出。以 `^\\s+([0-9A-Fa-f]+):` 收集 ASM 地址，用 Capstone Python 包 5.0.9（核心报告 5.0.7）的 x86-64 模式从原件同址独立解码一条指令，按解码长度取字节覆盖并对照展开区间。用 `pe.get_data(rva, size)` 读取常量、字符串和资源叶的字节。逐行比较两套导出即可定位正式版文字的变化。

本轮静态检查使用原件和已有交付。Windows 重建和行为对照留待后续阶段。
