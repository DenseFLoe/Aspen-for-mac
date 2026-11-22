"""Validate evidence files from the checkout root. Requires Python 3.8+."""
import csv
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

folder = Path(__file__).resolve().parents[1] / "inbox" / "CLR-CLOSURE"


def require(condition, message):
    if not condition:
        sys.exit(message)


def read_csv(name):
    with (folder / name).open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


graph = json.loads((folder / "closure.json").read_text(encoding="utf-8-sig"))
nodes = {n["id"]: n for n in graph["nodes"]}
edges = read_csv("assemblyrefs.csv")
summary = graph["summary"]
require(nodes and edges and len(edges) == summary["assemblyref_edges"], "AssemblyRef count")
require(len(nodes) == summary["root_count"] == len(graph["roots"]), "root count")
require({r["id"] for r in graph["roots"]} == set(nodes), "root IDs")
require(len({n["sha256"] for n in nodes.values()}) == summary["unique_source_sha256"], "unique originals")
require(sum(v["clr_rows"] for v in graph["inventories"].values()) == summary["clr_inventory_records"], "inventory total")
unresolved = {e["edge_id"]: e for e in graph["unresolved_edges"]}
edges_by_source = defaultdict(list)
status_counts = Counter()
for index, edge in enumerate(edges):
    require(int(edge["edge_id"]) == index, "edge ID")
    src = int(edge["source_id"])
    require(nodes[src]["path"] == edge["assembly"], "source path")
    status = edge["resolve_status"]
    status_counts[status] += 1
    target = edge["target_id"]
    if status == "resolved":
        other = nodes[int(target)]
        require(other["path"] == edge["resolved_path"], "resolved path")
        for part in ("name", "version", "culture", "public_key_token", "content_type"):
            require(str(other["identity"][part]).lower() == edge["ref_" + part].lower(), f"identity: {index}/{part}")
    else:
        require(not target and not edge["resolved_path"], "unresolved edge with target")
        gap = unresolved[index]
        require(gap["status"] == status and gap["source_id"] == src, f"unresolved source: {index}")
        for part in ("name", "version", "culture", "public_key_token", "content_type"):
            require(str(gap[part]).lower() == edge["ref_" + part].lower(), f"unresolved identity: {index}/{part}")
    edges_by_source[src].append((index, target))
require(dict(status_counts) == summary["status_counts"], "resolution counts")
require(len(unresolved) == len(edges) - status_counts["resolved"], "named unresolved edges")

for root in graph["roots"]:
    pending = [root["id"]]
    visited, gaps = set(pending), set()
    while pending:
        for index, target in edges_by_source[pending.pop()]:
            if not target:
                gaps.add(index)
            elif int(target) not in visited:
                visited.add(int(target))
                pending.append(int(target))
    require(sorted(visited) == root["reachable"] and sorted(gaps) == root["unresolved"], f"closure: {root['id']}")

builds = read_csv("build-results.csv")
diagnostics = json.loads((folder / "build-diagnostics.json").read_text(encoding="utf-8"))
hashes = {n["sha256"].lower() for n in nodes.values()}
samples = {r["sha256"].lower() for r in builds}
require(len(samples) == len(builds) >= 3 and samples <= hashes, "distinct original sample hashes")
require(max(int(r["bytes"]) for r in builds) > 1048576, "large sample")
for row in builds:
    name = Path(row["sample"]).stem
    require(nodes[int(row["node_id"])]["sha256"] == row["sha256"], f"original identity: {name}")
    for phase in ("before", "after"):
        errors = int(row[phase + "_errors"])
        exit_code = int(row[phase + "_exit"])
        require(errors >= 0 and (exit_code == 0) == (errors == 0), f"{row['sample']}: {phase}")
        counts = diagnostics[name][phase]
        require(sum(d["count"] for d in counts if d["level"] == "error") == errors, f"diagnostics: {name}/{phase}")
        log = (folder / (name + "." + phase + ".txt")).read_text(encoding="utf-8")
        require(sum(": error " in line for line in log.splitlines()) == errors, f"log: {name}/{phase}")
require((folder / "closure-test.md").stat().st_size > 0, "build report")
print(f"{len(nodes)} roots, {len(edges)} edges, {len(builds)} paired builds; counts and identities verified")
