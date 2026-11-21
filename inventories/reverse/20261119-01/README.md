# 第 20261119-01 轮逐文件归档

[逐文件台账](ledger.csv) 按原文件 SHA-256 记录本轮处置。[新归档指纹](artifacts.csv) 将本轮产物和逐份说明关联到原件。两个表中的归档与证据路径均相对仓库根目录，指向本机文件。旧成果的每份路径和指纹保存在历史核验表中。

## 历史交接

| 入口 | 不同原文件 | 本地证据 |
| --- | ---: | --- |
| 旧源码索引 | 39 | `.local/source-classification-20261118/index.json` |
| 原名归档中另有 IL 或原生分析的文件 | 13 | `.local/step-2-naming-20261118/{V15-final,V15-check}/index.json` |
| 含 VBA 的工作簿 | 3 | `.local/properties-deep-20261118-verified/internal-code-members.json` |
| 读取函数的局部反汇编 | 2 | `.local/properties-deep-20261118-verified/reader-code-evidence.json` |
| AdsDataMap.dll 的局部 C# | 1 | `.local/suffix-sampling-20261118-initial/02-incomplete/` |

本轮目录为 `.local/reverse-round-20261119-01/`。`history/freeze.json` 冻结上述 58 项，SHA-256 为 `1fcd7778a2dd3673114d238bfe1f77b66ef7b7aa4199cf0c700735f5cf21a545`。`history/audit.json` 记录 175 条去重来源的原件核验及 727 条历史产物路径的指纹，包含不同时期的副本。表内的历史建议与本轮验收结果可按原哈希对照。内层 VBA 模块保留父工作簿与成员身份。

## 整文件验收

五个原文件的 Plus 安装包成员、Properties 安装包成员和已安装副本均已分别核对。每件归档三份成果，各配独立说明。下表记录整文件的核验边界。

| 原文件 | 方法定义 | 核验结果 |
| --- | ---: | --- |
| Interop.Aosapfs.dll | 336 | 114 个用户类型、59 个 COM 接口。对照原始 IL 修正 C# 中 BlockPosition 两个访问器遗漏的索引参数。336 项均为原版导入接口声明。 |
| AspenTech.AspenPlus.ModelLibrary.Controls.dll | 263 | 全部有方法体。四处抛出 NotImplementedException 均能对应原 IL，四个模板部件在卫星资源中定位。 |
| AspenTech.AspenPlus.WpfPropertyControl.dll | 249 | 全部有方法体，七个布局 URI 与 en-US 卫星资源逐一对应。 |
| AspenTech.Visualisation.Assistant.Run.exe | 5 | 核对完整入口程序、图标、清单和版本资源。 |
| AspenTech.Visualisation.Controls.Assistant.W1.dll | 254 | 218 项有方法体，另 36 项由接口声明、委托运行时方法及 COM 保留槽解释。两份嵌入布局的连接编号已核对。 |

四个历史完成件共核对 735 个方法体、11,352 条 IL 指令及 41 个异常区。`interop-evidence/review.json` 和 `prior-evidence/review.json` 保存来源、工具操作、覆盖证据和归档指纹。验收范围为静态逆向归档，运行行为留待 Windows 重建阶段对照。

## 清单视图

本机 `views/` 保留 Plus、Properties、Properties 重复子表及共用索引的完整来源行和分类列，追加来源标识、逆向状态及轮次。`views/summary.json` 分别按原文件哈希、来源身份和各视图行数统计。跨视图重复出现的来源以同一来源标识关联。

| 范围 | 不同内容 | 去重来源 |
| --- | ---: | ---: |
| 已完成 | 5 | 15 |
| 未完成 | 38 | 119 |
| 暂存 | 15 | 41 |
| 未开始 | 1,339 | 3,718 |
| 合计 | 1,397 | 3,893 |

从仓库根目录运行以下命令可核验已发布台账与四份冻结清单的对应关系。在归档机上加 `--verify-local` 可复算本轮产物、同名说明及验收记录指纹。参数 `--output <新目录>` 会核验本机归档并生成完整视图。

```sh
python tools/reverse_status_views.py inventories/reverse/20261119-01
```
