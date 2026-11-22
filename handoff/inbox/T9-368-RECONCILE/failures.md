# T9 失败清单（按 fail_code 分组 · 第二轮更正）

机检预审口径：本清单只列**机械可判**的缺口；语义层（类型用途、调用约定、逻辑等价）未复核，故不等于上游「静态验收未通过」结论，也不做 P0–P3 终判。

总件数 1000 ｜ fail **470** ｜ partial **0** ｜ blocked **0** ｜ pass **530**

> **2026-11-22 第二轮更正**：旧第 5 行「978 pass / 15 fail / 7 partial」作废。455 件 .cs.txt 尾部残留 ilspycmd 升级提示（tool_nag_tail）首轮漏检，现已全部计入 fail；旧标 partial 的 7 件（idx 311, 332, 357, 359, 459, 968, 982）均带 tool_nag_tail，verdict 已改为 fail，partial 归 0。
> 命名映射：a3_report_missing 即 lead 口径的 report_missing（15 件）；a2_sha_missing 与之同源（报告缺失 ⇒ 无第二处指纹可比）。

复跑命令（单件）：PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh

## fail_code 计数（独立行数，允许重叠）

| fail_code | 件数 | 含义 |
| --- | ---: | --- |
| tool_nag_tail | 455 | .cs.txt 尾部残留 ilspycmd 升级提示（未注释、非合法 C#）；首轮 A6/B4 只匹配行首工具名，漏检 |
| a2_sha_missing | 15 | 归档说明或制作者报告里取不到 64 位 SHA-256（报告缺失 ⇒ 无第二处指纹可比） |
| a3_report_missing | 15 | 制作者报告（v0.*/制作者报告/<name>.md）缺失或为空 |
| tier_b_incomplete | 6 | Tier B 只做一半（CLR 缺 il.txt，tier_b=PARTIAL:no_il） |
| analyze_failed | 1 | 报告自述 status=failed_analyze（反编译失败），无统计数可比对（tier_b=PARTIAL:no_claim） |
| **原因占用合计** | **492** | 去重后 fail 行 470（重叠 22 行） |

> 多码行：15 行同带 a2_sha_missing + a3_report_missing；6 行同带 tier_b_incomplete + tool_nag_tail；1 行同带 analyze_failed + tool_nag_tail。下面分组明细逐组列全，同一 idx 可在多组出现。

## 分组明细

### tool_nag_tail（455 件）

