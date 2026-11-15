# 云端与本地分支功能标注

> 后续开发更新（2026-11-15）：本次 UI 静态补齐与对象交互在新分支 `codex/ui-object-interactions` 开发，基于 `main@7c19bc5`；静态里程碑 `384392b` 已上传。该分支未合并到 main。以下“两条分支”及 U4 清单是创建此新分支前的清理记录，保留作为历史基线；当前功能见 [对象交互记录](ui-object-interactions.md)。

核对日期：2026-11-15（北京时间）。仓库：`DenseFLoe/Aspen-for-mac`，云端默认分支为 `main`。**最新界面交互、明文数据库工具、永久保留规则和本次分支标注已整合到 main，本地与云端 main 同步。后续应用开发基于 main。**

按用户要求，完成合并后的分支清理，**本地和云端均只保留 `main` 与 `codex/plaintext-database-export` 两条分支**。已合并的功能分支、标注分支、重复本地副本及相应远端引用均已删除；原功能提交继续保留在 main 历史中。

## 标注标准

界面按功能分为 U4（最新交互）、U3（资源浏览与预览）、U2+（组分页及浅色主题修复）、U2（组分页）、U1（菜单外壳）、U0（仓库初始化）。数据库另标为 D2（完整明文导出与恢复核验工具）、D1（调查及样本提取）、D0（无相关工具）；P1 表示包含永久保留规则。等级是本次调查的功能阶段，不是软件版本号，也不按提交时间机械排序。

## 分支清单

“本地”指 `refs/heads/*`；“云端”指 GitHub 实时返回的分支，不把本机 `origin/*` 缓存当作真实云端分支。同名本地与云端分支提交一致。“本报告提交”指包含本次清理标注的 Git 提交，避免在文件中循环引用自身 SHA。

| 功能标注 | 分支 | 本地提交 | 云端提交 | 功能与同步状态 |
| --- | --- | --- | --- | --- |
| **U4 / D2 / P1 综合最新** | `main` | 本报告提交 | 本报告提交 | 已整合原 main、最新交互、数据库工具、永久保留规则及分支标注；推荐应用开发基线 |
| **U2 / D2 独立保留的提取工具基线** | `codex/plaintext-database-export` | `a9ed53c` | `a9ed53c` | 完整明文导出、覆盖核验、附属数据及便携恢复工具；工具已进入 main，本分支独立保留用于维护和复用，界面仍为早期 17 页/39 标签 |

## 本轮分支清理

以下记录只用于追溯，不表示分支仍存在。删除前核对全部云端功能分支的提交已合入 main；本地重复副本以完整文件树比较确认没有额外功能。

| 分支 | 已核对的功能提交 | 清理结果 |
| --- | --- | --- |
| `codex/branch-function-audit` | `f22531e` | 标注及本次清理说明进入 main，云端和本地分支及远端引用已删除；临时清理 workflow 不合入 main |
| `codex/preserve-database-archive` | `3add176` | 云端和本地分支及远端引用已删除；功能和永久保留规则仍在 main |
| `codex/property-database-investigation` | `45be18a` | 云端和本地分支及远端引用已删除；调查记录仍在 main |
| `codex/ui-interactions` | `db4bf0b` | 云端和本地分支及远端引用已删除；最新交互功能仍在 main |
| `codex/ui-resource-recovery` | `5ef0861` | 云端和本地分支及远端引用已删除；资源恢复功能仍在 main |
| `codex/local-ui-interactions` | `df59d89` | 仅本地的重复副本已删除；其文件树与已合入的 db4bf0b 完全相同 |
| `codex/aspen-plus-icons-components` | `5bec246` | 上一轮已删除本地分支、分支描述及旧远端引用；提交仍在 main 历史中 |
| `codex/aspen-plus-ui-menus` | `71b7215` | 上一轮已删除本地分支、分支描述、失效 upstream 及旧远端引用；提交仍在 main 历史中 |

本次只删除分支引用及其配置，不清理 Git 对象，不运行 `git clean`，不删除任何数据库资产。数据库资产与分支生命周期独立。

