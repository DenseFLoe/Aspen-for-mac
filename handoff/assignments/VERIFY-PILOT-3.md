# VERIFY-PILOT-3 · 三件原生交付的批量验收试跑

执行方 `tietoumiao`，`assigned_seq=1`，自 #13 本轮 ACK 起 24 小时内回执。用 [#412 合并版验收器](https://github.com/DenseFLoe/Aspen-for-mac/tree/63f12578ef185f22e72b01076e81420b595a9499/tools/reverse_acceptance) 的 `project` 一次处理下表三件已有交付。前两件检验下游环境能否复现已有结果，第三件检验验收器在下游自己的固定交付上能给出哪些证据。原件级判定遵循[静态验收 v2](../standards/static-acceptance.v2.md)。

| 原件 | 固定候选目录 | 原件来源 | 回执重点 |
| --- | --- | --- | --- |
| zedstwu.dll | [NATIVE-350 第五轮](https://github.com/DenseFLoe/Aspen-for-mac/tree/a36f877783294ac56a138619ef162dd3ed52db68/handoff/inbox/NATIVE-350) | [首轮卡内的固定原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/63f12578ef185f22e72b01076e81420b595a9499/handoff/assignments/NATIVE-350.md) | 四个导出各自的匹配字节、重定位和状态；入口缺口与未决转移；提供方数据导入与观测到的调用。 |
| ppexec.dll | [NATIVE-346 第九轮](https://github.com/DenseFLoe/Aspen-for-mac/tree/e1dbdeedbac8413bce795bcc7f3bdaabf7bd4791/handoff/inbox/NATIVE-346) | [原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/346/ppexec.dll) | 入口缺口与未决地址分别计数。取一条未决记录回指主表和附件。该原件同时是上一件的导入提供方。 |
| FindComponent.dll | [下游 PR #411 的第十三轮固定交付](https://github.com/DenseFLoe/Aspen-for-mac/tree/43017ac0901a450784de1678b55d2f501641b75c/handoff/inbox/NATIVE-337) | [原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/337/FindComponent.dll) | 记录实际整件状态、已登记和缺失的转移、未决位置及样例证据。若与 #411 的站点统计不同，写明两边统计的对象和可复核位置。 |

## 复跑

从指定提交取得完整候选目录，包括源码、表及证据。保留目录内部的原始路径和字节。用 [三件清单](VERIFY-PILOT-3/inventory.csv) 中的 SHA-256 校验每份原件。取同一工具提交的 `tools/reverse_acceptance/` 和 `handoff/assignments/check-native-coverage.py`，按[使用说明](https://github.com/DenseFLoe/Aspen-for-mac/blob/63f12578ef185f22e72b01076e81420b595a9499/tools/reverse_acceptance/README.md)准备 Python 和依赖。导出回编使用 Windows Zig 0.13.0，`zig.exe` 的 SHA-256 为 `2e44af5bbf7a72ef8cbdae370284687c95d65a19affa469d2ad0364d905b8e84`。

从本次分配提交取得任务卡和两个输入文件。[绑定模板](VERIFY-PILOT-3/inputs.json)可直接复制到本地工作目录。把三份原件放入该目录的 `originals/`，完整候选分别放入 `delivery/NATIVE-350/`、`delivery/NATIVE-346/`、`delivery/NATIVE-337/`。在仓库根执行以下 PowerShell 命令，将两个环境变量设成本机实际路径。

```powershell
$env:ASPEN_PILOT_INPUTS = (Resolve-Path '.local/verify-pilot-3/inputs.json').Path
$env:ASPEN_PILOT_ZIG = (Get-Command zig.exe -ErrorAction Stop).Source
python -B tools/reverse_acceptance/verify.py project --inventory handoff/assignments/VERIFY-PILOT-3/inventory.csv --inventory-sha256 7a19965d3734a40040f1fc0a6d4db67f4e5fdd36dfdd7601e466de721659fccb --inputs "$env:ASPEN_PILOT_INPUTS" --assembler "$env:ASPEN_PILOT_ZIG" > "$env:ASPEN_PILOT_INPUTS.project.json"
$batchExit = $LASTEXITCODE
$report = Get-Content -Raw -Encoding utf8 "$env:ASPEN_PILOT_INPUTS.project.json" | ConvertFrom-Json
$report | Select-Object scope,status,items_expected,items_bound,distinct_originals,counts
"project exit=$batchExit"
```

本次分母为三件。`items_expected`、`items_bound`、`distinct_originals` 在完整供件时均应为 3，计数之和应等于 3。记录实际退出码，0 为整批通过，1 为至少一件有已核实的缺口，2 为仍有待核且无已确认失败，或输入本身无法解析。逐件读取 `rows[].proof.checks`，保留 `pass`、`fail`、`inconclusive` 及具体原因。运行结束后再对照[上游固定样本实测](https://github.com/DenseFLoe/Aspen-for-mac/blob/63f12578ef185f22e72b01076e81420b595a9499/tools/reverse_acceptance/native-regression.md)。发现差异时附原 SHA、RVA 或主表行号、两侧值和复现办法。

缺某个输入时先处理可运行的项目，按原 SHA、固定来源、实际错误和恢复条件回报。若只有受信 Zig 无法使用，去掉 `--assembler` 仍可运行其余核对，并在回执中标出导出回编待核。

上游在 #411 固定交付上实跑得到 475 个可核的间接转移站点，462 个已有登记，其中 99 个显式未决。其余 13 个站点在 `findings` 中为 `missing_transfer`，原件 RVA 依次为 `0x4eb4`、`0x54ff`、`0x5576`、`0x55b9`、`0x5bc6`、`0x5c02`、`0x5e39`、`0x5e75`、`0x5ec6`、`0x5f03`、`0x5f59`、`0x6050`、`0x6070`。这给出了 [#13 提问](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7079447161)中所需的逐址对照。请据本机 JSON 核实；可记录尚缺的对象类型或目标证据。

## 提交

在 `handoff/inbox/VERIFY-PILOT-3/` 放 `s1-started.md`、`s1-submission.md` 和本轮原始机器输出 `project.json`。提交回执写工具提交、Python/依赖/Zig 版本、运行命令、真实退出码、报告 SHA-256，以及三行逐件结论和仍需补的证据。仓库中保存报告和回执；三份原件和候选已在表中定位。执行方开产物 PR，在 #13 报任务号、轮次与 PR head，上游按相同输入复跑。等待本批反馈后再决定扩量。
