"""Compare the four revised pre-review reports with the fingerprinted #368 inputs."""
import argparse
import hashlib
import importlib.util
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path


ASSIGNMENTS = Path(__file__).resolve().parent
REFERENCE_SHA = "ff2fbcd5873e5d86d4912417dccdc39eb6d638fef701a80dd8c047f00e9a58b1"
REPORTS = ("README.md", "stats.md", "failures.md", "validation.md")


def read_baseline(folder):
    path = ASSIGNMENTS / "check-t9-368.py"
    if hashlib.sha256(path.read_bytes()).hexdigest() != REFERENCE_SHA:
        raise ValueError("fixed upstream checker SHA-256 differs")
    spec = importlib.util.spec_from_file_location("t9_baseline", path)
    baseline = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(baseline)
    fixed = baseline.inputs(folder)
    result = baseline.reconcile(fixed)
    return result, baseline.index_csv(fixed["ledger-1000.csv"])


def cells(line):
    return [x.strip() for x in line.strip().strip("|").split("|")]


def tables(lines):
    """Yield header and rows; Markdown alignment and column order can vary."""
    i = 0
    while i + 1 < len(lines):
        if "|" in lines[i] and re.fullmatch(r"[ |:\-\t]+", lines[i + 1]) and "-" in lines[i + 1]:
            header = cells(lines[i])
            body = []
            i += 2
            while i < len(lines) and lines[i].startswith("|"):
                body.append(cells(lines[i]))
                i += 1
            yield header, body
        else:
            i += 1


