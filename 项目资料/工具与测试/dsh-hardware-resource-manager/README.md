# DSH 硬件资源管理器

作者：铁头喵

Windows x64 下的 DeepSeek Harness 插件。为官方单次 PowerShell，以及 DSH Ops 的 Bash、原生文件和 PTC Worker 提供同一条先来先到的队列，以及 CPU 和内存限额。配置 GNU diff 后，也会保护通过 `PATH` 调用的 `diff`。当前组合为 DSH Desktop 0.2.3-alpha.2、DSH Ops 0.5.7 和 Niubash 1.5.0。包内也保留了 DSH 0.2.2-rc.5 与 OPS 0.5.5 使用的补丁。

## 安装

插件通过 Windows 自带的 .NET Framework x64 C# 编译器构建。将本目录打包，在本机 DSH 桌面 profile 中安装。从旧版升级时，用新插件替换 `dsh-diff-oom-guard`。

```powershell
pnpm pack
dsh plugin --profile desktop add "C:\path\to\dsh-hardware-resource-manager-0.5.0-beta.13.tgz"
```

在桌面 profile 的 `package.json` 中，将 `dsh-hardware-resource-manager` 加入 `dsh.profile.bundles`，排在 `dsh-ops` 之后。将匹配已安装 OPS 版本的补丁复制到桌面 profile 的 `patches` 目录，在 `pnpm-workspace.yaml` 加入对应映射，然后执行 `dsh plugin --profile desktop install` 并重新启动桌面应用。OPS 0.5.7 使用 [GitHub 发布包](https://github.com/T-Auto/dsh-ops/releases/tag/v0.5.7)。

```yaml
patchedDependencies:
  dsh-ops@0.5.7: patches/dsh-ops-0.5.7.patch
```

使用 OPS 0.5.5 时，将上面的版本和文件名都改为 `0.5.5`。

使用官方 Windows 基础配置时，插件会接管单次 `pwsh` 的执行器。在 profile 中自定义了 PowerShell 路径或输出限额时，将原 `pwsh-sandbox` 配置移到 `pwsh-resource-sandbox`。

同一配置下，官方 Node PTC 运行时也会自动启用主程序队列。自定义的 `ptc-runtime` 配置可沿用在 `ptc-resource-runtime`。

插件会查找 Git for Windows 和 Codex 自带的 GNU diff。可在桌面 profile 的 `cordis.patch.yml` 里指定其他绝对路径。

```yaml
- id: dsh-hardware-resource-manager
  config:
    gnuDiff: 'C:\Program Files\Git\usr\bin\diff.exe'
```

安装后可在 **DSH Ops 的 Bash 工具**里查看管理器路径。已启用 GNU diff 时，也可以查看 `diff` 版本。

```bash
command -v dsh-resource.exe
diff --version
```

管理器位于 DSH home 下的 `dsh-hardware-resource-manager` 目录。受保护的 `diff` 会显示 `GNU diffutils`。

## 工作方式

全机 CPU、物理内存或提交内存任一最新实测占用达到 **95%** 时，暂停发放新的工具和 PTC 主程序席位。新请求仍可登记，已运行的任务继续执行，CPU 降额和工作集回收照常。三项都回落到 95% 以下后，调度器再检查可用席位和适用的内存余量，并按 FIFO 恢复。工具在领取许可和实际启动时都复核资源状态。当前全机 CPU 准入和动态降额适用于单处理器组 Windows 主机。

同一用户在同一 Windows 登录会话中的受管工具共享一条 FIFO 队列。调用按抵达硬件准入入口的顺序登记。队首先检查全机物理内存和提交余量，满足条件时自动领取席位并启动，下一条随后检查其余席位。最多同时运行四棵工具进程树，每棵由 Windows Job Object 设置提交内存上限。Bash、单次 PowerShell 及其他原生 Worker 默认使用 **2 GiB**。DSH Ops 的单文件 `stat` 流式读取并计算哈希，自动使用 **256 MiB**。调度按运行中各进程树的实际硬上限加上队首所需配额预留内存，并要求物理内存和提交内存的预计用量都在 **95%** 以内。小配额请求在同一队列中按原顺序等待。

当运行期间的全机物理内存占用超过 **93%**，管理器会让 Windows 尝试回收受管进程的工作集，为 95% 上限留出缓冲。同一命令树的两次尝试至少间隔 8 秒。回收只涉及已核对属于这个 Job 的进程，保留进程和已提交内存。全机提交压力继续由准入检查处理。

CPU 调度在 **95%** 阈值前预留 5 个百分点，受管命令树共享最多 **90%** 的 CPU 硬配额。在单处理器组的机器上，调度器约每 200 毫秒读取 Windows 系统和 Job 的 CPU 时间，从 90% 中扣除其他进程的实测负载，再均分配额。全机采样达到 95% 时，按超出 90% 的幅度额外降额。每次准入检查同时更新运行中命令的配额，负载回落后每次采样最多恢复 2 个百分点。CPU 预算用光后暂停发放席位，并将运行中的命令树降至 Windows 支持的最小配额。每棵进程树的后台子进程全部退出后，席位回收。多处理器组系统采用固定的受管 CPU 配额。

Agent 照常提交 Bash 命令。接入宿主队列时，每个 DSH 宿主通常只启动一个调度进程，排队期间暂缓启动各自的 Niubash。资源转交前会重新检查 DSH 的会话权限。队首检查内存，后续请求由 Windows 等待前一个请求离队。宿主取消后，等待中的请求会离队。DSH 带作业管理时，达到前台等待时限的调用可以由宿主转为后台作业。已有席位的进程树内调用防护入口会复用席位。Niubash 启动脚本也能接收未接入宿主队列的 Bash 调用。

从支持平滑卸载的版本升级时，旧调度进程处理完它已接收的请求后退出，新进程接收新增请求。两者共用同一条 FIFO。每份许可携带签发它的启动脚本路径，桌面切换配置后，旧请求仍会经过自己的资源检查。

原生文件与 PTC 的 Windows Worker 获得席位后才启动并开始执行计时。排队期间仍遵循调用方的取消信号和 PTC 父程序的截止时间。启动前会重新核对会话授权，原有的沙箱参数、标准输入输出和退出状态通过启动器传递给 Worker。

单次 `pwsh` 使用官方工具的超时、取消、输出和沙箱行为。执行器在启动 PowerShell 前领取同一队列的席位，并复核等待期间是否变更会话授权。持久 PowerShell 终端沿用终端后端。

同一宿主内访问同一工作区审计存储的 PTC 调用先按工作区排队，轮到后才申请硬件席位。其他工作区和独立的文件工具可继续申请硬件。等待中取消会自动离队，无需 Agent 重试存储锁冲突。

`run_code` 主程序按到达顺序进入各宿主的执行队列。并行主程序数由 Node 可用的逻辑处理器数决定，最多八个。排队期间遵循调用方的取消和权限变更，获准后由官方运行时开始执行计时。主程序席位与普通工具席位独立，主程序等待子工具时，子工具仍可按全局 FIFO 启动。启用了持久模式的 PTC 运行时仍保留已有变量及其进程，直到对应状态释放。

通过 PATH 调用的 `diff` 或 `diff.exe` 另有一层 **768 MiB** 单进程上限。启动器以挂起状态创建 GNU diff，绑定上限后才放行，保留参数、标准输入、输出、错误输出和退出码。

把下面的管理器路径换成 `command -v dsh-resource.exe` 对应的 Windows 路径。可以从 PowerShell 查看当前排队数、运行数、运行中进程树的内存配额总和、CPU 硬配额、全机及外部 CPU 采样、两项内存压力和本次活跃周期中的工作集回收次数。通过同一个入口启动工具时，60 秒内没有拿到席位会返回 75。

```powershell
& 'C:\path\to\manager\dsh-resource.exe' --dsh-resource-status
& 'C:\path\to\manager\dsh-resource.exe' --dsh-run-bounded 'C:\path\to\tool.exe' arg1 arg2
```

DSH 的会话权限和 shell 执行流程由宿主处理。插件生成的启动器放在 DSH home 内，独立于 Niubash 的执行缓存。Windows Job 的硬上限覆盖经过上述入口的进程树。外部 CPU 负载通过采样参与调节，外部内存使用计入下一次准入。

## 宿主进程树的总配额

从 `--dsh-run-host` 启动新的 DSH 宿主时，可以为宿主及继承其 Windows Job 的后代设置同一份提交内存和 CPU 硬配额。启动器先核验全机两项内存余量能否容纳配置的 MiB，再创建进程。受管宿主及后代共享最多 90% 的 CPU 配额。内存达到 Job 的提交上限后，Windows 拒绝新的提交申请。

在单处理器组的机器上，启动器在恢复宿主线程前读取外部 CPU 负载，并在运行期间约每 200 毫秒更新整棵宿主进程树的硬配额。外部负载升高时降低配额，全机采样达到 95% 时额外降额。外部负载下降后逐步恢复。多处理器组系统继续使用固定配额。CPU 采样失败时保留最近已写入 Windows Job 的硬配额。

```powershell
& 'C:\path\to\manager\dsh-resource.exe' --dsh-run-host 1024 'C:\path\to\host.exe' <宿主参数>
```

这个外层 Job 不占用普通工具席位。PTC 主程序可以在同一外层 Job 内等待仍按 FIFO 领取席位的宿主工具，原有进程间控制通道继续由 DSH 管理。提交内存上限按本次启动指定的 MiB 固定。这个模式从新宿主启动时生效。

在外层 Job 内，发放许可和启动都会检查宿主的实测提交量、该宿主在运行工具的预留和下一项工具的配额。必要时请求继续等待。工具所需配额超过宿主总上限时会在启动前返回明确的容量错误。启动器通过 Windows Job 成员身份确认该宿主，默认保守预留运行中工具的完整配额。
