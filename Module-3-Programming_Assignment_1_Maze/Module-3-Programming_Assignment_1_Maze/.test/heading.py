
import argparse
import re
import sys
from pathlib import Path

PATTERN = re.compile(
    r"/\*.*program name:.*?\s.*?author:.*\s.*?date last updated:\s*(1[12]|0?[1-9])\/((1|2)[0-9]|0?[1-9]|3[01])\/(20)?2[6789]\s.*?purpose:",
    re.DOTALL | re.IGNORECASE,
)

def search_file(path: Path) -> list[str]:
    text = path.read_text(encoding="utf-8", errors="ignore")
    return PATTERN.findall(text) if PATTERN.search(text) else []

def main() -> None:
    parser = argparse.ArgumentParser(
        description="Search files for /* ... program name: ... author: ... date last updated: ... purpose: ... */ blocks."
    )
    parser.add_argument("files", nargs="+", help="One or more filenames to search")
    args = parser.parse_args()

    for filename in args.files:
        path = Path(filename)
        if not path.exists():
            print(f"{filename}: file not found")
            continue

        matches = PATTERN.finditer(path.read_text(encoding="utf-8", errors="ignore"))
        found = False
        for match in matches:
            found = True
            print(f"{filename}: match:")
            print(match.group(0))
            print("-" * 40)
            sys.exit(0)

        if not found:
            print(f"{filename}: no match found")
    sys.exit(1)

if __name__ == "__main__":
    main()
