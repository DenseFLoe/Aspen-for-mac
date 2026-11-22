import csv
import hashlib
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest

if __package__:
    from .native_sites import check
    from .native_targets import SCHEMA
    from .test_native_sites import tiny_pe
    from .test_target_witness import SLOT, fixture, rip
    from .verify import item
else:
    from native_sites import check
    from native_targets import SCHEMA
    from test_native_sites import tiny_pe
    from test_target_witness import SLOT, fixture, rip
    from verify import item


@unittest.skipUnless(importlib.util.find_spec("iced_x86") and importlib.util.find_spec("pefile"),
                     "requires iced-x86 and pefile")
class SubmittedTargetsTest(unittest.TestCase):
    def setUp(self):
        temp = tempfile.TemporaryDirectory()
        self.addCleanup(temp.cleanup)
        self.root = Path(temp.name) / "delivery"
        (self.root / "code").mkdir(parents=True)
        self.original, call = tiny_pe(tail=b"\xff\xd0\xff\x50\x18\xc3")
        self.digest = hashlib.sha256(self.original).hexdigest()
        self.pe_path = self.root.parent / "test.dll"
        self.pe_path.write_bytes(self.original)
        (self.root / "code/native.asm").write_text(
            f"00001000  {call.hex(' ')}  call qword ptr [slot]\n"
            "00001006  ff d0  call rax\n00001008  ff 50 18  call [rax+18h]\n0000100b  c3  ret\n",
            encoding="utf-8")
        self.header = ["kind", "caller", "callee", "class", "listing", "note"]
        self.main = [["native", "0x1000", callee, cls, f"code/native.asm#L{line}", ""]
                     for line, callee, cls in [(1, "x.dll!#5", "external"), (2, "indirect@0x1006", "unresolved"),
                                               (3, "indirect@0x1008", "unresolved")]]
        self.table("calls.csv", self.header, self.main)
        self.table("code/indirect.csv", self.header, self.main[1:])
        self.legacy = [[*self.main[1], "", "unresolved"], [*self.main[2], "base rax MOV RAX", "unresolved"]]
        self.set_legacy(self.legacy)
        self.positive = {"site": "0x1000", "owner": "0x1000", "target": None,
                         "external": {"iat_rva": "0x2050", "import": "X.dll!#5"},
                         "witness": {"kind": "iat", "slot_rva": "0x2050"}}

    def table(self, path, header, rows):
        with (self.root / path).open("w", newline="", encoding="utf-8") as f:
            csv.writer(f).writerows([header, *rows])

    def set_legacy(self, rows):
        self.table("code/indirect-resolved.csv", [*self.header, "resolved", "verdict"], rows)

    def claims(self, *claims, digest=None):
        data = {"schema": SCHEMA, "original_sha256": digest or self.digest, "claims": claims}
        (self.root / "target-evidence.json").write_text(json.dumps(data), encoding="utf-8")

    def audit(self):
        return check(self.original, self.root)

    def rows(self, result):
        return {r["site_rva"]: r for r in result["indirect_call_targets"]["sites"]}

    def test_old_hints_and_blank_rows_are_both_addressed(self):
        result = self.audit()
        rows = self.rows(result)
        self.assertEqual(list(rows), ["0x1006", "0x1008"])
        self.assertEqual(rows["0x1006"]["operand"], {"kind": "register", "register": "rax"})
        memory = rows["0x1008"]
        self.assertEqual(memory["operand"]["displacement"], 24)
        self.assertEqual(memory["original_bytes"], "ff 50 18")
        hint, = memory["evidence"]["code/indirect-resolved.csv"]
        self.assertTrue(hint["base_matches_operand"])
        self.assertEqual(hint["definition_status"], "no_instruction_address_supplied")
        self.assertEqual(result["indirect_call_targets"]["counts"], {"confirmed": 0, "unresolved": 2, "contradicted": 0})

    def test_correct_and_wrong_ordinal_through_item(self):
        for claimed, decision, code in [("#5", "confirmed", "witness_verified"), ("#6", "contradicted", "witness_import")]:
            with self.subTest(claimed=claimed):
                self.claims({**self.positive, "external": {"iat_rva": "0x2050", "import": "x.dll!" + claimed}})
                result = item(self.pe_path, self.digest, self.root)
                native = next(c for c in result["checks"] if "indirect_call_targets" in c)
                row = self.rows(native)["0x1000"]
                self.assertEqual((row["decision"], row["witness_result"]["code"]), (decision, code))
                self.assertEqual(row["witness_result"]["original"]["external"]["import"], "X.dll!#5")
                self.assertEqual(row["confirmed_target"] is not None, decision == "confirmed")
                self.assertEqual(native["indirect_call_targets"]["counts"]["unresolved"], 2)
                self.assertNotEqual(result["status"], "pass")

    def test_old_explicit_import_gets_its_slot_from_cited_original_operand(self):
        self.set_legacy([*self.legacy, [*self.main[0], "X.dll!#5", "resolved"]])
        verified = self.rows(self.audit())["0x1000"]
        self.assertEqual(verified["confirmed_target"]["external"], {"iat_rva": "0x2050", "import": "X.dll!#5"})

    def test_real_import_at_an_unrelated_memory_call(self):
        claim = {**self.positive, "site": "0x1008"}
        self.claims(claim)
        row = self.rows(self.audit())["0x1008"]
        self.assertEqual(row["decision"], "contradicted")
        self.assertIn("witness_operand", row["reasons"])
        self.assertEqual((row["operand"]["base"], row["operand"]["displacement"]), ("rax", 24))
        del claim["witness"]
        self.claims(claim)
        row = self.rows(self.audit())["0x1008"]
        self.assertEqual((row["decision"], row["confirmed_target"]), ("unresolved", None))

    def test_duplicate_records_and_wrong_hash_cannot_confirm(self):
        self.claims(self.positive, self.positive)
        row = self.rows(self.audit())["0x1000"]
        self.assertEqual((row["decision"], row["confirmed_target"]), ("contradicted", None))
        self.assertIn("indirect_target_duplicate", row["reasons"])
        self.claims(self.positive, digest="0" * 64)
        result = self.audit()
        self.assertEqual(result["indirect_call_targets"]["counts"]["confirmed"], 0)
        self.assertIn("indirect_target_original_mismatch", [f["code"] for f in result["findings"]])

    def test_wrong_base_site_and_owner_are_independent_conflicts(self):
        for column, value, expected in [(6, "base rbx MOV RBX", "indirect_target_base_mismatch"),
                                        (4, "code/native.asm#L2", "indirect_target_evidence_reference"),
                                        (1, "0x1006", "indirect_target_owner_mismatch")]:
            with self.subTest(column=column):
                rows = [list(v) for v in self.legacy]
                rows[1][column] = value
                self.set_legacy(rows)
                out = self.rows(self.audit())
                self.assertIn(expected, out["0x1008"]["reasons"])
                self.assertIsNone(out["0x1008"]["confirmed_target"])
                self.assertEqual(out["0x1006"]["decision"], "unresolved")
        self.set_legacy(self.legacy)
        main = [list(v) for v in self.main]
        main[2][2] = "indirect@0x1006"
        self.table("calls.csv", self.header, main)
        self.assertIn("indirect_target_site_mismatch", self.rows(self.audit())["0x1008"]["reasons"])

    def test_absent_index_record_and_absent_main_record_stay_visible(self):
        self.set_legacy(self.legacy[:1])
        row = self.rows(self.audit())["0x1008"]
        self.assertEqual(row["missing_legacy_records"], ["code/indirect-resolved.csv"])
        self.table("calls.csv", self.header, self.main[:2])
        result = self.audit()
        self.assertEqual(set(self.rows(result)), {"0x1006", "0x1008"})
        self.assertIn("indirect_target_primary_registration", self.rows(result)["0x1008"]["reasons"])
        self.assertEqual(result["metrics"]["missing_sites"], 1)

    def test_unsupported_claim_preserves_other_evidence(self):
        unknown = {**self.positive, "site": "0x1006", "witness": {"kind": "observed_once"}}
        self.claims(unknown, self.positive)
        rows = self.rows(self.audit())
        self.assertEqual((rows["0x1006"]["decision"], rows["0x1006"]["confirmed_target"]), ("unresolved", None))
        self.assertEqual(rows["0x1000"]["decision"], "confirmed")
        self.claims({**unknown, "external": []}, self.positive)
        rows = self.rows(self.audit())
        self.assertEqual(rows["0x1006"]["decision"], "contradicted")
        self.assertEqual(rows["0x1000"]["decision"], "confirmed")

    def test_missing_main_file_still_audits_sidecar_through_item(self):
        self.claims(self.positive)
        (self.root / "calls.csv").unlink()
        result = item(self.pe_path, self.digest, self.root)
        native = next(c for c in result["checks"] if "indirect_call_targets" in c)
        self.assertEqual(native["status"], "fail")
        self.assertEqual(self.rows(native)["0x1000"]["decision"], "contradicted")

    def check_body(self, body, listing, site, claim):
        self.original = fixture(body, guard=claim["witness"]["kind"] == "guard_dispatch")
        self.digest = hashlib.sha256(self.original).hexdigest()
        (self.root / "code/native.asm").write_text("\n".join(listing), encoding="utf-8")
        row = ["native", "0x1000", "indirect@" + site, "unresolved", f"code/native.asm#L{len(listing)-1}", ""]
        self.table("calls.csv", self.header, [row])
        self.table("code/indirect.csv", self.header, [row])
        self.set_legacy([[*row, "", "unresolved"]])
        self.claims({"site": site, "owner": "0x1000", "external": None, **claim})
        return self.rows(self.audit())[site]

    def test_skipped_guard_load_cannot_certify_dispatch(self):
        load = rip(b"\x4c\x8b\x0d", 0x1002, SLOT)
        body = b"\xeb\x07" + load + b"\x41\xff\xd1\xc3"
        listing = ["00001000  eb 07  jmp 0x1009", f"00001002  {load.hex(' ')}  mov r9, [rip]",
                   "00001009  41 ff d1  call r9", "0000100c  c3  ret"]
        row = self.check_body(body, listing, "0x1009", {"target": None, "witness": {"kind": "guard_dispatch",
                              "register": "r9", "definition_rva": "0x1002", "slot_rva": hex(SLOT)}})
        self.assertTrue(row["original_boundary_confirmed"])
        self.assertEqual(row["decision"], "unresolved")
        self.assertIn("original_definition_boundary_unverified", row["reasons"])

    def test_known_internal_target_preserves_owner_entry_scope(self):
        definition = rip(b"\x48\x8d\x05", 0x1000, SLOT - 24)
        body = definition + b"\xff\x50\x18\xc3"
        listing = [f"00001000  {definition.hex(' ')}  lea rax, [rip]", "00001007  ff 50 18  call [rax+18h]",
                   "0000100a  c3  ret"]
        for declared, decision in [("0x1040", "confirmed"), ("0x1041", "contradicted")]:
            with self.subTest(declared=declared):
                row = self.check_body(body, listing, "0x1007", {"target": declared, "witness": {"kind": "readonly_table",
                                      "register": "rax", "definition_rva": "0x1000", "slot_rva": hex(SLOT)}})
                self.assertEqual(row["decision"], decision)
                self.assertEqual(row["witness_result"]["original"]["target"], "0x1040")
                if decision == "confirmed":
                    self.assertEqual(row["confirmed_target"], {"target": "0x1040", "external": None,
                                     "binding_scope": "from_owner_entry", "whole_program_unique": False})
                else:
                    self.assertIn("witness_target", row["reasons"])
