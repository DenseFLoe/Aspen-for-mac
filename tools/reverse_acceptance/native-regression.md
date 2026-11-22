# 三份原生交付的固定输入复验

同一原件、同一交付、同一工具链各跑两次 `verify.py item`。旧版本取自主干 `12dafbebf12c2f9c6f275c1197ccf5c073c31b45`，新版本取自本记录所在提交。候选目录为各提交的 `handoff/inbox/NATIVE-编号/`。三个目录的 44、80、83 个文件按路径、大小和 Git blob 指纹回读核对。三件的整件退出码在改动前后均为 **1**。

| 样本及固定候选 | 旧输出 | 新输出 | 原件与专项复跑依据 | 仍未覆盖 |
| --- | --- | --- | --- | --- |
| [zedstwu.dll，第五轮](https://github.com/DenseFLoe/Aspen-for-mac/tree/a36f877783294ac56a138619ef162dd3ed52db68/handoff/inbox/NATIVE-350) | 列出 121 个入口缺口。读取旧转移表表头时报 `invalid_input`，没有导出回编结果。 | 四个导出逐个通过。705 条已登记直接边的源指令和目标操作数与原件相符，其中 229 个位置还缺已核对清单中的指令边界。列出 44 个未决转移地址和 10 个未登记间接转移位置。 | 通用验收器独立编译下表的四份 C 源码。该件业务专项另行核得同一批 13,218 字节、812 处 REL32。 | 255 个入口中有 121 个申报缺口。44 处转移的最终目标仍待证。 |
| [Ikc2Bkp.dll，第九轮](https://github.com/DenseFLoe/Aspen-for-mac/tree/a65e08d7c459587bb734926974c7e9a902284437/handoff/inbox/NATIVE-349) | 15 个入口缺口、15 处未决，另有 2 个漏登和 72 个重复登记的转移位置。 | 保留上述判定，并列出未决 RVA。 | 独立重跑该件重组和 CRT 专项。187 个实现共 145,279 字节、5,347 处重定位。这一总数已包含本轮 2 段的 271 字节、25 处重定位，185 个旧实现及 4 个展开入口的证据保留。 | 未决边仍需目标证据，入口定位也仍有缺口。187 段的结果来自该件专项。 |
| [ppexec.dll，第九轮](https://github.com/DenseFLoe/Aspen-for-mac/tree/e1dbdeedbac8413bce795bcc7f3bdaabf7bd4791/handoff/inbox/NATIVE-346) | 532 个入口、0 个入口缺口。转移检查报 15 处未决、5 个漏登位置。 | 15 处未决逐址对应主表与附件。35 个使用内部边资料的位置仍需复核可行路径。 | 索引专项从原件核对 20 张表的 2,946 个槽。上轮待查的 20 处索引中，14 处在指定入口和长度前提下有界，1 处从已知入口未见可达路径。回调专项核得 4 个固定只读零槽。 | 5 处需调用方长度约束，10 处需回调证据。其中 1 处已知一个调用方传入的目标，其他调用方和可能目标尚未穷尽。 |

## 四段回编结果

| 导出 | 原件 RVA 区间，右端不含 | 匹配字节 | REL32 |
| --- | --- | ---: | ---: |
| DSWU_EUDL01 | 0x2320–0x237a | 90 | 5 |
| DSWU_IUDL01 | 0x2380–0x2636 | 694 | 63 |
| DSWU_UDL01I | 0x78b0–0x9c35 | 9,093 | 547 |
| DSWU_ZUDL01 | 0xbed0–0xcbdd | 3,341 | 197 |

双件对照中，`ppexec.dll!PPEXEC_PPROY` 位于提供方的 `.data` 节，RVA 为 `0x21f60`。使用方在 `0x9327` 读取 IAT 槽 `0x19308`，在 `0x932e` 读取指向对象的首个双精度值。`0x153ca` 是引用同一槽的 JMP 桩。在已核对的指令清单和已登记直接边中，未发现直接进入该桩的调用。JSON 单列提供方导出、槽读取、桩和观测到的调用。

## 复跑

Windows AMD64，Python 3.12.14，依赖见 [requirements.txt](requirements.txt)。旧专项另用 Capstone 5.0.6。Zig 0.13.0 的 `zig.exe` SHA-256 为 `2e44af5bbf7a72ef8cbdae370284687c95d65a19affa469d2ad0364d905b8e84`。以下 PowerShell 命令使用旧版和本版仓库的完整目录（均须包含 `handoff/assignments/check-native-coverage.py`）、原件目录、三个固定候选目录和 Zig 的绝对路径。

```powershell
param($OldRoot, $NewRoot, $Originals, $Candidates, $Zig)
$samples = @(
    @('350','zedstwu.dll','09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b'),
    @('349','Ikc2Bkp.dll','bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011'),
    @('346','ppexec.dll','d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a')
)
foreach ($s in $samples) {
    $original = Join-Path $Originals $s[1]
    $unit = Join-Path $Candidates "NATIVE-$($s[0])"
    foreach ($root in $OldRoot,$NewRoot) {
        python -B "$root/tools/reverse_acceptance/verify.py" item --original $original --sha256 $s[2] --delivery $unit --assembler $Zig
    }
    python -B "$NewRoot/handoff/assignments/check-native-coverage.py" "NATIVE-$($s[0])" --original $original --submission $unit
}
$item = "$NewRoot/tools/reverse_acceptance/verify.py"
python -B $item item --original "$Originals/zedstwu.dll" --sha256 $samples[0][2] --delivery "$Candidates/NATIVE-350" --assembler $Zig --provider "$Originals/ppexec.dll" --provider-sha256 $samples[2][2]
python -B -m unittest discover -s "$NewRoot/tools/reverse_acceptance" -v
```

三件的交接检查均退出 2。逐件专项的复跑命令还可查阅固定裁定中的输入与工具版本。[zedstwu.dll 裁定](https://github.com/DenseFLoe/Aspen-for-mac/blob/47f1f4dd21b7b4bd1f5bc331a6d7561c5ba2b0fd/handoff/outbox/NATIVE-350/s5-decision.md) · [Ikc2Bkp.dll 裁定](https://github.com/DenseFLoe/Aspen-for-mac/blob/47f1f4dd21b7b4bd1f5bc331a6d7561c5ba2b0fd/handoff/outbox/NATIVE-349/s9-decision.md) · [ppexec.dll 裁定](https://github.com/DenseFLoe/Aspen-for-mac/blob/47f1f4dd21b7b4bd1f5bc331a6d7561c5ba2b0fd/handoff/outbox/NATIVE-346/s9-decision.md)

## 能推翻局部通过的反例

- 只把 `DSWU_EUDL01.c` 第一条直接调用的目标从 `rva_15388` 改为 `rva_1538e`。函数长度和重定位数相同，正常 `item` 返回 `export_relocation_target`。它定位到字段 `0x2345`，给出原目标和回编目标。其他三个导出仍通过，121 个入口缺口仍可见，整件退出 1。
- 只移除 `ppexec.dll` 主表中 `0x91a4` 的未决记录，保留同址附件。`control_gap_main_row` 指向该址。主表显式未决数变为 14，含附件的不同未决地址仍为 15，整件退出 1。

本轮项目模式在固定的 1,397 个原件中绑定上述三件，结果为 3 件未通过、1,394 件缺输入待核。其他格式的源码、未能确定边界的函数、任意间接目标和 Windows 运行行为仍需要相应的证据。
