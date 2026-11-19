# AspenTech.AspenPlus.MMForms.Flowsheet.dll · instructions.il

本轮：20261119-05；判定：已完成（限原件逐文件归档）。Plus 与独立 Properties 共用，版本 41.0.0.614。原安装路径：C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Flowsheet.dll。原始 SHA-256：aba9d5c58c1cbe4d0ee5584ea7c36ee8dd8be4196816c919151895adfe8b2bac。逐包来源、容器和成员：本轮 identity.json；语言资源来源：satellite-identity.json。

本份范围：逐方法原始 IL、操作数字节、异常处理及外部声明。

验收依据：117 个方法定义逐令牌对照：115 个 IL 实现及 2 个原生 COM 接口声明，无遗漏；核对 2,245 条指令、6 个异常区、238 个成员引用。3 个外置 BAML 的 445 条记录逐字节复原，11 处接线、8 个绑定与代码对应；原版无窗口探针两次各通过 111 项断言。

复核入口：主件及卫星来源：identity.json、satellite-identity.json。总复核：independent.json、interop-boundary.json、messages.json。代码：flowsheet-code/methods.tsv 和 verify.py；布局：flowsheet-resources/index.json、relationships.json、audit.py --verify；原版探针：flowsheet-probes/Replay.ps1 与对应 pair 目录的两份结果。

成果路径：.local/reverse-round-20261119-05/01-completed/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Flowsheet.dll.instructions.il；SHA-256：6ec0b97adda8f41e690de2de842bdffa3a30d4cf005a5a8dda6bae3316826b58。

缺口、边界与下一步：仅验收本哈希的原版逐文件恢复。真实宿主交互、模型写回、实际删除/COM 导出及像素表现未测；资源卫星和外部程序集不另计完成。下一阶段在真实 Windows 宿主对照，本轮不启动重建。 
