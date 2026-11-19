# 项目规则完整参考

2026-11-19 精简前全文，来源 `AGENTS.md@2c528f04d00403d05840a7b0df220a3040c16165`。原条款与历史记录保留；AGENTS 原文的相对链接已适配本目录。现行入口见[精简版](../AGENTS.md)，本参考仅按相关章节读取；其中带日期的进度陈述属于当时记录，不代替当前状态。

---

# Aspen project workflow

## 数据资产永久保留原则（强制执行）

- 已提取的 Aspen V15 数据库是需要长期保留的独立项目资产，不是缓存、临时文件或可重新生成的构建产物。**项目开发、重构、构建、分支切换和清理均不得删除、清空、覆盖或损坏这些资产。**
- 受保护范围包括 `.local/property-database/plaintext-export/` 完整数据包、`.local/property-database/archives/` 下的归档及其校验/核验记录，以及 `.local/property-database/DO_NOT_DELETE.md` 保留声明。保留整个目录结构、元数据、恢复工具和原始十进制数值。
- 公式资料同样长期独立保留：`.local/formula-extraction-20261116/` 原目录，以及 `.local/extraction-archives-20261117/` 中所有 `aspen-v15-formulas-*` 压缩包、校验和核验记录。保留主题正文、公式原图、转录、索引和流体参数文件；开发、构建、分支切换与清理不得删除、清空或覆盖，新增处理使用新路径。资料及归档仅本地保存，不加入 Git 或上传 GitHub。详见 [公式提取说明](formula-extraction.md)。
- `.local/` 被 Git 忽略只表示数据不上传，不表示它可以删除。禁止对工作区运行会清除这些资产的 `git clean -fdx`、`git clean -ffdx`，也禁止递归清理整个 `.local/` 或 `.local/property-database/`。清理脚本必须明确排除受保护路径。
- 压缩归档不是删除原目录的授权；新增导出、恢复、迁移或归档必须使用新路径，不得覆盖已有数据。数据包和归档继续仅本地保存，不得自动加入 Git 或上传 GitHub。
- 只有用户今后针对具体受保护路径明确要求删除或覆盖，才可执行对应操作。常规的“清理项目”“重新构建”“整理分支”不构成授权。详见 `docs/database-preservation.md`。

## 开发原则与工作顺序

**本次开发范围包括 Aspen Plus 与 Aspen Properties，Aspen Properties 作为独立产品正式纳入开发。** 两者均以各自原版安装包交付的文件为首选范围，已安装程序用于补充缺项、版本差异与运行证据；Aspen Properties Enterprise Database Server 作为 Properties 配套安装组件单列。共享组件须有安装归属、依赖或调用证据确认被其中一个或两个产品使用，按相关部分纳入，不因扫描到整个 AspenTech 安装目录而扩大范围。

**本轮新增盘点、分类与复核仅针对 Aspen Properties。** Aspen Plus 沿用此前已固定的分类结果，作为只读对照基线；Plus 清单只新增共用文件的交叉索引，不重跑分类、不重标分类状态、不新增本轮待核实项。Properties 与 Plus 相同内容哈希的文件复用既有 Plus 分类及分析记录，剩余新内容单独核验。

Properties 当前整理采用五份清单：需要逆向、不需要逆向、需要逆向中的重复项、不需要逆向中的重复项、尚未确定。两份重复清单是对应分类的附加子集，总共两份；按可读内容 SHA-256 标明与 Plus 重复或 Properties 不同来源重复。尚未确定项单独列出，不混入已确认两类。只计 Properties 安装归属来源，Plus 仅作只读引用；旧清单与证据继续保留。

分别维护 Plus、Properties 和两者共用文件的分类文档清单。确认同时属于两者的文件须在三份清单中同时出现，保留双方来源、归属依据、SHA-256 与统一 analysis_key；同名异哈希分别记录，不凭名称认定内容相同。分类沿用“需要逆向 / 不需要逆向”，类内按末级后缀排序；与成果验收的“已完成 / 未完成”分开。入口见 [双产品盘点](plus-properties-inventory.md) 和 [共用文件清单](plus-properties-shared-files.md)。

通用后缀或文件头规则只作为初步处理路线，须显式保留待核实状态；有结构、内容或原版读取用途证据后，才能认定相应分类已核实。内层 VBA / 程序成员单独分类，不得因外层是文档或成员后缀为 `.bin` 就归入已确认的数据。读取受限、安装路径未解析与内容分类分别统计，不能用空的 `review` 字段宣称全部通过分类验收。

HYSYS、EDR、Energy Analyzer、Adsorption、Chromatography 等其他产品自身的文件暂不开展分类调查、逆向、重建或移植评估，也不计入本次 Plus / Properties 的未分类项、未完成项或验收分母。已有全来源扫描记录继续保留，汇报时单列范围外记录；后续仅在用户明确扩大范围后再评估其他产品。

按以下顺序开发。详细过程和验收要求见 [开发要求与实施顺序](development-requirements.md)。

