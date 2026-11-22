"""Check a submitted indirect-call witness against an original AMD64 PE."""
import re
import struct


def _rva(value):
    if type(value) is int and 0 <= value < 1 << 32:
        return value
    if isinstance(value, str) and re.fullmatch(r"0[xX][0-9a-fA-F]{1,8}", value):
        return int(value, 16)
    raise ValueError("An RVA is missing or malformed")


def _section(pe, address, length):
    sections = [s for s in pe.sections if s.VirtualAddress <= address and
                address + length <= s.VirtualAddress + min(s.SizeOfRawData, s.Misc_VirtualSize)]
    if len(sections) != 1:
        raise ValueError("Range lacks a unique file-backed section")
    return sections[0]


def _bytes(pe, address, length):
    _section(pe, address, length)
    data = pe.get_data(address, length)
    if len(data) != length:
        raise ValueError("Truncated original PE range")
    return data


def _runtime_entry(pe, address, end=None, *, allow_handlers=False):
    # A candidate-supplied label or executable-section address does not type
    # a pointer as a function. Require a unique original RUNTIME_FUNCTION.
    functions = [r.struct for r in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ())
                 if r.struct.BeginAddress <= address < r.struct.EndAddress]
    if len(functions) != 1 or functions[0].BeginAddress != address:
        raise ValueError("Original exception directory does not identify a unique function entry")
    f = functions[0]
    if end is not None and f.EndAddress != end:
        raise ValueError("Witness owner extent disagrees with the original exception directory")
    if not _section(pe, address, f.EndAddress - address).Characteristics & 0x20000000:
        raise ValueError("Function lacks file-backed executable bytes")
    header = _bytes(pe, f.UnwindData, 4)
    flags = header[0] >> 3
    if (f.UnwindData % 4 or header[0] & 7 != 1 or flags not in ((0, 1, 2, 3) if allow_handlers else (0,))
            or header[1] > f.EndAddress - address):
        raise ValueError("Unsupported unwind version, flags, alignment or prolog size")
    size = 4 + ((header[2] + 1) & ~1) * 2
    unwind = _bytes(pe, f.UnwindData, size + (4 if flags else 0))
    if flags and not _section(pe, int.from_bytes(unwind[size:], "little"), 1).Characteristics & 0x20000000:
        raise ValueError("Original unwind handler is not executable")


def _imports(pe):
    slots = {}
    for index, attr in ((1, "DIRECTORY_ENTRY_IMPORT"), (13, "DIRECTORY_ENTRY_DELAY_IMPORT")):
        directories = pe.OPTIONAL_HEADER.DATA_DIRECTORY
        if index < len(directories) and directories[index].VirtualAddress and not hasattr(pe, attr):
            raise ValueError("Import directory unavailable")
        for dll in getattr(pe, attr, ()):
            for imp in dll.imports:
                address = imp.address - pe.OPTIONAL_HEADER.ImageBase
                name = f"#{imp.ordinal}" if imp.import_by_ordinal else imp.name.decode("ascii")
                if address in slots:
                    raise ValueError("Ambiguous original IAT slot")
                slots[address] = dll.dll.decode("ascii") + "!" + name
    return slots


def _readonly(pe, address):
    section = _section(pe, address, 8)
    if section.Characteristics & 0xa2000000 or section.Characteristics & 0x40000040 != 0x40000040:
        raise ValueError("Slot or table base lacks a read-only initialized data section")
    return section


def _load_config(pe):
    instance = getattr(pe, "DIRECTORY_ENTRY_LOAD_CONFIG", None)
    if instance is None:
        return {}
    config = instance.struct
    if config.Size > config.sizeof():
        raise ValueError("Unsupported load-config fields may describe loader-managed slots")
    return {key: getattr(config, key) for key in config.dump_dict() if key != "Structure"}


def _loader_slots(pe, config, imports):
    base = pe.OPTIONAL_HEADER.ImageBase
    slots = {slot: "IAT" for slot in imports}
    # Include loader-owned pointer cells, including GuardCF/XFG dispatch and
    # cookie slots. Other load-config image pointers are conservatively reserved.
    for field, va in config.items():
        if type(va) is int and base <= va < base + pe.OPTIONAL_HEADER.SizeOfImage:
            slots[va - base] = field
    tls = getattr(pe, "DIRECTORY_ENTRY_TLS", None)
    if tls and tls.struct.AddressOfIndex:
        slots[tls.struct.AddressOfIndex - base] = "TLS index"
    for descriptor in getattr(pe, "DIRECTORY_ENTRY_DELAY_IMPORT", ()):
        d = descriptor.struct
        handle = d.phmod
        if handle:
            slots[handle if d.grAttrs & 1 else handle - base] = "delay-load module handle"
        for field in ("pIAT", "pBoundIAT", "pUnloadIAT"):
            address = getattr(d, field, 0)
            if address:
                start = address if d.grAttrs & 1 else address - base
                for offset in range(len(descriptor.imports) + 1):
                    slots[start + offset * 8] = "delay-load " + field
    return slots


