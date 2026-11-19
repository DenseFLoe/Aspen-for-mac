# Aspen 项目指令

## 阅读方式

逐文件逆向任务默认只需本文件、[执行规则](docs/reverse-execution-workflow.md)和[当前状态](docs/reverse-work-status.md)。已在当前上下文中读取且未变化的内容不重复全文读取；上下文缺失、文件变化或结论存疑时重新核对。总纲、历史、清单和证据按任务定位相关章节/记录，不遍读全库。相关详细条款仍须执行，入口见[完整参考](docs/project-workflow-reference.md)。

## 不可省略的约束

- **资产永久保留、仅本地保存：** `.local/property-database/`（含 `plaintext-export/`、`archives/`、`DO_NOT_DELETE.md`）、`.local/formula-extraction-20261116/`、`.local/extraction-archives-20261117/` 中全部 `aspen-v15-formulas-*` 归档及校验/核验记录。保留原目录、元数据、恢复工具、公式图文与原始十进制数值；新增处理用新路径，禁止删除、清空、覆盖或损坏。只有用户针对具体路径明确授权才可例外。
- `.local/` 被忽略、已有压缩包或常规清理要求均不授权删除；禁止 `git clean -fdx`、`git clean -ffdx` 及递归清理整个 `.local/` 或 `.local/property-database/`。清理脚本明确排除保护路径。详见[数据库](docs/database-preservation.md)及[公式](docs/formula-extraction.md)。
- **范围：** Aspen Plus、独立的 Aspen Properties；Properties Enterprise Database Server 单列。各自原版安装包优先，已安装文件补缺、版本及运行证据；共享组件须有归属/依赖/调用证据。HYSYS、EDR、Energy Analyzer、Adsorption、Chromatography 等其他产品自身文件暂不调查或计入验收。
- **当前阶段：** 原版逐文件逆向归档。顺序为盘点 → 逆向归档 → Windows 重建及对照验收 → 从已验证基准复制独立 Mac 工程 → macOS 构建与实机复验。Windows 原源码保留，当前不自动启动重建。数值单位与容差在比较前确定。详见[总纲](docs/development-requirements.md)。
- **分类与完成分开：** Plus 既有分类冻结；Properties 五份清单为需要/不需要逆向、对应两份重复子集、尚未确定，类内按末级后缀排序。证据核实后才能确认分类，不能只凭后缀；内层代码单列。读取限制、路径定位和分类分别记录。双归属内容在双方及共用索引关联，同哈希共用 `analysis_key` 并保留来源，同名异哈希分开。历史清单与证据保留，新完成状态另建台账/视图。
- **每轮成果：** 验收通过放 `01-completed/`，局部、失败或未验收放 `02-incomplete/`；新归档保留产品、原路径/文件名，每份成果配同目录同名 `.md`，写来源/版本/哈希、范围、状态、验收证据、缺口和下一步。目录汇总、工具成功或编译成功不能替代逐文件完整性验收。
- **子智能体：** 本类任务均允许按需调用，由模型决定数量及分工，无需逐轮确认；传递核心约束及必要上下文，分开写入路径，主智能体核验并统一同步完成状态。
- **从下一轮起：** 同一来源成员不重复解包；多套代码对照、布局重复验证、深入追查外部依赖只为补具体缺口。行为测试留到 Windows 重建对照阶段。新归档只留正式成果、同名说明和必要证据；清单只验本轮增量。以往归档原样保留。

## 仓库工作流

- 仓库 `https://github.com/DenseFLoe/Aspen-for-mac.git`。改仓库前获取并检查远端默认分支及适用指令，保留用户改动和历史；聚焦工作分支用 `codex/` 前缀。不强推、不替换历史、不擅改默认分支。
- 每个已验证里程碑及时提交并上传工作分支，报告分支、SHA、检查及上传结果。只暂存明确文件；每次提交前审阅暂存文件名、完整差异、统计及大文件，运行适用检查。
- 每轮将通过静态逆向验收的 `01-completed/` 中的完整成果、同名说明和可上传的验收证据同步到 GitHub 私有仓库的 `reverse/01-completed/<轮次>/`，保留产品及原路径，本地原件保留。提交前对照完成台账和归档指纹。自编工具、项目文档及分类/来源/哈希/重复关系/定位/完成状态等元数据仍可上传。
- `02-incomplete/`、安装包、原版二进制及其编码副本、数据库、公式、凭据、工具安装包、缓存、构建产物和无关文件仅留本地。混合归档只提取并发布其中已核验的可上传成果，用清单记录来源及文件指纹。不得输出秘密或把凭据写入 URL/日志。
- 未配置安全 Git 凭据提供程序前，使用已认证 GitHub 连接器上传，核验远端并对齐本地历史；失败则保留本地成果、报告具体阻塞，不声称上传成功。
- 本地 Git：`.local-tools/mingit/cmd/git.exe`；必要时仅用 `-c safe.directory=C:/Users/Administrator/Desktop/Aspen`，不改全局信任/凭据设置。导入远端时先协调本地文件，不创建无关根历史。
