"""Verify submitted AMD64 COM call witnesses against the original PE."""
import re
from collections import defaultdict, deque
from functools import lru_cache
from uuid import UUID

if __package__:
    from . import native_sites
else:
    import native_sites

TABLE = "code/com-call-sites.csv"
LEGACY_TABLE = "code/s25-idispatch-slots.csv"
BINDING = "code/s21-com-binding.csv"
LISTING = "code/native.asm"
SCOPE = ("AMD64 IDispatch calls: check submitted member names and byte displacements on "
         "normal Windows x64 ABI paths from a CoCreateInstance factory. "
         "Implementation address and module are unknown.")
MEMBERS = dict(enumerate(("IUnknown::QueryInterface", "IUnknown::AddRef", "IUnknown::Release",
                          "IDispatch::GetTypeInfoCount", "IDispatch::GetTypeInfo",
                          "IDispatch::GetIDsOfNames", "IDispatch::Invoke")))
IID = UUID("00020400-0000-0000-c000-000000000046").bytes_le

def number(value):
    if re.fullmatch(r"0[xX][0-9a-fA-F]{1,8}|[0-9]{1,10}", value):
        return int(value, 16 if value.lower().startswith("0x") else 10)
    return None


def listing_refs(root, sites):
    listing = defaultdict(list)
    owner = None
    for n, line in enumerate(native_sites.safe_path(root, LISTING).read_text(encoding="utf-8-sig").splitlines(), 1):
        label = native_sites.OWNER.match(line)
        if label:
            owner = int(label[1], 16)
        address = native_sites.LINE.match(line)
        if address and (site := int(address[1], 16)) in sites:
            listing[site].append((n, owner, bytes.fromhex(address[2])))
    calls = defaultdict(list)
    for row in native_sites.csv_rows(root, "calls.csv", {"caller", "callee", "listing"}):
        if row["callee"].lower().startswith("indirect@"):
            site = number(row["callee"].split("@")[1])
            if site in sites:
                calls[site].append((number(row["caller"]), native_sites.parse_ref(row["listing"])))
    return listing, calls



def _function(pe, owner, ends, x):
    """Use an unambiguous original function extent and complete instruction boundaries."""
    if len(ends[owner]) != 1:
        raise ValueError("Missing or ambiguous original function extent")
    size = ends[owner][0] - owner
    if size <= 0 or size > 65536:
        raise ValueError("Unsupported function size")
    sections = [s for s in pe.sections if s.VirtualAddress <= owner
                and ends[owner][0] <= s.VirtualAddress + min(s.Misc_VirtualSize, s.SizeOfRawData)]
    if len(sections) != 1 or not sections[0].Characteristics & 0x20000000:
        raise ValueError("Missing original file-backed executable range")
    data = pe.get_data(owner, size)
    code = {i.ip: i for i in x.Decoder(64, data, ip=owner)}
    if len(data) != size or any(i.is_invalid for i in code.values()):
        raise ValueError("Unsupported original function instructions")
    return code


