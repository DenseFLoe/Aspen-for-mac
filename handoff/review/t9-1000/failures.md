# T9 失败清单（按 fail_code 分组）

机检预审口径：本清单只列**机械可判**的缺口；语义层（类型用途、调用约定、逻辑等价）未复核，故本清单不等于上游「静态验收未通过」结论，也不做 P0–P3 终判。

总件数 1000 ｜ fail 15 ｜ partial 122 ｜ blocked 0 ｜ pass 863

复跑命令（单件）：`PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh`

## fail_code 计数

| fail_code | 件数 | 含义 |
| --- | ---: | --- |
| export_missing_pe | 115 |  |
| non_pe_tier_a_only | 115 | 非 PE（.xls/.chm 等）只做 Tier A |
| a2_sha_missing | 15 | 归档说明或制作者报告里取不到 64 位 SHA-256 |
| a3_report_missing | 15 | 制作者报告（v0.*/制作者报告/<name>.md）缺失或为空 |
| tier_b_incomplete | 6 | Tier B 只做一半（如 CLR 缺 il.txt） |
| analyze_failed | 1 |  |

## 分组明细

### export_missing_pe（115 件）

复跑：`PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh`

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 62 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/COCOMTh.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 63 | 3 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/COCOMTh11.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 65 | 5 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HYPCOThK.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 66 | 6 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HYPCOThK11.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 67 | 7 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HyCOGUI.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 68 | 8 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HyCOGUI11.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 70 | 10 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HypCOTh.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 71 | 11 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HypCOTh11.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 100 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/COMThermo/thpropmanager.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 110 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/XML/Xmlread.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 175 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/acmexp.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 176 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/atdll_support.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 181 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AprCorrMan.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 193 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/GasProps.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 199 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/PetroleumProps.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 200 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/aesuom.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 201 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/aesxml.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 202 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/aosbridge.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 203 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/apbatutl.exe | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 227 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/createva.exe | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 234 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/hyspropC.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 235 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/libifcoremd.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 236 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/libifportmd.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 239 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/perl.exe | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 255 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/pppropsystem.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 259 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/pptderefprop.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 266 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/rtmalloc.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 267 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/rtpdfutl.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 307 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/APRegFix.exe | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 314 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnContext.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 400 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/FindCompDBSpec.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 438 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/MMDialog.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 440 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/MMutil.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 527 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/apmodlib.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 528 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ast100.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 532 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/libEGL.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 535 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/mmtbsdll.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 536 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/pfsplot.ocx | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 538 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/recdefdll.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 586 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Open Solvers V15.0/Bin/IntegratorServer.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| … | | | 共 115 件，余 75 件见 ledger-1000.csv | | |

### non_pe_tier_a_only（115 件）

复跑：`PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh`

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 62 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/COCOMTh.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 63 | 3 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/COCOMTh11.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 65 | 5 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HYPCOThK.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 66 | 6 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HYPCOThK11.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 67 | 7 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HyCOGUI.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 68 | 8 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HyCOGUI11.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 70 | 10 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HypCOTh.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 71 | 11 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/CAPE-OPEN/HypCOTh11.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 100 | 4 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/COMThermo/thpropmanager.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 110 | 2 | Plus | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/Hyprotech/XML/Xmlread.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 175 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/acmexp.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 176 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/atdll_support.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 181 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AprCorrMan.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 193 | 1 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/GasProps.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 199 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/PetroleumProps.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 200 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/aesuom.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 201 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/aesxml.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 202 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/aosbridge.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 203 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/apbatutl.exe | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 227 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/createva.exe | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 234 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/hyspropC.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 235 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/libifcoremd.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 236 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/libifportmd.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 239 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/perl.exe | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 255 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/pppropsystem.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 259 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/pptderefprop.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 266 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/rtmalloc.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 267 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/rtpdfutl.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 307 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/APRegFix.exe | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 314 | 2 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnContext.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 400 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/FindCompDBSpec.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 438 | 6 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/MMDialog.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 440 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/MMutil.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 527 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/apmodlib.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 528 | 0 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ast100.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 532 | 4 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/libEGL.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 535 | 7 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/mmtbsdll.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 536 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/pfsplot.ocx | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 538 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/recdefdll.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| 586 | 10 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Open Solvers V15.0/Bin/IntegratorServer.dll | partial | A:PASS / B:NOT_RUN / no_tierb_input /  |
| … | | | 共 115 件，余 75 件见 ledger-1000.csv | | |

