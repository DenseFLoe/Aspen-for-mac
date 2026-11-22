"""Compare ordinary AMD64 COFF with one root-level .s file in bounded AT&T syntax."""
import collections
import hashlib
import os
from pathlib import Path
import re
import struct
import subprocess
import tempfile


ZIG_SHA256 = "2e44af5bbf7a72ef8cbdae370284687c95d65a19affa469d2ad0364d905b8e84"
SCOPE = "AMD64 COFF reassembly: sections, symbols and symbolic relocations"
MAX_SOURCE = 1 << 20
MAX_OBJECT = 8 << 20

# Ordinary AT&T registers, immediates, displacements, and base/index addresses.
# Only full statements from this grammar are sent to the assembler.
IDENT = r"(?:[A-Za-z_]|\.[A-Za-z_])[A-Za-z0-9_.$]{0,126}"
NUMBER = r"(?:0[xX][a-fA-F0-9]{1,16}|[0-9]{1,19})"
EXPR = rf"(?:-?{NUMBER}|{IDENT}(?:@IMGREL)?(?:[+-]{NUMBER})?)"
REG = r"%[a-z][a-z0-9]{0,7}"
ADDRESS = rf"\((?:{REG}(?:,{REG}(?:,[1248])?)?|,{REG}(?:,[1248])?)\)"
OPERAND = rf"(?:{REG}|\${EXPR}|(?:{EXPR})?{ADDRESS}|{EXPR})"
ARGUMENTS = re.compile(rf"{OPERAND}(?:[ \t]*,[ \t]*{OPERAND}){{0,3}}")
CPP_DIRECTIVE = re.compile(
    rb"^[ \t]*#[ \t]*(?:if|ifdef|ifndef|elif|elifdef|elifndef|else|endif|define|undef|"
    rb"include|include_next|line|pragma|error|warning|embed)\b"
)
MNEMONICS = set("""
    ret retq nop nopl pushq popq call callq jmp je jne jz jnz ja jae jb jbe
    jg jge jl jle jp setneb movabsq leaq shlq sarq comisd ucomisd cvttsd2si
    movsd movaps movups movdqa movdqu addsd addpd mulsd divsd pxor por pand
    pcmpeqd pshufd psrldq punpcklqdq unpckhpd
""".split())
MNEMONICS.update(base + width for base in
                 ("mov", "add", "sub", "and", "or", "xor", "cmp", "test", "inc", "dec", "neg", "not")
                 for width in ("b", "w", "l", "q"))


def _statement_cost(line):
    if (line in (".text", ".data", ".bss") or re.fullmatch(IDENT + ":", line)
            or re.fullmatch(rf"\.globl[ \t]+{IDENT}", line)
            or re.fullmatch(r'\.section[ \t]+\.[A-Za-z][A-Za-z0-9_$]{0,6},[ \t]*"[bdrwxyn]{1,6}"', line)
            or re.fullmatch(rf"\.def\s+{IDENT};\s*\.scl\s+[23];\s*\.type\s+(?:0|32);\s*\.endef", line)):
        return 0
    if re.fullmatch(rf"\.rva\s+{EXPR}", line):
        return 4
    if re.fullmatch(r"\.p2align\s+(?:[0-9]|1[0-2])", line):
        return 1 << int(line.split()[1])
    size = re.fullmatch(rf"(?:\.comm\s+{IDENT},\s*([0-9]{{1,7}}),\s*[0-6]|\.zero\s+([0-9]{{1,7}}))", line)
    if size:
        return int(size[1] or size[2])
    if re.fullmatch(rf"\.byte\s+{NUMBER}(?:\s*,\s*{NUMBER})*", line):
        return line.count(",") + 1
    instruction = re.fullmatch(r"(?:\{disp(?:8|32)\}\s+)?([a-z0-9]+)(?:\s+(.+))?", line)
    if instruction and instruction[1] in MNEMONICS and (not instruction[2] or ARGUMENTS.fullmatch(instruction[2])):
        return 15
    raise ValueError("statement outside supported assembly syntax")


def _assembly(source):
    if len(source) > MAX_SOURCE:
        raise ValueError("assembly exceeds the source size limit")
    vetted = []
    emitted = 0
    for number, raw in enumerate(source.replace(b"\r\n", b"\n").split(b"\n"), 1):
        if number > 16384 or len(raw) > 4096:
            raise ValueError("assembly exceeds the line limit")
        if CPP_DIRECTIVE.match(raw):
            raise ValueError(f"line {number}: preprocessed assembly is outside the supported profile")
        code = raw.partition(b"#")[0].strip(b" \t")
        if not code:
            continue
        if any(c != 9 and not 32 <= c <= 126 for c in code):
            raise ValueError(f"unsupported characters on line {number}")
        try:
            emitted += _statement_cost(code.decode("ascii"))
        except ValueError as exc:
            raise ValueError(f"line {number}: {exc}") from exc
        if emitted > MAX_OBJECT // 2:
            raise ValueError("assembly exceeds the output size budget")
        vetted.append(code)
    if not vetted:
        raise ValueError("empty assembly")
    return b"\n".join(vetted) + b"\n"


