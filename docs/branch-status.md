# 云端与本地分支功能标注

核对日期：2026-11-15（北京时间）。仓库：`DenseFLoe/Aspen-for-mac`，云端默认分支为 `main`。调查时共有 **6 条真实云端分支、9 条本地分支**；本次新增的 `codex/branch-function-audit` 只保存标注，不增加应用功能。

**继续开发优先基于 `codex/preserve-database-archive`（`3add176`）**：它包含当前最完整的界面交互、明文数据库工具及数据库永久保留规则。`codex/ui-interactions` 的应用功能与它相同，少了后续保留文档。云端 `main` 仍停留在早期组分页版本。

## 标注标准

界面按功能分为 U4（最新交互）、U3（资源浏览与预览）、U2+（组分页及浅色主题修复）、U2（组分页）、U1（菜单外壳）、U0（仓库初始化）。数据库另标为 D2（完整明文导出与恢复核验工具）、D1（调查及样本提取）、D0（无相关工具）；P1 表示包含永久保留规则。等级是本次调查的功能阶段，不是软件版本号，也不按提交时间机械排序。

## 分支清单

“本地”指 `refs/heads/*`；“云端”指 GitHub 实时返回的分支，不把本机 `origin/*` 缓存当作真实云端分支。除本地 `main` 和仅本地分支外，下表中的本地与云端提交一致。

| 功能标注 | 分支 | 本地提交 | 云端提交 | 功能与同步状态 |
| --- | --- | --- | --- | --- |
| **U4 / D2 / P1 综合最新** | `codex/preserve-database-archive` | `3add176` | `3add176` | 最新界面交互和明文数据库工具，加独立归档、永久保留规则及 UTF-8 文档修正；比云端 main 多 9 个提交，已包含 main |
| **U4 / D2 应用功能最新** | `codex/ui-interactions` | `db4bf0b` | `db4bf0b` | 页面前进/后退、菜单路由、会话内输入状态、单位联动、数据库列表排序、向导导航及 173 份补充图像；比云端 main 多 7 个提交，已包含 main |
| **U4 / D2 等内容本地副本** | `codex/local-ui-interactions` | `df59d89` | 不存在 | 与 db4bf0b 的整个 Git 文件树完全相同，提交身份不同；没有额外未上传功能，不属于 preserve 分支的提交祖先 |
| **U3 / D2 上一界面阶段** | `codex/ui-resource-recovery` | `5ef0861` | `5ef0861` | 47 模块、2,947 份静态布局、289 个传统对话框、106 份菜单树的搜索及 Qt 预览；已合入 main 的浅色主题修复，比云端 main 多 6 个提交 |
| **U2 / D2 数据工具最新阶段** | `codex/plaintext-database-export` | `a9ed53c` | `a9ed53c` | 完整明文导出、覆盖核验、附属数据和便携恢复工具；界面仍为 17 页/39 标签；相对云端 main 独有 3 个提交，缺少浅色主题修复 1 个提交 |
| **U2 / D1 数据调查阶段** | `codex/property-database-investigation` | `45be18a` | `45be18a` | 数据库结构调查、API 可读性验证和样本提取；未包含后续完整导出工具；相对云端 main 独有 1 个提交，缺少浅色主题修复 1 个提交 |
| **U2+ / D0 默认分支较旧** | `main` | `37ecc9c` | `1fe0e13` | 云端有 97 个原版图标、17 个组分页、39 个页内标签及浅色主题修复；本地 main 只有初始化和工作流文件，落后云端 4 个提交，实际为 U0 |
| **U2 / D0 早期组分页** | `codex/aspen-plus-icons-components` | `5bec246` | 已删除 | 97 图标、17 页/39 标签和导航；是云端 main 的祖先，缺少后续浅色主题修复；本地仍有旧 origin 引用 |
| **U1 / D0 最早界面外壳** | `codex/aspen-plus-ui-menus` | `71b7215` | 已删除 | 基础功能区、按钮及菜单外壳；是云端 main 的祖先，落后 3 个提交；本地仍有旧 origin 引用及失效的 upstream 配置 |

本次报告分支 `codex/branch-function-audit` 基于 `3add176`，同属 **U4 / D2 / P1**，只新增本清单及 README 入口。它不取代上表中的功能开发分支。

## 影响判断的提交关系

数据库工具线和浅色主题修复线曾分叉，所以 `plaintext-database-export` 虽提交时间较晚，仍缺少 main 的浅色主题修复。`78f304f` 把两线合并，后续资源恢复和交互分支同时包含两者。

```text
37ecc9c 本地 main
  └─71b7215 菜单外壳
      └─33a2128 原版图标
          └─5bec246 组分页
              ├─1fe0e13 云端 main：浅色主题修复 ─────────┐
              └─45be18a 数据调查                       │
                  └─d7aee2f 明文导出                   │
                      └─a9ed53c 核验及恢复 ────────────┤
                          78f304f 合并两线 ◀───────────┘
                            └─0f24280 静态资源提取
                                └─5ef0861 资源浏览与预览
                                    ├─df59d89 本地交互副本
                                    └─db4bf0b 云端交互版本
                                        └─10d7a1c 永久保留规则
                                            └─3add176 文档编码修正
```

`df59d89` 和 `db4bf0b` 的文件树均为 `d23f7428b9aafe020c1115aebe14c0a8bcde0e1f`。`db4bf0b..3add176` 只修改 `AGENTS.md`、`README.md`、`docs/plaintext-database-export.md` 并新增 `docs/database-preservation.md`；`src/`、`ui/`、`tests/`、`tools/` 和 `CMakeLists.txt` 无差异。

## 范围与保留要求

U4 仍是 Qt 界面外壳：未接入 Aspen 计算引擎、物性数据库检索或文件保存，输入仅保留于本次会话。D2 表示导出和恢复工具已具备，不表示数据库已经接入应用；2,947 份布局也不等于同等数量的完整业务页面。详细范围见 [交互记录](ui-interactions.md)、[资源恢复报告](ui-resource-recovery.md) 和 [明文导出说明](plaintext-database-export.md)。

数据库资产独立保存在本地受保护目录，分支的新旧不改变其保留要求。本次标注不读取或重写数据包，不删除分支，不改默认分支，不合并代码，不清除失效的远端引用。保护规则见 [数据库永久保留原则](database-preservation.md)。

## 复核方式

云端清单来自已认证 GitHub 连接器的完整分支查询及逐分支头提交读取；两条早期分支同时经过名称查询和按名称读取提交核对，均已不存在。6 条真实云端分支的头提交均与现有本地 Git 对象及对应 origin 引用一致，无需下载新对象。

本地通过 `for-each-ref`、`rev-list --left-right --count`、`merge-base --is-ancestor`、`rev-parse <ref>^{tree}` 和指定目录的 `git diff` 核对；不会因本次标注重新宣称各旧分支已通过编译或运行测试。本次变更只涉及文档，检查覆盖表内提交、祖先关系、文件树等价性、文档链接及暂存差异。

本地分支的标注同时保存在 `.git/config` 的 `branch.<分支名>.description` 中，可用下列命令查看；GitHub 分支不支持同步这种描述，因此云端以本清单为准。后续分支变化后应重新核对，不能将本快照当作实时状态。

```powershell
& .local-tools/mingit/cmd/git.exe -c safe.directory=C:/Users/Administrator/Desktop/Aspen config --local --get-regexp '^branch\..*\.description$'
```
