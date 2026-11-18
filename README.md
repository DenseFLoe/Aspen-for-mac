# Aspen V15 源码研究

当前工作按原版文件逐个核对反编译源码。已确认来源的两类代码各有独立的本地目录和说明。

| 分类 | 原版文件 | 本地目录 |
| --- | ---: | --- |
| 第一类，反编译已完成 | 4 | `.local/source-classification-20261118/01-completed/` |
| 第二类，反编译未完成 | 35 | `.local/source-classification-20261118/02-incomplete/` |

第一类目录的 `README.md` 记录整份反编译的完成依据。第二类每份 `.cs` 都有同目录的同名 `.md`，逐份记录来源、范围和已知缺口。反编译源码、索引和原版二进制仅存本机。 [归档和证据说明](docs/step-2-source-attribution.md#当前源码归档)

当前分支已移除归入第三类的 45 个 Qt 应用源文件，Windows 和 macOS 的应用构建及 Qt 集成测试暂停。旧工程的功能、构建和测试记录仍可从清理前的提交查阅。 [旧 Qt 工程 README](https://github.com/DenseFLoe/Aspen-for-mac/blob/02c9f6f6aa75faf3efd39b217b00c39184c51678/README.md)

资源解析、数据库导出校验、只读库工具及其 Python 测试仍可独立使用。已提取的数据库、校验记录及压缩归档长期保留在本机。 [开发顺序](docs/development-requirements.md) · [数据库永久保留原则](docs/database-preservation.md)