def _slice(data, start, length):
    if start < 0 or length < 0 or start + length > len(data):
        raise ValueError("COFF range exceeds file")
    return data[start:start + length]


def _parse(data):
    """Decode ordinary AMD64 COFF with short section names and simple auxiliary records."""
    if len(data) > MAX_OBJECT:
        raise ValueError("COFF exceeds the object size limit")
    machine, count, _, symoff, nsyms, optional, flags = struct.unpack_from("<HHIIIHH", data)
    if (machine, optional, flags) != (0x8664, 0, 0) or not 0 < count <= 96:
        raise ValueError("unexpected COFF architecture, optional header, flags or section count")
    symend = symoff + nsyms * 18
    if nsyms > 65536:
        raise ValueError("COFF exceeds the symbol limit")
    _slice(data, symoff, nsyms * 18)
    string_size, = struct.unpack_from("<I", data, symend)
    if string_size < 4 or symend + string_size != len(data):
        raise ValueError("invalid COFF string table")
    strings = _slice(data, symend, string_size)
    names = {}
    sections = {}
    relocation_rows = {}
    total_relocations = 0
    regions = [(0, 20 + 40 * count), (symoff, len(data))]
    for index in range(1, count + 1):
        hdr = struct.unpack_from("<8sIIIIIIHHI", data, 20 + 40 * (index - 1))
        raw_name, physical, virtual, size, pointer, relptr, lineptr, nrel, nline, attrs = hdr
        name = raw_name.rstrip(b"\0").decode("ascii")
        if not name or name in sections or name.startswith("/") or any((physical, virtual, lineptr, nline)):
            raise ValueError(f"unexpected section or line-number layout at {name!r}")
        if attrs & (0x1000 | 0x01000000) or (size and not pointer and not attrs & 0x80):
            raise ValueError(f"unsupported COMDAT or missing stored section {name!r}")
        names[index] = name
        if pointer and size:
            regions.append((pointer, pointer + size))
        if nrel:
            regions.append((relptr, relptr + nrel * 10))
        # Validate bounds and reject aliasing before copying section or relocation data.
        regions.sort()
        for (_, end), (start, _) in zip(regions, regions[1:]):
            if end > start:
                raise ValueError("overlapping COFF records")
        total_relocations += nrel
        if total_relocations > 65536:
            raise ValueError("COFF exceeds the relocation limit")
        sections[name] = (size, attrs, _slice(data, pointer, size) if pointer else b"")
        relocation_rows[name] = list(struct.iter_unpack("<IIH", _slice(data, relptr, nrel * 10)))
    for (_, end), (start, _) in zip(regions, regions[1:]):
        if any(data[end:start]):
            raise ValueError("unclassified non-padding bytes between COFF records")
    symbols = {}
    aux_count = 0
    index = 0
    while index < nsyms:
        namefield, value, section, typ, storage, naux = struct.unpack_from("<8sIhHBB", data, symoff + 18 * index)
        if namefield.startswith(b"\0" * 4):
            pos = int.from_bytes(namefield[4:], "little")
            if not 4 <= pos < len(strings):
                raise ValueError("COFF symbol has invalid string offset")
            raw_name = strings[pos:strings.index(b"\0", pos, pos + 1025)]
        else:
            raw_name = namefield.rstrip(b"\0")
        name = raw_name.decode("ascii")
        if section < -1 or storage not in (2, 3):
            raise ValueError("unsupported COFF symbol storage or section")
        owner = names[section] if section > 0 else section
        aux = None
        if naux:
            # Only section-definition auxiliary records are supported.
            if naux != 1 or index + naux >= nsyms or storage != 3 or owner != name:
                raise ValueError(f"unsupported auxiliary record for {name}")
            length, nrel, lines, _, associated, selection, reserved, high = struct.unpack_from(
                "<IHHIhBBH", data, symoff + 18 * (index + 1))
            if associated not in (0, section) or selection or reserved or high:
                raise ValueError(f"unexpected auxiliary association for {name}")
            if (length, nrel, lines) != (sections[name][0], len(relocation_rows[name]), 0):
                raise ValueError(f"inconsistent section-definition record for {name}")
            # Non-COMDAT section definitions may differ in optional checksum and ordinal.
            aux = (length, nrel, lines)
            aux_count += 1
        symbols[index] = (name, value, owner, typ, storage, aux)
        index += 1 + naux
    relocations = {}
    for section, rows in relocation_rows.items():
        relocated = []
        for offset, target, typ in rows:
            if typ not in (3, 4) or offset + 4 > len(sections[section][2]) or target not in symbols:
                raise ValueError(f"invalid or unsupported relocation in {section}")
            relocated.append((offset, typ, symbols[target]))
        relocations[section] = collections.Counter(relocated)
    return sections, collections.Counter(symbols.values()), aux_count, relocations


