# -*- coding: utf-8 -*-
"""Correct CLI method-body reader: MethodDef RVA -> fat/tiny header -> IL -> data sections.

Defects this module removes (all were present in the s33 generator):

  * the EH clause count was read from the fat header flags (flags >> 8).  That field
    is not the clause count; the EH table is a separate data section that follows
    the IL, starts with a kind byte (0x01 EHTable, 0x40 fat format, 0x80 MoreSects)
    plus a 3-byte data size, and holds (size - 4) / 24 (fat) or /12 (small) clauses.
  * the header size was assumed to be 12 bytes and the EH offset was aligned on the
    file offset instead of the RVA.
  * only one section was read.  A body may chain several data sections (the 0x80
    bit says "another section follows"); each is read and every declared range is
    validated against the IL body.  A section kind outside this reader's support is
    reported with its exact RVA/kind/size and the unit is not judged further.
"""
import struct

EHTABLE = 0x01
OPTIL = 0x02
SUPPORTED = (EHTABLE, OPTIL)


class UnsupportedSection(ValueError):
    """A data section kind this reader does not implement; carries its exact range."""

    def __init__(self, rva, kind, size):
        self.rva, self.kind, self.size = rva, kind, size
        super().__init__("unsupported data section kind 0x%02X at RVA 0x%X (size %d); "
                         "supported kinds: 0x01 EHTable, 0x02 OptIL" % (kind, rva, size))


# ECMA-335 II.25.4.1 CorILMethod flags (method header, 16-bit word):
#   CorILMethod_TinyFormat 0x2, CorILMethod_FatFormat 0x3,
#   CorILMethod_MoreSects 0x8, CorILMethod_InitLocals 0x10.
CORILMETHOD_MORESECTS = 0x8
# ECMA-335 II.25.4.5 COR_ILMETHOD_SECT (per data-section kind byte):
#   bits 0..5 Kind (0x01 EHTable), bit 0x40 FatFormat, bit 0x80 MoreSects.
SECT_FATFORMAT = 0x40
SECT_MORESECTS = 0x80
SECT_KIND_MASK = 0x3F


def section_of(pe, rva):
    """RVA -> section; a section spans max(SizeOfRawData, VirtualSize)."""
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
                more_sections=bool(flags & CORILMETHOD_MORESECTS),
                il=data[p + header_size:p + header_size + code_size])


