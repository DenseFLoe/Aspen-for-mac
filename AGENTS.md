# Aspen project workflow

## 数据资产永久保留原则（强制执行）

- 已提取的 Aspen V15 数据库是需要长期保留的独立项目资产，不是缓存、临时文件或可重新生成的构建产物。**项目开发、重构、构建、分支切换和清理均不得删除、清空、覆盖或损坏这些资产。**
- 受保护范围包括 `.local/property-database/plaintext-export/` 完整数据包、`.local/property-database/archives/` 下的归档及其校验/核验记录，以及 `.local/property-database/DO_NOT_DELETE.md` 保留声明。保留整个目录结构、元数据、恢复工具和原始十进制数值。
- `.local/` 被 Git 忽略只表示数据不上传，不表示它可以删除。禁止对工作区运行会清除这些资产的 `git clean -fdx`、`git clean -ffdx`，也禁止递归清理整个 `.local/` 或 `.local/property-database/`。清理脚本必须明确排除受保护路径。
- 压缩归档不是删除原目录的授权；新增导出、恢复、迁移或归档必须使用新路径，不得覆盖已有数据。数据包和归档继续仅本地保存，不得自动加入 Git 或上传 GitHub。
- 只有用户今后针对具体受保护路径明确要求删除或覆盖，才可执行对应操作。常规的“清理项目”“重新构建”“整理分支”不构成授权。详见 `docs/database-preservation.md`。

## 开发原则与工作顺序

按以下顺序开发。详细过程和验收要求见 [开发要求与实施顺序](docs/development-requirements.md)。

1. **盘点安装包和已安装程序。** 分别记录原路径、文件类型、版本和 SHA-256。哈希相同的文件共用一份分析记录，并保留两边的来源。
2. **逐文件分析并按原名归档。** 对程序文件逐个反编译，按原相对路径和文件名保存结果，记录依赖、证据和待核实项。数据库、配置和资源按原有格式分别处理。安装介质、原版二进制、完整反编译资料及数据库仅在本地保存。
3. **先重建并验证 Windows 版。** 把确认过的逻辑整理成可编辑、可编译的 Windows 源码，补齐模块调用、依赖和构建配置。用相同操作和输入与原版对照，验收后用提交号固定 Windows 源码和构建基准。
4. **复制一份独立的 Mac 源码。** 从已验证的 Windows 基准复制出单独工程，原样保留 Windows 源码。只在 Mac 副本中替换 Windows 专用接口、依赖库和构建配置。两套源码分别维护和构建。
5. **编译并验证 Mac 版。** 在干净的 macOS 环境构建，并在 Mac 实机复跑 Windows 阶段的验收案例。记录构建、实际运行、对照结果和剩余差异。数值比较的单位和容差应在测试前确定。

近期交付范围为阶段 0–2，包括统一开发基线、项目模型与保存、只读物性数据库及真实组分检索。后续用户明确调整范围时按最新要求执行，并同步更新开发要求。

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
