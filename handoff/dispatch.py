"""Project a handoff snapshot into work queues. No commands or state changes."""
import argparse
import csv
import json
import re
import sys
from datetime import datetime, timedelta
from pathlib import Path, PurePosixPath


TASK_FIELDS = "task_id owner input deliverable standard criterion check_command due_utc".split()
EVENT_FIELDS = "task_id seq state at_utc actor evidence sha256".split()
NEXT = {
    "": {"assigned"},
    "assigned": {"started"},
    "started": {"submitted"},
    "submitted": {"accepted", "returned", "blocked"},
    "returned": {"assigned"},
    "blocked": {"assigned"},
    "accepted": set(),
}
QUEUES = ("ready", "working", "review", "waiting", "terminal")


def read_table(path, required):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        reader = csv.DictReader(stream, strict=True)
        header = reader.fieldnames or []
        missing = set(required) - set(header)
        if missing or len(header) != len(set(header)):
            raise ValueError(f"{path.name}: invalid header; required fields: {', '.join(required)}")
        rows = []
        for row in reader:
            if None in row or None in row.values():
                raise ValueError(f"{path.name}:{reader.line_num}: malformed CSV row")
            rows.append({key: row[key].strip() for key in required})
    return rows


def validate_event(event, previous):
    state = event["state"]
    if state not in NEXT[previous]:
        raise ValueError(f"invalid transition {previous or '(new)'} -> {state}")
    if not re.fullmatch(r"[0-9a-fA-F]{64}", event["sha256"]):
        raise ValueError("invalid evidence SHA-256")
    evidence = PurePosixPath(event["evidence"])
    if (len(evidence.parts) < 2 or evidence.parts[0] != "handoff"
            or ".." in evidence.parts or "\\" in event["evidence"]):
        raise ValueError("evidence must be a path inside handoff/")
    try:
        timestamp = datetime.fromisoformat(event["at_utc"])
        if timestamp.utcoffset() != timedelta(0):
            raise ValueError
    except ValueError:
        raise ValueError(f"invalid UTC timestamp {event['at_utc']}") from None
    if not event["actor"]:
        raise ValueError("missing actor")


def project(root, owner=None, limit=None):
    report = {"ok": True, "issues": [], **{q: [] for q in QUEUES}}
    handoff = root / "handoff"
    try:
        assignments = read_table(handoff / "assignments/tasks.csv", TASK_FIELDS)
        events = read_table(handoff / "ledger/events.csv", EVENT_FIELDS)
    except (OSError, UnicodeError, csv.Error, ValueError) as exc:
        report.update(ok=False, issues=[str(exc)])
        return report

    bad = set()

    def problem(task_id, reason):
        bad.add(task_id)
        report["ok"] = False
        report["issues"].append(f"{task_id or '(no task_id)'}: {reason}")

    tasks = {}
    for task in assignments:
        key = task["task_id"]
        if key in tasks:
            problem(key, "duplicate assignment")
            continue
        tasks[key] = task
        if not re.fullmatch(r"[A-Za-z0-9_-]+", key):
            problem(key, "invalid task_id")
        missing = [field for field in TASK_FIELDS if not task[field]]
        if missing:
            problem(key, "missing " + ", ".join(missing))

    history = {key: {} for key in tasks}
    attempts = {}
    for event in events:
        key = event["task_id"]
        if key in bad:
            continue
        if key not in tasks:
            problem(key, "event has no assignment")
            continue
        entries = history[key]
        try:
            if not re.fullmatch(r"[1-9][0-9]*", event["seq"]):
                raise ValueError("invalid seq")
            seq = int(event["seq"])
            if seq in entries:
                if entries[seq] == event:  # the same event can be delivered twice
                    continue
                raise ValueError(f"conflicting events at seq {seq}")
            if seq != len(entries) + 1:
                raise ValueError(f"expected seq {len(entries) + 1}, got {seq}")
            previous = entries[seq - 1]["state"] if entries else ""
            validate_event(event, previous)
            entries[seq] = event
            if event["state"] == "assigned":
                attempts[key] = seq
        except ValueError as exc:
            problem(key, str(exc))

    for key, task in tasks.items():
        entries = history[key]
        last = entries.get(len(entries), {})
        state = last.get("state", "")
        if not entries and key not in bad:
            problem(key, "missing assigned event")
        item = {
            **task, "state": state or None, "seq": len(entries), "assigned_seq": attempts.get(key),
            "evidence": last.get("evidence"), "evidence_sha256": last.get("sha256"),
            "hints": [], "upstream_action": None,
        }
        if key in bad:
            bucket, action = "waiting", "repair_records"
        elif state == "submitted":
            bucket, action = "review", "upstream_review"
            item["upstream_action"] = action
        elif state == "accepted":
            bucket, action = "terminal", "complete"
        elif state in {"returned", "blocked"}:
            bucket, action = "waiting", "await_reassignment"
        else:
            # Hints belong to this attempt. A re-assignment changes its seq, so
            # retained receipts from earlier attempts cannot claim work twice.
            for kind in ("started", "submission"):
                receipt = handoff / "inbox" / key / f"s{attempts[key]}-{kind}.md"
                if receipt.is_file():
                    item["hints"].append(kind)
            if "submission" in item["hints"]:
                bucket, action = "waiting", "upstream_record_submission"
                item["upstream_action"] = action
            elif "started" in item["hints"] or state == "started":
                bucket, action = "working", "continue"
                if state == "assigned":
                    item["upstream_action"] = "upstream_record_start"
            else:
                bucket, action = "ready", "start"
        if owner and owner != task["owner"]:
            if owner != "upstream" or not item["upstream_action"]:
                continue
            action = item["upstream_action"]
        item["action"] = action
        if bucket != "ready" or limit is None or len(report["ready"]) < limit:
            report[bucket].append(item)
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[1],
                        help="repository root containing handoff/")
    parser.add_argument("--owner", help="show this owner's tasks; upstream also sees receipts and pending reviews")
    parser.add_argument("--limit", type=int, help="show at most N ready tasks in assignment-file order")
    parser.add_argument("--json", action="store_true", help="print queues and work instructions as JSON")
    parser.add_argument("--check-only", action="store_true", help="validate the snapshot without listing tasks")
    args = parser.parse_args()
    if args.limit is not None and args.limit < 0:
        parser.error("--limit must be >= 0")
    report = project(args.root, args.owner, args.limit)
    if args.json:
        result = {k: report[k] for k in ("ok", "issues")} if args.check_only else report
        print(json.dumps(result, ensure_ascii=False, indent=2))
    else:
        for issue in report["issues"]:
            print(issue, file=sys.stderr)
        if args.check_only:
            print("valid" if report["ok"] else "invalid")
        else:
            for bucket in QUEUES:
                print(f"{bucket} ({len(report[bucket])})")
                for item in report[bucket]:
                    print(f"  {item['task_id']}  {item['owner']}  {item['action']}  {item['deliverable']}")
    return 0 if report["ok"] else 2


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    sys.stderr.reconfigure(encoding="utf-8")
    sys.exit(main())
