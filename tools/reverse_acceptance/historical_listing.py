"""Reconcile original-verified instruction addresses with a pinned earlier listing."""
import csv
from hashlib import sha256
from io import StringIO
import re


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


def compare(data, pe, x86, decode, instructions, report):
    result = {"reference_sha256": sha256(data).hexdigest(), "status": "inconclusive",
              "verified_baseline_instructions": 0, "missing_nonpadding": [], "missing_nop_or_int3": []}
    try:
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
    except (UnicodeError, ValueError, csv.Error) as exc:
        report("inconclusive", "historical_instruction_baseline", str(exc))
        return result
    missing = result["missing_nonpadding"]
    result["status"] = "fail" if missing else "pass"
    if missing:
        report("fail", "historical_instruction_missing",
               f"{len(missing)} verified historical instruction starts are absent from the submitted listing.",
               int(missing[0]["rva"], 16))
    return result
