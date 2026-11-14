# Aspen Plus UI Shell

基于 Aspen Plus V15 中文界面的 Qt 6 / C++17 桌面界面外壳。现已接入 **97 个原版图标、17 个“物性 → 组分”导航页面及 39 个页内标签**，并保存 31 张原版界面裁图用于核对。原有文件侧栏、四个功能区和已观察菜单继续可用。

左侧导航、功能区“组分/绘制结构”、页面选择菜单和页内标签会切换实际 Qt 页面。每页保留独立的控件和标签状态；注释可在本次运行期间编辑。“查找”打开化合物查询界面预览。当前版本没有 Aspen 计算引擎、物性数据库或文件保存功能，不产生模拟结果，注释退出后不保存。

本机 V15 的物性库已完成提取可行性调查，验证了四库元数据和 266 条明文参数导出。调查结论、适用范围与复现脚本见 [物性数据库调查](docs/property-database-investigation.md)。导出数据保留在本地，尚未接入本应用。

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

只构建程序时可加 `-DBUILD_TESTING=OFF`。Qt 官方安装器用户将 `CMAKE_PREFIX_PATH` 改为对应 `macos` 目录。测试默认使用 offscreen 平台，覆盖图标装载、17 页导航、可用标签、注释状态、弹窗关闭和最小窗口。设置 `ASPEN_CAPTURE_DIR` 可保存各页渲染图到本机目录。macOS 发布打包、签名、公证仍未配置。

## 结构

| 文件 | 内容 |
| --- | --- |
| `src/UiShell.cpp` | 功能区、导航树和文件侧栏 |
| `src/ComponentWorkspace.cpp` | 页面构造器、切换状态和查询弹窗 |
| `ui/components.json` | 17 页、39 标签及空案例控件数据 |
| `ui/aspen-plus.json` | 功能区、按钮、菜单清单 |
| `ui/icons/` | 无损 PNG 图集及逐图来源清单 |
| `docs/reference/` | 31 张原版裁图和校验清单 |
| `tests/UiSmokeTest.cpp` | 导航和资源集成检查 |

原版截图与图标版权归原权利人；本仓库不为这些图像授予新的许可。原始程序二进制、工具、构建产物及完整本机会话截图均不进入版本控制。
