import csv
import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import verify


class WholeItemTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.base = Path(self.tmp.name)
        self.original = self.base / "ref.dll"
        self.original.write_bytes(b"test reference")
        self.digest = verify.digest_file(self.original)
        self.delivery = self.base / "delivery"
        self.delivery.mkdir()
        self.source = self.delivery / "source.cs"
        self.source.write_text("class C {}", encoding="utf-8")
        self.archive = dict(sha256=self.digest, commit="test fixture", archive="Archive",
                            product="Plus", original_path="ref.dll",
                            files={"source.cs": verify.digest_file(self.source)})

    def evaluate(self, **kw):
        return verify.item(self.original, self.digest, self.delivery, **kw)

    def test_original_is_wrong_input(self):
        self.original.write_bytes(b"different version")
        result = self.evaluate()
        self.assertEqual(result["status"], "inconclusive")
        self.assertEqual(result["findings"][0]["code"], "original_identity_mismatch")

    def test_archive_needs_exact_set_and_identity(self):
        with patch.object(verify, "APPROVALS", [self.archive]):
            self.assertEqual(self.evaluate()["status"], "pass")
            self.assertEqual(self.evaluate(product="Properties")["status"], "inconclusive")
            extra = self.delivery / "unused.cs"
            extra.write_text("class Extra {}", encoding="utf-8")
            self.assertEqual(self.evaluate()["status"], "inconclusive")
            extra.unlink()
            self.source.write_text("class D {}", encoding="utf-8")
            self.assertEqual(self.evaluate()["status"], "inconclusive")
            self.source.unlink()
            self.assertEqual(self.evaluate()["status"], "fail")

    def test_self_attestation_and_original_copy(self):
        (self.delivery / "claims.json").write_text('{"status":"pass"}')
        (self.delivery / "result.dll").write_bytes(self.original.read_bytes())
        self.assertNotEqual(self.evaluate()["status"], "pass")

    def test_copied_approved_digest_under_another_name(self):
        with patch.object(verify, "APPROVALS", [self.archive]):
            self.source.rename(self.delivery / "other.cs")
            mismatches = self.evaluate()["checks"][0]["findings"]
            self.assertEqual({r["code"] for r in mismatches},
                             {"approved_asset_missing", "asset_not_in_baseline"})

    def test_missing_local_input_is_preserved(self):
        self.original.unlink()
        self.assertEqual(self.evaluate()["findings"][0]["code"], "original_unavailable")
        self.original.write_text("version https://git-lfs.github.com/spec/v1\n")
        self.digest = verify.digest_file(self.original)
        self.assertEqual(self.evaluate()["findings"][0]["code"], "original_is_lfs_pointer")

    def test_source_notes_match_external_identity(self):
        src = self.delivery / "fresh-cs"
        src.mkdir()
        self.source.rename(src / "C.cs")
        source_digest = verify.digest_file(src / "C.cs")
        (src / "C.md").write_text(f"Source: fresh-cs/C.cs\nSource SHA-256: {source_digest}", encoding="utf-8")
        md = self.delivery / "ref.dll.md"
        md.write_text(f"Product: Plus\nOriginal path: ref.dll\nOriginal SHA-256: {self.digest}\n"
                      "Assembly version: 1.2.3.4\nVerification profile: test\nScope: whole-pe-static\n"
                      "Evidence: fresh-source-build\nStatic gaps: none", encoding="utf-8")
        files = verify.tree_files(self.delivery)
        build = dict(assembly_version="1.2.3.4", profile="test", source_sha256={"C.cs": source_digest})
        def check():
            return verify.file_notes(files, self.digest, "Plus", "ref.dll", build)["status"]
        self.assertEqual(check(), "pass")
        good = md.read_text(encoding="utf-8")
        md.write_text(good + "\nProduct: Other", encoding="utf-8")
        self.assertEqual(check(), "inconclusive")
        md.write_text(good.replace("Product: Plus", "Product: WrongPlusSuffix"), encoding="utf-8")
        self.assertEqual(check(), "inconclusive")
        md.write_text(good.replace("path: ref.dll", "path: Other/ref.dll"), encoding="utf-8")
        self.assertEqual(check(), "inconclusive")
        md.write_text(good, encoding="utf-8")
        (src / "C.md").write_text("?", encoding="utf-8")
        self.assertEqual(check(), "inconclusive")

    def test_self_declared_report_only_is_a_gap(self):
        self.source.unlink()
        (self.delivery / "run.json").write_text(json.dumps({"original_sha256": self.digest, "status": "pass"}))
        self.assertEqual(self.evaluate()["status"], "fail")

    def test_single_file_phase_two_delivery_keeps_its_shape(self):
        self.source.rename(self.delivery / "implementation.txt")
        result = self.evaluate()
        self.assertEqual(result["status"], "inconclusive")
        self.assertIn("whole_item_proof_outstanding", [f["code"] for f in result["findings"]])
        self.assertEqual(result["checks"], [])

    def test_later_tool_problem_preserves_an_independent_failure(self):
        self.original.write_bytes(b"MZ" + bytes(64))
        self.digest = verify.digest_file(self.original)
        (self.delivery / "native-functions.csv").write_text("rva,name\n")
        (self.delivery / "resources.csv").write_text("test\n")
        with patch.object(verify.importlib, "import_module", side_effect=ImportError("test")):
            result = self.evaluate()
        self.assertEqual(result["status"], "fail")
        self.assertIn("check_unavailable", [f["code"] for c in result["checks"] for f in c["findings"]])

    def test_export_evidence_and_coverage_gap_in_same_item_report(self):
        self.original.write_bytes(b"MZ" + bytes(64))
        self.digest = verify.digest_file(self.original)
        (self.delivery / "s5").mkdir()
        (self.delivery / "s5/business-evidence.json").write_text("{}")
        (self.delivery / "coverage.csv").write_text("kind,key,state,first_bytes,listing,source,note\n"
                                                    "native,0x1200,gap,,,,missing body\n")
        rebuilt = verify.section("export rebuild", "pass", exports={"sample": {"status": "pass"}})
        import native_exports
        with patch.object(native_exports, "check", return_value=rebuilt) as build:
            result = self.evaluate()
        build.assert_called_once_with(self.original.read_bytes(), self.delivery, None)
        self.assertIn(rebuilt, result["checks"])
        coverage = next(c for c in result["checks"] if "declared_entry_gaps" in c["metrics"])
        self.assertEqual(coverage["metrics"]["declared_entry_gaps"], 1)
        self.assertIn("0x1200", [f.get("key") for f in coverage["findings"]])
        self.assertEqual(verify.EXIT[result["status"]], 1)

    def test_provider_flags_must_identify_an_independent_reference(self):
        args = [sys.executable, "-B", str(verify.HERE / "verify.py"), "item", "--original", str(self.original),
                "--delivery", str(self.delivery), "--sha256", self.digest]
        for flags in (["--provider", "dependency.dll"], ["--provider-sha256", self.digest],
                      ["--provider", "dependency.dll", "--provider-sha256", "invalid"]):
            with self.subTest(flags=flags):
                run = subprocess.run(args + flags, capture_output=True, check=False)
                self.assertEqual(run.returncode, 2)
                self.assertEqual(json.loads(run.stdout)["findings"][0]["code"], "invalid_verification_inputs")

    def test_duplicate_coverage_columns_cannot_hide_a_gap(self):
        import coverage_table
        p = self.delivery / "coverage.csv"
        p.write_text("kind,key,state,first_bytes,listing,source,note,state\nnative,0x1000,gap,,,,,covered\n")
        self.assertEqual(coverage_table.check(b"", {"coverage.csv": p})["status"], "fail")

    def test_wrong_evidence_line_and_source_comment(self):
        import coverage_table
        p = self.delivery / "coverage.csv"
        (self.delivery / "a.asm").write_text("; listing\n00001000  C3  RET\n")
        (self.delivery / "a.c").write_text("/* header */\nint f(void) {return 0;}\n")
        p.write_text("kind,key,state,first_bytes,listing,source,note\n"
                     "native,0x1000,covered,c3,a.asm#L1,a.c#L1,verified\n")
        result = coverage_table.check(b"", verify.tree_files(self.delivery))
        self.assertEqual(result["status"], "fail")
        self.assertEqual({f["column"] for f in result["findings"] if "column" in f}, {"listing","source"})

    def test_live_source_from_another_function_is_rejected(self):
        import coverage_table
        p = self.delivery / "coverage.csv"
        (self.delivery / "a.asm").write_text("; FUNC 00001000 f\n00001000  C3  RET\n")
        (self.delivery / "a.c").write_text("/* ---- FUNC 00001000 f */\nvoid f(){}\n"
                                           "/* ---- FUNC 00001020 g */\nvoid g(){}\n")
        p.write_text("kind,key,state,first_bytes,listing,source,note\n"
                     "native,0x1000,covered,c3,a.asm#L2,a.c#L4,verified\n")
        result = coverage_table.check(b"", verify.tree_files(self.delivery))
        self.assertEqual(result["status"], "fail")
        self.assertTrue(any("does not belong" in f.get("message", "") for f in result["findings"]))

    def test_batch_rechecks_every_identity_even_if_digests_repeat(self):
        ledger = self.base / "inventory.csv"
        with ledger.open("w", encoding="utf-8", newline="") as f:
            w = csv.writer(f)
            w.writerow(["产品", "原路径", "原件SHA256", "状态"])
            for name in ("ref.dll", "alias.dll"):
                w.writerow(["Plus", name, self.digest, "静态验收通过"])
        bound = dict(product="Plus", path="ref.dll", sha256=self.digest,
                     original=str(self.original), delivery=str(self.delivery))
        inputs = self.base / "bindings.json"
        inputs.write_text(json.dumps([bound]), encoding="utf-8")
        digest = verify.digest_file(ledger)
        with patch.object(verify, "APPROVALS", [self.archive]):
            result = verify.project(ledger, digest, inputs, None)
            self.assertEqual(result["status"], "inconclusive")
            self.assertEqual(result["counts"], {"pass": 1, "fail": 0, "inconclusive": 1})
            self.assertEqual(result["distinct_originals"], 1)
        with self.assertRaisesRegex(ValueError, "SHA-256"):
            verify.project(ledger, "0"*64, inputs, None)
        inputs.write_text(json.dumps([bound, bound]), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "duplicate"):
            verify.project(ledger, digest, inputs, None)
        ledger.write_text("产品,原路径,原件SHA256\n", encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "empty inventory"):
            verify.project(ledger, verify.digest_file(ledger), inputs, None)

    def test_project_resolves_provider_from_input_file(self):
        ledger = self.base / "inventory.csv"
        ledger.write_text(f"产品,原路径,原件SHA256\nPlus,ref.dll,{self.digest}\n", encoding="utf-8")
        inputs = self.base / "bindings.json"
        binding = dict(product="Plus", path="ref.dll", sha256=self.digest,
                       original="ref.dll", delivery="delivery", provider="dep.dll")
        inputs.write_text(json.dumps([binding]))
        with self.assertRaisesRegex(ValueError, "both provider"):
            verify.project(ledger, verify.digest_file(ledger), inputs, None)
        binding["provider_sha256"] = self.digest
        inputs.write_text(json.dumps([binding]))
        with patch.object(verify, "item", return_value={"status": "fail"}) as run:
            result = verify.project(ledger, verify.digest_file(ledger), inputs, None)
        self.assertEqual(run.call_args.args[-1], (self.base.resolve() / "dep.dll", self.digest))
        self.assertEqual(result["counts"]["fail"], 1)

    def test_source_list_catches_missing_contents_and_mismatched_lists(self):
        scopes = self.base / "scopes"
        scopes.mkdir()
        digests = {}
        for name in ("plus", "properties", "shared"):
            p = scopes / (name + "-scope.csv")
            p.write_text("relative_path,sha256\nref.dll," + self.digest + "\n", encoding="utf-8")
            digests[name] = verify.digest_file(p)
        with patch.object(verify, "SOURCE_LISTS", digests):
            expected = {}
            report, origins = verify.complete_denominator(scopes, expected)
            self.assertEqual(report["absent_from_project_inventory"], [self.digest])
            self.assertEqual(origins[self.digest]["shared"], [2])
            self.assertEqual(len(expected), 1)
            (scopes / "plus-scope.csv").write_text("truncated", encoding="utf-8")
            with self.assertRaisesRegex(ValueError, "wrong original source list"):
                verify.complete_denominator(scopes, {})


if __name__ == "__main__":
    unittest.main()
