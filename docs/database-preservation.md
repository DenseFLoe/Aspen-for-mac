# 数据库永久保留原则

用户已明确要求：**已提取的数据库必须独立归档，项目开发不得删除。** 本规则适用于维护者、自动化代理、构建工具及项目清理脚本。

## 受保护资产

| 相对项目根目录的路径 | 用途 |
| --- | --- |
| `.local/property-database/plaintext-export/` | 完整导出数据包：数据、关系表、精确十进制数值、元数据、恢复工具、说明与核验记录 |
| `.local/property-database/archives/` | 完整压缩归档、SHA-256 校验文件和归档核验记录 |
| `.local/property-database/DO_NOT_DELETE.md` | 本地永久保留声明 |
| `.local/property-database/AGENTS.md` | 本地数据库目录维护规则 |

这些数据是独立项目资产，不属于缓存或构建输出。`.gitignore` 只决定不上传，不赋予删除权限。数据包及压缩归档继续仅本地保存，GitHub 仅保存原则、工具和说明。

## 必须遵守的开发规则

1. 开发、重构、构建、分支切换、整理目录和释放空间时，不得删除、清空、覆盖或损坏受保护资产。
2. 禁止对工作区执行会删除这些资产的 `git clean -fdx`、`git clean -ffdx`；禁止递归清理整个 `.local/` 或 `.local/property-database/`。任何清理脚本必须明确排除上述路径。
3. 压缩完成后仍保留完整原始导出目录。新增导出、转换、恢复、迁移和归档一律使用新路径，不覆盖已有资产。
4. 只有用户今后针对具体路径明确要求删除或覆盖，才可执行对应操作。常规的“清理项目”“重新构建”“整理分支”不构成授权。
5. 复制和备份必须保留完整数据包，或完整压缩包及其校验、核验文件。不得只保留数值表而丢弃单位、关系、来源、脚本或已知限制。

## 归档内容与验证

2026-11-15 创建的归档位于：

```text
.local/property-database/archives/
  aspen-v15-plaintext-export-2026-11-15.zip
  aspen-v15-plaintext-export-2026-11-15.zip.sha256
  aspen-v15-plaintext-export-2026-11-15.verification.json
```

压缩包采用 ZIP64/DEFLATE，包含整个 `plaintext-export/`，以及顶层 `DO_NOT_DELETE.md` 和逐文件 `ARCHIVE_MANIFEST.json`。原始导出保持独立保留。

验证先逐文件比对原数据包的 `checksums.sha256`，再完整读取压缩包内每个文件，检查 SHA-256、长度及 ZIP CRC，并检查源目录的文件清单、大小和修改时间未变化。归档本身另生成 SHA-256。此项验证确认归档内容完整，不替代物性公式或计算结果验证。

## 未来恢复和接入

先核对归档 SHA-256，再解压到新目录，不覆盖原始数据。数据包附带 `tools/import_aspen_plaintext.py` 和依赖脚本，使用 Python 3.11+ 标准库即可恢复为 SQLite，无需 Aspen 或 SQL Server。

后续程序需要实现数据库读取接口、单位与物性模型映射，并解释已记录的参数表示差异；数据包本身不包含已验证的热力学求解引擎。完整范围和已知限制见 [明文导出说明](plaintext-database-export.md) 以及本地数据包的 `README.md`、`DATA_MODEL.md` 和 `export-manifest.json`。
