# tags: lists

import re
from copy import deepcopy
from collections import defaultdict

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read().split("\n\n")

        raw_crates = data[0].splitlines()[:-1]  # dont need the last numbered line
        crates = defaultdict(list)
        for c in raw_crates:
            # a create is either space (3 spaces + 1 surrounding), or labeled [X]
            for i, a in enumerate(re.findall(r"    |\[([A-Z])\]", c)):
                if a.isalpha():
                    crates[i + 1].insert(0, a)

        raw_moves = data[1].splitlines()
        moves = []
        for move in raw_moves:
            for n, f, t in re.findall(r"move (\d+) from (\d+) to (\d+)", move):
                moves.append((int(n), int(f), int(t)))

    return crates, moves


def part1(data):
    crates, moves = deepcopy(data)

    for n, f, t in moves:
        # move each crate to its destination one-by-one to ensure ordering
        for _ in range(n):
            e = crates[f].pop()
            crates[t].append(e)

    output = ""
    for k in sorted(crates.keys()):
        output = output + crates[k][-1]

    return output


def part2(data):
    crates, moves = deepcopy(data)
    for n, f, t in moves:
        # instead of popping crates one-by-one, remove them in chunks
        es = crates[f][-n:]
        del crates[f][-n:]
        crates[t].extend(es)

    output = ""
    for k in sorted(crates.keys()):
        output = output + crates[k][-1]

    return output


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    print(benchmark(part1, 50)(real_input))
    print(benchmark(part2, 50)(real_input))

    assert part1(test1_input) == "CMZ"
    assert part2(test1_input) == "MCD"
    assert part1(real_input) == "FRDSQRRCD"
    assert part2(real_input) == "HRFTQVWNN"


if __name__ == "__main__":
    main()
