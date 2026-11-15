# Aspen project workflow

## �����ʲ����ñ���ԭ��ǿ��ִ�У�

- ����ȡ�� Aspen V15 ���ݿ�����Ҫ���ڱ����Ķ�����Ŀ�ʲ������ǻ��桢��ʱ�ļ�����������ɵĹ������**��Ŀ�������ع�����������֧�л�������������ɾ������ա����ǻ�����Щ�ʲ���**
- �ܱ�����Χ���� `.local/property-database/plaintext-export/` �������ݰ���`.local/property-database/archives/` �µĹ鵵����У��/�����¼���Լ� `.local/property-database/DO_NOT_DELETE.md` ������������������Ŀ¼�ṹ��Ԫ���ݡ��ָ����ߺ�ԭʼʮ������ֵ��
- `.local/` �� Git ����ֻ��ʾ���ݲ��ϴ�������ʾ������ɾ������ֹ�Թ��������л������Щ�ʲ��� `git clean -fdx`��`git clean -ffdx`��Ҳ��ֹ�ݹ��������� `.local/` �� `.local/property-database/`�������ű�������ȷ�ų��ܱ���·����
- ѹ���鵵����ɾ��ԭĿ¼����Ȩ�������������ָ���Ǩ�ƻ�鵵����ʹ����·�������ø����������ݡ����ݰ��͹鵵���������ر��棬�����Զ����� Git ���ϴ� GitHub��
- ֻ���û������Ծ����ܱ���·����ȷҪ��ɾ���򸲸ǣ��ſ�ִ�ж�Ӧ����������ġ�������Ŀ�������¹�������������֧����������Ȩ����� `docs/database-preservation.md`��

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
