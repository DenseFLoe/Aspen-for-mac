"""Compile the two edited zedstwu hosts and verify the emitted COFF against the original PE."""
import argparse
from collections import Counter
import csv
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
from iced_x86 import Decoder
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from verify import objects

ORIGINAL_SHA256 = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
HOSTS = {
    0x1000: ("sub_180001000", 0x1f1e, 0xb922, 682, 236,
             "e067ed69332d1828c85839741cbf514f7c58633768e7837c3151f69b10cfe000"),
    0xb980: ("sub_18000B980", 0xbec3, 0x9e67, 209, 128,
             "7bf357b30f110d5abba42432b371bf0bafd85f309042b7b403f73d6d0335108f"),
}
COMPILE_FLAGS = (
    "cc", "-target", "x86_64-windows-gnu", "-O2", "-g0",
    "-fno-stack-protector", "-fno-asynchronous-unwind-tables", "-c",
)


def read_csv(name):
    with (HERE.parent / name).open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def verify(original, zig):
    binary = original.read_bytes()
    assert sha256(binary) == ORIGINAL_SHA256
    pe = pefile.PE(data=binary)
    image = pe.get_memory_mapped_image()
    image_base = pe.OPTIONAL_HEADER.ImageBase
    assert pe.FILE_HEADER.Machine == 0x8664
    imports = {
        item.address - image_base: desc.dll.decode() + "!" + (
            item.name.decode() if item.name else str(item.ordinal)
        )
        for desc in pe.DIRECTORY_ENTRY_IMPORT
        for item in desc.imports
    }
    anchors = {x.struct.BeginAddress: x.struct for x in pe.DIRECTORY_ENTRY_EXCEPTION}
    export = next(x.address for x in pe.DIRECTORY_ENTRY_EXPORT.symbols
                  if x.name == b"DSWU_UDL01I")
    assert export == 0x78b0
    pe_base_relocations = {
        entry.rva for block in pe.DIRECTORY_ENTRY_BASERELOC
        for entry in block.entries if entry.type != 0
    }
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    compiler = subprocess.check_output([str(zig), "version"], text=True).strip()
    assert compiler == "0.13.0"
    previous_refs = read_csv("calls.csv")
    previous_transfers = read_csv("internal-transfers.csv")
    unresolved = [x for x in previous_refs if x["class"] == "unresolved"]
    assert len(unresolved) == 44

    def decode_at(address):
        return next(decoder.disasm(image[address:address + 15], address, count=1))

    def rip_target(instruction, operand):
        return instruction.address + instruction.size + operand.mem.disp

    def import_thunk(address):
        instruction = decode_at(address)
        if instruction.mnemonic == "jmp":
            operand = instruction.operands[0]
            if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP:
                slot = rip_target(instruction, operand)
                if slot in imports:
                    return slot, imports[slot]
        return None

    result = {}
    for start, (symbol, end, caller, instruction_count, reloc_count, text_hash) in HOSTS.items():
        entry = anchors[start]
        assert entry.EndAddress == end
        assert export <= 0x7a9a < anchors[export].EndAddress
        assert decode_at(0x7a9a).operands[0].imm == 0x9c40
        assert 0x9c40 <= caller < anchors[0x9c40].EndAddress
        inbound = decode_at(caller)
        assert inbound.mnemonic == "call" and inbound.operands[0].imm == start
        assert not {rva for rva in pe_base_relocations if start <= rva < end}
        original_text = image[start:end]
        assert sha256(original_text) == text_hash
        instructions = list(decoder.disasm(original_text, start))
        assert len(instructions) == instruction_count
        assert instructions[-1].address + instructions[-1].size == end
        second_decoder = Decoder(64, original_text, ip=start)
        instruction_starts = {i.address for i in instructions}
        expected_relocations = {}
        import_sites = {}
        rip_sites = {}
        other_code_transfers = {}
        local_branches = Counter()
        for ins in instructions:
            second = second_decoder.decode()
            assert not second.is_invalid and (second.ip, second.len) == (ins.address, ins.size)
            offsets = second_decoder.get_constant_offsets(second)
            if ins.group(capstone.CS_GRP_CALL) or ins.group(capstone.CS_GRP_JUMP):
                op = ins.operands[0]
                assert op.type == X86_OP_IMM, f"indirect transfer at {ins.address:#x}"
                target = op.imm
                assert second.near_branch_target == target
                if start <= target < end:
                    assert target in instruction_starts
                    local_branches[ins.mnemonic] += 1
                else:
                    offset = ins.address - start + offsets.immediate_offset
                    assert offsets.immediate_size == 4
                    expected_relocations[offset] = (target, offsets.immediate_offset, ins.size)
                    imported = import_thunk(target)
                    if imported:
                        slot, name = imported
                        import_sites[ins.address] = (target, slot, name)
                    else:
                        other_code_transfers[ins.address] = target
            for op in ins.operands:
                if op.type != X86_OP_MEM or op.mem.base != X86_REG_RIP:
                    continue
                target = rip_target(ins, op)
                assert second.is_ip_rel_memory_operand and second.ip_rel_memory_address == target
                offset = ins.address - start + offsets.displacement_offset
                assert offsets.displacement_size == 4 and offset not in expected_relocations
                assert any(s.contains_rva(target) for s in pe.sections)
                expected_relocations[offset] = (target, offsets.displacement_offset, ins.size)
                rip_sites[ins.address] = target
        assert not second_decoder.can_decode
        assert len(expected_relocations) == reloc_count

        def site(row):
            return int(re.match(r"RVA (0x[0-9a-f]+);", row["note"]).group(1), 16)

        scope = [r for r in previous_refs if int(r["caller"], 0) == start]
        assert not [r for r in scope if r["class"] == "unresolved"]
        assert {site(r): r["callee"] for r in scope if r["class"] == "data"} == {
            rva: imports.get(target, hex(target)) for rva, target in rip_sites.items()
        }
        assert {site(r): r["callee"] for r in scope if r["class"] == "external"} == {
            rva: name for rva, (_, _, name) in import_sites.items()
        }
        assert {int(r["site"], 0): int(r["target"], 0) for r in previous_transfers
                if int(r["owner"], 0) == start} == {
            **{rva: target for rva, (target, _, _) in import_sites.items()}, **other_code_transfers
        }

        source = HERE / (symbol + ".c")
        with tempfile.TemporaryDirectory() as work:
            obj = Path(work) / (symbol + ".obj")
            subprocess.run([str(zig), *COMPILE_FLAGS, str(source), "-o", str(obj)], check=True)
            payload, symbols, relocs = objects(obj.read_bytes())
        assert symbols[symbol] == 0 and symbols[f"rva_{start:x}"] == 0
        assert len(payload) == end - start and len(relocs) == reloc_count
        assert len({p for p, _, _ in relocs}) == reloc_count
        for pos, symbol_name, kind in relocs:
            target, disp_offset, size = expected_relocations[pos]
            suffix = re.search(r"_rva_([0-9a-f]+)$", symbol_name)
            assert suffix and int(suffix[1], 16) == target, (pos, symbol_name)
            addend = struct.unpack_from("<i", payload, pos)[0]
            assert 4 <= kind <= 9 and kind - addend == size - disp_offset, (pos, kind, addend)
            struct.pack_into("<i", payload, pos, target + addend - (start + pos + kind))
        assert payload == original_text, f"COFF text differs at host {start:#x}"

        dependencies = Counter(
            imports[target].split("!", 1)[0] + " (IAT)" if target in imports
            else next(s.Name.rstrip(b"\0").decode() for s in pe.sections if s.contains_rva(target))
            for target in rip_sites.values()
        )
        result[symbol] = {
            "entry": hex(start), "exclusive_end": hex(end), "caller": hex(caller),
            "original_text_sha256": sha256(original_text), "rebuilt_text_sha256": sha256(payload),
            "source_sha256": sha256(source.read_bytes()), "matching_bytes": len(payload),
            "instructions": instruction_count, "rel32": reloc_count,
            "unwind_info_rva": hex(entry.UnwindData), "indirect_instructions": 0,
            "local_branches": dict(sorted(local_branches.items())),
            "external_import_call_sites": len(import_sites),
            "import_calls_by_dll": dict(sorted(Counter(
                name.split("!", 1)[0] for _, _, name in import_sites.values()
            ).items())),
            "rip_relative_data_sites": len(rip_sites),
            "rip_relative_target_regions": dict(sorted(dependencies.items())),
            "other_direct_transfers": {hex(site): hex(target) for site, target in other_code_transfers.items()},
        }
    return {
        "original_sha256": ORIGINAL_SHA256, "compiler": f"Zig {compiler}",
        "capstone": capstone.__version__, "pefile": pefile.__version__,
        "compile_flags": list(COMPILE_FLAGS),
        "matched_bytes": sum(r["matching_bytes"] for r in result.values()),
        "matched_instructions": sum(r["instructions"] for r in result.values()),
        "checked_rel32": sum(r["rel32"] for r in result.values()),
        "remaining_unresolved_transfer_count": len(unresolved),
        "remaining_unresolved_transfer_owners": dict(sorted(Counter(
            row["caller"] for row in unresolved
        ).items(), key=lambda pair: int(pair[0], 0))),
        "hosts": result,
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    report = json.dumps(verify(args.original.resolve(), args.zig.resolve()), indent=2) + "\n"
    if args.output:
        args.output.write_bytes(report.encode("utf-8"))
    else:
        print(report, end="")
