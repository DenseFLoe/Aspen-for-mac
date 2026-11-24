
# -*- coding: utf-8 -*-
"""Red tests for receipt declaration parsing (fingerprint-pathset)."""
import hashlib
import os
import sys
import tempfile
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.dirname(HERE))
sys.path.insert(0, os.path.join(os.path.dirname(HERE), ".local", "pylibs"))
sys.path.insert(0, "D:/Lib/site-packages")

import det_fingerprint_pathset as F  # noqa: E402

BT = chr(96)


def sha(data):
    return hashlib.sha256(data).hexdigest()


class ReceiptParsing(unittest.TestCase):
    def setUp(self):
        self.dir = tempfile.mkdtemp()
        self.addCleanup(lambda: __import__("shutil").rmtree(self.dir, ignore_errors=True))
        self.good = b"# generator\nprint('x')\n"
        self.good_path = "code/gen.py"
        os.makedirs(os.path.join(self.dir, "code"), exist_ok=True)
        open(os.path.join(self.dir, self.good_path), "wb").write(self.good)
        os.makedirs(os.path.join(self.dir, "code"), exist_ok=True)
        open(os.path.join(self.dir, "code", "x.py"), "wb").write(b"real bytes\n")
        self.receipt = open(os.path.join(self.dir, "s2-submission.md"), "w", encoding="utf-8")

    def write(self, body):
        self.receipt.write(body)
        self.receipt.close()

    def run_detect(self):
        return F.detect("NATIVE-337", self.dir, "unused.dll", {})

    def row(self, key, size, digest, note="x"):
        return "| " + BT + key + BT + " | " + str(size) + " | " + BT + digest + BT + " | " + note + " |\n"

    def test_size_column_is_not_a_digest(self):
        self.write("| path | bytes | SHA-256 | why |\n| --- | ---: | --- | --- |\n"
                   + self.row(self.good_path, 3208, sha(self.good), "generator")
                   + self.row("code/x.py", 16955, "0" * 64, "wrong on purpose"))
        hits, stats = self.run_detect()
        short = [h for h in hits if "chars; expected 64" in h["evidence"]]
        self.assertEqual(short, [], "size column parsed as a digest: %r" % short)
        self.assertEqual(stats["verified_paths"], 1, stats)
        self.assertEqual(stats["declared_paths"], 2, stats)
        mism = [h for h in hits if "declared" in h["evidence"] and "disk" in h["evidence"]]
        self.assertEqual(len(mism), 1, hits)

    def test_readback_lines_are_not_declarations(self):
        self.write("readback: path=calls.csv algo=sha256 value=e473712f657c9b1a\n"
                   "readback: path=coverage.csv algo=sha256 value=3afe1c2a87c9e70c\n"
                   "readback: path=metrics.json algo=sha256 value=72515d6a0d747a62\n"
                   + self.row(self.good_path, 3208, sha(self.good), "ok"))
        hits, stats = self.run_detect()
        self.assertEqual([h for h in hits if h["severity"] == "defect"], [], hits)
        self.assertEqual(stats["declared_paths"], 1, stats)
        self.assertEqual(stats["verified_paths"], 1, stats)

    def test_code_fences_are_not_declarations(self):
        self.write(self.row(self.good_path, 3208, sha(self.good), "ok")
                   + BT * 3 + "python\n"
                   "for name in ('code/gen.py', 'code/x.py'):\n"
                   "    print(name, hashlib.sha256(open(name,'rb').read()).hexdigest())\n"
                   + self.row("code/x.py", 16955, "deadbee", "fake row inside code")
                   + BT * 3 + "\n")
        hits, stats = self.run_detect()
        self.assertEqual([h for h in hits if h["severity"] == "defect"], [], hits)
        self.assertEqual(stats["declared_paths"], 1, stats)

    def test_repo_relative_is_advisory(self):
        self.write(self.row("qa/mk_fingerprints.py", 3208, sha(self.good), "repo toolkit"))
        hits, stats = self.run_detect()
        self.assertEqual([h for h in hits if h["severity"] == "defect"], [], hits)
        adv = [h for h in hits if "repository-relative" in h["evidence"]]
        self.assertEqual(len(adv), 1, hits)

    def test_short_digest_reports_full_context(self):
        self.write(self.row("code/x.py", 17, "deadbee", "truncated"))
        hits, stats = self.run_detect()
        short = [h for h in hits if "chars; expected 64" in h["evidence"]]
        self.assertEqual(len(short), 1, hits)
        ev = short[0]["evidence"]
        self.assertIn("deadbee", ev)
        self.assertIn("code/x.py", ev + short[0]["locator"])
        self.assertGreaterEqual(len(ev), 60, "evidence must quote line context: %r" % ev)


if __name__ == "__main__":
    unittest.main()
