# 云端与本地分支功能标注

核对日期：2026-11-15（北京时间）。仓库：`DenseFLoe/Aspen-for-mac`，默认分支为 `main`。

用户最新确认：**本地与 GitHub 只保留最新 `main`，取消工具分支必须独立保留的约定，删除其余本地分支及云端工具分支。** 工具代码和既有提交已在主线历史中；数据库资产的永久保留规则继续执行。

## 本次统一为单一主分支（2026-11-15）

执行前 GitHub 默认分支为 `main@f7f3563b77b0d9452f8ec3e57c8b77957fd945ae`，另有 `codex/plaintext-database-export@a9ed53c2664c6dcb14ffd5370d1a984a467f7ab8`。本地 `main` 快进同步 GitHub；其余 7 条本地分支头均经祖先检查，已包含在最新主线中。

清理范围为本地 `codex/development-requirements`、`codex/interaction-parity`、`codex/mac-accessibility-fix`、`codex/plaintext-database-export`、`codex/project-database`、`codex/simulation-ui-parity`、`codex/ui-object-interactions`，以及云端工具分支和本次临时工作分支。Mac 修复的关联工作树仅解除分支绑定，保留文件及本地构建内容。

GitHub 连接器不提供直接删除分支的接口，因此使用临时分支中的一次性 Actions 任务：核对完整分支集合、精确 SHA 和工具提交祖先关系，再以 SHA lease 原子删除工具分支及临时分支。临时工作流不进入 `main`。最后复核 GitHub 与本地仅有 `main` 且提交相同，清除过期的远程跟踪引用。

