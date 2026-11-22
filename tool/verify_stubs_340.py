# -*- coding: utf-8 -*-
"""Parse an AMD64 COFF object and verify the recompiled fixup stubs.

For every symbol named fixup_stub_<site> the verifier requires:
  * the symbol lives in .text;
  * its first instruction is exactly 6 bytes FF 25 <rel32> (jmp qword ptr [rip+disp32]);
  * exactly one relocation sits at offset +2, type IMAGE_REL_AMD64_REL32 (0x0004);
  * that relocation targets the symbol fixup_slot_<slot>, i.e. the very slot the
    original instruction jumps through.
The linker therefore fills disp = slot - (stub + 6): the recompiled stub keeps the
original indirect tail-jump semantics at any placement.
"""
import struct


def _name(raw, start, strings, base):
    if raw[start:start + 4] == b"\0\0\0\0":
        off = struct.unpack_from("<I", raw, start + 4)[0]
        end = raw.index(b"\0", base + off)
        return raw[base + off:end].decode("utf-8", "replace")
    return raw[start:start + 8].split(b"\0")[0].decode("utf-8", "replace")


def parse(path):
    raw = open(path, "rb").read()
    if raw[:2] != b"d\x86":
        raise ValueError("not an AMD64 COFF object: machine %s" % raw[:2].hex())
    nsec = struct.unpack_from("<H", raw, 2)[0]
    symptr, nsym = struct.unpack_from("<II", raw, 8)
    opt = struct.unpack_from("<H", raw, 16)[0]
    secs = []
    for i in range(nsec):
        base = 20 + opt + 40 * i
        name = raw[base:base + 8].split(b"\0")[0].decode("utf-8", "replace")
        vsize, vaddr, rsize, rptr, relptr, lptr, nrel, lrel = struct.unpack_from("<IIIIIIHH", raw, base + 8)
        secs.append(dict(name=name, vsize=vsize, rsize=rsize, rptr=rptr, relptr=relptr, nrel=nrel))
    strtab = symptr + 18 * nsym
    syms = []
    by_index = {}
    i = 0
    while i < nsym:
        base = symptr + 18 * i
        nm = _name(raw, base, raw, strtab)
        val, secnum, typ, cls, naux = struct.unpack_from("<IhHBB", raw, base + 8)
        by_index[i] = dict(name=nm, value=val, section=secnum, type=typ, storage=cls, index=i)
        syms.append(by_index[i])
        i += 1 + naux
    relocs = {}
    for si, s in enumerate(secs):
        out = []
        for k in range(s["nrel"]):
            base = s["relptr"] + 10 * k
            va, symidx, rtype = struct.unpack_from("<IIH", raw, base)
            out.append(dict(offset=va, symbol=symidx, type=rtype,
                            name=by_index[symidx]["name"] if symidx in by_index else ""))
        relocs[si] = out
    return dict(raw=raw, secs=secs, syms=syms, relocs=relocs)


def verify(path, expected):
    """expected: {site_int: slot_int}.  Returns (results, failures)."""
    obj = parse(path)
    results, failures = [], []
    text = next((i for i, s in enumerate(obj["secs"]) if s["name"] == ".text"), None)
    if text is None:
        return [], [{"error": "no .text section"}]
    sec = obj["secs"][text]
    blob = obj["raw"][sec["rptr"]:sec["rptr"] + max(sec["vsize"], sec["rsize"])]
    rel_by_off = {r["offset"]: r for r in obj["relocs"][text]}
    seen = set()
    for sym in obj["syms"]:
        if not sym["name"].startswith("fixup_stub_") or sym["section"] != text + 1:
            continue
        site = int(sym["name"].rsplit("_", 1)[1], 16)
        seen.add(site)
        code = blob[sym["value"]:sym["value"] + 6]
        rec = dict(site="0x%X" % site, symbol=sym["name"], bytes=code.hex())
        problems = []
        if len(code) != 6 or code[0] != 0xFF or code[1] != 0x25:
            problems.append("first instruction is not a 6-byte jmp qword ptr [rip+disp32]")
        rel = rel_by_off.get(sym["value"] + 2)
        if rel is None:
            problems.append("no relocation at instruction+2")
        else:
            rec["reloc_type"] = "0x%04X" % rel["type"]
            rec["reloc_symbol"] = rel["name"]
            if rel["type"] != 0x0004:
                problems.append("relocation type is not REL32")
            slot = expected.get(site)
            want = "fixup_slot_%08X" % slot if slot is not None else None
            if want is None:
                problems.append("site not in expected map")
            elif rel["name"] != want:
                problems.append("relocation target %s != %s" % (rel["name"], want))
        rec["ok"] = not problems
        rec["problems"] = problems
        results.append(rec)
        if problems:
            failures.append(rec)
    missing = sorted(set(expected) - seen)
    for site in missing:
        failures.append(dict(site="0x%X" % site, problems=["no compiled symbol"]))
    return results, failures


if __name__ == "__main__":
    import json, sys
    sys.stdout.reconfigure(encoding="utf-8")
    obj = sys.argv[1]
    exp = {}
    for pair in sys.argv[2:]:
        a, b = pair.split(":")
        exp[int(a, 0)] = int(b, 0)
    res, bad = verify(obj, exp)
    print("verified", len(res) - len(bad), "of", len(exp), "failures", len(bad))
    for b in bad[:5]:
        print(b)
