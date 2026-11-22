"""Read-only audit of native transfer registrations in an existing PE delivery."""

import bisect
import csv
import hashlib
import re
from collections import Counter, defaultdict, deque
from pathlib import Path, PureWindowsPath


SCOPE = ("PE x86/x64: verify instruction bytes and single-instruction lengths in submitted "
         "native listings, and compare indirect transfers and static IAT targets with calls.csv. "
         "Also check listing coverage against a bounded static walk from original PE roots. "
         "Verify declared direct internal edges and distinguish IAT references from control transfers. "
         "Function discovery, all possible instruction boundaries, arbitrary data references, source equivalence "
         "and runtime target sets are outside this check.")
LINE = re.compile(r"^\s*(?:0[xX])?([0-9a-fA-F]{4,16})\s*:?\s+"
                  r"((?:[0-9a-fA-F]{2}[ \t]+)*[0-9a-fA-F]{2})(?=\s|$)")
ADDRESS = re.compile(r"^\s*(?:0[xX])?[0-9a-fA-F]{4,16}(?=[:\s])")
REF = re.compile(r"^(.+)#L(\d+)(?:-L(\d+))?$")
SITE = re.compile(r"(?:\bsite(?:\s+rva)?|指令\s*RVA)\s*[:=]?\s*(0x[0-9a-f]+)\b", re.I)
OWNER = re.compile(r"^\s*;\s*(?:FUNC\s+|owner\s+)(?:0x)?([0-9a-f]+)\b", re.I)
CLAIM_CLASSES = {"external", "boundary", "unresolved"}
ALIASES = {"retn": "ret", "retq": "ret", "callq": "call", "jmpq": "jmp", "jz": "je", "jnz": "jne",
           "jc": "jb", "jnae": "jb", "jnb": "jae", "jnc": "jae", "jna": "jbe", "jnbe": "ja",
           "jpe": "jp", "jpo": "jnp", "jnge": "jl", "jnl": "jge", "jng": "jle", "jnle": "jg",
           "loopz": "loope", "loopnz": "loopne"}
DISPLAY_PREFIX = re.compile(r"^(?:(?:rep(?:e|ne|z|nz)?|lock|bnd|notrack|data16|addr32)[.\s]+)*", re.I)
ORIGINAL_WALK_LIMIT = 200_000


def parse_ref(value):
    m = REF.fullmatch(value or "")
    if m:
        path, lo, hi = m.groups()
        lo, hi = int(lo), int(hi or lo)
        if lo > 0 and hi >= lo:
            return path.replace("\\", "/"), lo, hi
    return None


def safe_path(root, name):
    relative = PureWindowsPath(name)
    if relative.drive or relative.root or ".." in relative.parts or ":" in name:
        raise ValueError(f"Unsafe delivery path {name!r}")
    target = (root / name).resolve()
    if not target.is_relative_to(root):
        raise ValueError(f"Path outside delivery: {name!r}")
    return target


def csv_rows(root, name, *schemas, numbered=False):
    with safe_path(root, name).open(encoding="utf-8-sig", newline="") as f:
        reader = csv.DictReader(f, strict=True)
        header = reader.fieldnames or []
        if len(set(header)) != len(header) or sum(fields.issubset(header) for fields in schemas) != 1:
            raise ValueError(f"Invalid {name} header")
        for row in reader:
            if None in row or any(value is None for value in row.values()):
                raise ValueError(f"Incomplete {name} row at line {reader.line_num}")
            yield (reader.line_num, row) if numbered else row


