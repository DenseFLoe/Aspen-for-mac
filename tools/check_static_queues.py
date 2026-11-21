"""核对逐件总表、四份静态验收清单和修复清单。"""

import argparse
import csv
from pathlib import Path
import re
import sys


ID = "原件SHA256"
DETAILS = ("产品", "原路径", "文件夹")
PENDING = "待静态验收"
FAILED = "静态验收未通过"
STATES = {PENDING, FAILED, "静态验收通过", "未成功"}


def read_rows(path, required):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        reader = csv.DictReader(stream, strict=True)
        header = reader.fieldnames or []
        if len(set(header)) != len(header) or not set(required).issubset(header):
            raise ValueError(f"{path.name} 的表头重复或缺少必要字段")
        for row in reader:
            location = f"{path.name}:{reader.line_num}"
            if None in row or None in row.values() or not all(row[key].strip() for key in required):
                raise ValueError(f"{location} 字段为空或列数错误")
            if not re.fullmatch(r"[0-9a-fA-F]{64}", row[ID]):
                raise ValueError(f"{location} 原件 SHA-256 格式错误")
            yield row[ID].lower(), row, location


def check(root):
    ledger = {}
    folders = set()
    for key, row, location in read_rows(root / "逆向成果/逐件总表.csv", (ID, *DETAILS, "状态")):
        state, folder = row["状态"], row["文件夹"]
        prefix = f"逆向成果/{state}/{row['产品']}/"
        if state not in STATES or not folder.startswith(prefix) or folder == prefix:
            raise ValueError(f"{location} 状态或文件夹不匹配：{folder}")
        if key in ledger or folder.casefold() in folders:
            raise ValueError(f"{location} 总表原件或文件夹重复：{key} {folder}")
        ledger[key] = row
        folders.add(folder.casefold())

    assigned = {}
    counts = {}
    for filename in ("audit-1.csv", "audit-2.csv", "audit-3.csv", "audit-4.csv", "repair.csv"):
        queue = root / "项目资料/静态验收分工" / filename
        expected_state = FAILED if filename == "repair.csv" else PENDING
        counts[filename] = 0
        for key, row, location in read_rows(queue, (ID, *DETAILS, "复验组")):
            if key in assigned:
                raise ValueError(f"{location} 与 {assigned[key]} 重复认领：{key}")
            original = ledger.get(key)
            if original is None or original["状态"] != expected_state:
                raise ValueError(f"{location} 与总表状态不符或缺原件：{key}")
            if any(row[field] != original[field] for field in DETAILS):
                raise ValueError(f"{location} 产品、原路径或文件夹与总表不一致：{key}")
            group = row["复验组"]
            if group not in ("1", "2", "3", "4") or (expected_state == PENDING and filename != f"audit-{group}.csv"):
                raise ValueError(f"{location} 复验组错误：{group} / {key}")
            assigned[key] = location
            counts[filename] += 1

    expected = {key for key, row in ledger.items() if row["状态"] in (PENDING, FAILED)}
    missing = expected - assigned.keys()
    if missing:
        raise ValueError(f"清单漏列 {len(missing)} 件，例如 {min(missing)}")
    print(f"总表 {len(ledger)} 件，五份清单合计 {len(assigned)} 件，归属核对通过。")
    print("  ".join(f"{name}={count}" for name, count in counts.items()))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("root", nargs="?", type=Path, default=Path(__file__).resolve().parents[1],
                        help="待检查的仓库快照根目录")
    try:
        check(parser.parse_args().root)
    except (OSError, ValueError, csv.Error) as exc:
        print(exc, file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