1. **盘点安装包和已安装程序。** 分别记录原路径、文件类型、版本和 SHA-256。哈希相同的文件共用一份分析记录，并保留两边的来源。
   - **子要求：每轮成果分类与逐文件说明。** 每轮反编译或编译结束后，将完整完成且通过该阶段验收的文件归入第一个目录 `01-completed/`（已完成）；将尚未完成、仅部分恢复、编译失败或尚未通过该阶段验收的文件归入第二个目录 `02-incomplete/`（未完成）。两类目录均保留原相对路径和文件名，严格实行“一文件一说明”：每个成果文件在同一目录配套独立的同名 `.md` 说明（如 `A.dll.01.cs` 对应 `A.dll.01.md`），记录来源、处理范围、完成状态、验收依据、剩余缺口和下一步工作。目录级汇总不能替代逐文件说明；仅生成输出或编译成功不能代替完整性和该阶段验收。此要求适用于后续各步骤，新增归档使用新路径并保留历史记录。
2. **逐文件分析并按原名归档。** 对程序文件逐个反编译，按原相对路径和文件名保存结果，记录依赖、证据和待核实项。数据库、配置和资源按原有格式分别处理。已验收逆向成果及说明按[执行规则](reverse-execution-workflow.md#5-更新清单与下轮入口)发布。安装介质、原版二进制、未完成逆向资料及数据库仅在本地保存。
3. **先重建并验证 Windows 版。** 把确认过的逻辑整理成可编辑、可编译的 Windows 源码，补齐模块调用、依赖和构建配置。用相同操作和输入与原版对照，验收后用提交号固定 Windows 源码和构建基准。
4. **复制一份独立的 Mac 源码。** 从已验证的 Windows 基准复制出单独工程，原样保留 Windows 源码。只在 Mac 副本中替换 Windows 专用接口、依赖库和构建配置。两套源码分别维护和构建。
5. **编译并验证 Mac 版。** 在干净的 macOS 环境构建，并在 Mac 实机复跑 Windows 阶段的验收案例。记录构建、实际运行、对照结果和剩余差异。数值比较的单位和容差应在测试前确定。

当前交付范围为第 2 步的原版逐文件反编译与归档。按原始文件名分别归档已完成和未完成源码，逐项记录来源、验收依据和缺口。进入 Windows 重建前以原版文件证据为准。后续用户明确调整范围时按最新要求执行，并同步更新开发要求。

2026-11-19 起，后续逐文件工作按[逐文件逆向执行规则](reverse-execution-workflow.md)执行：从已有“需要逆向”清单选择未完成内容；模型依据证据自主决定孤立或连锁逆向及停止条件；逐文件验收、命名、归入两类目录并配齐同名说明后，再同步独立完成台账和带状态的新清单视图。同哈希复用成果并关联总清单、适用重复子清单及双方共用索引，原分类字段和历史快照不覆盖。“逆向完成”只表示当前反编译归档阶段通过，未完成项判断重新反编译、补充分析或暂存，不自动启动 Windows 重建。首次执行先按该规则的一次性衔接核查既有成果，不能只凭旧目录名沿用完成标记；每项处置后退出临时规则，全部交接后可移除临时条款并保留记录。

本规则适用的逐文件逆向任务均允许按需调用子智能体，涵盖既有成果复核、清单比对、逆向与依赖分析、验收、归档和状态整理。模型自主决定是否调用及分工，无需每轮另行征求授权；主智能体负责协调输出路径、核验成果并统一发布完成状态，所有参与者均遵守原有范围、阶段及资产保护要求。详见[子智能体协作](reverse-execution-workflow.md#子智能体协作)。

## Repository workflow

- 用户于 2026-11-19 明确要求上传完整分类清单。分类清单及其来源、哈希、重复关系、安装定位与源码完成状态索引等元数据发布到 `inventories/`，本地原清单及历史证据继续保留。用户后续要求将已验收的逆向文件及新增完成件发布到 [`reverse/01-completed/`](../reverse/01-completed/README.md)。

- Target repository: `https://github.com/DenseFLoe/Aspen-for-mac.git`.
- Before changing repository content, fetch and inspect the existing default branch and any applicable repository instructions. Preserve existing remote history and user changes.
- Commit each meaningful, verified milestone and push its working branch promptly. Report the branch, commit SHA, checks, and push result. If access or a push fails, keep local work safe and report the exact blocker; do not claim it was uploaded.
- Use a focused working branch for new work. Do not force-push, replace remote history, or change the default branch without explicit authorization.
- Stage specific project files. Review `git diff --cached --stat`, the full staged diff, filenames, and large files before every commit. Run checks appropriate to the change.
- Never upload installers, credentials, private keys, tokens, local tools, reverse-engineering input binaries, caches, build output, or unrelated files. Keep such files outside version control. Ignore rules are a safeguard, not a substitute for reviewing staged content.
- Never print secrets or embed credentials in remote URLs, scripts, documentation, commits, or logs. Use an authenticated GitHub connector or a secure Git credential provider.
- The authenticated GitHub connector can read and write this private repository. Local command-line Git has no GitHub credentials configured; do not assume `git push` is authenticated. Use the connector for uploads until a secure Git credential provider is configured, and keep local history aligned with the verified remote commit.
- This Windows workspace has an untracked MinGit at `.local-tools/mingit/cmd/git.exe`. Sandbox commands may need `-c safe.directory=C:/Users/Administrator/Desktop/Aspen`; use the exact workspace path. Writes to `.git` and network operations may require the normal sandbox escalation flow. Do not change global trust or credential settings merely to bypass a failure.
- When importing an existing remote repository into this prepared workspace, reconcile these local setup files with remote versions before staging anything. Do not create an unrelated root history.
