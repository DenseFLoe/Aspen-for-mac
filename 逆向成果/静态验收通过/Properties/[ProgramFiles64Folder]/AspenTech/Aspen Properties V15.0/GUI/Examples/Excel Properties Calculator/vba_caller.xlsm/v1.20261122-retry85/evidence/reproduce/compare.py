import collections
import json
import re
from pathlib import Path

root = Path(__file__).resolve().parent
project = json.loads((root / "structure.json").read_text(encoding="utf-8"))
MODULE = re.compile(r"VBA/(.+) - \d+ bytes")
LINE = re.compile(r"Line #(\d+):")
PROCEDURE = re.compile(r"(?i)^\s*(?:(?:Public|Private|Friend|Static)\s+)?(Sub|Function)\s+(\w+)")
STRING = re.compile(r'"(?:[^"]|"")*"')
TOKEN = re.compile(r'''"(?:[^"]|"")*"|'.*$''')

def parse_pcode():
    modules = {}
    for line in (root / "pcode.private.txt").read_text(encoding="utf-8").splitlines():
        if match := MODULE.fullmatch(line):
            name = match[1]
            assert name not in modules
            module = modules[name] = []
        elif match := LINE.fullmatch(line):
            assert int(match[1]) == len(module)
            module.append([])
        elif line.startswith("\t"):
            op = line.strip()
            assert not op.startswith(("Unrecognized", "Illegal", "Error")), op
            module[-1].append(op)
    return modules

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

def verify():
    pcode = parse_pcode()
    for spec in project["modules"]:
        name = spec["name"]
        stage = root / "stage" / "source" / spec["filename"]
        source = list(logical_lines(stage, project["codec"]))
        compiled = pcode[name]
        assert len(source) == len(compiled), name
        counters = collections.Counter()
        diffs = collections.defaultdict(list)
        for (start, end, line), ops in zip(source, compiled):
            code, comment, strings = parse_source_line(line)
            op_names = [op.split(" ", 1)[0] for op in ops]
            p_strings = operands(ops, "LitStr")
            p_comments = operands(ops, "QuoteRem")
            if sorted(p_strings) != sorted(strings):
                diffs["literal"].append(start)
            counters["strings"] += len(strings)
            if p_comments != ([] if comment is None else [comment]):
                diffs["comment"].append(start)
            counters["comments"] += int(comment is not None)
            match = PROCEDURE.match(code)
            p_def = [op for op in ops if op.startswith("FuncDefn (")]
            if bool(match) != bool(p_def):
                diffs["definition"].append(start)
            if match:
                counters["procedures"] += 1
                print("  proc", start, match[2], p_def[0].split("(")[1].split()[-1] if p_def else "none")
            blank = not code and not ops
            counters["pcode_nonempty"] += bool(ops)
            if bool(code) != bool(set(op_names) - {"QuoteRem"}):
                diffs["code_line"].append(start)
            if end > start:
                counters["continuations"] += end - start
        print(name, len(source), dict(counters), dict(diffs))

if __name__ == "__main__":
    verify()

