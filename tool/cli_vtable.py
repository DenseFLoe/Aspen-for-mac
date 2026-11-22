# -*- coding: utf-8 -*-
"""CLR VTableFixups reader for mixed-mode PE images (ECMA-335 II.24.2.3).

The fixup table lives in the CLI header field (offset +0x30: RVA, Size) and is
mirrored by PE data directory 15.  Both are read; a mismatch is reported instead
of silently trusting one of them.  Every entry is {RVA, Count, Type}; Type bits
COR_VTABLE_32BIT(1)/COR_VTABLE_64BIT(2) decide the slot width (4 or 8 bytes), so
the slot contents can be decoded as method tokens without guessing.

Each slot value is then resolved against the MethodDef table.  A value is a
"target" only when it is a MethodDef token (0x06xxxxxx) with a valid row.
"""
import struct

WIDTH = {0x1: 4, 0x2: 8}


def _width(typ):
    """Slot width from the COR_VTABLE_* bits (1=32-bit, 2=64-bit)."""
    if typ & 0x1:
        return 4
    if typ & 0x2:
        return 8
    return 0


def cli_header(data, pe):
    cli = pe.directory(14)[0]
    if not cli:
        raise ValueError("no CLI header (PE data directory 14 is empty)")
    return pe.filepos(cli)


def read(data, pe, methods=None):
    """Read the fixup table.  Returns dict with entries, targets and provenance.

    methods: optional {token: {...}} MethodDef map used for token resolution.
    """
    pos = cli_header(data, pe)
    hdr_rva, hdr_size = struct.unpack_from("<II", data, pos + 0x30)
    dir_rva, dir_size = pe.directory(15)
    notes = []
    if (hdr_rva, hdr_size) != (dir_rva, dir_size):
        notes.append("CLI header VTableFixups %#x/%#x != data directory 15 %#x/%#x"
                     % (hdr_rva, hdr_size, dir_rva, dir_size))
    rva, size = (hdr_rva, hdr_size) if hdr_rva else (dir_rva, dir_size)
    if not rva or not size:
        return dict(entries=[], targets=[], source="none", notes=notes + ["VTableFixups is empty"])
    if size % 8:
        raise ValueError("VTableFixups size %#x is not a multiple of 8" % size)
    base = pe.filepos(rva)
    entries, invalid = [], []
    for i in range(size // 8):
        er, count, typ = struct.unpack_from("<IHH", data, base + 8 * i)
        width = _width(typ)
        rec = dict(index=i, rva=er, count=count, type=typ, width=width,
                   slots=[], tokens=[], resolved=[])
        if not width:
            rec["error"] = "type %#x has neither 32-bit nor 64-bit width bit" % typ
            invalid.append(rec)
            entries.append(rec)
            continue
        if not count:
            rec["error"] = "count 0"
            invalid.append(rec)
            entries.append(rec)
            continue
        try:
            slot_pos = pe.filepos(er)
        except ValueError:
            rec["error"] = "slot RVA %#x is outside file-backed sections" % er
            invalid.append(rec)
            entries.append(rec)
            continue
        end = slot_pos + count * width
        if end > len(data):
            rec["error"] = "slot run %#x+%d*%d crosses EOF" % (er, count, width)
            invalid.append(rec)
            entries.append(rec)
            continue
        for k in range(count):
            if width == 8:
                v = struct.unpack_from("<Q", data, slot_pos + 8 * k)[0]
            else:
                v = struct.unpack_from("<I", data, slot_pos + 4 * k)[0]
            rec["slots"].append(v)
            rec["tokens"].append(v)
        entries.append(rec)
    targets, unresolved = [], []
    for rec in entries:
        if rec.get("error"):
            continue
        for k, tok in enumerate(rec["tokens"]):
            row = methods.get(tok) if methods else None
            if row is None:
                unresolved.append(dict(entry=rec["index"], slot=k, token=tok,
                                       reason="token is not a MethodDef row"))
                continue
            targets.append(dict(entry=rec["index"], slot=k, token=tok, rva=row["rva"],
                                flavor=row["flavor"], name=row["name"]))
    return dict(entries=entries, targets=targets, unresolved=unresolved,
                invalid=[r for r in entries if r.get("error")],
                source="cli-header" if hdr_rva else "data-dir-15",
                rva=rva, size=size, notes=notes)


def _fake(methods_fixups=None):
    """4 KiB fake image: CLI header at RVA 0x800, fixup slots at RVA 0x1000."""
    class FakePE:
        def directory(self, i):
            return (0x1100, len(methods_fixups) * 8) if i == 15 else (0x800, 0x48)

        def filepos(self, rva):
            if 0x800 <= rva < 0x900:
                return 0x100 + rva - 0x800
            if 0x1000 <= rva < 0x1200:
                return 0x400 + rva - 0x1000
            raise ValueError("outside file-backed sections")

    data = bytearray(0x1000)
    struct.pack_into("<II", data, 0x100 + 0x30, 0x1100, len(methods_fixups) * 8)
    for i, rec in enumerate(methods_fixups):
        struct.pack_into("<IHH", data, 0x500 + 8 * i, rec[0], rec[1], rec[2])
    return bytes(data), FakePE()


def self_test(methods):
    """Negative controls: samples that must NOT count as fixup targets, plus one
    positive control so the control itself is not vacuous."""
    results = []
    tok = sorted(methods)[0]

    # 1. all-zero entry: type has no width bit, count 0 -> rejected, no target
    data, pe = _fake([(0x1000, 0, 0), (0x1000, 0, 0)])
    got = read(data, pe, methods)
    results.append(("zeroed entries yield 0 targets",
                    len(got["targets"]) == 0 and len(got["invalid"]) == 2))

    # 2. slot RVA outside every file-backed section -> rejected, never counted
    data, pe = _fake([(0x9000, 1, 8)])
    got = read(data, pe, methods)
    results.append(("out-of-image slot RVA rejected",
                    len(got["targets"]) == 0 and len(got["invalid"]) == 1))

    # 3. type without a width bit (0) must not be decoded
    data, pe = _fake([(0x1000, 1, 0)])
    got = read(data, pe, methods)
    results.append(("type 0 rejected", len(got["invalid"]) == 1 and not got["targets"]))

    # 4. TypeRef token 0x01000001 in a slot is NOT a method target
    data, pe = _fake([(0x1000, 1, 2)])
    data = bytearray(data)
    struct.pack_into("<Q", data, 0x400, 0x01000001)
    got = read(bytes(data), pe, methods)
    results.append(("TypeRef token not a target",
                    len(got["targets"]) == 0 and len(got["unresolved"]) == 1))

    # 5. count 0 with a valid type bit -> rejected
    data, pe = _fake([(0x1000, 0, 2)])
    got = read(data, pe, methods)
    results.append(("count 0 rejected", len(got["invalid"]) == 1 and not got["targets"]))

    # 6. positive control: the same slot with a real MethodDef token resolves
    data, pe = _fake([(0x1000, 1, 2)])
    data = bytearray(data)
    struct.pack_into("<Q", data, 0x400, tok)
    got = read(bytes(data), pe, methods)
    results.append(("MethodDef token resolves (positive control)",
                    len(got["targets"]) == 1 and got["targets"][0]["token"] == tok))
    return results
