"""IL opcode table (ECMA-335 III) + disassembler producing (offset, bytes, text)."""
import struct

NONE = "none"; I = "i"; IS = "is"; I8 = "i8"; R4 = "r4"; R8 = "r8"; BR = "br"; BRS = "brs"
SW = "switch"; STR = "str"; METH = "meth"; FIELD = "field"; TYPE = "type"; TOK = "tok"
VAR = "var"; VARSHORT = "vars"; SIG = "sig"

ONE = {
0x00:("nop",NONE),0x01:("break",NONE),0x02:("ldarg.0",NONE),0x03:("ldarg.1",NONE),
0x04:("ldarg.2",NONE),0x05:("ldarg.3",NONE),0x06:("ldloc.0",NONE),0x07:("ldloc.1",NONE),
0x08:("ldloc.2",NONE),0x09:("ldloc.3",NONE),0x0A:("stloc.0",NONE),0x0B:("stloc.1",NONE),
0x0C:("stloc.2",NONE),0x0D:("stloc.3",NONE),0x0E:("ldarg.s",VARSHORT),0x0F:("ldarga.s",VARSHORT),
0x10:("starg.s",VARSHORT),0x11:("ldloc.s",VARSHORT),0x12:("ldloca.s",VARSHORT),
0x13:("stloc.s",VARSHORT),0x14:("ldnull",NONE),0x15:("ldc.i4.m1",NONE),0x16:("ldc.i4.0",NONE),
0x17:("ldc.i4.1",NONE),0x18:("ldc.i4.2",NONE),0x19:("ldc.i4.3",NONE),0x1A:("ldc.i4.4",NONE),
0x1B:("ldc.i4.5",NONE),0x1C:("ldc.i4.6",NONE),0x1D:("ldc.i4.7",NONE),0x1E:("ldc.i4.8",NONE),
0x1F:("ldc.i4.s",IS),0x20:("ldc.i4",I),0x21:("ldc.i8",I8),0x22:("ldc.r4",R4),0x23:("ldc.r8",R8),
0x25:("dup",NONE),0x26:("pop",NONE),0x27:("jmp",METH),0x28:("call",METH),0x29:("calli",SIG),
0x2A:("ret",NONE),0x2B:("br.s",BRS),0x2C:("brfalse.s",BRS),0x2D:("brtrue.s",BRS),
0x2E:("beq.s",BRS),0x2F:("bge.s",BRS),0x30:("bgt.s",BRS),0x31:("ble.s",BRS),0x32:("blt.s",BRS),
0x33:("bne.un.s",BRS),0x34:("bge.un.s",BRS),0x35:("bgt.un.s",BRS),0x36:("ble.un.s",BRS),
0x37:("blt.un.s",BRS),0x38:("br",BR),0x39:("brfalse",BR),0x3A:("brtrue",BR),0x3B:("beq",BR),
0x3C:("bge",BR),0x3D:("bgt",BR),0x3E:("ble",BR),0x3F:("blt",BR),0x40:("bne.un",BR),
0x41:("bge.un",BR),0x42:("bgt.un",BR),0x43:("ble.un",BR),0x44:("blt.un",BR),0x45:("switch",SW),
0x46:("ldind.i1",NONE),0x47:("ldind.u1",NONE),0x48:("ldind.i2",NONE),0x49:("ldind.u2",NONE),
0x4A:("ldind.i4",NONE),0x4B:("ldind.u4",NONE),0x4C:("ldind.i8",NONE),0x4D:("ldind.i",NONE),
0x4E:("ldind.r4",NONE),0x4F:("ldind.r8",NONE),0x50:("ldind.ref",NONE),0x51:("stind.ref",NONE),
0x52:("stind.i1",NONE),0x53:("stind.i2",NONE),0x54:("stind.i4",NONE),0x55:("stind.i8",NONE),
0x56:("stind.r4",NONE),0x57:("stind.r8",NONE),0x58:("add",NONE),0x59:("sub",NONE),
0x5A:("mul",NONE),0x5B:("div",NONE),0x5C:("div.un",NONE),0x5D:("rem",NONE),0x5E:("rem.un",NONE),
0x5F:("and",NONE),0x60:("or",NONE),0x61:("xor",NONE),0x62:("shl",NONE),0x63:("shr",NONE),
0x64:("shr.un",NONE),0x65:("neg",NONE),0x66:("not",NONE),0x67:("conv.i1",NONE),
0x68:("conv.i2",NONE),0x69:("conv.i4",NONE),0x6A:("conv.i8",NONE),0x6B:("conv.r4",NONE),
0x6C:("conv.r8",NONE),0x6D:("conv.u4",NONE),0x6E:("conv.u8",NONE),0x6F:("callvirt",METH),
0x70:("cpobj",TYPE),0x71:("ldobj",TYPE),0x72:("ldstr",STR),0x73:("newobj",METH),
0x74:("castclass",TYPE),0x75:("isinst",TYPE),0x76:("conv.r.un",NONE),0x79:("unbox",TYPE),
0x7A:("throw",NONE),0x7B:("ldfld",FIELD),0x7C:("ldflda",FIELD),0x7D:("stfld",FIELD),
0x7E:("ldsfld",FIELD),0x7F:("ldsflda",FIELD),0x80:("stsfld",FIELD),0x81:("stobj",TYPE),
0x82:("conv.ovf.i1.un",NONE),0x83:("conv.ovf.i2.un",NONE),0x84:("conv.ovf.i4.un",NONE),
0x85:("conv.ovf.i8.un",NONE),0x86:("conv.ovf.u1.un",NONE),0x87:("conv.ovf.u2.un",NONE),
0x88:("conv.ovf.u4.un",NONE),0x89:("conv.ovf.u8.un",NONE),0x8A:("conv.ovf.i.un",NONE),
0x8B:("conv.ovf.u.un",NONE),0x8C:("box",TYPE),0x8D:("newarr",TYPE),0x8E:("ldlen",NONE),
0x8F:("ldelema",TYPE),0x90:("ldelem.i1",NONE),0x91:("ldelem.u1",NONE),0x92:("ldelem.i2",NONE),
0x93:("ldelem.u2",NONE),0x94:("ldelem.i4",NONE),0x95:("ldelem.u4",NONE),0x96:("ldelem.i8",NONE),
0x97:("ldelem.i",NONE),0x98:("ldelem.r4",NONE),0x99:("ldelem.r8",NONE),0x9A:("ldelem.ref",NONE),
0x9B:("stelem.i",NONE),0x9C:("stelem.i1",NONE),0x9D:("stelem.i2",NONE),0x9E:("stelem.i4",NONE),
0x9F:("stelem.i8",NONE),0xA0:("stelem.r4",NONE),0xA1:("stelem.r8",NONE),0xA2:("stelem.ref",NONE),
0xA3:("ldelem",TYPE),0xA4:("stelem",TYPE),0xA5:("unbox.any",TYPE),0xB3:("conv.ovf.i1",NONE),
0xB4:("conv.ovf.u1",NONE),0xB5:("conv.ovf.i2",NONE),0xB6:("conv.ovf.u2",NONE),
0xB7:("conv.ovf.i4",NONE),0xB8:("conv.ovf.u4",NONE),0xB9:("conv.ovf.i8",NONE),
0xBA:("conv.ovf.u8",NONE),0xC2:("refanyval",TYPE),0xC3:("ckfinite",NONE),0xC6:("mkrefany",TYPE),
0xD0:("ldtoken",TOK),0xD1:("conv.u2",NONE),0xD2:("conv.u1",NONE),0xD3:("conv.i",NONE),
0xD4:("conv.ovf.i",NONE),0xD5:("conv.ovf.u",NONE),0xD6:("add.ovf",NONE),0xD7:("add.ovf.un",NONE),
0xD8:("mul.ovf",NONE),0xD9:("mul.ovf.un",NONE),0xDA:("sub.ovf",NONE),0xDB:("sub.ovf.un",NONE),
0xDC:("endfinally",NONE),0xDD:("leave",BR),0xDE:("leave.s",BRS),0xDF:("stind.i",NONE),
0xE0:("conv.u",NONE),
}

