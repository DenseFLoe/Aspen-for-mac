# Aspen V15 物性数据库提取调查

调查日期：2026 年 11 月 14 日。范围：本机 Aspen Plus / Aspen Properties V15、其 APED 数据库、已安装的数据访问 DLL，以及桌面的 V15 安装介质。

**可以提取，已完成实际导出验证。** 四个 SQL 数据库的组分标识、物性定义、单位等元数据已导出为 SQLite；通过原装 APED DLL 已导出 266 条明文参数记录，包含纯组分常数、温度相关参数向量和二元交互参数。完整数值库尚未全量导出。将加密 SQL 表复制出来与获得可计算参数是两个不同阶段。

## 数据库位置与规模

本机 SQL Server 默认实例 `.` 中存在以下四个在线数据库。当前 Windows 身份可通过集成认证查询，不需要从配置文件提取 SQL 密码。

| 数据库 | 子库数 | 有 NAME 标识的组分数 | active_Compounds 行数 | 数值存储行数 |
| --- | ---: | ---: | ---: | ---: |
| APV150 | 42 | 10,827 | 19,681 | 2,548,216 |
| NISTV150 | 4 | 34,707 | 53,205 | 3,718,633 |
| APESV150 | 6 | 2,147 | 5,293 | 57,243 |
| FACTV150 | 1 | 6,993 | 6,993 | 20,979 |

以上是本机实际 SQL `COUNT`，数值存储行指 `active_PropValueConst` 行。`active_Compounds` 还包含组分对等实体，不能当作独立化学物质数；不同数据库之间也有重复组分，表内数字不能相加作为去重总数。

主要文件位于 `C:\ProgramData\AspenTech\APED V15.0\`：

- `APV150.mdf`、`NISTV150.mdf`、`APESV150.mdf`、`FACTV150.mdf` 及对应日志，是 SQL Server 数据文件。
- 同名无扩展名文件均以 `TAPE` 开头，为 SQL Server 备份容器；不是 CSV 或 SQLite。
- 本机 SQL 数据文件合计约 1.272 GB，备份容器另占约 1.265 GB。

APV150 包含 `PURE25` 至 `PURE41` 的多个历史版本，以及 `AQUEOUS`、`SOLIDS`、`INORGANIC`、`PC-SAFT`、`POLYPCSF`、`NRTL-SAC`、`VLE-LIT`、`VLE-IG`、`VLE-RK`、`HENRY-AP`、`PITZER`、聚合物等子库。其中 `PURE41` 有 2,408 个有 NAME 标识且有子库参数的组分。

NISTV150 包含 `NIST-TRC`、`NIST-IG`、`NIST-RK`、`NIST-EOS`。APESV150 包含 `ACIDGAS`、`AP-EOS`、`FERMENT`、`BIOFEED`、`FLARE`、`AP-ASC`。FACTV150 包含 `FACTPCD`。

## 表结构与加密边界

核心关系如下：

```text
active_Databanks
  -> active_DatabankCompounds
       -> active_CompoundProperty
            -> active_Compounds -> active_CompoundIdentifiers
            -> active_Properties -> active_PropElements / active_PropertyUnitrow
            -> active_PropValueConst / active_PropValueText / active_PropValueLongText
```

`active_CompoundIdentifiers` 提供 CompoundIndex、NAME、ALIAS、CASRN 和 SYNONYM。二元实体通过 `active_Duos` 关联两个组分，电解质对通过 `active_ElectrolytePairs` 关联。一个参数可被多个子库引用，导出时必须保留数据库、子库、组分实体、参数名称与元素顺序。

元数据可直接查询；`pvcValue` 列实际为 `nvarchar`，不是 SQL 浮点类型。逐行检查结果：

| 数据库 | 可解析为数字的文本 | 非数字文本 |
| --- | ---: | ---: |
| APV150 | 19,015 | 2,529,201 |
| NISTV150 | 59,817 | 3,658,816 |
| APESV150 | 2,650 | 54,593 |
| FACTV150 | 6,993 | 13,986 |

在这些库中，全部为数字文本的参数类型仅有 MW、TB，FACTV150 仅 MW。TC、PC、OMEGA 等抽查值为编码后的密文。本地 `Database_Security.htm` 明确说明参数值加密；数字解析统计本身不作为每条非数字文本的加密格式判定。

不应把 `pvcIndex` 直接等同于 `active_PropElements.peId`：实测数值并不支持这种简单关联。物性元素与单位应由对应版本 API 或进一步验证后的格式映射取得。

## 已验证的明文读取路径

使用原安装目录中的：

```text
C:\Program Files\AspenTech\AprSystem V15.0\PropertiesDatabase\Bin\
  ApedGateway.dll
  ApedDataProvider.dll
