# -*- coding: utf-8 -*-
"""Tiny AMD64 reader for the 0x21AE guard sequence (no hard-coded conclusions).

Only the instruction forms that appear in the two windows are decoded:

  83 /7 ib          cmp  dword ptr [reg+disp8], imm8
  7x / 0F 8x        jcc  rel8 / rel32
  32 C0             xor  al, al
  B0 ib             mov  al, imm8
  84 C0             test al, al
  EB / E9           jmp  rel8 / rel32
  75 / 74           jnz / jz rel8
  C3                ret

callers derive the branch destinations, the AL value each path returns, and the
section characteristics from these decodes - never from a literal in the script.
"""
import struct

JCC = {0x74: "jz", 0x75: "jnz", 0x7C: "jl", 0x7D: "jge", 0x7E: "jle", 0x7F: "jg",
       0x72: "jc", 0x73: "jnc", 0x76: "jbe", 0x77: "ja"}
JCC32 = {0x84: "jz", 0x85: "jnz", 0x8C: "jl", 0x8D: "jge", 0x8E: "jle", 0x8F: "jg"}


def decode(data, pe, rva):
    p = pe.filepos(rva)
    b = data[p:p + 12]
    op = b[0]
    if op == 0xC3:
        return dict(addr=rva, len=1, text="ret")
    if op == 0x83 and len(b) >= 4 and (b[1] & 0xC0) == 0x40 and (b[1] & 0x38) == 0x38:
        # cmp dword ptr [reg+disp8], imm8  (mod=01, reg=7, rm=reg)
        reg = ["rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi"][b[1] & 7]
        return dict(addr=rva, len=4, text="cmp dword ptr [%s+0x%X], 0x%X" % (reg, b[2], b[3]),
                    kind="cmp_mem_imm", reg=reg, disp=b[2], imm=b[3])
    if op in JCC:
        tgt = rva + 2 + struct.unpack_from("<b", b, 1)[0]
        return dict(addr=rva, len=2, text="%s 0x%X" % (JCC[op], tgt), kind="jcc", cc=JCC[op], target=tgt)
    if op == 0x0F and b[1] in JCC32:
        tgt = rva + 6 + struct.unpack_from("<i", b, 2)[0]
        return dict(addr=rva, len=6, text="%s 0x%X" % (JCC32[b[1]], tgt), kind="jcc", cc=JCC32[b[1]], target=tgt)
    if op == 0x32 and b[1] == 0xC0:
        return dict(addr=rva, len=2, text="xor al,al", kind="mov_al", value=0)
    if op == 0xB0:
        return dict(addr=rva, len=2, text="mov al,0x%X" % b[1], kind="mov_al", value=b[1])
    if op == 0x84 and b[1] == 0xC0:
        return dict(addr=rva, len=2, text="test al,al", kind="test_al")
    if op == 0xEB:
        tgt = rva + 2 + struct.unpack_from("<b", b, 1)[0]
        return dict(addr=rva, len=2, text="jmp 0x%X" % tgt, kind="jmp", target=tgt)
    if op == 0xE9:
        tgt = rva + 5 + struct.unpack_from("<i", b, 1)[0]
        return dict(addr=rva, len=5, text="jmp 0x%X" % tgt, kind="jmp", target=tgt)
    return dict(addr=rva, len=1, text="db 0x%02X" % op, kind="other")


def walk(data, pe, rva, stop):
    """Linear decode from rva until stop rva (inclusive) or a ret/jmp outside."""
    out, cur, guard = [], rva, 0
    while cur <= stop and guard < 64:
        ins = decode(data, pe, cur)
        out.append(ins)
        cur += ins["len"]
        guard += 1
        if ins["kind"] == "jmp" and not (rva <= ins["target"] <= stop):
            break
        if ins["kind"] == "other" and ins["text"].startswith("db"):
            break
    return out


def path_return(data, pe, start, window=0x40):
    """Follow one branch from start to the first mov-al before leaving the window."""
    cur, guard = start, 0
    stop = start + window
    while rva_in(start, stop, cur) and guard < 32:
        ins = decode(data, pe, cur)
        if ins["kind"] == "mov_al":
            return ins["value"], cur
        if ins["kind"] == "jmp":
            return None, cur
        cur += ins["len"]
        guard += 1
    return None, cur


def rva_in(a, b, x):
    return a <= x <= b


def gate_facts(data, pe, slot_rva, cmp_addr, jcc_addr, test_addr, jz_addr):
    """Derive the guard semantics from the bytes themselves."""
    cmp_ins = decode(data, pe, cmp_addr)
    jcc = decode(data, pe, jcc_addr)
    test = decode(data, pe, test_addr)
    jz = decode(data, pe, jz_addr)
    taken_val, taken_at = path_return(data, pe, jcc["target"])
    fall_val, fall_at = path_return(data, pe, jcc_addr + jcc["len"])
    sec = next(s for s in pe.secs if s["rva"] <= slot_rva < s["rva"] + max(s["size"], s.get("vsize", 0)))
    chars = struct.unpack_from("<I", data, sec["hdr"] + 36)[0]      # IMAGE_SECTION_HEADER.Characteristics
    signed = chars - (1 << 32) if chars & 0x80000000 else chars
    # the decoded predicate: jge (signed >= 0) takes the branch that returns taken_val
    predicate = "%s: signed(Characteristics) %s 0 -> return %s" % (
        jcc["cc"], ">=" if jcc["cc"] == "jge" else "?", taken_val)
    al_for_slot = taken_val if signed >= 0 else fall_val
    # consumer: test al,al + jz -> skip when al == 0
    skip_when_zero = jz["cc"] == "jz"
    skipped = (al_for_slot == 0 and skip_when_zero) or (al_for_slot != 0 and not skip_when_zero)
    return dict(
        cmp=cmp_ins["text"], cmp_disp="0x%X" % cmp_ins["disp"],
        jcc=dict(cc=jcc["cc"], addr="0x%X" % jcc["addr"], target="0x%X" % jcc["target"],
                 fallthrough="0x%X" % (jcc["addr"] + jcc["len"])),
        taken_return=taken_val, taken_at="0x%X" % taken_at,
        fallthrough_return=fall_val, fallthrough_at="0x%X" % fall_at,
        test=test["text"], jz=dict(cc=jz["cc"], addr="0x%X" % jz["addr"], target="0x%X" % jz["target"],
                                   fallthrough="0x%X" % (jz["addr"] + jz["len"])),
        section=dict(name=sec["name"], rva="0x%X" % sec["rva"], characteristics="0x%X" % chars,
                     signed=signed, writable=bool(chars & 0x80000000)),
        predicate=predicate, al_for_slot=al_for_slot,
        slot_skipped=skipped,
        positive_branch="0x%X-0x%X" % (jz["addr"] + jz["len"], jz["target"] - 1),
        skip_branch="0x%X" % jz["target"])
