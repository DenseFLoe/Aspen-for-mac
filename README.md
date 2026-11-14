# Aspen Plus UI Shell

基于 Windows 上 Aspen Plus V15 中文界面的一次初步观察，使用 C++17、Qt 6 Widgets 和 CMake 编写的跨平台桌面界面外壳。当前只实现按钮、功能区切换及菜单展开，不包含 Aspen 计算引擎，也不控制已安装的 Aspen。

本轮研究范围是 **物性 → 组分 → 规定** 页面及其顶部四个功能区：主页、查看、用户定义、资源。没有研究 HYSYS 或其他 Aspen 产品，也没有补画未观察到的菜单内容。

## 已生成的界面

- 顶部快速访问按钮和“自定义快捷工具栏”菜单。
- 四个功能区的按钮分组、文字及本次观察到的禁用状态。
- “文件”侧栏；“新建”和“工具”分组中的已观察按钮。
- 分析、单位集、导航筛选、窗口列表等弹出菜单。
- 左侧物性导航、底部模式入口、空白组分表及页面按钮。

普通按钮和菜单末级条目不连接业务处理。文件打开、保存、删除、安装、网络访问、计算、单位换算及许可证操作均未实现。窗口标题标为“界面研究”。图标采用 Qt 标准图标和自行绘制的几何符号；没有提取或上传 Aspen 二进制文件、安装包或专有图标。

## Mac 后续编译

本轮**未编译、未启动生成的界面、未做二次验证**。下列命令是交接步骤，不是已通过的检查结果。

需要 C++17 编译器、CMake 3.21+ 和 Qt 6.5+（含 Widgets）。在已有 Xcode Command Line Tools 和 Homebrew 的 Mac 上，可按需安装依赖后构建：

```sh
brew install qt cmake ninja
cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_PREFIX_PATH="$(brew --prefix qt)"
cmake --build build
open build/AspenPlusUIShell.app
```

使用 Qt 官方安装器时，将 `CMAKE_PREFIX_PATH` 改成所安装 Qt 的 `macos` 目录。Windows / Linux 也使用同一份 CMake 工程，选择对应的 Qt 6 编译器套件即可。此处仅提供开发运行步骤；发布打包、签名、公证和通用二进制尚未配置。

## 后续接手

1. 首先编译并记录实际 Qt、编译器、CPU 架构和构建结果。
2. 核对中文字体、功能区横向滚动、800×540 以上窗口的布局。
3. 检查文件入口、返回/Escape、四个功能区及五类弹出菜单。
4. 确认末级点击只关闭菜单；不产生文件、网络请求或计算结果。
5. 后续再补采未展开的入口，不把当前清单当作完整 Aspen Plus 功能地图。

## 文件

| 文件 | 用途 |
| --- | --- |
| `ui/aspen-plus.json` | 人工整理的按钮、分组和菜单清单 |
| `src/UiShell.cpp` | 数据驱动的桌面控件布局，末级操作无业务回调 |
| `ui/shell.qss` | 浅蓝色功能区及窗格样式 |
| `docs/ui-research.md` | 观察依据、范围、差异和未覆盖项 |
| `CMakeLists.txt` | Qt Widgets 工程和内嵌 UI 资源 |

实现参考 Qt 官方的 [Widgets 文档](https://doc.qt.io/qt-6/qtwidgets-index.html)、[QToolButton 菜单接口](https://doc.qt.io/qt-6/qtoolbutton.html)和 [CMake 入门](https://doc.qt.io/qt-6/cmake-get-started.html)。项目保留已有 Git 历史及安全上传约定。
