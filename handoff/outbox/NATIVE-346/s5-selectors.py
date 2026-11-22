"""Resolve the two ppexec memory-dispatch selectors from the pinned PE."""
import argparse
import hashlib
import json
from pathlib import Path

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile

DIGEST = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"


def inspect(raw):
    if hashlib.sha256(raw).hexdigest() != DIGEST:
        raise ValueError("ppexec.dll SHA-256 mismatch")
    image = pefile.PE(data=raw).get_memory_mapped_image()
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True

    def decode(rva, operation):
        item = next(decoder.disasm(image[rva:rva + 15], rva, count=1))
        if item.mnemonic != operation:
            raise ValueError(f"{rva:#x}: expected {operation}, got {item.mnemonic}")
        return item

    def imm(rva, operation):
        op = decode(rva, operation).operands[-1]
        assert op.type == X86_OP_IMM
        return op.imm

    def relative(rva, operation):
        ins = decode(rva, operation)
        memory, = [op.mem for op in ins.operands if op.type == X86_OP_MEM]
        assert memory.base == X86_REG_RIP and not memory.index
        return ins.address + ins.size + memory.disp

    rows = []
    for entry, cache, test, high, mid, low, fallback, store, tail in [
        (0x8d20, 0x8d30, 0x8d47, 0x8d78, 0x8d97, 0x8dab, 0x8db2, 0x8dbd, 0x8dcb),
        (0x8df0, 0x8e00, 0x8e17, 0x8e47, 0x8e65, 0x8e78, 0x8e7f, 0x8e8a, 0x8e98)
    ]:
        slot = relative(entry, "mov")
        slow = imm(entry + 10, "je")
        assert relative(store, "mov") == slot
        assert decode(cache, "jmp").op_str == decode(tail, "jmp").op_str == "rax"
        assert relative(test, "mov") == 0x20ab0
        assert imm(test + 12, "call") == 0xd180 and imm(test + 17, "jmp") == test
        assert imm(test + 25, "movabs") == 0x7189d9fee
        assert imm(0x8d85 if entry == 0x8d20 else 0x8e54, "test") == 0x9d9fee
        assert imm(low - 2, "test") == 0x6e
        assert decode(fallback + 7, "cmove").op_str == "rax, r9"
        assert decode(high + 5, "jmp").address < low
        targets = []
        for address in (high, mid):
            helper = imm(address, "call")
            targets.append(relative(helper, "lea"))
            decode(helper + 7, "ret")
        targets.extend([relative(low, "lea"), relative(fallback, "lea")])
        rows.append(dict(entry=hex(entry), selector=hex(slow), cached_tail=hex(cache),
                         selector_tail=hex(tail), cache_slot=hex(slot), flag_slot="0x20ab0",
                         init_call="0xd180", targets=[hex(t) for t in targets]))
    return {"original_sha256": DIGEST, "decoder": capstone.__version__,
            "ordered_masks": ["0x7189d9fee", "0x9d9fee", "0x6e", "fallback"],
            "rows": rows}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    args = parser.parse_args()
    print(json.dumps(inspect(args.original.read_bytes()), indent=2))
