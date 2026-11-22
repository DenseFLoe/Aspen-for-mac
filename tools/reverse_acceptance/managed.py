"""Conservative comparison of delivered CLR method definitions and a claimed rebuild.

Requires PowerShell 7 on PATH with the .NET MetadataReader. No assembly is loaded
for execution. The extractor lives alongside this module in ManagedEvidence.cs.
"""

from __future__ import annotations

import hashlib
import json
import os
import shutil
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from pathlib import Path


SCOPE = "CLR MethodDef signatures, CIL instruction bytes and token metadata, locals, exception regions and declaration kinds"
READER = Path(__file__).with_name("ManagedEvidence.cs")
# Inputs use environment variables, never executable PowerShell text.
COMMAND = """
$ErrorActionPreference = 'Stop'
[Console]::OutputEncoding = [Text.UTF8Encoding]::new($false)
Add-Type -Path $env:ASPEN_CLR_READER
function Inspect([string]$p) {
    try { [ManagedEvidence]::Inspect($p) }
    catch { @{ error = $_.Exception.GetBaseException().Message } }
}
@{ original = Inspect $env:ASPEN_CLR_ORIGINAL; rebuilt = Inspect $env:ASPEN_CLR_REBUILT } |
    ConvertTo-Json -Compress -Depth 7
"""

BODY_FIELDS = (
    "il_sha256", "eh_sha256", "locals_signature", "init_locals", "max_stack",
)


def _result():
    return {"status": "pass", "scope": SCOPE, "findings": [], "metrics": {}, "methods": []}


def _finding(result, status, code, **detail):
    ranks = {"pass": 0, "inconclusive": 1, "fail": 2}
    if ranks[status] > ranks[result["status"]]:
        result["status"] = status
    result["findings"].append({"code": code, "status": status, **detail})


def _compare(a, b):
    result = _result()
    for side, sample in (("original", a), ("rebuilt", b)):
        if "error" in sample:
            _finding(result, "inconclusive", "clr_unreadable", side=side, reason=sample["error"])
    if result["findings"]:
        return result

    same_metadata = a["metadata"] == b["metadata"]
    metrics = result["metrics"]
    metrics.update(original_sha256=a["sha256"], rebuilt_sha256=b["sha256"],
                   identical_file=a["sha256"] == b["sha256"],
                   normalized_metadata_equal=same_metadata, original_methods=len(a["methods"]),
                   rebuilt_methods=len(b["methods"]), method_comparisons={})
    if not same_metadata:
        # Raw tokens and signatures can point at different strings/members/types
        # even if every instruction is bit-for-bit equal.
        _finding(result, "inconclusive", "metadata_differences_require_review",
                 original_digest=a["metadata"], rebuilt_digest=b["metadata"])

    indices = []
    families = []
    for side, sample in (("original", a), ("rebuilt", b)):
        index = defaultdict(list)
        family = Counter()
        kinds = Counter()
        for row in sample["methods"]:
            kind = row["kind"]
            kinds[kind] += 1
            if kind in ("invalid", "unsupported_body"):
                _finding(result, "inconclusive", "unverified_method", side=side, token=row["token"],
                         kind=kind, reason=row.get("reason", "body lacks a checkable CIL definition"))
            if "key" in row:
                index[row["key"]].append(row)
                family[row["family"]] += 1
        indices.append(index)
        families.append(family)
        metrics[side + "_kinds"] = dict(sorted(kinds.items()))
        metrics[side + "_cil_bytes"] = sum(row.get("il_bytes", 0) for row in sample["methods"])
        metrics[side + "_eh_clauses"] = sum(row.get("eh_count", 0) for row in sample["methods"])
        metrics[side + "_field_rvas"] = sample["field_rvas"]
        metrics[side + "_resources"] = sample["managed_resources"]
        if not kinds["cil"]:
            _finding(result, "inconclusive", "no_verifiable_cil_bodies", side=side)
        if sample["external_modules"]:
            _finding(result, "inconclusive", "additional_cli_modules_unverified",
                     side=side, count=sample["external_modules"])
        if (sample["cli_flags"] & 1) == 0 or sample["cli_flags"] & 16 or any(
            sample[k] for k in ("native_header", "vtable_fixups", "code_manager", "export_jumps")
        ):
            _finding(result, "inconclusive", "mixed_or_native_payload", side=side)

    for field in ("machine", "pe_magic", "cli_flags", "managed_entry"):
        if a[field] != b[field]:
            _finding(result, "inconclusive", "execution_context_changed", field=field,
                     original=a[field], rebuilt=b[field])
    # Metadata includes FieldRVA rows and manifest resource descriptors, but
    # the actual initialized bytes are stored separately in the PE image.
    if a["resource_data"] != b["resource_data"]:
        _finding(result, "inconclusive", "managed_resource_directory_changed",
                 original=a["resource_data"], rebuilt=b["resource_data"])
    if a["resource_data"]["external"] or b["resource_data"]["external"]:
        _finding(result, "inconclusive", "external_resource_unverified")
    for side, sample in (("original", a), ("rebuilt", b)):
        metrics[side + "_field_bytes"] = sum(row["size"] for row in sample["field_data"])
        metrics[side + "_resource_bytes"] = sample["resource_data"]["size"]
        for row in sample["field_data"]:
            if not row["digest"]:
                _finding(result, "inconclusive", "field_extent_unverified", side=side, token=row["token"])
    if a["field_data"] != b["field_data"]:
        _finding(result, "inconclusive", "managed_field_initializers_changed",
                 original=a["field_data"], rebuilt=b["field_data"])
    clean_identities = all("key" in row for sample in (a,b) for row in sample["methods"])
    for family in sorted(families[0].keys() | families[1].keys()):
        if families[0][family] != families[1][family]:
            _finding(result, "fail" if clean_identities else "inconclusive",
                     "named_method_count_changed", family=family,
                     original=families[0][family], rebuilt=families[1][family])

    left, right = indices
    counts = Counter()
    for key in sorted(left.keys() | right.keys()):
        x, y = left.get(key, []), right.get(key, [])
        row = {"signature_key": key, "original": [i["token"] for i in x],
               "rebuilt": [i["token"] for i in y]}
        if len(x) != 1 or len(y) != 1:
            state = "signature_unpaired" if not x or not y else "signature_ambiguous"
            _finding(result, "inconclusive", state, **row)
        else:
            old, new = x[0], y[0]
            changed = [field for field in ("kind", "attrs", "impl", *BODY_FIELDS)
                       if old.get(field) != new.get(field)]
            if changed:
                state = "method_difference"
                # No general equivalence claim follows from changed IL. A body
                # replaced with a declaration, however, has lost its implementation.
                lost = old["kind"] == "cil" and new["kind"] in ("abstract", "runtime", "internalcall", "pinvoke")
                _finding(result, "fail" if lost else "inconclusive", state,
                         **row, changed={k: [old.get(k), new.get(k)] for k in changed})
            elif old["kind"] in ("invalid", "unsupported_body"):
                state = "unverified_method"
            elif not same_metadata:
                state = "matching_projection_metadata_unverified"
            else:
                state = "cil_equal" if old["kind"] == "cil" else "declaration_equal"
        counts[state] += 1
        row["state"] = state
        result["methods"].append(row)
    metrics["method_comparisons"] = dict(sorted(counts.items()))
    return result


