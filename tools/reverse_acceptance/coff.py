"""Reassemble the reviewed BFDYLD submission and compare its AMD64 COFF semantics.

This profile covers the two original objects and one assembly source independently
reviewed in the COFF-BFDYLD handoffs. It never runs code from a submission.
"""
import collections
import hashlib
import os
from pathlib import Path
import struct
import subprocess
import tempfile


ORIGINALS = {
    "194e88b44801eb787ccd0964ef43f869a7d355a2ea905a0f679d173f91703ec0",
    "3caaf37f068d6fa7c36ae8d1600055e236002a2538baa2a15f377769a1c1620a",
}
SOURCE_SHA256 = "78582c5805916c1a6d06566390235188860beae4514fe3564ab51c0b4f68ea63"
ZIG_SHA256 = "2e44af5bbf7a72ef8cbdae370284687c95d65a19affa469d2ad0364d905b8e84"
SCOPE = "BFDYLD AMD64 COFF assembly reassembly: sections, symbols and symbolic relocations"


def _slice(data, start, length):
    if start < 0 or length < 0 or start + length > len(data):
        raise ValueError("COFF range exceeds file")
    return data[start:start + length]


def _parse(data):
    """Decode just the ordinary, non-COMDAT AMD64 COFF used by both originals."""
    machine, count, _, symoff, nsyms, optional, flags = struct.unpack_from("<HHIIIHH", data)
    if (machine, optional, flags) != (0x8664, 0, 0) or not 0 < count <= 96:
        raise ValueError("unexpected COFF architecture, optional header, flags or section count")
    symend = symoff + nsyms * 18
    _slice(data, symoff, nsyms * 18)
    string_size, = struct.unpack_from("<I", data, symend)
    if string_size < 4:
        raise ValueError("invalid COFF string table")
    strings = _slice(data, symend, string_size)
    names = {}
    sections = {}
    relocation_rows = {}
    for index in range(1, count + 1):
        hdr = struct.unpack_from("<8sIIIIIIHHI", data, 20 + 40 * (index - 1))
        raw_name, physical, virtual, size, pointer, relptr, lineptr, nrel, nline, attrs = hdr
        name = raw_name.rstrip(b"\0").decode("ascii")
        if name in sections or name.startswith("/") or any((physical, virtual, lineptr, nline)):
            raise ValueError(f"unexpected section or line-number layout at {name!r}")
        if attrs & 0x1000 or (size and not pointer and not attrs & 0x80):
            raise ValueError(f"unsupported COMDAT or missing stored section {name!r}")
        names[index] = name
        sections[name] = (size, attrs, _slice(data, pointer, size) if pointer else b"")
        relocation_rows[name] = list(struct.iter_unpack("<IIH", _slice(data, relptr, nrel * 10)))
    symbols = {}
    aux_count = 0
    index = 0
    while index < nsyms:
        namefield, value, section, typ, storage, naux = struct.unpack_from("<8sIhHBB", data, symoff + 18 * index)
        if namefield.startswith(b"\0" * 4):
            pos = int.from_bytes(namefield[4:], "little")
            if not 4 <= pos < len(strings):
                raise ValueError("COFF symbol has invalid string offset")
            raw_name = strings[pos:strings.index(b"\0", pos)]
        else:
            raw_name = namefield.rstrip(b"\0")
        name = raw_name.decode("ascii")
        owner = names[section] if section > 0 else str(section)
        aux = None
        if naux:
            # Both reviewed files contain only section-definition auxiliary records.
            if naux != 1 or index + naux >= nsyms or storage != 3 or owner != name:
                raise ValueError(f"unsupported auxiliary record for {name}")
            length, nrel, lines, _, associated, selection, reserved, high = struct.unpack_from(
                "<IHHIhBBH", data, symoff + 18 * (index + 1))
            if associated not in (0, section) or selection or reserved or high:
                raise ValueError(f"unexpected auxiliary association for {name}")
            # The two assemblers differ in the optional checksum and the ordinal of
            # the same non-associative section. Length and counts must still match.
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

    if digest not in ORIGINALS:
        return result("inconclusive", "unsupported_original", "This COFF profile has no reviewed source pair for this original.")
    try:
        root = Path(delivery).resolve(strict=True)
        path = (root / "BFDYLD.s").resolve(strict=True)
        if not root.is_dir() or path.parent != root or not path.is_file():
            return result("fail", "source_path", "The reviewed BFDYLD.s must be a file inside the delivery.")
        with path.open("rb") as reader:
            source = reader.read(1_048_577)
    except FileNotFoundError:
        return result("fail", "missing_source", "The delivery is missing BFDYLD.s.")
    except (OSError, RuntimeError) as exc:
        return result("inconclusive", "source_unreadable", str(exc))
    metrics["source_sha256"] = hashlib.sha256(source).hexdigest()
    if metrics["source_sha256"] != SOURCE_SHA256:
        return result("fail", "unreviewed_source", "BFDYLD.s differs from the source pinned for this profile.")
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
            # Compile exactly the reviewed bytes. The submission's working directory,
            # project files and scripts play no part in this build.
            (tmp / "BFDYLD.s").write_bytes(source)
            env = {k: v for k, v in os.environ.items() if k.upper() in
                   {"SYSTEMROOT", "WINDIR", "LOCALAPPDATA", "USERPROFILE", "TEMP", "TMP"}}
            run = subprocess.run([str(compiler), "cc", "--target=x86_64-windows-gnu",
                                  "-x", "assembler", "-g0", "-c", "BFDYLD.s", "-o", "checked.obj"],
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
        sections, symbols, auxiliary, relocs = _parse(original)
    except (ValueError, KeyError, struct.error) as exc:
        return result("inconclusive", "coff_layout", str(exc))
    metrics.update(sections=len(sections), text_bytes=sections[".text"][0], symbols=sum(symbols.values()),
                   auxiliary_symbols=auxiliary, relocations=sum(r.total() for r in relocs.values()),
                   rebuilt_sha256=hashlib.sha256(rebuilt).hexdigest())
    return result("pass")

