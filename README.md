# Aspen V15 源码研究

逐文件任务从[项目核心指令](AGENTS.md)、[精简执行规则](docs/reverse-execution-workflow.md)和[当前工作状态](docs/reverse-work-status.md)开始；总纲、详细规则和历史证据按需查阅，避免每轮全文重复读取。

开发范围包括 **Aspen Plus 与独立的 Aspen Properties**。Properties 主安装包及配套数据库服务器已纳入第 1 步盘点和分类复核；当前尚未确定的处理路线为零，读取限制、解码及反编译验收仍分别记录。双归属文件在 Plus、Properties、共用三份清单同时列出。 [完整分类清单下载](inventories/2026-11-19/README.md) · [盘点与验证](docs/plus-properties-inventory.md) · [Plus 分类](docs/aspen-plus-classification.md) · [Properties 分类](docs/aspen-properties-classification.md) · [共用文件](docs/plus-properties-shared-files.md)

当前工作按原版文件逐个核对反编译源码。已确认来源的两类代码各有独立的本地目录和说明。

后续按[逐文件逆向执行规则](docs/reverse-execution-workflow.md)从“需要逆向”清单选取起点，判断孤立或连锁处理，验收归档后同步完成状态。下表是既有归档快照，首次衔接按新规则复核；后续完成标记通过新台账及清单视图关联，历史分类不覆盖。

| 分类 | 原版文件 | 本地目录 |
| --- | ---: | --- |
| 第一类，反编译已完成 | 4 | `.local/source-classification-20261118/01-completed/` |
| 第二类，反编译未完成 | 35 | `.local/source-classification-20261118/02-incomplete/` |

第一类目录的 `README.md` 记录整份反编译的完成依据。四件历史成果已在后续轮次复验，和其他已验收成果一起发布到[已完成逆向目录](reverse/01-completed/README.md)。第二类每份 `.cs` 都有同目录的同名 `.md`，逐份记录来源、范围和缺口。未完成成果和原版二进制仅存本机。 [归档和证据说明](docs/step-2-source-attribution.md#当前源码归档)

当前分支已移除归入第三类的 45 个 Qt 应用源文件，Windows 和 macOS 的应用构建及 Qt 集成测试暂停。旧工程的功能、构建和测试记录仍可从清理前的提交查阅。 [旧 Qt 工程 README](https://github.com/DenseFLoe/Aspen-for-mac/blob/02c9f6f6aa75faf3efd39b217b00c39184c51678/README.md)

资源解析、数据库导出校验、只读库工具及其 Python 测试仍可独立使用。已提取的数据库、校验记录及压缩归档长期保留在本机。 [开发顺序](docs/development-requirements.md) · [数据库永久保留原则](docs/database-preservation.md)

## 独立保留的数据库与公式

以下资料独立于两类反编译源码，长期保留原目录和压缩归档，开发、切换分支及清理均不得删除或覆盖。仅本地保存，迁移电脑时需单独备份。

| 资料 | 本地目录 | 说明 |
| --- | --- | --- |
| 数据库 | `.local/property-database/plaintext-export/`；归档在 `.local/property-database/archives/` | [导出范围、单位、关系与已知限制](docs/plaintext-database-export.md) |
| 公式及流体数据 | `.local/formula-extraction-20261116/`；归档在 `.local/extraction-archives-20261117/aspen-v15-formulas-*` | [文档公式、图片转录和流体文件](docs/formula-extraction.md) |

原版界面与按钮研究、资源图标、提取与恢复工具继续保留。旧 Qt 工程可从上述历史提交恢复；当前主线的交付仍为逐文件反编译与归档。
