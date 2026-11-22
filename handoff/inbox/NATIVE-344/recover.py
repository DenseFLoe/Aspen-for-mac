"""Reproduce the pinned AMD64 instruction inventory and cross-reference evidence."""
import argparse
from bisect import bisect_right
from collections import defaultdict
import csv
import hashlib
import json
from pathlib import Path
import struct

import pefile
import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP, X86_REG_RCX

DIGEST = "9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601"
CORE = {0x39c00, 0x109c0, 0x22a50}
SWITCH = (0x22a8f,0x22aa9,0x22b32,0x22b32,0x22ac5,0x22b32,0x22a9b,
          0x22aba,0x22b32,0x22b32,0x22b32,0x22ace,0x22afa,0x22b05,
          0x22b10,0x22b1b,0x22a9b,0x22aba,0x22b26)

def table(path, fields, rows):
    with path.open('w', encoding='utf-8', newline='') as f:
        writer = csv.writer(f, lineterminator='\n')
        writer.writerow(fields.split(','))
        writer.writerows(rows)

def textfile(path, lines):
    path.write_bytes(('\n'.join(lines) + '\n').encode())

def recover(path, dest):
    raw = path.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == DIGEST
    pe = pefile.PE(data=raw)
    base = pe.OPTIONAL_HEADER.ImageBase
    cs = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    cs.detail = True
    image = pe.get_memory_mapped_image()
    text = next(s for s in pe.sections if s.Name.rstrip(b'\0') == b'.text')
    lo_text = text.VirtualAddress
    hi_text = lo_text + text.Misc_VirtualSize
    def is_code(rva): return lo_text <= rva < hi_text
    exports = defaultdict(list)
    for symbol in pe.DIRECTORY_ENTRY_EXPORT.symbols:
        if is_code(symbol.address):
            exports[symbol.address].append(symbol.name.decode() if symbol.name else f'#{symbol.ordinal}')
    bounds = {e.struct.BeginAddress: e.struct.EndAddress for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    parents = {e.struct.BeginAddress:e.unwindinfo.FunctionEntry for e in pe.DIRECTORY_ENTRY_EXCEPTION
               if e.unwindinfo.UNW_FLAG_CHAININFO}
    def parent(k):
        visited = set()
        while k in parents:
            assert k not in visited
            visited.add(k)
            k = parents[k]
        return k
    imports = {}
    for tab in ('DIRECTORY_ENTRY_IMPORT','DIRECTORY_ENTRY_DELAY_IMPORT'):
        for desc in getattr(pe,tab,[]):
            for s in desc.imports:
                label = f'#{s.ordinal}' if s.import_by_ordinal else s.name.decode()
                imports[s.address-base] = desc.dll.decode()+'!'+label
    anchors = set(bounds) | set(exports) | {pe.OPTIONAL_HEADER.AddressOfEntryPoint}
    assert len(anchors) == 911
    assert struct.unpack_from('<19I', image, 0x22b4c) == SWITCH
    assert image[0x416f8:0x41715] == b'SkipEngineLoadOnDocumentLoad\0'

    def walk(start, stop):
        instructions = {}
        pending = [start]
        while pending:
            pos = pending.pop()
            if pos in instructions or not start <= pos < stop:
                continue
            for ins in cs.disasm(image[pos:stop], base + pos):
                site = ins.address - base
                if site in instructions: break
                instructions[site] = ins
                if ins.group(capstone.CS_GRP_JUMP):
                    if ins.operands[0].type == X86_OP_IMM:
                        pending.append(ins.operands[0].imm - base)
                    elif site == 0x22a8d:
                        pending.extend(SWITCH)
                    if ins.mnemonic == 'jmp': break
                if ins.group(capstone.CS_GRP_RET) or ins.mnemonic in ('int3','ud2','hlt'):
                    break
        return instructions

    targets = set(anchors)
    decoded = {}
    queue = set(anchors)
    while queue:
        limits = sorted(targets | {hi_text})
        new = set()
        for start in sorted(queue):
            stop = bounds.get(start, limits[bisect_right(limits,start)])
            insns = walk(start,stop)
            decoded[start] = insns
            for ins in insns.values():
                if ins.mnemonic == 'call' and ins.operands[0].type == X86_OP_IMM:
                    addr = ins.operands[0].imm-base
                    if is_code(addr): new.add(addr)
        queue = new - targets
        targets.update(new)
    # Reapply the final set of known boundaries to candidate functions outside .pdata.
    limits = sorted(targets | {hi_text})
    for start in sorted(targets - set(bounds)):
        decoded[start] = walk(start,limits[bisect_right(limits,start)])
    def rip(ins):
        for op in ins.operands:
            if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
                return ins.address-base + ins.size + op.mem.disp
        return None
    def trampoline(target):
        if image[target:target+2] == b'\xff\x25':
            slot = target+6+struct.unpack_from('<i',image,target+2)[0]
            if slot in imports: return slot
        return None
    src = ['#include <stdint.h>', 'extern unsigned char *const sim_image;', '']
    asm = []
    coverage = {}
    refs = defaultdict(set)
    callrows = []
    ranges = []
    core_lines = {0x22a50:(22,48),0x109c0:(50,59),0x39c00:(63,86)}
    def short_model(insns):
        seq = list(sorted(insns))
        if not 2 <= len(seq) <= 3: return None
        body = [insns[k] for k in seq]
        if body[-1].mnemonic != 'ret' or body[-1].op_str: return None
        if any(a.address + a.size != b.address for a,b in zip(body,body[1:])): return None
        ins = body[0]
        rva = rip(ins)
        operand = ins.op_str
        if len(seq) == 3:
            second=body[1]
            if (ins.mnemonic,operand,second.mnemonic) == ('movzx','eax, cl','mov') and second.op_str.startswith('dword ptr [rip') and second.op_str.endswith(', eax'):
                return ('uint32_t','uint8_t value',[f'*(uint32_t *)(sim_image + {rip(second):#x}) = value;', 'return value;'])
            if ins.mnemonic == second.mnemonic == 'mov' and operand.startswith('eax, dword ptr [rip') and second.op_str.endswith(', ecx') and rva == rip(second):
                return ('uint32_t','uint32_t value',[f'uint32_t *slot = (uint32_t *)(sim_image + {rva:#x});','uint32_t before = *slot;', '*slot = value;', 'return before;'])
            return None
        if (ins.mnemonic, operand) == ('xor','eax, eax'): return ('uint32_t','void',['return 0;'])
        if ins.mnemonic == 'mov' and operand.startswith('eax, ') and ins.operands[1].type == X86_OP_IMM:
            return ('uint32_t','void',[f'return {ins.operands[1].imm & 0xffffffff:#x}u;'])
        if rva is not None:
            if ins.mnemonic == 'lea' and operand.startswith('rax, '): return ('uintptr_t','void',[f'return (uintptr_t)(sim_image + {rva:#x});'])
            if ins.mnemonic == 'mov' and operand.startswith('eax, dword ptr [rip'): return ('uint32_t','void',[f'return *(const uint32_t *)(sim_image + {rva:#x});'])
            if ins.mnemonic == 'mov' and operand.startswith('rax, qword ptr [rip'): return ('uintptr_t','void',[f'return *(const uintptr_t *)(sim_image + {rva:#x});'])
            if ins.mnemonic == 'mov' and operand.startswith('byte ptr [rip') and operand.endswith(', cl'): return ('void','uint8_t value',[f'sim_image[{rva:#x}] = value;'])
        if ins.mnemonic=='mov' and operand.startswith('rax, qword ptr [rcx') and ins.operands[1].mem.base == X86_REG_RCX and not ins.operands[1].mem.index:
            return ('uintptr_t','const unsigned char *self',[f'return *(const uintptr_t *)(self + {ins.operands[1].mem.disp:#x});'])
        return None

    for owner, insns in sorted(decoded.items()):
        owner_root=parent(owner)
        leaf = short_model(insns)
        focus = owner_root in CORE or bool(leaf)
        if focus:
            asm.append(f'; begin RVA {owner:#x}')
            first = len(asm)+1
        for site,ins in sorted(insns.items()):
            slot = rip(ins)
            branch = ins.mnemonic in ('call','jmp')
            transfer = ins.group(capstone.CS_GRP_JUMP) or ins.mnemonic == 'call'
            group, target, classification, note = None, None, None, None
            if transfer and ins.operands[0].type == X86_OP_IMM:
                dest_rva = ins.operands[0].imm-base
                thunk_slot = trampoline(dest_rva) if is_code(dest_rva) else None
                if branch and thunk_slot is not None:
                    classification='external'
                    target=imports[thunk_slot]
                    group='thunk'
                    note=f'via {dest_rva:#x}, slot {thunk_slot:#x}'
                elif ins.mnemonic=='call':
                    group,target='call',hex(dest_rva)
                elif not (owner <= dest_rva < bounds.get(owner,limits[bisect_right(limits,owner)])):
                    group,target='range-branch',hex(dest_rva)
            elif branch and slot in imports:
                group,target,classification,note='iat',imports[slot],'external',f'slot {slot:#x}'
            elif branch and site==0x22a8d:
                group,target='switch','0x22b4c'
            elif branch:
                group,target,classification,note='indirect',ins.op_str,'unresolved','recover register or memory producer and possible targets'
            elif slot is not None:
                group,target,classification,note='data',imports.get(slot,hex(slot)),'data',f'RIP target {slot:#x}'
            if group: refs[group,target].add((owner,site))
            if focus:
                asm.append(f'{site:08x}  {ins.bytes.hex(" ")}  {ins.mnemonic} {ins.op_str}')
                if classification:
                    callrows.append(['native',hex(owner),target,classification,f'code/focus.asm#L{len(asm)}',f'{site:#x}: {note}'])
        if owner in bounds:
            end=bounds[owner]
            ranges.append((hex(owner),hex(end),hex(owner_root),sum(i.size for i in insns.values()),len(insns),hashlib.sha256(image[owner:end]).hexdigest()))
        if leaf:
            ctype,params,body=leaf
            begin=len(src)+1
            src += [f'{ctype} sim_{owner:05x}({params})','{',*['    '+line for line in body],'}','']
            coverage[owner]=(f'code/focus.asm#L{first}-L{len(asm)}',f'code/leaves.c#L{begin}-L{len(src)-1}')
        elif owner in CORE:
            lo,hi=core_lines[owner]
            coverage[owner]=(f'code/focus.asm#L{first}-L{len(asm)}',f'code/simdll.c#L{lo}-L{hi}')
    capstone_targets = set(targets)
    gh = {}
    gh_index = dest/'ghidra/functions.tsv'
    if gh_index.is_file():
        with gh_index.open(encoding='utf-8', newline='') as f:
            for row in csv.DictReader(f, delimiter='\t'):
                rva = int(row['rva'],16)
                assert rva not in gh and is_code(rva)
                gh[rva] = row
        targets |= gh.keys()
    leaf_count = len(coverage.keys()-CORE)
    def name(k):
        if exports.get(k): return ' | '.join(exports[k])
        if k in gh: return gh[k]['name']
        return ('pdata_' if k in bounds else 'call_target_')+f'{k:x}'
    rows=[]
    for k in sorted(targets):
        listing,source=coverage.get(k,('',''))
        if k in CORE: note='Control-flow model present; verify callee/import prototypes, state ownership and referenced helper implementations.'
        elif k in coverage: note='Complete straight-line leaf body, using observed register and memory widths.'
        elif k in parents: note=f'Chained unwind fragment of {parent(k):#x}; recover the containing implementation and outgoing references.'
        elif trampoline(k): note=f'IAT jump to {imports[trampoline(k)]}; bind source declaration and verify its calling contract.'
        elif gh.get(k,{}).get('listing'):
            note='Review generated body against original control flow, indirect targets, signatures and data.'
        else: note='Recover source and resolve outgoing operands for this RVA; confirm full extent with control flow.'
        if not source and k in gh: source=gh[k]['listing']
        rows.append(('native',hex(k),'covered' if k in coverage and k not in CORE else 'gap',image[k:k+8].hex(),listing,source,note))
    dest.mkdir(parents=True,exist_ok=True)
    (dest/'code').mkdir(exist_ok=True)
    textfile(dest/'code/focus.asm',asm)
    textfile(dest/'code/leaves.c',src)
    table(dest/'native-functions.csv','rva,name',[(hex(k),name(k)) for k in sorted(targets)])
    table(dest/'coverage.csv','kind,key,state,first_bytes,listing,source,note',rows)
    table(dest/'calls.csv','kind,caller,callee,class,listing,note',callrows)
    table(dest/'runtime-ranges.csv','begin,end_exclusive,unwind_root,visited_bytes,visited_instructions,range_sha256',ranges)
    table(dest/'references.csv','kind,target,owner_rva:instruction_rva_hex',[(g,t,' '.join(f'{o:x}:{s:x}' for o,s in sorted(sites))) for (g,t),sites in sorted(refs.items())])
    resources=[]
    def ident(entry): return str(entry.name) if entry.name is not None else str(entry.id)
    for kind in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        for item in kind.directory.entries:
            for language in item.directory.entries:
                record=language.data.struct
                blob=pe.get_data(record.OffsetToData,record.Size)
                assert len(blob)==record.Size
                resources.append((ident(kind),ident(item),ident(language),hex(record.OffsetToData),
                                  record.Size,record.CodePage,hashlib.sha256(blob).hexdigest()))
    table(dest/'resources.csv','type,name,language,rva,bytes,code_page,sha256',resources)
    summary=dict(original_sha256=DIGEST,tool_version=f'pefile {pefile.__version__}, Capstone {capstone.__version__}',
                 command='python recover.py <original-simdll> <output-folder>',scope='AMD64 PE unwind and code export anchors; recursive direct call targets; bounded direct-flow blocks; named switch and leaf models',
                 limitations='Unrecovered bodies, indirect targets, other jump tables, ABI prototypes and unvisited ranges require review. Chained unwind fragments are grouped by root, without asserting each range is a separate function.',
                 original_anchors=len(anchors),native_reported_count=len(targets),unwind_ranges=len(bounds),chained_ranges=len(parents),
                 covered_leaves=leaf_count,core_models_kept_as_gaps=len(CORE),declared_gaps=len(targets)-leaf_count,
                 references={g:sum(len(s) for (k,t),s in refs.items() if k==g) for g in sorted({k for k,t in refs})},
                 scope_calls=len(callrows),code_export_ordinals=sum(map(len,exports.values())),unique_code_export_rvas=len(exports),
                 resource_leaves=len(resources),resource_types=len(pe.DIRECTORY_ENTRY_RESOURCE.entries))
    if gh:
        states = [x['state'] for x in gh.values()]
        gh_version,gh_digest = (dest/'ghidra/version.txt').read_text(encoding='utf-8').splitlines()
        assert gh_version == '12.2' and gh_digest == DIGEST
        summary.update(ghidra_version=gh_version,ghidra_functions=len(gh),ghidra_states={s:states.count(s) for s in sorted(set(states))},
                       capstone_candidates=len(capstone_targets),ghidra_only=len(gh.keys()-capstone_targets),
                       capstone_only=len(capstone_targets-gh.keys()))
        summary['tool_version'] += ', Ghidra 12.2 PUBLIC'
    textfile(dest/'run.json',[json.dumps(summary,indent=2)])
    print(json.dumps(summary))

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original',type=Path)
    parser.add_argument('output',type=Path)
    args=parser.parse_args()
    recover(args.original,args.output)