FE = {
0x00:("arglist",NONE),0x01:("ceq",NONE),0x02:("cgt",NONE),0x03:("cgt.un",NONE),
0x04:("clt",NONE),0x05:("clt.un",NONE),0x06:("ldftn",METH),0x07:("ldvirtftn",METH),
0x09:("ldarg",VAR),0x0A:("ldarga",VAR),0x0B:("starg",VAR),0x0C:("ldloc",VAR),
0x0D:("ldloca",VAR),0x0E:("stloc",VAR),0x0F:("localloc",NONE),0x11:("endfilter",NONE),
0x12:("unaligned.",IS),0x13:("volatile.",NONE),0x14:("tail.",NONE),0x15:("initobj",TYPE),
0x16:("constrained.",TYPE),0x17:("cpblk",NONE),0x18:("initblk",NONE),0x19:("no.",IS),
0x1A:("rethrow",NONE),0x1C:("sizeof",TYPE),0x1D:("refanytype",NONE),0x1E:("readonly.",NONE),
}


def decode(asm, il, base_off=0):
    out = []
    i = 0
    n = len(il)
    while i < n:
        start = i
        b = il[i]; i += 1
        if b == 0xFE:
            b2 = il[i]; i += 1
            name, kind = FE.get(b2, ("<fe%02x>" % b2, NONE))
            opbytes = bytes([0xFE, b2])
        else:
            name, kind = ONE.get(b, ("<%02x>" % b, NONE))
            opbytes = bytes([b])
        operand = None
        extra = None
        if kind == NONE:
            pass
        elif kind in (IS, VARSHORT):
            operand = il[i]; i += 1
        elif kind == I:
            operand = struct.unpack_from("<i", il, i)[0]; i += 4
        elif kind == I8:
            operand = struct.unpack_from("<q", il, i)[0]; i += 8
        elif kind == R4:
            operand = struct.unpack_from("<f", il, i)[0]; i += 4
        elif kind == R8:
            operand = struct.unpack_from("<d", il, i)[0]; i += 8
        elif kind == BR:
            operand = struct.unpack_from("<i", il, i)[0]; i += 4
        elif kind == BRS:
            operand = struct.unpack_from("<b", il, i)[0]; i += 1
        elif kind == SW:
            cnt = struct.unpack_from("<I", il, i)[0]; i += 4
            operand = list(struct.unpack_from("<%di" % cnt, il, i)); i += 4*cnt
        elif kind in (STR, METH, FIELD, TYPE, TOK):
            operand = struct.unpack_from("<I", il, i)[0]; i += 4
            operand = ("tok", operand)
        elif kind == VAR:
            operand = struct.unpack_from("<H", il, i)[0]; i += 2
        elif kind == SIG:
            operand = struct.unpack_from("<I", il, i)[0]; i += 4
        raw = il[start:i]
        out.append({"off": start, "size": i-start, "raw": raw.hex(), "op": name,
                    "kind": kind, "operand": operand})
    return out


