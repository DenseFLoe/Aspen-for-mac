# Aspen V15 明文数据导出

导出产物保存在本机 `.local/property-database/plaintext-export/`，不随源代码上传。数据来源为本机 Aspen V15 安装；导出工具不附带 Aspen DLL、数据库二进制、密码、密钥或许可证内容。当前程序仍是 UI 外壳，尚未接入计算引擎。

## 本次范围与结果

2026 年 11 月 14 日，本机四个在线 APED 数据库、四个 TDE/TIIS 文件，以及安装目录中发现的附属数据库和物性数据文件。

| APED 数据库 | 子库 | 原始数值单元 | API 参数记录 | 无子库引用但有存值的参数集 |
| --- | ---: | ---: | ---: | ---: |
| APV150 | 42 | 2,548,216 | 634,304 | 6,719 |
| NISTV150 | 4 | 3,718,633 | 790,083 | 190,707 |
| APESV150 | 6 | 57,243 | 19,239 | 2,284 |
| FACTV150 | 1 | 20,979 | 20,979 | 0 |
| 合计 | 53 | 6,345,071 | 1,464,605 | 199,710 |

112 张 active 表全部导出。每个数值单元的 `(数据库, cp_id, element_index)` 与在线 SQL 的排序结果逐个核对，完全覆盖且无重复，全部解码为有限数字。NIST 的 42 条 API 空返回均在原库三张值表中没有存值，关系记录仍保留，未伪造为零。

| 附属数据库 | 表数 | 行数 |
| --- | ---: | ---: |
| TDE9i | 2 | 42,606 |
| TIIS | 28 | 960,121 |
| TDE9m | 43 | 337,302 |
| TDE9r | 16 | 970,771 |

另外导出 7 份 SQLite 文件及 1 份 Access 文件（包含安装目录与 ProgramData 的同源副本，**不应把重复副本当作新增化学物质**），以及 189 份文本数据文件。`support/inventory.json` 为 220 个发现的文件逐项记录来源、校验、输出位置和状态；其中主库与 TDE 的 8 个源文件指向上述专用导出。

16 份结构化数据库导出均已使用独立 SQLite 文件重新导入，各表行数一致且 `PRAGMA integrity_check` 全部为 `ok`。检查保留原有 SQLite 索引和自增序列；无原装 Aspen 参与恢复。导出数据库和数据包仅本地留存，GitHub 只保存自写工具、测试和说明。

**不能把本次结果描述为所有安装文件均已语义解码。** 还有 15 份旧二进制文件仅做了可逆的十六进制保存；其中 5 份属于 Aspen Plus / AprSystem：`bps.dat`、`dmo.dat`、`flowtran.dat`、`aspcost.dat`、`sdffil.sdf`。其余 10 份是 HYSYS / Energy Analyzer 的 `.mdf` 模型文件，不是已导出的 SQL Server MDF。它们未获得经过验证的结构和数值解释，不能直接作为计算参数读取。`opaque_binary_preserved_as_hex` 是待解析状态，绝不等同于明文物性数据。安装包备份、程序内嵌常量、尚未安装或远程数据库也不在全量保证范围内。

## 数值表示核验

使用 API 的 `LabelIJArray`、`LabelJIArray` 重建方向展开后，1,411,994 条 API 数组在 14 位有效数字下逐位置一致；52,611 条仍不同，完整差异清单保存在各库 `api-layout-differences.jsonl`。不得把这些差异简单判为解密失败或自动覆盖：已确认 API 的对称展开、补缺失值行为会改变数组形态，仍有差异的部分需要按物性类别继续解释。底层所有索引和十进制值均独立保留。多重集比较报告是初筛，顺序比较报告是后续更严格的检查；两者都不是物性公式正确性的证明。

92 个十进制值在 .NET Framework 与 Python 的二进制浮点解析中出现末位差异，均在核验容差内；完整 `value_text` 原样保留。主库来自在线读取，关系表与 API 不是跨进程的同一时点事务快照；本次记录了计数、单元身份和文件哈希，未修改源库。

## 两种 APED 数据表示

- `aped/<数据库>/values/constant-values.jsonl`：每个原始数值单元一行，保留 `cp_id`、`element_index`、**原始明文十进制字符串 `value_text`** 和数值预览 `value`。覆盖有子库引用及没有子库引用的记录，不按化学名称合并。数据库名是身份的一部分。
- `aped/<数据库>/api/parameters.jsonl`：原安装 API 的参数视图，每个独立 `cp_id` 选择一个实际引用子库读取。全部子库引用仍由 `active_DatabankCompounds` 保留；来源、文献、注释可经原始 ID 关联。`properties.jsonl` 保留标签、方向和单位元数据。
- `aped/<数据库>/storage/`：完整 active 关系表、列定义、外键清单、行数与 SHA-256。初始导出中的 `active_PropValueConst` 是编码存储，必须在核验后用明文 `value_text` 替换。不要把初始编码表作为参数明文使用。

数值单元使用已连接数据库上的原装 `AspenTech.APED.Database.DecryptVal(data, propName, Version)`。这是 **V15 非公开方法**，本机程序集版本为 `41.0.0.1`；工具仅调用已安装方法，不复制实现或读取密钥。升级 Aspen 后必须重新核对接口与数据。逐参数读取使用 `GetUnaryPropertyValue`，包括由 CompoundIndex 标识的二元实体。

