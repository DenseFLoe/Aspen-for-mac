# Properties 98 条安装目标核验（2026-11-19）

上一轮 98 条 `[TARGETDIR]/<文件名>` 均已确认安装目标：全部属于 **.NET 全局程序集缓存（GAC）**。其中 **97 条来源记录找到本机物理路径，涉及 48 个不同物理文件；1 条为本机禁用组件，没有已安装文件路径**。没有用猜测目录填补后者。

当前本地入口：`.local/properties-install-paths-20261119-verified/README.md`。其中五份分类 CSV 保留原 19,298 条来源及分类，增加安装定位字段；原 `.local/properties-deep-20261118-verified/` 继续保留为分类及完整源码证据基线。

| 原安装归属 | 与载荷哈希相同 | 实际路径已确定但内容不同 | 本机禁用组件 | 合计 |
| --- | ---: | ---: | ---: | ---: |
| Aspen Properties 主包 | 49 | 4 | 1 | 54 |
| Properties Enterprise Database Server 配套包 | 44 | 0 | 0 | 44 |
| 合计 | 93 | 4 | 1 | 98 |

## 原因与逐项证据

旧工具沿 `File → Component → Directory` 处理普通安装目录。这里的 `GlobalAssemblyCache` 目录在 MSI 中是 `TARGETDIR` 下的 `.:Global~1|GlobalAssemblyCache`，因此普通目录展开得到 `[TARGETDIR]/<文件名>`。这不能用于推断最终 GAC 物理路径。

本轮重新只读打开两个原 MSI，逐条连接 `File`、`Component`、`MsiAssembly` 和 `MsiAssemblyName`。98 条的 `File_Application` 全为空、程序集属性全为 .NET，且安装序列包含 `MsiPublishAssemblies` / `MsiUnpublishAssemblies`。微软说明，这类程序集安装到 GAC，不能沿普通组件目录规则定位。[MsiAssembly 表](https://learn.microsoft.com/en-us/windows/win32/msi/msiassembly-table)、[GAC 安装规则](https://learn.microsoft.com/en-us/windows/win32/msi/installation-of-assemblies-to-the-global-assembly-cache)。

随后用产品代码及组件 GUID 查询 `MsiGetComponentPathW`，仅在两个系统 GAC 根下枚举这些已知程序集名。读取实际 DLL 的程序集清单，核对名称、版本、文化、公钥标记及 MSI 明确提供的处理器架构，不执行 DLL，也不启动安装或修复。个别 MSI 未写架构时保留缺省，不自行补造值。组件注册路径优先；配套产品注册未知时要求唯一匹配的 GAC 清单身份。

本轮重新核对两个原 MSI、98 个 CAB 的哈希，并从这 98 个 CAB 重新读取相应载荷、核对大小及 SHA-256。读取 51 个候选 GAC 清单后排除版本或架构不符者，确定 48 个物理文件。所有原来源哈希保持不变。

每条来源各有独立 JSON 和同名 Markdown 说明，共 98 对，保存在新入口的 `evidence/`；`target-resolutions.json` 提供逐条入口。证据包括原来源、组件条件、安装表连接、程序集身份、安装注册状态、候选及选中路径、原载荷与本机哈希。

## 差异与未安装状态

4 条内容差异均来自主包：`AspenTech.CompositeDoc.dll`、`Xceed.Compression.dll`、`Xceed.FileSystem.dll`、`Xceed.Zip.dll`。实际 GAC 清单身份和注册目标匹配，但本机字节与原载荷不同，状态为 `gac-installed-different-content`。原安装包 SHA-256、analysis_key、分类及重复组继续保留，本机 SHA-256 单列；本轮未确认差异原因或行为等价性。

剩余 1 条为主包的 `SLMServerCLS.dll`，程序集版本 `1.0.0.0`、MSIL。其组件安装条件针对 32 位 Office，或无 Office 的 32 位 Windows；本机 API 返回 `INSTALLSTATE_NOTUSED (-7)`，同身份 GAC 文件未找到。另一版本 `2.0.0.0` 的 64 位组件确已安装，不能用它冒充缺失版本。该记录的 GAC 目标身份已确认，`installed_path` 与本机哈希留空，状态为 `gac-component-disabled`。微软将 NOTUSED 定义为本机禁用组件。[MsiGetComponentPathW](https://learn.microsoft.com/en-us/windows/win32/api/msi/nf-msi-msigetcomponentpathw)。

主包产品注册状态为 `DEFAULT (5)`；配套服务器包的产品及组件查询为 `UNKNOWN (-1)`。配套包的 44 条身份均在共享 GAC 中找到相同哈希文件，仅证明其交付内容在本机存在，不据此声称配套产品本身已经安装。

`unresolved_target_rows=0` 表示 98 条的目标类型及定位状态均已落实；**不表示 98 条都有已安装物理文件**。`physical_path_rows=97`、禁用组件 1 条独立统计。原 `relative_path` 保留以维持来源身份，新增 `resolved_target` 记录 GAC 身份，`installed_path` 记录实际物理路径，`previous_target_resolution` 保留旧状态。

## 验证与复现

独立校验通过：19,298 条来源身份及所有原字段保持不变（仅更新这 98 条的 `target_resolution`）；五份清单覆盖及排序、重复子集、重复组、98 对逐项证据、程序集表连接、实际文件哈希均一致。114 份输入指纹前后相同，涵盖分类基线、Plus 四份冻结清单、两包来源清单及原 MSI/CAB。结果在本地 `validation.json`。14 项无原版内容的回归测试通过，覆盖私有/原生程序集排除、版本/架构冲突、禁用组件、哈希差异、注册路径优先及未知产品注册的处理。

```powershell
& .local-tools/research/venv/Scripts/python.exe -X utf8 tools/resolve_properties_install_paths.py `
  --inventory .local/properties-deep-20261118-verified `
  --package-inventory .local/properties-inventory-20261118-primary `
  --package-inventory .local/properties-inventory-20261118-server `
  --plus-baseline .local/suffix-sampling-20261118-final `
  --output .local/properties-install-paths-NEW
& .local-tools/research/venv/Scripts/python.exe -X utf8 tools/validate_properties_install_paths.py `
  --before .local/properties-deep-20261118-verified `
  --after .local/properties-install-paths-NEW `
  --output .local/properties-install-paths-NEW/validation.json
& .local-tools/research/venv/Scripts/python.exe -X utf8 -m unittest discover `
  -s tests -p test_properties_install_paths.py -v
```

工具拒绝覆盖已有输出。当前 Windows 环境需要 Windows Installer API、Windows PowerShell 和已有 Python 工具；程序集清单读取由 `tools/Get-AssemblyIdentityEvidence.ps1` 完成。历史尝试也继续保留，当前验收只指向 `-verified` 目录。

本轮仅落实安装目标，不改变处理路线，不增加反编译或编译完成件。8 个 MDF/LDF 的读取限制、既有 VBA/原生局部恢复及其他阶段验收缺口继续保留。所有详细清单、原版输入及逐文件证据仅本地保存；仓库只提交自编工具、合成测试及本报告。数据库、公式和历史归档未修改。
