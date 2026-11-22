"""Verify the two declared AMD64 callback paths in the S13 evidence format."""
import csv
import hashlib
import json
import re

if __package__:
    from . import clr_fixups, native_sites, native_targets
else:
    import clr_fixups
    import native_sites
    import native_targets


SCOPE = "submitted_callback_paths"
EVIDENCE = "s13/evidence.json"
DISPOSITIONS = "s13/disposition.csv"
EDGES = "internal-transfers.csv"

# A named path is verified only for these consecutive decoded instructions. Labels bind
# original branch destinations, including bypasses and the section loop's back edge.
GATE = """
getter_call: call {getter}
mov rbx, rax
cmp qword ptr [rax], 0
je {end}
pass_slot: mov rcx, rax
predicate_call: call {predicate}
test_result: test al, al
bypass: je {end}
mov r8, rsi
mov edx, 2
mov rcx, r14
mov rax, qword ptr [rbx]
mov r9, qword ptr [{dispatch}]
site: call r9
"""
PREDICATE = """
sub rsp, 0x18
mov r8, rcx
mov eax, 0x5a4d
cmp word ptr [0x0], ax
jne {bad_header}
movsxd rcx, dword ptr [0x3c]
lea rdx, [0x0]
add rcx, rdx
cmp dword ptr [rcx], 0x4550
jne {bad_header}
mov eax, 0x20b
cmp word ptr [rcx + 0x18], ax
jne {bad_header}
sub r8, rdx
movzx edx, word ptr [rcx + 0x14]
add rdx, 0x18
add rdx, rcx
movzx eax, word ptr [rcx + 6]
lea rcx, [rax + rax * 4]
lea r9, [rdx + rcx * 8]
loop: mov qword ptr [rsp], rdx
cmp rdx, r9
je {no_section}
mov ecx, dword ptr [rdx + 0xc]
lower: cmp r8, rcx
jb {advance}
mov eax, dword ptr [rdx + 8]
add eax, ecx
cmp r8, rax
inside: jb {selected}
advance: add rdx, 0x28
jmp {loop}
no_section: xor edx, edx
selected: test rdx, rdx
jne {flags}
xor al, al
jmp {epilogue}
flags: cmp dword ptr [rdx + 0x24], 0
sign: jge {accept}
reject: xor al, al
jmp {epilogue}
accept: mov al, 1
jmp {epilogue}
bad_header: xor al, al
jmp {epilogue}
xor al, al
epilogue: add rsp, 0x18
ret
"""
CALLER = """
push rbp
sub rsp, 0x30
mov rbp, rdx
mov rax, qword ptr [rcx]
mov edx, dword ptr [rax]
mov qword ptr [rsp + 0x28], rcx
mov dword ptr [rsp + 0x20], edx
argument: lea r9, [{target}]
mov r8, qword ptr [rbp + 0x70]
mov edx, dword ptr [rbp + 0x68]
mov rcx, qword ptr [rbp + 0x60]
site: call {helper}
"""
HELPER = """
mov qword ptr [rsp + 8], rbx
mov qword ptr [rsp + 0x10], rbp
mov qword ptr [rsp + 0x18], rsi
push rdi
sub rsp, 0x20
save_argument: mov rdi, r9
mov rsi, r8
mov ebx, edx
mov rbp, rcx
call {nested}
test eax, eax
jne {end}
cmp ebx, 1
jne {end}
mov r8, rsi
xor edx, edx
mov rcx, rbp
restore_argument: mov rax, rdi
site: call qword ptr [{dispatch}]
"""


def require(condition, message):
    if not condition:
        raise ValueError(message)


