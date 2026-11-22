import sys
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import watch


class WatchTest(unittest.TestCase):
    def test_either_channel_wakes_reader_and_replay_has_same_cursor(self):
        head = [{"name": "ledger", "sha": "a" * 40}]
        issue = {"comments": 1, "updated_at": "2026-11-22T00:00:00Z"}
        def read(endpoint, cached=None):
            return "tag", head if endpoint.startswith("contents/") else dict(issue)
        with patch.object(watch, "request", side_effect=read):
            cache = {}
            initial = watch.observe(cache)[0]
            self.assertEqual(initial, watch.observe(cache)[0])
            issue["comments"] += 1
            next_event = watch.observe(cache)[0]
            self.assertNotEqual(initial, next_event)
            head[0]["sha"] = "b" * 40
            self.assertNotEqual(next_event, watch.observe(cache)[0])

    def test_incomplete_snapshot_and_mismatched_git_object_are_rejected(self):
        entries = {"tree": [{"path": "tasks.csv", "mode": "100644", "sha": "0" * 40}]}
        with patch.object(watch, "request", side_effect=[(None, entries), (None, {"content": "YQ=="})]):
            with self.assertRaisesRegex(ValueError, "fingerprint"):
                watch.read_file("any", "tasks.csv")
        with patch.object(watch, "request", return_value=(None, {"truncated": True})), patch.object(watch, "read_file", return_value=b""):
            with self.assertRaisesRegex(ValueError, "Incomplete inbox"):
                watch.queue_snapshot({"assignments":"a", "ledger":"b", "inbox":"c"}, "upstream")
