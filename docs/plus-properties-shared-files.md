# Aspen Plus 与 Aspen Properties 共用文件清单

本轮只新增共享归属与交叉索引；共用内容沿用既有 Plus 分类，不重开 Plus 分类或新增其待核实项。Properties 的新内容待复核项另见[说明](classification-uncertainties.md)。

本页是新增的共用文件分类入口。[Plus](aspen-plus-classification.md)、[Properties](aspen-properties-classification.md)与本清单同时保留双归属文件。共用清单是两份产品清单的交集索引，不替代它们。

| 处理路线 | 来源记录 | 本地 CSV |
| --- | ---: | --- |
| 需要逆向 | 2,534 | `.local/properties-only-20261118-delivery-final/shared/01-needs-reverse/files.csv` |
| 不需要逆向 | 8,189 | `.local/properties-only-20261118-delivery-final/shared/02-no-reverse/files.csv` |

完整逐来源 Markdown：`.local/properties-only-20261118-delivery-final/shared/classification.md`。每条记录保留原产品、安装包、路径、包内成员、组件、版本、SHA-256、分类依据和统一分析键；类内按末级后缀排序。三份清单的共用来源行已逐项核对一致。

## 纳入依据

- **两份产品安装来源均交付同一内容：** SHA-256 一致且内容读取成功，共 **2,671 个不同哈希**，其中 **2,620 个**出现在实际 CAB 载荷中。其余属于安装流、容器或内层成员；通过 `source` 区分，不能把它们都称为运行模块。
- **已安装文件的实际目标被双方 MSI 明确指向：** 同一目标文件保留双方安装归属，即使现场内容与原版载荷存在差异，也独立保存其版本和哈希，不冒充原载荷。该途径额外纳入 **5 个不同现场内容哈希**。

共用清单共 10,723 条来源记录、2,676 个不同可读内容哈希。例子包括 AprSystem 中的 `ppaproph.dll`、`AspenTech.APED.Core.dll` 和 OOMF 的 `amodel.dll`；双方交付记录和具体内容哈希均在完整清单中。

同名异哈希分开存放和分类，不合并内容分析键。已解析安装目标中未发现双方同目标异哈希项；`shared-target-variants.csv` 保留对应空表。另有 **4 个 `[TARGETDIR]` 符号目标名称**包含不同内容版本，单列 `symbolic-target-variants.csv`；因实际目录未解析，不据此认定真实安装目标相同或将不同内容强行归为一个文件。

相同字节内容证明双方交付有交集，不能单独证明运行时调用关系。后续逐文件分析仍须记录依赖、入口与运行证据。反编译 / 编译成果继续按已完成与未完成及逐文件说明另行验收。完整范围、来源链与读取限制见[双产品盘点](plus-properties-inventory.md)。
