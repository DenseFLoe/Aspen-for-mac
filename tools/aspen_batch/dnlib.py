"""Minimal CLR metadata/IL helper layer on top of dnfile (pure-python reader).

Used by the log4net.dll static-analysis scripts. No Ghidra required.
"""
import struct, dnfile



def u16(b, o): return struct.unpack_from("<H", b, o)[0]
def u32(b, o): return struct.unpack_from("<I", b, o)[0]
def u64(b, o): return struct.unpack_from("<Q", b, o)[0]


class Asm:
    def __init__(self, path):
        self.path = path
        with open(path, "rb") as f:
            self.raw = f.read()
        self.dn = dnfile.dnPE(path)
        self.net = self.dn.net
        self.md = self.net.mdtables
        self.image = self.dn.get_memory_mapped_image()
        self._build_methods()
        self._build_types()
        self.streams = self._parse_streams()

    # ---------- basic PE/CLR ----------
    def pe_info(self):
        dn = self.dn
        fh = dn.FILE_HEADER
        oh = dn.OPTIONAL_HEADER
        clr = dn.DIRECTORY_ENTRY_COM_DESCRIPTOR.struct
        out = {
            "size": len(self.raw),
            "machine": hex(fh.Machine),
            "machine_name": {0x14c: "i386", 0x8664: "amd64", 0xaa64: "arm64"}.get(fh.Machine, hex(fh.Machine)),
            "subsystem": oh.Subsystem,
            "image_base": hex(oh.ImageBase),
            "checksum": hex(oh.CheckSum),
            "sections": [(s.Name.split(b"\x00")[0].decode("ascii", "replace"), hex(s.VirtualAddress), s.Misc_VirtualSize, s.SizeOfRawData, hex(s.PointerToRawData)) for s in dn.sections],
            "clr": {
                "rva": dn.DIRECTORY_ENTRY_COM_DESCRIPTOR.struct.get_file_offset() if False else None,
                "cb": clr.cb,
                "runtime_version": (clr.MajorRuntimeVersion, clr.MinorRuntimeVersion),
                "flags": hex(clr.Flags),
                "entry_point_token": hex(clr.EntryPointTokenOrRva),
                "metadata_rva": hex(clr.MetaDataRva),
                "metadata_size": clr.MetaDataSize,
                "resources_rva": hex(clr.ResourcesRva),
                "resources_size": clr.ResourcesSize,
                "strongname_rva": hex(clr.StrongNameSignatureRva),
                "strongname_size": clr.StrongNameSignatureSize,
            },
            "data_dirs": [(i, d.VirtualAddress, d.Size) for i, d in enumerate(oh.DATA_DIRECTORY) if d.Size],
        }
        return out

    def _parse_streams(self):
        rva = self.net.struct.MetaDataRva
        base = self.rva2off(rva)
        sig = self.raw[base:base+4]
        assert sig == b"BSJB", sig
        major, minor = u16(self.raw, base+4), u16(self.raw, base+6)
        resv = u32(self.raw, base + 8)
        verlen = u32(self.raw, base+12)
        ver = self.raw[base+16:base+16+verlen].rstrip(b"\x00").decode("ascii", "replace")
        off = base + 16 + verlen
        off = (off + 3) & ~3
        mdflags = u16(self.raw, off)
        nstreams = u16(self.raw, off+2); off += 4
        streams = []
        for _ in range(nstreams):
            so, ss = u32(self.raw, off), u32(self.raw, off+4)
            off += 8
            end = self.raw.index(b"\x00", off)
            name = self.raw[off:end].decode("ascii", "replace")
            off = (end + 4) & ~3
            streams.append({"name": name, "offset": so, "size": ss, "file_offset": base+so,
                            "rva": rva + so})
        return {"version_string": ver, "major": major, "minor": minor, "flags": mdflags,
                "reserved": resv, "streams": streams, "file_offset": base}

    def rva2off(self, rva):
        return self.dn.get_offset_from_rva(rva)

    # ---------- symbols ----------
    def _build_types(self):
        self.types = self.md.TypeDef.rows
        self.typemap = {}   # method row idx (0-based) -> typedef row idx
        for ti, t in enumerate(self.types):
            for m in t.MethodList:
                self.typemap[m.row_index - 1] = ti

    def _build_methods(self):
        self.methods = self.md.MethodDef.rows
        self._midx = {r.struct.get_file_offset(): i for i, r in enumerate(self.methods)}

    def method_index(self, row):
        return self._midx[row.struct.get_file_offset()]

    def type_name(self, ti):
        t = self.types[ti]
        ns = t.TypeNamespace.value if t.TypeNamespace else ""
        nm = t.TypeName.value
        # nested?
        return (ns + "." if ns else "") + nm

    def method_name(self, mi):
        m = self.methods[mi]
        ti = self.typemap.get(mi)
        owner = self.type_name(ti) if ti is not None else "<global>"
        return owner + "::" + m.Name.value

    def method_token(self, mi):
        return 0x06000000 | (mi + 1)

    # ---------- signatures ----------
    def sig_blob(self, heapitem):
        return bytes(heapitem.value) if hasattr(heapitem, "value") else bytes(heapitem)

    def method_sig_text(self, mi):
        """return (calling_conv, ret, [param types], generic_arity) from blob."""
        blob = self.sig_blob(self.methods[mi].Signature)
        return parse_methsig(self, blob)

    def params(self, mi):
        m = self.methods[mi]
        out = []
        for p in (m.ParamList or []):
            r = p.row
            out.append({"name": r.Name.value if r.Name else "", "flags": r.struct.Flags,
                        "seq": r.struct.Sequence})
        return out

    # ---------- tokens ----------
    def type_ref_name(self, row):
        ns = row.TypeNamespace.value if row.TypeNamespace else ""
        return (ns + "." if ns else "") + row.TypeName.value

    def resolve_method_token(self, tok):
        t = tok >> 24
        idx = (tok & 0xFFFFFF) - 1
        if t == 0x06:
            return self.method_name(idx), 0x06000000
        if t == 0x0A:
            mr = self.md.MemberRef.rows[idx]
            cls = mr.Class
            cname = self.memberref_parent_name(cls)
            return "%s::%s" % (cname, mr.Name.value), 0x0A000000
        if t == 0x2B:
            ms = self.md.MethodSpec.rows[idx]
            base = ms.Method
            inner, _ = self.resolve_method_token(ms.Method.row_index) if False else (None, None)
            # dnfile: Method is a MethodDefOrRef coded index
            tt = ms.Method.table
            if tt is not None:
                nm = "%s::%s" % (self.type_ref_name(ms.Method.row) if False else "", "")
            return self._resolve_coded_method(ms.Method), 0x2B000000
        return "token_%08X" % tok, t

    def _resolve_coded_method(self, coded):
        row = coded.row
        tbl = type(row).__name__.replace("Row", "")
        if tbl == "MethodDef":
            return self.method_name(self.method_index(row))
        if tbl == "MemberRef":
            return "%s::%s" % (self.memberref_parent_name(row.Class), row.Name.value)
        return "<%s>" % tbl

    def memberref_parent_name(self, coded):
        row = coded.row
        tbl = type(row).__name__.replace("Row", "")
        if tbl == "TypeRef":
            return self.type_ref_name(row)
        if tbl == "TypeDef":
            return self.type_name(self.types.index(row))
        if tbl == "TypeSpec":
            return "TypeSpec[%d]" % (self.md.TypeSpec.rows.index(row) + 1)
        if tbl == "ModuleRef":
            return "ModuleRef:" + row.Name.value
        if tbl == "MethodDef":
            return self.method_name(self.method_index(row))
        return "<%s>" % tbl

    def resolve_field_token(self, tok):
        t = tok >> 24
        idx = (tok & 0xFFFFFF) - 1
        if t == 0x04:
            f = self.md.Field.rows[idx]
            return self.field_owner(idx) + "::" + f.Name.value
        if t == 0x0A:
            mr = self.md.MemberRef.rows[idx]
            return "%s::%s" % (self.memberref_parent_name(mr.Class), mr.Name.value)
        return "field_%08X" % tok

    def field_owner(self, fi):
        if not hasattr(self, "_fown"):
            self._fown = {}
            for ti, t in enumerate(self.types):
                for fr in t.FieldList:
                    self._fown[fr.row_index - 1] = ti
        ti = self._fown.get(fi)
        return self.type_name(ti) if ti is not None else "?"

    def resolve_string_token(self, tok):
        idx = tok & 0xFFFFFF
        return self.net.user_strings.get(idx)

    # ---------- method body ----------
    def body(self, mi):
        m = self.methods[mi]
        rva = m.Rva
        if rva == 0:
            return None
        off = self.rva2off(rva)
        b0 = self.raw[off]
        if (b0 & 3) == 2:      # tiny
            size = b0 >> 2
            hdr = 1
            maxstack = 8
            localvar = None
        else:                   # fat
            flags = u16(self.raw, off)
            hdr = (flags >> 12) * 4
            maxstack = u16(self.raw, off+2)
            size = u32(self.raw, off+4)
            localvar = u32(self.raw, off+8)
        il = self.raw[off+hdr: off+hdr+size]
        return {"rva": rva, "file_offset": off, "header_size": hdr, "code_size": size,
                "maxstack": maxstack, "localvarsig": localvar, "il": il,
                "il_file_offset": off+hdr, "flags_raw": b0}

    def il_bytes(self, mi):
        b = self.body(mi)
        return b["il"] if b else b""


