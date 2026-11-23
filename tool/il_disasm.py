# -*- coding: utf-8 -*-
"""Minimal CIL method-body disassembler (stdlib only).

Reads a PE/CLI image, enumerates MethodDef bodies by RVA, decodes IL bytes and
resolves call/callvirt/calli operands to metadata tokens. Emits IL text and a
call-site table used by the evidence builder.
"""
import struct

ONE = {
    0x00: ('nop', 0), 0x01: ('break', 0),
    0x02: ('ldarg.0', 0), 0x03: ('ldarg.1', 0), 0x04: ('ldarg.2', 0), 0x05: ('ldarg.3', 0),
    0x06: ('ldloc.0', 0), 0x07: ('ldloc.1', 0), 0x08: ('ldloc.2', 0), 0x09: ('ldloc.3', 0),
    0x0A: ('stloc.0', 0), 0x0B: ('stloc.1', 0), 0x0C: ('stloc.2', 0), 0x0D: ('stloc.3', 0),
    0x0E: ('ldarg.s', 1), 0x0F: ('ldarga.s', 1), 0x10: ('starg.s', 1),
    0x11: ('ldloc.s', 1), 0x12: ('ldloca.s', 1), 0x13: ('stloc.s', 1),
    0x14: ('ldnull', 0), 0x15: ('ldc.i4.m1', 0),
    0x16: ('ldc.i4.0', 0), 0x17: ('ldc.i4.1', 0), 0x18: ('ldc.i4.2', 0), 0x19: ('ldc.i4.3', 0),
    0x1A: ('ldc.i4.4', 0), 0x1B: ('ldc.i4.5', 0), 0x1C: ('ldc.i4.6', 0), 0x1D: ('ldc.i4.7', 0),
    0x1E: ('ldc.i4.8', 0), 0x1F: ('ldc.i4.s', 1), 0x20: ('ldc.i4', 4), 0x21: ('ldc.i8', 8),
    0x22: ('ldc.r4', 4), 0x23: ('ldc.r8', 8), 0x25: ('dup', 0), 0x26: ('pop', 0),
    0x27: ('jmp', 4), 0x28: ('call', 4), 0x29: ('calli', 4), 0x2A: ('ret', 0),
    0x2B: ('br.s', 1), 0x2C: ('brfalse.s', 1), 0x2D: ('brtrue.s', 1),
    0x2E: ('beq.s', 1), 0x2F: ('bge.s', 1), 0x30: ('bgt.s', 1), 0x31: ('ble.s', 1),
    0x32: ('blt.s', 1), 0x33: ('bne.un.s', 1), 0x34: ('bge.un.s', 1), 0x35: ('bgt.un.s', 1),
    0x36: ('ble.un.s', 1), 0x37: ('blt.un.s', 1),
    0x38: ('br', 4), 0x39: ('brfalse', 4), 0x3A: ('brtrue', 4), 0x3B: ('beq', 4),
    0x3C: ('bge', 4), 0x3D: ('bgt', 4), 0x3E: ('ble', 4), 0x3F: ('blt', 4),
    0x40: ('bne.un', 4), 0x41: ('bge.un', 4), 0x42: ('bgt.un', 4), 0x43: ('ble.un', 4),
    0x44: ('blt.un', 4), 0x45: ('switch', -1),
    0x46: ('ldind.i1', 0), 0x47: ('ldind.u1', 0), 0x48: ('ldind.i2', 0), 0x49: ('ldind.u2', 0),
    0x4A: ('ldind.i4', 0), 0x4B: ('ldind.u4', 0), 0x4C: ('ldind.i8', 0), 0x4D: ('ldind.i', 0),
    0x4E: ('ldind.r4', 0), 0x4F: ('ldind.r8', 0), 0x50: ('ldind.ref', 0),
    0x51: ('stind.ref', 0), 0x52: ('stind.i1', 0), 0x53: ('stind.i2', 0), 0x54: ('stind.i4', 0),
    0x55: ('stind.i8', 0), 0x56: ('stind.r4', 0), 0x57: ('stind.r8', 0),
    0x58: ('add', 0), 0x59: ('sub', 0), 0x5A: ('mul', 0), 0x5B: ('div', 0), 0x5C: ('div.un', 0),
    0x5D: ('rem', 0), 0x5E: ('rem.un', 0), 0x5F: ('and', 0), 0x60: ('or', 0), 0x61: ('xor', 0),
    0x62: ('shl', 0), 0x63: ('shr', 0), 0x64: ('shr.un', 0), 0x65: ('neg', 0), 0x66: ('not', 0),
    0x67: ('conv.i1', 0), 0x68: ('conv.i2', 0), 0x69: ('conv.i4', 0), 0x6A: ('conv.i8', 0),
    0x6B: ('conv.r4', 0), 0x6C: ('conv.r8', 0), 0x6D: ('conv.u4', 0), 0x6E: ('conv.u8', 0),
    0x6F: ('callvirt', 4), 0x70: ('cpobj', 4), 0x71: ('ldobj', 4), 0x72: ('ldstr', 4),
    0x73: ('newobj', 4), 0x74: ('castclass', 4), 0x75: ('isinst', 4), 0x76: ('conv.r.un', 0),
    0x79: ('unbox', 4), 0x7A: ('throw', 0), 0x7B: ('ldfld', 4), 0x7C: ('ldflda', 4),
    0x7D: ('stfld', 4), 0x7E: ('ldsfld', 4), 0x7F: ('ldsflda', 4), 0x80: ('stsfld', 4),
    0x81: ('stobj', 4),
    0x82: ('conv.ovf.i1.un', 0), 0x83: ('conv.ovf.i2.un', 0), 0x84: ('conv.ovf.i4.un', 0),
    0x85: ('conv.ovf.i8.un', 0), 0x86: ('conv.ovf.u1.un', 0), 0x87: ('conv.ovf.u2.un', 0),
    0x88: ('conv.ovf.u4.un', 0), 0x89: ('conv.ovf.u8.un', 0), 0x8A: ('conv.ovf.i.un', 0),
    0x8B: ('conv.ovf.u.un', 0),
    0x8C: ('box', 4), 0x8D: ('newarr', 4), 0x8E: ('ldlen', 0), 0x8F: ('ldelema', 4),
    0x90: ('ldelem.i1', 0), 0x91: ('ldelem.u1', 0), 0x92: ('ldelem.i2', 0), 0x93: ('ldelem.u2', 0),
    0x94: ('ldelem.i4', 0), 0x95: ('ldelem.u4', 0), 0x96: ('ldelem.i8', 0), 0x97: ('ldelem.i', 0),
    0x98: ('ldelem.r4', 0), 0x99: ('ldelem.r8', 0), 0x9A: ('ldelem.ref', 0),
    0x9B: ('stelem.i', 0), 0x9C: ('stelem.i1', 0), 0x9D: ('stelem.i2', 0), 0x9E: ('stelem.i4', 0),
    0x9F: ('stelem.i8', 0), 0xA0: ('stelem.r4', 0), 0xA1: ('stelem.r8', 0), 0xA2: ('stelem.ref', 0),
    0xA3: ('ldelem', 4), 0xA4: ('stelem', 4), 0xA5: ('unbox.any', 4),
    0xB3: ('conv.ovf.i1', 0), 0xB4: ('conv.ovf.u1', 0), 0xB5: ('conv.ovf.i2', 0),
    0xB6: ('conv.ovf.u2', 0), 0xB7: ('conv.ovf.i4', 0), 0xB8: ('conv.ovf.u4', 0),
    0xB9: ('conv.ovf.i8', 0), 0xBA: ('conv.ovf.u8', 0),
    0xC2: ('refanyval', 4), 0xC3: ('ckfinite', 0), 0xC6: ('mkrefany', 4),
    0xD0: ('ldtoken', 4), 0xD1: ('conv.u2', 0), 0xD2: ('conv.u1', 0), 0xD3: ('conv.i', 0),
    0xD4: ('conv.ovf.i', 0), 0xD5: ('conv.ovf.u', 0), 0xD6: ('add.ovf', 0),
    0xD7: ('add.ovf.un', 0), 0xD8: ('mul.ovf', 0), 0xD9: ('mul.ovf.un', 0),
    0xDA: ('sub.ovf', 0), 0xDB: ('sub.ovf.un', 0), 0xDC: ('endfinally', 0),
    0xDD: ('leave', 4), 0xDE: ('leave.s', 1), 0xDF: ('stind.i', 0), 0xE0: ('conv.u', 0),
}

