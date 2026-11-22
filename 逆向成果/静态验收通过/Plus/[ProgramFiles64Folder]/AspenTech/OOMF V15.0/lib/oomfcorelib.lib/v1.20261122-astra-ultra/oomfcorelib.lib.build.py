"""Reassemble the editable GNU assembly members and write Microsoft AMD64 COFF/ar.

Usage: python oomfcorelib.lib.build.py --assembler PATH_TO_MINGW_AS --out NEW_DIR
The source files beside this script are the only build inputs.
"""
import argparse
from dataclasses import dataclass
from pathlib import Path
import struct
import subprocess
import tempfile

MEMBERS = ('aechks', 'rtanalyzevar', 'rtcfg_f', 'aosgen_int_f', 'rtanalyzeqn', 'rtsenstvt')
pack = struct.pack
unpack_at = struct.unpack_from

@dataclass
class Section:
    name: str
    size: int
    data: bytearray
    relocations: list
    flags: int = 0

def read_assembled(path):
    """Read the section images and relocation sites actually produced by GNU as."""
    blob = path.read_bytes()
    machine, count, _, symtab, nsyms, opt, _ = unpack_at('<HHIIIHH', blob)
    if machine != 0x8664 or opt:
        raise ValueError('The assembler must target Windows x86-64 COFF.')
    strings = symtab + 18*nsyms
    symbols = {}
    by_index = {}
    i = 0
    while i < nsyms:
        p = symtab + 18*i
        tag, value, section, _, _, aux = unpack_at('<8sIhHBB', blob, p)
        if tag.startswith(b'\0'*4):
            start = strings + unpack_at('<I', tag, 4)[0]
            name = blob[start:blob.index(0,start)].decode('ascii')
        else:
            name = tag.rstrip(b'\0').decode('ascii')
        by_index[i] = name
        symbols[name] = (section, value)
        i += 1 + aux
    sections = {}
    for i in range(count):
        tag, _, _, size, raw, rel, _, nrel, _, _ = unpack_at('<8sIIIIIIHHI', blob, 20+40*i)
        name = tag.rstrip(b'\0').decode('ascii')
        sites = []
        for j in range(nrel):
            offset, symbol_index, reloc_type = unpack_at('<IIH', blob, rel+10*j)
            sites.append((offset, by_index[symbol_index], reloc_type))
        data = bytearray(blob[raw:raw+size]) if raw else bytearray()
        sections[name] = (i+1, Section(name, size, data, sites))
    return sections, symbols

def convert_relocations(section):
    """Preserve function-name relocations, image-relative RVAs and REL32_4 bias."""
    for offset, target, kind in section.relocations:
        if target.startswith('coff_rva.'):
            if kind != 2:
                raise ValueError('Expected an absolute 32-bit field for an image-relative RVA')
            yield offset, target.removeprefix('coff_rva.'), 3
        elif target.startswith('coff_rel32_4.'):
            if kind != 4:
                raise ValueError('Expected a PC-relative field preceding an imm32')
            # GNU as uses REL32 with -4 in the operand. REL32_4 encodes the bias in the type.
            addend = unpack_at('<i', section.data, offset)[0]
            struct.pack_into('<i', section.data, offset, addend+4)
            yield offset, target.removeprefix('coff_rel32_4.'), 8
        else:
            yield offset, target.removeprefix('coff_ref.'), kind