class Image:
    def __init__(self, data, pe, x86):
        self.data, self.pe, self.x86 = data, pe, x86
        require(pe.FILE_HEADER.Machine == 0x8664 and pe.OPTIONAL_HEADER.Magic == 0x20b,
                "expected an AMD64 PE32+ original")
        self.ranges = [(row.struct.BeginAddress, row.struct.EndAddress)
                       for row in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ())]
        require(pe.OPTIONAL_HEADER.DATA_DIRECTORY[3].Size == len(self.ranges) * 12,
                "incomplete PE runtime-function table")
        fmt = self.fmt = x86.Formatter(x86.FormatterSyntax.INTEL)
        fmt.hex_prefix, fmt.hex_suffix = "0x", ""
        fmt.uppercase_hex = fmt.branch_leading_zeros = fmt.show_branch_size = False
        fmt.rip_relative_addresses = fmt.space_after_operand_separator = True
        fmt.space_between_memory_add_operators = fmt.space_between_memory_mul_operators = True
        fmt.memory_size_options = x86.MemorySizeOptions.ALWAYS

    def owner(self, rva):
        matching = [(start, end) for start, end in self.ranges if start <= rva < end]
        require(len(matching) == 1, f"missing unique PE runtime-function owner at {rva:#x}")
        return matching[0]

    def instruction(self, rva):
        ins = self.x86.Decoder(64, self.pe.get_data(rva, 15), ip=rva).decode()
        require(not ins.is_invalid, f"invalid original instruction at {rva:#x}")
        raw = clr_fixups.raw(self.data, self.pe, rva, ins.len, executable=True)
        return ins, raw

    def boundary_from(self, begin, target):
        require(0 <= target - begin <= 4096, "declared instruction is outside the supported owner prefix")
        while begin < target:
            ins, _ = self.instruction(begin)
            begin = ins.next_ip
        require(begin == target, f"declared path starts inside an instruction at {target:#x}")

    def block(self, start, pattern, **external):
        position = start
        labels, rows = {}, []
        for line in pattern.strip().splitlines():
            name, sep, text = line.partition(": ")
            if sep:
                labels[name] = position
            ins, _ = self.instruction(position)
            rows.append((ins, text if sep else line))
            position = ins.next_ip
        labels["end"] = position
        symbols = {key: hex(value) for key, value in (external | labels).items()}
        for ins, expected in rows:
            observed = self.fmt.format(ins)
            if ins.is_ip_rel_memory_operand:
                observed = re.sub(r"\[rip(?: [+-] [^\]]+)?\]", f"[{ins.ip_rel_memory_address:#x}]", observed)
            if expected == "call {nested}":
                # The target need not be inferred. The conditional path assumes a
                # returning Win64 ABI call, preserving the nonvolatile RDI register.
                require(ins.code == self.x86.Code.CALL_REL32_64, f"expected direct call at {ins.ip:#x}")
                labels["nested_target"] = ins.near_branch_target
                continue
            require(observed == expected.format_map(symbols), f"original instruction differs at {ins.ip:#x}")
        return labels

    def section_fact(self, rva):
        matches = [s for s in self.pe.sections
                   if s.VirtualAddress <= rva < s.VirtualAddress + s.Misc_VirtualSize]
        require(len(matches) == 1, f"no unique original section containing {rva:#x}")
        s, = matches
        end = s.VirtualAddress + s.Misc_VirtualSize
        require(end < 1 << 32 and rva + 8 <= end, f"ambiguous section boundary for {rva:#x}")
        return {"section": s.Name.rstrip(b"\0").decode("ascii"), "start": hex(s.VirtualAddress),
                "end_exclusive": hex(end), "characteristics": hex(s.Characteristics),
                "raw_backed": rva + 8 <= s.VirtualAddress + s.SizeOfRawData,
                "accepted_by_122f4": not bool(s.Characteristics & 0x80000000)}

    def dispatch(self):
        config = getattr(self.pe, "DIRECTORY_ENTRY_LOAD_CONFIG", None)
        require(config and hasattr(config.struct, "GuardCFDispatchFunctionPointer"), "missing Guard CF dispatch field")
        return config.struct.GuardCFDispatchFunctionPointer - self.pe.OPTIONAL_HEADER.ImageBase


def resolved(rows, site, owner):
    records = [(line, row) for line, row in rows if native_targets.address(row["site_rva"]) == site]
    require(len(records) == 1, f"expected one {DISPOSITIONS} entry for {site:#x}")
    line, row = records[0]
    require(native_targets.address(row["owner_rva"]) == owner and row["state"] == "resolved",
            f"owner or disposition differs at {DISPOSITIONS}#L{line}")
    return f"{DISPOSITIONS}#L{line}"


def section_gate(image, proof, dispositions, root):
    claim = proof["optional_callback"]
    site, slot = (native_targets.address(claim[key]) for key in ("site", "slot"))
    rows = claim["evidence"]
    require(isinstance(rows, list) and len(rows) == 12, "expected twelve S13 gate instruction witnesses")
    locations = [native_targets.address(row["rva"]) for row in rows]
    start, getter = locations[:2]
    owner, end = image.owner(site)
    line = resolved(dispositions, site, owner)
    image.boundary_from(owner, start)
    pred_call, _ = image.instruction(locations[3])
    predicate = pred_call.near_branch_target
    gate = image.block(start, GATE, getter=getter, predicate=predicate, dispatch=image.dispatch())
    require(owner <= start and gate["end"] <= end and gate["site"] == site, "gate bypass/site outside owner")
    image.block(getter, "lea rax, [{slot}]\nret", slot=slot)
    pred = image.block(predicate, PREDICATE)
    require(image.owner(predicate) == (predicate, pred["end"]), "predicate boundary differs from original unwind range")
    expected = [gate["getter_call"], getter, gate["pass_slot"], gate["predicate_call"], pred["lower"],
                pred["inside"], pred["flags"], pred["sign"], pred["reject"], gate["test_result"], gate["bypass"], site]
    require(set(locations) == set(expected) and len(set(locations)) == len(expected),
            "S13 witnesses do not cover the complete declared gate evidence")
    for row, location in zip(rows, locations):
        ins, raw = image.instruction(location)
        require(row["bytes"] == raw.hex() and row["instruction"] == image.fmt.format(ins),
                f"submitted gate witness differs from original at {location:#x}")
    fact = image.section_fact(slot)
    control = image.section_fact(native_targets.address(claim["readonly_control"]["start"]))
    require(json.dumps(claim["section"], sort_keys=True) == json.dumps(fact, sort_keys=True) and
            json.dumps(claim["readonly_control"], sort_keys=True) == json.dumps(control, sort_keys=True)
            and control["accepted_by_122f4"] is True,
            "submitted section attributes differ from original")
    require(fact["accepted_by_122f4"] is False and claim["normal_original_gate"] == "inactive",
            "original section predicate does not establish the declared rejection")
    return hex(slot), {"site_rva": hex(site), "slot_rva": hex(slot), "section": fact,
                       "predicate_rva": hex(predicate), "bypass_rva": hex(gate["end"]),
                       "source": [EVIDENCE + "#optional_callback", line],
                       "condition": "unmodified PE section headers, on the submitted path"}


