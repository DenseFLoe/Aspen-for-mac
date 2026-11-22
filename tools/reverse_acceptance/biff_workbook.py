"""Compare an editable BIFF8 record listing with the original Workbook stream."""
import io
import json
from pathlib import Path
import re
import struct


SCOPE = "BIFF8 workbook record identities and payloads"
MAX_INPUT = 64 * 1024 * 1024
MAX_JSON = 16 * 1024 * 1024
MAX_RECORDS = 131072
MAX_PAYLOAD = 8224
BOF = 0x0809
LBL = 0x0018


def _unique(pairs):
    fields = dict(pairs)
    if len(fields) != len(pairs):
        raise ValueError("duplicate workbook record field")
    return fields


def _hex(data, limit):
    if not isinstance(data, str) or len(data) > 2 * limit or not re.fullmatch(r"(?:[0-9A-Fa-f]{2})*", data):
        raise ValueError("invalid workbook record bytes")
    return bytes.fromhex(data)


def _uint(data, maximum):
    if type(data) is not int or not 0 <= data <= maximum:
        raise ValueError("invalid numeric workbook record field")
    return data


def _defined_name(value):
    fields = {"text", "flags", "key", "ixals", "scope", "reserved", "wide", "formula_tokens"}
    if not isinstance(value, dict) or value.keys() != fields or not isinstance(value["text"], str):
        raise ValueError("unsupported defined-name record")
    wide = _uint(value["wide"], 1)
    text = value["text"].encode("utf-16le" if wide else "latin-1")
    formula = _hex(value["formula_tokens"], MAX_PAYLOAD)
    reserved = _hex(value["reserved"], 4)
    if len(reserved) != 4:
        raise ValueError("incomplete defined-name field")
    length = _uint(len(text) // (wide + 1), 255)
    header = struct.pack("<HBBHHH", _uint(value["flags"], 65535), _uint(value["key"], 255),
                         length, len(formula), _uint(value["ixals"], 65535), _uint(value["scope"], 65535))
    return header + reserved + bytes([wide]) + text + formula


def _claimed_records(rows):
    if not isinstance(rows, list) or not 0 < len(rows) <= MAX_RECORDS:
        raise ValueError("invalid editable workbook record table size")
    for row in rows:
        if not isinstance(row, dict) or not isinstance(row.get("id"), str) or not re.fullmatch(r"[0-9A-Fa-f]{4}", row["id"]):
            raise ValueError("invalid editable workbook record identifier")
        record = int(row["id"], 16)
        if row.keys() == {"id", "data"}:
            yield record, _hex(row["data"], MAX_PAYLOAD)
        elif row.keys() == {"id", "defined_name"} and record == LBL:
            payload = _defined_name(row["defined_name"])
            if len(payload) > MAX_PAYLOAD:
                raise ValueError("defined-name payload exceeds the BIFF8 record size")
            yield record, payload
        else:
            raise ValueError("unsupported editable workbook record shape")


def _original_records(raw):
    if len(raw) < 20:
        raise ValueError("original workbook does not begin with a complete BIFF8 Globals BOF")
    first_type, first_size = struct.unpack_from("<HH", raw)
    version, stream_type = struct.unpack_from("<HH", raw, 4)
    if (first_type, first_size, version, stream_type) != (BOF, 16, 0x0600, 0x0005):
        raise ValueError("original workbook does not begin with a complete BIFF8 Globals BOF")
    offset = 0
    records = []
    while offset < len(raw):
        if offset + 4 > len(raw) or len(records) >= MAX_RECORDS:
            raise ValueError("incomplete or oversized original BIFF8 record stream")
        record, size = struct.unpack_from("<HH", raw, offset)
        end = offset + 4 + size
        if end > len(raw) or size > MAX_PAYLOAD:
            raise ValueError("invalid original BIFF8 record span")
        records.append((offset, record, raw[offset + 4:end]))
        offset = end
    return records


def compare(raw, rows):
    """Compare record identities and payloads without interpreting or executing formulas."""
    expected = _original_records(raw)
    actual = list(_claimed_records(rows))
    findings = []
    if len(expected) != len(actual):
        findings.append({"code": "biff_record_count", "original": len(expected), "submitted": len(actual)})
    exact_names = exact_records = 0
    for index, ((offset, record, raw_payload), (claimed, payload)) in enumerate(zip(expected, actual), 1):
        if record == claimed and payload == raw_payload:
            exact_records += 1
            exact_names += record == LBL
        else:
            difference = next((pos for pos, pair in enumerate(zip(raw_payload, payload)) if pair[0] != pair[1]),
                              min(len(raw_payload), len(payload)))
            findings.append({
                "code": "biff_record_differs", "row": index, "original_offset": offset,
                "original_record": f"0x{record:04x}", "submitted_record": f"0x{claimed:04x}",
                "first_payload_offset": difference if record == claimed else None,
            })
    return {
        "scope": SCOPE, "status": "fail" if findings else "pass", "findings": findings,
        "metrics": {
            "original_records": len(expected), "submitted_records": len(actual),
            "exact_records": exact_records, "exact_defined_name_records": exact_names,
        },
    }


def check(original, delivery):
    """Read the original compound workbook stream and a pinned candidate's JSON projection."""
    def inconclusive(code):
        return {"scope": SCOPE, "status": "inconclusive", "findings": [{"code": code}], "metrics": {}}

    try:
        import olefile
    except ImportError:
        return inconclusive("biff_compound_reader_unavailable")
    if len(original) > MAX_INPUT:
        return inconclusive("biff_original_size_limit")
    try:
        root = Path(delivery).resolve(strict=True)
        manifest = root / "workbook.json"
        if manifest.is_symlink() or manifest.resolve(strict=True) != manifest or not manifest.is_file():
            return inconclusive("biff_workbook_listing_path")
        with manifest.open("rb") as handle:
            claimed = handle.read(MAX_JSON + 1)
        if len(claimed) > MAX_JSON:
            return inconclusive("biff_workbook_listing_size_limit")
        with olefile.OleFileIO(io.BytesIO(original), raise_defects=olefile.DEFECT_INCORRECT) as compound:
            streams = [path for path in compound.listdir() if len(path) == 1 and path[0].casefold() in {"book", "workbook"}]
            if len(streams) != 1 or compound.get_size(streams[0]) > MAX_INPUT:
                return inconclusive("biff_workbook_stream_unavailable")
            with compound.openstream(streams[0]) as workbook:
                raw = workbook.read(MAX_INPUT + 1)
        if len(raw) > MAX_INPUT:
            return inconclusive("biff_workbook_stream_size_limit")
        return compare(raw, json.loads(claimed.decode("utf-8"), object_pairs_hook=_unique))
    except (ValueError, OSError, RuntimeError, TypeError, struct.error):
        return inconclusive("biff_workbook_structure_unverified")
