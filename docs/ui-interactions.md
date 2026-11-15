# 界面交互补齐记录

2026-11-15，基于 `5ef0861`（已包含默认分支 `1fe0e13`）继续补齐。未载入原版程序集代码；图像由资源读取器提取，运行时观察使用 Windows computer-use。

## 本轮实现

- 功能区、左侧设置/方法子项、单位菜单、组分工具按钮使用统一动作路由。清理参数、运行设置、重新初始化、物性管理、查询等可打开对应资源窗口；页面历史支持后退和前进。未接入的外部命令显示未执行原因。
- 恢复旧式 `ContentProgId` 到已有 WPF 页面，以及按控件类型嵌入的页面。设置、方法等的注释页能实际显示、编辑；查找化合物增加数据库页和 PubChem 页面入口。
- 静态声明的下拉项目、单选组、复选框、文本及数值输入能够保留本次会话的界面状态。窗口之间不共享未说明的业务数据；重新启动后不保存。本轮没有接入 Aspen 引擎、文件格式或数据库检索。
- 提供电解质、SFE、用户定义组分向导的资源页面和导航。用户定义向导的空 ID 阻止前进，返回保留输入；空案例 SFE 没有可选组分；生成反应/组分及完成操作需要引擎，保持不可用。后续步骤布局来自静态资源，尚未逐步核对原版生成行为。
- 全局单位菜单与设置页双向同步。数据库列表支持本地移动和排序，按钮随选择和边界启用；不更改原版数据库。
- 从安装资源补充 173 份去重图像、285 处引用（包括快捷按钮、页面插图及公式）。`ui/icons/recovered.json` 保留资源路径、原始哈希和未解决引用。原有 97 图标图集保持独立。

## 原版直接观察

观察对象为 `Simulation 2 - Aspen Plus V15 - aspenONE` 的物性模式空案例。

| 页面/操作 | 实际观察 |
| --- | --- |
| 设置 → 规定 | 全局、描述、记录、诊断、注释五个标签；全局显示标题、单位、有效相态、自由水 |
| 有效相态 | 仅汽相、仅液相、汽-液、汽-液-液；空案例未选择 |
| 自由水 | 否、是、污水；当前为否 |
| 方法 → 规定 | 物性方法和选项直接显示，无预览器附加的“条件分组”标签；真实组分勾选；模型修改区初始灰显，数据集为 1 |
| 方法过滤器 | COMMON、BIOCONV、CHEMICAL、COALPROC、ELECTROL、ENVIRON、GASPROC、HF-ACID、METAL、OIL-GAS、PETCHEM、PHARMA、POLYMER、POWER、REFINERY、SYNFUEL、WATER |
| COMMON 基本方法 | BK10、CHAO-SEA、CPA、ELECNRTL、ENRTL-RK、ENRTL-SR、IAPWS-95、IDEAL、NRTL、NRTL-SAC、PC-SAFT、PENG-ROB、POLYNRTL、PSRK、SOLIDS、SRK、UNIFAC、UNIQUAC、VTPR、WILSON |
| 自由水方法 | IAPWS-95、IDEAL、IF97、RTOSTM、STEAM-TA、STEAMNBS、STMNBS2、SYSOP0，以及新建入口；当前 STEAM-TA |
| 水溶度 | 0–5；当前 3 |
| 方法助手 | 打开原版帮助窗口中的 Property Method Selection Assistant；不是独立计算向导 |

全部观察的文字记录（可读取时）留在本机 `.local/interaction-evidence/`，完整桌面图不上传。选项与覆盖规则在 `ui/interactions.json`；图像提取可运行 `tools/recover_ui_images.py --root "C:/Program Files/AspenTech"`，需 dnfile、pefile、Pillow。

## 尚待核对

这次没有把 2,947 个布局解释为 2,947 个完整交互页面。涉及引擎、许可证、对象创建或案例数据的控件仍有缺口，包括其他方法过滤器的具体方法集合、模型修改后的联动、原生菜单的全部命令、流程图绘图以及源目录里 11 个无独立布局的 ContentType。它们继续保留来源和不可用提示，未伪造模拟结果。

观察期间桌面重新失去可操作性：`GetCursorPos / 0x80070005`，随后激活失败；重新枚举窗口后截图报 `IGraphicsCaptureItemInterop.CreateForMonitor / 0x80070057`。已请求恢复交互桌面，未使用旧坐标继续操作。

## 验证

Windows Qt 6.8.3 / MinGW 13.1 构建；测试检查图片资源、可编辑输入和跨页状态隔离、全局单位同步、页面历史、向导输入门槛与返回、弹窗打开/关闭、原有组分页，以及全部恢复布局/对话框/菜单创建。额外执行 Python 资源解析测试与目录引用校验。渲染图保存在 `.local/rendered/interactions/`。
