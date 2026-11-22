# check-appid-tail.py

项目现有 COFF 回填逻辑的局部调用入口。额外核对两个字符串、入口参数搬运与异常目录。

原件 ApwnIPShell.dll 版本 41.0.0.614，SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。基线 `e3b3049622bbefa9241099561a8fadd35a9b25c1`。范围属 NATIVE-342 s29 部分静态验收。
