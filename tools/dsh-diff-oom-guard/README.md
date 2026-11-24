# DSH Diff OOM Guard

作者：铁头喵

Windows x64 下的 DeepSeek Harness 插件。针对 DSH Ops 的 Niubash 使用 WinuxCmd `diff.exe` 比较伪代码时出现的内存耗尽问题。适配和验证环境为 DSH Desktop 0.2.2-rc.5、DSH Ops 0.5.5 和 Niubash 1.5.0。

## 安装

准备 Git for Windows 和 Windows 自带的 .NET Framework x64 C# 编译器。有 Codex 附带的 GNU diff 时也可使用。将本目录打包，再在本机 DSH 桌面配置中安装。

```powershell
pnpm pack
dsh plugin --profile desktop add "C:\path\to\dsh-diff-oom-guard-0.1.0.tgz"
```

如果 GNU diff 位于自定义安装目录，在桌面 profile 的 `cordis.patch.yml` 里给插件指定路径。

```yaml
- id: dsh-diff-oom-guard
  config:
    gnuDiff: 'C:\Program Files\Git\usr\bin\diff.exe'
```

安装后可在 **DSH Ops 的 Bash 工具**里运行以下命令验证。

```bash
command -v diff
diff --version
```

第一条应解析到 DSH home 下的 `dsh-diff-oom-guard`，第二条应显示 `GNU diffutils`。

## 工作方式

插件为 DSH 启动的 Niubash 命令准备 Bash 启动脚本，在命令解析时优先选用防护版 `diff`。启动器先创建 Windows Job Object，再以挂起状态创建 GNU diff，绑定 **768 MiB** 的进程内存上限后才放行。启动器保留 GNU diff 的参数、标准输入、输出、错误输出和退出码。

防护范围是通过 PATH 查找的 `diff` 或 `diff.exe`。显式绝对路径沿用调用者指定的程序。DSH 的会话权限和 shell 执行流程由宿主处理。插件生成的启动器位于 DSH home 的独立目录，Niubash 重建自己的执行缓存后仍可使用。