```

在 Windows PowerShell 5.1 下加载，使用公开类型 `AspenTech.APED.SqlServerDatabase`，程序集版本为 `41.0.0.1`。以当前 Windows 身份连接后，枚举子库，再调用 `PropertyValueManager.GetUnaryPropertyValue`。没有修改数据库内容、程序二进制、许可证设置或访问标记，没有导出密钥。

SQL 负责列出确实存在的参数并生成读取计划；API 负责返回数值及单位、元素、对称性元数据。当前 V15 的该读取方法也接受二元实体的 `CompoundIndex`，因此可以读取组分对参数。二元组分的真实身份和顺序从 `active_Duos` 取得，不能仅依据返回对象的名称字段。

本次导出结果：

| 来源 | 对象 | 参数记录数 |
| --- | --- | ---: |
| PURE41 | 乙醇 | 88 |
| PURE41 | 甲烷 | 89 |
| PURE41 | 水 | 86 |
| VLE-IG | 乙醇、水有序组分对 | 3 |
| 合计 | 包含 NRTL、UNIQ、WILSON 二元参数 | 266 |

记录可能包含一个或多个系数，266 不是单个系数数量。当前样本数值均由 API 返回为 `System.Double[]`，标量参数也保存为单元素数组。

可核查的样例：

| PURE41 参数 | 甲烷 | 水 | 乙醇 |
| --- | ---: | ---: | ---: |
| MW | 16.0425 | 18.0153 | 46.0684 |
| TB，K | 111.67 | 373.15 | 351.44 |
| TC，K | 190.564 | 647.096 | 514 |
| PC，Pa | 4,599,000 | 22,064,000 | 6,137,000 |

API 的压力单位字符串为 `N/sqm`，与 Pa 等价；MW 的单位类型数组为空，导出程序保持原样。

水的 PLXANT 返回 9 个元素，标签为 `A B C D E F G Tlower Tupper`，末两项为 273.16、647.1 K，说明温度关联式的系数与有效区间都能读取。

乙醇—水的 NRTL 原始数组有 16 项，而 `ElementCount` 为 8、标签列表为 12 项。因此不能直接把标签列表与数值数组逐项配对。导出文件保留原始数组、`LabelIJArray`、`LabelJIArray`、`SymmetryList` 和组分顺序；在接入计算程序之前还需要验证方向展开与公式约定。

另两个接口直接试调用出现问题：`GetBinaryPropertyValue` 抛出内部 `NullReferenceException`，`GetAllUnaryPropertyValues` 报告 `Error setting working compounds`。本次可复现脚本使用已经成功验证的逐条索引读取路径，不依赖这两个批量或便捷接口。

## 安装包拆解结果

安装介质位于桌面的 `AspenONE V15.0(1)\3-ENG\Aspen-V15-ENG (2)\aspenONEMedia\aspenonesuite\Aspen Properties V15 (64bit)\`。

- `APED_P~1.cab` 包含 `apesv150_backup.tar`。
- `APED_P~2.cab` 包含 `apv150_backup.tar`、`nistv150_backup.tar`、`factv150_backup.tar`、`apldb_backup.tar` 等文件；实际文件名带安装器组件标识后缀。
- 已使用 7-Zip 解出 `apv150_backup.tar`，大小 251,881,472 字节，内含 60 个成员。
- 其中 `toc.dat` 以 `PGDMP` 开头，并包含 `active_propvalueconst`、`active_databanks`、`active_compoundidentifiers` 的表定义信息，证实这是 PostgreSQL 的 tar 格式数据库转储。

因此，安装介质也带有可拆出的数据库备份，且至少这一组是 PostgreSQL 格式；不能把它与本机正在运行的 SQL Server MDF 混为一谈。本次未恢复该 PostgreSQL 转储，也未验证它与已安装 SQL Server 库的逐行一致性。解包本身并不能证明其中所有参数为明文。

## 其他 SQLite 文件

`C:\Program Files\AspenTech\AprSystem V15.0\GUI\Xeq\` 中另有：

| 文件 | 实测状态 |
| --- | --- |
| TDE9i.sqlite | 标准 SQLite，可只读打开，含 HISTORY、SOURCE2_MOLFILE |
| TIIS.sqlite | 标准 SQLite，可只读打开，含 GeneralData、Tc、Pc、UNIFAC、COSMONEW 等表 |
| TDE9m.sqlite | 无标准 SQLite 文件头，普通 SQLite 打开失败 |
| TDE9r.sqlite | 无标准 SQLite 文件头，普通 SQLite 打开失败 |

后两者可能采用加密或其他封装，本次没有进一步判定。不能把这些文件直接当作全部 APED 主库。

## 复现与验证

仓库只保存调查文字与自写脚本。实际产物位于被 Git 忽略的 `.local/property-database/verified-export/`：

- 四个 `*-catalog.sqlite`：组分标识、子库、物性定义、单位、元素标签、组分对等十类元数据表；不含完整数值库。
- `inventory.json`：四库表结构、精确行数与数值编码统计。
- `sample-plan.json`：266 条参数读取请求。
- `parameters.json`：266 条明文参数及元数据，失败数 0。
- `validation.json`：本次独立核对摘要。

Python 需要 `pyodbc`，本机测试使用 Python 3.12.14、pyodbc 5.5.0、Microsoft ODBC Driver 17。API 导出需 Windows PowerShell 5.1 和本机对应版本的 Aspen DLL。

从仓库根目录运行，输出目录必须是新的目录：

```powershell
& '.local-tools/research/venv/Scripts/python.exe' `
  'tools/inspect_aspen_properties.py' `
  --output '.local/property-database/another-export'