### a2_sha_missing（15 件）

复跑：`PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh`

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 916 | 4 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnShell.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 917 | 5 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.UnmanagedWrapper.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 918 | 6 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/FindComponent.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 919 | 7 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Happ.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 920 | 8 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Ikc2Bkp.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 921 | 9 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WrapSaveMergeNNFiles.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 922 | 10 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/fimmtop.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 923 | 11 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/mmg.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 924 | 0 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/mmstruct.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 925 | 1 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/simdll.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 926 | 2 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/smge.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 930 | 6 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.APED.Core.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 931 | 7 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppexec.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 932 | 8 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/AspenTech.APED.Core.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 933 | 9 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnIPShell.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |

### a3_report_missing（15 件）

复跑：`PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh`

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 916 | 4 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnShell.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 917 | 5 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.UnmanagedWrapper.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 918 | 6 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/FindComponent.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 919 | 7 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Happ.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 920 | 8 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Ikc2Bkp.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 921 | 9 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WrapSaveMergeNNFiles.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 922 | 10 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/fimmtop.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 923 | 11 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/mmg.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 924 | 0 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/mmstruct.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 925 | 1 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/simdll.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 926 | 2 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/smge.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 930 | 6 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.APED.Core.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 931 | 7 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppexec.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 932 | 8 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/Bin/AspenTech.APED.Core.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |
| 933 | 9 | Plus-Properties | 逆向成果/静态验收未通过/Plus-Properties/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnIPShell.dll | fail | A:FAIL:a3_report_missing,a2_sha_missing / B:NOT_RUN / no_tierb_input / a2=note=True rep=False |

### tier_b_incomplete（6 件）

复跑：`PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh`

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 311 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AdvancedFileDialog.ocx | partial | A:PASS / B:PASS / no_tierb_input /  |
| 332 | 8 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Exchange.SecureServices.dll | partial | A:PASS / B:PASS / no_tierb_input /  |
| 357 | 9 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.BrowserSubprocess.Core.dll | partial | A:PASS / B:PASS / b3_cs_hits=11(@42077,42082,42087,42092,42097,42102,42164,42169) / b3_cs=lines 42077,42082,42087,42092,42097,42102,42164,42169,42174,42413,42434 |
| 359 | 11 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.Core.Runtime.dll | partial | A:PASS / B:PASS / b3_cs_hits=1(@79647) / b3_cs=lines 79647 |
| 459 | 3 | Plus | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/TDEdll.dll | partial | A:PASS / B:PASS / no_tierb_input /  |
| 968 | 8 | Plus | 逆向成果/静态验收未通过/Plus/[CommonFilesFolder]/AspenTech Shared/Stingray.GridControl71.dll | partial | A:PASS / B:PASS / no_tierb_input /  |

### analyze_failed（1 件）

复跑：`PYTHONIOENCODING=utf-8 python out/review9/verify_item.py --idx <idx> --fresh`

| idx | shard | product | item_dir | verdict | evidence |
| ---: | ---: | --- | --- | --- | --- |
| 982 | 10 | Plus | 逆向成果/静态验收未通过/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinListView.v15.1.dll | partial | A:PASS / B:PASS / b1_il_MD=2185 hdr=2185 md_methods=None /  |

## 观察项（不判 fail）

