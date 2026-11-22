"""Reconcile original-verified instruction addresses with a pinned earlier listing."""
import csv
from hashlib import sha256
from io import StringIO
from pathlib import Path
import re


REFERENCE = "baselines/findcomponent-s5-instructions.csv"
BASELINES = {
    "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02": (
        REFERENCE,
        "ae40cd3c83ab73d0115c71822545a645bb9514082c125ea5ff890f143857ff62",
        "a180dcfd1b6bd39072a4a03b94b908408e6da426:handoff/inbox/NATIVE-337/code/native.asm",
    ),
}


def read_baseline(data):
    rows = csv.reader(StringIO(data.decode("ascii")), strict=True)
    if next(rows, None) != ["rva", "bytes"]:
        raise ValueError("Unexpected historical instruction table header")
    previous_end = 0
    for rva, blob in rows:
        if not re.fullmatch(r"[0-9a-f]{1,8}", rva) or not re.fullmatch(r"(?:[0-9a-f]{2}){1,15}", blob):
            raise ValueError("Invalid historical instruction row")
        address, raw = int(rva, 16), bytes.fromhex(blob)
        if address < previous_end:
            raise ValueError("Historical instructions overlap or are out of order")
        previous_end = address + len(raw)
        yield address, raw


def compare(original, pe, x86, decode, instructions, report):
    identity = sha256(original).hexdigest()
    if identity not in BASELINES:
        return None
    reference, digest, source = BASELINES[identity]
    result = {"reference": source, "reference_sha256": digest, "original_sha256": identity, "status": "inconclusive",
              "verified_baseline_instructions": 0, "missing_nonpadding": [], "missing_nop_or_int3": []}
    try:
        data = (Path(__file__).resolve().parent / reference).read_bytes()
        if sha256(data).hexdigest() != digest:
            raise ValueError("Historical instruction table differs from its reviewed fingerprint")
        verified = list(read_baseline(data))
        if not verified:
            raise ValueError("Historical instruction table is empty")
        padding = {x86.Mnemonic.NOP, x86.Mnemonic.INT3}
        decoded = []
        for address, raw in verified:
            ins = decode(address)
            if ins is None or ins.is_invalid or ins.len != len(raw) or pe.get_data(address, len(raw)) != raw:
                report("inconclusive", "historical_instruction_identity",
                       "Historical instruction cannot be proven against the original.", address)
                return result
            decoded.append((address, raw, ins))
        for address, raw, ins in decoded:
            if address in instructions:
                continue
            key = "missing_nop_or_int3" if ins.mnemonic in padding else "missing_nonpadding"
            result[key].append({"rva": hex(address), "bytes": raw.hex(" "), "instruction": str(ins)})
        result["verified_baseline_instructions"] = len(verified)
    except (OSError, UnicodeError, ValueError, csv.Error) as exc:
        report("inconclusive", "historical_instruction_baseline", str(exc), line=reference)
        return result
    missing = result["missing_nonpadding"]
    result["status"] = "fail" if missing else "pass"
    if missing:
        report("fail", "historical_instruction_missing",
               f"{len(missing)} verified historical instruction starts are absent from the submitted listing.",
               int(missing[0]["rva"], 16), reference)
    return result
