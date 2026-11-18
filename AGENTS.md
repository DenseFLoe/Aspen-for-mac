# Aspen project workflow

## 数据资产永久保留原则（强制执行）

- 已提取的 Aspen V15 数据库是需要长期保留的独立项目资产，不是缓存、临时文件或可重新生成的构建产物。**项目开发、重构、构建、分支切换和清理均不得删除、清空、覆盖或损坏这些资产。**
- 受保护范围包括 `.local/property-database/plaintext-export/` 完整数据包、`.local/property-database/archives/` 下的归档及其校验/核验记录，以及 `.local/property-database/DO_NOT_DELETE.md` 保留声明。保留整个目录结构、元数据、恢复工具和原始十进制数值。
- `.local/` 被 Git 忽略只表示数据不上传，不表示它可以删除。禁止对工作区运行会清除这些资产的 `git clean -fdx`、`git clean -ffdx`，也禁止递归清理整个 `.local/` 或 `.local/property-database/`。清理脚本必须明确排除受保护路径。
- 压缩归档不是删除原目录的授权；新增导出、恢复、迁移或归档必须使用新路径，不得覆盖已有数据。数据包和归档继续仅本地保存，不得自动加入 Git 或上传 GitHub。
- 只有用户今后针对具体受保护路径明确要求删除或覆盖，才可执行对应操作。常规的“清理项目”“重新构建”“整理分支”不构成授权。详见 `docs/database-preservation.md`。

## 等效重建、开发顺序与验收

- 以 Aspen V15 安装包及已安装软件为参照，逐文件盘点、分析模块和依赖，再按完整功能链重建可编辑、可编译、可在 Mac 运行的源码。逐文件研究用于建立证据，交付按功能链组织。
- 开发功能前，追踪原版从操作入口到数据读写、业务处理、计算和结果的相关环节，记录来源、适用条件和未知项。用原版实际运行核对关键行为；对照后复用已有代码和资料，按证据补齐差异。
- 开始功能开发前阅读 [开发要求与实施顺序](docs/development-requirements.md)，核对当前阶段、前置依赖和验收标准。主线为项目保存、数据库检索、字段与单位、流程图连接规则、最小计算、复杂模型。
- 近期交付范围为阶段 0–2：统一开发基线、项目模型与保存、只读物性数据库及真实组分检索。后续用户明确调整范围时按最新要求执行，并同步更新开发要求。
- 按本次声明的范围，用相同输入对照原版的界面反馈、状态变化、保存内容及计算结果；数值计算提前确定容差，并核对边界和失败情形。静态布局、可打开的输入页和可创建的对象不等于业务功能完成。阶段完成必须记录对应提交、检查结果及剩余边界；数据库永久保留原则持续适用。

## Repository workflow

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
