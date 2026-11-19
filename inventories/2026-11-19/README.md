# 完整分类清单快照（2026-11-19）

按用户本次要求，将现有完整分类清单作为元数据上传 GitHub。这里是原清单的逐字节副本，不重新扫描、分类或验收；本地原目录及历史记录继续保留。每份副本的来源、字节数和 SHA-256 见 [manifest.json](manifest.json)。

## Properties 当前五份清单

| 清单 | 来源记录数 | 完整 CSV |
| --- | ---: | --- |
| 需要逆向 | 1,866 | [files.csv](properties/01-needs-reverse/files.csv) |
| 不需要逆向 | 17,432 | [files.csv](properties/02-no-reverse/files.csv) |
| 需要逆向中的重复项 | 1,828 | [duplicates.csv](properties/01-needs-reverse/duplicates.csv) |
| 不需要逆向中的重复项 | 10,735 | [duplicates.csv](properties/02-no-reverse/duplicates.csv) |
| 尚未确定 | 0 | [files.csv](properties/03-undetermined/files.csv) |

五份清单使用 `.local/properties-install-paths-20261119-verified/` 的最新结果，包含安装定位字段。两份重复清单是对应主分类的子集，不能再次相加。[duplicate-groups.json](properties/duplicate-groups.json) 保留全部双方来源关联；[target-resolutions.json](properties/target-resolutions.json) 保留 98 条安装目标的定位记录。

19,298 条为有 Properties 安装归属的来源记录，包含容器、成员和副本，不是去重内容数。8 个受限 MDF/LDF 的原内容及 SHA-256 仍不可读；尚未确定为零仅表示处理路线已明确，不表示数据库解码、反编译或行为验收已完成。

## Plus 冻结分类及共用交叉索引

沿用 `.local/properties-only-20261118-delivery-final/` 的原索引。索引中保留双方归属来源，不能把其中所有行都计为 Plus 自身的物理文件。Plus 分类、理由、状态和证据保持不变。

| 索引 | 需要逆向 | 不需要逆向 | 完整文档 |
| --- | --- | --- | --- |
| Plus | [3,791 条](plus/01-needs-reverse/files.csv) | [48,187 条](plus/02-no-reverse/files.csv) | [classification.md](plus/classification.md) |
| 共用文件 | [2,534 条](shared/01-needs-reverse/files.csv) | [8,189 条](shared/02-no-reverse/files.csv) | [classification.md](shared/classification.md) |

附 [Plus 后缀统计](plus/extension-statistics.csv)、[原待核实清单](plus/remaining-review.csv)、[共用后缀统计](shared/extension-statistics.csv)及[原待核实清单](shared/remaining-review.csv)。当前 Properties 五份清单采用上表的新快照；不能用旧混合索引替代 Properties 最新统计。同内容的分析键与来源继续交叉引用。

## 已完成 / 未完成的历史源码索引

[source-completion/index.json](source-completion/index.json) 是 `.local/source-classification-20261118/index.json` 的完整元数据副本，保留 4 份原版文件标记已完成、35 份标记未完成及相应源码条目。它记录当时的归档状态，不重新验收，不表示 Windows 编译或行为验证通过。反编译正文和原版二进制继续仅本地保存。

## 阅读及核验

CSV 保留原始文件名、路径、归属、版本、哈希、分类理由、状态与证据引用。路径字段和证据链接可能指向本机 `.local/`，这些引用不是已上传的证据正文。数据库、公式资料、原版安装包/二进制、完整反编译正文、工具安装包、构建产物和凭据不在本次上传范围内。其他产品的历史扫描仍仅本地保留，不扩大本次分类范围。

部分文件较大，GitHub 可能不显示全文预览；可使用页面的下载按钮或检出本分支后阅读。

在仓库根目录运行：

```sh
python tools/verify_published_classification.py
```

有原本地清单的机器还可运行 `python tools/verify_published_classification.py --check-local-sources`，逐字节核对副本来源。
