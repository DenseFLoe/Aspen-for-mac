import collections
import contextlib
import io
import json
import re
import struct
import sys
from pathlib import Path
from types import SimpleNamespace

from compare import logical_lines, parse_source_line, operands, project, root

sys.path.insert(0, str(root / "deps"))
import pcodedmp.pcodedmp as pc

NUMBER = re.compile(r"(?i)(?<!\w)(?:&H[0-9a-f]+|(?:\d+(?:\.\d*)?|\.\d+)(?:[Ee][+-]?\d+)?)(?:[!#%&^@])?(?!\w)")
CALL = re.compile(r"^(?:ArgsCall|ArgsMemCall|ArgsMemCallWith|ArgsLd|ArgsMemLd|ArgsMemLdWith)\b.* (\w+) 0x[0-9A-F]+$")
FUNCTION = re.compile(r"(?i)^(Public|Private) (Sub|Function) (\w+)\((.*)\)(?: As (\w+))?$")
VARIABLE = re.compile(r"(?i)^(Optional )?(ByVal |ByRef )?(\w+) As (\w+)(?: = (.*))?$")
BRANCHES = {
    "for each": "ForEach", "for": "For", "next": "NextVar", "do until": "DoUnitil",
    "loop": "Loop", "elseif": "ElseIfBlock", "else": "ElseBlock", "end if": "EndIfBlock",
    "if": "IfBlock", "select case": "SelectCase", "case else": "CaseElse", "case": "Case",
    "end select": "EndSelect", "on error": "OnError", "exit sub": "ExitSub",
    "end sub": "EndSub", "end function": "EndFunc", "stop": "Stop",
}
CONTROL = re.compile(r"(?i)^(?:" + "|".join(BRANCHES) + r")\b")
MODULE = re.compile(r"VBA/(.+) - \d+ bytes")
LINE = re.compile(r"Line #(\d+):")

def number(token):
    token = token.rstrip("!#%&^@")
    if token[:2].lower() == "&h":
        return int(token[2:], 16)
    return float(token) if any(c in token for c in ".Ee") else int(token)

def pcode_numeric(op):
    opcode, *words = op.split()
    if opcode not in ("LitDI2", "LitDI4", "LitR8"):
        return None
    raw = b"".join(int(word, 16).to_bytes(2, "little") for word in words)
    return struct.unpack("<d", raw)[0] if opcode == "LitR8" else int.from_bytes(raw, "little", signed=True)

def decode_cache():
    assert project["vba_cache_version"] == "0xb5"
    original_get_id, original_function = pc.getID, pc.disasmFunc
    signature_records = []
    corrected_internal = collections.Counter()

    def get_id(word, identifiers, version, is_64_bit):
        assert version == 7 and is_64_bit
        index = (word >> 1) - 0x107
        if 0xBE < index < len(identifiers):
            return identifiers[index]
        if word == 0x00DE:
            corrected_internal[word] += 1
            return "Len"
        return original_get_id(word, identifiers, version, is_64_bit)

    def function(table, declarations, identifiers, offset, op_type, endian, version, is_64_bit):
        rendered = original_function(table, declarations, identifiers, offset, op_type, endian, version, is_64_bit)
        name = pc.getName(table, identifiers, offset + 2, endian, version, is_64_bit)
        cursor = pc.getDWord(table, offset + 56, endian)
        args = []
        seen = set()
        return_slot = None
        while cursor not in (0, 0xFFFFFFFF):
            assert 0 < cursor <= len(table) - 32 and cursor not in seen
            seen.add(cursor)
            ident = pc.getWord(table, cursor + 2, endian)
            descriptor = pc.getDWord(table, cursor + 16, endian)
            options = pc.getWord(table, cursor + 28, endian)
            previous, cursor = cursor, pc.getDWord(table, cursor + 24, endian)
            type_name = pc.getTypeName(descriptor & 0xFF) if descriptor >> 16 == 0xFFFF else None
            if ident == 0xFFFE:
                assert cursor == 0xFFFFFFFF
                return_slot = type_name
                continue
            type_record = None if type_name else table[descriptor:descriptor + 8].hex()
            args.append({"name": get_id(ident, identifiers, version, is_64_bit),
                         "optional": bool(options & 0x200), "byval": bool(options & 4),
                         "builtin_type": type_name, "custom_type_record": type_record,
                         "arg_record": hex(previous)})
        signature_records.append({"name": name, "args": args, "return_slot": return_slot,
                                  "rendered": rendered, "record": hex(offset)})
        return rendered

    pc.getID, pc.disasmFunc = get_id, function
    output, errors = io.StringIO(), io.StringIO()
    try:
        with contextlib.redirect_stderr(errors):
            pc.processFile(str(root.parent / "input" / "vbaProject.bin"),
                           SimpleNamespace(disasmOnly=True, verbose=False), output_file=output)
        assert not errors.getvalue(), "P-code decoder emitted errors"
    finally:
        pc.getID, pc.disasmFunc = original_get_id, original_function
    assert corrected_internal == {0x00DE: 5}
    modules = {}
    for line in output.getvalue().splitlines():
        if match := MODULE.fullmatch(line):
            assert match[1] not in modules
            block = modules[match[1]] = []
        elif match := LINE.fullmatch(line):
            assert int(match[1]) == len(block)
            block.append([])
        elif line.startswith("\t"):
            op = line.strip()
            assert not op.startswith(("Unrecognized", "Illegal", "Error"))
            block[-1].append(op)
    return modules, iter(signature_records)