def parse_methsig(asm, blob):
    """Very small ECMA-335 method sig parser. Returns dict with text summary."""
    if not blob:
        return None
    b = blob
    i = 0
    conv = b[i]; i += 1
    gp = 0
    if conv & 0x10:
        gp = b[i]; i += 1
    n = b[i]; i += 1
    ret, i = parse_type(asm, b, i)
    ps = []
    for _ in range(n):
        t, i = parse_type(asm, b, i)
        ps.append(t)
    return {"calling_conv": conv, "generic": gp, "ret": ret, "params": ps}


def read_compressed(b, i):
    b0 = b[i]
    if b0 & 0x80 == 0:
        return b0, i + 1
    if b0 & 0xC0 == 0x80:
        return ((b0 & 0x3F) << 8) | b[i+1], i + 2
    return ((b0 & 0x1F) << 24) | (b[i+1] << 16) | (b[i+2] << 8) | b[i+3], i + 4


ELEM = {1:"void",2:"bool",3:"char",4:"int8",5:"uint8",6:"int16",7:"uint16",8:"int32",9:"uint32",
        10:"int64",11:"uint64",12:"float32",13:"float64",14:"string",0x18:"native int",0x19:"native uint",
        0x1C:"object",0x1D:"array"}


def parse_type(asm, b, i):
    e = b[i]; i += 1
    if e in ELEM:
        if e in (0x1C, 0x1D):
            if b[i-1] == 0x1D:
                t, i = parse_type(asm, b, i); return t + "[]", i
        return ELEM[e], i
    if e == 0x0F:  # PTR
        t, i = parse_type(asm, b, i); return t + "*", i
    if e == 0x10:  # BYREF
        t, i = parse_type(asm, b, i); return t + "&", i
    if e == 0x11 or e == 0x12:  # VALUETYPE/CLASS (compressed TypeDefOrRef)
        v, i = read_compressed(b, i)
        tag, idx = v & 3, v >> 2
        if tag == 0:
            return asm.type_name(idx - 1), i
        if tag == 1:
            return asm.type_ref_name(asm.md.TypeRef.rows[idx - 1]), i
        return "TypeSpec[%d]" % idx, i
    if e == 0x13:  # VAR
        n = u16(b, i); i += 2; return "!" + str(n), i
    if e == 0x1E:  # MVAR
        n = u16(b, i); i += 2; return "!!" + str(n), i
    if e == 0x1F:  # CMOD_REQD
        i += 4; return parse_type(asm, b, i)
    if e == 0x20:
        i += 4; return parse_type(asm, b, i)
    if e == 0x45:  # PINNED
        return parse_type(asm, b, i)
    return "elem_0x%02x" % e, i


def typename_token(asm, tok):
    t = tok >> 24
    idx = (tok & 0xFFFFFF) - 1
    if t == 0x01:
        return asm.type_ref_name(asm.md.TypeRef.rows[idx])
    if t == 0x02:
        return asm.type_name(idx)
    if t == 0x1B:
        return "TypeSpec[%d]" % (idx + 1)
    return "typetok_%08X" % tok