def _terminal_reporter(pe, target, x):
    """Follow a bounded, acyclic reporter to a fail-fast or process termination."""
    ends = defaultdict(list)
    for entry in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ()):
        ends[entry.struct.BeginAddress].append(entry.struct.EndAddress)
    imports = {i.address - pe.OPTIONAL_HEADER.ImageBase: i.name
               for d in getattr(pe, "DIRECTORY_ENTRY_IMPORT", ())
               if d.dll.lower() in {b"kernel32.dll", b"kernelbase.dll"} for i in d.imports}
    info = x.InstructionInfoFactory()
    writes = {x.OpAccess.WRITE, x.OpAccess.COND_WRITE, x.OpAccess.READ_WRITE, x.OpAccess.READ_COND_WRITE}

    @lru_cache(maxsize=64)
    def terminal(start, depth):
        if depth > 3:
            return False
        try:
            code = _function(pe, start, ends, x)
        except ValueError:
            return False
        work = [(start, frozenset())]
        visited = set()
        while work:
            ip, handles = work.pop()
            if (ip, handles) in visited:
                continue
            visited.add((ip, handles))
            ins = code.get(ip)
            if ins is None or len(visited) > 512:
                return False
            flow = ins.flow_control
            api = imports.get(ins.ip_rel_memory_address) if ins.is_ip_rel_memory_operand else None
            if flow in {x.FlowControl.CALL, x.FlowControl.INDIRECT_CALL, x.FlowControl.INDIRECT_BRANCH}:
                if api == b"ExitProcess" or (api == b"TerminateProcess" and x.Register.RCX in handles):
                    continue
                if flow == x.FlowControl.INDIRECT_BRANCH:
                    return False
                if flow == x.FlowControl.CALL and terminal(ins.near_branch_target, depth + 1):
                    continue
                handles = frozenset({x.Register.RAX}) if api == b"GetCurrentProcess" else frozenset()
            elif flow in {x.FlowControl.UNCONDITIONAL_BRANCH, x.FlowControl.CONDITIONAL_BRANCH}:
                if ins.near_branch_target <= ip:
                    return False
                work.append((ins.near_branch_target, handles))
                if flow == x.FlowControl.UNCONDITIONAL_BRANCH:
                    continue
            elif ins.mnemonic == x.Mnemonic.INT and ins.immediate8 == 0x29:
                continue
            elif flow == x.FlowControl.NEXT:
                updated = set(handles)
                for used in info.info(ins).used_registers():
                    if used.access in writes:
                        updated.discard(x.RegisterExt.full_register(used.register))
                if (ins.mnemonic == x.Mnemonic.MOV and ins.op1_kind == x.OpKind.REGISTER
                        and ins.op1_register in handles and x.RegisterExt.is_gpr64(ins.op0_register)):
                    updated.add(ins.op0_register)
                handles = frozenset(updated)
            else:
                return False
            work.append((ins.next_ip, handles))
        return True
    return terminal(target, 0)

def _cookie_guard(pe, target, x):
    """MSVC x64 /GS guard normal return: success path only reads the cookie and RCX.

    Only handle the canonical leaf guard with both failure edges going to the
    same out-of-line reporter. A normal /GS return excludes stack-cookie failure.
    """
    directory = getattr(pe, "DIRECTORY_ENTRY_LOAD_CONFIG", None)
    if not directory or not getattr(directory.struct, "SecurityCookie", 0):
        return False
    cookie = directory.struct.SecurityCookie - pe.OPTIONAL_HEADER.ImageBase
    code = list(x.Decoder(64, pe.get_data(target, 64), ip=target))[:9]
    if len(code) != 9:
        return False
    cmp_, jne, rol, test, bad, ret, ror, jump, _ = code
    return (cmp_.mnemonic == x.Mnemonic.CMP and cmp_.op0_register == x.Register.RCX
            and cmp_.is_ip_rel_memory_operand and cmp_.ip_rel_memory_address == cookie
            and jne.mnemonic == bad.mnemonic == x.Mnemonic.JNE and jne.near_branch_target == jump.ip
            and bad.near_branch_target == ror.ip and rol.mnemonic == x.Mnemonic.ROL
            and ror.mnemonic == x.Mnemonic.ROR and rol.op0_register == ror.op0_register == x.Register.RCX
            and rol.immediate8 == ror.immediate8 == 16 and test.mnemonic == x.Mnemonic.TEST
            and test.op0_register == x.Register.CX and test.immediate16 == 65535
            and ret.code == x.Code.RETNQ and jump.flow_control == x.FlowControl.UNCONDITIONAL_BRANCH
            and _terminal_reporter(pe, jump.near_branch_target, x))


