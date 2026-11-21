from pathlib import Path
from struct import unpack_from as u
import sys

obj = Path(sys.argv[1]).read_bytes()
machine, ns, stamp, ps, nsyms, os, flags = u('<HHIIIHH', obj)
strings = ps + nsyms * 18

def cstr(start):
    return obj[start:obj.index(0, start)].decode('ascii')

sections = []
for idx in range(ns):
    name, vsize, vaddr, size, off, rel, linen, nr, nl, char = u('<8sIIIIIIHHI', obj, 20+os+40*idx)
    sections.append((name.rstrip(b'\0').decode(), size, off, rel, nr, char))

symbols = {}
i = 0
while i < nsyms:
    pos = ps + i*18
    name, value, section, typ, cls, aux = u('<8sIhHBB', obj, pos)
    name = cstr(strings + int.from_bytes(name[4:], 'little')) if name[:4] == bytes(4) else name.rstrip(b'\0').decode('ascii')
    symbols[i] = (name, value, section, typ, cls, aux)
    i += 1+aux

print('machine=%04X sections=%d timestamp=%08X symbol_entries=%d primary_symbols=%d size=%d' % (machine, ns, stamp, nsyms, len(symbols), len(obj)))
for idx, (name,size,off,rel,count,flags) in enumerate(sections, 1):
    print(f'SECTION {idx} {name} size={size:#x} file={off:#x} relocations={count} flags={flags:08X}')
    if name == '.drectve':
        print('DIRECTIVES', repr(obj[off:off+size].decode('ascii')))
    if name == '.pdata':
        for i in range(0,size,12):
            print('  runtime function range/unwind', ' '.join(f'{n:03x}' for n in u('<III',obj,off+i)))
    for i in range(count):
        virtual, symbol, typ = u('<IIH', obj, rel+i*10)
        target = symbols[symbol]
        print(f'  RELOC {virtual:04x} type={typ:04x} addend={u("<i",obj,off+virtual)[0]:+d} symbol={symbol}:{target[0]}')
for idx, (name,value,sec,typ,cls,aux) in symbols.items():
    print(f'SYMBOL {idx:2} {name:30} value={value:04x} section={sec:2} type={typ:04x} class={cls} auxiliary={aux}')

