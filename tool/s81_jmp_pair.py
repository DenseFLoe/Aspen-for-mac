# -*- coding: utf-8 -*-
"""s81: distinguish a real RIP-relative indirect JMP (FF 25 disp32) from INC/other FF forms."""
import struct, sys

def decode_ff(bs):
    """Return ('jmp'|'call'|'inc'|'dec'|'other', rip_target_or_None) for an FF-prefixed instruction."""
    if len(bs) < 2 or bs[0] != 0xFF:
        return 'other', None
    m = bs[1]
    reg = (m >> 3) & 7
    mod = m >> 6
    rm = m & 7
    if mod == 3:
        return ('inc' if reg == 0 else 'dec' if reg == 1 else 'other'), None
    if (m & 0xC7) == 0x05 and len(bs) >= 6:
        disp = struct.unpack_from('<i', bs, 2)[0]
        return ('jmp' if reg == 4 else 'call' if reg == 2 else 'other'), disp
    return 'other', None


CASES = [
    ('ff2500000000', 'jmp', 0, 'FF /4 mod=00 rm=101 -> RIP-relative JMP'),
    ('ff1500000000', 'call', 0, 'FF /2 -> RIP-relative CALL'),
    ('ffc0', 'inc', None, 'FF /0 mod=11 -> INC EAX'),
    ('ffc8', 'dec', None, 'FF /1 mod=11 -> DEC EAX'),
    ('ff2500000000', 'jmp', 0, 'same disp32 bytes as INC form but modrm 0x25 -> JMP, not INC'),
]


def main():
    ok = True
    for hexs, want, want_disp, why in CASES:
        got, disp = decode_ff(bytes.fromhex(hexs))
        good = got == want and (want_disp is None or disp == want_disp)
        ok &= good
        print('%-14s -> %-4s disp=%s want=%-4s %s' % (hexs, got, disp, want, 'PASS' if good else 'FAIL'))
    # the classic confusion: FF 25 (jmp) vs FF /0 with the same low byte
    a, _ = decode_ff(bytes.fromhex('ff25aabbccdd'))
    b, _ = decode_ff(bytes.fromhex('ffc0aabbccdd'))
    pair = (a == 'jmp' and b == 'inc')
    ok &= pair
    print('PAIR jmp-vs-inc : jmp=%s inc=%s status=%s' % (a, b, 'PASS' if pair else 'FAIL'))
    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