def original_reachability(pe, bits, x86, mapped, decode, listed, result):
    """Compare original-rooted instruction boundaries to the verified delivery listings."""
    roots, ends = {}, set()
    stops = {}

    def diagnostic(reason, rva):
        group = stops.setdefault(reason, {"count": 0, "example_rvas": []})
        group["count"] += 1
        if len(group["example_rvas"]) < 12:
            group["example_rvas"].append(hex(rva))

    entry = pe.OPTIONAL_HEADER.AddressOfEntryPoint
    if entry:
        if mapped(entry):
            roots[entry] = "entry_point"
        else:
            diagnostic("unmapped_entry_point", entry)
    if bits == 64:
        entries = getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ())
        directories = pe.OPTIONAL_HEADER.DATA_DIRECTORY
        if len(directories) > 3 and directories[3].Size != 12 * len(entries):
            diagnostic("exception_directory_incomplete", directories[3].VirtualAddress)
        for item in entries:
            begin, end = item.struct.BeginAddress, item.struct.EndAddress
            region = mapped(begin)
            if region and 0 < end - begin <= region[1]:
                roots.setdefault(begin, "exception_function")
                ends.add(end)
            else:
                diagnostic("invalid_exception_range", begin)
    exports = getattr(pe, "DIRECTORY_ENTRY_EXPORT", None)
    if exports:
        for symbol in exports.symbols:
            if symbol.address and not symbol.forwarder and mapped(symbol.address):
                # An executable section can also contain exported objects. Its export RVA alone
                # does not certify a function boundary.
                roots.setdefault(symbol.address, "executable_section_export")
    elif pe.OPTIONAL_HEADER.DATA_DIRECTORY and pe.OPTIONAL_HEADER.DATA_DIRECTORY[0].VirtualAddress:
        diagnostic("export_directory_unreadable", pe.OPTIONAL_HEADER.DATA_DIRECTORY[0].VirtualAddress)

    flows = x86.FlowControl
    indirect = {flows.INDIRECT_BRANCH: "indirect_jump", flows.INDIRECT_CALL: "indirect_call"}
    direct = {flows.CALL, flows.CONDITIONAL_BRANCH, flows.UNCONDITIONAL_BRANCH}
    fallthrough = {flows.NEXT, flows.CONDITIONAL_BRANCH, flows.CALL, flows.INDIRECT_CALL}
    terminal = {flows.RETURN, flows.EXCEPTION, flows.INTERRUPT, flows.INDIRECT_BRANCH, flows.UNCONDITIONAL_BRANCH}
    near = {x86.OpKind.NEAR_BRANCH16, x86.OpKind.NEAR_BRANCH32, x86.OpKind.NEAR_BRANCH64}
    base = pe.OPTIONAL_HEADER.ImageBase
    boundaries = sorted(ends)
    predecessors = {rva: (rva, None, "root") for rva in sorted(roots)}
    queue = deque(predecessors)
    nodes = {}
    while queue and len(nodes) < ORIGINAL_WALK_LIMIT:
        rva = queue.popleft()
        ins = decode(rva)
        nodes[rva] = (1, (), None)
        if ins is None or ins.is_invalid:
            diagnostic("undecodable_instruction", rva)
            continue
        following = rva + ins.len
        end_index = bisect.bisect_right(boundaries, rva)
        if end_index < len(boundaries) and boundaries[end_index] < following:
            diagnostic("instruction_crosses_exception_end", rva)
            continue
        flow = ins.flow_control
        neighbours = []
        if flow in direct:
            if ins.op0_kind not in near:
                diagnostic("unsupported_direct_operand", rva)
                continue
            neighbours.append((ins.near_branch_target - base, "direct_target"))
        if flow in fallthrough:
            # A call continuation is a structural return address, conditional on the call returning.
            # A PE runtime-function end cannot by itself establish a new function's fallthrough.
            if following not in ends:
                edge = "call_continuation" if flow in {flows.CALL, flows.INDIRECT_CALL} else "fallthrough"
                neighbours.append((following, edge))
            elif following not in roots:
                diagnostic("fallthrough_at_exception_end", rva)
        elif flow not in terminal:
            diagnostic("unmodeled_control_flow", rva)
        valid = []
        for target, edge in neighbours:
            if not mapped(target):
                diagnostic("unmapped_" + edge, rva)
                continue
            valid.append((target, edge))
            if target not in predecessors:
                predecessors[target] = (predecessors[rva][0], rva, edge)
                queue.append(target)
        nodes[rva] = (ins.len, valid, indirect.get(flow))
    capped = bool(queue)
    if capped:
        diagnostic("instruction_budget_exhausted", queue[0])

    # Two reachable starts may overlap even if the competing interpretation was found later.
    # Remove both starts and re-establish reachability, so their descendants need an independent path.
    conflicts = set()
    active = []
    for rva in sorted(nodes):
        active = [(addr, end) for addr, end in active if end > rva]
        if active:
            conflicts.add(rva)
            conflicts.update(addr for addr, _ in active)
        active.append((rva, rva + nodes[rva][0]))
    for site in sorted(conflicts):
        diagnostic("overlapping_original_boundaries", site)
    confirmed = {rva: (rva, None, "root") for rva in sorted(roots)
                 if not capped and roots[rva] != "executable_section_export" and rva not in conflicts}
    queue = deque(confirmed)
    while queue:
        rva = queue.popleft()
        for target, edge in nodes[rva][1]:
            if target not in conflicts and target not in confirmed:
                confirmed[target] = (confirmed[rva][0], rva, edge)
                queue.append(target)

    records = []
    confirmed_indirect = 0
    for site, (_, _, kind) in sorted(nodes.items()):
        if kind is None:
            continue
        certain = site in confirmed
        confirmed_indirect += int(certain)
        if site in listed:
            continue
        root, prev, edge = (confirmed if certain else predecessors)[site]
        if certain:
            basis = "unambiguous_code_root_path"
        elif capped:
            basis = "walk_budget_exhausted"
        elif site in conflicts:
            basis = "overlapping_instruction_boundary"
        elif roots[root] == "executable_section_export":
            basis = "export_root_without_independent_code_path"
        else:
            basis = "path_depends_on_overlapping_boundaries"
        records.append({"site_rva": hex(site), "transfer": kind, "root_rva": hex(root), "root_kind": roots[root],
                        "predecessor_rva": hex(prev) if prev is not None else None, "edge": edge,
                        "basis": basis, "status": "fail" if certain else "inconclusive"})
    for level in ("fail", "inconclusive"):
        selected = [item for item in records if item["status"] == level]
        if selected:
            code = "original_unlisted_transfer" if level == "fail" else "original_candidate_unlisted_transfer"
            result["findings"].append({"severity": level, "code": code, "site_rva": selected[0]["site_rva"],
                                       "message": f"{len(selected)} indirect sites lack verified listing instructions. "
                                                  "Per-site evidence is in original_reachability.unlisted_transfers."})
    if stops or not any(kind != "executable_section_export" for kind in roots.values()):
        result["findings"].append({"severity": "inconclusive", "code": "original_walk_limits",
                                   "message": "Original-root walk has diagnostic stops or no verified code roots. See original_reachability."})
    result["original_reachability"] = {
        "basis": "Original file-backed x86/x64 instruction boundaries from PE roots through direct targets and ordinary "
                 "fallthrough, including potential return from calls. Indirect destinations and runtime execution are unknown. "
                 "An unlisted failure requires a path from the PE entry or a valid runtime-function entry avoiding "
                 "overlapping original boundaries. Export-only paths, conflicts and a capped walk are provisional.",
        "instruction_limit": ORIGINAL_WALK_LIMIT, "examined_starts": len(nodes), "budget_exhausted": capped,
        "roots_by_kind": dict(Counter(roots.values())), "diagnostics": stops, "unlisted_transfers": records}
    unlisted = sum(item["status"] == "fail" for item in records)
    result["metrics"].update(original_reachable_indirect_sites=confirmed_indirect,
                             original_reachable_unlisted_sites=unlisted,
                             original_candidate_unlisted_sites=len(records) - unlisted)
    return set(confirmed)


