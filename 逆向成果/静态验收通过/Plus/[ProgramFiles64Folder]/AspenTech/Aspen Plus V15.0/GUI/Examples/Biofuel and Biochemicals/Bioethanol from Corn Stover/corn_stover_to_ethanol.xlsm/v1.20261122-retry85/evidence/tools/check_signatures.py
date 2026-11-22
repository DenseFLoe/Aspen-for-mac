"""Read-only check for this workbook's Win64 parameter records with pcodedmp 1.2.6."""
import argparse
import io
import json
import re
import sys
from hashlib import sha256
from pathlib import Path
from struct import unpack_from
from types import SimpleNamespace
from zipfile import ZipFile

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('workbook', type=Path)
parser.add_argument('module_source', type=Path)
parser.add_argument('pcode_text', type=Path)
parser.add_argument('--tools', type=Path, help='directory containing pcodedmp 1.2.6 and olefile')
cli = parser.parse_args()
if cli.tools:
    sys.path.insert(0, str(cli.tools))
from pcodedmp import pcodedmp as p
from olefile import OleFileIO

def u32(data, offset):
    return unpack_from('<I', data, offset)[0]

def u16(data, offset):
    return unpack_from('<H', data, offset)[0]

with ZipFile(cli.workbook) as archive:
    project = archive.read('xl/vbaProject.bin')
cfg = SimpleNamespace(verbose=False, disasmOnly=True)
with OleFileIO(io.BytesIO(project)) as ole:
    code = ole.openstream('VBA/MEBAspenGUI').read()
    project_info = ole.openstream('VBA/_VBA_PROJECT').read()
    directory, _, win64 = p.processDir(SimpleNamespace(ole_file=ole), 'VBA/dir', cfg, io.StringIO())
assert win64
ids = p.getTheIdentifiers(project_info)
table_start = u32(code, 0x11) + 16
table = code[table_start:table_start + u32(code, table_start-4)]
object_start = u32(code, 5) + 0x8a + 4
objects = code[object_start:object_start + u32(code, object_start-4)]
source = cli.module_source.read_bytes().decode('latin-1').splitlines()
listing = cli.pcode_text.read_bytes().decode('latin-1')
rows = []
original_disasm = p.disasmFunc

def capture(indirect, declarations, names, off, op_type, endian, ver, is64):
    assert indirect == table and is64 and ver == 7 and endian == '<'
    name = p.getName(table, names, off+2, endian, ver, is64)
    reported = original_disasm(table, declarations, names, off, op_type, endian, ver, is64)
    a = u32(table, off+56)
    args = []
    visited = set()
    while a not in (0, 0xFFFFFFFF):
        assert a not in visited and a+32 <= len(table)
        visited.add(a)
        kind = u32(table, a+16)
        options = u16(table, a+28)
        row = dict(offset=hex(a), name=p.getName(table,names,a+2,endian,ver,is64),
                   raw_type=hex(kind), link_at_20=hex(u32(table,a+20)), link_at_24=hex(u32(table,a+24)),
                   raw_options=hex(options))
        if kind >> 16 == 0xffff:
            row['type'] = p.getTypeName(kind & 0xff)
        else:
            assert u16(table,kind) == 0x011d
            type_reference = u16(table,kind+2)
            assert type_reference % 8 == 0
            oi = type_reference // 8 * 10
            row['object_reference'] = hex(type_reference)
            row['object_record'] = hex(oi)
            row['type'] = p.getID(u16(objects,oi+6),names,ver,is64)
        args.append(row)
        a=u32(table,a+24)
    assert len(args) == table[off+81]
    access = 'Public' if table[off+83] & 2 else 'Private'
    arguments = ', '.join(('Optional ' if int(a['raw_options'],16) & 0x200 else '') +
                          a['name'] + ' As ' + a['type'] for a in args)
    # Defaults may follow the signature in the original source.
    signature = f'{access} Sub {name}({arguments})'
    declaration = next(x.strip() for x in source if re.match(rf'(?:Public|Private) Sub {name}\(', x.strip(),re.I))
    assert declaration == signature, (declaration, signature)
    call_arities = [int(v,16) for v in re.findall(rf'\bArgsCall\s+(?:\(Call\)\s+)?{name}\s+0x([0-9a-fA-F]+)',listing)]
    if name in ('InitializeSimulatorInterface','FillStreams','ExtractStream'):
        assert call_arities and all(n == len(args) for n in call_arities)
    rows.append(dict(signature=signature, original_display=reported, function_offset=hex(off), count_byte=table[off+81],
                     access_byte=hex(table[off+83]), args=args, caller_arities=call_arities))
    return reported

p.disasmFunc = capture
p.pcodeDump(code, project_info, directory, ids, win64, cfg, io.StringIO())
assert len(rows) == 5
print(json.dumps(dict(workbook_sha256=sha256(cli.workbook.read_bytes()).hexdigest(), module='VBA/MEBAspenGUI',
                      indirect_table_stream_offset=hex(table_start), object_table_stream_offset=hex(object_start),
                      project_syskind='Win64', project_internal_version=hex(u16(project_info,2)),
                      procedures=rows), indent=2))