FE = {
    0x00: ('arglist', 0), 0x01: ('ceq', 0), 0x02: ('cgt', 0), 0x03: ('cgt.un', 0),
    0x04: ('clt', 0), 0x05: ('clt.un', 0), 0x06: ('ldftn', 4), 0x07: ('ldvirtftn', 4),
    0x09: ('ldarg', 2), 0x0A: ('ldarga', 2), 0x0B: ('starg', 2), 0x0C: ('ldloc', 2),
    0x0D: ('ldloca', 2), 0x0E: ('stloc', 2), 0x0F: ('localloc', 0), 0x11: ('endfilter', 0),
    0x12: ('unaligned.', 1), 0x13: ('volatile.', 0), 0x14: ('tail.', 0), 0x15: ('initobj', 4),
    0x16: ('constrained.', 4), 0x17: ('cpblk', 0), 0x18: ('initblk', 0), 0x19: ('no.', 1),
    0x1A: ('rethrow', 0), 0x1C: ('sizeof', 4), 0x1D: ('refanytype', 0), 0x1E: ('readonly.', 0),
}


def body(data, filepos, rva):
    p = filepos(rva)
    h = data[p]
    if (h & 3) == 2:
        size = h >> 2
        return data[p + 1:p + 1 + size]
    if (h & 3) == 3:
        size = struct.unpack_from('<I', data, p + 4)[0]
        return data[p + 12:p + 12 + size]
    raise ValueError('bad method header at RVA %#x' % rva)


def decode(code, token_names=None):
    """Yield (offset, mnemonic, operand_repr, size)."""
    i, n = 0, len(code)
    while i < n:
        b = code[i]
        if b == 0xFE:
            op = FE.get(code[i + 1])
            if not op:
                yield i, 'unknown', '0xFE%02x' % code[i + 1], 2
                i += 2
                continue
            name, sz = op
            base = 2
        else:
            op = ONE.get(b)
            if not op:
                yield i, 'unknown', '0x%02x' % b, 1
                i += 1
                continue
            name, sz = op
            base = 1
        if sz < 0:  # switch
            count = struct.unpack_from('<I', code, i + base)[0]
            yield i, name, '(%d targets)' % count, base + 4 + 4 * count
            i += base + 4 + 4 * count
            continue
        operand = ''
        if sz:
            raw = code[i + base:i + base + sz]
            if sz == 4:
                v = int.from_bytes(raw, 'little')
                tokname = (token_names or {}).get(v)
                operand = '0x%08X%s' % (v, (' ' + tokname) if tokname else '')
            elif sz == 8:
                operand = str(int.from_bytes(raw, 'little'))
            else:
                operand = '0x%x' % int.from_bytes(raw, 'little')
        yield i, name, operand, base + sz
        i += base + sz