`cp_id` 关联 `active_CompoundProperty.cpId`；再经 `cpCompoundId`、`cpPropertyId` 关联组分和物性。二元、三元和电解质顺序分别保留在 `active_Duos`、`active_Trios`、`active_ElectrolytePairs`。`element_index` 是原始 `pvcIndex`，不能当成 `active_PropElements.peId` 或数组下标。引用优先级、模型公式和方向展开必须在后续计算层验证。

`value_text` 是无损的十进制表示。.NET Framework 与 Python 将十进制转换为二进制浮点时可能相差一个 ULP，因此不要用 JSON 数值预览覆盖它。原 API 有时会添加 `1e35` 缺失值或省略存储系数；也不能直接以 API 数组替代底层完整数值单元。

## TDE 与 SQLite

`TDE9i.sqlite`、`TIIS.sqlite` 用 SQLite 只读事务导出为 JSONL。字段类型、NULL、Unicode、BLOB 都保留；BLOB 使用明确标记的 Base64，源 TEXT 中非法 UTF-8 字节使用 `$text_hex`，不静默替换字符。

`TDE9m.sqlite`、`TDE9r.sqlite` 在本机副本上通过原装 `TDE.dll` 的数据库读取接口导出标准 SQL。`schema.sql`、各表 SQL 和 `post-schema.sql` 可在普通 SQLite 恢复。BLOB 和含 NUL 的字符串使用 SQL 十六进制字面量，其余文本保留可读形式。这个适配器依赖 Windows x64 / V15 ABI，并核对实际打开的文件路径、行数、完整性和源副本哈希。

## 复现

所有输出路径都应为新的本地目录。Python SQL 导出需要 `pyodbc` 和 ODBC Driver 17；API 导出需要 Windows PowerShell 5.1。源数据库只查询，不修改访问设置或业务记录。

```powershell
$root='.local/property-database/new-export'
foreach($db in 'APV150','NISTV150','APESV150','FACTV150') {
    powershell.exe -NoProfile -NonInteractive -ExecutionPolicy Bypass -File tools/Export-AspenDatabase.ps1 `
        -Database $db -Mode storage -OutputDirectory "$root/aped/$db/values"
    powershell.exe -NoProfile -NonInteractive -ExecutionPolicy Bypass -File tools/Export-AspenDatabase.ps1 `
        -Database $db -Mode parameters -OutputDirectory "$root/aped/$db/api"
    & .local-tools/research/venv/Scripts/python.exe tools/export_aspen_catalogs.py `
        --database $db --output "$root/aped/$db/storage"
}
```

逐参数接口返回空值会记录在 `failures.jsonl` 并返回非零退出码；必须与三张实际值表核对，以区分本来无数值的关系记录与读取失败，不能仅删除失败项。

完成四库导出后进行一次性核验：

```powershell
& .local-tools/research/venv/Scripts/python.exe tools/verify_aspen_plaintext.py `
    --root $root --evidence .local/property-database/new-encoded-evidence --live-sql
& .local-tools/research/venv/Scripts/python.exe tools/audit_aspen_vectors.py --root $root
```

核验工具将编码数值表移至独立 evidence 目录，以完整明文值替换交付目录中的同名表，并更新校验清单；不要在已核验目录重复运行该步骤。`--live-sql` 用于逐单元核对原库身份。

普通 SQLite 与附属数据的导出：

```powershell
foreach($name in 'TDE9i.sqlite','TIIS.sqlite') {
    & .local-tools/research/venv/Scripts/python.exe tools/export_aspen_catalogs.py `
        --sqlite "C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/$name" --output "$root/auxiliary/$name"
}
& .local-tools/research/venv/Scripts/python.exe tools/export_aspen_support.py --output "$root/support"
```

附属导出中断时可加 `--resume` 校验和复用已完成的文件；存在未完成的单库目录时应保留其现场并选择新输出位置。

将安装目录的 `TDE9m.sqlite`、`TDE9r.sqlite`、`TIIS.sqlite` 复制到 `.local/` 下独立的临时目录后运行：

```powershell
& .local-tools/research/venv/Scripts/python.exe tools/export_aspen_tde.py `
    --source-directory .local/property-database/tde-read-source `
    --output "$root/tde"
```

## 在 Mac 上恢复和使用

恢复工具只需要 Python 3.11+ 标准库，不依赖 Aspen 或 SQL Server；目的文件必须不存在。先完成明文关系表核验，再恢复 APED。

```sh
python3 tools/import_aspen_plaintext.py /data/aped/APV150/storage /data/APV150.sqlite
python3 tools/import_aspen_plaintext.py /data/tde/TDE9r.sqlite /data/TDE9r.sqlite
```

API 数组与原始关系表分别保存，后续改造应以明确的组分/子库/物性/元素 ID 建立访问层。导出数据本身不实现热力学模型、闪蒸、流程求解或商业软件的授权迁移。

工具检查：

```sh
python3 -m unittest discover -s tests -p test_plaintext_export.py -v
```

检查覆盖中文、换行、引号、NUL、NULL、二进制字段、非法 UTF-8 TEXT 的无损恢复，以及拒绝覆盖现有文件、行数不匹配时不发布最终文件。
