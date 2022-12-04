# tags: overlapping ranges, set operations

import re

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        ranges = []
        for a, b, x, y in re.findall(r"(\d+)-(\d+),(\d+)-(\d+)", data):
            l = set(range(int(a), int(b) + 1))
            r = set(range(int(x), int(y) + 1))
            ranges.append((l, r))
    return ranges


def part1(data):
    overlaps = 0
    for l, r in data:
        if l.issubset(r) or r.issubset(l):
            overlaps = overlaps + 1

    return overlaps


def part2(data):
    overlaps = 0
    for l, r in data:
        if len(l.intersection(r)) > 0:
            overlaps = overlaps + 1

    return overlaps


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    print(benchmark(part1, 50)(real_input))
    print(benchmark(part2, 50)(real_input))

    assert part1(test1_input) == 2
    assert part2(test1_input) == 4
    assert part1(real_input) == 567
    assert part2(real_input) == 907


if __name__ == "__main__":
    main()