def text(asm, name, kind, operand, off):
    if kind == METH and operand:
        tok = operand[1]
        try:
            s, _ = asm.resolve_method_token(tok)
        except Exception:
            s = "<unresolved %08X>" % tok
        return "%s (0x%08X)  -> %s" % (name, tok, s)
    if kind == FIELD and operand:
        tok = operand[1]
        try:
            s = asm.resolve_field_token(tok)
        except Exception:
            s = "<unresolved %08X>" % tok
        return "%s (0x%08X)  -> %s" % (name, tok, s)
    if kind == STR and operand:
        tok = operand[1]
        try:
            s = asm.resolve_string_token(tok)
            if isinstance(s, bytes):
                s = s.decode("utf-16-le", "replace")
        except Exception:
            s = "<unresolved %08X>" % tok
        return '%s (0x%08X)  -> "%s"' % (name, tok, s)
    if kind == TYPE and operand:
        return "%s (0x%08X)  -> %s" % (name, operand[1], safe_type(asm, operand[1]))
    if kind == TOK and operand:
        return "%s (0x%08X)" % (name, operand[1])
    if kind == BR:
        return "%s IL_%04X" % (name, off + 5 + operand)
    if kind == BRS:
        return "%s IL_%04X" % (name, off + 2 + operand)
    if kind == SW:
        return "%s [%s]" % (name, ", ".join("IL_%04X" % (off + 5 + 4*len(operand) + x) for x in operand))
    if kind in (I, IS, VARSHORT, VAR):
        return "%s 0x%X" % (name, operand)
    if kind == I8:
        return "%s %d" % (name, operand)
    if operand is not None:
        return "%s %s" % (name, operand)
    return name


def safe_type(asm, tok):
    try:
        t = tok >> 24
        idx = (tok & 0xFFFFFF) - 1
        if t == 0x01:
            return asm.type_ref_name(asm.md.TypeRef.rows[idx])
        if t == 0x02:
            return asm.type_name(idx)
        if t == 0x1B:
            return "TypeSpec[%d]" % (idx+1)
    except Exception:
        pass
    return "0x%08X" % tok
