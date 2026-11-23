# NATIVE-337 s117 独立复验

[固定头](https://github.com/DenseFLoe/Aspen-for-mac/tree/ea4a5c7ffc59c27075030fb4b8726f534d23c153)，原件 FindComponent.dll SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。相对 5f6e5b63 是两个提交、六个路径。新增 s117 指纹、回执、排除说明、两份脚本，另改 s101_receipt_section.py。独立回读并核对本件、tool 和 qa 三棵树 209 个文件的 Git blob、大小及 SHA-256。[固定清单](s117-fixed-manifest.json)

候选检查器 SHA-256 `0069dc3a8237f5550ccf9cf4db8715d0832bd4decfaf7de805a9bd739fa6259e`，配对运行 24 组。正常 listing+signature、单独 signature、等价 JSON 排序和空白均 exit 0。19 个错误组定位并 exit 3，其中前置矛盾重复 CSV 行、错误注册类、裸接口小写均已修复。另两组预期应提示依据缺失或矛盾，实际如下。

| 单一变量 | 原始结果 | 预期 |
| --- | --- | --- |
| 保持交付不动，只把 --signature 的 --binary 指向不存在的文件 | signature-check: conflicts=0，exit 0 | 缺独立数据时待核或非零 |
| 只改 Registry64.codeBase 指向不存在的部署 DLL，更新交付清单内该附件 SHA-256 | listing-check: sites=2 conflicts=0；signature-check: conflicts=0，exit 0 | 应核对独立注册信息并报告 codeBase 绑定矛盾 |

独立用 PowerShell 从本机 CLSID 取得 CodeBase，打开目标 PE 读取元数据。采集 JSON 与交付逐字节相同，SHA-256 `72abab6b73c616bc454ede59d9698510cee968a26100dbaaf07627ffa86b363e`，部署 PE SHA-256 `04e68b8eca60b732e661bf322d74b6f042abeba9ea801e2e2e410c1be007b5d5`，接口与实现签名 2001080E，RVA 分别为 0 和 0xA848。[采集脚本](s117-read-registration.ps1) 候选 verify(folder) 只读附件和 CSV，按脚本常量判断，未打开部署 PE 或独立注册源。交付中的 D 组删的是附件字段，得到 exit 3；该组未模拟缺部署原件。上游核对的当前部署绑定成立，缺独立依据的其他输入仍可误过。同一原件的交付表再生成逐字节一致。

活动清单 109/109 已声明指纹匹配。固定生成器运行 seq=117，实得 110，唯一差异为 code/README.md，SHA-256 `83a6fb2e104fc798fdfa170330ca92dd0cbccc23b03f1369675f5d387f9d67cf`。回执的活动清单 SHA-256 `4b01f6046cbb6d8f5e7d606e393a8ed217fd417562c7f3bb9d10e3b4c3995e9e` 正确。回执列明的五份脚本（含主干 checker）逐个核对大小和 SHA-256，全部吻合。回执唯一固定候选为旧 7c18f40d；该树尚无 s117 脚本。实际 s117 变体脚本在固定头生成同组基准哈希 f2cdadc8166a14d59c4a94b529c85ecb860129873c7d00b526041409b8a91c68，与回执的 8be1e7c0ecc1093a… 不同。四项均定位、套件 exit 0。

主干 fe5c0bee 的覆盖 v1 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`，实测 307 覆盖行、307 入口、684 引用、0 声明缺口、112 未决、exit 2。另核对协作方选用的 QA 93bf962c 共 31 个 QA 文件，固定基线与仅改 codeBase 并重算交付指纹的副本均是 11 pass、3 不适用、0 error、整体 exit 2。重汇编对照 6083 项、6081 相符、2 项既有例外、0 mismatch。路径检测两组均读 109 项，均报通过。QA 的上述输出不能补足部署依赖或漏列交付文件。[复跑脚本](s117-replay.py) · [原始结果及用例输入指纹](s117-recheck.json)

    pwsh -File s117-read-registration.ps1
    python -B s117-replay.py ORIGINAL registration.json NEW_OUTPUT_DIR CANDIDATE MAIN_CHECKER
    python -B qa/gate.py --task NATIVE-337 --item-dir UNIT --original ORIGINAL --l1-path MAIN_CHECKER