def check(folder, inputs):
    baseline, rows = read_baseline(inputs)
    docs = {p: (folder / p).read_text(encoding="utf-8-sig").replace("*", "").replace("`", "").splitlines()
            for p in REPORTS}
    errors, manual = [], []
    verdicts = baseline["verdicts"]
    codes = defaultdict(set)
    for idx, row in rows.items():
        for code in filter(None, row["fail_codes"].split(";")):
            codes[code].add(idx)
    nag = codes["tool_nag_tail"]
    old = Counter(rows[i]["tier_b"].split(":")[0].lower() for i in nag)
    if (old["pass"], old["partial"], len(nag)) != (448, 7, 455):
        raise ValueError("pinned input distribution differs")

    # Locate a complete current summary anywhere in each document, leaving a prose-only layout to review.
    verdict_pattern = r"\b(pass|fail|partial|blocked)\s*[:=：]?\s*(\d+)\b"
    for name, lines in docs.items():
        summaries = [dict((k.lower(), int(v)) for k,v in re.findall(verdict_pattern, line, re.I)) for line in lines]
        complete = [s for s in summaries if set(s) == set(verdicts)]
        if verdicts not in complete:
            (errors if complete else manual).append(name + " current verdict summary")
        for line, summary in zip(lines, summaries):
            if set(summary) == set(verdicts) and summary != verdicts and not re.search(
                    r"旧|历史|原报|作废|prior|historical|superseded", line, re.I):
                errors.append(name + " contradictory verdict summary")

    stats = list(tables(docs["stats.md"]))
    for key, matrix in [("product", baseline["by_product"]), ("state", baseline["by_archive_state"])]:
        seen = set()
        for header, data in stats:
            head = [h.lower() for h in header]
            if not set(verdicts) <= set(head):
                continue
            for row in data:
                names = [s for s in row if s in matrix]
                if not names:
                    continue
                name = names[0]
                values = {s: row[head.index(s)] for s in verdicts}
                if name in seen or values != {s: str(n) for s,n in matrix[name].items()}:
                    errors.append("stats.md " + key + " " + name)
                seen.add(name)
        if seen != set(matrix):
            manual.append("stats.md missing " + key + " rows: " + str(sorted(set(matrix)-seen)))

    for name in ("stats.md", "failures.md"):
        found = {}
        for header, data in tables(docs[name]):
            if "fail_code" not in header:
                continue
            for row in data:
                code = row[header.index("fail_code")]
                if code in codes:
                    numbers = [int(s) for s in row if s.isdigit()]
                    if numbers != [len(codes[code])] or code in found:
                        errors.append(f"{name} {code} reason count")
                    found[code] = True
        if set(found) != set(codes):
            manual.append(name + " reason-count table")

    actual = defaultdict(list)
    group = None
    header = []
    for line in docs["failures.md"]:
        if line.lstrip().startswith("#"):
            group = next((c for c in codes if re.search(rf"\b{c}\b", line)), None)
            header = []
        elif line.startswith("|"):
            row = cells(line)
            if "idx" in row:
                header = row
            elif "idx" in header and len(row) > header.index("idx") and row[header.index("idx")].isdigit():
                record = dict(zip(header, row))
                idx = int(record["idx"])
                reason = record.get("fail_code", group)
                if reason not in codes:
                    manual.append("failures.md detail reason or layout")
                    continue
                actual[reason].append(idx)
                for field in ("shard", "product", "item_dir", "verdict"):
                    if field not in record:
                        manual.append("failures.md detail field " + field)
                    elif idx not in rows or record[field] != rows[idx][field]:
                        errors.append(f"failures.md {reason} idx={idx} {field}")
    if not actual:
        manual.append("failures.md detailed index layout")
    else:
        for code, indices in codes.items():
            if Counter(actual[code]) != Counter({i: 1 for i in indices}):
                errors.append("failures.md missing, extra or duplicated entries for " + code)

    validation = docs["validation.md"]
    r3 = [l for l in validation if re.search(r"\bR3\b", l, re.I) and re.search(r"\b470\b", l)]
    if not r3:
        manual.append("validation.md R3 470")
    current_changes = "\n".join(validation)
    def paired(count, label):
        match_number = rf"(?<!\d){count}(?!\d)"
        qualifier = r"(?:\s|个|件|条|行|原先|原来|原|旧|先前|之前|过去|为|为原|曾|记录|的|[:：=|])*"
        return re.search(rf"{match_number}{qualifier}{label}\b|\b{label}{qualifier}{match_number}",
                         current_changes, re.I)
    corrected = paired(448, "pass") and paired(7, "partial")
    if not corrected:
        manual.append("validation.md 448 previous pass and 7 previous partial records")
    for i,l in enumerate(validation, 1):
        if re.search(r"假\s*pass\s*[:：=]?\s*455|455\s*(?:个|件|条)?\s*假\s*pass", l, re.I):
            if not re.search(r"作废|弃用|撤回|不正确|实为|应为|原误|旧称|误称|错误说法|更正为", l):
                errors.append(f"validation.md:{i} still counts 455 former pass records")

    current_b4 = set()
    for header, data in stats:
        for j, label in enumerate(header):
            metric = label.lower()
            if not re.search(r"失败|fail", metric) or re.search(r"旧|原始|原值|历史|old|legacy", metric):
                continue
            for row in data:
                identity = row[0].lower()
                if "tier b" not in identity and "b4" not in identity:
                    continue
                target = "clr" if "clr" in identity else "total" if re.search(r"合计|总计|total", identity) else None
                if target and j < len(row) and row[j].isdigit():
                    if int(row[j]) != len(nag):
                        errors.append(f"stats.md {row[0]} {label}={row[j]}, expected {len(nag)}")
                    else:
                        current_b4.add(target)
    stats_text = "\n".join(docs["stats.md"])
    if current_b4 != {"clr", "total"} and not any("b4" in l.lower() and "clr" in l.lower()
            and re.search(r"\b455\b", l) and re.search(r"失败|fail", l, re.I) for l in stats_text.splitlines()):
        manual.append("stats.md current CLR B4 failures and coverage scope")

    for message in dict.fromkeys(errors):
        print("DIFFERENCE", message)
    for message in dict.fromkeys(manual):
        print("REVIEW", message)
    print(f"fixed rows={len(rows)}, pass={verdicts['pass']}, fail={verdicts['fail']}, "
          f"reason memberships={sum(map(len,codes.values()))}, correction=448+7, CLR B4={len(nag)}")
    return 2 if errors else 3 if manual else 0


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input-dir", type=Path, help="six original #368 files; default uses fixed commit URLs")
    parser.add_argument("--reports", type=Path, default=ASSIGNMENTS.parent/"inbox/T9-REPORTS-399")
    args = parser.parse_args()
    try:
        sys.exit(check(args.reports, args.input_dir))
    except (ValueError, OSError, KeyError, IndexError) as exc:
        sys.exit(f"Input or table error: {exc}")
