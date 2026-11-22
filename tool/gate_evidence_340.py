# -*- coding: utf-8 -*-
"""Derive the 0x21AE guard evidence table from bytes, with fault injection.

The table is a pure function of the input bytes: condition code, compare operand,
the AL immediate of each branch, the consumer branch, the section-header
Characteristics and the resulting skip decision are all decoded, never asserted.

Fault injection rewrites one opcode/operand in a bytearray copy and re-runs the
same decoder, which is what proves the generator follows the original instead of
remembering conclusions.
"""
import argparse, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import x86_340 as X  # noqa: E402

CMP = 0x28F3
JCC = 0x28F7
XOR_AL = 0x28F9
MOV_AL = 0x28FD
TEST_AL = 0x2195
JZ = 0x2197
SLOT = 0x19B78


def table(data, pe, slot=SLOT):
    """Decode the guard into a flat evidence table (no conclusions baked in)."""
    g = X.gate_facts(data, pe, slot, CMP, JCC, TEST_AL, JZ)
    cmp_ins = X.decode(data, pe, CMP)
    jcc_ins = X.decode(data, pe, JCC)
    jz_ins = X.decode(data, pe, JZ)
    return {
        "cmp_addr": "0x%X" % CMP,
        "cmp_operand": "dword ptr [%s+0x%X]" % (cmp_ins["reg"], cmp_ins["disp"]),
        "cmp_disp": "0x%X" % cmp_ins["disp"],
        "cmp_imm": "0x%X" % cmp_ins["imm"],
        "cmp_value_signed": g["cmp_value"],
        "condition": g["predicate"],
        "jcc_addr": "0x%X" % JCC,
        "jcc_opcode": "0x%02X" % data[pe.filepos(JCC)],
        "jcc_cc": jcc_ins["cc"],
        "jcc_target": "0x%X" % jcc_ins["target"],
        "jcc_fallthrough": "0x%X" % (JCC + jcc_ins["len"]),
        "taken_al": g["taken_return"],
        "taken_at": g["taken_at"],
        "fallthrough_al": g["fallthrough_return"],
        "fallthrough_at": g["fallthrough_at"],
        "consumer_test_addr": "0x%X" % TEST_AL,
        "consumer_jz_addr": "0x%X" % JZ,
        "consumer_jz_target": "0x%X" % jz_ins["target"],
        "consumer_skip_when_al_zero": jz_ins["cc"] == "jz",
        "section_name": g["section"]["name"],
        "section_rva": g["section"]["rva"],
        "section_characteristics": g["section"]["characteristics"],
        "section_characteristics_signed": g["section"]["signed"],
        "section_characteristics_write_bit": bool(int(g["section"]["characteristics"], 16) & 0x80000000),
        "page_protection": "runtime only (VirtualProtect/VirtualQuery); not encoded in the file",
        "al_immediates": {"0x%X" % (X.decode(data, pe, a)["addr"]): X.decode(data, pe, a)["value"]
                          for a in (XOR_AL, MOV_AL) if X.decode(data, pe, a)["kind"] == "mov_al"},
        "al_for_slot": g["al_for_slot"],
        "slot_skipped": g["slot_skipped"],
        "positive_branch": g["positive_branch"],
        "skip_branch": g["skip_branch"],
    }


def inject(data, cc=None, al_imm=None):
    """Patch the condition-code opcode or the AL immediate in a byte copy."""
    buf = bytearray(data)
    pe = PE(bytes(buf))
    if cc:
        rev = {v: k for k, v in X.JCC.items()}
        if cc not in rev:
            raise ValueError("unsupported injected condition code %r" % cc)
        buf[pe.filepos(JCC)] = rev[cc]
    if al_imm is not None:
        if not 0 <= al_imm <= 0xFF:
            raise ValueError("AL immediate out of range")
        p = pe.filepos(MOV_AL)
        if buf[p] != 0xB0:
            raise ValueError("expected mov al,imm8 at 0x%X" % MOV_AL)
        buf[p + 1] = al_imm
    return bytes(buf)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    ap.add_argument("--out", default="")
    ap.add_argument("--expect-skip", choices=("0", "1"), default="")
    a = ap.parse_args()
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    base = table(data, pe)
    inj_cc = table(inject(data, cc="jl"), PE(inject(data, cc="jl")))
    d2 = inject(data, al_imm=2)
    inj_al = table(d2, PE(d2))
    out = {"baseline": base, "inject_cc_jl": inj_cc, "inject_al_imm_2": inj_al}
    if a.out:
        Path(a.out).write_text(json.dumps(out, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print(json.dumps(out, ensure_ascii=False, indent=1))
    if a.expect_skip and str(base["slot_skipped"]).lower() != ("true" if a.expect_skip == "1" else "false"):
        print("EXPECTATION FAILED: slot_skipped=%s" % base["slot_skipped"], file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
