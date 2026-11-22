"""Check the editable bodies, two host CFGs, and four chained unwind entries."""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

import capstone as cs
from capstone import x86
import pefile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent


def table(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def verify(original, compiler):
    previous = json.loads((ROOT/"reassembly.json").read_text(encoding="utf-8"))
    delta = json.loads((HERE/"reassembly-delta.json").read_text(encoding="utf-8"))
    data = original.read_bytes()
    assert hashlib.sha256(data).hexdigest() == previous["original_sha256"] == delta["original_sha256"]
    command = [sys.executable, "-B", str(ROOT/"reassemble.py"), str(original), str(compiler)]
    actual = json.loads(subprocess.check_output(command))
    expected = sorted(previous["matches"] + delta["matches"], key=lambda r: int(r["rva"], 16))
    assert actual["matches"] == expected
    assert (actual["bodies"], actual["bytes"], actual["relocations"]) == (185, 145008, 5322)
    pe = pefile.PE(data=data)
    im = pe.get_memory_mapped_image()
    pdata = {e.struct.BeginAddress:e.struct for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    dis = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_64)
    dis.detail = True
    evidence = table(HERE/"host-flow.csv")
    assert len(evidence) == 250
    for start, children, end in [(0x2ee0, (0x2f05, 0x302b), 0x3033),
                                  (0x22da0, (0x22df6, 0x2300a), 0x23025)]:
        assert [pdata[x].EndAddress for x in [start, *children]] == [*children, end]
        for child in children:
            uw = pdata[child].UnwindData
            assert im[uw]>>3 & 4
            tail = uw + 4 + 4 * ((im[uw + 2] + 1)//2)
            assert struct.unpack_from("<III", im, tail) == (start, pdata[start].EndAddress, pdata[start].UnwindData)
        instructions = {i.address:i for i in dis.disasm(im[start:end], start)}
        rows = [r for r in evidence if int(r["owner"], 0) == start]
        assert len(rows) == len(instructions) and set(map(lambda r:int(r["instruction"],0),rows)) == set(instructions)
        graph = {}
        for row in rows:
            pos = int(row["instruction"], 0)
            ins = instructions[pos]
            assert (row["bytes"], row["mnemonic"], row["operands"]) == (ins.bytes.hex(), ins.mnemonic, ins.op_str)
            assert row["entry_kind"] == ("entry" if pos == start else "CHAININFO" if pos in children else "")
            successors = []
            if ins.group(cs.CS_GRP_JUMP):
                assert ins.operands[0].type == x86.X86_OP_IMM
                successors.append(ins.operands[0].imm)
            if not ins.group(cs.CS_GRP_RET) and ins.mnemonic != "jmp":
                successors.append(pos + ins.size)
            assert successors == [int(x,0) for x in row["successors_in_body"].split()]
            graph[pos] = successors
        seen = set()
        pending = [start]
        while pending:
            pos = pending.pop()
            if pos not in seen:
                seen.add(pos)
                pending.extend(graph[pos])
        assert seen == set(instructions)
    coverage = {r["key"]:r["state"] for r in table(ROOT/"coverage.csv")}
    prior = table(HERE/"prior-gaps.csv")
    assert len(prior) == len({r["entry"] for r in prior}) == 23
    assert all(coverage[r["entry"]] == r["current_state"] for r in prior)
    assert sum(r["current_state"] == "gap" for r in prior) == 17
    transfers = {(r["caller"],r["listing"],r["callee"]) for r in table(ROOT/"calls.csv") if r["class"] == "unresolved"}
    carried = {(r["owner"],r["listing"],r["operand"]) for r in table(HERE/"prior-indirect.csv")}
    assert transfers == carried and len(carried) == 15
    print("185 bodies, 145008 bytes, 5322 relocations; 250 reachable instructions; four CHAININFO matches; 17 gaps, 15 unresolved")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("compiler", type=Path)
    args = parser.parse_args()
    verify(args.original, args.compiler)
