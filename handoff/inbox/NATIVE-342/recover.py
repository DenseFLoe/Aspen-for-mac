"""Recover PE boundaries, direct call targets, short accessors and SetHelpFile references."""
import argparse
import csv
import hashlib
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_64
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP

ORIGINAL = "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"
HOST = 0x235C0
LEAVES = (0x1520, 0x1530, 0x1540, 0x1CD0, 0x1D40, 0x1F80,
          0x33BB0, 0x33BC0, 0x33BD0, 0x33C00, 0x360A8, 0x360CC)


def write_table(folder, name, fields, rows):
    with (folder / name).open("w", encoding="utf-8", newline="") as stream:
        writer = csv.writer(stream, lineterminator="\n")
        writer.writerow(fields.split(","))
        writer.writerows(rows)


def write_text(path, lines):
    path.write_bytes(("\n".join(lines) + "\n").encode("utf-8"))


def recover(original, folder):
    raw = original.read_bytes()
    if hashlib.sha256(raw).hexdigest() != ORIGINAL:
        raise ValueError("Unexpected original SHA-256")
    pe = pefile.PE(data=raw)
    base = pe.OPTIONAL_HEADER.ImageBase
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    md.detail = True
    bounds = {e.struct.BeginAddress: e.struct.EndAddress for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    imports = {}
    for key in ("DIRECTORY_ENTRY_IMPORT", "DIRECTORY_ENTRY_DELAY_IMPORT"):
        for desc in getattr(pe, key, []):
            for sym in desc.imports:
                label = sym.name.decode("ascii") if sym.name else f"ordinal_{sym.ordinal}"
                imports[sym.address - base] = desc.dll.decode("ascii") + "!" + label
    executable = [(s.VirtualAddress, s.VirtualAddress + s.Misc_VirtualSize)
                  for s in pe.sections if s.Characteristics & 0x20000000]
    exports = {s.address: s.name.decode("ascii") for s in pe.DIRECTORY_ENTRY_EXPORT.symbols
               if s.name and any(lo <= s.address < hi for lo, hi in executable)}
    candidates = set(bounds) | set(exports) | {pe.OPTIONAL_HEADER.AddressOfEntryPoint}
    focus = []
    indirect_examples = []
    interval_rows = []
    for lo, hi in sorted(bounds.items()):
        target_bytes = pe.get_data(lo, hi - lo)
        insns = list(md.disasm(target_bytes, base + lo))
        end = insns[-1].address + insns[-1].size - base if insns else lo
        interval_rows.append([hex(lo), hex(hi), hex(end), len(insns), hashlib.sha256(target_bytes).hexdigest()])
        for insn in insns:
            if (len(indirect_examples) < 8 and insn.mnemonic == "call" and
                    insn.operands[0].type != X86_OP_IMM and
                    not (insn.operands[0].type == X86_OP_MEM and
                         insn.operands[0].mem.base == X86_REG_RIP)):
                indirect_examples.append((lo, insn))
            if insn.mnemonic == "call" and insn.operands[0].type == X86_OP_IMM:
                address = insn.operands[0].imm - base
                if any(start <= address < stop for start, stop in executable):
                    candidates.add(address)
        if lo == HOST:
            focus = insns
            if end != hi:
                raise ValueError("Incomplete SetHelpFile host decode")
    if not set(LEAVES).issubset(candidates):
        raise ValueError("Missing leaf")

    code_dir = folder / "code"
    code_dir.mkdir(parents=True, exist_ok=True)
    asm = []
    source = ["#include <stdint.h>", "",
              "/* module_base is the loaded image base, supplied by the caller.",
              "   Functions below model only the documented x64 register result. */",
              "extern const unsigned char *module_base;", ""]
    coverage = {}
    calls = []
    relative = "code/focus.asm"
    for key in sorted([HOST, *LEAVES]):
        rows = focus if key == HOST else list(md.disasm(pe.get_data(key, 16), base + key, count=2))
        asm.append(f"; RVA {key:#x}")
        asm_first = len(asm) + 1
        for insn in rows:
            pos = insn.address - base
            asm.append(f"{pos:08x}  {insn.bytes.hex(' ')}  {insn.mnemonic} {insn.op_str}")
            listing = f"{relative}#L{len(asm)}"
            ctrl = insn.mnemonic in {"call", "jmp"}
            rip_target = None
            for op in insn.operands:
                if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
                    rip_target = insn.address + insn.size + op.mem.disp - base
                    break
            if ctrl:
                if rip_target in imports:
                    calls.append(["native", hex(key), imports[rip_target], "external", listing,
                                  f"RVA {pos:#x}, import slot {rip_target:#x}; PE import/name table"])
                elif insn.operands[0].type != X86_OP_IMM:
                    calls.append(["native", hex(key), insn.op_str, "unresolved", listing,
                                  f"RVA {pos:#x}; require static receiver or table/slot provenance"])
            elif rip_target is not None:
                calls.append(["native", hex(key), f"RVA {rip_target:#x}", "data", listing,
                              f"RVA {pos:#x}; RIP after instruction plus signed displacement"])
        if key != HOST:
            one, two = rows
            if two.mnemonic != "ret" or two.op_str:
                raise ValueError(f"Unexpected leaf return {key:#x}")
            line = len(source) + 1
            if one.mnemonic == "xor" and one.op_str == "eax, eax":
                expr, ctype = "0", "uint32_t"
            elif one.mnemonic == "mov" and one.op_str == "eax, 1":
                expr, ctype = "1", "uint32_t"
            else:
                op = one.operands[1]
                if op.type != X86_OP_MEM or op.mem.base != X86_REG_RIP:
                    raise ValueError(f"Unrecognised leaf {key:#x}")
                rva = one.address + one.size + op.mem.disp - base
                if one.mnemonic == "lea" and one.op_str.startswith("rax, "):
                    expr, ctype = f"(uintptr_t)(module_base + {rva:#x})", "uintptr_t"
                elif one.mnemonic == "mov" and one.op_str.startswith("eax, dword ptr"):
                    expr, ctype = f"*(const uint32_t *)(module_base + {rva:#x})", "uint32_t"
                else:
                    raise ValueError(f"Unrecognised leaf {key:#x}")
            source += [f"{ctype} result_{key:05x}(void)", "{", f"    return {expr};", "}", ""]
            coverage[key] = (f"{relative}#L{asm_first}-L{len(asm)}", f"code/leaves.c#L{line}-L{line+3}")
    if not any(r[2] == "mmg.dll!SetHelpFile" for r in calls):
        raise ValueError("Missing SetHelpFile edge")
    for caller, insn in indirect_examples:
        pos = insn.address - base
        asm.append(f"; Indirect call in runtime range {caller:#x}")
        asm.append(f"{pos:08x}  {insn.bytes.hex(' ')}  {insn.mnemonic} {insn.op_str}")
        calls.append(["native", hex(caller), insn.op_str, "unresolved",
                      f"{relative}#L{len(asm)}",
                      f"RVA {pos:#x}; bind the receiver or register to a concrete target"])
    write_text(code_dir / "focus.asm", asm)
    write_text(code_dir / "leaves.c", source)
    write_table(folder, "runtime-boundaries.csv", "begin_rva,end_rva,linear_decode_end_rva,decoded_instructions,range_sha256", interval_rows)
    write_table(folder, "native-functions.csv", "rva,name", [
        [hex(k), exports.get(k, f"runtime_{k:x}" if k in bounds else f"call_target_{k:x}")] for k in sorted(candidates)])
    cov_rows = []
    for key in sorted(candidates):
        if key in coverage:
            listing, csrc = coverage[key]
            cov_rows.append(["native", hex(key), "covered", pe.get_data(key, 8).hex(), listing, csrc,
                             "Complete two-instruction x64 return-value model; verified direct-call target."])
        else:
            note = ("Match unwind range to containing function and recover editable implementation and outgoing references."
                    if key in bounds else "Confirm non-unwind target extent, recover editable implementation and outgoing references.")
            cov_rows.append(["native", hex(key), "gap", pe.get_data(key, 8).hex(), "", "", note])
    write_table(folder, "coverage.csv", "kind,key,state,first_bytes,listing,source,note", cov_rows)
    write_table(folder, "calls.csv", "kind,caller,callee,class,listing,note", calls)
    print(f"runtime={len(bounds)} targets={len(candidates)} leaf={len(coverage)} focused_refs={len(calls)}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    recover(args.original, args.output)
