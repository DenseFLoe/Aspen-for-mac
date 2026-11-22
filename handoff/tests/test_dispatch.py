import csv
import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from dispatch import EVENT_FIELDS, TASK_FIELDS, project


def task(key, owner="tietoumiao"):
    return dict(zip(TASK_FIELDS, [key, owner, "input", "output", "standard", "criteria", "example --check", "ACK+24h"]))


def event(key, seq, state):
    return dict(zip(EVENT_FIELDS, [key, str(seq), state, "2026-11-22T00:00:00Z", "upstream",
                                   "handoff/assignments/tasks.csv", "a" * 64]))


def table(path, fields, rows):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        writer.writerows(rows)


class DispatchTest(unittest.TestCase):
    def setUp(self):
        temp = tempfile.TemporaryDirectory()
        self.addCleanup(temp.cleanup)
        self.root = Path(temp.name)
        self.base = self.root / "handoff"

    def load(self, tasks, events):
        table(self.base / "assignments/tasks.csv", TASK_FIELDS, tasks)
        table(self.base / "ledger/events.csv", EVENT_FIELDS, events)

    def test_views_show_work_for_owner_and_reviews_on_both_sides(self):
        a, b, c = task("A"), task("B"), task("C", "upstream")
        self.load([a, b, c], [event("A", 1, "assigned"), event("B", 1, "assigned"),
                              event("B", 2, "started"), event("B", 3, "submitted"),
                              event("C", 1, "assigned"), event("C", 2, "started")])
        executor = project(self.root, "tietoumiao")
        self.assertTrue(executor["ok"])
        self.assertEqual([r["task_id"] for r in executor["ready"]], ["A"])
        self.assertEqual([r["task_id"] for r in executor["review"]], ["B"])
        reviewer = project(self.root, "upstream")
        self.assertEqual([r["task_id"] for r in reviewer["working"]], ["C"])
        self.assertEqual([r["task_id"] for r in reviewer["review"]], ["B"])
        self.assertEqual(reviewer["ready"], [])

    def test_receipts_and_retries_do_not_change_states(self):
        receipt_dir = self.base / "inbox/A"
        receipt_dir.mkdir(parents=True)
        receipt_dir.joinpath("s1-started.md").write_text("ack", encoding="utf-8")
        assigned = event("A", 1, "assigned")
        self.load([task("A")], [assigned, assigned])
        self.assertEqual(project(self.root)["working"][0]["state"], "assigned")
        self.assertEqual(project(self.root, "upstream")["working"][0]["action"], "upstream_record_start")
        receipt_dir.joinpath("s1-submission.md").write_text("evidence", encoding="utf-8")
        self.assertEqual(project(self.root, "upstream")["waiting"][0]["action"], "upstream_record_submission")
        for returned in ("returned", "blocked"):
            with self.subTest(returned=returned):
                events = [assigned, event("A", 2, "started"), event("A", 3, "submitted"), event("A", 4, returned)]
                self.load([task("A")], events)
                self.assertEqual(project(self.root)["waiting"][0]["state"], returned)
                self.load([task("A")], events + [event("A", 5, "assigned")])
                ready, = project(self.root)["ready"]
                self.assertEqual((ready["assigned_seq"], ready["hints"]), (5, []))

    def test_invalid_records_quarantine_affected_tasks(self):
        assigned = event("A", 1, "assigned")
        cases = [
            ([task("A"), task("A")], [assigned]),
            ([{**task("A"), "check_command": ""}], [assigned]),
            ([task("A")], []),
            ([task("A")], [assigned, event("A", 3, "started")]),
            ([task("A")], [assigned, event("A", 2, "accepted")]),
            ([task("A")], [assigned, {**assigned, "sha256": "b" * 64}]),
            ([task("A")], [{**assigned, "evidence": "handoff/../outside.md"}]),
        ]
        for tasks, events in cases:
            with self.subTest(tasks=tasks, events=events):
                self.load(tasks + [task("B")], events + [event("B", 1, "assigned")])
                result = project(self.root)
                self.assertFalse(result["ok"])
                self.assertEqual([r["task_id"] for r in result["ready"]], ["B"])
                self.assertEqual(result["waiting"][0]["action"], "repair_records")

    def test_historical_assignment_hash_survives_append_and_capacity_limit(self):
        self.load([task("A"), task("B")], [event("A", 1, "assigned"), event("B", 1, "assigned")])
        result = project(self.root, limit=1)
        self.assertTrue(result["ok"])
        self.assertEqual([r["task_id"] for r in result["ready"]], ["A"])
        self.assertEqual(result["ready"][0]["evidence_sha256"], "a" * 64)
        self.assertEqual(project(self.root, limit=0)["ready"], [])

    def test_cli_check_only_and_malformed_csv(self):
        cli = [sys.executable, "-B", str(Path(__file__).resolve().parents[1] / "dispatch.py"),
               "--root", str(self.root), "--check-only", "--json"]
        self.load([task("A")], [event("A", i, s) for i, s in enumerate(
            ["assigned", "started", "submitted", "accepted"], 1)])
        self.assertEqual(project(self.root)["terminal"][0]["state"], "accepted")
        valid = subprocess.run(cli, capture_output=True, check=True)
        self.assertTrue(json.loads(valid.stdout)["ok"])
        (self.base / "ledger/events.csv").write_text("invalid,header\n", encoding="utf-8")
        invalid = subprocess.run(cli, capture_output=True)
        self.assertEqual(invalid.returncode, 2)
        self.assertFalse(json.loads(invalid.stdout)["ok"])


if __name__ == "__main__":
    unittest.main()
