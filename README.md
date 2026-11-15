# Aspen Plus UI Shell

**开发强制原则：已提取的数据库及其压缩归档必须长期保留，不得在开发、清理或重建时删除、覆盖。** `.local/` 中的数据资产不是缓存；保护路径、归档核验和未来接入规则见 [数据库永久保留原则](docs/database-preservation.md) 和 [AGENTS.md](AGENTS.md)。

云端与本地分支的功能阶段、同步状态及开发基线见 [分支功能标注](docs/branch-status.md)（2026-11-15 核对）。

后续开发顺序、阶段验收与近期交付范围见 [开发要求与实施顺序](docs/development-requirements.md)。近期优先完成项目保存与真实组分检索，再推进字段、单位、流程图规则及计算能力。

基于 Aspen Plus V15 中文界面的 Qt 6 / C++17 桌面界面外壳。保留 **97 个原版图标、17 个已核对的组分页面、39 个页内标签**和 31 张参考裁图；新增 **59 个模块、3,086 份静态布局、289 个传统对话框和 117 份菜单树**的可搜索目录与 Qt 预览。布局数包含页签和控件片段，不代表同等数量的完整业务页面。

左侧导航、功能区和菜单可跳转页面及资源窗口，支持后退/前进、单位联动、数据库列表移动排序及向导导航。恢复页面的输入、勾选和注释可随项目保存；补充 437 份去重原版图像、685 处图像引用。原版直接核实的下拉列表、动态状态及未完成边界见 [交互补齐记录](docs/ui-interactions.md)。本分支新增自有 `.afmp` 项目保存、打开、另存为与基础撤销重做；对象身份、父子关系、连线和现有页面输入可跨会话恢复。当前没有 Aspen 计算引擎，不产生模拟结果；已接入只读真实组分检索、来源查看与项目组分保存。保存格式、验证与边界见 [项目保存记录](docs/project-persistence.md)。

新增对象工作区：15 类集合、95 种对象类型（含 67 种模块）支持新建、独立输入页签、重命名、复制后解决 ID 冲突及删除；导航节点、对象列表和页签同步更新。模拟模式支持放置模块、双击打开输入、拖动模块和连接流股；RadFrac 支持新增设计规范、调整变量和中段回流子对象。用户组分向导完成后增加组分行及对象节点，输入可随项目保存。实际原版观察、已测试流程与剩余边界见 [对象交互记录](docs/ui-object-interactions.md)。

左侧“全部资源”按模块浏览，可搜索页面、按钮和菜单。对象输入表格支持填写及增删行；未知动态列表可暂存手工输入，但不包含原版候选项校验。模型专属条件、运行时控件和未接入命令仍有缺口，不能将静态布局数量视为交互完成率。每页保留来源资源信息；扫描方法、完整清单和上一轮边界见 [界面资源恢复报告](docs/ui-resource-recovery.md)。

本机 V15 四个 APED 主库的 **6,345,071 个数值单元**已导出明文，另保留 1,464,605 条 API 参数视图、完整 active 关系表以及 TDE、SQLite、Access 附属数据。数据、来源清单和核验报告位于本地 `.local/property-database/plaintext-export/`，本分支从新目录的运行库只读检索。使用方法与范围见 [只读数据库接入](docs/runtime-property-database.md)。复现、跨平台恢复及尚未解析的旧格式文件见 [明文导出说明](docs/plaintext-database-export.md)；早期调查保留在 [调查记录](docs/property-database-investigation.md)。

## 页面范围

- 规定：选择、石油、非常规、SQL 服务器数据库、注释。
- 分子结构、原油/混合油、轻端物性、虚拟组分、组分属性、Henry 组分、UNIFAC 基团。
- 石油表征：列表、生成、分析选项（油品化验数据程序/混合选项/高级）、所选方法、结果（摘要/状态）。
- 聚合物：表征、选项、注释及分布；生物组分：规格、生物原料、注释。

39 个标签中含空案例下不可用的标签，保持灰显；未采集的内容没有补造。详细覆盖、交互限制和截图对应关系见 [本轮记录](docs/components-research.md)。原版图像来源见 [图像清单说明](docs/ui-assets.md)。

![原版组分页截图索引](docs/reference-overview.jpg)

## Mac 构建与测试

依赖：CMake 3.21+、Qt Widgets / Test / Sql、C++17 编译器。macOS 固定 Qt 6.8.3，以隔离 Cocoa 可访问性所有权回归；安装、原生检查和复验见 [Mac 崩溃修复记录](docs/macos-accessibility.md)。其他平台仍支持 Qt 6.5+。用户已确认上一版在 Mac 编译；本轮代码在 Windows Qt 6.8.3 / MinGW 13.1 编译及 CTest 通过。新增 macOS GitHub Actions 配置，运行结果以 Actions 为准。

```sh
brew install cmake ninja
cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_PREFIX_PATH="$QT_ROOT_DIR"
cmake --build build
ctest --test-dir build --output-on-failure
open build/AspenPlusUIShell.app
```

只构建程序时可加 `-DBUILD_TESTING=OFF`。先按修复记录安装 Qt 6.8.3，并将 `QT_ROOT_DIR` 设为其 `macos` 目录。常规测试使用 offscreen 平台；macOS 另强制运行 Cocoa 数据库可访问性回归。常规测试覆盖全部恢复布局/对话框/菜单的创建、59 个模块导航、资源搜索、功能区入口，以及原有图标、17 页导航、标签、注释状态、弹窗关闭和最小窗口。设置 `ASPEN_CAPTURE_DIR` 可保存代表页面渲染图到本机目录。可运行 `sh tools/package_macos.sh build "$QT_ROOT_DIR"` 在新目录生成含 Qt / SQLite 依赖的本地 Mac 应用包；正式签名、公证仍未配置。

## 结构

| 文件 | 内容 |
| --- | --- |
| `src/UiShell.cpp` | 功能区、导航树和文件侧栏 |
| `src/ObjectWorkspace.cpp` / `ui/object-types.json` | 对象生命周期、流程图和输入页映射 |
| `src/UiShellObjects.cpp` | 动态导航节点与对象路由 |
| `src/ComponentWorkspace.cpp` | 页面构造器、切换状态和查询弹窗 |
| `src/RecoveredWorkspace.cpp` | 静态布局、对话框和菜单的按需 Qt 渲染 |
| `ui/components.json` | 17 页、39 标签及空案例控件数据 |
| `ui/recovered/` | 59 模块布局、按钮/菜单清单、来源与比对报告 |
| `ui/aspen-plus.json` | 功能区、按钮、菜单清单 |
| `ui/icons/` | 无损 PNG 图集及逐图来源清单 |
| `docs/reference/` | 31 张原版裁图和校验清单 |
| `tests/UiSmokeTest.cpp` | 导航和资源集成检查 |
| `tools/scan_aspen_ui.py` / `tools/build_ui_catalog.py` | 原生/托管资源扫描及便携清单生成 |
| `tests/test_ui_resources.py` | BAML、Unicode 资源、对话框及菜单解析检查 |

原版截图与图标版权归原权利人；本仓库不为这些图像授予新的许可。原始程序二进制、工具、构建产物及完整本机会话截图均不进入版本控制。
