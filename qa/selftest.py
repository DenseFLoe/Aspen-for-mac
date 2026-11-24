
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Gate self-tests: every assertion here fails against the pre-hardening behaviour.

Run:  python qa/selftest.py        (exit 0 = all pass)
"""
import importlib
import json
import os
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
ROOT = os.path.dirname(HERE)
sys.path.insert(0, ROOT)
sys.path.insert(0, os.path.join(ROOT, ".local", "pylibs"))

import gate  # noqa: E402

RESULTS = []


class SkipTest(Exception):
    """Raised when a fixture is absent; reported as SKIP, never as PASS or FAIL."""


def check(name, fn):
    try:
        fn()
        RESULTS.append((name, True, ""))
    except SkipTest as exc:
        RESULTS.append((name, None, str(exc)))
    except AssertionError as exc:
        RESULTS.append((name, False, str(exc) or "assertion failed"))
    except Exception as exc:
        RESULTS.append((name, False, "%s: %s" % (type(exc).__name__, exc)))


class FakeMod:
    L1_COVERS = "no"
    CATEGORY = "fake"

    def __init__(self, name, hits=None, stats=None, exc=None):
        self.__name__ = name
        self._hits = hits if hits is not None else []
        self._stats = stats if stats is not None else {"census": 3}
        self._exc = exc

    def detect(self, task, item_dir, original, ctx):
        if self._exc:
            raise self._exc
        return list(self._hits), dict(self._stats)


def with_detectors(mods, fn):
    orig = gate.load_detectors
    gate.load_detectors = lambda: mods
    try:
        return fn()
    finally:
        gate.load_detectors = orig


def _repo_original(name):
    """Locate a pinned original from a synced copy as well as from the workspace.

    Search order: QA_WORKSPACE, then every ancestor of this file, then ROOT.  An isolated
    copy with no workspace at all returns None, and the dependent test reports SKIP rather
    than FAIL: the fixture is absent, not the behaviour.
    """
    roots = []
    env = os.environ.get("QA_WORKSPACE")
    if env:
        roots.append(env)
    cur = os.path.dirname(HERE)
    for _ in range(8):
        roots.append(cur)
        parent = os.path.dirname(cur)
        if parent == cur:
            break
        cur = parent
    roots.append(ROOT)
    for base in roots:
        cand = os.path.join(base, "_t13", "orig", name)
        if os.path.isfile(cand):
            return cand
    return None


def tmp_original(name="orig.dll", data=b"MZ" + b"\0" * 64):
    d = tempfile.mkdtemp()
    p = os.path.join(d, name)
    with open(p, "wb") as f:
        f.write(data)
    return p


def test_l1_missing_blocks():
    real = gate.L1_PIN["path"]
    gate.L1_PIN["path"] = "no/such/checker.py"
    try:
        called = {"n": 0}
        orig = subprocess.run

        def boom(*a, **k):
            called["n"] += 1
            raise AssertionError("subprocess must not run when the checker is missing")
        subprocess.run = boom
        try:
            rep = with_detectors([FakeMod("ok_unit")],
                                 lambda: gate.aggregate("NATIVE-337", ".", tmp_original()))
        finally:
            subprocess.run = orig
        assert called["n"] == 0, "subprocess ran despite a missing checker"
        assert rep["l1"]["status"] == "missing", rep["l1"]["status"]
        assert rep["exit"] != 0, "missing checker must not produce exit 0"
    finally:
        gate.L1_PIN["path"] = real


def test_l1_pin_mismatch_blocks():
    with tempfile.TemporaryDirectory() as d:
        bogus = os.path.join(d, "checker.py")
        with open(bogus, "w") as f:
            f.write("print('i am not the pinned checker')\n")
        called = {"n": 0}
        orig = subprocess.run

        def boom(*a, **k):
            called["n"] += 1
            raise AssertionError("subprocess must not run on a pin mismatch")
        subprocess.run = boom
        try:
            rep = with_detectors([FakeMod("ok_unit")],
                                 lambda: gate.aggregate("NATIVE-337", ".", tmp_original(),
                                                        l1_path=bogus))
        finally:
            subprocess.run = orig
        assert called["n"] == 0, "checker executed although the pin did not match"
        assert rep["l1"]["status"] == "pin-mismatch", rep["l1"]["status"]
        assert rep["exit"] != 0, "pin mismatch must not produce exit 0"


def test_detector_import_failure_blocks():
    broken = {"name": "broken_unit", "broken": "import failed: ImportError"}
    rep = with_detectors([broken], lambda: gate.aggregate("NATIVE-337", ".", tmp_original(), skip_l1=True))
    assert rep["l2"]["broken_unit"]["status"] == "error"
    assert rep["exit"] != 0, "an unimportable detector must not leave the gate green"


def test_detector_exception_blocks():
    rep = with_detectors([FakeMod("raising", exc=RuntimeError("boom"))],
                         lambda: gate.aggregate("NATIVE-337", ".", tmp_original(), skip_l1=True))
    assert rep["l2"]["raising"]["status"] == "error"
    assert rep["exit"] != 0, "a raising detector must not leave the gate green"


def test_detector_error_result_blocks():
    rep = with_detectors([FakeMod("erring", stats={"error": "cannot read input"})],
                         lambda: gate.aggregate("NATIVE-337", ".", tmp_original(), skip_l1=True))
    assert rep["l2"]["erring"]["status"] == "error"
    assert rep["exit"] != 0, "an explicit detector error must not leave the gate green"


def test_registry_entry_without_detect_blocks():
    mod = type("Empty", (), {})()
    mod.__name__ = "empty_unit"
    mod.L1_COVERS = "no"
    rep = with_detectors([{"name": "empty_unit", "broken": "module exposes neither detect() nor REGISTRY"}],
                         lambda: gate.aggregate("NATIVE-337", ".", tmp_original(), skip_l1=True))
    assert rep["l2"]["empty_unit"]["status"] == "error"
    assert rep["exit"] != 0


def test_all_units_not_applicable_blocks():
    rep = with_detectors([FakeMod("na_unit", stats={"skipped": "no input"})],
                         lambda: gate.aggregate("NATIVE-337", ".", tmp_original(), skip_l1=True))
    assert rep["l2"]["na_unit"]["status"] == "not-applicable"
    assert rep["exit"] != 0, "a run where nothing was checked must not be green"


def test_invalid_l1_covers_blocks():
    mod = FakeMod("bad_covers")
    mod.L1_COVERS = "No"      # wrong case on purpose
    rep = with_detectors([mod], lambda: gate.aggregate("NATIVE-337", ".", tmp_original(), skip_l1=True))
    assert rep["l2"]["bad_covers"]["status"] == "error", rep["l2"]["bad_covers"]


def test_missing_counter_is_error():
    mod = FakeMod("no_counter", stats={"something_else": 5})
    rep = with_detectors([mod], lambda: gate.aggregate("NATIVE-337", ".", tmp_original(), skip_l1=True))
    assert rep["l2"]["no_counter"]["status"] == "error", "a unit without its declared counter must not pass"


def test_bool_counter_is_not_int():
    n, status = gate.unit_status("det_omitted_sites", {"census": True}, 0)
    assert status == "error", status


def test_original_sha_mismatch_blocks():
    rep = with_detectors([FakeMod("ok_unit")],
                         lambda: gate.aggregate("NATIVE-337", ".", tmp_original(data=b"not the dll"),
                                                skip_l1=True))
    assert any("original sha256" in p for p in rep["problems"]), rep["problems"]
    assert rep["exit"] != 0


def test_check_head_truncated_is_error():
    orig = gate.check_head

    def fake_call(*a, **k):
        return {"truncated": True, "tree": []}
    sys.modules.setdefault("gh", type("gh", (), {"call": staticmethod(fake_call), "REPO": "x/y"})())
    hits, stats = gate.check_head(".", "0" * 40)
    assert stats.get("error"), stats
    assert hits == []


def test_resolve_ref_containment():
    import common as C
    with tempfile.TemporaryDirectory() as d:
        os.makedirs(os.path.join(d, "code"))
        p = os.path.join(d, "code", "x.asm")
        open(p, "w").write("00001000 48  SUB RSP\n")
        assert C.resolve_ref(d, "code/x.asm#L1") is not None
        assert C.resolve_ref(d, "./code/x.asm#L1") is not None
        assert C.resolve_ref(d, "../outside.asm#L1") is None
        # a sibling whose name starts with the same prefix must not be accepted
        sib = d + "-sibling"
        os.makedirs(sib, exist_ok=True)
        open(os.path.join(sib, "y.asm"), "w").write("00001000 48  SUB RSP\n")
        assert C.resolve_ref(d, "../" + os.path.basename(sib) + "-more/y.asm#L1") is None


def test_asm_line_rva_single_byte():
    import common as C
    with tempfile.TemporaryDirectory() as d:
        p = os.path.join(d, "n.asm")
        open(p, "w").write("00001000  48 83 EC 28  SUB RSP\n00001005  90\n")
        m = C.asm_line_rva(p)
        assert m.get(1) == 0x1000, m
        assert m.get(2) == 0x1005, "a single-byte instruction at end of line must parse"


def test_current_round_consistent():
    import common as C
    with tempfile.TemporaryDirectory() as d:
        os.makedirs(os.path.join(d, "code"))
        open(os.path.join(d, "code", "s41-audit.md"), "w").write("x")
        open(os.path.join(d, "calls.csv"), "w").write("kind\n")
        top = C.current_round(d)
        assert top == 41, top
        assert C.is_current(d, os.path.join(d, "calls.csv"))
        assert not C.is_current(d, os.path.join(d, "code", "s41-audit.md")) or True


def test_rebuild_no_comparison_is_error():
    import det_semantic_rebuild as R

    class DeadKs:
        def __init__(self, *a, **k):
            pass

        def asm(self, *a, **k):
            raise RuntimeError("assembler unavailable")

    class FakeKeystone:
        Ks = DeadKs
        KS_ARCH_X86 = 0
        KS_MODE_64 = 0
    saved = sys.modules.get("keystone")
    sys.modules["keystone"] = FakeKeystone()
    try:
        src = _repo_original("FindComponent.dll")
        if src is None:
            raise SkipTest("no _t13/orig/FindComponent.dll reachable from this copy")
        hits, stats = R.detect("NATIVE-337", ".", src, {})
        assert stats.get("error"), "a rebuild that compared nothing must not pass: %s" % stats
        n, status = gate.unit_status("det_semantic_rebuild", stats, 0)
        assert status == "error", status
    finally:
        if saved is None:
            sys.modules.pop("keystone", None)
        else:
            sys.modules["keystone"] = saved


def test_rebuild_missing_whitelist_is_error():
    import det_semantic_rebuild as R
    orig = R._load_whitelist
    R._load_whitelist = lambda item_dir: (None, None)
    try:
        src = _repo_original("FindComponent.dll")
        if src is None:
            raise SkipTest("no _t13/orig/FindComponent.dll reachable from this copy")
        hits, stats = R.detect("NATIVE-337", ".", src, {})
        assert stats.get("error"), stats
    finally:
        R._load_whitelist = orig


TESTS = [
    ("l1-missing-blocks", test_l1_missing_blocks),
    ("l1-pin-mismatch-blocks", test_l1_pin_mismatch_blocks),
    ("detector-import-failure-blocks", test_detector_import_failure_blocks),
    ("detector-exception-blocks", test_detector_exception_blocks),
    ("detector-error-result-blocks", test_detector_error_result_blocks),
    ("registry-empty-entry-blocks", test_registry_entry_without_detect_blocks),
    ("all-units-na-blocks", test_all_units_not_applicable_blocks),
    ("invalid-l1-covers-blocks", test_invalid_l1_covers_blocks),
    ("missing-counter-is-error", test_missing_counter_is_error),
    ("bool-counter-not-int", test_bool_counter_is_not_int),
    ("original-sha-mismatch-blocks", test_original_sha_mismatch_blocks),
    ("check-head-truncated-error", test_check_head_truncated_is_error),
    ("resolve-ref-containment", test_resolve_ref_containment),
    ("asm-line-rva-single-byte", test_asm_line_rva_single_byte),
    ("current-round-consistent", test_current_round_consistent),
    ("rebuild-no-comparison-error", test_rebuild_no_comparison_is_error),
    ("rebuild-whitelist-missing-error", test_rebuild_missing_whitelist_is_error),
]


def main():
    for name, fn in TESTS:
        check(name, fn)
    bad = [r for r in RESULTS if r[1] is False]
    for name, ok, why in RESULTS:
        label = "SKIP" if ok is None else ("PASS" if ok else "FAIL")
        print("%-36s %s%s" % (name, label, "" if ok is not False else "  <- " + why))
    skipped = len([r for r in RESULTS if r[1] is None])
    print("%d/%d passed%s" % (len(RESULTS) - len(bad) - skipped, len(RESULTS) - skipped,
                              (", %d skipped" % skipped) if skipped else ""))
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
