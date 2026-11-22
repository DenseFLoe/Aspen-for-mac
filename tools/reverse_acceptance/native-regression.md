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

## 验收器 1.1 对三件下游试点的复验

按 [VERIFY-PILOT-3 的三份固定输入、清单与命令](https://github.com/DenseFLoe/Aspen-for-mac/blob/2a1738d450ba68e9d3c11743bf2cbe98d4404f1a/handoff/assignments/VERIFY-PILOT-3.md) 运行 `project`，仅更换验收器。旧版和 1.1 均绑定 3 件、整批退出 1。下表是上游的原件复验结果。

| 样本 | 已在指令清单中但缺登记 | 从原件可信入口独立核得的间接站点 | 资源对照 |
| --- | ---: | ---: | --- |
| zedstwu.dll | 10 | 151 | 从可编辑模型重建 800 字节，与原件版本资源逐字节吻合。 |
| ppexec.dll | 5 | 181 | 包含 ID、语言与代码页的版本资源模型重建出相同的 800 字节。 |
| FindComponent.dll | 13 | 366 | 原件有 36 个资源叶节点，提交中缺少可独立核对这些字节的材料。 |

三件在上述静态可达范围内均未发现额外漏列的间接转移。原来显式未决的 44、15、99 个位置仍保留。静态可达范围受 PE 入口、可明确解码的直接边和调用可能返回的后继约束。

| 仅在试验副本中改变的一项事实 | 旧版表现 | 1.1 的证据 |
| --- | --- | --- |
| FindComponent.dll 的反汇编清单删除 `0x4eb4` 行 | 清单内缺登记数从 13 降至 12。 | 另列 1 个原件可证的漏列站点，给出异常函数入口 `0x4e7c` 和前驱 `0x4eb1`。 |
| zedstwu.dll 的清单把 `0x2344` 导入名从 `UU_EOERR` 写为 `UU_FAULT` | 导出专项仍通过。 | 指出调用地址、申报名与原件名。该导出的字节回编仍通过。 |
| ppexec.dll 的可编辑版本资源把 build 605 改成 606 | 没有版本资源专项记录。 | 在资源偏移 52、RVA `0x26094` 定位到首个差异，原件 `5d`，重建 `5e`。 |
| ppexec.dll 的覆盖表删除工具已发现的入口 `0x8d00` | 覆盖专项仍通过。 | `discovered_native_entry_missing` 精确定位该入口。 |

在单独的候选指纹对照中，只替换三件清单中第三件的预期交付指纹，结果为 2 件有已证实的缺口，1 件因输入身份不符待核。

## 验收器 1.2 对 FindComponent.dll 的逐址复验

固定使用下游 S13 的 19 个交付文件，交付 SHA-256 为 `4c1faed2f79210c13bb5de7b4139c3708e4126b4456fce0fe172a601c09ab081`，原件 SHA-256 为 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。99 处的清单引用、原件指令字节和调用边界全部对上。97 条为内存间接调用，旧表只给了基址提示。余下两条分别是 `0x4a7c CALL RAX` 和 `0x53f2 CALL R9`，旧表的目标栏为空。[固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/43017ac0901a450784de1678b55d2f501641b75c/handoff/inbox/NATIVE-337)

下表每行均从固定交付另建副本，走 `verify.py item`。正确导入和分派路径的完整附件格式见[下游提交说明](README.md#下游如何提交间接-call-的目标依据)。导入对照用的 `0x1012` 已在原主表登记，与原 99 个未决地址合计 100 个。

| 交付内容或单项改动 | 已确认 / 未决 / 有矛盾 | 报告能定位的事实 |
| --- | --- | --- |
| 下游原样 | 0 / 99 / 0 | 99 条均保留，原先另有的 13 处漏登仍见覆盖报告。 |
| 在 `0x1012` 提交槽 `0x75b8` 和 `mfc140.dll!#310` | 1 / 99 / 0 | 原件指令和导入描述符都指向该序号。 |
| 在上一项仅将目标改为 `#311` | 0 / 99 / 1 | `witness_import` 同址列出申报的 #311 和原件的 #310。 |
| 在原未决 `0x1389` 申报同一个 #310 并引用槽 `0x75b8` | 0 / 98 / 1 | `witness_operand` 指出原件实际调用 `[RBX+0x28]`。 |
| 在上一项去掉 `witness`，只留目标申报 | 0 / 99 / 0 | 该站点缺目标依据，仍为未决。 |
| 在 `0x53f2` 提交 `0x53eb` 从 Guard CF 槽 `0x7670` 装入 R9 的证据 | 0 / 99 / 0 | 分派路径证实，最终业务目标未知。 |
| 在上一项仅将分派槽改为 `0x7678` | 0 / 98 / 1 | `witness_slot` 指出原件读取 `0x7670`。 |
| 仅将旧表 `0x1389` 的基址提示从 RBX 改为 RAX | 0 / 98 / 1 | `indirect_target_base_mismatch` 定位到旧表的具体行与原件操作数。 |

按同一三件试点的固定清单运行 `project`，FindComponent、ppexec、zedstwu 均仍为整件未通过。三个样本的 21 个原有原生转移指标逐项相同，主表漏登数分别为 13、5、10，主表显式未决的转移分别为 99、15、44。上述 8 次单件检查和 1 次项目检查均按预期退出 1。单元测试另覆盖可核实的内部 RVA、只读表、错误寄存器、寄存器局部改写、分支绕过、伪造入口及原件指纹不符。

## 验收器 1.3 的内部函数与 CLR 复验

以固定候选逐件运行 `item`，计算原件及交付指纹。对 5 件原样交付再用相同绑定运行 `project`，每件专项逐项比对一致，整批得到 4 件未通过、1 件待核。5 件为下表中的三件、FindComponent S17 及 ppexec S13。

| 固定候选 | 专项独立核对 | 整件状态 |
| --- | --- | --- |
| [zedstwu S13](https://github.com/DenseFLoe/Aspen-for-mac/tree/c57d3a0349dff208bf2a4ef1bd32e9c03ac8a569/handoff/inbox/NATIVE-350) | `[0x1000, 0x1f1e)` 与 `[0xb980, 0xbec3)` 合计 5,217 字节、891 条指令、364 处重定位。四个原有导出另有 13,218 字节回编吻合。 | 未通过，覆盖表申报入口缺口 117，主表显式未决转移 44 处。 |
| [Ikc2Bkp S13](https://github.com/DenseFLoe/Aspen-for-mac/tree/71af42aa2df54844b0bb73397a747c052e6168b1/handoff/inbox/NATIVE-349) | `[0x24b3c, 0x24bd4)` 与 `[0x24ea4, 0x24eff)` 合计 243 字节、75 条指令、6 处重定位。 | 未通过，覆盖表申报入口缺口 13，主表显式未决转移 15 处。 |
| [WrapSaveMergeNNFiles S13](https://github.com/DenseFLoe/Aspen-for-mac/tree/b16fc9edf36dd9355e6ff083b3566ea8cbb57fdf/handoff/inbox/NATIVE-340) | 237 个 CLR 描述符、237 个槽、122 个不同 MethodDef 和 9 条附件中申报的原生跳转吻合。旧间接表有 13 个未决 CALL、11 个未决 JMP、15 条托管记录。 | 待核，未决间接转移和资源等仍需证据。 |

逐次用全新交付副本测试一个变化，每个副本都走 `item`。

| 单项改动 | 1.3 的对照结果 |
| --- | --- |
| zedstwu 的第一段将 `push r15` 换成 `push r14` | `region_code_byte` 指出首个差异 `0x1001`，原件 `57`，重编 `56`。第二段 1,347 字节仍吻合。 |
| zedstwu 的 `0x1071` 指令把重定位目标从 `0x24378` 改为 `0x22360` | `region_relocation_target` 定位到字段 `0x1074`，报告两侧目标。第二段仍吻合。 |
| WrapSaveMergeNNFiles 的表中把槽 `0x19018` 的 token 改为另一个存在的 MethodDef | `clr_fixup_slot_mismatch` 指到第 3 行、描述符 1、槽 0，申报 `0x0600000a`，原件 `0x06000001`，其余 236 槽仍吻合。 |
| WrapSaveMergeNNFiles 仅把旧表 `0x48b0` 的 `JMP RAX` 写成 `CALL RAX` | `indirect_target_transfer_kind_mismatch` 定位到该址。其余 10 个 JMP 仍是未决。 |

FindComponent S13 另作兼容复验，原 99 个 CALL 均保持未决。S17 的旧附件仍存在行号引用差异。局部回编和 CLR 磁盘槽核验各按自身证据给出结论。
