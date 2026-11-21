# AspenTech.AspenCxs.dll 的 C# 源码

第 20261119-16 轮通过整件静态验收。Aspen Plus 和 Aspen Properties 的安装包分别以 File 序号 1736、1373 安装此库到 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenCxs.dll`。版本为 41.0.0.57，原件大小为 265,256 字节。两包原成员及共用安装件的 SHA-256 均为 `84fdfccb7a92901d723ef284490cfe88d64c22758aeb75b2a2f6876255b57206`。源码 SHA-256 为 `901803d23c0e4ee87b4135e44b8662a78b84ba572bf41d5570374e32c3810c5b`。

本件提供案例操作、节点读写、求解请求及消息读取接口。ILSpy 9.1.0.7988 导出整件 C#。以原始元数据令牌核对 164 个顶层类型、4 个嵌套类型及模块定义，覆盖 671 个字段、385 个属性和 9 个事件。旧档选取的 8 个顶层类型合计 238 个方法定义。

1,654 个方法定义中有 1,480 个 IL 实现、170 个抽象声明、4 个 OLE 外部调用。1,295 个实现可由源码序列点定位，140 个自动属性访问器核对了字段和操作指令，另有 45 个折叠实现按令牌附在文件末尾。逐项核对 40,791 条 IL 指令、197 个 finally 和 113 个 catch。两处条件抛出 NotImplementedException 的分支可在原件指令中定位。

13 个导入类型的 100 个方法和访问器均保留原顺序。静态检查时修正 32/64 位注册表分支中的同名局部变量。Roslyn 语法与语义检查为零错误，5 个未使用变量警告和 1 条未使用 using 的隐藏提示保存在 focused-checks.json。3 个属性的编辑器绑定、2 个下拉列表与各自的点击处理已核对。字符串及版本资源的恢复与逐字节核验详见同目录的两份资源说明。

本轮 evidence 中的 identity.json 记录安装来源，code-coverage.json 和 focused-checks.json 按令牌给出源码、声明和折叠成员依据。逐指令 IL 和 il-coverage.json 存于本机轮次 evidence。Windows 重建阶段再验证案例操作、COM 调度、事件以及不同程序集版本间的实际绑定。