def _clauses(data, p, kind, size):
    fat = bool(kind & SECT_FATFORMAT)
    entry = 24 if fat else 12
    if size < 4 or (size - 4) % entry:
        raise ValueError("data section size %d does not fit %d-byte clauses" % (size, entry))
    out = []
    for i in range((size - 4) // entry):
        q = p + 4 + entry * i
        if fat:
            flags, toff, tlen, hoff, hlen, tok = struct.unpack_from("<IIIIII", data, q)
        else:
            flags, toff, tlen, hoff, hlen, tok = struct.unpack_from("<HHBHB I", data, q)
        out.append(dict(index=i, flags=flags, try_offset=toff, try_length=tlen,
                        handler_offset=hoff, handler_length=hlen, class_token=tok))
    return fat, out


def data_sections(data, pe, hdr):
    """Read every chained data section.

    Two different bits control this, and they live in different structures:
      * method header flags  CorILMethod_MoreSects = 0x8  -> data sections exist;
      * each section's kind byte  COR_ILMETHOD_SECT MoreSects = 0x80 -> another follows.
    """
    if not hdr["more_sections"]:
        return []
    rva = (hdr["rva"] + hdr["header_size"] + hdr["code_size"] + 3) & ~3
    out, guard = [], 0
    while True:
        sec = section_of(pe, rva)
        if sec is None:
            raise ValueError("data section RVA %#x is outside every section" % rva)
        p = pe.filepos(rva)
        kind = data[p]
        size = data[p + 1] | (data[p + 2] << 8) | (data[p + 3] << 16)
        base = kind & SECT_KIND_MASK
        if base not in SUPPORTED:
            raise UnsupportedSection(rva, kind, size)
        rec = dict(rva=rva, kind=kind, fat=bool(kind & SECT_FATFORMAT), size=size,
                   more=bool(kind & SECT_MORESECTS), base=base)
        if base == EHTABLE:
            rec["fat"], rec["clauses"] = _clauses(data, p, kind, size)
            for c in rec["clauses"]:
                if (c["try_offset"] + c["try_length"] > hdr["code_size"] or
                        c["handler_offset"] + c["handler_length"] > hdr["code_size"]):
                    raise ValueError("clause %d range outside the IL body (code size %d)"
                                     % (c["index"], hdr["code_size"]))
        out.append(rec)
        guard += 1
        if not rec["more"] or guard > 8:
            break
        rva += size
    return out


def read(data, pe, rva):
    hdr = header(data, pe, rva)
    secs = data_sections(data, pe, hdr)
    eh = next((s for s in secs if s["base"] == EHTABLE), None)
    return hdr, eh, (eh["clauses"] if eh else [])


class _FakePE:
    def __init__(self, data, sections):
        self.data = data
        self.secs = sections

    def filepos(self, rva):
        for s in self.secs:
            if s["rva"] <= rva < s["rva"] + max(s["size"], s.get("vsize", 0)):
                return s["raw"] + rva - s["rva"]
        raise ValueError("RVA %#x outside" % rva)


def _synthetic(kind1, kind2=None, clause=None, try_len=4, handler_off=3, handler_len=1,
               hdr_flags=None):
    data = bytearray(0x4000)
    sec = dict(rva=0x1000, size=0x1000, raw=0x1000, vsize=0x1000, hdr=0x80, exec=True, name=".text")
    struct.pack_into("<I", data, 0x80 + 36, 0x60000020)
    pe = _FakePE(data, [sec])
    body = 0x1000
    code = bytes([0x00, 0x2A, 0x00, 0x00])
    flags = hdr_flags if hdr_flags is not None else (0x0B if kind1 else 0x03)
    struct.pack_into("<H", data, body, (3 << 12) | flags)
    struct.pack_into("<H", data, body + 2, 8)
    struct.pack_into("<I", data, body + 4, len(code))
    struct.pack_into("<I", data, body + 8, 0)
    data[body + 12:body + 12 + len(code)] = code
    q = (body + 12 + len(code) + 3) & ~3
    for kind in (kind1, kind2):
        if not kind:
            break
        entry = 24 if kind & 0x40 else 12
        size = 4 + entry
        data[q] = kind
        data[q + 1:q + 4] = bytes([size & 0xFF, (size >> 8) & 0xFF, (size >> 16) & 0xFF])
        if kind & 0x3F == EHTABLE:
            if kind & 0x40:
                struct.pack_into("<IIIIII", data, q + 4, 2, 0, try_len, handler_off, handler_len, 0x01000001)
            else:
                struct.pack_into("<HHBHB I", data, q + 4, 2, 0, try_len, handler_off, handler_len, 0x01000001)
        q += size
    return bytes(data), pe


def synthetic_tests():
    out = []
    for name, k1, k2 in (("fat", 0x41, None), ("small", 0x01, None),
                         ("fat|0x80 + small", 0xC1, 0x01), ("small|0x80 + fat", 0x81, 0x41)):
        data, pe = _synthetic(k1, k2)
        h, eh, cl = read(data, pe, 0x1000)
        ok = eh is not None and len(cl) == 1 and cl[0]["flags"] == 2 and cl[0]["try_length"] == 4
        if k2:
            secs = data_sections(data, pe, h)
            ok = ok and len(secs) == 2 and secs[1]["base"] == (k2 & 0x3F)
        out.append(("EH %s parsed (chained=%s)" % (name, bool(k2)), ok))
    data, pe = _synthetic(0x00)
    h, eh, cl = read(data, pe, 0x1000)
    out.append(("MoreSects clear -> no data section", eh is None and not cl and h["more_sections"] is False))
    # header bit must be 0x8, not 0x80: flags=0x83 has 0x80 set and 0x8 clear
    data, pe = _synthetic(0x41, hdr_flags=0x83)
    h, eh, cl = read(data, pe, 0x1000)
    out.append(("header uses CorILMethod_MoreSects 0x8, not 0x80",
                h["more_sections"] is False and eh is None and not cl))
    # chaining must come from the section kind byte 0x80, not from the header alone
    data, pe = _synthetic(0x41, 0x01)                 # first kind 0x41 has no 0x80
    h, eh, cl = read(data, pe, 0x1000)
    secs = data_sections(data, pe, h)
    out.append(("section chain stops when kind lacks 0x80", len(secs) == 1 and secs[0]["more"] is False))
    data, pe = _synthetic(0x41, try_len=0x40)
    try:
        read(data, pe, 0x1000)
        out.append(("try range outside IL rejected", False))
    except ValueError:
        out.append(("try range outside IL rejected", True))
    data, pe = _synthetic(0x41, handler_off=0x30)
    try:
        read(data, pe, 0x1000)
        out.append(("handler range outside IL rejected", False))
    except ValueError:
        out.append(("handler range outside IL rejected", True))
    data, pe = _synthetic(0x43)                      # 0x03 is not a supported kind
    try:
        read(data, pe, 0x1000)
        out.append(("unsupported kind reported with its range", False))
    except UnsupportedSection as exc:
        want = (0x1000 + 12 + 4 + 3) & ~3
        msg = str(exc).upper()
        out.append(("unsupported kind reported with its range",
                    exc.rva == want and exc.kind == 0x43 and "0X%X" % want in msg
                    and "0X43" in msg and "SIZE %d" % exc.size in msg))
    data, pe = _synthetic(0x41)
    q = 0x1000 + 12 + 4
    q = (q + 3) & ~3
    data = bytearray(data)
    struct.pack_into("<I", data, q + 1, 16)           # size says 16, fat needs 28
    try:
        read(bytes(data), pe, 0x1000)
        out.append(("inconsistent section size rejected", False))
    except ValueError:
        out.append(("inconsistent section size rejected", True))
    return out


def self_test(data, pe, rva_with_eh, rva_without_eh):
    out = []
    h1, i1, c1 = read(data, pe, rva_with_eh)
    out.append(("body with EH yields an EHTable section",
                h1["more_sections"] and i1 is not None and i1["base"] == EHTABLE))
    out.append(("clause count equals (size-4)/entry",
                i1 is not None and len(c1) == (i1["size"] - 4) // (24 if i1["fat"] else 12)))
    h2, i2, c2 = read(data, pe, rva_without_eh)
    out.append(("body without EH yields zero clauses", (not h2["more_sections"]) and not c2))
    try:
        read(data, pe, 0xDEAD000)
        out.append(("stray RVA rejected", False))
    except ValueError:
        out.append(("stray RVA rejected", True))
    try:
        read(data, pe, 0x61B8)
        out.append(("non-executable RVA rejected", False))
    except ValueError:
        out.append(("non-executable RVA rejected", True))
    return out