def provider_exports(provider, pefile, result):
    if provider is None:
        return {}
    path, digest = provider
    try:
        data = Path(path).read_bytes()
        actual = hashlib.sha256(data).hexdigest()
        if actual != digest.lower():
            raise ValueError("Provider SHA-256 differs from the supplied fingerprint.")
        with pefile.PE(data=data, fast_load=True) as pe:
            pe.parse_data_directories(directories=[0])
            exports = getattr(pe, "DIRECTORY_ENTRY_EXPORT", None)
            if not exports:
                raise ValueError("Provider has no readable export directory.")
            name = (pe.get_string_at_rva(exports.struct.Name) or b"").decode("ascii").casefold()
            if not name:
                raise ValueError("Missing provider DLL name in export directory.")
            found = {}
            for symbol in exports.symbols:
                if symbol.forwarder or not symbol.address:
                    continue
                sections = [s for s in pe.sections if s.VirtualAddress <= symbol.address <
                            s.VirtualAddress + (s.Misc_VirtualSize or s.SizeOfRawData)]
                if len(sections) != 1:
                    continue
                section = sections[0]
                evidence = {"provider_sha256": actual, "export_rva": hex(symbol.address),
                            "section": section.Name.rstrip(b"\0").decode("ascii", "backslashreplace"),
                            "executable": bool(section.Characteristics & 0x20000000)}
                aliases = [f"#{symbol.ordinal}"]
                if symbol.name:
                    aliases.append(symbol.name.decode("ascii", "backslashreplace"))
                for alias in aliases:
                    key = (name, alias)
                    found[key] = evidence if key not in found or found[key] == evidence else None
            return found
    except (ValueError, OSError, pefile.PEFormatError) as err:
        result["findings"].append({"severity": "inconclusive", "code": "provider_evidence", "message": str(err)})
        return {}


def check(original: bytes, delivery: Path, provider=None) -> dict:
    result = {"status": "inconclusive", "scope": SCOPE, "findings": [], "metrics": {}}
    try:
        import iced_x86 as x86
        import pefile
    except ImportError as err:
        result["findings"].append({"severity": "inconclusive", "code": "dependency", "message": str(err)})
        return result
    try:
        pe = pefile.PE(data=original, fast_load=True)
        machine = pe.FILE_HEADER.Machine
        if (machine, pe.OPTIONAL_HEADER.Magic) not in {(0x14C, 0x10B), (0x8664, 0x20B)}:
            result["findings"].append({"severity": "inconclusive", "code": "architecture",
                                       "message": "This audit supports x86 PE32 and x64 PE32+."})
            return result
        with pe:
            _audit(original, delivery.resolve(), pe, 64 if machine == 0x8664 else 32, x86, result,
                   provider_exports(provider, pefile, result))
    except (OSError, UnicodeError, ValueError, csv.Error, pefile.PEFormatError) as err:
        result["findings"].append({"severity": "fail", "code": "invalid_input", "message": str(err)})
    levels = {row["severity"] for row in result["findings"]}
    result["status"] = "fail" if "fail" in levels else "inconclusive" if "inconclusive" in levels else "pass"
    return result


