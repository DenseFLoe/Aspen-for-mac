# -*- coding: utf-8 -*-
"""Registry of detector modules.

preflight.py derives DETECTORS from this list and dedupes by module name, so a
concurrent contributor only adds a module and one line here (no shared edits).
"""
REGISTRY = [
    "det_omitted_sites",
    "det_stale_metrics",
    "det_row_linkage",
    "det_fingerprint_pathset",
    "det_unresolved_no_recovery",
    "det_symbol_substring",
    "det_wrong_symbol",
    "det_byte_mismatch",
    "det_access_flags",
    "det_eh_clause",
    "det_eh_boundary",
    "det_access_prose",
    "det_truncated_hash",
    "det_semantic_rebuild",
]

# non-detector modules shipped in the same tree (owner of the file, not a detector)
TOOLSETS = [
    {"module": "mk_fingerprints", "origin": "t13", "custodian": "t16",
     "note": "fingerprint table generator; not registered as a detector"},
]
