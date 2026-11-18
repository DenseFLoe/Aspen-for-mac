"""Capture static Properties reader evidence; never load or run Aspen code."""

import argparse
import hashlib
import json
from pathlib import Path
import sys

from inventory_aspen_sources import emit_json


def capture(path, literal, expected_import, inventory_rows, module_dir):
    sys.path.insert(0, str(module_dir.resolve()))
    import capstone
    import pefile
    data = path.read_bytes()
    sha = hashlib.sha256(data).hexdigest()
    owners = [r for r in inventory_rows if r['sha256'] == sha
              and 'Properties' in r['owner'].split(';') and r['read_status'] == 'ok']
    if not owners:
        raise ValueError('reader lacks Properties ownership and verified content hash')
    pe = pefile.PE(data=data)
    base = pe.OPTIONAL_HEADER.ImageBase
    offset = data.index(literal.encode('ascii'))
    target = base + pe.get_rva_from_offset(offset)
    if pe.PE_TYPE != 0x20b:
        raise ValueError('this reader-evidence implementation requires x64 PE')
    imports = {i.address: dict(dll=d.dll.decode(), name=i.name.decode() if i.name else str(i.ordinal))
               for d in pe.DIRECTORY_ENTRY_IMPORT + getattr(pe, 'DIRECTORY_ENTRY_DELAY_IMPORT', [])
               for i in d.imports}
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md.detail = True

    def mem_target(ins, op):
        return ins.address + ins.size + op.mem.disp if (
            op.type == capstone.x86.X86_OP_MEM and op.mem.base == capstone.x86.X86_REG_RIP) else None

    matches = []
    # Unwind entries give actual function boundaries, avoiding mid-instruction decoding.
    for entry in pe.DIRECTORY_ENTRY_EXCEPTION:
        start, end = entry.struct.BeginAddress, entry.struct.EndAddress
        instructions = list(md.disasm(pe.get_data(start, end - start), base + start))
        refs = [i.address for i in instructions if any(mem_target(i, op) == target for op in i.operands)]
        if not refs:
            continue
        lines, calls = [], []
        for ins in instructions:
            line = f'{ins.address:016x} {ins.mnemonic} {ins.op_str}'
            resolved = None
            if ins.mnemonic == 'call':
                for op in ins.operands:
                    resolved = imports.get(mem_target(ins, op)) or resolved
                    if op.type == capstone.x86.X86_OP_IMM and base <= op.imm < base + pe.OPTIONAL_HEADER.SizeOfImage:
                        thunk = list(md.disasm(pe.get_data(op.imm - base, 6), op.imm))
                        if thunk and thunk[0].mnemonic == 'jmp':
                            resolved = imports.get(mem_target(thunk[0], thunk[0].operands[0])) or resolved
                if resolved:
                    calls.append(dict(address=hex(ins.address), **resolved))
                    line += ' ; ' + resolved['dll'] + '!' + resolved['name']
            lines.append(line)
        if any(c['name'] == expected_import for c in calls):
            matches.append(dict(begin_rva=hex(start), end_rva=hex(end),
                                literal_references=[hex(a) for a in refs], imported_calls=calls, disassembly=lines))
    if not matches:
        raise ValueError('literal reference and expected reader import not found in a single bounded function')
    return dict(path=str(path.resolve()), sha256=sha, literal=literal, literal_offset=offset,
                expected_import=expected_import, ownership_sources=owners, functions=matches,
                limit='Static reader-role evidence; no complete decompilation or runtime acceptance claimed')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inventory', type=Path, required=True)
    parser.add_argument('--module-dir', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if args.output.exists():
        parser.error('output must be a new local path')
    import csv
    rows = []
    for cat in ('01-needs-reverse', '02-no-reverse', '03-undetermined'):
        with (args.inventory / cat / 'files.csv').open(encoding='utf-8-sig', newline='') as stream:
            rows.extend(csv.DictReader(stream))
    specs = [('propmmg.hms', 'ApwnIPShell.dll', 'propmmg.hms', 'SetHelpFile'),
             ('sdffil.aprsdf', 'ppexec.dll', '/xeq/sdffil.aprsdf', 'DMS_ASGOPN')]
    evidence = {}
    for key, reader, literal, expected in specs:
        row = next(r for r in rows if r['priority'] == '2'
                   and Path(r['original_path']).name.casefold() == reader.casefold())
        evidence[key] = capture(Path(row['original_path']), literal, expected, rows, args.module_dir)
    emit_json(args.output, evidence)
    print(json.dumps({k: dict(sha256=v['sha256'], functions=len(v['functions'])) for k, v in evidence.items()}))


if __name__ == '__main__':
    main()
