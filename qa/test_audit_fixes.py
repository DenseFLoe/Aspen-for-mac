import contextlib
import io
import json
import os
from pathlib import Path
import sys
import tempfile
import types
import unittest
from unittest.mock import patch

from qa import gate
import common as C
import det_fingerprint_pathset as F
import det_truncated_hash as T
import fetch


TASK = "NATIVE-337"
FULL = "a" * 64


def put(path, text):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")
    return path


def doc(path, data):
    return put(path, json.dumps(data))


class AuditFixes(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)
        self.item = self.root / TASK
        self.item.mkdir()
        self.original = put(self.root / "original.dll", "original")

    def cli(self, *args):
        stderr = io.StringIO()
        with contextlib.redirect_stderr(stderr):
            status = gate.main(["--quiet", *map(str, args)])
        return status, stderr.getvalue()

    def test_01_skipped_l1(self):
        hit = {"severity": "defect"}
        for cover in ("yes", "partial"):
            with self.subTest(cover=cover):
                detector = types.SimpleNamespace(__name__="det_row_linkage", L1_COVERS=cover,
                    detect=lambda *args: ([hit], {"appendix_files": 1}))
                with patch.object(gate, "load_detectors", return_value=[detector]):
                    rep = gate.aggregate("fixture", self.item, self.original, skip_l1=True)
                    self.assertEqual((rep["units"]["pass"], rep["units"]["fail"], rep["exit"]),
                                     (0, 1, 2))
                    with patch.object(gate, "run_l1", return_value={"ran": True, "exit": 0}):
                        rep = gate.aggregate("fixture", self.item, self.original)
                    self.assertEqual((rep["exit"], len(rep["warnings"])), (0, 1))

    def test_02_cache_identity(self):
        head_a, head_b = "12345678" + "a" * 32, "12345678" + "b" * 32
        combos = [("owner/first", head_a), ("owner/first", head_b), ("owner/second", head_a)]
        cache = self.root / "cache"
        report = self.root / "report.json"
        raw_requests = []
        expected = {}
        responses = {}
        path = f"handoff/inbox/{TASK}/payload.txt"
        for i, (repo, head) in enumerate(combos):
            data = str(i).encode()
            expected[repo, head] = data.decode()
            url = f"https://api.github.com/repos/{repo}/git/trees/{head}?recursive=1"
            responses[url] = json.dumps({"tree": [
                {"type": "blob", "path": path, "sha": gate.git_blob_sha1(data)}]}).encode()
            responses[f"https://raw.githubusercontent.com/{repo}/{head}/{path}"] = data

        def get(url, token=None):
            if "raw.githubusercontent.com" in url:
                raw_requests.append(url)
            return responses[url]

        def aggregate(task, item_dir, *args):
            return {"exit": 0, "payload": (Path(item_dir) / "payload.txt").read_text()}

        with patch.object(fetch, "_get", side_effect=get), patch.object(fetch, "_token", return_value=None), \
                patch.object(gate, "aggregate", side_effect=aggregate):
            caches = []
            for repo, head in combos:
                with self.subTest(repo=repo, head=head):
                    status, err = self.cli("--cache", cache, "--repo", repo, "--head", head, "--json", report)
                    self.assertEqual(status, 0, err)
                    result = json.loads(report.read_text())
                    caches.append(result["fetched"]["cache"])
                    self.assertEqual((result["fetched"]["head"], result["payload"]), (head, expected[repo, head]))
            self.assertEqual(len(set(caches)), 3)
            args = ("--cache", cache, "--repo", combos[-1][0], "--head", head_a, "--json", report)
            self.assertEqual(self.cli(*args)[0], 0)
            self.assertEqual(len(raw_requests), 3)
            cached_item = Path(caches[-1]) / "handoff" / "inbox" / TASK
            extra = put(cached_item / "extra.txt", "extra")
            status, err = self.cli(*args)
            self.assertEqual(status, 2, err)
            self.assertIn("extra.txt", err)
            extra.unlink()
            payload = put(cached_item / "payload.txt", "tampered")
            status, err = self.cli(*args)
            self.assertEqual(status, 2, err)
            self.assertIn("payload.txt", err)
            payload.unlink()
            status, err = self.cli(*args)
            self.assertEqual(status, 2, err)
            self.assertIn("payload.txt", err)

    def test_03_default_from_root(self):
        cwd = Path.cwd()
        output = io.StringIO()
        observations = []
        expected = self.root / "handoff" / "inbox" / TASK
        self.addCleanup(os.chdir, cwd)
        os.chdir(self.item)

        def compare(item_dir, head):
            observations.append((Path(item_dir), str(expected) in output.getvalue()))
            return [], {}

        with patch.object(gate, "ROOT", str(self.root)), patch.object(gate, "check_head", side_effect=compare), \
                patch.object(gate, "aggregate", return_value={"exit": 0}), contextlib.redirect_stderr(output):
            status = gate.main(["--quiet", "--against-head", "0" * 40])
        self.assertEqual((status, observations), (0, [(expected, True)]))

    def test_04_report_outside_tree(self):
        put(self.item / "payload.txt", "payload")
        tree = {"tree": [{"type": "blob", "path": f"handoff/inbox/{TASK}/payload.txt",
                          "sha": gate.git_blob_sha1(b"payload")}]}
        gh = types.SimpleNamespace(REPO="owner/repo", call=lambda *args: tree)
        args = ("--item-dir", self.item, "--against-head", "0" * 40, "--json")
        unsafe = self.item / "report.json"
        with patch.dict(sys.modules, {"gh": gh}), patch.object(gate, "aggregate", side_effect=lambda *a: {"exit": 0}):
            runs = [self.cli(*args, unsafe) for _ in range(2)]
            self.assertEqual([status for status, _ in runs], [2, 2])
            self.assertTrue(all("report" in err and "candidate" in err for _, err in runs), runs)
            self.assertFalse(unsafe.exists())
            safe = self.root / "report.json"
            os.link(self.item / "payload.txt", safe)
            self.assertEqual([self.cli(*args, safe)[0] for _ in range(2)], [0, 0])
            self.assertEqual((self.item / "payload.txt").read_text(), "payload")

    def test_05_metadata_round_and_snapshot(self):
        doc(self.item / "baseline.json", {"digest": FULL})
        put(self.item / "s2-submission.md", "receipt")
        doc(self.item / "s2-table.json", {"digest": "aaaa"})
        put(self.item / "work" / "s99-gate.txt", "log")
        with patch.object(gate, "load_detectors", return_value=[T]):
            before = gate.aggregate("fixture", self.item, self.original, skip_l1=True)
            put(self.item / "s3-submission.md", "new receipt")
            doc(self.item / "s3-table.json", {"digest": FULL})
            after = gate.aggregate("fixture", self.item, self.original, skip_l1=True)
        self.assertEqual((before["l2"][T.__name__]["status"], before["exit"],
                          after["l2"][T.__name__]["status"], after["exit"]), ("fail", 2, "pass", 0))
        self.assertEqual(after["l2"][T.__name__]["inputs_checked"], 2)

    def test_06_no_historical_fallback(self):
        payload = put(self.item / "payload.txt", "bytes")
        digest = C.sha256_file(payload)
        doc(self.item / "s1-fingerprints.json", {"payload.txt": digest})
        receipt = put(self.item / "s2-submission.md", "receipt")
        hits, stats = F.detect(TASK, self.item, self.original, {})
        self.assertEqual((stats["fingerprint_files"], stats["previous_tables"], stats["declared_paths"]), (0, 1, 0))
        self.assertTrue(any(h["severity"] == "defect" and "missing" in h["evidence"] for h in hits), hits)
        put(receipt, f"| payload.txt | {digest} |\n")
        hits, stats = F.detect(TASK, self.item, self.original, {})
        self.assertEqual((hits, stats["verified_paths"]), ([], 1))

    def test_07_real_containment(self):
        sibling = put(self.root / (TASK + "-sibling") / "payload.txt", "bytes")
        label = f"../{sibling.parent.name}/payload.txt"
        doc(self.item / "fingerprints.json", {label: C.sha256_file(sibling)})
        with patch.object(C, "sha256_file", wraps=C.sha256_file) as read:
            hits, stats = F.detect(TASK, self.item, self.original, {})
        self.assertFalse(read.called, "read a file in a sibling with the same path prefix")
        self.assertEqual((stats["declared_paths"], stats["verified_paths"]), (1, 0))
        self.assertTrue(any("outside" in h["evidence"] for h in hits), hits)

    def test_08_parse_errors_and_counters(self):
        put(self.item / "s2-submission.md", "receipt")
        payload = put(self.item / "payload.txt", "bytes")
        broken = put(self.item / "s2-fingerprints.json", "{")
        doc(self.item / "s2-manifest.json", {"payload.txt": C.sha256_file(payload)})
        doc(self.item / "metrics.json", {"payload_sha256": C.sha256_file(payload)})
        for detector, keys, expected in (
            (F, ("fingerprint_files", "files_parsed", "comparisons"), (2, 1, 1)),
            (T, ("files_found", "files_parsed", "digests_compared"), (3, 2, 1)),
        ):
            with self.subTest(detector=detector.__name__):
                hits, stats = detector.detect(TASK, self.item, self.original, {})
                self.assertIn(broken.name, stats.get("error", ""), stats)
                self.assertEqual(tuple(stats[key] for key in keys), expected)
                self.assertEqual(gate.unit_status(detector.__name__, stats, len(hits))[1], "error")

    def test_09_declared_vs_verified(self):
        keep = put(self.item / "keep.txt", "bytes")
        digest = C.sha256_file(keep)
        previous = {"keep.txt": digest, "short.txt": digest, "absent.txt": digest,
                    "mismatch.txt": digest, "tool/outside.txt": digest, "listed.txt": digest, "dropped.txt": digest}
        doc(self.item / "s1-fingerprints.json", previous)
        put(self.item / "s2-submission.md", "- listed.txt\n")
        put(self.item / "mismatch.txt", "different bytes")
        doc(self.item / "s2-fingerprints.json", {"keep.txt": digest, "short.txt": "aaa", "absent.txt": digest,
                                                "mismatch.txt": digest, "tool/outside.txt": digest})
        hits, stats = F.detect(TASK, self.item, self.original, {})
        self.assertEqual((stats["declared_paths"], stats.get("verified_paths"), stats["shrank_paths"]), (6, 1, 1))
        self.assertTrue(any("dropped=['dropped.txt']" in h["evidence"] for h in hits), hits)


if __name__ == "__main__":
    unittest.main()
