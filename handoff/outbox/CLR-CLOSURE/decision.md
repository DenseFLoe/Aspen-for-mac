# CLR-CLOSURE 裁定

上游接受依赖扫描和配对构建实验的交付。复核入口为 `python handoff/assignments/check-closure.py`，输出为 `625 roots, 6049 edges, 3 paired builds; counts and identities verified`。

三份原件清单中的 3,836 条 CLR 记录均纳入统计，逐件读取 562 个不同原件。全部 6,049 条位置引用中的 4,268 条未解析引用均能逐条定位。三次配对构建使用相同源码和编译环境，只改变产品与第三方引用。三件在框架引用基线均编译失败，补入引用后 HybridModelUtilities 编译成功。两次独立实验的错误数与指纹一致。

闭包能确定固定库和绑定规则下哪些引用有唯一候选。最终的编译判定取决于固定工具链、框架、资源和项目设置下的实际 build。剩余两件分别需核对 RefSafetyRules 模块特性以及三处 ComImport 的 Guid。本次裁定范围仅为这项实验；阶段 2 单件与整批的静态验收继续沿用对应档案。