def _pointer(pe, slot, observed, imports):
    _readonly(pe, slot)
    iat = pe.OPTIONAL_HEADER.DATA_DIRECTORY
    config = _load_config(pe)
    for addr, identity in _loader_slots(pe, config, imports).items():
        if slot - 8 < addr < slot + 8:
            observed["loader_slot"] = identity
            raise ValueError("Loader-managed storage cannot prove a fixed internal target")
    if (len(iat) > 12 and iat[12].VirtualAddress and slot < iat[12].VirtualAddress + iat[12].Size
            and slot + 8 > iat[12].VirtualAddress):
        raise ValueError("Loader-managed IAT region cannot prove a fixed internal target")
    if ((len(iat) > 14 and iat[14].VirtualAddress) or
            any(config.get(field) for field in ("DynamicValueRelocTable", "DynamicValueRelocTableOffset",
                "CHPEMetadataPointer", "HotPatchTableOffset", "VolatileMetadataPointer", "EnclaveConfigurationPointer",
                "LockPrefixTable", "EditList"))):
        raise ValueError("Additional dynamic fixups or hotpatch metadata require independent analysis")
    value = int.from_bytes(_bytes(pe, slot, 8), "little")
    observed["pointer_va"] = hex(value)
    # A typed VA needs relocation provenance. Partial, mixed or duplicate
    # relocations do not establish the contents of an eight-byte pointer.
    nearby = [(r.rva, r.type) for block in getattr(pe, "DIRECTORY_ENTRY_BASERELOC", ()) for r in block.entries
              if r.type and slot - 8 < r.rva < slot + 8]
    if not all(kind == 10 for _, kind in nearby) or [p for p, _ in nearby] != [slot]:
        raise ValueError("Slot lacks one independent PE DIR64 relocation")
    target = value - pe.OPTIONAL_HEADER.ImageBase
    if not 0 <= target < pe.OPTIONAL_HEADER.SizeOfImage:
        raise ValueError("Slot does not contain a preferred-base VA inside the original image")
    _runtime_entry(pe, target)
    observed.update(target=hex(target), pointer_type="IMAGE_REL_BASED_DIR64",
                    target_type="AMD64 RUNTIME_FUNCTION")
    return target


def _clobber(instructions, definition, reg, x86):
    factory = x86.InstructionInfoFactory()
    writes = {x86.OpAccess.WRITE, x86.OpAccess.COND_WRITE, x86.OpAccess.READ_WRITE, x86.OpAccess.READ_COND_WRITE}
    for ins in instructions:
        if ins.ip <= definition:
            continue
        if ins.flow_control != x86.FlowControl.NEXT or any(
                r.access in writes and x86.RegisterExt.full_register(r.register) == reg
                for r in factory.info(ins).used_registers()):
            return ins.ip
    return None