复跑：PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 4 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/AspenTech.AspenCxs.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1654 hdr=1654 md_methods=1654; b3_cs_hits=2(@2162,2195) ; b3_cs=lines 2162,2195 |
| 5 | 5 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/Interop.SLMErrorDialogLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=9 hdr=9 md_methods=None ; |
| 6 | 6 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/AspenTech.AspenCxs.ExportToExcel.dll | fail | A:PASS ; B:PASS ; b1_il_MD=666 hdr=666 md_methods=666 ; |
| 7 | 7 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/AspenTech.AspenCxs.SummaryGrid.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1085 hdr=1085 md_methods=1085; b3_cs_hits=7(@11580,11610,11643,11675,11712,11739,11760) ; b3_cs=lines 11580,11610,11643,116… |
| 8 | 8 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/AspenTech.AspenCxs.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1654 hdr=1654 md_methods=1654; b3_cs_hits=2(@2162,2195) ; b3_cs=lines 2162,2195 |
| 9 | 9 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.Controls.Editors.XamComboEditor.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1093 hdr=1093 md_methods=1093 ; |
| 10 | 10 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.DataManager.dll | fail | A:PASS ; B:PASS ; b1_il_MD=817 hdr=817 md_methods=817; b3_cs_hits=2(@3293,6547) ; b3_cs=lines 3293,6547 |
| 11 | 11 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.Editors.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3211 hdr=3211 md_methods=3211 ; |
| 12 | 0 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.dll | fail | A:PASS ; B:PASS ; b1_il_MD=8852 hdr=8852 md_methods=8852; b3_cs_hits=1(@3085) ; b3_cs=lines 3085 |
| 13 | 1 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/Interop.SECSERVEROBJECTLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=290 hdr=290 md_methods=290 ; |
| 14 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/Interop.SLMErrorDialogLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=9 hdr=9 md_methods=None ; |
| 15 | 3 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/Interop.appinitLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3 hdr=3 md_methods=None ; |
| 16 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AdbBrowser.exe | fail | A:PASS ; B:PASS ; b1_il_MD=113 hdr=113 md_methods=113 ; |
| 17 | 5 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AdbComInterfaces.dll | fail | A:PASS ; B:PASS ; b1_il_MD=66 hdr=66 md_methods=None ; |
| 18 | 6 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AdbConfigOptions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=19 hdr=19 md_methods=None ; |
| 19 | 7 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AdbCsLayer.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1189 hdr=1189 md_methods=1189; b3_cs_hits=32(@72,80,88,96,104,125,130,135) ; b3_cs=lines 72,80,88,96,104,125,130,135,140,14… |
| 21 | 9 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AdsComparer.exe | fail | A:PASS ; B:PASS ; b1_il_MD=109 hdr=109 md_methods=109; b3_cs_hits=1(@759) ; b3_cs=lines 759 |
| 22 | 10 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/CompareAds.dll | fail | A:PASS ; B:PASS ; b1_il_MD=54 hdr=54 md_methods=54 ; |
| 23 | 11 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/AspenTech.CompositeDoc.dll | fail | A:PASS ; B:PASS ; b1_il_MD=258 hdr=258 md_methods=258 ; |
| 25 | 1 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AdbComInterfaces.dll | fail | A:PASS ; B:PASS ; b1_il_MD=66 hdr=66 md_methods=66 ; |
| 26 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenDataShareCS.dll | fail | A:PASS ; B:PASS ; b1_il_MD=20069 hdr=20069 md_methods=20069 ; |
| 27 | 3 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenHydraulicsResources.dll | fail | A:PASS ; B:PASS ; b1_il_MD=639 hdr=639 md_methods=639 ; |
| 28 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.AspenCxs.CxsViewModel.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2439 hdr=2439 md_methods=2439; b3_cs_hits=8(@4812,19938,20293,20298,20316,20321,20334,20339) ; b3_cs=lines 4812,19938,20293… |
| 29 | 5 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.AspenCxs.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1654 hdr=1654 md_methods=1654; b3_cs_hits=2(@2162,2195) ; b3_cs=lines 2162,2195 |
| 30 | 6 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.Components.Utilities.dll | fail | A:PASS ; B:PASS ; b1_il_MD=20 hdr=20 md_methods=None ; |
| 31 | 7 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.EquipmentAnalysis.DataMigration.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1515 hdr=1515 md_methods=1515 ; |
| 32 | 8 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.EquipmentAnalysis.Engine.dll | fail | A:PASS ; B:PASS ; b1_il_MD=904 hdr=904 md_methods=904 ; |
| 33 | 9 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.EquipmentAnalysis.Infrastructure.dll | fail | A:PASS ; B:PASS ; b1_il_MD=847 hdr=847 md_methods=847 ; |
| 34 | 10 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.EquipmentAnalysis.Models.dll | fail | A:PASS ; B:PASS ; b1_il_MD=4878 hdr=4878 md_methods=4878; b3_cs_hits=25(@5126,5134,5144,5152,5174,5179,5213,5218) ; b3_cs=lines 5126,5134,5144,5152,51… |
| 35 | 11 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.EquipmentAnalysis.PSVControlResources.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2620 hdr=2620 md_methods=2620; b3_cs_hits=29(@7840,7856,7872,7892,7912,7935,7963,8028) ; b3_cs=lines 7840,7856,7872,7892,79… |
| 36 | 0 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.EquipmentAnalysis.Resources.dll | fail | A:PASS ; B:PASS ; b1_il_MD=730 hdr=730 md_methods=730; b3_cs_hits=1(@609) ; b3_cs=lines 609 |
| 37 | 1 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.Hydraulics.Framework.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1154 hdr=1154 md_methods=1154; b3_cs_hits=11(@3191,4320,8284,8378,8448,8608,8638,8705) ; b3_cs=lines 3191,4320,8284,8378,84… |
| 38 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.Visualisation.CommonShell.Infrastructure.Wpf.dll | fail | A:PASS ; B:PASS ; b1_il_MD=857 hdr=857 md_methods=857 ; |
| 39 | 3 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.Visualisation.Controls.Support.Wpf.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1820 hdr=1820 md_methods=1820; b3_cs_hits=8(@2089,2440,4224,11239,11263,11275,11287,11299) ; b3_cs=lines 2089,2440,4224,112… |
| 40 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/CraneMethodLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=20 hdr=20 md_methods=20 ; |
| 41 | 5 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Data.dll | fail | A:PASS ; B:PASS ; b1_il_MD=237 hdr=237 md_methods=237; b3_cs_hits=1(@416) ; b3_cs=lines 416 |
| 42 | 6 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/FluidFlowInterfaceAndEnum.dll | fail | A:PASS ; B:PASS ; b1_il_MD=72 hdr=72 md_methods=72 ; |
| 43 | 7 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/FluidFlowhandler.dll | fail | A:PASS ; B:PASS ; b1_il_MD=865 hdr=865 md_methods=865 ; |
| 44 | 8 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/HTFSMethodLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=158 hdr=158 md_methods=158 ; |
| 45 | 9 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/InfragisticsWPF.Editors.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3222 hdr=3222 md_methods=3222 ; |
| 46 | 10 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/InfragisticsWPF.Ribbon.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3744 hdr=3744 md_methods=3744 ; |
| 47 | 11 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/InfragisticsWPF.dll | fail | A:PASS ; B:PASS ; b1_il_MD=8881 hdr=8881 md_methods=8881; b3_cs_hits=1(@3175) ; b3_cs=lines 3175 |
| 48 | 0 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Microsoft.Practices.Composite.dll | fail | A:PASS ; B:PASS ; b1_il_MD=489 hdr=489 md_methods=489 ; |
| 49 | 1 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Microsoft.Practices.ServiceLocation.dll | fail | A:PASS ; B:PASS ; b1_il_MD=44 hdr=44 md_methods=None ; |
| 50 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Microsoft.Practices.Unity.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1029 hdr=1029 md_methods=1029; b3_cs_hits=5(@1544,1549,1554,1571,1576) ; b3_cs=lines 1544,1549,1554,1571,1576 |
| 51 | 3 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/NetworkPlugins.dll | fail | A:PASS ; B:PASS ; b1_il_MD=28 hdr=28 md_methods=28 ; |
| 52 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/PSVLegacyDataRecallServer.exe | fail | A:PASS ; B:PASS ; b1_il_MD=134 hdr=134 md_methods=134 ; |
| 53 | 5 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/PSVSizingEngine.dll | fail | A:PASS ; B:PASS ; b1_il_MD=535 hdr=535 md_methods=535 ; |
| 54 | 6 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/PipeFittingServer.dll | fail | A:PASS ; B:PASS ; b1_il_MD=722 hdr=722 md_methods=722 ; |
| 55 | 7 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/PipeFlowMethodLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=22 hdr=22 md_methods=22 ; |
| 56 | 8 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/PluginsSupport.dll | fail | A:PASS ; B:PASS ; b1_il_MD=48 hdr=48 md_methods=48 ; |
| 57 | 9 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/PropertyUtilities.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1436 hdr=1436 md_methods=1436; b3_cs_hits=8(@3507,6802,6807,6812,6817,10624,10757,10762) ; b3_cs=lines 3507,6802,6807,6812,… |
| 58 | 10 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/TeeJunctionMethodLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=35 hdr=35 md_methods=35 ; |
| 60 | 0 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/ActiveXtender.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1847 hdr=1847 md_methods=1847 ; |
| 61 | 1 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/ActiveXtender11.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1640 hdr=1640 md_methods=1640 ; |
| 64 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/CapeError.dll | fail | A:PASS ; B:PASS ; b1_il_MD=171 hdr=171 md_methods=171 ; |
| 69 | 9 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HyExtn3.dll | fail | A:PASS ; B:PASS ; b1_il_MD=70 hdr=70 md_methods=70 ; |
| 72 | 0 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/NETExtnLoader.dll | fail | A:PASS ; B:PASS ; b1_il_MD=9 hdr=9 md_methods=None ; |
| 73 | 1 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/RegHelper.dll | fail | A:PASS ; B:PASS ; b1_il_MD=130 hdr=130 md_methods=130 ; |
| 74 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/RegImage.dll | fail | A:PASS ; B:PASS ; b1_il_MD=63 hdr=63 md_methods=63 ; |
| 75 | 3 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/regextn32.exe | fail | A:PASS ; B:PASS ; b1_il_MD=5 hdr=5 md_methods=5 ; |
| 111 | 3 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/AspenTech.AspenCxs.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1654 hdr=1654 md_methods=1654; b3_cs_hits=2(@2162,2195) ; b3_cs=lines 2162,2195 |
| 112 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/AspenTech.AspenCxs.ExportToExcel.dll | fail | A:PASS ; B:PASS ; b1_il_MD=666 hdr=666 md_methods=666 ; |
| 113 | 5 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/AspenTech.AspenCxs.SummaryGrid.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1085 hdr=1085 md_methods=1085; b3_cs_hits=7(@11580,11610,11643,11675,11712,11739,11760) ; b3_cs=lines 11580,11610,11643,116… |
| 114 | 6 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/AspenTech.AspenCxs.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1654 hdr=1654 md_methods=1654; b3_cs_hits=2(@2162,2195) ; b3_cs=lines 2162,2195 |
| 115 | 7 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.Controls.Editors.XamComboEditor.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1093 hdr=1093 md_methods=1093 ; |
| 116 | 8 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.DataManager.dll | fail | A:PASS ; B:PASS ; b1_il_MD=817 hdr=817 md_methods=817; b3_cs_hits=2(@3293,6547) ; b3_cs=lines 3293,6547 |
| 117 | 9 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.Editors.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3211 hdr=3211 md_methods=3211 ; |
| 118 | 10 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.dll | fail | A:PASS ; B:PASS ; b1_il_MD=8852 hdr=8852 md_methods=8852; b3_cs_hits=1(@3085) ; b3_cs=lines 3085 |
| 119 | 11 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/AxInterop.MOLESTRUCTLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=78 hdr=78 md_methods=78 ; |
| 120 | 0 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/ICSharpCode.SharpZipLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=585 hdr=585 md_methods=585 ; |
| 121 | 1 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Interop.BPCOMPRESSORLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=9 hdr=9 md_methods=None ; |
| 122 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Interop.MOLESTRUCTLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=130 hdr=130 md_methods=130 ; |
| 123 | 3 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/MMCLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=740 hdr=740 md_methods=740 ; |
| 124 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Microsoft.Bcl.AsyncInterfaces.dll | fail | A:PASS ; B:PASS ; b1_il_MD=81 hdr=81 md_methods=81 ; |
| 125 | 5 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Microsoft.Extensions.Configuration.Abstractions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=107 hdr=107 md_methods=107 ; |
| 126 | 6 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Microsoft.Extensions.Configuration.dll | fail | A:PASS ; B:PASS ; b1_il_MD=258 hdr=258 md_methods=258 ; |
| 127 | 7 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Microsoft.Extensions.DependencyInjection.Abstractions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=351 hdr=351 md_methods=351 ; |
| 128 | 8 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Microsoft.Extensions.DependencyInjection.dll | fail | A:PASS ; B:PASS ; b1_il_MD=476 hdr=476 md_methods=476 ; |
| 129 | 9 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Microsoft.Extensions.Logging.Abstractions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=427 hdr=427 md_methods=427 ; |
| 130 | 10 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Microsoft.Extensions.Logging.dll | fail | A:PASS ; B:PASS ; b1_il_MD=269 hdr=269 md_methods=269 ; |
| 131 | 11 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Microsoft.Extensions.Options.dll | fail | A:PASS ; B:PASS ; b1_il_MD=399 hdr=399 md_methods=399 ; |
| 132 | 0 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Npgsql.dll | fail | A:PASS ; B:PASS ; b1_il_MD=7446 hdr=7446 md_methods=7446; b3_cs_hits=10(@34762,45788,47903,47922,48520,50732,50737,50742) ; b3_cs=lines 34762,45788,47… |
| 133 | 1 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/SelectAspenLanguage.exe | fail | A:PASS ; B:PASS ; b1_il_MD=48 hdr=48 md_methods=48 ; |
| 134 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Serilog.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1145 hdr=1145 md_methods=1145 ; |
| 135 | 3 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Buffers.dll | fail | A:PASS ; B:PASS ; b1_il_MD=34 hdr=34 md_methods=None ; |
| 136 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Data.SqlClient.dll | fail | A:PASS ; B:PASS ; b1_il_MD=431 hdr=431 md_methods=431; b3_cs_hits=1(@845) ; b3_cs=lines 845 |
| 137 | 5 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Diagnostics.DiagnosticSource.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1224 hdr=1224 md_methods=1224 ; |
| 138 | 6 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Memory.dll | fail | A:PASS ; B:PASS ; b1_il_MD=703 hdr=703 md_methods=703; b3_cs_hits=3(@5639,5643,5648) ; b3_cs=lines 5639,5643,5648 |
| 139 | 7 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Numerics.Vectors.dll | fail | A:PASS ; B:PASS ; b1_il_MD=188 hdr=188 md_methods=188 ; |
| 140 | 8 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Security.AccessControl.dll | fail | A:PASS ; B:PASS ; b1_il_MD=87 hdr=87 md_methods=87 ; |
| 141 | 9 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Text.Encodings.Web.dll | fail | A:PASS ; B:PASS ; b1_il_MD=461 hdr=461 md_methods=461 ; |
| 142 | 10 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Text.Json.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3739 hdr=3739 md_methods=3739 ; |
| 143 | 11 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Threading.Channels.dll | fail | A:PASS ; B:PASS ; b1_il_MD=279 hdr=279 md_methods=279 ; |
| 144 | 0 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Threading.Tasks.Extensions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=110 hdr=110 md_methods=110 ; |
| 145 | 1 | Plus | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.ValueTuple.dll | fail | A:PASS ; B:PASS ; b1_il_MD=11 hdr=11 md_methods=11 ; |
| 146 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/ACMDotNetWrapper.dll | fail | A:PASS ; B:PASS ; b1_il_MD=31 hdr=31 md_methods=31 ; |
| 147 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/ACMOtfReader.dll | fail | A:PASS ; B:PASS ; b1_il_MD=122 hdr=122 md_methods=122 ; |
| 155 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/AspenCustomModelManager.exe | fail | A:PASS ; B:PASS ; b1_il_MD=39 hdr=39 md_methods=39 ; |
| 156 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/AspenTech.Modeler.ACMExpUtilities.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1080 hdr=1080 md_methods=1080; b3_cs_hits=19(@267,272,277,551,556,3713,3721,3725) ; b3_cs=lines 267,272,277,551,556,3713,37… |
| 157 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/BSPCycleManager.dll | fail | A:PASS ; B:PASS ; b1_il_MD=415 hdr=415 md_methods=415 ; |
| 164 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Documents.Excel.v15.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=13566 hdr=13566 md_methods=13566; b3_cs_hits=5(@57068,106025,106060,106294,106329) ; b3_cs=lines 57068,106025,106060,106294… |
| 165 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Shared.v15.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1477 hdr=1477 md_methods=1477 ; |
| 166 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.Misc.v15.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=6948 hdr=6948 md_methods=6948; b3_cs_hits=1(@53191) ; b3_cs=lines 53191 |
| 167 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraChart.v15.1.Design.dll | fail | A:PASS ; B:PASS ; b1_il_MD=846 hdr=846 md_methods=846 ; |
| 168 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinChart.v15.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=8549 hdr=8549 md_methods=8549; b3_cs_hits=2(@51155,51160) ; b3_cs=lines 51155,51160 |
| 169 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinDataSource.v15.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=691 hdr=691 md_methods=691 ; |
| 170 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinEditors.v15.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3306 hdr=3306 md_methods=3306 ; |
| 171 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinGrid.ExcelExport.v15.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=643 hdr=643 md_methods=643 ; |
| 172 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinGrid.v15.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=13914 hdr=13914 md_methods=13914; b3_cs_hits=5(@5863,58588,58596,58661,186448) ; b3_cs=lines 5863,58588,58596,58661,186448 |
| 173 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinTabControl.v15.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1428 hdr=1428 md_methods=1428 ; |
| 182 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.CalculationService.dll | fail | A:PASS ; B:PASS ; b1_il_MD=624 hdr=624 md_methods=624; b3_cs_hits=2(@503,2205) ; b3_cs=lines 503,2205 |
| 183 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.DataManagement.dll | fail | A:PASS ; B:PASS ; b1_il_MD=88 hdr=88 md_methods=88 ; |
| 184 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.DatabaseManagement.dll | fail | A:PASS ; B:PASS ; b1_il_MD=179 hdr=179 md_methods=179; b3_cs_hits=4(@1418,2005,2033,2054) ; b3_cs=lines 1418,2005,2033,2054 |
| 185 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.Document.dll | fail | A:PASS ; B:PASS ; b1_il_MD=256 hdr=256 md_methods=256 ; |
| 186 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.PhysicalProperties.dll | fail | A:PASS ; B:PASS ; b1_il_MD=10876 hdr=10876 md_methods=10876; b3_cs_hits=10(@1599,4198,4856,5044,5085,5147,5419,6089) ; b3_cs=lines 1599,4198,4856,5044… |
| 188 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.Utilities.dll | fail | A:PASS ; B:PASS ; b1_il_MD=14 hdr=14 md_methods=14 ; |
| 196 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/Npgsql.dll | fail | A:PASS ; B:PASS ; b1_il_MD=7446 hdr=7446 md_methods=7446; b3_cs_hits=10(@34762,45788,47903,47922,48520,50732,50737,50742) ; b3_cs=lines 34762,45788,47… |
| 197 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/PackingHydraulicDLL_v1.0.dll | fail | A:PASS ; B:PASS ; b1_il_MD=113 hdr=113 md_methods=113 ; |
| 228 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/cstabledata.dll | fail | A:PASS ; B:PASS ; b1_il_MD=79 hdr=79 md_methods=79 ; |
| 295 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/APropDataConvertor.dll | fail | A:PASS ; B:PASS ; b1_il_MD=574 hdr=574 md_methods=574 ; |
| 296 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/ApedAspenProperties.dll | fail | A:PASS ; B:PASS ; b1_il_MD=257 hdr=257 md_methods=257 ; |
| 297 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/ApedCommon.dll | fail | A:PASS ; B:PASS ; b1_il_MD=321 hdr=321 md_methods=321 ; |
| 298 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/ApedDataManager.dll | fail | A:PASS ; B:PASS ; b1_il_MD=936 hdr=936 md_methods=936 ; |
| 299 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/ApedIntegration.dll | fail | A:PASS ; B:PASS ; b1_il_MD=508 hdr=508 md_methods=508 ; |
| 300 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/ApedIntegration64.dll | fail | A:PASS ; B:PASS ; b1_il_MD=508 hdr=508 md_methods=508 ; |
| 301 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/ApedIntegrationPostgreSQL.dll | fail | A:PASS ; B:PASS ; b1_il_MD=444 hdr=444 md_methods=444 ; |
| 302 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/DipprData.dll | fail | A:PASS ; B:PASS ; b1_il_MD=102 hdr=102 md_methods=102 ; |
| 303 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/dbRestore.exe | fail | A:PASS ; B:PASS ; b1_il_MD=51 hdr=51 md_methods=51 ; |
| 304 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/dbTesterAdv.exe | fail | A:PASS ; B:PASS ; b1_il_MD=57 hdr=57 md_methods=57 ; |
| 308 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/APlusRegUtl.exe | fail | A:PASS ; B:PASS ; b1_il_MD=20 hdr=20 md_methods=20 ; |
| 309 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AdbComInterfaces.dll | fail | A:PASS ; B:PASS ; b1_il_MD=66 hdr=66 md_methods=None ; |
| 310 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AdsAccessor.dll | fail | A:PASS ; B:PASS ; b1_il_MD=20069 hdr=20069 md_methods=20069 ; |
| 311 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AdvancedFileDialog.ocx | fail | A:PASS ; B:PARTIAL:no_il ; no_tierb_input ; |
| 312 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AdvancedFileDialogLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=42 hdr=42 md_methods=None ; |
| 315 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenDataShareCS.dll | fail | A:PASS ; B:PASS ; b1_il_MD=20069 hdr=20069 md_methods=20069 ; |
| 316 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.ActivationDashboard.Infrastructure.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1058 hdr=1058 md_methods=1058; b3_cs_hits=10(@1041,1058,1662,1682,1719,1739,1792,1834) ; b3_cs=lines 1041,1058,1662,1682,17… |
| 317 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenCxs.ExportToExcel.dll | fail | A:PASS ; B:PASS ; b1_il_MD=666 hdr=666 md_methods=666 ; |
| 318 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenCxs.InfragisticsControls.dll | fail | A:PASS ; B:PASS ; b1_il_MD=895 hdr=895 md_methods=895 ; |
| 319 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenCxs.SummaryGrid.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1085 hdr=1085 md_methods=1085; b3_cs_hits=7(@11596,11626,11659,11691,11728,11755,11776) ; b3_cs=lines 11596,11626,11659,116… |
| 320 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenONEShare.dll | fail | A:PASS ; B:PASS ; b1_il_MD=626 hdr=626 md_methods=626; b3_cs_hits=1(@5034) ; b3_cs=lines 5034 |
| 321 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.AddInContracts.dll | fail | A:PASS ; B:PASS ; b1_il_MD=391 hdr=391 md_methods=391 ; |
| 322 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.MMForms.SummaryGrid.dll | fail | A:PASS ; B:PASS ; b1_il_MD=200 hdr=200 md_methods=200 ; |
| 323 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.MolecularDrawing.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3032 hdr=3032 md_methods=3032; b3_cs_hits=9(@586,613,650,687,723,2483,11042,24435) ; b3_cs=lines 586,613,650,687,723,2483,1… |
| 324 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.SpreadsheetCalculator.dll | fail | A:PASS ; B:PASS ; b1_il_MD=27 hdr=27 md_methods=27 ; |
| 325 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.WpfAzeoAnalysisGUI.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1319 hdr=1319 md_methods=1319 ; |
| 326 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Dashboard.Contracts.dll | fail | A:PASS ; B:PASS ; b1_il_MD=56 hdr=56 md_methods=None ; |
| 327 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.EconomicsAnalysis.Overlays.dll | fail | A:PASS ; B:PASS ; b1_il_MD=53 hdr=53 md_methods=53 ; |
| 328 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Engineering.CommonShellExtensions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=229 hdr=229 md_methods=229; b3_cs_hits=10(@1395,1400,1405,1410,1422,1427,1432,1444) ; b3_cs=lines 1395,1400,1405,1410,1422,… |
| 329 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Engineering.GridControls.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2602 hdr=2602 md_methods=2602; b3_cs_hits=18(@1029,2556,2696,19985,20015,20037,20062,20078) ; b3_cs=lines 1029,2556,2696,19… |
| 330 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.EquipmentAnalysis.Infrastructure.dll | fail | A:PASS ; B:PASS ; b1_il_MD=847 hdr=847 md_methods=847 ; |
| 331 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.EquipmentAnalysis.UserInterface.dll | fail | A:PASS ; B:PASS ; b1_il_MD=686 hdr=686 md_methods=686; b3_cs_hits=11(@4806,4814,4848,4853,5089,5219,5492,5497) ; b3_cs=lines 4806,4814,4848,4853,5089,… |
| 332 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Exchange.SecureServices.dll | fail | A:PASS ; B:PARTIAL:no_il ; no_tierb_input ; |
| 333 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.ExchangerDesign.UserInterface.dll | fail | A:PASS ; B:PASS ; b1_il_MD=248 hdr=248 md_methods=248 ; |
| 334 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.HtmlHelp.HelpCefViewer.dll | fail | A:PASS ; B:PASS ; b1_il_MD=267 hdr=267 md_methods=267; b3_cs_hits=69(@193,201,219,231,239,247,259,271) ; b3_cs=lines 193,201,219,231,239,247,259,271,2… |
| 335 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.HtmlHelp.HelpInfrastructure.dll | fail | A:PASS ; B:PASS ; b1_il_MD=16 hdr=16 md_methods=None ; |
| 336 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.HtmlHelp.HelpLauncher.dll | fail | A:PASS ; B:PASS ; b1_il_MD=85 hdr=85 md_methods=85 ; |
| 337 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.HtmlHelp.Logging.dll | fail | A:PASS ; B:PASS ; b1_il_MD=13 hdr=13 md_methods=None ; |
| 338 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.HybridModel.Desktop.ClientLibrary.dll | fail | A:PASS ; B:PASS ; b1_il_MD=58 hdr=58 md_methods=58 ; |
| 339 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.InContextGuidance.CfsNet.dll | fail | A:PASS ; B:PASS ; b1_il_MD=193 hdr=193 md_methods=193 ; |
| 340 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.InContextGuidance.ExchangeControls.dll | fail | A:PASS ; B:PASS ; b1_il_MD=17 hdr=17 md_methods=17; b3_cs_hits=2(@54,104) ; b3_cs=lines 54,104 |
| 341 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.InContextGuidance.ExchangeIntegration.dll | fail | A:PASS ; B:PASS ; b1_il_MD=84 hdr=84 md_methods=84; b3_cs_hits=1(@595) ; b3_cs=lines 595 |
| 342 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.InContextGuidance.Localization.dll | fail | A:PASS ; B:PASS ; b1_il_MD=54 hdr=54 md_methods=54 ; |
| 343 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.InContextGuidance.Widgets.dll | fail | A:PASS ; B:PASS ; b1_il_MD=256 hdr=256 md_methods=256; b3_cs_hits=12(@1455,1486,1502,1519,1535,1555,1567,1585) ; b3_cs=lines 1455,1486,1502,1519,1535,… |
| 344 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Utilities.ObjectCopy.dll | fail | A:PASS ; B:PASS ; b1_il_MD=317 hdr=317 md_methods=317 ; |
| 345 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Visualisation.CommonImages.Wpf.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1423 hdr=1423 md_methods=1423 ; |
| 346 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Visualisation.CommonShell.Infrastructure.Wpf.dll | fail | A:PASS ; B:PASS ; b1_il_MD=857 hdr=857 md_methods=857 ; |
| 347 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Visualisation.Controls.Plot.Wpf.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2191 hdr=2191 md_methods=2191 ; |
| 348 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Visualisation.Controls.Support.Wpf.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1820 hdr=1820 md_methods=1820; b3_cs_hits=8(@2089,2440,4224,11239,11263,11275,11287,11299) ; b3_cs=lines 2089,2440,4224,112… |
| 349 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.WpfControls.Engineering.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1426 hdr=1426 md_methods=1426; b3_cs_hits=22(@2339,2362,2388,2408,2430,2529,2603,2656) ; b3_cs=lines 2339,2362,2388,2408,24… |
| 350 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Aspentech.EnergyAnalysis.ClassLibrary.dll | fail | A:PASS ; B:PASS ; b1_il_MD=851 hdr=851 md_methods=851 ; |
| 351 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Aspentech.EnergyAnalysis.Integration.dll | fail | A:PASS ; B:PASS ; b1_il_MD=758 hdr=758 md_methods=758 ; |
| 352 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Aspentech.EnergyAnalysis.UserInterface.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3227 hdr=3227 md_methods=3227; b3_cs_hits=46(@991,4327,7609,14172,14197,14221,14255,14275) ; b3_cs=lines 991,4327,7609,1417… |
| 353 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Aspentech.ExchangerDesign.Infrastructure.dll | fail | A:PASS ; B:PASS ; b1_il_MD=51 hdr=51 md_methods=None ; |
| 354 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AxAdvancedFileDialogLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=23 hdr=23 md_methods=None ; |
| 355 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AxInterop.MSHierarchicalFlexGridLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1266 hdr=1266 md_methods=1266 ; |
| 356 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AxPFSPlotLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=486 hdr=486 md_methods=486 ; |
| 357 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.BrowserSubprocess.Core.dll | fail | A:PASS ; B:PARTIAL:no_il ; b3_cs_hits=11(@42077,42082,42087,42092,42097,42102,42164,42169) ; b3_cs=lines 42077,42082,42087,42092,42097,42102,42164,421… |
| 358 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.BrowserSubprocess.exe | fail | A:PASS ; B:PASS ; b1_il_MD=2 hdr=2 md_methods=None ; |
| 359 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.Core.Runtime.dll | fail | A:PASS ; B:PARTIAL:no_il ; b3_cs_hits=1(@79647) ; b3_cs=lines 79647 |
| 360 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=7127 hdr=7127 md_methods=7127 ; |
| 361 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.WinForms.dll | fail | A:PASS ; B:PASS ; b1_il_MD=326 hdr=326 md_methods=326 ; |
| 362 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.Wpf.dll | fail | A:PASS ; B:PASS ; b1_il_MD=689 hdr=689 md_methods=689; b3_cs_hits=2(@2356,2719) ; b3_cs=lines 2356,2719 |
| 363 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2287 hdr=2287 md_methods=2287; b3_cs_hits=24(@2719,2724,2729,2734,2739,2744,2749,2782) ; b3_cs=lines 2719,2724,2729,2734,27… |
| 364 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ColumnConverter.dll | fail | A:PASS ; B:PASS ; b1_il_MD=102 hdr=102 md_methods=102 ; |
| 366 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Charts.Designer.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=9337 hdr=9337 md_methods=9337; b3_cs_hits=25(@11085,11090,11095,11100,11184,11189,11194,11199) ; b3_cs=lines 11085,11090,11… |
| 367 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Charts.v23.2.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=8532 hdr=8532 md_methods=8532; b3_cs_hits=6(@35815,35827,35839,35851,42522,60956) ; b3_cs=lines 35815,35827,35839,35851,425… |
| 368 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.CodeParser.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=15284 hdr=15284 md_methods=15284; b3_cs_hits=69(@44776,78609,78614,79937,83590,83798,83803,88479) ; b3_cs=lines 44776,78609… |
| 369 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Data.Desktop.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=7358 hdr=7358 md_methods=7358; b3_cs_hits=14(@5130,5161,5169,5173,5181,5185,5206,5211) ; b3_cs=lines 5130,5161,5169,5173,51… |
| 370 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.DataAccess.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=15996 hdr=15996 md_methods=15996; b3_cs_hits=2(@57346,60615) ; b3_cs=lines 57346,60615 |
| 371 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.DataVisualization.v23.2.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=882 hdr=882 md_methods=882 ; |
| 372 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Drawing.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=7264 hdr=7264 md_methods=7264; b3_cs_hits=42(@9683,9692,16614,17600,17605,25099,25998,26065) ; b3_cs=lines 9683,9692,16614,… |
| 373 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Mvvm.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=15819 hdr=15819 md_methods=15819; b3_cs_hits=3(@16232,16243,35928) ; b3_cs=lines 16232,16243,35928 |
| 374 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Office.v23.2.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=16496 hdr=16496 md_methods=16496; b3_cs_hits=3(@65389,65471,65476) ; b3_cs=lines 65389,65471,65476 |
| 375 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Pdf.v23.2.Drawing.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3818 hdr=3818 md_methods=3818; b3_cs_hits=1(@31471) ; b3_cs=lines 31471 |
| 376 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Snap.v23.2.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=7601 hdr=7601 md_methods=7601; b3_cs_hits=49(@3880,3884,13554,21254,21262,22125,22133,22141) ; b3_cs=lines 3880,3884,13554,… |
| 377 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Sparkline.v23.2.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=553 hdr=553 md_methods=553 ; |
| 378 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.TreeMap.v23.2.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=185 hdr=185 md_methods=185 ; |
| 379 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Charts.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=22486 hdr=22486 md_methods=22486; b3_cs_hits=33(@5730,21334,23153,23160,39422,40201,40805,49351) ; b3_cs=lines 5730,21334,2… |
| 380 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Controls.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=10581 hdr=10581 md_methods=10581; b3_cs_hits=32(@749,753,1472,1676,1681,1686,1691,1907) ; b3_cs=lines 749,753,1472,1676,168… |
| 381 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Docking.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=11499 hdr=11499 md_methods=11499; b3_cs_hits=20(@528,39899,39971,40002,40616,41326,49873,72470) ; b3_cs=lines 528,39899,399… |
| 382 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.DocumentViewer.v23.2.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1720 hdr=1720 md_methods=1720 ; |
| 383 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Grid.v23.2.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=19024 hdr=19024 md_methods=19024; b3_cs_hits=31(@206,210,218,222,9252,16545,22270,30947) ; b3_cs=lines 206,210,218,222,9252… |
| 384 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Grid.v23.2.Extensions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1204 hdr=1204 md_methods=1204; b3_cs_hits=4(@1270,1617,2659,2710) ; b3_cs=lines 1270,1617,2659,2710 |
| 385 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Grid.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=18103 hdr=18103 md_methods=18103; b3_cs_hits=141(@3873,4351,4436,5760,5765,5770,5775,5780) ; b3_cs=lines 3873,4351,4436,576… |
| 386 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Layout.v23.2.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1171 hdr=1171 md_methods=1171 ; |
| 387 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.LayoutControl.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3336 hdr=3336 md_methods=3336; b3_cs_hits=12(@2002,2019,2029,2039,2140,2160,2195,2202) ; b3_cs=lines 2002,2019,2029,2039,21… |
| 388 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.NavBar.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2846 hdr=2846 md_methods=2846; b3_cs_hits=17(@1036,1113,1125,1137,1158,1170,1182,1212) ; b3_cs=lines 1036,1113,1125,1137,11… |
| 389 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Office.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=412 hdr=412 md_methods=412 ; |
| 390 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Printing.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=8099 hdr=8099 md_methods=8099; b3_cs_hits=45(@3752,5008,5792,6557,13583,13593,13603,15376) ; b3_cs=lines 3752,5008,5792,655… |
| 391 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.PropertyGrid.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=4891 hdr=4891 md_methods=4891; b3_cs_hits=6(@9532,15322,15327,16979,23094,23553) ; b3_cs=lines 9532,15322,15327,16979,23094… |
| 392 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Ribbon.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=7709 hdr=7709 md_methods=7709; b3_cs_hits=6(@45694,48549,48565,54028,54061,54094) ; b3_cs=lines 45694,48549,48565,54028,540… |
| 393 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.Spreadsheet.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=10652 hdr=10652 md_methods=10652; b3_cs_hits=7(@2300,2378,23339,50206,50548,70392,71611) ; b3_cs=lines 2300,2378,23339,5020… |
| 394 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpf.TreeMap.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1644 hdr=1644 md_methods=1644; b3_cs_hits=1(@4875) ; b3_cs=lines 4875 |
| 395 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Xpo.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=12939 hdr=12939 md_methods=12939; b3_cs_hits=22(@4360,29914,47407,58902,58951,58973,65842,70469) ; b3_cs=lines 4360,29914,4… |
| 396 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.XtraCharts.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=28075 hdr=28075 md_methods=28075; b3_cs_hits=53(@7896,24249,24253,24345,24349,27880,73872,76407) ; b3_cs=lines 7896,24249,2… |
| 397 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.XtraTreeMap.v23.2.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2489 hdr=2489 md_methods=2489; b3_cs_hits=6(@252,13069,13074,13079,13084,15303) ; b3_cs=lines 252,13069,13074,13079,13084,1… |
| 398 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/EntityFramework.SqlServer.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1873 hdr=1873 md_methods=1873; b3_cs_hits=4(@7225,7878,7927,15524) ; b3_cs=lines 7225,7878,7927,15524 |
| 399 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/FimmtopForManaged.dll | fail | A:PASS ; B:PASS ; b1_il_MD=487 hdr=487 md_methods=487 ; |
| 401 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/HeatExchangeConverter.dll | fail | A:PASS ; B:PASS ; b1_il_MD=99 hdr=99 md_methods=99 ; |
| 402 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/IconCtrl.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1144 hdr=1144 md_methods=1144; b3_cs_hits=3(@12682,16712,16761) ; b3_cs=lines 12682,16712,16761 |
| 403 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Documents.Reports.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=8483 hdr=8483 md_methods=8483; b3_cs_hits=3(@93234,93254,93259) ; b3_cs=lines 93234,93254,93259 |
| 404 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Shared.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1526 hdr=1526 md_methods=1526 ; |
| 405 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Win.Misc.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=7218 hdr=7218 md_methods=7218; b3_cs_hits=1(@72590) ; b3_cs=lines 72590 |
| 406 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Win.UltraWinDock.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3290 hdr=3290 md_methods=3290 ; |
| 407 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Win.UltraWinEditors.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3475 hdr=3475 md_methods=3475 ; |
| 408 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Win.UltraWinGrid.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=14524 hdr=14524 md_methods=14524; b3_cs_hits=9(@6183,61016,61021,61026,61031,94725,94733,94798) ; b3_cs=lines 6183,61016,61… |
| 409 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Win.UltraWinStatusBar.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=958 hdr=958 md_methods=958 ; |
| 410 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Win.UltraWinTabControl.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1522 hdr=1522 md_methods=1522 ; |
| 411 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Win.UltraWinTabbedMdi.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1657 hdr=1657 md_methods=1657 ; |
| 412 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Win.UltraWinToolbars.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=15548 hdr=15548 md_methods=15548; b3_cs_hits=2(@88024,88029) ; b3_cs=lines 88024,88029 |
| 413 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Infragistics4.Win.UltraWinTree.v21.1.dll | fail | A:PASS ; B:PASS ; b1_il_MD=4760 hdr=4760 md_methods=4760 ; |
| 414 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Controls.Charts.XamDataChart.dll | fail | A:PASS ; B:PASS ; b1_il_MD=17962 hdr=17962 md_methods=17962; b3_cs_hits=66(@33521,33543,33578,47378,47463,52865,55186,55323) ; b3_cs=lines 33521,33543… |
| 415 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Controls.Editors.XamColorPicker.dll | fail | A:PASS ; B:PASS ; b1_il_MD=629 hdr=629 md_methods=629 ; |
| 416 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Controls.Editors.XamComboEditor.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1093 hdr=1093 md_methods=1093 ; |
| 417 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Controls.Editors.XamRichTextEditor.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1573 hdr=1573 md_methods=1573 ; |
| 418 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Controls.Editors.XamSlider.dll | fail | A:PASS ; B:PASS ; b1_il_MD=556 hdr=556 md_methods=556 ; |
| 419 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Controls.Menus.XamMenu.dll | fail | A:PASS ; B:PASS ; b1_il_MD=512 hdr=512 md_methods=512 ; |
| 420 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.DataManager.dll | fail | A:PASS ; B:PASS ; b1_il_MD=817 hdr=817 md_methods=817; b3_cs_hits=2(@3293,6547) ; b3_cs=lines 3293,6547 |
| 421 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.DataVisualization.dll | fail | A:PASS ; B:PASS ; b1_il_MD=22257 hdr=22257 md_methods=22257; b3_cs_hits=40(@5684,5689,5694,5709,5714,9722,9727,9732) ; b3_cs=lines 5684,5689,5694,5709… |
| 422 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.DockManager.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2258 hdr=2258 md_methods=2258 ; |
| 423 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Documents.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=7078 hdr=7078 md_methods=7078; b3_cs_hits=3(@34547,49176,78202) ; b3_cs=lines 34547,49176,78202 |
| 424 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Documents.RichTextDocument.dll | fail | A:PASS ; B:PASS ; b1_il_MD=7015 hdr=7015 md_methods=7015; b3_cs_hits=2(@5693,13076) ; b3_cs=lines 5693,13076 |
| 425 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Editors.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3222 hdr=3222 md_methods=3222 ; |
| 426 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.OutlookBar.dll | fail | A:PASS ; B:PASS ; b1_il_MD=737 hdr=737 md_methods=737 ; |
| 427 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Persistence.dll | fail | A:PASS ; B:PASS ; b1_il_MD=232 hdr=232 md_methods=232 ; |
| 428 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Reporting.dll | fail | A:PASS ; B:PASS ; b1_il_MD=281 hdr=281 md_methods=281 ; |
| 429 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Ribbon.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3744 hdr=3744 md_methods=3744 ; |
| 430 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.Undo.dll | fail | A:PASS ; B:PASS ; b1_il_MD=353 hdr=353 md_methods=353 ; |
| 431 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/InfragisticsWPF.dll | fail | A:PASS ; B:PASS ; b1_il_MD=8881 hdr=8881 md_methods=8881; b3_cs_hits=1(@3175) ; b3_cs=lines 3175 |
| 432 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Interop.APServer.dll | fail | A:PASS ; B:PASS ; b1_il_MD=670 hdr=670 md_methods=670 ; |
| 433 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Interop.ASCclasslib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=968 hdr=968 md_methods=968 ; |
| 434 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Interop.ApvCom.dll | fail | A:PASS ; B:PASS ; b1_il_MD=299 hdr=299 md_methods=299 ; |
| 435 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Interop.Happ.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1425 hdr=1425 md_methods=1425 ; |
| 436 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Interop.MMLocal.dll | fail | A:PASS ; B:PASS ; b1_il_MD=118 hdr=118 md_methods=118 ; |
| 437 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Interop.MSHierarchicalFlexGridLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1488 hdr=1488 md_methods=1488 ; |
| 441 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Microsoft.Practices.Composite.Presentation.dll | fail | A:PASS ; B:PASS ; b1_il_MD=368 hdr=368 md_methods=368 ; |
| 442 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Microsoft.Practices.Composite.UnityExtensions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=54 hdr=54 md_methods=54 ; |
| 443 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Microsoft.Practices.Composite.dll | fail | A:PASS ; B:PASS ; b1_il_MD=489 hdr=489 md_methods=489 ; |
| 444 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Microsoft.ServiceBus.dll | fail | A:PASS ; B:PASS ; b1_il_MD=22650 hdr=22650 md_methods=22650; b3_cs_hits=69(@2898,4028,4046,4738,6368,6373,8029,11520) ; b3_cs=lines 2898,4028,4046,473… |
| 445 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Modules/AspenTech.AspenPlus.ColumnAnalysisIntegration.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2238 hdr=2238 md_methods=2238; b3_cs_hits=1(@36596) ; b3_cs=lines 36596 |
| 446 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Modules/AspenTech.AspenPlus.MolecularEditor.dll | fail | A:PASS ; B:PASS ; b1_il_MD=21 hdr=21 md_methods=None ; |
| 447 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Modules/AspenTech.AspenPlus.Tools.VariableExplorer.dll | fail | A:PASS ; B:PASS ; b1_il_MD=79 hdr=79 md_methods=79; b3_cs_hits=1(@1090) ; b3_cs=lines 1090 |
| 448 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Modules/AspenTech.ColumnAnalysis.UserInterfaces.dll | fail | A:PASS ; B:PASS ; b1_il_MD=6234 hdr=6234 md_methods=6234; b3_cs_hits=15(@188,11313,25055,25069,25089,25102,25115,29170) ; b3_cs=lines 188,11313,25055,… |
| 449 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Modules/AspenTech.ExchangerDesign.UserInterface.dll | fail | A:PASS ; B:PASS ; b1_il_MD=248 hdr=248 md_methods=248 ; |
| 450 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Modules/AttpsrMan.exe | fail | A:PASS ; B:PASS ; b1_il_MD=93 hdr=93 md_methods=93 ; |
| 451 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Newtonsoft.Json.dll | fail | A:PASS ; B:PASS ; b1_il_MD=4213 hdr=4213 md_methods=4213; b3_cs_hits=2(@31528,33142) ; b3_cs=lines 31528,33142 |
| 452 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/PFSPlotLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=816 hdr=816 md_methods=816 ; |
| 454 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/SmartIconContainer.dll | fail | A:PASS ; B:PASS ; b1_il_MD=157 hdr=157 md_methods=157 ; |
| 456 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/System.Data.SQLite.EF6.Migrations.dll | fail | A:PASS ; B:PASS ; b1_il_MD=151 hdr=151 md_methods=151; b3_cs_hits=1(@678) ; b3_cs=lines 678 |
| 457 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/System.Data.SQLite.EF6.dll | fail | A:PASS ; B:PASS ; b1_il_MD=470 hdr=470 md_methods=470 ; |
| 458 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/System.Data.SQLite.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2541 hdr=2541 md_methods=2541; b3_cs_hits=6(@1564,7303,7810,11904,18465,27980) ; b3_cs=lines 1564,7303,7810,11904,18465,279… |
| 459 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/TDEdll.dll | fail | A:PASS ; B:PARTIAL:no_il ; no_tierb_input ; |
| 460 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.ACMModel.dll | fail | A:PASS ; B:PASS ; b1_il_MD=179 hdr=179 md_methods=179 ; |
| 461 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.BatchOp.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2361 hdr=2361 md_methods=2361; b3_cs_hits=14(@10379,13757,14577,43847,44039,44055,44295,44315) ; b3_cs=lines 10379,13757,14… |
| 462 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.BatchSep.dll | fail | A:PASS ; B:PASS ; b1_il_MD=4167 hdr=4167 md_methods=4167; b3_cs_hits=34(@9694,66105,81589,85054,86341,86746,86766,86786) ; b3_cs=lines 9694,66105,8158… |
| 463 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.ConSep.dll | fail | A:PASS ; B:PASS ; b1_il_MD=353 hdr=353 md_methods=353 ; |
| 464 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Distl.dll | fail | A:PASS ; B:PASS ; b1_il_MD=85 hdr=85 md_methods=85 ; |
| 465 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Dstwu.dll | fail | A:PASS ; B:PASS ; b1_il_MD=105 hdr=105 md_methods=105 ; |
| 466 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Extract.dll | fail | A:PASS ; B:PASS ; b1_il_MD=619 hdr=619 md_methods=619 ; |
| 467 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Manipulators.dll | fail | A:PASS ; B:PASS ; b1_il_MD=416 hdr=416 md_methods=416 ; |
| 468 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Multifrac.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2589 hdr=2589 md_methods=2589 ; |
| 469 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Petrofrac.dll | fail | A:PASS ; B:PASS ; b1_il_MD=4456 hdr=4456 md_methods=4456; b3_cs_hits=1(@19431) ; b3_cs=lines 19431 |
| 470 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Pipe_Valve.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1533 hdr=1533 md_methods=1533; b3_cs_hits=2(@13333,21798) ; b3_cs=lines 13333,21798 |
| 471 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Pump_Compr.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1841 hdr=1841 md_methods=1841 ; |
| 472 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Radfrac.dll | fail | A:PASS ; B:PASS ; b1_il_MD=5258 hdr=5258 md_methods=5258; b3_cs_hits=2(@34600,49709) ; b3_cs=lines 34600,49709 |
| 473 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Reactor.dll | fail | A:PASS ; B:PASS ; b1_il_MD=5427 hdr=5427 md_methods=5427; b3_cs_hits=18(@19527,28550,29977,31679,53772,54701,68438,99551) ; b3_cs=lines 19527,28550,29… |
| 474 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Scfrac.dll | fail | A:PASS ; B:PASS ; b1_il_MD=197 hdr=197 md_methods=197 ; |
| 475 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Solids.dll | fail | A:PASS ; B:PASS ; b1_il_MD=4374 hdr=4374 md_methods=4374; b3_cs_hits=1(@78146) ; b3_cs=lines 78146 |
| 476 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.User.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1298 hdr=1298 md_methods=1298 ; |
| 477 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Controllers.dll | fail | A:PASS ; B:PASS ; b1_il_MD=428 hdr=428 md_methods=428 ; |
| 478 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Convergence.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1950 hdr=1950 md_methods=1950 ; |
| 479 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.DynOptions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=24 hdr=24 md_methods=24 ; |
| 480 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.EO_Configuration.dll | fail | A:PASS ; B:PASS ; b1_il_MD=871 hdr=871 md_methods=871; b3_cs_hits=1(@6669) ; b3_cs=lines 6669 |
| 481 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.FlowsheetingOptions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2781 hdr=2781 md_methods=2781; b3_cs_hits=4(@33903,42011,42068,50473) ; b3_cs=lines 33903,42011,42068,50473 |
| 482 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Generic.dll | fail | A:PASS ; B:PASS ; b1_il_MD=966 hdr=966 md_methods=966; b3_cs_hits=4(@3098,4924,13323,16599) ; b3_cs=lines 3098,4924,13323,16599 |
| 483 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.HybridModels.dll | fail | A:PASS ; B:PASS ; b1_il_MD=372 hdr=372 md_methods=372 ; |
| 484 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.ModelAnalysis.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1442 hdr=1442 md_methods=1442; b3_cs_hits=5(@840,1156,6502,11290,20242) ; b3_cs=lines 840,1156,6502,11290,20242 |
| 485 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.OperatingSteps.dll | fail | A:PASS ; B:PASS ; b1_il_MD=477 hdr=477 md_methods=477 ; |
| 486 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.PlotForms.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1244 hdr=1244 md_methods=1244 ; |
| 487 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Utility.dll | fail | A:PASS ; B:PASS ; b1_il_MD=280 hdr=280 md_methods=280 ; |
| 488 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WPFHierarchyComboBox.dll | fail | A:PASS ; B:PASS ; b1_il_MD=48 hdr=48 md_methods=48; b3_cs_hits=1(@445) ; b3_cs=lines 445 |
| 489 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfAdhocPlot.dll | fail | A:PASS ; B:PASS ; b1_il_MD=52 hdr=52 md_methods=52 ; |
| 490 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfAdsAdhocPlot.dll | fail | A:PASS ; B:PASS ; b1_il_MD=38 hdr=38 md_methods=38 ; |
| 491 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLAssay.dll | fail | A:PASS ; B:PASS ; b1_il_MD=250 hdr=250 md_methods=250 ; |
| 492 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLBatchOp.dll | fail | A:PASS ; B:PASS ; b1_il_MD=599 hdr=599 md_methods=599 ; |
| 493 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLBatchSep.dll | fail | A:PASS ; B:PASS ; b1_il_MD=841 hdr=841 md_methods=841 ; |
| 494 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLBlend.dll | fail | A:PASS ; B:PASS ; b1_il_MD=153 hdr=153 md_methods=153 ; |
| 495 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLCfuge.dll | fail | A:PASS ; B:PASS ; b1_il_MD=68 hdr=68 md_methods=68 ; |
| 496 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLClassifier.dll | fail | A:PASS ; B:PASS ; b1_il_MD=148 hdr=148 md_methods=148 ; |
| 497 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLCompr.dll | fail | A:PASS ; B:PASS ; b1_il_MD=105 hdr=105 md_methods=105 ; |
| 498 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLConSep.dll | fail | A:PASS ; B:PASS ; b1_il_MD=139 hdr=139 md_methods=139 ; |
| 499 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLControllers.dll | fail | A:PASS ; B:PASS ; b1_il_MD=51 hdr=51 md_methods=51 ; |
| 500 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLControls.dll | fail | A:PASS ; B:PASS ; b1_il_MD=156 hdr=156 md_methods=156 ; |
| 501 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLConvergence.dll | fail | A:PASS ; B:PASS ; b1_il_MD=193 hdr=193 md_methods=193; b3_cs_hits=2(@201,205) ; b3_cs=lines 201,205 |
| 502 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLCyclone.dll | fail | A:PASS ; B:PASS ; b1_il_MD=93 hdr=93 md_methods=93 ; |
| 503 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLData.dll | fail | A:PASS ; B:PASS ; b1_il_MD=211 hdr=211 md_methods=211 ; |
| 504 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLDataNIST.dll | fail | A:PASS ; B:PASS ; b1_il_MD=195 hdr=195 md_methods=195 ; |
| 505 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLDiscurves.dll | fail | A:PASS ; B:PASS ; b1_il_MD=477 hdr=477 md_methods=477 ; |
| 506 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLDryer.dll | fail | A:PASS ; B:PASS ; b1_il_MD=457 hdr=457 md_methods=457 ; |
| 507 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLDryerBatch.dll | fail | A:PASS ; B:PASS ; b1_il_MD=358 hdr=358 md_methods=358 ; |
| 508 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLFilter.dll | fail | A:PASS ; B:PASS ; b1_il_MD=91 hdr=91 md_methods=91 ; |
| 509 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLFluidBed.dll | fail | A:PASS ; B:PASS ; b1_il_MD=346 hdr=346 md_methods=346 ; |
| 510 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLHeatx.dll | fail | A:PASS ; B:PASS ; b1_il_MD=80 hdr=80 md_methods=80 ; |
| 511 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLHyCyc.dll | fail | A:PASS ; B:PASS ; b1_il_MD=148 hdr=148 md_methods=148 ; |
| 512 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLMCompr.dll | fail | A:PASS ; B:PASS ; b1_il_MD=103 hdr=103 md_methods=103 ; |
| 513 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLMultifrac.dll | fail | A:PASS ; B:PASS ; b1_il_MD=554 hdr=554 md_methods=554; b3_cs_hits=3(@1116,3978,4858) ; b3_cs=lines 1116,3978,4858 |
| 514 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLPetroFrac.dll | fail | A:PASS ; B:PASS ; b1_il_MD=573 hdr=573 md_methods=573 ; |
| 515 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLPipe.dll | fail | A:PASS ; B:PASS ; b1_il_MD=548 hdr=548 md_methods=548 ; |
| 516 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLPipeline.dll | fail | A:PASS ; B:PASS ; b1_il_MD=470 hdr=470 md_methods=470 ; |
| 517 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLRBatch.dll | fail | A:PASS ; B:PASS ; b1_il_MD=493 hdr=493 md_methods=493 ; |
| 518 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLRCSTR.dll | fail | A:PASS ; B:PASS ; b1_il_MD=106 hdr=106 md_methods=106 ; |
| 519 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLRPlug.dll | fail | A:PASS ; B:PASS ; b1_il_MD=458 hdr=458 md_methods=458 ; |
| 520 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLRadFrac.dll | fail | A:PASS ; B:PASS ; b1_il_MD=564 hdr=564 md_methods=564 ; |
| 521 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLRegression.dll | fail | A:PASS ; B:PASS ; b1_il_MD=666 hdr=666 md_methods=666 ; |
| 522 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLResults.dll | fail | A:PASS ; B:PASS ; b1_il_MD=257 hdr=257 md_methods=257 ; |
| 523 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLScreen.dll | fail | A:PASS ; B:PASS ; b1_il_MD=148 hdr=148 md_methods=148 ; |
| 524 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLSensitivity.dll | fail | A:PASS ; B:PASS ; b1_il_MD=94 hdr=94 md_methods=94 ; |
| 525 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLVscrub.dll | fail | A:PASS ; B:PASS ; b1_il_MD=118 hdr=118 md_methods=118 ; |
| 526 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizardsHelper.dll | fail | A:PASS ; B:PASS ; b1_il_MD=91 hdr=91 md_methods=91 ; |
| 544 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AMOS.dll | fail | A:PASS ; B:PASS ; b1_il_MD=122 hdr=122 md_methods=122 ; |
| 545 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AMOSLinear.dll | fail | A:PASS ; B:PASS ; b1_il_MD=128 hdr=128 md_methods=128 ; |
| 546 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AMOSNLP.dll | fail | A:PASS ; B:PASS ; b1_il_MD=208 hdr=208 md_methods=208 ; |
| 547 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AMOSNonLinear.dll | fail | A:PASS ; B:PASS ; b1_il_MD=180 hdr=180 md_methods=180 ; |
| 548 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenHydraulicsResources.dll | fail | A:PASS ; B:PASS ; b1_il_MD=639 hdr=639 md_methods=639 ; |
| 550 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenTech.Components.Utilities.dll | fail | A:PASS ; B:PASS ; b1_il_MD=20 hdr=20 md_methods=None ; |
| 551 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenTech.Hydraulics.Framework.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1154 hdr=1154 md_methods=1154; b3_cs_hits=11(@3191,4320,8277,8371,8441,8601,8631,8698) ; b3_cs=lines 3191,4320,8277,8371,84… |
| 552 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenTech.Interop.HyprotechEstimator.dll | fail | A:PASS ; B:PASS ; b1_il_MD=15 hdr=15 md_methods=None ; |
| 553 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenTech.Interop.HyprotechXML.dll | fail | A:PASS ; B:PASS ; b1_il_MD=71 hdr=71 md_methods=71 ; |
| 554 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenTech.Interop.thcontainers.dll | fail | A:PASS ; B:PASS ; b1_il_MD=866 hdr=866 md_methods=866 ; |
| 555 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenTech.Interop.thflashmanager.dll | fail | A:PASS ; B:PASS ; b1_il_MD=32 hdr=32 md_methods=None ; |
| 556 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenTech.Interop.thipmanager.dll | fail | A:PASS ; B:PASS ; b1_il_MD=15 hdr=15 md_methods=None ; |
| 557 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenTech.Interop.thpropmanager.dll | fail | A:PASS ; B:PASS ; b1_il_MD=405 hdr=405 md_methods=405 ; |
| 558 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenTech.Interop.thutility.dll | fail | A:PASS ; B:PASS ; b1_il_MD=161 hdr=161 md_methods=161 ; |
| 559 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/CompositionSolver.dll | fail | A:PASS ; B:PASS ; b1_il_MD=532 hdr=532 md_methods=532; b3_cs_hits=6(@2660,2668,2674,2679,2684,2689) ; b3_cs=lines 2660,2668,2674,2679,2684,2689 |
| 560 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/CraneMethodLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=20 hdr=20 md_methods=20 ; |
| 561 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/Data.dll | fail | A:PASS ; B:PASS ; b1_il_MD=237 hdr=237 md_methods=237; b3_cs_hits=1(@416) ; b3_cs=lines 416 |
| 562 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/DynamicSolver.dll | fail | A:PASS ; B:PASS ; b1_il_MD=557 hdr=557 md_methods=557; b3_cs_hits=6(@2649,2657,2663,2668,2673,2678) ; b3_cs=lines 2649,2657,2663,2668,2673,2678 |
| 563 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/DynamicSolver3p.dll | fail | A:PASS ; B:PASS ; b1_il_MD=530 hdr=530 md_methods=530; b3_cs_hits=6(@2628,2636,2642,2647,2652,2657) ; b3_cs=lines 2628,2636,2642,2647,2652,2657 |
| 564 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/FluidFlowhandler.dll | fail | A:PASS ; B:PASS ; b1_il_MD=865 hdr=865 md_methods=865 ; |
| 565 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/HTFSMethodLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=158 hdr=158 md_methods=158 ; |
| 566 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/HydraulicMethods.dll | fail | A:PASS ; B:PASS ; b1_il_MD=50 hdr=50 md_methods=50 ; |
| 567 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/InterfacesForSteadyStateUnitOp.dll | fail | A:PASS ; B:PASS ; b1_il_MD=36 hdr=36 md_methods=36 ; |
| 570 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/NetworkPlugins.dll | fail | A:PASS ; B:PASS ; b1_il_MD=28 hdr=28 md_methods=28 ; |
| 571 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/PipeFittingServer.dll | fail | A:PASS ; B:PASS ; b1_il_MD=722 hdr=722 md_methods=722 ; |
| 572 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/PipeFlowMethodLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=22 hdr=22 md_methods=22 ; |
| 573 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/PluginsSupport.dll | fail | A:PASS ; B:PASS ; b1_il_MD=48 hdr=48 md_methods=48 ; |
| 574 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/PropertyUtilities.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1436 hdr=1436 md_methods=1436; b3_cs_hits=8(@3507,6763,6768,6773,6778,10585,10718,10723) ; b3_cs=lines 3507,6763,6768,6773,… |
| 575 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/SSNetworkSolver.dll | fail | A:PASS ; B:PASS ; b1_il_MD=470 hdr=470 md_methods=470 ; |
| 576 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/SSUnitOp.dll | fail | A:PASS ; B:PASS ; b1_il_MD=318 hdr=318 md_methods=318; b3_cs_hits=7(@779,795,948,5315,5320,7652,8090) ; b3_cs=lines 779,795,948,5315,5320,7652,8090 |
| 578 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/TankModel.dll | fail | A:PASS ; B:PASS ; b1_il_MD=191 hdr=191 md_methods=191 ; |
| 579 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/TeeJunctionMethodLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=35 hdr=35 md_methods=35 ; |
| 580 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Open Solvers V15.0/Bin/AMOS.dll | fail | A:PASS ; B:PASS ; b1_il_MD=107 hdr=107 md_methods=107 ; |
| 581 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Open Solvers V15.0/Bin/AMOSLinear.dll | fail | A:PASS ; B:PASS ; b1_il_MD=128 hdr=128 md_methods=128 ; |
| 582 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Open Solvers V15.0/Bin/AMOSNLP.dll | fail | A:PASS ; B:PASS ; b1_il_MD=208 hdr=208 md_methods=208 ; |
| 583 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Open Solvers V15.0/Bin/AMOSNonLinear.dll | fail | A:PASS ; B:PASS ; b1_il_MD=180 hdr=180 md_methods=180 ; |
| 765 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/ApDotNetAsmReg.exe | fail | A:PASS ; B:PASS ; b1_il_MD=5 hdr=5 md_methods=None ; |
| 767 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/AspenTech.AspenPlus.CustomModels.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2100 hdr=2100 md_methods=2100; b3_cs_hits=5(@1968,1988,2009,14551,18607) ; b3_cs=lines 1968,1988,2009,14551,18607 |
| 768 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/AspenTech.AspenPlus.ExcelVarDefWizard64.dll | fail | A:PASS ; B:PASS ; b1_il_MD=231 hdr=231 md_methods=231 ; |
| 769 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/AspenTech.AspenPlus.HybridModelUtilities.dll | fail | A:PASS ; B:PASS ; b1_il_MD=200 hdr=200 md_methods=200 ; |
| 771 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/AxEditorCtrlLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=79 hdr=79 md_methods=79 ; |
| 772 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/AxIconEditorAxLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=87 hdr=87 md_methods=87 ; |
| 774 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/ConvBspfToBkp.exe | fail | A:PASS ; B:PASS ; b1_il_MD=97 hdr=97 md_methods=97 ; |
| 776 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/EditorCtrlLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=156 hdr=156 md_methods=156 ; |
| 779 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/HMManagedXLP.dll | fail | A:PASS ; B:PASS ; b1_il_MD=665 hdr=665 md_methods=665 ; |
| 780 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/IconEditorAxLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=138 hdr=138 md_methods=138 ; |
| 782 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/Modules/AspenTech.ActivationDashboard.EconomicAnalysis.dll | fail | A:PASS ; B:PASS ; b1_il_MD=264 hdr=264 md_methods=264; b3_cs_hits=2(@1855,2467) ; b3_cs=lines 1855,2467 |
| 783 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/Modules/AspenTech.ActivationDashboard.EdrActivation.dll | fail | A:PASS ; B:PASS ; b1_il_MD=947 hdr=947 md_methods=947 ; |
| 784 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/Modules/AspenTech.ActivationDashboard.GHGEmission.dll | fail | A:PASS ; B:PASS ; b1_il_MD=56 hdr=56 md_methods=56 ; |
| 786 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/OomfModelEquationsSolver.dll | fail | A:PASS ; B:PASS ; b1_il_MD=689 hdr=689 md_methods=689 ; |
| 787 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/PfsDotNetActiveXCtrl.dll | fail | A:PASS ; B:PASS ; b1_il_MD=67 hdr=67 md_methods=67 ; |
| 790 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/System.Text.Encoding.CodePages.dll | fail | A:PASS ; B:PASS ; b1_il_MD=494 hdr=494 md_methods=494 ; |
| 802 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/x86/AspenTech.AspenPlus.ExcelVarDefWizard.dll | fail | A:PASS ; B:PASS ; b1_il_MD=231 hdr=231 md_methods=231 ; |
| 804 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.DataMigration.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1515 hdr=1515 md_methods=1515 ; |
| 805 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.Engine.dll | fail | A:PASS ; B:PASS ; b1_il_MD=904 hdr=904 md_methods=904 ; |
| 806 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.Infrastructure.dll | fail | A:PASS ; B:PASS ; b1_il_MD=847 hdr=847 md_methods=847 ; |
| 807 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.Models.dll | fail | A:PASS ; B:PASS ; b1_il_MD=4878 hdr=4878 md_methods=4878; b3_cs_hits=25(@5279,5287,5297,5305,5329,5334,5368,5373) ; b3_cs=lines 5279,5287,5297,5305,53… |
| 808 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.PSVControlLibrary.dll | fail | A:PASS ; B:PASS ; b1_il_MD=4561 hdr=4561 md_methods=4561; b3_cs_hits=11(@3469,9274,10227,14594,14598,16167,16178,38520) ; b3_cs=lines 3469,9274,10227,… |
| 809 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.PSVControlResources.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2620 hdr=2620 md_methods=2620; b3_cs_hits=29(@7838,7854,7870,7890,7910,7933,7961,8026) ; b3_cs=lines 7838,7854,7870,7890,79… |
| 810 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.PSVModelLibrary.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2924 hdr=2924 md_methods=2924; b3_cs_hits=2(@7522,7526) ; b3_cs=lines 7522,7526 |
| 811 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.PSVPlus.dll | fail | A:PASS ; B:PASS ; b1_il_MD=147 hdr=147 md_methods=147 ; |
| 812 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.Properties.AspenHysys.dll | fail | A:PASS ; B:PASS ; b1_il_MD=151 hdr=151 md_methods=151; b3_cs_hits=2(@166,171) ; b3_cs=lines 166,171 |
| 813 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.Properties.AspenPlus.dll | fail | A:PASS ; B:PASS ; b1_il_MD=124 hdr=124 md_methods=124; b3_cs_hits=3(@481,486,830) ; b3_cs=lines 481,486,830 |
| 814 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.Resources.dll | fail | A:PASS ; B:PASS ; b1_il_MD=730 hdr=730 md_methods=730; b3_cs_hits=1(@609) ; b3_cs=lines 609 |
| 815 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/AspenTech.EquipmentAnalysis.UserInterface.dll | fail | A:PASS ; B:PASS ; b1_il_MD=686 hdr=686 md_methods=686; b3_cs_hits=11(@4864,4872,4906,4911,5147,5277,5550,5555) ; b3_cs=lines 4864,4872,4906,4911,5147,… |
| 816 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Safety Analysis V15.0/PSVSizingEngine.dll | fail | A:PASS ; B:PASS ; b1_il_MD=535 hdr=535 md_methods=535 ; |
| 817 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/AspenHelper.dll | fail | A:PASS ; B:PASS ; b1_il_MD=17 hdr=17 md_methods=None ; |
| 818 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/AspenTech.HtmlHelp.StrongNameInvoke.dll | fail | A:PASS ; B:PASS ; b1_il_MD=19 hdr=19 md_methods=None ; |
| 819 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/AspenTech.Visualisation.Controls.Support.Wpf.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1825 hdr=1825 md_methods=1825; b3_cs_hits=8(@2123,2474,4258,11273,11297,11309,11321,11333) ; b3_cs=lines 2123,2474,4258,112… |
| 820 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/Aspentech.HYSYS.Interop.dll | fail | A:PASS ; B:PASS ; b1_il_MD=45483 hdr=45483 md_methods=45483 ; |
| 821 | 5 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/Common.dll | fail | A:PASS ; B:PASS ; b1_il_MD=786 hdr=786 md_methods=786 ; |
| 822 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/HYSYSHelper.dll | fail | A:PASS ; B:PASS ; b1_il_MD=531 hdr=531 md_methods=531; b3_cs_hits=1(@7951) ; b3_cs=lines 7951 |
| 823 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/HYSYSObjects.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1343 hdr=1343 md_methods=1343 ; |
| 824 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/P2ConvertCore.dll | fail | A:PASS ; B:PASS ; b1_il_MD=21 hdr=21 md_methods=21 ; |
| 825 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/P2ConvertGUI.dll | fail | A:PASS ; B:PASS ; b1_il_MD=79 hdr=79 md_methods=79 ; |
| 826 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/P2Converter.exe | fail | A:PASS ; B:PASS ; b1_il_MD=15 hdr=15 md_methods=15 ; |
| 827 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/P2DataMapResult.dll | fail | A:PASS ; B:PASS ; b1_il_MD=152 hdr=152 md_methods=152 ; |
| 828 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/P2InputParser.dll | fail | A:PASS ; B:PASS ; b1_il_MD=23 hdr=23 md_methods=23 ; |
| 829 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Converter V15.0/P2Objects.dll | fail | A:PASS ; B:PASS ; b1_il_MD=3388 hdr=3388 md_methods=3388; b3_cs_hits=2(@430,446) ; b3_cs=lines 430,446 |
| 831 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/xeq/ASCGridLib410.dll | fail | A:PASS ; B:PASS ; b1_il_MD=215 hdr=215 md_methods=215 ; |
| 832 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/OOMF V15.0/xeq/AxASCGridLib410.dll | fail | A:PASS ; B:PASS ; b1_il_MD=105 hdr=105 md_methods=105 ; |
| 856 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Shared Engineering Models V15.0/AspenEngine.dll | fail | A:PASS ; B:PASS ; b1_il_MD=151 hdr=151 md_methods=151 ; |
| 860 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Shared Engineering Models V15.0/AspenTech.APED.Core.dll | fail | A:PASS ; B:PASS ; b1_il_MD=2521 hdr=2521 md_methods=2521; b3_cs_hits=30(@1471,1491,1499,1511,1516,1521,1526,1531) ; b3_cs=lines 1471,1491,1499,1511,15… |
| 861 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Shared Engineering Models V15.0/AspenTech.NGP.CalculationService.dll | fail | A:PASS ; B:PASS ; b1_il_MD=619 hdr=619 md_methods=619; b3_cs_hits=2(@435,2051) ; b3_cs=lines 435,2051 |
| 863 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Shared Engineering Models V15.0/Microsoft.Extensions.Hosting.Abstractions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=121 hdr=121 md_methods=121 ; |
| 888 | 0 | Plus | 逆向成果/待静态验收/Plus/[TARGETDIR]/AspenTech.Exchange.AddIn.dll | fail | A:PASS ; B:PASS ; b1_il_MD=155 hdr=155 md_methods=155 ; |
| 889 | 1 | Plus | 逆向成果/待静态验收/Plus/[TARGETDIR]/Aspentech.Exchange.EquipmentSelection.dll | fail | A:PASS ; B:PASS ; b1_il_MD=27 hdr=27 md_methods=None ; |
| 890 | 2 | Plus | 逆向成果/待静态验收/Plus/[TARGETDIR]/Xceed.Compression.dll | fail | A:PASS ; B:PASS ; b1_il_MD=436 hdr=436 md_methods=436 ; |
| 891 | 3 | Plus | 逆向成果/待静态验收/Plus/[TARGETDIR]/Xceed.FileSystem.dll | fail | A:PASS ; B:PASS ; b1_il_MD=726 hdr=726 md_methods=726 ; |
| 892 | 4 | Plus | 逆向成果/待静态验收/Plus/[TARGETDIR]/Xceed.Zip.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1470 hdr=1470 md_methods=1470 ; |
| 893 | 5 | Properties | 逆向成果/待静态验收/Properties/[CommonFiles64Folder]/AspenTech Shared/Aspen Excel Add-in Manager 64 Bit.exe | fail | A:PASS ; B:PASS ; b1_il_MD=188 hdr=188 md_methods=188 ; |
| 894 | 6 | Properties | 逆向成果/待静态验收/Properties/[CommonFiles64Folder]/AspenTech Shared/SLMServerCLS.dll | fail | A:PASS ; B:PASS ; b1_il_MD=15 hdr=15 md_methods=None ; |
| 895 | 7 | Properties | 逆向成果/待静态验收/Properties/[CommonFilesFolder]/AspenTech Shared/Aspen Excel Add-in Manager.exe | fail | A:PASS ; B:PASS ; b1_il_MD=188 hdr=188 md_methods=188 ; |
| 896 | 8 | Properties | 逆向成果/待静态验收/Properties/[CommonFilesFolder]/AspenTech Shared/SLMServerCLS.dll | fail | A:PASS ; B:PASS ; b1_il_MD=11 hdr=11 md_methods=11 ; |
| 897 | 9 | Properties | 逆向成果/待静态验收/Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/DatabaseConfiguration/ICSharpCode.SharpZipLib.dll | fail | A:PASS ; B:PASS ; b1_il_MD=585 hdr=585 md_methods=585 ; |
| 898 | 10 | Properties | 逆向成果/待静态验收/Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/DatabaseConfiguration/Serilog.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1026 hdr=1026 md_methods=1026 ; |
| 900 | 0 | Properties | 逆向成果/待静态验收/Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/DatabaseConfiguration/runtimes/win/lib/netcoreapp2.1/System.Data.SqlClient.dll | fail | A:PASS ; B:PASS ; b1_il_MD=5386 hdr=5386 md_methods=5386; b3_cs_hits=7(@13450,13657,13661,14855,14860,15183,23117) ; b3_cs=lines 13450,13657,13661,148… |
| 904 | 4 | Properties | 逆向成果/待静态验收/Properties/[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/Engine/xeq/AspenTech.APXL.Addin.dll | fail | A:PASS ; B:PASS ; b1_il_MD=750 hdr=750 md_methods=750 ; |
| 906 | 6 | Properties | 逆向成果/待静态验收/Properties/[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/Engine/xeq/Microsoft.VisualStudio.Imaging.Interop.14.0.DesignTime.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1 hdr=1 md_methods=1 ; |
| 907 | 7 | Properties | 逆向成果/待静态验收/Properties/[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/Engine/xeq/Microsoft.VisualStudio.Interop.dll | fail | A:PASS ; B:PASS ; b1_il_MD=16767 hdr=16767 md_methods=16767 ; |
| 908 | 8 | Properties | 逆向成果/待静态验收/Properties/[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/Engine/xeq/SetAppID.exe | fail | A:PASS ; B:PASS ; b1_il_MD=30 hdr=30 md_methods=30 ; |
| 910 | 10 | Properties | 逆向成果/待静态验收/Properties/[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/GUI/xeq/AspenProperties.exe | fail | A:PASS ; B:PASS ; b1_il_MD=54 hdr=54 md_methods=54 ; |
| 912 | 0 | Properties | 逆向成果/待静态验收/Properties/[TARGETDIR]/AspenTech.CompositeDoc.dll | fail | A:PASS ; B:PASS ; b1_il_MD=258 hdr=258 md_methods=258 ; |
| 913 | 1 | Properties | 逆向成果/待静态验收/Properties/[TARGETDIR]/Xceed.Compression.dll | fail | A:PASS ; B:PASS ; b1_il_MD=436 hdr=436 md_methods=436 ; |
| 914 | 2 | Properties | 逆向成果/待静态验收/Properties/[TARGETDIR]/Xceed.FileSystem.dll | fail | A:PASS ; B:PASS ; b1_il_MD=726 hdr=726 md_methods=726 ; |
| 915 | 3 | Properties | 逆向成果/待静态验收/Properties/[TARGETDIR]/Xceed.Zip.dll | fail | A:PASS ; B:PASS ; b1_il_MD=1470 hdr=1470 md_methods=1470 ; |
| 952 | 4 | Plus | 逆向成果/静态验收未通过/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Microsoft.Practices.Composite.Presentation.dll | fail | A:PASS ; B:PASS ; b1_il_MD=368 hdr=368 md_methods=368 ; |
| 963 | 3 | Plus | 逆向成果/静态验收未通过/Plus/[CommonFilesFolder]/AspenTech Shared/Microsoft.Bcl.HashCode.dll | fail | A:PASS ; B:PASS ; b1_il_MD=48 hdr=48 md_methods=48 ; |
| 964 | 4 | Plus | 逆向成果/静态验收未通过/Plus/[CommonFilesFolder]/AspenTech Shared/Microsoft.Extensions.Primitives.dll | fail | A:PASS ; B:PASS ; b1_il_MD=290 hdr=290 md_methods=290 ; |
| 968 | 8 | Plus | 逆向成果/静态验收未通过/Plus/[CommonFilesFolder]/AspenTech Shared/Stingray.GridControl71.dll | fail | A:PASS ; B:PARTIAL:no_il ; no_tierb_input ; |
| 969 | 9 | Plus | 逆向成果/静态验收未通过/Plus/[CommonFilesFolder]/AspenTech Shared/Stingray.GridUtils71.dll | fail | A:PASS ; B:PASS ; b1_il_MD=215 hdr=215 md_methods=215 ; |
| 970 | 10 | Plus | 逆向成果/静态验收未通过/Plus/[CommonFilesFolder]/AspenTech Shared/System.Runtime.CompilerServices.Unsafe.dll | fail | A:PASS ; B:PASS ; b1_il_MD=47 hdr=47 md_methods=None ; |
| 971 | 11 | Plus | 逆向成果/静态验收未通过/Plus/[CommonFilesFolder]/AspenTech Shared/System.Security.Permissions.dll | fail | A:PASS ; B:PASS ; b1_il_MD=56 hdr=56 md_methods=56 ; |
| 972 | 0 | Plus | 逆向成果/静态验收未通过/Plus/[CommonFilesFolder]/AspenTech Shared/System.Security.Principal.Windows.dll | fail | A:PASS ; B:PASS ; b1_il_MD=25 hdr=25 md_methods=None ; |
| 982 | 10 | Plus | 逆向成果/静态验收未通过/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinListView.v15.1.dll | fail | A:PASS ; B:PARTIAL:no_claim ; b1_il_MD=2185 hdr=2185 md_methods=None ; |

### a2_sha_missing（15 件）

复跑：PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 916 | 4 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnShell.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 917 | 5 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.UnmanagedWrapper.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 918 | 6 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/FindComponent.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 919 | 7 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Happ.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 920 | 8 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Ikc2Bkp.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 921 | 9 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WrapSaveMergeNNFiles.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 922 | 10 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/fimmtop.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 923 | 11 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/mmg.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 924 | 0 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/mmstruct.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 925 | 1 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/simdll.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 926 | 2 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/smge.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 930 | 6 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.APED.Core.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 931 | 7 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppexec.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 932 | 8 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/AspenTech.APED.Core.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 933 | 9 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnIPShell.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |

### a3_report_missing（15 件）

复跑：PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 916 | 4 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnShell.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 917 | 5 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.UnmanagedWrapper.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 918 | 6 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/FindComponent.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 919 | 7 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Happ.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 920 | 8 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Ikc2Bkp.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 921 | 9 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WrapSaveMergeNNFiles.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 922 | 10 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/fimmtop.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 923 | 11 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/mmg.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 924 | 0 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/mmstruct.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 925 | 1 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/simdll.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 926 | 2 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/smge.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 930 | 6 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.APED.Core.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 931 | 7 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppexec.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 932 | 8 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/AspenTech.APED.Core.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |
| 933 | 9 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnIPShell.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing ; B:NOT_RUN ; no_tierb_input ; a2=note=True rep=False |

### tier_b_incomplete（6 件）

复跑：PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 311 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AdvancedFileDialog.ocx | fail | A:PASS ; B:PARTIAL:no_il ; no_tierb_input ; |
| 332 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Exchange.SecureServices.dll | fail | A:PASS ; B:PARTIAL:no_il ; no_tierb_input ; |
| 357 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.BrowserSubprocess.Core.dll | fail | A:PASS ; B:PARTIAL:no_il ; b3_cs_hits=11(@42077,42082,42087,42092,42097,42102,42164,42169) ; b3_cs=lines 42077,42082,42087,42092,42097,42102,42164,421… |
| 359 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.Core.Runtime.dll | fail | A:PASS ; B:PARTIAL:no_il ; b3_cs_hits=1(@79647) ; b3_cs=lines 79647 |
| 459 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/TDEdll.dll | fail | A:PASS ; B:PARTIAL:no_il ; no_tierb_input ; |
| 968 | 8 | Plus | 逆向成果/静态验收未通过/Plus/[CommonFilesFolder]/AspenTech Shared/Stingray.GridControl71.dll | fail | A:PASS ; B:PARTIAL:no_il ; no_tierb_input ; |

### analyze_failed（1 件）

复跑：PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 982 | 10 | Plus | 逆向成果/静态验收未通过/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinListView.v15.1.dll | fail | A:PASS ; B:PARTIAL:no_claim ; b1_il_MD=2185 hdr=2185 md_methods=None ; |

## 观察项（不判 fail）

B3 占位符扫描命中 135 件：NotImplementedException / #error / 待填 出现在反编译正文里。**无法区分是原版本来就抛 NotImplementedException 还是恢复缺口**（原件不在仓库），因此只登记、不判 fail。命中行号见台账 evidence 列的 b3_cs= 字段与 shard-*.jsonl。
