import json
import re
from pathlib import Path

root = Path(__file__).resolve().parent
project = json.loads((root / "structure.json").read_text(encoding="utf-8"))
TOKEN = re.compile(r'''"(?:[^"]|"")*"|'.*$''')

def logical_lines(path, codec):
    current = []
    start = None
    for index, text in enumerate(path.read_bytes().decode(codec).splitlines(), start=1):
        if text.startswith("Attribute "):
            continue
        if start is None:
            start = index
        if text.rstrip().endswith(" _"):
            current.append(text.rstrip()[:-2])
            continue
        current.append(text)
        yield start, index, " ".join(current)
        start = None
        current.clear()
    assert not current

def parse_source_line(line):
    tokens = list(TOKEN.finditer(line))
    comment = tokens.pop()[0][1:] if tokens and tokens[-1][0].startswith("'") else None
    code = line if comment is None else line[:-(len(comment) + 1)]
    return code.strip(), comment, [m[0][1:-1].replace('""', '"') for m in tokens]

def operands(ops, mnemonic):
    values = []
    match = re.compile(rf'{mnemonic} 0x[0-9A-F]+(?: 0x[0-9A-F]+)? "(.*)"$')
    for op in ops:
        if m := match.fullmatch(op):
            values.append(m[1])
    return values


