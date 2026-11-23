# NATIVE-337 s85 裁定

原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ fedc23d](https://github.com/DenseFLoe/Aspen-for-mac/tree/fedc23d69963d80b423f4e467efbf68da383ff43)。主干基线 6f39d81802e8d60331c0c6706f192ae7d45ac52a。

固定原件覆盖 v1 实测 307／307／684／0，退出 2，112 条仍未决。原件 0x1389 的机器级参数依次为 this、IID_NULL、名字数组、1、LCID、DISPID 输出地址。交付的说明及表漏掉 IID_NULL，错移其余参数。原件只证实 VariantInit 调用、24 字节元素步幅及显式写入 VT_BSTR 与入参指针。s73 枚举的 FF /4 修正成立，s65 实际分类入口仍收同位移 INC。另在本机同 SHA 安装中固定了组件绑定，接口和类的 ShowDialog(string dialogName) 均返回 int32，运行期 DISPID 来源为 GetIDsOfNames。

裁定 returned。覆盖命令、输入和实测见[复验记录](s85-verifier-notes.md)。交付复验证据 SHA-256 6a27bc18c8ea92ff153211c6cadb45454431d8c54f9547babd4871d9d9612769。

[开工回执](../../inbox/NATIVE-337/s85-started.md) · [交付回执](../../inbox/NATIVE-337/s85-submission.md) · [续领卡](../../assignments/NATIVE-337-s89.md)
