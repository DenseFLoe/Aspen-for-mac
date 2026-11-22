"""Static evidence for one guarded, single-level AMD64 RVA switch pattern."""
from bisect import bisect_left, bisect_right
from hashlib import sha256
import struct


MAX_TABLE_ENTRIES = 4096
MAX_TOTAL_ENTRIES = 65536
SCOPE = ("Original preferred-base file bytes on the in-range fallthrough of the recorded unsigned comparison. "
         "Table entries are image-relative values in selector order. Other entries into the block, runtime "
         "destinations, loader changes and the implementation of destination blocks remain unverified.")


def file_span(original, pe, rva, size, *, code=False):
    """Require the full span to map uniquely to original bytes with the requested use."""
    end = rva + size
    if size <= 0 or rva < pe.OPTIONAL_HEADER.SizeOfHeaders or end > min(2**32, pe.OPTIONAL_HEADER.SizeOfImage):
        return None
    matches = []
    for section in pe.sections:
        start = section.VirtualAddress
        virtual_end = start + (section.Misc_VirtualSize or section.SizeOfRawData)
        if start >= end or virtual_end <= rva:
            continue
        flags = section.Characteristics
        offset = section.PointerToRawData + rva - start
        backed_end = min(virtual_end, start + section.SizeOfRawData)
        if (rva < start or end > backed_end or not section.PointerToRawData or offset + size > len(original)
                or (code and not flags & 0x20000000)
                or (not code and (flags & 0x80000000 or not flags & 0x40000000))):
            return None
        matches.append((section, offset))
    return matches[0] if len(matches) == 1 else None


def table_pattern(sequence, x86, image_base):
    """Match operand widths and register values on seven consecutive proved instructions."""
    cmp, branch, lea, extend, load, add, jump = sequence
    code, reg, kind = x86.Code, x86.Register, x86.OpKind
    if (cmp.code not in (code.CMP_RM32_IMM8, code.CMP_RM32_IMM32, code.CMP_EAX_IMM32)
            or cmp.op0_kind != kind.REGISTER or branch.code not in (code.JA_REL8_64, code.JA_REL32_64)
            or lea.code != code.LEA_R64_M or lea.memory_base != reg.RIP or lea.ip_rel_memory_address != image_base):
        return None
    bound = cmp.immediate(1)
    base, selector = lea.op0_register, cmp.op0_register
    if not 0 <= bound < 2**31 or base == x86.RegisterExt.full_register(selector):
        return None
    if extend.code == code.CDQE and selector == reg.EAX:
        index = reg.RAX
    elif extend.code == code.MOVSXD_R64_RM32 and extend.op1_kind == kind.REGISTER and extend.op1_register == selector:
        index = extend.op0_register
    else:
        return None
    if (base == index or load.code != code.MOV_R32_RM32 or load.op1_kind != kind.MEMORY
            or load.memory_base != base or load.memory_index != index or load.memory_index_scale != 4):
        return None
    dest = x86.RegisterExt.full_register(load.op0_register)
    if (dest == base or add.code not in (code.ADD_R64_RM64, code.ADD_RM64_R64)
            or add.op0_kind != kind.REGISTER or add.op1_kind != kind.REGISTER
            or add.op0_register != dest or add.op1_register != base
            or jump.code != code.JMP_RM64 or jump.op0_kind != kind.REGISTER or jump.op0_register != dest):
        return None
    if any(ins.has_segment_prefix or ins.has_lock_prefix or ins.has_rep_prefix or ins.has_repne_prefix for ins in sequence):
        return None
    return bound, load.memory_displacement, branch.near_branch_target - image_base


def target_boundary(site, original, pe, decode, nodes, examined, proven, excluded, boundaries):
    ins = decode(site)
    if ins is None or ins.is_invalid or not file_span(original, pe, site, ins.len, code=True):
        return "unmapped_or_undecodable", 0
    end = site + ins.len
    if site in excluded or bisect_right(boundaries, site) < bisect_left(boundaries, end):
        return "conflicting_or_rejected_boundary", ins.len
    if site in proven:
        return "original_root_path", ins.len
    # x86 instructions have at most fifteen bytes. Include provisional original interpretations.
    for i in range(bisect_left(examined, site - 14), bisect_left(examined, end)):
        other = examined[i]
        if other != site and other + nodes[other][0] > site:
            return "overlapping_original_decode", ins.len
    return "selector_derived_candidate", ins.len


