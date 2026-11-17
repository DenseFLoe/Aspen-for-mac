# Flash2 字段、单位与下一步实施

2026-11-17，工作分支 `codex/flash2-input-guidance`，继承研究提交 `8fa281b`。

## 字段里程碑

进料 MATERIAL 和 Flash2 输入页接入独立 `ProcessInput` 规则及专用编辑器。对象 `processInput` 保存版本、温度、绝对压力、总摩尔流量及按数据库/实体身份索引的摩尔分率；全局 `process` 保存明确选定的 NRTL/IDEAL 方法。输入字符串和单位分别保存，允许保存未完成草稿。旧 `inputs` 与 `unverifiedInputs` 保留，不自动猜测字段含义。

当前温度使用 K、绝对压力使用 Pa、流量使用 mol/s。校验拒绝空值、非有限数值、非正绝对温压/总流量、超界摩尔分率及和不为 1 的组成（容差 1e-8）。组分移除后旧组成保留并报错，可明确移除失效项。产品/中间流股由上游求解，不能填写成独立进料。方法选择仅表示输入规定，未确认参数齐备或计算支持。

验证覆盖模型的缺失/非法/边界值、版本结构、保存重开、撤销重做和旧输入保留；UI 验证正在编辑温度时保存，以及方法撤销重做。该里程碑不具备物性或 Flash2 求解器。


## 单位里程碑

温度支持 K/C/F；绝对压力支持 Pa/kPa/bar/atm/psia；总摩尔流量支持 mol/s、kmol/hr、lbmol/hr。ENG 映射 F/psia/lbmol/hr，MET 映射 C/atm/kmol/hr，METCBAR 映射 C/bar/kmol/hr，SI 映射 K/Pa/mol/s。单字段选择和全局切换均转换数值，空值继续为空；非法数值阻止转换并保留原输入。全局转换先验证全部已接入对象，成功后一次保存到项目，可整体撤销。

参考案例核对：185 F = 358.15 K；200 F = 366.4833333333333 K；50 psia = 344737.864658418 Pa；100 lbmol/hr = 12.59978805555556 mol/s。用 17 位有效数字保存转换值；100 轮 F/K/C 往返误差检查限值 1e-10 K。未接入业务语义的旧页面仍只保存其单位显示，不能视为全软件字段已完成换算。

字段提交 `02b838f` 已推送；Windows CTest 4/4 通过（123.72 秒），字段、方法恢复与保留原页面结构专项 5 passed。macOS Actions [44034900320](https://github.com/DenseFLoe/Aspen-for-mac/actions/runs/44034900320) 成功。

单位里程碑 Windows 完整编译通过；process-input CTest 通过，单位切换/撤销/非法值保护与字段保存 UI 专项 4 passed。
