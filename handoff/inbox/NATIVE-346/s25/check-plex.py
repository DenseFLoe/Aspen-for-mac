"""Verify the PLEX record fields and paired locator for the ppexec copy path."""
import argparse
import json
import runpy
import struct
from pathlib import Path

from capstone.x86 import X86_OP_IMM, X86_OP_MEM


BASE = runpy.run_path(str(Path(__file__).resolve().parents[1] / 's21/check-tinfo.py'))
Original, describe, rip_targets = (BASE[name] for name in ('Original', 'describe', 'rip_targets'))


def imm(image, site):
    instruction = image.instruction(site)
    if instruction.operands[0].type != X86_OP_IMM:
        raise ValueError(f'Expected an immediate target at {site:#x}')
    return instruction.operands[0].imm


def memory(image, site, operand, expected):
    instruction = image.instruction(site)
    op = instruction.operands[operand]
    if op.type != X86_OP_MEM:
        raise ValueError(f'Expected a memory operand at {site:#x}')
    actual = (instruction.reg_name(op.mem.base), instruction.reg_name(op.mem.index), op.mem.disp, op.size)
    if actual != expected:
        raise ValueError(f'{site:#x}: {actual} differs from {expected}')


def imports(image):
    base = image.pe.OPTIONAL_HEADER.ImageBase
    return {
        (module.dll.lower(), item.name): item.address - base
        for module in image.pe.DIRECTORY_ENTRY_IMPORT for item in module.imports if item.name
    }


def checked(test, label):
    if not test:
        raise ValueError(label)


def inspect(pp, at):
    pp_imports = imports(pp)
    plex_iat = pp_imports[b'atdms.dll', b'DMS_PLEX']
    locate_iat = pp_imports[b'atdms.dll', b'DMS_LOCATI']
    checked(rip_targets(pp.instruction(0x7dcb)) == [plex_iat], 'PLEX IAT')
    for address in (0x7dc6, 0x7de8):
        target = pp.instruction(imm(pp, address))
        checked(target.mnemonic == 'jmp' and rip_targets(target) == [locate_iat], 'LOCATI IAT')
    checked(rip_targets(pp.instruction(0x7dbf)) == [0x17bf0], 'First locator input')
    checked(struct.unpack_from('<q', pp.image, 0x17bf0)[0] == 2, 'First locator input value')
    memory(pp, 0x7dd2, 1, ('r15', 'rax', 0x308, 8))
    for address in (0x7dda, 0x7de1):
        checked(rip_targets(pp.instruction(address)) == [0x20688], 'Secondary record key slot')

    sources = [
        (0x7df5, 0x20, 'rax', 0x7e3f, 0x7e45, 0x7e48, 0x7e5a, 0x2f0),
        (0x7dfa, 0x38, 'rbx', 0x7e42, 0x7e5f, 0x7e62, 0x7e70, 0x4f8),
        (0x7df0, 0x60, 'rax', 0x7e3c, 0x7e75, 0x7e78, 0x7e86, 0x0f0),
    ]
    source_evidence = []
    for load_at, field, index, dec, add, address, call, dest in sources:
        memory(pp, load_at, 1, ('r15', index, field, 8))
        checked(pp.instruction(dec).mnemonic == 'dec' and pp.instruction(add).mnemonic == 'add', 'Copy index calculation')
        checked(imm(pp, call) == 0x8d20, 'Copy target')
        source_evidence.append({
            'record_field_byte_offset': hex(field), 'relative_destination': hex(dest),
            'span_bytes_at_64_words': 512, 'required_payload_relative_word_range': '[field-1, field-1+64)',
            'path': [describe(pp.instruction(rva)) for rva in (load_at, dec, add, address, call)],
        })
    checked(at.exports['DMS_LOCATI'] == 0x20760 and at.exports['DMS_ATLOOK'] == imm(at, 0x207a9), 'Locator-to-ATLOOK')
    checked(rip_targets(at.instruction(0x207a2)) == [0x128368] == rip_targets(at.instruction(0x207ae)), 'Locator return slot')
    plex_export = at.exports['DMS_PLEX']
    checked(struct.unpack_from('<Q', at.image, 0x749a8)[0] == at.pe.OPTIONAL_HEADER.ImageBase + plex_export, 'Paired PLEX base')
    memory(at, 0xb6f6, 1, ('r13', 'rcx', 0x10, 8))
    for rva, displacement in ((0xb705, -8), (0xb716, 0), (0xb734, 0x10)):
        memory(at, rva, 1, ('r13', 'rcx', displacement, 8))
    checked(imm(at, 0xb757) == at.exports['DMS_DEREF5'], 'Descriptor lazy resolution')
    checked(at.exports['DMS_ABEAD'] == 0x1870 and at.exports['DMS_ACHAIN'] == 0x18f0, 'Descriptor writers')
    checked(rip_targets(at.instruction(0x1882)) == [plex_export], 'DMS_ABEAD PLEX base')
    checked(rip_targets(at.instruction(0x68fa1)) == [0x8ed68] and at.image[0x8ed68:0x8ed73] == b'PCS_LookUp\0', 'Managed PCS lookup')
    checked(at.image[0x8ed10:0x8ed34].split(b'\0')[0] == b'\\AspenTech.NGP.UnmanagedBridge.dll', 'Bridge module')
    writer_sites = (0x18ba, 0x18c6, 0x18d5, 0x1907, 0x1913, 0x1927, 0xb76b)
    return {
        'original_sha256': {'ppexec.dll': BASE['PPEXEC_SHA'], 'atdms.dll': BASE['ATDMS_SHA']},
        'tools': {'capstone': BASE['cs'].__version__, 'pefile': BASE['pefile'].__version__},
        'pex_record_path': [describe(pp.instruction(rva)) for rva in (
            0x7dbf, 0x7dc6, 0x7dcb, 0x7dd2, 0x7dda, 0x7de1, 0x7de8, 0x7ded, 0x7e26, 0x7e36, 0x7e4c)],
        'copy_sources': source_evidence,
        'small_count_loads': [describe(pp.instruction(rva)) for rva in (0x7ec0, 0x7ece, 0x7edc, 0x7f40, 0x7f4c, 0x7f54)],
        'plex_export_rva': hex(plex_export),
        'locator_and_descriptor_path': [describe(at.instruction(rva)) for rva in (
            0x207a2, 0x207a9, 0x207ae, 0xb5d7, 0xb5da, 0xb604, 0xb617, 0xb654, 0xb67e, 0xb685, 0xb68d,
            0xb6dc, 0xb6ef, 0xb6f6, 0xb701, 0xb705, 0xb716, 0xb734, 0xb73e, 0xb757, 0xb76b, 0xb777, 0xb87b,
            0xb8a3, 0x55da6, 0x55dae, 0x55db6, 0x55dc0, 0x55dcf, 0x68fa1, 0x68ff3, 0x6903d, 0x69049, 0x69054)],
        'paired_descriptor_writes': [describe(at.instruction(rva)) for rva in writer_sites],
        'record_producer_and_capacity': 'Open for all three payload fields; generic descriptor bounds do not bind this dynamic key.',
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('ppexec', type=Path)
    parser.add_argument('atdms', type=Path)
    args = parser.parse_args()
    print(json.dumps(inspect(Original(args.ppexec, BASE['PPEXEC_SHA']), Original(args.atdms, BASE['ATDMS_SHA'])), indent=2))


if __name__ == '__main__':
    main()