本次只更新分支策略文档并清理引用，不改应用代码；沿用 `f7f3563` 的成功 [macOS Actions 43708516142](https://github.com/DenseFLoe/Aspen-for-mac/actions/runs/43708516142)。文档执行差异检查与暂存内容复核；分支操作执行祖先关系、精确 SHA 和最终清单检查。

## 数据库与键鼠交互整合（历史记录）

本轮将 `codex/interaction-parity` 的两个新提交 `51cf289dcb1bd33ef2ce41b1613f73311865f2e2`、`ebe47d0ea91053075e022cee9d06e4b504c7ab78` 纳入 `main`。旧主线 `73728c5` 是最新交互提交 `ebe47d0` 的祖先，可正常快进；本报告仅补充文档，不做 squash、rebase 或历史改写。

新增内容包括化合物查找窗口、数据库子库筛选、流程图设备／流股／画布菜单、取消放置、键盘反馈、多选拖动单次撤销，以及模拟导航与过滤状态修正。详细实现与业务边界见 [交互整改记录](interaction-parity.md)。上一轮记录中的嵌套对象入口、过滤和模式同步已有专项回归；Mac 外部 AX、原生文件选择、真实运行库实机验收及计算能力不能因此标为完成。

本轮验证：

- `ebe47d0` 的 [macOS Actions 43707534958](https://github.com/DenseFLoe/Aspen-for-mac/actions/runs/43707534958) 成功，包含 Qt 6.8.3 构建、CTest 和包内 Qt／SQLite 自检。
- 本地 Mac arm64 / Qt 6.8.3 新目录 Release 构建通过；显式设置空 `ASPEN_PROPERTY_DATABASE` 后，CTest **3/3** 通过（24.34 秒），含 Cocoa 原生可访问性。首次未隔离用户数据库配置时，原有“未连接”状态断言失败；隔离后通过，未修改或清除用户偏好。
- 本地隔离 Python 3.12 环境安装 CI 同版本解析依赖后，资源解析 **8/8**、明文导出恢复 **3/3**、运行库构建 **2/2**，共 **13/13** 通过；全部使用合成夹具。资源目录核验通过（59 模块、3,086 布局、289 对话框、117 菜单）。
- 本地新目录部署包首次启动被系统终止；`codesign --verify --deep --strict` 报资源签名不一致。仅对本轮生成的临时应用包补做 ad-hoc 签名后，签名核验、`--self-check` 与 Cocoa `--accessibility-self-check` 均通过。未改打包脚本；此结果不表示正式签名、公证或原脚本在本机无额外步骤即可完成 ZIP。
- 新增代码与测试已审查；本轮只补充整合文档，不额外扩展功能。Windows 检查沿用功能分支已有记录，本轮不重跑 Windows 构建。

该轮仅清理 `codex/interaction-parity@ebe47d0` 和临时整合分支 `codex/integrate-main-20261115-interaction`，当时保留了工具分支。此保留决定已被上方最新单一主分支策略取代。

本轮不清理 Git 对象、构建目录或数据库资产，不上传本地应用包、测试环境和数据。当前源码检出中的受保护导出、归档和保留声明路径仍不存在；未访问或处理其他位置的数据资产。

## 上一轮整合（历史记录）

整合提交 `c37eceb5ed6a310caa2ba5db93d917aebf0ba929` 正常合并两条最新开发线，保留原有父提交与全部开发历史，不做 squash、rebase 或强制改写。原 `origin/main@7c19bc5` 是整合结果的祖先，主线可快进更新。

| 整合内容 | 原分支头 | 说明 |
| --- | --- | --- |
| 最新对象交互、项目保存与只读数据库 | `25e90c3` | 已包含静态恢复 `384392b`、对象交互 `2e17f09`、开发要求 `a07bf11`、保存 `127fd28`、检索 `a389c41` 和后续修复 |
| 模拟 / 主工艺流程界面对齐 | `5793d95` | 包含界面提交 `29d29c8`，新增模型选项板、模拟导航、锁定和缩放 |
| macOS 可访问性修复 | `d3a5859` | 固定 Qt 6.8.3，补充 Cocoa 原生回归、包内检查及新版 SDK AGL 兼容修正 |
| 明文数据库提取与恢复工具 | `a9ed53c` | 其全部提交原已进入 main；当时独立保留的分支现纳入清理 |

## 最终保留分支

| 分支 | 用途 | 基线 |
| --- | --- | --- |
| `main` | 唯一保留的本地及云端主分支 | 本报告提交，继承 GitHub `f7f3563`，包含整合提交 `c37eceb` 及最新交互提交 `ebe47d0` |

提取、核验和恢复工具代码继续保存在 `main`。后续工作可按仓库流程使用临时分支，验证并整合后清理，不再为工具分支设置永久保留例外。

## 上一轮清理对象（历史记录）

以下分支头必须先通过 `git merge-base --is-ancestor <tip> main`，且确认远端没有新增提交，才能删除引用：

| 分支 | 已核对的分支头 |
| --- | --- |
| `codex/development-requirements` | `a07bf119cf7c2c4a9d4a39447d18292cae523c0e` |
| `codex/ui-object-interactions` | `2e17f09f543b2e7204f36e6f3ca0fd32ae557b49` |
| `codex/project-database` | `25e90c3ca40e3e6ef841420bd40c48bea236aff1` |
| `codex/simulation-ui-parity` | `5793d954bd38215d076f481f9fd04ffc63aded08` |
| `codex/mac-accessibility-fix` | `d3a58599ed1db1868364487c04fcc06f69c375f8` |
| `codex/integrate-main-20261115` | 本次临时整合分支；文档记录完成并合入后清理 |

该轮清理方式：整合提交快进推送到 GitHub main；上述五个旧开发分支在逐个核对分支头及祖先关系后，以精确旧 SHA 约束的原子删除完成云端清理。临时整合分支也随报告清理，本地旧分支使用非强制删除。当前保留集合以上方单一主分支策略及 GitHub 实时复核为准。

## 上一轮验证与边界（历史记录）

- 本地 Python 3.12：资源解析 8/8、明文导出恢复 3/3、运行库构建 2/2，合计 13/13 通过；全部使用合成夹具。
- 资源目录核验通过：59 个模块、3,086 份布局、289 个传统对话框和 117 份菜单树。
- 整合提交 `c37eceb` 的 macOS Qt 6.8.3 构建、CTest 3/3（含 Cocoa 原生可访问性）和包内 Qt／SQLite 自检全部通过：[GitHub Actions 43696203183](https://github.com/DenseFLoe/Aspen-for-mac/actions/runs/43696203183)。本次不在本机重跑 Qt 构建，以该固定版本的 macOS Actions 验证整合结果。
- 各功能分支已有的 Windows 检查记录仍保留，本次未重新运行 Windows 构建。
- 外部跨进程 AX 扫描、原生文件选择器、真实运行库和 Mac 实机视觉验收仍待完成。自动检查及合并不等于这些验收已通过，也不表示已有计算引擎。
- 静态审查另发现模拟树的嵌套对象页面入口、“仅输入”过滤及资源浏览后的模式状态仍需专项回归；本次不扩展功能或将这些行为标为已验证。

功能证据与剩余范围见 [项目保存](project-persistence.md)、[只读数据库](runtime-property-database.md)、[模拟界面对齐](simulation-ui-parity.md)、[Mac 可访问性](macos-accessibility.md) 和 [开发要求](development-requirements.md)。

## 安全复核方式

先 fetch 并读取 GitHub 实时分支清单，核对工作区无未提交改动及各分支头的祖先关系；整合检查通过后正常快进推送 main，再清理已合并引用。本地删除使用 `git branch -d`，不强删未合并分支。最终重新读取 GitHub 分支清单、默认分支与提交 SHA，并核对本地引用一致。

本次 Windows 工作区实际存在 `.local/property-database/` 下的导出、归档与保留声明。操作前后核对整个目录的文件清单、大小、修改时间和 6 个关键文件 SHA-256；受保护资产保持不变。不运行 `git clean`，不清理 Git 对象，不删除构建产物，不对数据库资产执行导出、恢复、覆盖、移动或删除。保护规则见 [数据库永久保留原则](database-preservation.md)。

## 历史记录说明

此前清理曾保留 main 和提取工具分支，随后又创建对象交互、项目数据库、模拟界面和 Mac 修复分支，因此旧版“两条分支”清单一度不再代表实时状态。早期清理及文件树等价性记录保留在 `7c19bc5:docs/branch-status.md`，可通过 Git 历史查看。本次以当前整合结果重新统一主线，不丢弃这些历史提交。