def _compare(original, rebuilt):
    expected, symbols, auxiliary, relocs = _parse(original)
    actual, built_symbols, built_auxiliary, built_relocs = _parse(rebuilt)
    if set(expected) != set(actual):
        return "section names differ"
    for name, (size, flags, payload) in expected.items():
        actual_size, actual_flags, actual_payload = actual[name]
        if (size, flags) != (actual_size, actual_flags):
            return f"{name}: section size or characteristics differ"
        if payload != actual_payload:
            first = next((i for i, (a, b) in enumerate(zip(payload, actual_payload)) if a != b),
                         min(len(payload), len(actual_payload)))
            return f"{name}+0x{first:x}: stored section bytes differ"
        if relocs[name] != built_relocs[name]:
            diff = relocs[name] - built_relocs[name] or built_relocs[name] - relocs[name]
            return f"{name}+0x{next(iter(diff))[0]:x}: relocation type, target, or multiplicity differs"
    if symbols != built_symbols or auxiliary != built_auxiliary:
        return "COFF symbols, definitions or auxiliary records differ"
    return None


def check(original: bytes, delivery: Path, assembler: Path) -> dict:
    digest = hashlib.sha256(original).hexdigest()
    metrics = {"original_sha256": digest}

    def result(status, code=None, message=None):
        findings = [{"code": code, "message": message}] if code else []
        return {"status": status, "scope": SCOPE, "findings": findings, "metrics": metrics}

    try:
        sections, symbols, auxiliary, relocs = _parse(original)
    except (ValueError, KeyError, struct.error) as exc:
        return result("inconclusive", "unsupported_original", str(exc))
    try:
        root = Path(delivery).resolve(strict=True)
        paths = [entry for entry in root.iterdir() if entry.suffix.casefold() == ".s"]
        if not paths:
            return result("fail", "missing_source", "Expected one root-level .s assembly source.")
        if len(paths) != 1:
            return result("inconclusive", "ambiguous_source", "Multiple root-level .s assembly sources.")
        path = paths[0]
        if path.suffix != ".s":
            return result("inconclusive", "unsupported_source_profile", "Preprocessed assembly (.S) requires a separate profile.")
        if path.resolve(strict=True) != path or path.is_symlink() or not path.is_file():
            return result("inconclusive", "source_path", "Expected a regular assembly file inside the delivery.")
        with path.open("rb") as reader:
            source = reader.read(MAX_SOURCE + 1)
    except (OSError, RuntimeError) as exc:
        return result("inconclusive", "source_unreadable", str(exc))
    if len(source) <= MAX_SOURCE:
        metrics["source_sha256"] = hashlib.sha256(source).hexdigest()
    try:
        vetted = _assembly(source)
    except ValueError as exc:
        return result("inconclusive", "unsupported_assembly", str(exc))
    if assembler is None:
        return result("inconclusive", "assembler_missing", "The reviewed Windows x64 Zig 0.13.0 compiler is required.")
    try:
        compiler = Path(assembler).resolve(strict=True)
        if compiler.is_relative_to(root) or compiler.name.lower() != "zig.exe":
            return result("inconclusive", "assembler_untrusted", "Supply the reviewed Zig executable outside the delivery.")
        with compiler.open("rb") as reader:
            metrics["assembler_sha256"] = hashlib.file_digest(reader, "sha256").hexdigest()
        if metrics["assembler_sha256"] != ZIG_SHA256:
            return result("inconclusive", "assembler_untrusted", "The selected executable differs from the reviewed Zig 0.13.0 build.")
        with tempfile.TemporaryDirectory(prefix="aspen-coff-check-") as scratch:
            tmp = Path(scratch)
            (tmp / "source.s").write_bytes(vetted)
            env = {k: v for k, v in os.environ.items() if k.upper() in
                   {"SYSTEMROOT", "WINDIR", "LOCALAPPDATA", "USERPROFILE", "TEMP", "TMP"}}
            run = subprocess.run([str(compiler), "cc", "--target=x86_64-windows-gnu",
                                  "-x", "assembler", "-g0", "-c", "source.s", "-o", "checked.obj"],
                                 cwd=tmp, env=env, stdin=subprocess.DEVNULL, capture_output=True,
                                 timeout=90, check=False)
            if run.returncode:
                return result("inconclusive", "assembler_error",
                              f"Zig returned {run.returncode}: {run.stderr[-1500:].decode('utf-8', 'replace')}")
            rebuilt = (tmp / "checked.obj").read_bytes()
    except (OSError, RuntimeError, subprocess.TimeoutExpired) as exc:
        return result("inconclusive", "assembler_unavailable", str(exc))
    try:
        mismatch = _compare(original, rebuilt)
        if mismatch:
            return result("fail", "coff_mismatch", mismatch)
    except (ValueError, KeyError, struct.error) as exc:
        return result("inconclusive", "coff_layout", str(exc))
    metrics.update(sections=len(sections), text_bytes=sections.get(".text", (0,))[0], symbols=sum(symbols.values()),
                   auxiliary_symbols=auxiliary, relocations=sum(r.total() for r in relocs.values()),
                   rebuilt_sha256=hashlib.sha256(rebuilt).hexdigest())
    return result("pass")