def object_from_source(asm, source, temp):
    lines = source.read_text(encoding='utf-8').splitlines()
    member = next(s.split() for s in lines if s.startswith('# @member '))
    _, _, member_name, stamp = member
    dest = temp/(source.stem + '.obj')
    subprocess.run([asm, '-L', '--fatal-warnings', '-o', dest, source],check=True)
    assembled, labels = read_assembled(dest)
    sections = []
    numbers = {}
    gas_numbers = {}
    for line in lines:
        if not line.startswith('# @section '):
            continue
        _, _, name, flags = line.split()
        gas_index, section = assembled[name]
        end_index, length = labels['coff_end'+name]
        if gas_index != end_index or length > section.size:
            raise ValueError('Invalid end label for '+name)
        # GNU pads sections to native alignment. The source explicitly marks the original end.
        section.size = length
        del section.data[length:]
        section.flags = int(flags,0)
        section.relocations = list(convert_relocations(section))
        if any(off+4 > length for off, _, _ in section.relocations):
            raise ValueError('Relocation extends past '+name)
        sections.append(section)
        numbers[name] = len(sections)
        gas_numbers[gas_index] = len(sections)
    strings = bytearray()
    symbols = bytearray()
    indices = {}
    exports = []
    for line in lines:
        if not line.startswith('# @symbol '):
            continue
        _, _, kind, name, *args = line.split()
        indices[name] = len(symbols)//18
        encoded = name.encode('ascii')
        if len(encoded)>8:
            tag = pack('<II',0,len(strings)+4)
            strings.extend(encoded+b'\0')
        else:
            tag = encoded.ljust(8,b'\0')
        value = 0
        number = 0
        stype = 32 if kind in ('function','external_function') else 0
        storage = 3 if kind in ('section','local') else 2
        aux = b''
        if kind == 'section':
            number = numbers[name]
            section = sections[number-1]
            aux = pack('<IH12x',section.size,len(section.relocations))
        elif kind in ('function','local'):
            gas_index, value = labels[name]
            number = gas_numbers[gas_index]
        elif kind == 'common':
            value = int(args[0], 0)
        elif kind not in ('external_data','external_function'):
            raise ValueError('Unknown symbol kind '+kind)
        if kind in ('function','common'):
            exports.append(name)
        symbols.extend(pack('<8sIhHBB',tag,value,number,stype,storage,len(aux)//18)+aux)
    raw_start = 20+40*len(sections)
    reloc_start = raw_start + sum(len(s.data) for s in sections)
    headers, payload, relocs = bytearray(), bytearray(), bytearray()
    for s in sections:
        raw = raw_start + len(payload) if s.data else 0
        rel = reloc_start + len(relocs) if s.relocations else 0
        headers.extend(pack('<8sIIIIIIHHI',s.name.encode(),0,0,s.size,raw,rel,0,len(s.relocations),0,s.flags))
        payload.extend(s.data)
        for off,target,kind in s.relocations:
            relocs.extend(pack('<IIH',off,indices[target],kind))
    sym_offset = reloc_start+len(relocs)
    header = pack('<HHIIIHH',0x8664,len(sections),int(stamp),sym_offset,len(symbols)//18,0,0)
    obj = header+headers+payload+relocs+symbols+pack('<I',len(strings)+4)+strings
    return member_name,int(stamp),obj,exports

def archive(members):
    """Build Microsoft's two symbol indices followed by long names and the COFF members."""
    time = max(stamp for _,stamp,_,_ in members)
    long_names = bytearray()
    objects = []
    owner = {}
    for i,(name,stamp,obj,exports) in enumerate(members):
        objects.append(('/'+str(len(long_names)),stamp,'100666',obj))
        long_names.extend(name.encode()+b'\0')
        for name in exports:
            owner[name] = i
    def indices(offsets):
        a = sorted(owner,key=lambda name:(owner[name],name))
        b = sorted(owner)
        def names(items):
            return b''.join(x.encode()+b'\0' for x in items)
        left = pack('>I',len(a)) + b''.join(pack('>I',offsets[owner[x]]) for x in a) + names(a)
        right = pack('<I',len(offsets)) + b''.join(pack('<I',j) for j in offsets)
        right += pack('<I',len(b)) + b''.join(pack('<H',owner[x]+1) for x in b) + names(b)
        return [('/',time,'0',left),('/',time,'0',right),('//',time,'0',long_names)]
    def record_size(row):
        size = len(row[3])
        return 60+size+size%2
    dummy = indices([0]*len(members))
    position = 8+sum(map(record_size,dummy))
    starts = []
    for row in objects:
        starts.append(position)
        position += record_size(row)
    result = bytearray(b'!<arch>\n')
    for tag,stamp,mode,content in indices(starts)+objects:
        header = f'{tag:<16}{stamp:<12}{"":<6}{"":<6}{mode:<8}{len(content):<10}' + chr(96)+'\n'
        result.extend(header.encode()+content)
        if len(content)%2:
            result.extend(b'\n')
    return result

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--assembler',required=True,help='GNU as for x86_64-w64-mingw32')
    parser.add_argument('--out',type=Path,required=True,help='new or empty output directory')
    options = parser.parse_args()
    options.out.mkdir(parents=True,exist_ok=True)
    if any(options.out.iterdir()):
        parser.error('Specify an empty output directory.')
    here = Path(__file__).resolve().parent
    with tempfile.TemporaryDirectory(dir=options.out) as temp:
        members = [object_from_source(options.assembler,here/f'oomfcorelib.lib.{m}.s',Path(temp)) for m in MEMBERS]
    for name,_,blob,_ in members:
        dest = options.out.joinpath(*name.split(chr(92)))
        dest.parent.mkdir(parents=True,exist_ok=True)
        dest.write_bytes(blob)
    (options.out/'oomfcorelib.lib').write_bytes(archive(members))

if __name__=='__main__':
    main()