def verify(pe, entry, end, site, claim, x86):
    """entry/end delimit a verifier-owned range; site is the independently decoded call RVA.

    A readonly_table proof is scoped to execution from the named PE function
    entry. The witness supplies a definition and slot, never an executable script.
    """
    import pefile

    observed = {"site": hex(site)}
    witness = claim.get("witness") if isinstance(claim, dict) else None
    kind = witness.get("kind") if isinstance(witness, dict) else None
    scope = {"readonly_table": "from_owner_entry", "guard_dispatch": "definition_fallthrough"}.get(
        kind if isinstance(kind, str) else "", "instruction_operand")

    def result(status, code, message):
        return {"status": status, "code": code, "message": message, "rva": hex(site), "original": observed,
                "reported": claim, "target": observed.get("target"), "external": observed.get("external"),
                "binding_scope": scope, "whole_program_unique": False}

    try:
        if pe.FILE_HEADER.Machine != 0x8664 or pe.OPTIONAL_HEADER.Magic != 0x20b:
            raise ValueError("Only AMD64 PE32+ witnesses are supported")
        if kind not in ("iat", "readonly_slot", "readonly_table", "guard_dispatch"):
            raise ValueError("Unsupported or absent witness kind")
        allowed = {"kind", "slot_rva"}
        if kind in ("readonly_table", "guard_dispatch"):
            allowed.update(("register", "definition_rva"))
        if witness.keys() != allowed:
            raise ValueError("Missing or unsupported witness fields")
        claimed_slot = _rva(witness["slot_rva"])
        if _rva(claim["site"]) != site:
            return result("fail", "witness_site", "Claim identifies a different instruction")
        if not entry <= site < end or end - entry > 1 << 20:
            raise ValueError("Site outside supported original function extent")
        if not _section(pe, entry, end - entry).Characteristics & 0x20000000:
            raise ValueError("Witness owner is not executable")
        # Decode from the independent owner boundary. Never decode an arbitrary
        # candidate offset as an instruction start, or search for another site.
        decoder = x86.Decoder(64, _bytes(pe, entry, end - entry), ip=entry)
        prefix = []
        for ins in decoder:
            if ins.is_invalid or ins.ip > site:
                raise ValueError("Site is not an established instruction start")
            if ins.ip == site:
                break
            prefix.append(ins)
        else:
            raise ValueError("Site not present in the original owner")
        observed["instruction"] = str(ins)
        if ins.mnemonic != x86.Mnemonic.CALL or ins.flow_control != x86.FlowControl.INDIRECT_CALL:
            return result("fail", "witness_call", "Original instruction is not an indirect call")
        attrs = {0: "EXPORT", 1: "IMPORT", 3: "EXCEPTION", 13: "DELAY_IMPORT"}
        if kind == "guard_dispatch":
            attrs = {3: "EXCEPTION", 10: "LOAD_CONFIG"}
        elif kind in ("readonly_slot", "readonly_table"):
            attrs.update({0: "EXPORT", 3: "EXCEPTION", 5: "BASERELOC", 9: "TLS", 10: "LOAD_CONFIG"})
        needed = [i for i, attr in attrs.items() if i < len(pe.OPTIONAL_HEADER.DATA_DIRECTORY)
                  and pe.OPTIONAL_HEADER.DATA_DIRECTORY[i].VirtualAddress and not hasattr(pe, "DIRECTORY_ENTRY_" + attr)]
        if needed:
            pe.parse_data_directories(directories=needed)
            if any(not hasattr(pe, "DIRECTORY_ENTRY_" + attrs[i]) for i in needed):
                raise ValueError("Original PE directory could not be interpreted")
        if kind == "guard_dispatch":
            _runtime_entry(pe, entry, end, allow_handlers=True)
            observed["owner_entry"] = hex(entry)
            if ins.op0_kind != x86.OpKind.REGISTER or not x86.RegisterExt.is_gpr64(ins.op0_register):
                return result("fail", "witness_operand", "Guard-register witness requires a register call")
            reg = ins.op0_register
            observed["register"] = x86.Formatter(x86.FormatterSyntax.INTEL).format_register(reg)
            if not isinstance(witness["register"], str) or witness["register"].lower() != observed["register"]:
                return result("fail", "witness_register", "Original call consumes a different register")
            definition = _rva(witness["definition_rva"])
            load = next((i for i in prefix if i.ip == definition), None)
            if load is None:
                return result("fail", "witness_definition", "No such earlier instruction in the original owner")
            observed.update(definition_rva=hex(definition), definition_instruction=str(load))
            if (load.mnemonic != x86.Mnemonic.MOV or load.op0_register != reg or load.memory_base != x86.Register.RIP
                    or load.segment_prefix in (x86.Register.FS, x86.Register.GS)):
                return result("fail", "witness_definition", "Claimed load does not read this register from RIP memory")
            slot = load.ip_rel_memory_address
            observed["slot_rva"] = hex(slot)
            if slot != claimed_slot:
                return result("fail", "witness_slot", "Original register load addresses a different slot")
            clobber = _clobber(prefix, definition, reg, x86)
            if clobber is not None:
                observed["clobber_rva"] = hex(clobber)
                raise ValueError("Original path does not preserve the loaded dispatch register")
            base = pe.OPTIONAL_HEADER.ImageBase
            config = _load_config(pe)
            fields = [f for f in ("GuardCFDispatchFunctionPointer", "GuardXFGDispatchFunctionPointer",
                                  "GuardXFGTableDispatchFunctionPointer") if config.get(f) == base + slot]
            if not fields:
                raise ValueError("No original Load Config field types this slot as a guard dispatcher")
            _bytes(pe, slot, 8)
            observed["dispatch_route"] = {"status": "pass", "load_config_fields": fields,
                                          "binding_scope": scope, "final_target": None}
            return result("inconclusive", "witness_guard_route", "Dispatch route verified; final target unresolved")
        if (ins.op0_kind != x86.OpKind.MEMORY or x86.MemorySizeExt.size(ins.memory_size) != 8 or
                ins.segment_prefix in (x86.Register.FS, x86.Register.GS) or ins.memory_index != x86.Register.NONE):
            raise ValueError("Witness requires a qword memory call without index or segment override")

        if kind == "readonly_table":
            _runtime_entry(pe, entry, end)
            observed["owner_entry"] = hex(entry)
            observed["register"] = x86.Formatter(x86.FormatterSyntax.INTEL).format_register(ins.memory_base)
            if not isinstance(witness["register"], str) or observed["register"] != witness["register"].lower():
                return result("fail", "witness_register", "Call uses a different base register")
            if not x86.RegisterExt.is_gpr64(ins.memory_base):
                raise ValueError("Call requires a 64-bit general-purpose base register")
            definition = _rva(witness["definition_rva"])
            # Require one straight-line owner with no branches before the call,
            # no alternate exported/declared entry and a return-only suffix.
            if any(i.flow_control != x86.FlowControl.NEXT for i in prefix):
                raise ValueError("A transfer in the owner prefix can bypass or invalidate the definition")
            suffix = list(decoder)
            if (not suffix or suffix[-1].mnemonic != x86.Mnemonic.RET or
                    any(i.mnemonic != x86.Mnemonic.NOP for i in suffix[:-1])):
                raise ValueError("Owner suffix does not exclude a path returning to this call")
            starts = [pe.OPTIONAL_HEADER.AddressOfEntryPoint]
            starts.extend(e.address for e in getattr(getattr(pe, "DIRECTORY_ENTRY_EXPORT", None), "symbols", ())
                          if not e.forwarder)
            starts.extend(r.struct.BeginAddress for r in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ()))
            if any(entry < start < end for start in starts):
                raise ValueError("Original metadata identifies an alternate owner entry")
            ins_def = next((i for i in prefix if i.ip == definition), None)
            if ins_def is None:
                return result("fail", "witness_definition", "Claimed definition is not an earlier owner instruction")
            observed.update(definition_rva=hex(definition), definition_instruction=str(ins_def))
            if (ins_def.mnemonic != x86.Mnemonic.LEA or ins_def.op0_register != ins.memory_base or
                    ins_def.memory_base != x86.Register.RIP):
                return result("fail", "witness_definition", "Claimed instruction does not define this RIP-relative base")
            clobber = _clobber(prefix, definition, ins.memory_base, x86)
            if clobber is not None:
                observed["clobber_rva"] = hex(clobber)
                raise ValueError("Table base is written after the claimed definition")
            table = ins_def.ip_rel_memory_address
            disp = ins.memory_displacement
            if disp >= 1 << 31 or disp % 8:
                raise ValueError("Table witness requires a fixed nonnegative qword offset")
            slot = table + disp
            observed.update(table_rva=hex(table), displacement=disp)
            if _readonly(pe, table).VirtualAddress != _readonly(pe, slot).VirtualAddress:
                raise ValueError("Table and consumed slot are in different original sections")
        else:
            if any(e.struct.BeginAddress <= entry < e.struct.EndAddress
                   for e in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ())):
                _runtime_entry(pe, entry, end, allow_handlers=True)
            elif (entry != pe.OPTIONAL_HEADER.AddressOfEntryPoint and not any(e.address == entry and not e.forwarder
                    for e in getattr(getattr(pe, "DIRECTORY_ENTRY_EXPORT", None), "symbols", ()))):
                raise ValueError("Owner instruction stream lacks an independent original entry")
            if ins.memory_base != x86.Register.RIP:
                return result("fail", "witness_operand", "Original call does not use the claimed RIP-relative form")
            slot = ins.ip_rel_memory_address
        observed["slot_rva"] = hex(slot)
        if slot != claimed_slot:
            return result("fail", "witness_slot", "Original operand addresses a different slot")
        imports = _imports(pe)
        if kind == "iat":
            _bytes(pe, slot, 8)
            if slot not in imports:
                raise ValueError("No original import descriptor binds this slot")
            observed["external"] = {"iat_rva": hex(slot), "import": imports[slot]}
            external = claim.get("external")
            if not isinstance(external, dict) or not isinstance(external.get("import"), str):
                raise ValueError("External target declaration is missing")
            dll, _, name = imports[slot].partition("!")
            other_dll, sep, other_name = external["import"].partition("!")
            if _rva(external.get("iat_rva")) != slot or not sep or (dll.casefold(), name) != (other_dll.casefold(), other_name):
                return result("fail", "witness_import", "Declared import or IAT address differs from original")
            if claim.get("target") is not None:
                raise ValueError("IAT identity supplies no static loaded target RVA")
        else:
            target = _pointer(pe, slot, observed, imports)
            if target != _rva(claim.get("target")):
                return result("fail", "witness_target", "Declared target differs from the typed original pointer")
            if claim.get("external") is not None:
                raise ValueError("Internal pointer does not establish the additional external target")
        return result("pass", "witness_verified", "Submitted binding verified within the reported scope")
    except (KeyError, ValueError, OverflowError, struct.error, pefile.PEFormatError) as exc:
        return result("inconclusive", "witness_insufficient", str(exc))
