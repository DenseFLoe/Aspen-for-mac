# DSH Diff OOM Guard

作者：铁头喵

Windows x64 下的 DeepSeek Harness 插件。为 DSH Ops 的 Niubash 命令树限制提交内存，并修复 WinuxCmd `diff.exe` 比较大文件时耗尽内存的问题。适配环境为 DSH Desktop 0.2.2-rc.5、DSH Ops 0.5.5 和 Niubash 1.5.0。

## 安装

准备 Git for Windows 和 Windows 自带的 .NET Framework x64 C# 编译器。有 Codex 附带的 GNU diff 时也可使用。将本目录打包，再在本机 DSH 桌面配置中安装。

```powershell
pnpm pack
dsh plugin --profile desktop add "C:\path\to\dsh-diff-oom-guard-0.2.0.tgz"
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

DSH Ops 启动 Niubash 后，在执行命令前先领取当前 Windows 登录会话共享的四个内存席位之一。Windows Job Object 将每棵命令进程树的提交内存限制为 **2 GiB**。后台子进程退出后，席位才回收。启动前检查系统可用物理内存和提交余量，条件不足就排队，60 秒后以退出码 75 返回。空闲物理内存底线为 3 GiB，提交余量底线为 6 GiB，准入时另为活跃和待启动席位保留配额。

通过 PATH 调用的 `diff` 或 `diff.exe` 另有一层 **768 MiB** 单进程上限。启动器以挂起状态创建 GNU diff，绑定上限后才放行，保留参数、标准输入、输出、错误输出和退出码。

从 PowerShell 等入口直接启动重工具时，可以显式经过同一组席位。将下面的第一个路径换成 Niubash 中 `command -v diff.exe` 返回的防护程序的 Windows 路径。

```powershell
& 'C:\path\to\guard\diff.exe' --dsh-run-bounded 'C:\path\to\tool.exe' arg1 arg2
```

DSH 的会话权限和 shell 执行流程由宿主处理。插件生成的启动器放在 DSH home 内，独立于 Niubash 的执行缓存。Windows Job 的硬上限覆盖经过上述入口的进程树。调度前的内存测量也会计入其它程序使用的系统内存。