def _audit(original, root, pe, bits, x86, result, provider):
    findings, metrics = result["findings"], result["metrics"]

    def report(level, code, message, site=None, line=None):
        row = dict(severity=level, code=code, message=message)
        if site is not None:
            row["site_rva"] = hex(site)
        if line is not None:
            row["listing"] = line
        findings.append(row)

    base = pe.OPTIONAL_HEADER.ImageBase
    regions = []
    for section in pe.sections:
        if section.Characteristics & 0x20000000:
            length = min(section.Misc_VirtualSize or section.SizeOfRawData, section.SizeOfRawData)
            if section.PointerToRawData + length > len(original):
                raise ValueError("Truncated raw executable section")
            regions.append((section.VirtualAddress, section.VirtualAddress + length, section.PointerToRawData))

    def mapped(rva):
        found = [(raw + rva - lo, hi - rva) for lo, hi, raw in regions if lo <= rva < hi]
        return found[0] if len(found) == 1 else None

    def normalize(address):
        choices = {i for i in (address, address - base) if mapped(i)}
        return choices.pop() if len(choices) == 1 else None

    pe.parse_data_directories(directories=[0, 1, 3, 13])
    iat = {}
    complete_imports = True
    for index, attr in ((1, "DIRECTORY_ENTRY_IMPORT"), (13, "DIRECTORY_ENTRY_DELAY_IMPORT")):
        directories = pe.OPTIONAL_HEADER.DATA_DIRECTORY
        if index < len(directories) and directories[index].VirtualAddress and not hasattr(pe, attr):
            complete_imports = False
        for module in getattr(pe, attr, ()):
            for symbol in module.imports:
                # pefile may attach a friendly name to an import that the original binds by ordinal.
                name = f"#{symbol.ordinal}" if symbol.import_by_ordinal else symbol.name.decode("ascii", "backslashreplace")
                key = symbol.address - base
                ident = (module.dll.decode("ascii", "backslashreplace").casefold(), name)
                if key in iat and iat[key] != ident:
                    complete_imports = False
                iat[key] = ident
    if not complete_imports:
        report("inconclusive", "import_directory", "Import descriptors could not be fully or uniquely mapped.")

    flows = x86.FlowControl
    indirect = {flows.INDIRECT_CALL, flows.INDIRECT_BRANCH}
    direct = {flows.CALL, flows.UNCONDITIONAL_BRANCH, flows.CONDITIONAL_BRANCH}
    near = {x86.OpKind.NEAR_BRANCH16, x86.OpKind.NEAR_BRANCH32, x86.OpKind.NEAR_BRANCH64}
    next_flow = {flows.NEXT, flows.CONDITIONAL_BRANCH, flows.CALL, flows.INDIRECT_CALL}

    def text_conflict(ins, text):
        # Compare only recognized, unambiguous Intel spellings. Symbols and expressions need other evidence.
        clean = DISPLAY_PREFIX.sub("", text.split(";", 1)[0].strip().casefold()).split(None, 1)
        if not clean:
            return None
        mnemonic = ALIASES.get(clean[0], clean[0])
        displayed = getattr(x86.Mnemonic, mnemonic.upper(), None)
        is_transfer = ins.flow_control in indirect | direct | {flows.RETURN}
        names_control = mnemonic.startswith(("j", "loop")) or mnemonic in {"call", "ret", "retf"}
        if displayed is not None and (is_transfer or names_control) and displayed != ins.mnemonic:
            return "Displayed instruction mnemonic disagrees with original bytes."
        if not is_transfer or len(clean) != 2:
            return None
        operand = clean[1].strip()
        if ins.op0_kind == x86.OpKind.REGISTER:
            shown = getattr(x86.Register, operand.upper(), None)
            if shown is not None and shown != ins.op0_register:
                return "Displayed transfer register disagrees with original bytes."
        if ins.op0_kind in near:
            numeric = re.fullmatch(r"(?:(?:short|near(?: ptr)?)\s+)?(?:0x([0-9a-f]+)|([0-9][0-9a-f]*)h)", operand)
            if numeric and int(numeric[1] or numeric[2], 16) not in {ins.near_branch_target, ins.near_branch_target - base}:
                return "Displayed direct branch target disagrees with original bytes."
        return None

    def static_memory(ins):
        if not any(ins.op_kind(i) == x86.OpKind.MEMORY for i in range(ins.op_count)):
            return None
        if ins.segment_prefix in (x86.Register.FS, x86.Register.GS):
            return None
        if ins.is_ip_rel_memory_operand:
            return ins.ip_rel_memory_address - base
        if ins.memory_base == x86.Register.NONE and ins.memory_index == x86.Register.NONE:
            return ins.memory_displacement - base
        return None

    def slot_of(ins):
        if ins.flow_control in indirect and ins.op0_kind == x86.OpKind.MEMORY:
            return static_memory(ins)
        return None

    def decode(rva):
        mapping = mapped(rva)
        if mapping:
            offset, remaining = mapping
            return x86.Decoder(bits, original[offset:offset + min(15, remaining)], ip=base + rva).decode()
        return None

    def import_veneer(ins):
        # Only accept an unbroken chain of unconditional direct jumps ending at an IAT jump.
        if ins.op0_kind not in near:
            return None
        target = ins.near_branch_target - base
        seen = set()
        while target not in seen and len(seen) < 32:
            seen.add(target)
            jump = decode(target)
            if jump is None:
                break
            if jump.flow_control == flows.INDIRECT_BRANCH:
                return iat.get(slot_of(jump))
            if jump.flow_control != flows.UNCONDITIONAL_BRANCH or jump.op0_kind not in near:
                break
            target = jump.near_branch_target - base
        return None

    try:
        rows = [(line, r) for line, r in csv_rows(root, "calls.csv", {"kind", "caller", "class", "callee", "listing", "note"}, numbered=True)
                if r["kind"].casefold() == "native"]
    except (OSError, ValueError, csv.Error) as err:
        report("fail", "invalid_input", str(err))
        rows = []
    files = set()
    default = "code/native.asm"
    if safe_path(root, default).is_file():
        files.add(default)
    coverage = safe_path(root, "coverage.csv")
    if coverage.is_file():
        try:
            for row in csv_rows(root, "coverage.csv", {"kind", "listing"}):
                ref = parse_ref(row["listing"])
                if row["kind"].casefold() == "native" and ref and ref[0].lower().endswith(".asm"):
                    files.add(ref[0])
        except (OSError, ValueError, csv.Error) as err:
            report("fail", "invalid_input", str(err))
    for _, row in rows:
        ref = parse_ref(row["listing"])
        if ref and ref[0].lower().endswith(".asm"):
            files.add(ref[0])

    instructions = {}
    owners = defaultdict(set)
    by_file = {}
    for name in sorted(files):
        path = safe_path(root, name)
        if not path.is_file():
            report("fail", "missing_listing", "Referenced native listing file is absent.", line=name)
            continue
        line_numbers, sites = [], []
        owner = None
        with path.open(encoding="utf-8-sig") as stream:
            for num, line in enumerate(stream, 1):
                match = LINE.match(line)
                where = f"{name}#L{num}"
                if not match:
                    label = OWNER.match(line)
                    if label:
                        owner = normalize(int(label[1], 16))
                    if ADDRESS.match(line):
                        report("inconclusive", "unsupported_listing_line", "Cannot read instruction bytes.", line=where)
                    continue
                rva = normalize(int(match[1], 16))
                raw = bytes.fromhex(match[2])
                if rva is None:
                    report("fail", "unmapped_listing", "Listing address is not uniquely in an executable section.", line=where)
                    continue
                offset, remaining = mapped(rva)
                if len(raw) > remaining or original[offset:offset + len(raw)] != raw:
                    report("fail", "listing_bytes", "Listed bytes differ from original.", rva, where)
                    continue
                instruction = instructions.get(rva)
                if instruction is None:
                    instruction = decode(rva)
                if instruction.is_invalid or instruction.len != len(raw):
                    report("fail", "instruction_length", "Listed bytes do not encode exactly one instruction.", rva, where)
                    continue
                conflict = text_conflict(instruction, line[match.end():])
                if conflict:
                    report("fail", "listing_flow_text", conflict, rva, where)
                instructions[rva] = instruction
                if owner is not None:
                    owners[rva].add(owner)
                line_numbers.append(num)
                sites.append(rva)
        by_file[name] = (line_numbers, sites, num if line_numbers else 0)
    metrics.update(instruction_sites=len(instructions), native_call_rows=len(rows), listing_files=len(files))
    proven_starts = original_reachability(pe, bits, x86, mapped, decode, instructions, result)
    if not instructions:
        report("inconclusive", "no_native_listing", "No independently decodable instruction sites available.")

    ordered = sorted(instructions)
    end = 0
    for rva in ordered:
        if rva < end:
            report("inconclusive", "overlapping_decode", "Overlapping instruction interpretations require review.", rva)
        end = max(end, rva + instructions[rva].len)
    anchors = {pe.OPTIONAL_HEADER.AddressOfEntryPoint}
    if bits == 64:
        anchors.update(x.struct.BeginAddress for x in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ()))
    exports = getattr(pe, "DIRECTORY_ENTRY_EXPORT", None)
    if exports:
        anchors.update(x.address for x in exports.symbols if x.address and not x.forwarder)
    anchors = {a for a in anchors if mapped(a)}
    pending = list(anchors & instructions.keys())
    reached = set()
    frontier = set()
    while pending:
        rva = pending.pop()
        if rva in reached:
            continue
        reached.add(rva)
        ins = instructions[rva]
        neighbours = []
        if ins.flow_control in next_flow:
            neighbours.append(rva + ins.len)
        if ins.op0_kind in near:
            neighbours.append(ins.near_branch_target - base)
        for n in neighbours:
            if n in instructions:
                if n not in reached:
                    pending.append(n)
            elif mapped(n):
                frontier.add(n)
    metrics.update(original_roots=len(anchors), listed_roots=len(anchors & instructions.keys()),
                   root_connected_instruction_sites=len(reached), unlisted_successor_sites=len(frontier))
    if len(reached) < len(instructions) or anchors - instructions.keys() or frontier:
        report("inconclusive", "boundary_coverage",
               "Checked roots, successor positions and listed boundaries do not all connect in the supplied listing.")

    expected = {rva for rva, ins in instructions.items() if ins.flow_control in indirect}
    counts = Counter()
    known_iat = {rva for rva in expected if slot_of(instructions[rva]) in iat}
    explicit_unresolved = set()
    unresolved_pairs = defaultdict(list)
    main_rows = defaultdict(list)
    route_rows = defaultdict(list) if safe_path(root, "code/import-callers.csv").is_file() else None
    data_sites = defaultdict(dict)
    qualified_slot = re.compile(r"IAT\s+(0x[0-9a-f]+)\s+\(([^()!]+)!([^()!]+)\)", re.I)
    for row_index, row in rows:
        cls = row["class"].strip().casefold()
        if cls == "data" and "!" not in row["callee"]:
            continue
        ref = parse_ref(row["listing"])
        if not ref or ref[0] not in by_file:
            report("fail", "invalid_reference", f"Native control record {row_index} lacks a supported listing reference.")
            continue
        name, lo, hi = ref
        numbers, addresses, last_line = by_file[name]
        starts, stops = bisect.bisect_left(numbers, lo), bisect.bisect_right(numbers, hi)
        candidates = set(addresses[starts:stops])
        site_hint = SITE.search(row["note"])
        if site_hint:
            candidates &= {normalize(int(site_hint[1], 16))}
        if len(candidates) != 1 or hi > last_line:
            report("fail" if not candidates or hi > last_line else "inconclusive", "ambiguous_reference",
                   "Reference must identify a single original transfer instruction.", line=row["listing"])
            continue
        site = candidates.pop()
        ins = instructions[site]
        raw_owner = None
        owner = None
        if owners[site] or (cls != "data" and (ins.flow_control == flows.INDIRECT_CALL or cls == "unresolved")):
            try:
                raw_owner = int(row["caller"], 0)
                owner = normalize(raw_owner)
            except ValueError:
                report("fail", "invalid_caller", f"calls.csv#L{row_index} lacks a numeric caller.", site, row["listing"])
            if owners[site] and owner not in owners[site]:
                report("inconclusive", "caller_ownership", "Caller and listing ownership require reconciliation.", site, row["listing"])
        if cls == "data":
            label = row["callee"].strip()
            wrapped = qualified_slot.fullmatch(label)
            dll, _, symbol = label.partition("!")
            slot = static_memory(ins)
            if wrapped:
                dll, symbol = wrapped[2], wrapped[3]
            ident = (dll.casefold(), symbol)
            if iat.get(slot) != ident or (wrapped and int(wrapped[1], 16) != slot):
                report("fail", "data_iat_target", "Declared import operand disagrees with the original IAT slot.",
                       site, row["listing"])
                continue
            if site in data_sites[ident]:
                report("fail", "duplicate_data_import", "Repeated import operand registration.", site, row["listing"])
            data_sites[ident][site] = slot
            continue
        if ins.flow_control in indirect and raw_owner is not None:
            dll, sep, symbol = row["callee"].strip().partition("!")
            matched_iat = (cls == "external" and bool(sep) and (dll.casefold(), symbol) == iat.get(slot_of(ins)))
            main_rows[site].append({"owner": owner if owner is not None else raw_owner, "source": f"calls.csv#L{row_index}",
                                    "listing": row["listing"], "callee": row["callee"], "classification": cls,
                                    "known_iat": matched_iat})
        if route_rows is not None and ins.flow_control in direct:
            route_rows[site].append({"source": f"calls.csv#L{row_index}", "caller": row["caller"],
                                     "listing": row["listing"], "callee": row["callee"], "classification": cls})
        if cls not in CLAIM_CLASSES:
            report("fail", "invalid_class", f"Unrecognized native transfer class {cls!r}.", site, row["listing"])
            continue
        if ins.flow_control not in indirect | direct:
            report("fail", "non_transfer_claim", "Record labels a non-transfer instruction as a call or jump.", site, row["listing"])
            continue
        counts[site] += 1
        destination = iat.get(slot_of(ins)) if ins.flow_control in indirect else import_veneer(ins)
        if destination is not None:
            dll, sep, symbol = row["callee"].strip().partition("!")
            if cls != "external" or not sep or (dll.casefold(), symbol) != destination:
                report("fail", "iat_target", "Classification or destination differs from the original import slot.", site, row["listing"])
        elif cls == "unresolved":
            explicit_unresolved.add(site)
            if raw_owner is not None:
                unresolved_pairs[(raw_owner, site)].append({"source": f"calls.csv#L{row_index}", "listing": row["listing"]})
        else:
            report("inconclusive", "target_evidence", "Target or boundary needs evidence beyond this local instruction.", site, row["listing"])

    incoming = defaultdict(set)
    fallthrough = defaultdict(set)
    for site, ins in instructions.items():
        if ins.flow_control in direct and ins.op0_kind in near:
            incoming[ins.near_branch_target - base].add(site)
        if ins.flow_control in next_flow:
            fallthrough[site + ins.len].add(site)

    # Explicit direct edges bind to decoded original operands. Rows describing a possible
    # indirect destination give only registration, regardless of how many candidates they list.
    internal = set()
    verified_direct = set()
    sidecar = safe_path(root, "internal-transfers.csv")
    if sidecar.is_file():
        modern = {"site_rva", "target_rva", "basis"}
        legacy = {"owner", "site", "target", "target_owner", "instruction"}
        for row in csv_rows(root, "internal-transfers.csv", modern, legacy):
            old = legacy.issubset(row)
            site = int(row["site" if old else "site_rva"], 0)
            target = int(row["target" if old else "target_rva"], 0)
            is_direct = old or row["basis"].strip().casefold() == "direct"
            if is_direct:
                ins = decode(site)
                if (not ins or ins.is_invalid or ins.flow_control not in direct or ins.op0_kind not in near
                        or not mapped(target) or ins.near_branch_target - base != target):
                    report("fail", "internal_direct_target", f"Declared direct edge to {hex(target)} disagrees with original.", site)
                    continue
                if old:
                    words = DISPLAY_PREFIX.sub("", row["instruction"].strip().casefold()).split()
                    mnemonic = ALIASES.get(words[0], words[0]) if words else ""
                    if getattr(x86.Mnemonic, mnemonic.upper(), None) != ins.mnemonic or text_conflict(ins, row["instruction"]):
                        report("fail", "internal_direct_instruction", "Legacy instruction disagrees with original.", site)
                        continue
                owner_text = row["owner"] if old else row.get("owner_rva")
                endpoints = [(site, owner_text)]
                if old:
                    endpoints.append((target, row["target_owner"]))
                if any(value is not None and (not mapped(int(value, 0)) or
                       (owners[rva] and int(value, 0) not in owners[rva])) for rva, value in endpoints):
                    report("inconclusive", "internal_owner", "Declared ownership requires reconciliation.", site)
                if site in verified_direct:
                    report("fail", "duplicate_internal_direct", "Repeated direct edge registration.", site)
                verified_direct.add(site)
                incoming[target].add(site)
                continue
            if site in expected and site not in known_iat and site not in counts and row["basis"].strip() and mapped(target):
                internal.add(site)
        if internal:
            report("inconclusive", "internal_destinations",
                   f"{len(internal)} transfer sites use internal edge evidence; path constraints require independent review.")
        unlisted = sorted(verified_direct - instructions.keys())
        if unlisted:
            report("inconclusive", "internal_boundary",
                   f"{len(unlisted)} direct operands match original bytes at boundaries absent from the verified listings.",
                   unlisted[0])

    # A gap named in a sidecar must still have its unresolved native row at the same caller and site.
    gaps = set()
    gap_records = []
    if safe_path(root, "control-gaps.csv").is_file():
        for line, row in csv_rows(root, "control-gaps.csv", {"owner_rva", "site_rva", "observation"}, numbered=True):
            owner, site = int(row["owner_rva"], 0), int(row["site_rva"], 0)
            gap_records.append({"owner_rva": hex(owner), "site_rva": hex(site), "source": f"control-gaps.csv#L{line}",
                                "submitted_observation": row["observation"],
                                "unresolved_main_rows": unresolved_pairs.get((owner, site), [])})
            if (owner, site) in gaps:
                report("fail", "duplicate_control_gap", "Repeated control gap registration.", site)
            gaps.add((owner, site))
            if (owner, site) not in unresolved_pairs:
                report("fail", "control_gap_main_row", "No unresolved calls.csv record matches this gap's owner and site.", site)
                internal.discard(site)
        for _, site in sorted(unresolved_pairs.keys() - gaps):
            report("fail", "control_gap_sidecar_row", "Unresolved main-table record is absent from the supplied gap index.", site)
    result["control_gap_records"] = gap_records
    unresolved = explicit_unresolved | {site for _, site in gaps}

    # Discover uses of trusted non-executable exports even when a submission omits its data records.
    declared_data = {(ident, site) for ident, sites in data_sites.items() for site in sites}
    data_slots = {slot: ident for slot, ident in iat.items() if provider.get(ident) and not provider[ident]["executable"]}
    if data_slots:
        for ident in data_slots.values():
            data_sites.setdefault(ident, {})
        for site, ins in instructions.items():
            slot = static_memory(ins)
            if slot in data_slots:
                data_sites[data_slots[slot]][site] = slot

    # An IAT operand in an instruction may be listed as data alongside its control record.
    # Without such a record, only a standalone JMP thunk may be explained as a data import.
    details = []
    for ident, sites in sorted(data_sites.items()):
        provider_export = provider.get(ident)
        reads = []
        stubs = []
        observed_jumps = []
        for site, slot in sorted(sites.items()):
            ins = instructions[site]
            if site in expected:
                if ins.flow_control == flows.INDIRECT_BRANCH and ins.mnemonic == x86.Mnemonic.JMP:
                    observed_jumps.append(hex(site))
                if counts[site] or (ident, site) not in declared_data:
                    continue
                if ins.flow_control != flows.INDIRECT_BRANCH or ins.mnemonic != x86.Mnemonic.JMP:
                    report("fail", "data_hides_call", "An IAT operand registration does not account for an original call.", site)
                    continue
                counts[site] += 1
                callers = sorted(incoming[site])
                stubs.append({"site_rva": hex(site), "slot_rva": hex(slot),
                              "observed_direct_incoming_rvas": [hex(x) for x in callers],
                              "listed_fallthrough_rvas": [hex(x) for x in sorted(fallthrough[site])],
                              "pe_root": site in anchors})
                if callers or fallthrough[site] or site in anchors or (provider_export and provider_export["executable"]):
                    report("fail", "data_thunk_control", "Data-only thunk classification conflicts with a control entry or executable export.", site)
                elif not provider_export:
                    report("inconclusive", "data_thunk_provider", "A matching provider export section is required to verify the data-only thunk claim.", site)
            elif ins.mnemonic == x86.Mnemonic.MOV and ins.op0_kind == x86.OpKind.REGISTER and ins.op1_kind == x86.OpKind.MEMORY:
                read = {"site_rva": hex(site), "slot_rva": hex(slot)}
                following = decode(site + ins.len)
                if (following and not following.is_invalid and following.op_count == 2
                        and following.op1_kind == x86.OpKind.MEMORY and following.op0_kind == x86.OpKind.REGISTER
                        and following.memory_base == ins.op0_register and following.memory_index == x86.Register.NONE
                        and following.memory_displacement == 0 and following.segment_prefix == x86.Register.NONE
                        and following.mnemonic == x86.Mnemonic.MOVSD):
                    read["scalar_double_read_rva"] = hex(site + ins.len)
                reads.append(read)
        if stubs or (provider_export and not provider_export["executable"]):
            calls = set()
            for site in instructions.keys() | verified_direct:
                ins = instructions.get(site) or decode(site)
                if ((ins.flow_control == flows.INDIRECT_CALL and iat.get(slot_of(ins)) == ident)
                        or (ins.flow_control == flows.CALL and import_veneer(ins) == ident)):
                    calls.add(site)
            if calls and provider_export and not provider_export["executable"]:
                report("fail", "call_to_data_export", "Original call instruction targets a non-executable provider export.", min(calls))
            details.append({"import": "!".join(ident), "provider_export": provider_export,
                            "slot_reads": reads, "data_registered_jump_thunks": stubs,
                            "observed_iat_jump_rvas": observed_jumps,
                            "observed_call_rvas": [hex(s) for s in sorted(calls)],
                            "observation_scope": "Verified listing instructions and declared direct edges decoded from original bytes."})
    result["data_import_evidence"] = details
    registered = (expected & counts.keys()) | internal
    missing = sorted(expected - registered)
    duplicates = sorted(site for site, count in counts.items() if count > 1)
    for site in missing:
        report("fail", "missing_transfer", "No native transfer record for this original-backed listing site.", site)
    for site in duplicates:
        report("fail", "duplicate_transfer", f"{counts[site]} native transfer registrations.", site)
    if unresolved:
        report("inconclusive", "unresolved_destinations", f"{len(unresolved)} registered destinations require other evidence.")
    metrics.update(verified_internal_direct_sites=len(verified_direct), sidecar_control_gap_sites=len({s for _, s in gaps}),
                   unresolved_site_rvas=[hex(s) for s in sorted(unresolved)])
    metrics.update(indirect_sites=len(expected), direct_iat_sites=len(known_iat),
                   registered_expected_sites=len(registered), internally_registered_sites=len(internal), missing_sites=len(missing),
                   duplicate_sites=len(duplicates), explicitly_unresolved_sites=len(explicit_unresolved),
                   missing_register_jumps=sum(instructions[s].flow_control == flows.INDIRECT_BRANCH
                                              and instructions[s].op0_kind == x86.OpKind.REGISTER for s in missing))
    # Keep previous coverage results available if the optional submitted target evidence is unreadable.
    try:
        if __package__:
            from .native_targets import audit
        else:
            from native_targets import audit
        audit(root, original, pe, bits, x86, instructions, owners, main_rows, report, result, proven_starts, by_file)
    except (ImportError, OSError) as err:
        report("inconclusive", "target_audit_unavailable", str(err))
    except (ValueError, csv.Error) as err:
        report("fail", "invalid_target_evidence", str(err))
    if route_rows is not None:
        if __package__:
            from .import_routes import audit as audit_import_routes
        else:
            from import_routes import audit as audit_import_routes
        result["import_routes"] = audit_import_routes(root, pe, bits, x86, decode, slot_of, iat if complete_imports else {},
                                                     owners, proven_starts, by_file, route_rows, report)
