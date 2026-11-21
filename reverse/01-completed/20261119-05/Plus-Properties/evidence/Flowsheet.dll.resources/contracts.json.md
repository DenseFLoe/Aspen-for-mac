# contracts.json

- 来源：C:\Program Files\AspenTech\AprSystem V15.0\GUI\Xeq\WPFForms\AspenTech.AspenPlus.MMForms.Flowsheet.dll + C:\Program Files\AspenTech\AprSystem V15.0\GUI\Xeq\WPFForms\en-US\AspenTech.AspenPlus.MMForms.Flowsheet.resources.dll；文件/程序集版本与源指纹见 index.json 的 inputs。仅已安装件，包身份交由主任务。
- 此件范围及状态：MMControls 与 Localization 的两处外部签名边界；限本机此哈希的资源静态核对，非整 DLL 验收。
- 成果：4804 字节；SHA-256：5718926da4e8af9474b350caae3eb5a3ff0ff86e2faef700bca339efd09d8f3b。
- 复核：Cecil 精确匹配继承 info_var 和每个引用的 ApwnResources 静态 getter；不读取外部业务实现。执行 README.md 所列只读验证；SHA256SUMS 收录本件及说明。
- 边界及下一步：参考依赖的静态证据，不对其作整件验收。不实例化界面控件、不验证实际宿主、外观或业务执行；后续由整件任务决定验收。