B3 占位符扫描命中 135 件：`NotImplementedException` / `#error` / 待填 出现在反编译正文里。**无法区分是原版本来就抛 NotImplementedException 还是恢复缺口**（原件不在仓库），因此只登记、不判 fail。

| idx | item_dir | 命中 |
| ---: | --- | --- |
| 4 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/AspenTech.AspenCxs.dll | b3_cs_hits=2(@2162,2195) | b3_cs=lines 2162,2195 |
| 7 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/AspenTech.AspenCxs.SummaryGrid.dll | b3_cs_hits=7(@11580,11610,11643,11675,11712,11739,11760) | b3_cs=lines 11580,11610,11643,11675,11712,11739,11760 |
| 8 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/AspenTech.AspenCxs.dll | b3_cs_hits=2(@2162,2195) | b3_cs=lines 2162,2195 |
| 10 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.DataManager.dll | b3_cs_hits=2(@3293,6547) | b3_cs=lines 3293,6547 |
| 12 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.dll | b3_cs_hits=1(@3085) | b3_cs=lines 3085 |
| 19 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AdbCsLayer.dll | b3_cs_hits=32(@72,80,88,96,104,125,130,135) | b3_cs=lines 72,80,88,96,104,125,130,135,140,145,150,155,160,165,170,175,18 |
| 21 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AdsComparer.exe | b3_cs_hits=1(@759) | b3_cs=lines 759 |
| 28 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.AspenCxs.CxsViewModel.dll | b3_cs_hits=8(@4812,19938,20293,20298,20316,20321,20334,20339) | b3_cs=lines 4812,19938,20293,20298,20316,20321,20334,203 |
| 29 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.AspenCxs.dll | b3_cs_hits=2(@2162,2195) | b3_cs=lines 2162,2195 |
| 34 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.EquipmentAnalysis.Models.dll | b3_cs_hits=25(@5126,5134,5144,5152,5174,5179,5213,5218) | b3_cs=lines 5126,5134,5144,5152,5174,5179,5213,5218,5223,5340, |
| 35 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.EquipmentAnalysis.PSVControlResources.dll | b3_cs_hits=29(@7840,7856,7872,7892,7912,7935,7963,8028) | b3_cs=lines 7840,7856,7872,7892,7912,7935,7963,8028,8045,8061, |
| 36 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.EquipmentAnalysis.Resources.dll | b3_cs_hits=1(@609) | b3_cs=lines 609 |
| 37 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.Hydraulics.Framework.dll | b3_cs_hits=11(@3191,4320,8284,8378,8448,8608,8638,8705) | b3_cs=lines 3191,4320,8284,8378,8448,8608,8638,8705,8759,8947, |
| 39 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/AspenTech.Visualisation.Controls.Support.Wpf.dll | b3_cs_hits=8(@2089,2440,4224,11239,11263,11275,11287,11299) | b3_cs=lines 2089,2440,4224,11239,11263,11275,11287,11299 |
| 41 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Data.dll | b3_cs_hits=1(@416) | b3_cs=lines 416 |
| 47 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/InfragisticsWPF.dll | b3_cs_hits=1(@3175) | b3_cs=lines 3175 |
| 50 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Microsoft.Practices.Unity.dll | b3_cs_hits=5(@1544,1549,1554,1571,1576) | b3_cs=lines 1544,1549,1554,1571,1576 |
| 57 | 逆向成果/待静态验收/Plus/[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/PropertyUtilities.dll | b3_cs_hits=8(@3507,6802,6807,6812,6817,10624,10757,10762) | b3_cs=lines 3507,6802,6807,6812,6817,10624,10757,10762 |
| 111 | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/AspenTech.AspenCxs.dll | b3_cs_hits=2(@2162,2195) | b3_cs=lines 2162,2195 |
| 113 | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/AspenTech.AspenCxs.SummaryGrid.dll | b3_cs_hits=7(@11580,11610,11643,11675,11712,11739,11760) | b3_cs=lines 11580,11610,11643,11675,11712,11739,11760 |
| 114 | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/AspenTech.AspenCxs.dll | b3_cs_hits=2(@2162,2195) | b3_cs=lines 2162,2195 |
| 116 | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.DataManager.dll | b3_cs_hits=2(@3293,6547) | b3_cs=lines 3293,6547 |
| 118 | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Aspen CXS V15.0/SummaryGrid/InfragisticsWPF.dll | b3_cs_hits=1(@3085) | b3_cs=lines 3085 |
| 132 | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/Npgsql.dll | b3_cs_hits=10(@34762,45788,47903,47922,48520,50732,50737,50742) | b3_cs=lines 34762,45788,47903,47922,48520,50732,50737, |
| 136 | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Data.SqlClient.dll | b3_cs_hits=1(@845) | b3_cs=lines 845 |
| 138 | 逆向成果/待静态验收/Plus/[CommonFilesFolder]/AspenTech Shared/System.Memory.dll | b3_cs_hits=3(@5639,5643,5648) | b3_cs=lines 5639,5643,5648 |
| 156 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/AspenTech.Modeler.ACMExpUtilities.dll | b3_cs_hits=19(@267,272,277,551,556,3713,3721,3725) | b3_cs=lines 267,272,277,551,556,3713,3721,3725,4353,4795,5616,5621, |
| 164 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Documents.Excel.v15.1.dll | b3_cs_hits=5(@57068,106025,106060,106294,106329) | b3_cs=lines 57068,106025,106060,106294,106329 |
| 166 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.Misc.v15.1.dll | b3_cs_hits=1(@53191) | b3_cs=lines 53191 |
| 168 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinChart.v15.1.dll | b3_cs_hits=2(@51155,51160) | b3_cs=lines 51155,51160 |
| 172 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Infragistics4.Win.UltraWinGrid.v15.1.dll | b3_cs_hits=5(@5863,58588,58596,58661,186448) | b3_cs=lines 5863,58588,58596,58661,186448 |
| 182 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.CalculationService.dll | b3_cs_hits=2(@503,2205) | b3_cs=lines 503,2205 |
| 184 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.DatabaseManagement.dll | b3_cs_hits=4(@1418,2005,2033,2054) | b3_cs=lines 1418,2005,2033,2054 |
| 186 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.PhysicalProperties.dll | b3_cs_hits=10(@1599,4198,4856,5044,5085,5147,5419,6089) | b3_cs=lines 1599,4198,4856,5044,5085,5147,5419,6089,6176,6228 |
| 196 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/Npgsql.dll | b3_cs_hits=10(@34762,45788,47903,47922,48520,50732,50737,50742) | b3_cs=lines 34762,45788,47903,47922,48520,50732,50737, |
| 316 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.ActivationDashboard.Infrastructure.dll | b3_cs_hits=10(@1041,1058,1662,1682,1719,1739,1792,1834) | b3_cs=lines 1041,1058,1662,1682,1719,1739,1792,1834,1914,3360 |
| 319 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenCxs.SummaryGrid.dll | b3_cs_hits=7(@11596,11626,11659,11691,11728,11755,11776) | b3_cs=lines 11596,11626,11659,11691,11728,11755,11776 |
| 320 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenONEShare.dll | b3_cs_hits=1(@5034) | b3_cs=lines 5034 |
| 323 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.MolecularDrawing.dll | b3_cs_hits=9(@586,613,650,687,723,2483,11042,24435) | b3_cs=lines 586,613,650,687,723,2483,11042,24435,25713 |
| 328 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Engineering.CommonShellExtensions.dll | b3_cs_hits=10(@1395,1400,1405,1410,1422,1427,1432,1444) | b3_cs=lines 1395,1400,1405,1410,1422,1427,1432,1444,1456,1461 |
| 329 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Engineering.GridControls.dll | b3_cs_hits=18(@1029,2556,2696,19985,20015,20037,20062,20078) | b3_cs=lines 1029,2556,2696,19985,20015,20037,20062,20078, |
| 331 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.EquipmentAnalysis.UserInterface.dll | b3_cs_hits=11(@4806,4814,4848,4853,5089,5219,5492,5497) | b3_cs=lines 4806,4814,4848,4853,5089,5219,5492,5497,5502,5507, |
| 334 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.HtmlHelp.HelpCefViewer.dll | b3_cs_hits=69(@193,201,219,231,239,247,259,271) | b3_cs=lines 193,201,219,231,239,247,259,271,283,295,307,323,331,335,34 |
| 340 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.InContextGuidance.ExchangeControls.dll | b3_cs_hits=2(@54,104) | b3_cs=lines 54,104 |
| 341 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.InContextGuidance.ExchangeIntegration.dll | b3_cs_hits=1(@595) | b3_cs=lines 595 |
| 343 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.InContextGuidance.Widgets.dll | b3_cs_hits=12(@1455,1486,1502,1519,1535,1555,1567,1585) | b3_cs=lines 1455,1486,1502,1519,1535,1555,1567,1585,1603,1621, |
| 348 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Visualisation.Controls.Support.Wpf.dll | b3_cs_hits=8(@2089,2440,4224,11239,11263,11275,11287,11299) | b3_cs=lines 2089,2440,4224,11239,11263,11275,11287,11299 |
| 349 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.WpfControls.Engineering.dll | b3_cs_hits=22(@2339,2362,2388,2408,2430,2529,2603,2656) | b3_cs=lines 2339,2362,2388,2408,2430,2529,2603,2656,2692,2708, |
| 352 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/Aspentech.EnergyAnalysis.UserInterface.dll | b3_cs_hits=46(@991,4327,7609,14172,14197,14221,14255,14275) | b3_cs=lines 991,4327,7609,14172,14197,14221,14255,14275,14 |
| 357 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.BrowserSubprocess.Core.dll |  |
| 359 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.Core.Runtime.dll |  |
| 362 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.Wpf.dll | b3_cs_hits=2(@2356,2719) | b3_cs=lines 2356,2719 |
| 363 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/CefSharp.dll | b3_cs_hits=24(@2719,2724,2729,2734,2739,2744,2749,2782) | b3_cs=lines 2719,2724,2729,2734,2739,2744,2749,2782,2787,2792, |
| 366 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Charts.Designer.v23.2.dll | b3_cs_hits=25(@11085,11090,11095,11100,11184,11189,11194,11199) | b3_cs=lines 11085,11090,11095,11100,11184,11189,11194, |
| 367 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Charts.v23.2.Core.dll | b3_cs_hits=6(@35815,35827,35839,35851,42522,60956) | b3_cs=lines 35815,35827,35839,35851,42522,60956 |
| 368 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.CodeParser.v23.2.dll | b3_cs_hits=69(@44776,78609,78614,79937,83590,83798,83803,88479) | b3_cs=lines 44776,78609,78614,79937,83590,83798,83803, |
| 369 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Data.Desktop.v23.2.dll | b3_cs_hits=14(@5130,5161,5169,5173,5181,5185,5206,5211) | b3_cs=lines 5130,5161,5169,5173,5181,5185,5206,5211,5216,5221, |
| 370 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.DataAccess.v23.2.dll | b3_cs_hits=2(@57346,60615) | b3_cs=lines 57346,60615 |
| 372 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Drawing.v23.2.dll | b3_cs_hits=42(@9683,9692,16614,17600,17605,25099,25998,26065) | b3_cs=lines 9683,9692,16614,17600,17605,25099,25998,2606 |
| 373 | 逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.Mvvm.v23.2.dll | b3_cs_hits=3(@16232,16243,35928) | b3_cs=lines 16232,16243,35928 |
| … | 共 135 件 | |
