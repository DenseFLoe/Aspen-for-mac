# macOS 数据库窗口可访问性崩溃修复与复验

日期：2026-11-15（北京时间）。分支 `codex/mac-accessibility-fix`，基线 `25e90c3`。所有改动在独立工作树；原工作区 UI 开发及原始数据库资产不参与本次修改。

## 证据与修复范围

Mac arm64 打包复制版在数据库窗口选择合成 SQLite 后，两次读取可访问性树出现 EXC_BAD_ACCESS / SIGSEGV，栈顶为 `-[QMacAccessibilityElement accessibilitySelectedChildren]`。没有取得该包的完整符号化报告和 Qt 精确版本，不能把上游缺陷认定为本次已证实的唯一根因。

Qt [QTBUG-149612](https://qt-project.atlassian.net/browse/QTBUG-149612) 记录了相同栈顶和表格查询触发路径。原生表格占位节点共享父接口 ID；某些版本释放这些节点时错误删除接口，造成后续选中项访问失效。Qt 已提交[所有权修复 b74d6cb3c](https://github.com/qt/qtbase/commit/b74d6cb3c)。本次采用可验证的依赖隔离修复：macOS 固定为 Qt **6.8.3**，其 [Cocoa 节点析构实现](https://github.com/qt/qtbase/blob/v6.8.3/src/plugins/platforms/cocoa/qcocoaaccessibilityelement.mm) 不含该回归的接口删除逻辑。不是宣称旧 Qt 没有其他缺陷；后续升级到含上游修复的版本需要重新通过本文原生和实机检查。

- CMake 拒绝其他 macOS Qt 版本，CI 使用固定的 Qt 官方二进制安装，不再跟随 Homebrew 的 Qt 更新。
- 打包要求显式 Qt 前缀，校验 qmake 版本；应用检查构建/运行 Qt 版本一致。Qt 6.8.3 的导出目标还携带旧 Carbon AGL 链接，本项目移除这项 Cocoa 应用不使用的依赖，兼容新版 Xcode SDK。
- 保持原生可访问性开启，没有关闭 VoiceOver、删掉表格语义或给 Qt 注入运行时补丁。
- 新增 `--accessibility-self-check`，从复制后的应用包加载 Cocoa 插件，查询真实原生节点、替换占位单元、切换行列和释放窗口。包内 Cocoa 检查失败时不生成成功 ZIP。
- 新增数据库窗口测试：合成库只读哈希不变、重复查询、空结果、参数 200/2 条翻页、来源、加入/移除、缺库和关闭重开。与原测试共用合成夹具。
- 原生探针通过 Qt Cocoa 的 Objective-C 类/选择器调用同一个 `accessibilitySelectedChildren` 入口；缺少该入口会失败。它不替代外部 AX 客户端的跨进程扫描及原生文件选择器验收。

## 自动检查

Windows Qt 6.8.3 构建及完整 CTest、macOS 原生 CTest 和包内检查的最终提交与结果在下方里程碑记录。offscreen 检查本身不能证明 Cocoa 崩溃已解决。所有测试库均为临时合成数据，不读取原始导出及归档。

macOS CTest 包含 `database-accessibility`（offscreen）、`database-accessibility-cocoa`（原生 Cocoa）和 `ui-smoke`。原生测试必须运行，不能把它跳过后称为通过；需要图形登录会话。跨进程 AX 仍由下面实机步骤核验。

## Mac 构建

使用 Qt 官方安装器安装 6.8.3 macOS，或用 aqtinstall 安装到全新的本地路径。以下路径仅为示例，已存在时另选新目录：

```sh
python3 -m venv .local/aqt-ax-683
.local/aqt-ax-683/bin/python -m pip install aqtinstall==3.3.0
.local/aqt-ax-683/bin/python -m aqt install-qt mac desktop 6.8.3 clang_64 -O .local/qt-ax-683
export QT_ROOT_DIR="$PWD/.local/qt-ax-683/6.8.3/macos"
"$QT_ROOT_DIR/bin/qmake" -query QT_VERSION
cmake -S . -B build/mac-ax-683 -G Ninja -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_PREFIX_PATH="$QT_ROOT_DIR" -DBUILD_TESTING=ON
cmake --build build/mac-ax-683 --parallel 3
ctest --test-dir build/mac-ax-683 --output-on-failure
sh tools/package_macos.sh build/mac-ax-683 "$QT_ROOT_DIR"
```

qmake 必须输出 `6.8.3`。不要沿用已使用其他 Qt 版本配置的构建目录，也不要从旧包手工替换部分 dylib。脚本将包复制到新的 `macos-package.XXXXXX` 目录并执行 offscreen 保存/SQLite 自检和原生 Cocoa 自检。

## Mac arm64 实机复验

1. 记录本分支提交、macOS 版本、CPU 架构、Qt 版本及包路径。从上述新目录复制应用到另一个新目录启动，确认没有启动旧包。
2. 启用原先会触发崩溃的可访问性扫描客户端。先对空窗口和数据库窗口各读取至少 10 次可访问性树。
3. 在“真实组分与物性数据库”点击“选择数据库…”，选择此前复现用的合成 SQLite。取消一次再重新选择一次，检查提示和后续查询。
4. 搜索合成记录的名称、CAS、别名；选中结果及参数，再读取至少 20 次可访问性树。同步检查 VoiceOver 或 Accessibility Inspector 能读到行和单元值，选中项数量正确。
5. 来回切换有结果/无结果/空查询；若库含多页参数，选中参数后前后翻页。加入/移除组分、撤销、关闭重开窗口。普通窗口和原生全屏分别重复。
6. 保存项目、退出重开，确认合成组分身份和来源仍在。比较合成库前后 SHA-256，库内容应不变。
7. 如仍崩溃，保留完整 `.ips`、包内 QtCore/libqcocoa 的版本与 UUID、精确操作和扫描时序；本次依赖隔离并未充分解释该故障，需要继续定位。
8. **真实组分查询仍待验收**：另行提供已核验的真实运行库后，再查 WATER / 7732-18-5、ETHANOL、来源及项目保存往返。合成数据和 CI 通过不代表真实物性或计算验收通过。

## 里程碑

- 依赖隔离与回归：`0dc275b0bc3c1778918bc448cad4432250c0bee0`。
- 最终应用与构建代码：`beefe3ac34ca3efcc80e82eeb91025c7fffcc807`（含新版 SDK 的 AGL 链接兼容修正）。
- Windows Qt 6.8.3 / MinGW：构建通过，完整 CTest **2/2**（74.08 秒）；Python 运行库构建回归 **2/2**。测试仅使用合成库。
- [macOS arm64 Actions](https://github.com/DenseFLoe/Aspen-for-mac/actions/runs/43695487433) 全部通过：Python **13/13**、资源目录核验、构建、CTest **3/3**（18.79 秒）。其中原生 `database-accessibility-cocoa` 通过（0.93 秒），并非 offscreen 替代。
- 新目录复制包的 `--self-check` 和 `--accessibility-self-check` 均通过，日志确认 `Cocoa accessibility lifecycle passed; Qt 6.8.3`。构建产物和数据库未上传仓库。
- 本地与远端代码文件树一致；原工作区源码、原始数据库导出及归档未修改。此文档记录提交只更新检查结果。
- **仍待验收**：用户 Mac 上原先触发崩溃的外部 AX 扫描、原生文件选择、真实运行库查询。当前证据支持隔离已知 Qt 缺陷；未对原始崩溃包做逐帧根因确认。