def check(original: bytes, rebuilt: Path) -> dict:
    """Compare a claimed rebuild; this result never vouches for source provenance."""
    result = _result()
    pwsh = shutil.which("pwsh")
    rebuilt = Path(rebuilt)
    if not pwsh or not READER.is_file() or not rebuilt.is_file():
        _finding(result, "inconclusive", "clr_input_or_tool_missing",
                 powershell=bool(pwsh), reader=READER.is_file(), rebuilt=rebuilt.is_file())
        return result
    try:
        with tempfile.TemporaryDirectory(prefix="aspen-clr-compare-") as td:
            path = Path(td, "original.bin")
            path.write_bytes(original)
            env = {**os.environ, "ASPEN_CLR_READER": str(READER.resolve()),
                   "ASPEN_CLR_ORIGINAL": str(path), "ASPEN_CLR_REBUILT": str(rebuilt.resolve())}
            proc = subprocess.run(
                [pwsh, "-NoProfile", "-NonInteractive", "-Command", COMMAND],
                env=env, capture_output=True, timeout=180, check=False,
            )
        if proc.returncode:
            raise ValueError(proc.stderr.decode("utf-8", errors="replace")[-1500:])
        data = json.loads(proc.stdout.decode("utf-8-sig"))
        a, b = data["original"], data["rebuilt"]
        if "sha256" in a and a["sha256"] != hashlib.sha256(original).hexdigest():
            raise ValueError("reader consumed different original bytes")
        return _compare(a, b)
    except (OSError, ValueError, KeyError, subprocess.TimeoutExpired) as exc:
        _finding(result, "inconclusive", "clr_reader_error", reason=str(exc))
        return result


if __name__ == "__main__":
    import argparse
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("original", type=Path)
    p.add_argument("rebuilt", type=Path)
    args = p.parse_args()
    report = check(args.original.read_bytes(), args.rebuilt)
    print(json.dumps(report, ensure_ascii=True))
    sys.exit({"pass": 0, "fail": 1, "inconclusive": 2}[report["status"]])