## 提取工具分支的维护方式

`codex/plaintext-database-export` 单独保留比较合适：数据库导出、格式核验和跨平台恢复有独立于 Qt 界面的使用场景，可以按自己的节奏验证和复用。分支保存工具代码、测试与说明，实际数据库资产继续独立保存在本地，不能把分支当作数据备份。

目前 main 中的提取与恢复工具仍沿用该分支的代码，main 另外增加了界面资源工具；数据库工具修复可以在该分支维护，验证后再合入 main。若后续工具目录同时有不同改动，需要正常解决合并冲突。应用开发使用 main，避免为了更新工具退回本分支的旧界面。项目级永久保留规则仍适用于任何分支。

## 影响判断的提交关系

数据库工具线和浅色主题修复线曾分叉，所以 `plaintext-database-export` 虽提交时间较晚，仍缺少原 main 的浅色主题修复。`78f304f` 把两线合并，后续资源恢复和交互分支同时包含两者。本轮 main 以快进方式整合，保留两线的所有历史。

```text
37ecc9c 原本地 main
  └─71b7215 菜单外壳
      └─33a2128 原版图标
          └─5bec246 组分页
              ├─1fe0e13 原云端 main：浅色主题修复 ───────┐
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
                                                └─756b3ff 首次分支标注
                                                    └─f22531e main 整合及工具分支保留说明
                                                        └─本报告提交 main 与提取工具分支保留
```

`df59d89` 和 `db4bf0b` 的文件树均为 `d23f7428b9aafe020c1115aebe14c0a8bcde0e1f`。`db4bf0b..3add176` 只修改 `AGENTS.md`、`README.md`、`docs/plaintext-database-export.md` 并新增 `docs/database-preservation.md`；`src/`、`ui/`、`tests/`、`tools/` 和 `CMakeLists.txt` 无差异。

## 范围与保留要求

U4 仍是 Qt 界面外壳：未接入 Aspen 计算引擎、物性数据库检索或文件保存，输入仅保留于本次会话。D2 表示导出和恢复工具已具备，不表示数据库已经接入应用；2,947 份布局也不等于同等数量的完整业务页面。详细范围见 [交互记录](ui-interactions.md)、[资源恢复报告](ui-resource-recovery.md) 和 [明文导出说明](plaintext-database-export.md)。

数据库资产独立保存在本地受保护目录，分支的新旧不改变其保留要求。本轮仅进行代码历史整合、分支元数据清理和文档更新；不对数据库资产执行导出、恢复、重写、移动或删除。整合前后比对数据库目录清单、大小、修改时间及关键校验文件哈希。保护规则见 [数据库永久保留原则](database-preservation.md)。

## 复核方式

云端清单来自已认证 GitHub 连接器的完整分支查询及分支头提交读取。连接器未提供分支删除接口，云端删除由临时工作分支上的一次性 GitHub Actions 任务执行：先核对保留分支和全部待删分支的提交，再使用原子推送及逐分支预期 SHA 删除指定引用；临时 workflow 不进入 main。删除后回读完整云端清单，并核对本地分支集合及同名提交一致。main 的文档更新采用快进，保留原有历史。

本地通过 `for-each-ref`、`merge-base --is-ancestor`、`rev-parse <ref>^{tree}` 和指定目录的 `git diff` 核对提交关系、文件树等价性与保留范围；检查文档链接及暂存差异。本次没有修改应用及提取工具代码，沿用上一轮通过的 9 项 Python 测试、资源目录核验、Windows Qt 构建与 CTest 界面测试；本轮验证分支清理流程、文档及数据库资产前后状态。

本地分支的标注同时保存在 `.git/config` 的 `branch.<分支名>.description` 中，可用下列命令查看；GitHub 分支不支持同步这种描述，因此云端以本清单为准。后续分支变化后应重新核对，不能将本快照当作实时状态。

```powershell
& .local-tools/mingit/cmd/git.exe -c safe.directory=C:/Users/Administrator/Desktop/Aspen config --local --get-regexp '^branch\..*\.description$'
```
