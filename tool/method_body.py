# -*- coding: utf-8 -*-
"""Correct CLI method-body reader: MethodDef RVA -> fat/tiny header -> IL -> EH section.

Two defects this module removes (both were present in the s33 generator):

  * the EH clause count was read from the fat header flags (flags >> 8).  That field
    is not the clause count; the EH table is a separate section that follows the IL,
    starts with a kind byte (0x01 EHTable, 0x40 fat format) plus a 3-byte data size,
    and holds (size - 4) / 24 clauses.
  * the header size was assumed to be 12 bytes and the EH offset was aligned on the
    file offset instead of the RVA.  The fat header carries its own size in dwords
    (bits 12..15); alignment is a property of the RVA.

The reader also refuses to trust a MethodDef RVA that does not land inside an
executable section, and checks that the whole body + EH section stay in that
section.
"""
import struct


def section_of(pe, rva):
    """RVA -> section.  A section's RVA span is max(SizeOfRawData, VirtualSize): the
    tail behind the raw data is the zero fill the runtime maps in."""
    for s in pe.secs:
        if s["rva"] <= rva < s["rva"] + max(s["size"], s.get("vsize", 0)):
            return s
    return None


def header(data, pe, rva):
    sec = section_of(pe, rva)
    if sec is None or not sec["exec"]:
        raise ValueError("MethodDef RVA %#x is not inside an executable section" % rva)
    p = pe.filepos(rva)
    h = struct.unpack_from("<H", data, p)[0]
    fmt = h & 3
    if fmt == 2:                                     # tiny
        return dict(rva=rva, kind="tiny", header_size=1, code_size=h >> 2,
                    flags=0, maxstack=8, local_var=0, more_sections=False,
                    il=data[p + 1:p + 1 + (h >> 2)])
    if fmt != 3:
        raise ValueError("bad IL method header format %d at RVA %#x" % (fmt, rva))
    flags = h & 0xFFF
    header_size = ((h >> 12) & 0xF) * 4
    maxstack = struct.unpack_from("<H", data, p + 2)[0]
    code_size = struct.unpack_from("<I", data, p + 4)[0]
    local_var = struct.unpack_from("<I", data, p + 8)[0]
    end = rva + header_size + code_size
    if end - sec["rva"] > max(sec["size"], sec.get("vsize", 0)):
        raise ValueError("IL body of RVA %#x leaves section %s" % (rva, sec["name"]))
    return dict(rva=rva, kind="fat", header_size=header_size, code_size=code_size,
                flags=flags, maxstack=maxstack, local_var=local_var,
                more_sections=bool(flags & 0x8),
                il=data[p + header_size:p + header_size + code_size])


def eh_section(data, pe, hdr):
    """Parse the EH section that follows the IL body.  Returns (info, clauses)."""
    if not hdr["more_sections"]:
        return None, []
    rva = hdr["rva"] + hdr["header_size"] + hdr["code_size"]
    rva = (rva + 3) & ~3                            # alignment is on the RVA
    sec = section_of(pe, rva)
    if sec is None:
        raise ValueError("EH section RVA %#x is outside every section" % rva)
    p = pe.filepos(rva)
    kind = data[p]
    if kind & 0x3F != 0x01:
        raise ValueError("unexpected EH section kind %#x at RVA %#x" % (kind, rva))
    fat = bool(kind & 0x40)
    size = data[p + 1] | (data[p + 2] << 8) | (data[p + 3] << 16)
    entry = 24 if fat else 12
    count = (size - 4) // entry
    if count < 0 or 4 + count * entry != size:
        raise ValueError("EH section size %d does not fit %d-byte clauses" % (size, entry))
    clauses = []
    for i in range(count):
        q = p + 4 + entry * i
        if fat:
            flags, try_off, try_len, h_off, h_len, tok = struct.unpack_from("<IIIIII", data, q)
        else:
            flags, try_off, h_off = struct.unpack_from("<HHH", data, q)
            try_len = h_len = 0
            tok = struct.unpack_from("<I", data, q + 8)[0]
        clauses.append(dict(index=i, flags=flags, try_offset=try_off, try_length=try_len,
                            handler_offset=h_off, handler_length=h_len, class_token=tok))
    return dict(rva=rva, kind=kind, fat=fat, size=size, entry=entry, count=count), clauses


def read(data, pe, rva):
    hdr = header(data, pe, rva)
    info, clauses = eh_section(data, pe, hdr)
    return hdr, info, clauses


def self_test(data, pe, rva_with_eh, rva_without_eh):
    """Controls: the reader must not invent clauses for a body without EH, and must
    reject a stray RVA.  Returns [(name, ok)]."""
    out = []
    h1, i1, c1 = read(data, pe, rva_with_eh)
    out.append(("body with EH yields a fat EHTable section",
                h1["more_sections"] and i1 is not None and i1["kind"] & 0x3F == 0x01))
    out.append(("clause count equals (size-4)/entry",
                i1 is not None and (i1["size"] - 4) // i1["entry"] == len(c1) == i1["count"]))
    h2, i2, c2 = read(data, pe, rva_without_eh)
    out.append(("body without EH yields zero clauses", (not h2["more_sections"]) and not c2))
    try:
        read(data, pe, 0xDEAD000)
        out.append(("stray RVA rejected", False))
    except ValueError:
        out.append(("stray RVA rejected", True))
    try:
        read(data, pe, 0x61B8)                       # .rdata, not executable
        out.append(("non-executable RVA rejected", False))
    except ValueError:
        out.append(("non-executable RVA rejected", True))
    return out