def one_callback(image, proof, dispositions, root):
    claim = proof["local_callback"]
    caller, helper, site, target, slot = (native_targets.address(claim[k]) for k in
                                          ("caller", "helper", "site", "target", "dispatch_slot"))
    require(slot == image.dispatch(), "declared dispatch slot differs from PE load configuration")
    caller_owner, caller_end = image.owner(caller)
    require(image.owner(target)[0] == target, "submitted callback argument is not an original function entry")
    path = image.block(caller_owner, CALLER, helper=helper, target=target)
    require(path["site"] == caller and path["end"] <= caller_end, "declared caller differs from original call site")
    begin, end = image.owner(site)
    require(begin == helper, "submitted helper differs from original owner")
    dispatch = image.block(helper, HELPER, dispatch=slot)
    require(dispatch["site"] == site and dispatch["end"] <= end, "declared callback site differs from original")
    line = resolved(dispositions, site, helper)
    rel32 = proof["matching_rel32_sites"]
    require(isinstance(rel32, dict) and rel32.get(hex(caller)) == hex(helper),
            "submitted direct-caller inventory omits the named caller")
    expected = {(caller_owner, caller, helper), (helper, site, target)}
    matches = []
    for lineno, row in native_sites.csv_rows(root, EDGES, {"owner_rva", "site_rva", "target_rva", "basis"}, numbered=True):
        edge = tuple(native_targets.address(row[k]) for k in ("owner_rva", "site_rva", "target_rva"))
        if edge in expected:
            matches.append((edge, f"{EDGES}#L{lineno}"))
    require(len(matches) == 2 and {e for e, _ in matches} == expected, "named callback edge missing or duplicated")
    return [hex(caller), hex(target)], {"site_rva": hex(site), "caller_rva": hex(caller), "target_rva": hex(target),
                "helper_rva": hex(helper), "dispatch_slot": hex(slot), "argument_rva": hex(path["argument"]),
                "source": [EVIDENCE + "#local_callback", line, *(ref for _, ref in matches)],
                "condition": "named direct caller, returning Win64 ABI call, both helper tests fall through",
                "all_callers_exhausted": False}


def check(data, root):
    import iced_x86
    import pefile
    root = root.resolve()
    report = {"scope": SCOPE, "status": "pass", "metrics": {}, "findings": [], "paths": {}}
    try:
        proof = json.loads(native_sites.safe_path(root, EVIDENCE).read_bytes(), object_pairs_hook=native_targets.unique_object)
        require(isinstance(proof, dict) and proof.get("original_sha256") == hashlib.sha256(data).hexdigest(),
                "submitted callback evidence original SHA-256 differs")
        dispositions = list(native_sites.csv_rows(root, DISPOSITIONS, {"owner_rva", "site_rva", "state"}, numbered=True))
        with pefile.PE(data=data) as pe:
            image = Image(data, pe, iced_x86)
            for name, member, verify in (("section_gate", "optional_callback", section_gate),
                                         ("one_callback", "local_callback", one_callback)):
                try:
                    value, verified = verify(image, proof, dispositions, root)
                    report["metrics"][name], report["paths"][name] = value, verified
                except (OSError, ValueError, KeyError, TypeError, csv.Error, pefile.PEFormatError) as exc:
                    claimed = proof.get(member)
                    site = claimed.get("site") if isinstance(claimed, dict) else None
                    severity = "inconclusive" if isinstance(exc, (OSError, pefile.PEFormatError)) else "fail"
                    report["findings"].append({"code": "callback_path_unverified", "path": name,
                                               "site_rva": site, "source": EVIDENCE + "#" + member, "detail": str(exc),
                                               "severity": severity})
    except (OSError, ValueError, KeyError, TypeError, csv.Error, pefile.PEFormatError) as exc:
        severity = "inconclusive" if isinstance(exc, (OSError, pefile.PEFormatError)) else "fail"
        report["findings"].append({"code": "callback_evidence_unavailable", "detail": str(exc), "severity": severity})
    levels = {finding["severity"] for finding in report["findings"]}
    report["status"] = "fail" if "fail" in levels else "inconclusive" if levels else "pass"
    return report