def _analyze(pe, code, entry, x, imports, *, via=None, factory=None):
    """Forward must analysis. Unknown register definitions, partial writes and joins kill facts."""
    R, K, M, FC = x.Register, x.OpKind, x.Mnemonic, x.FlowControl
    info = x.InstructionInfoFactory()
    written = {x.OpAccess.WRITE, x.OpAccess.COND_WRITE, x.OpAccess.READ_WRITE, x.OpAccess.READ_COND_WRITE}
    volatile = {R.RAX, R.RCX, R.RDX, R.R8, R.R9, R.R10, R.R11}
    states = {entry: {R.RSP: ("stack", 0)}}
    pending = deque([entry])
    returns = {}
    def stack(base, displacement):
        if isinstance(base, tuple):
            return ("stack", base[1] + displacement)
        return None

    while pending:
        site = pending.popleft()
        if site not in code:
            raise ValueError("Original control flow leaves supported function")
        i, old = code[site], states[site]
        state = old.copy()
        if i.has_segment_prefix:
            raise ValueError("Unsupported segment override")
        if i.flow_control == FC.RETURN:
            if i.code != x.Code.RETNQ:
                raise ValueError("Unsupported return")
            returns[site] = old.get(R.RAX)
            continue
        flow = i.flow_control
        succ = [i.next_ip]
        if flow in {FC.CONDITIONAL_BRANCH, FC.UNCONDITIONAL_BRANCH}:
            succ = [i.near_branch_target] + (succ if flow == FC.CONDITIONAL_BRANCH else [])
        elif flow in {FC.CALL, FC.INDIRECT_CALL}:
            for reg in volatile:
                state.pop(reg, None)
            # Home slots and escaped memory are caller-clobbered. The only
            # retained facts are nonvolatile registers and stack/frame addresses.
            for key in list(state):
                if isinstance(key, tuple):
                    del state[key]
            if site == via and "factory_call_executed" in old:
                raise ValueError("Repeated factory call in a loop")
            if site == via and i.op0_kind == K.NEAR_BRANCH64 and i.near_branch_target == factory:
                state[R.RAX] = "interface"
                state["factory_call_executed"] = True
            elif (via is None and i.is_ip_rel_memory_operand and i.ip_rel_memory_address in imports
                  and old.get(R.R9) == "iid"):
                output = old.get(stack(old.get(R.RSP), 32))
                if (isinstance(output, tuple) and isinstance(old.get(R.RSP), tuple)
                        and old[R.RSP][1] + 40 <= output[1] <= -8):
                    state[output] = "interface"
            elif (via is None and old.get(R.RAX) in {"interface", "zero", "nullable"}
                  and i.op0_kind == K.NEAR_BRANCH64 and _cookie_guard(pe, i.near_branch_target, x)):
                state[R.RAX] = old[R.RAX]
        elif flow == FC.INTERRUPT and i.mnemonic in {M.INT3, M.INT}:
            if i.mnemonic == M.INT and i.immediate8 != 0x29:
                raise ValueError("Unsupported interrupt")
            continue
        elif flow != FC.NEXT:
            raise ValueError("Unsupported original control flow")
        else:
            details = info.info(i)
            for used in details.used_registers():
                if used.access in written:
                    state.pop(x.RegisterExt.full_register(used.register), None)
            base = old.get(i.memory_base)
            address = stack(base, i.memory_displacement if i.memory_displacement < 2**63 else
                            i.memory_displacement - 2**64) if i.memory_index == R.NONE else None
            if any(m.access in written for m in details.used_memory()):
                if base in {"interface", "vtable"}:
                    raise ValueError("Unsupported mutation of interface or vtable")
                # Invalidate overlapping stack ranges, including partial writes.
                for key in list(state):
                    if isinstance(key, tuple) and (address is None or abs(key[1] - address[1]) <
                            max(8, x.MemorySizeExt.size(i.memory_size))):
                        del state[key]
            dest, src = i.op0_register, i.op1_register
            value = None
            if i.mnemonic == M.MOV and i.op0_kind == K.REGISTER and x.RegisterExt.is_gpr64(dest):
                if i.op1_kind == K.REGISTER:
                    value = old.get(src)
                elif i.op1_kind == K.MEMORY:
                    if base == "interface" and i.memory_index == R.NONE and not i.memory_displacement:
                        value = "vtable"
                    else:
                        value = old.get(address)
            elif i.mnemonic == M.LEA and i.op0_kind == K.REGISTER and x.RegisterExt.is_gpr64(dest):
                if i.is_ip_rel_memory_operand:
                    rva = i.ip_rel_memory_address
                    if any(s.VirtualAddress <= rva and rva + 16 <= s.VirtualAddress + min(s.SizeOfRawData, s.Misc_VirtualSize)
                           and not s.Characteristics & 0x80000000 for s in pe.sections) and pe.get_data(rva, 16) == IID:
                        value = "iid"
                else:
                    value = address
            elif i.mnemonic == M.XOR and i.op0_kind == i.op1_kind == K.REGISTER and dest == src and x.RegisterExt.size(dest) >= 4:
                value = "zero"
                dest = x.RegisterExt.full_register(dest)
            elif i.mnemonic == M.MOV and i.op0_kind == K.MEMORY and address and i.op1_kind == K.REGISTER and x.RegisterExt.is_gpr64(src):
                if src in old:
                    state[address] = old[src]
            elif i.mnemonic in {M.PUSH, M.POP}:
                dest = R.RSP
                value = stack(old.get(dest), i.stack_pointer_increment)
            elif i.mnemonic in {M.SUB, M.ADD} and dest == R.RSP and i.op1_kind in {K.IMMEDIATE8TO64, K.IMMEDIATE32TO64}:
                value = stack(old.get(dest), i.immediate(1) * (1 if i.mnemonic == M.ADD else -1))
            if value is not None:
                state[dest] = value

        for nxt in succ:
            merged = state.copy()
            if nxt in states:
                prior = states[nxt]
                merged = {k: v for k, v in state.items() if prior.get(k) == v}
                for key in state.keys() & prior.keys():
                    if {state[key], prior[key]} <= {"interface", "zero", "nullable"} and state[key] != prior[key]:
                        merged[key] = "nullable"
                if "factory_call_executed" in prior or "factory_call_executed" in state:
                    merged["factory_call_executed"] = True
                if merged == prior:
                    continue
            states[nxt] = merged
            pending.append(nxt)
    return states, returns