powershell.exe -NoProfile -NonInteractive -ExecutionPolicy Bypass `
  -File 'tools/Export-AspenPropertySample.ps1' `
  -PlanPath '.local/property-database/another-export/sample-plan.json' `
  -OutputPath '.local/property-database/another-export/parameters.json'
```

已完成的检查：四个 SQLite 文件各自 `PRAGMA integrity_check` 返回 `ok`；每个导出元数据表行数与 SQL 原表相等；266 条请求与输出身份完全一致且无重复；所有输出数值有限；三种物质的 MW、TB 共 6 项与相同子库的 SQL 明文值独立核对一致。

## 对 Mac 项目的含义

组分查找功能可以利用提取的名称、CAS、同义词等元数据。明文参数可以通过 JSON 或进一步转换后的 SQLite 在 Mac 读取，提取阶段目前依赖 Windows 上的原装 API。

全量迁移还需扩展读取计划，覆盖各子库、组分对、电解质、聚合物及其他数据类型，验证公式编号、方向展开、单位、缺失值、温度区间、数据来源和搜索优先级。目前实际明文验证范围是 APV150 的 PURE41 与 VLE-IG 样本，不能据此宣称另外三个库的全部数值已验证。

物性参数不是 Aspen 计算引擎。当前 Qt 界面仍未接入状态方程、活度系数模型、闪蒸和流程求解器；本次没有把导出数据嵌入应用。

## 依据

本机 SQL、程序集返回值、安装介质和上述导出产物是数量及可提取性结论的直接依据。版本行为可在以下随软件安装的帮助文件核对：

- `C:\ProgramData\AspenTech\APED V15.0\HtmlHelp\Content\html\About_the_Aspen_Properties_Enterprise_Database.htm`
- 同目录 `Database_Security.htm`：数值加密及受限数据库机制。
- 同目录 `Create_Databank_Script_File.htm`：`.aprdts` 是选择数据复制范围的脚本，不等于明文参数转储。
- `C:\ProgramData\AspenTech\Aspen Plus V15.0\HtmlHelp\Subsystems\apr-ug2\Content\html\Details About Retrieving Parameters.htm`：界面 Retrieve Parameters 可将参数复制到输入。
- 同目录 `Importing and Exporting IK-CAPE Property Data.htm`：`PROPERTY-REPORT NEUTRAL` 可请求 IK-CAPE 导出；本次未运行此导出路线。

产品定位参见 [AspenTech 官方 Aspen Properties 页面](https://www.aspentech.com/en/products/engineering/aspen-properties)，本报告的数据库计数使用本机实测值。