def verify():
    modules, records = decode_cache()
    layout = []
    for spec in project["modules"]:
        name = spec["name"]
        code_file = root / "stage" / "source" / spec["filename"]
        source = logical_lines(code_file, project["codec"])
        counts = collections.Counter()
        checks = []
        runs = []
        current = None
        descriptors = collections.defaultdict(set)
        for index, ((first, last, line), ops) in enumerate(zip(source, modules[name], strict=True)):
            code, comment, strings = parse_source_line(line)
            sanitized = re.sub(r'"(?:[^"]|"")*"', '""', code)
            counts["logical_lines"] += 1
            counts["lines_with_instructions"] += bool(ops)
            counts["executable_or_declaration_lines"] += bool(code)
            counts["comments"] += int(comment is not None)
            counts["string_literals"] += len(strings)
            assert operands(ops, "QuoteRem") == ([] if comment is None else [comment]), (name, first)
            assert collections.Counter(operands(ops, "LitStr")) == collections.Counter(strings), (name, first)
            op_names = [op.split()[0] for op in ops]
            assert bool(code) == bool(set(op_names) - {"QuoteRem"}), (name, first)

            act_numbers = [n for op in ops if (n := pcode_numeric(op)) is not None]
            if code.startswith("Option "):
                assert len(ops) == 1 and ops[0].replace("  ", " ") == f"Option ({code[7:]})"
                exp_numbers = []
            else:
                exp_numbers = [number(token[0]) for token in NUMBER.finditer(sanitized)]
            assert collections.Counter(exp_numbers) == collections.Counter(act_numbers), (name, first)
            counts["numeric_literals"] += len(act_numbers)

            calls = [m[1] for op in ops if (m := CALL.match(op))]
            assert all(re.search(rf"(?i)\b{re.escape(call)}\b", sanitized) for call in calls), (name, first)
            counts["call_and_index_operands"] += len(calls)
            if branch := CONTROL.match(sanitized):
                assert BRANCHES[branch[0].lower()] in op_names, (name, first)
                counts["control_statements"] += 1
                if branch[0].lower() == "on error":
                    assert ops[0] == f"OnError ({code[9:]})", (name, first)

            definition = FUNCTION.fullmatch(code)
            assert bool(definition) == ("FuncDefn" in op_names), (name, first)
            if definition:
                visibility, kind, method, arguments, returns = definition.groups()
                record = next(records)
                assert method.casefold() == record["name"].casefold(), (name, method)
                assert kind + " " in record["rendered"], (name, method)
                assert (visibility == "Public") == ("Public " in record["rendered"]), (name, method)
                if returns:
                    assert record["rendered"].endswith(f" As {returns})") and record["return_slot"] in (
                        None, returns), (name, method)
                else:
                    assert record["return_slot"] is None, (name, method)
                args = [VARIABLE.fullmatch(arg.strip()).groups() for arg in arguments.split(",")] if arguments else []
                declared = []
                for (optional, mode, label, vba_type, default), a in zip(args, record["args"], strict=True):
                    assert a["name"].casefold() == label.casefold(), (name, method, label)
                    assert a["optional"] == bool(optional), (name, method, label)
                    assert a["byval"] == (mode == "ByVal "), (name, method, label)
                    if a["builtin_type"]:
                        assert a["builtin_type"].casefold() == vba_type.casefold(), (name, method, label)
                    else:
                        assert a["custom_type_record"]
                        descriptors[vba_type].add(a["custom_type_record"])
                    declared.append({"name": label, "type_in_source": vba_type, "optional": bool(optional),
                                     "passing_mode": "ByVal" if mode == "ByVal " else "ByRef",
                                     "default_in_source": default, **a})
                current = {"name": method, "source_first_line": first, "pcode_first_line_zero_based": index,
                           "compiled_interface_offset": record["record"], "arguments": declared}
                runs.append(current)
                counts["procedures"] += 1
                counts["parameters"] += len(declared)
            if code in ("End Sub", "End Function"):
                assert current is not None
                current["source_last_line"] = last
                current["pcode_last_line_zero_based"] = index
                current = None
            if op_names and (first != last or definition or code.startswith(("On Error ", "Err.Raise ")) or
                             set(op_names) & {"Open", "Close", "PrintChan", "Stop"}):
                checks.append({"source_first_line": first, "source_last_line": last,
                               "pcode_line_zero_based": index, "opcodes": op_names, "calls": calls})
        assert current is None
        row = {"module": spec, "counts": counts, "procedures": runs, "key_pcode_lines": checks,
               "custom_type_records_by_source_type": {k: sorted(v) for k, v in descriptors.items()}}
        print(name, dict(counts), {k: len(v) for k, v in descriptors.items()})
        layout.append(row)
    assert next(records, None) is None
    (root / "coverage.json").write_text(json.dumps(layout, ensure_ascii=False, indent=2), encoding="utf-8")

if __name__ == "__main__":
    verify()


