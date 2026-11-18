# Aspen Properties 文件分类清单

**本清单包含 3,441 条新内容规则初分待复核来源记录，分类验收尚未完成。** 逐项见本地同目录 `remaining-review.csv`；[纠正说明](classification-uncertainties.md)记录遗漏原因与 VBA 误分类修复。

Aspen Properties 正式作为独立产品开发。首选来源为 `Aspen Properties V15 (64bit).msi`，配套的 `Aspen Properties Enterprise Database Server V15 (64bit).msi` 独立标记；已安装文件仅作补充。来源、验证和限制见[双产品盘点](plus-properties-inventory.md)。

| 处理路线 | 来源记录 | 本地 CSV |
| --- | ---: | --- |
| 需要逆向 | 2,632 | `.local/properties-only-20261118-delivery-final/properties/01-needs-reverse/files.csv` |
| 不需要逆向 | 19,900 | `.local/properties-only-20261118-delivery-final/properties/02-no-reverse/files.csv` |

完整逐来源 Markdown：`.local/properties-only-20261118-delivery-final/properties/classification.md`。两类内部均按末级后缀排序；每类另有首选 / 备选子清单。`package` 区分主包、配套包和已安装来源。

主包载荷 2,867 份，分类为 767 / 2,100；配套包载荷 1,553 份，分类为 319 / 1,234（需要逆向 / 不需要逆向）。安装表明确交付的 AprSystem、OOMF、共享 DLL、数据库与接口文件按相应组件纳入；安装在其他产品目录的内容仅限 MSI 明确交付的相关文件，不扩大为整个产品评估。

双归属文件在本清单、[Plus 清单](aspen-plus-classification.md)和[共用清单](plus-properties-shared-files.md)同时出现，共用内容哈希与分析键，保留各自来源。APED 8 个运行中 MDF/LDF 的内容与哈希不可读，单独标记；分类明确不等于内容已取得或已完成恢复。

上述总数按来源行计数，包含容器、内嵌流和 ZIP 成员，不是去重文件数。未开展新一轮完整反编译、Windows 重建或 Mac 构建。
