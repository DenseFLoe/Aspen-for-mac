
# -*- coding: utf-8 -*-
"""semantic-rebuild detector.

l1_covers: no

Every instruction in the executable sections is disassembled with capstone, re-assembled
from its textual form with keystone, disassembled again, and the two textual forms are
compared (mnemonic + operands, whitespace removed).  This is a SEMANTIC round trip only:
byte-identical re-encoding is not required, because 15% of the instructions legitimately
re-encode to a different but equivalent encoding (31/33 xor, 8b/89 mov, redundant REX).

Anything that comes back different and is not in qa/rebuild_whitelist.json is a defect and
names its RVA.  The whitelist is an explicit list of 'orig => new' patterns with a reason,
a sample RVA and a count; there is no catch-all ignore rule.

Missing keystone is an error, not a skip: a detector whose dependency is absent has not
checked anything.
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "rebuild-semantics"

HERE = os.path.dirname(os.path.abspath(__file__))
WHITELIST_NAMES = ("rebuild_whitelist.json", "qa/rebuild_whitelist.json")


def _norm(text):
    return " ".join(text.split())


def _load_whitelist(item_dir):
    """Only the toolkit's own directory is consulted.  Falling back to the current working
    directory lets a stray file turn a defect into a whitelisted one."""
    for base in (HERE, os.path.join(HERE, "..", "qa")):
        for name in WHITELIST_NAMES:
            p = os.path.normpath(os.path.join(base, name))
            if os.path.isfile(p):
                doc = json.loads(C.read_text(p))
                return doc.get("entries", []), p
    return None, None


def _match(entries, pair):
    for e in entries:
        pat = e.get("pattern", "")
        if pat == pair:
            return e
        try:
            if re.fullmatch(pat, pair):
                return e
        except re.error:
            continue
    return None


def detect(task, item_dir, original, ctx):
    hits = []
    # Pin the decoder build: the toolkit's vendored capstone wins over any site-packages
    # copy, because two 5.0.7 builds can differ on a couple of skipdata boundaries (we
    # measured 5,926 vs 5,928 entries on the same .text). The build is recorded in stats.
    import sys
    for cand in (os.path.join(C.ROOT, ".local", "pylibs"),
                 os.path.join(os.path.dirname(HERE), ".local", "pylibs")):
        if os.path.isdir(cand):
            if cand in sys.path:
                sys.path.remove(cand)
            sys.path.insert(0, cand)
    try:
        import capstone
        import keystone
    except Exception:
        # the toolkit vendors its own dependencies under <workspace>/.local/pylibs
        import sys
        for cand in (os.path.join(C.ROOT, ".local", "pylibs"),
                     os.path.join(os.path.dirname(HERE), ".local", "pylibs")):
            if os.path.isdir(cand) and cand not in sys.path:
                sys.path.append(cand)
        try:
            import capstone
            import keystone
        except Exception as exc:
            return hits, {"error": "capstone/keystone unavailable: %s" % exc}
    entries, wl_path = _load_whitelist(item_dir)
    if entries is None:
        return hits, {"error": "no rebuild_whitelist.json next to the toolkit; a whitelist that "
                               "cannot be found would turn defects into passes"}
    data = open(original, "rb").read()
    pe = C.prepared_pe(data)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md.skipdata = True
    # a SECOND decoder for the re-disassembly: iterating one Cs instance while calling
    # disasm() on it again corrupts the outer generator and silently drops instructions
    # (that is exactly how the entry count came out 2 short)
    md_recheck = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md_recheck.skipdata = True
    ks = keystone.Ks(keystone.KS_ARCH_X86, keystone.KS_MODE_64)
    total = ok = whitelisted = mismatch = asm_error = skipped = 0
    sections = []
    # Scan baseline (also written into stats and README):
    #   * sections with IMAGE_SCN_MEM_EXECUTE (0x20000000)
    #   * span = SizeOfRawData (raw), never clamped by VirtualSize: .nep has raw 0x800 and
    #     vsize 0x7A0, and the tail still decodes
    #   * capstone skipdata on; data pseudo-instructions are counted per section and kept
    #     out of inputs_checked
    for sect in pe.sections:
        if not (sect.Characteristics & 0x20000000):
            continue
        va = sect.VirtualAddress
        raw = sect.PointerToRawData
        rawsize = sect.SizeOfRawData
        vsize = sect.Misc_VirtualSize
        name = sect.Name.rstrip(b"\0").decode("ascii", "replace")
        chunk = data[raw:raw + rawsize]
        if len(chunk) != rawsize:
            hits.append({"severity": "defect", "locator": "section=%s" % name,
                         "evidence": "only %d of %d raw bytes are file-backed; the census would "
                                     "cover a truncated section" % (len(chunk), rawsize)})
        s_ins = s_dat = s_bytes = 0
        _dbg = os.environ.get("DSH_QA_DEBUG") and len(list(md.disasm(chunk, va)))
        # materialise the sweep first: doing keystone work inside an active capstone
        # generator makes the entry count depend on interleaving (it came out 2 short)
        for insn in list(md.disasm(chunk, va)):
            if insn.id == 0:
                s_dat += 1
                continue
            total += 1
            s_ins += 1
            s_bytes += insn.size
            orig = _norm("%s %s" % (insn.mnemonic, insn.op_str))
            try:
                enc, _count = ks.asm(orig, insn.address)
                if not enc:
                    raise ValueError("keystone produced no encoding")
            except Exception as exc:
                asm_error += 1
                hits.append({"severity": "advisory", "locator": "rva=0x%X" % insn.address,
                             "evidence": "cannot re-assemble %r: %s" % (orig, exc)})
                continue
            again = next(md_recheck.disasm(bytes(enc), insn.address), None)
            if again is None or again.id == 0:
                asm_error += 1
                hits.append({"severity": "advisory", "locator": "rva=0x%X" % insn.address,
                             "evidence": "re-assembled bytes do not decode: %r" % orig})
                continue
            if again.size != len(enc):
                asm_error += 1
                hits.append({"severity": "advisory", "locator": "rva=0x%X" % insn.address,
                             "evidence": "re-decoded instruction consumed %d of %d bytes: %r"
                                         % (again.size, len(enc), orig)})
                continue
            new = _norm("%s %s" % (again.mnemonic, again.op_str))
            if new == orig:
                ok += 1
                continue
            pair = orig + " => " + new
            entry = _match(entries, pair)
            if entry:
                whitelisted += 1
                continue
            mismatch += 1
            hits.append({"severity": "defect", "locator": "rva=0x%X" % insn.address,
                         "evidence": "semantic round trip changed the instruction: %s" % pair[:160]})
        if _dbg:
            print("DBG", name, "len(chunk)=", len(chunk), "entries=", _dbg,
                  "instr=", s_ins, "data=", s_dat)
        if s_bytes + s_dat != len(chunk):
            hits.append({"severity": "defect", "locator": "section=%s" % name,
                         "evidence": "decoded %d bytes + %d data bytes out of %d; the sweep does "
                                     "not cover the section" % (s_bytes, s_dat, len(chunk))})
        sections.append({"name": name, "raw_size": rawsize, "virtual_size": vsize,
                         "bytes_scanned": len(chunk), "bytes_decoded": s_bytes,
                         "instructions": s_ins, "data_bytes": s_dat})
        skipped += s_dat
    libs = {"capstone": "%s at %s" % (getattr(capstone, "__version__", "?"),
                                      os.path.basename(os.path.dirname(capstone.__file__))),
            "keystone": getattr(keystone, "__version__", "?"),
            "capstone_path": capstone.__file__}
    stats = {"libs": libs, "sections": sections,
             "baseline": ("sections with Characteristics & 0x20000000; span = SizeOfRawData "
                          "(never clamped by VirtualSize); capstone skipdata on; data "
                          "pseudo-instructions counted per section and excluded from "
                          "inputs_checked; decoder = the vendored build under .local/pylibs"),
             "total": total, "entries_total": total + skipped,
             "ok": ok, "whitelisted": whitelisted, "mismatch": mismatch,
             "asm_error": asm_error, "skipped_data_bytes": skipped,
             "whitelist_entries": len(entries),
             "whitelist_path": os.path.relpath(wl_path, os.path.dirname(os.path.dirname(wl_path)))
             if wl_path else None,
             # inputs_checked counts the instructions this unit examined; data
             # pseudo-instructions are already outside total.  Never derive one figure by
             # subtracting the other -- that double-counted the 478 data records and shrank
             # the coverage denominator by 478.
             "inputs_checked": total,
             "total_instructions": total,
             "compared": ok + whitelisted + mismatch}
    if stats["compared"] == 0:
        return hits, {"error": "nothing completed the round trip (%d instructions, %d asm errors)"
                               % (stats["total_instructions"], stats["asm_error"])}
    ratio = stats["asm_error"] / float(max(stats["total_instructions"], 1))
    stats["asm_error_ratio"] = round(ratio, 6)
    if ratio > 0.01:
        return hits, {"error": "%.2f%% of instructions could not be re-assembled (limit 1%%): %d/%d"
                               % (ratio * 100, stats["asm_error"], stats["total_instructions"])}
    return hits, stats
