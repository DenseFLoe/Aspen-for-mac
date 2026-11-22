# check-callbacks.py

读取 SHA-256 固定的 Ikc2Bkp.dll，与同目录父级的原件地址范围逐址核对异常作用域、R9 到 RAX 的传递和两个可写数据字段。用 Python 3.12、Capstone 和 pefile 运行 `python -B s25/check-callbacks.py ORIGINAL`。页内读写和指针扫描的覆盖范围见 [机器输出](callbacks.json)。