def check(original, delivery):
    import iced_x86 as x
    import pefile

    root = delivery.resolve()
    issues, verified_sites = [], []
    stats = dict(submitted_rows=0, member_matches=0, member_mismatches=0, missing_displacements=0,
                 displacement_matches=0, displacement_mismatches=0, concrete_targets_verified=0)
    def report(severity, code, **detail):
        finding = dict(severity=severity, code=code, **detail)
        issues.append(finding)
        return finding

    def finish():
        status = "fail" if any(i["severity"] == "fail" for i in issues) else "inconclusive" if issues else "pass"
        return dict(scope=SCOPE, status=status, metrics=stats, findings=issues, sites=verified_sites)

    tables = [name for name in (TABLE, LEGACY_TABLE) if native_sites.safe_path(root, name).is_file()]
    if len(tables) != 1:
        report("inconclusive", "com_missing_or_ambiguous_table")
        return finish()
    table = tables[0]
    rows = list(native_sites.csv_rows(root, table, {"site", "disp", "member", "target_module"}, numbered=True))
    stats["submitted_rows"] = len(rows)
    absent = {}
    for line, row in rows:
        if not row["disp"].strip():
            stats["missing_displacements"] += 1
            absent[line] = report("inconclusive", "com_displacement_missing", file=table, line=line, site=row["site"])
    if not rows:
        report("inconclusive", "com_no_submitted_rows")
        return finish()

    sites = {number(row["site"]) for _, row in rows}
    witnesses = defaultdict(list)
    if table == TABLE:
        for _, row in rows:
            triplet = tuple(number(row.get(key, "")) for key in ("owner", "factory_call", "factory"))
            witnesses[number(row["site"])].append(triplet if None not in triplet else None)
    elif native_sites.safe_path(root, BINDING).is_file():
        for row in native_sites.csv_rows(root, BINDING, {"rva", "owner", "detail"}):
            site = number(row["rva"])
            match = re.match(r"factory (0x[0-9a-f]+) via (0x[0-9a-f]+)(?:,|$)", row["detail"], re.I)
            if site in sites:
                witnesses[site].append((number(row["owner"]), int(match[2], 16), int(match[1], 16)) if match else None)

    refs, calls = listing_refs(root, sites)
    with pefile.PE(data=original) as pe:
        if pe.FILE_HEADER.Machine != 0x8664 or pe.OPTIONAL_HEADER.Magic != 0x20b:
            report("inconclusive", "com_unsupported_abi")
            return finish()
        ends = defaultdict(list)
        for e in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ()):
            ends[e.struct.BeginAddress].append(e.struct.EndAddress)
        imports = {i.address - pe.OPTIONAL_HEADER.ImageBase for d in getattr(pe, "DIRECTORY_ENTRY_IMPORT", ())
                   if d.dll.lower() in {b"ole32.dll", b"combase.dll"} for i in d.imports if i.name == b"CoCreateInstance"}

        @lru_cache(maxsize=64)
        def function(owner):
            return _function(pe, owner, ends, x)

        @lru_cache(maxsize=64)
        def proven_factory(factory):
            _, returns = _analyze(pe, function(factory), factory, x, imports)
            values = set(returns.values())
            return bool(values & {"interface", "nullable"}) and values <= {"interface", "nullable", "zero"}

        @lru_cache(maxsize=64)
        def caller(owner, via, factory):
            body = function(owner)
            return _analyze(pe, body, owner, x, imports, via=via, factory=factory)[0]

        seen = set()
        for line, row in rows:
            site = number(row["site"])
            where = dict(site=row["site"], line=line, file=table)
            if site in seen:
                report("fail", "com_duplicate_site", **where)
                continue
            seen.add(site)
            if site is None or len(witnesses[site]) != 1 or not witnesses[site][0] or None in witnesses[site][0]:
                report("inconclusive", "com_interface_binding_unavailable", **where)
                continue
            owner, via, factory = witnesses[site][0]
            try:
                if not all(sum(start <= addr < end for start, boundaries in ends.items() for end in boundaries) == 1
                           for addr in (site, via, factory)):
                    raise ValueError("Original runtime ownership is ambiguous")
                ins = function(owner).get(site)
                if ins is None or ins.flow_control != x.FlowControl.INDIRECT_CALL or ins.op0_kind != x.OpKind.MEMORY:
                    raise ValueError("Site is not an original indirect call instruction boundary")
                entries = refs[site]
                if len(entries) != 1:
                    raise ValueError("Missing or ambiguous listing site")
                n, label, data = entries[0]
                if label != owner or data != pe.get_data(site, ins.len) or calls[site] != [(owner, (LISTING, n, n))]:
                    report("fail", "com_listing_or_call_reference_mismatch", listing_line=n, **where)
                    continue
                if (ins.memory_index != x.Register.NONE or not x.RegisterExt.is_gpr64(ins.memory_base)
                        or ins.segment_prefix != x.Register.NONE or x.MemorySizeExt.size(ins.memory_size) != 8):
                    raise ValueError("Not a base-plus-slot memory operand")
                disp = ins.memory_displacement
                if line in absent:
                    absent[line]["original"] = hex(disp)
                if row["disp"].strip():
                    if number(row["disp"].strip()) == disp:
                        stats["displacement_matches"] += 1
                    else:
                        stats["displacement_mismatches"] += 1
                        report("fail", "com_displacement_mismatch", claimed=row["disp"], original=hex(disp), **where)
                edge = function(owner).get(via)
                if (edge is None or edge.flow_control != x.FlowControl.CALL or
                        edge.op0_kind != x.OpKind.NEAR_BRANCH64 or edge.near_branch_target != factory):
                    report("fail", "com_factory_call_mismatch", via=hex(via), factory=hex(factory), **where)
                    continue
                if not proven_factory(factory):
                    raise ValueError("Unproved IDispatch factory return")
                state = caller(owner, via, factory).get(site, {})
                if state.get(x.Register.RCX) != "interface" or state.get(ins.memory_base) != "vtable":
                    raise ValueError("Unproved factory result in RCX or its vtable in call operand")
                if disp % 8 or disp // 8 not in MEMBERS:
                    raise ValueError("Outside standard x64 IDispatch slots")
            except ValueError as exc:
                report("inconclusive", "com_interface_binding_unavailable", reason=str(exc), **where)
                continue
            member = MEMBERS[disp // 8]
            verified_sites.append(dict(site_rva=hex(site), source=f"{table}#L{line}", listing=f"{LISTING}#L{n}",
                                       caller_rva=hex(owner), factory_call_rva=hex(via), factory_rva=hex(factory),
                                       original_bytes=data.hex(" "), original_disp=hex(disp), original_member=member,
                                       submitted_disp=row["disp"], submitted_member=row["member"], implementation_rva=None))
            if row["member"] == member:
                stats["member_matches"] += 1
            else:
                stats["member_mismatches"] += 1
                report("fail", "com_member_mismatch", claimed=row["member"], original=member,
                       original_disp=hex(disp), **where)
            if row["target_module"].strip().lower() not in {"", "unknown", "runtime", "runtime (cocreateinstance factory)"}:
                report("inconclusive", "com_runtime_module_unverified", claimed=row["target_module"], **where)
    return finish()
