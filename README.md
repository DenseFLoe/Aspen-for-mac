# Aspen Plus UI Shell

基于 Aspen Plus V15 中文界面的 Qt 6 / C++17 桌面界面外壳。保留 **97 个原版图标、17 个已核对的组分页面、39 个页内标签**和 31 张参考裁图；新增 **47 个模块、2,947 份静态布局、289 个传统对话框和 106 份菜单树**的可搜索目录与 Qt 预览。布局数包含页签和控件片段，不代表同等数量的完整业务页面。

左侧导航、功能区和菜单可跳转页面及资源窗口，支持后退/前进、单位联动、数据库列表移动排序及向导导航。恢复页面的输入、勾选、注释和标签状态保留于本次会话；补充 173 份原版图像、285 处图像引用。原版直接核实的下拉列表、动态状态及未完成边界见 [交互补齐记录](docs/ui-interactions.md)。当前版本没有 Aspen 计算引擎、物性数据库检索或文件保存功能，不产生模拟结果，退出后不保存界面输入。

左侧“全部资源”按模块浏览，可搜索页面、按钮和菜单；“设置、方法、物性组”入口直接打开恢复布局。已核实的动态选项和静态声明的输入可操作；需要引擎的表格、命令和未知列表保持不可用。每页保留来源资源信息；扫描方法、完整清单和上一轮边界见 [界面资源恢复报告](docs/ui-resource-recovery.md)。

本机 V15 四个 APED 主库的 **6,345,071 个数值单元**已导出明文，另保留 1,464,605 条 API 参数视图、完整 active 关系表以及 TDE、SQLite、Access 附属数据。数据、来源清单和核验报告位于本地 `.local/property-database/plaintext-export/`，尚未接入本应用。复现、跨平台恢复及尚未解析的旧格式文件见 [明文导出说明](docs/plaintext-database-export.md)；早期调查保留在 [调查记录](docs/property-database-investigation.md)。

## 页面范围

- 规定：选择、石油、非常规、SQL 服务器数据库、注释。
- 分子结构、原油/混合油、轻端物性、虚拟组分、组分属性、Henry 组分、UNIFAC 基团。
- 石油表征：列表、生成、分析选项（油品化验数据程序/混合选项/高级）、所选方法、结果（摘要/状态）。
- 聚合物：表征、选项、注释及分布；生物组分：规格、生物原料、注释。

39 个标签中含空案例下不可用的标签，保持灰显；未采集的内容没有补造。详细覆盖、交互限制和截图对应关系见 [本轮记录](docs/components-research.md)。原版图像来源见 [图像清单说明](docs/ui-assets.md)。

![原版组分页截图索引](docs/reference-overview.jpg)

## Mac 构建与测试

依赖：CMake 3.21+、Qt 6.5+ Widgets / Test、C++17 编译器。用户已确认上一版在 Mac 编译；本轮代码在 Windows Qt 6.8.3 / MinGW 13.1 编译及 CTest 通过。新增 macOS GitHub Actions 配置，运行结果以 Actions 为准。

```sh
brew install qt cmake ninja
cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_PREFIX_PATH="$(brew --prefix qt)"
cmake --build build
ctest --test-dir build --output-on-failure
open build/AspenPlusUIShell.app
```

只构建程序时可加 `-DBUILD_TESTING=OFF`。Qt 官方安装器用户将 `CMAKE_PREFIX_PATH` 改为对应 `macos` 目录。测试默认使用 offscreen 平台，覆盖全部恢复布局/对话框/菜单的创建、47 个模块导航、资源搜索、功能区入口，以及原有图标、17 页导航、标签、注释状态、弹窗关闭和最小窗口。设置 `ASPEN_CAPTURE_DIR` 可保存代表页面渲染图到本机目录。macOS 发布打包、签名、公证仍未配置。

## 结构

| 文件 | 内容 |
| --- | --- |
| `src/UiShell.cpp` | 功能区、导航树和文件侧栏 |
| `src/ComponentWorkspace.cpp` | 页面构造器、切换状态和查询弹窗 |
| `src/RecoveredWorkspace.cpp` | 静态布局、对话框和菜单的按需 Qt 渲染 |
| `ui/components.json` | 17 页、39 标签及空案例控件数据 |
| `ui/recovered/` | 47 模块布局、按钮/菜单清单、来源与比对报告 |
| `ui/aspen-plus.json` | 功能区、按钮、菜单清单 |
| `ui/icons/` | 无损 PNG 图集及逐图来源清单 |
| `docs/reference/` | 31 张原版裁图和校验清单 |
| `tests/UiSmokeTest.cpp` | 导航和资源集成检查 |
| `tools/scan_aspen_ui.py` / `tools/build_ui_catalog.py` | 原生/托管资源扫描及便携清单生成 |
| `tests/test_ui_resources.py` | BAML、Unicode 资源、对话框及菜单解析检查 |

原版截图与图标版权归原权利人；本仓库不为这些图像授予新的许可。原始程序二进制、工具、构建产物及完整本机会话截图均不进入版本控制。