def mark_overlapping_entries(ranges):
    """Resolve competing selector-derived starts across all inspected tables."""
    active = []
    conflicts = set()
    for start, (length, _) in sorted(ranges.items()):
        active = [(other, end) for other, end in active if end > start]
        if active:
            conflicts.add(start)
            conflicts.update(other for other, _ in active)
        active.append((start, start + length))
    for start in conflicts:
        for entry in ranges[start][1]:
            entry["boundary"] = "overlapping_selector_destinations"


def audit(original, pe, x86, decode, nodes, proven, excluded, ends, listed):
    result = {"scope": SCOPE, "table_entry_limit": MAX_TABLE_ENTRIES, "total_entry_limit": MAX_TOTAL_ENTRIES,
              "examined_register_jumps": 0, "unmatched_register_jumps": 0, "paths": []}
    # Membership alone does not connect adjacent instructions across a runtime-function end.
    previous = {target: site for site in proven for target, edge in nodes[site][1]
                if edge == "fallthrough" and target in proven}
    examined, boundaries = sorted(nodes), sorted(ends)
    image_base = pe.OPTIONAL_HEADER.ImageBase
    formatter = x86.Formatter(x86.FormatterSyntax.INTEL)
    remaining = MAX_TOTAL_ENTRIES
    selector_ranges = {}
    for site in sorted(proven):
        if nodes[site][2] != "indirect_jump":
            continue
        jump = decode(site)
        if jump.code != x86.Code.JMP_RM64 or jump.op0_kind != x86.OpKind.REGISTER:
            continue
        result["examined_register_jumps"] += 1
        chain = [site]
        while len(chain) < 7 and chain[-1] in previous:
            chain.append(previous[chain[-1]])
        if len(chain) != 7:
            continue
        chain.reverse()
        sequence = [decode(address) for address in chain]
        pattern = table_pattern(sequence, x86, image_base)
        if not pattern:
            continue
        spans = [file_span(original, pe, address, ins.len, code=True) for address, ins in zip(chain, sequence)]
        if not all(spans):
            continue
        bound, table, default = pattern
        count, size = bound + 1, 4 * (bound + 1)
        record = {"site_rva": hex(site), "original_boundary_confirmed": True, "listed_site": site in listed,
                  "guard_rva": hex(chain[0]), "unsigned_selector_min": 0, "unsigned_selector_max": bound,
                  "selector_register": formatter.format_register(sequence[0].op0_register).lower(),
                  "target_expression": "image_base + uint32_le_at_rva(table_rva + 4 * selector)",
                  "default_target_rva": hex(default), "table_rva": hex(table), "entry_bytes": 4, "table_bytes": size,
                  "path_instructions": [{"rva": hex(address), "bytes": original[offset:offset + ins.len].hex(" "),
                                         "instruction": str(ins)}
                                        for address, ins, (_, offset) in zip(chain, sequence, spans)],
                  "status": "inconclusive", "ordered_target_rvas": [], "destinations": []}
        result["paths"].append(record)
        if (chain[0] <= default < site + jump.len or default not in proven
                or not file_span(original, pe, default, proven[default], code=True)):
            record["reason"] = "default_path_unverified"
            continue
        if count > MAX_TABLE_ENTRIES or count > remaining:
            record["reason"] = "entry_budget_exceeded"
            continue
        span = file_span(original, pe, table, size)
        if span is None:
            record["reason"] = "table_not_uniquely_file_backed_and_readonly"
            continue
        remaining -= count
        section, offset = span
        raw = original[offset:offset + size]
        record["table_sha256"] = sha256(raw).hexdigest()
        record["table_section"] = section.Name.rstrip(b"\0").decode("ascii", "backslashreplace")
        targets = [value for value, in struct.iter_unpack("<I", raw)]
        record["ordered_target_rvas"] = [hex(target) for target in targets]
        for target in sorted(set(targets)):
            basis, length = target_boundary(target, original, pe, decode, nodes, examined, proven, excluded, boundaries)
            entry = {"rva": hex(target), "boundary": basis}
            if basis == "selector_derived_candidate":
                selector_ranges.setdefault(target, (length, []))[1].append(entry)
            record["destinations"].append(entry)

    mark_overlapping_entries(selector_ranges)
    for record in result["paths"]:
        if record["destinations"]:
            if all(entry["boundary"] in ("original_root_path", "selector_derived_candidate")
                   for entry in record["destinations"]):
                record["status"] = "verified_table_mapping"
            else:
                record["reason"] = "destination_boundary_unverified"
    result["unmatched_register_jumps"] = result["examined_register_jumps"] - len(result["paths"])
    return result
