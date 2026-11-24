# Aspen V15 源码研究

[本机已安装文件统一清单](docs/installed-baseline.md) · [四份验收清单](逆向成果/README.md) · [本机逐件总表](逆向成果/本机逐件总表.csv) · [工作计划、研究报告、工具与原件清单](项目资料/README.md)

逐文件任务从[项目核心指令](AGENTS.md)、[精简执行规则](docs/reverse-execution-workflow.md)和[当前工作状态](docs/reverse-work-status.md)开始；总纲、详细规则和历史证据按需查阅，避免每轮全文重复读取。

开发基准为本机已安装的 **Aspen Plus 和 Aspen Properties V15**。两个产品合并盘点，按文件 SHA-256 去重并保留实际路径与产品归属。

从[本机统一清单](docs/installed-baseline.md)选取需要逆向的文件，按[逐文件逆向执行规则](docs/reverse-execution-workflow.md)逐件核验和归档。[静态验收通过](逆向成果/静态验收通过/) · [静态验收未通过](逆向成果/静态验收未通过/) · [待静态验收](逆向成果/待静态验收/) · [未成功](逆向成果/未成功/)

当前分支已移除归入第三类的 45 个 Qt 应用源文件，Windows 和 macOS 的应用构建及 Qt 集成测试暂停。旧工程的功能、构建和测试记录仍可从清理前的提交查阅。 [旧 Qt 工程 README](https://github.com/DenseFLoe/Aspen-for-mac/blob/02c9f6f6aa75faf3efd39b217b00c39184c51678/README.md)

资源解析、数据库导出校验、只读库工具及其 Python 测试仍可独立使用。已提取的数据库、校验记录及压缩归档长期保留在本机。 [开发顺序](docs/development-requirements.md) · [数据库永久保留原则](docs/database-preservation.md)

## 独立保留的数据库与公式

以下资料独立于两类反编译源码，长期保留原目录和压缩归档，开发、切换分支及清理均不得删除或覆盖。仅本地保存，迁移电脑时需单独备份。

| 资料 | 本地目录 | 说明 |
| --- | --- | --- |
| 数据库 | `.local/property-database/plaintext-export/`；归档在 `.local/property-database/archives/` | [导出范围、单位、关系与已知限制](docs/plaintext-database-export.md) |
| 公式及流体数据 | `.local/formula-extraction-20261116/`；归档在 `.local/extraction-archives-20261117/aspen-v15-formulas-*` | [文档公式、图片转录和流体文件](docs/formula-extraction.md) |

原版界面与按钮研究、资源图标、提取与恢复工具继续保留。旧 Qt 工程可从上述历史提交恢复；当前主线的交付仍为逐文件反编译与归档。
