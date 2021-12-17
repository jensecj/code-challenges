# tags: graphs, bfs, dfs, reursion

import re
from collections import defaultdict, deque

import compytetive as C
from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        nodes = defaultdict(set)
        for x, y in re.findall(r"([a-zA-Z]+)-([a-zA-Z]+)", data):
            nodes[x].add(y)
            nodes[y].add(x)
    return nodes


def part1_rec(nodes):
    def paths(nodes, cave, seen):
        # if a path reaches the end, it counts
        if cave == "end":
            return 1
        # dont count paths that visit the same small cave twice
        if cave.islower() and cave in seen:
            return 0

        seen = seen | {cave}
        return sum(paths(nodes, c, seen) for c in nodes[cave])

    return paths(nodes, "start", set())


def part1_iter(nodes):
    num_paths = 0
    Q = deque([("start", {"start"})])
    while Q:
        cave, seen = Q.pop()
        if cave == "end":
            num_paths += 1
            continue
        for c in nodes[cave]:
            if c.islower() and c in seen:
                continue
            Q.append((c, seen | {cave}))
    return num_paths


def part2_rec(nodes):
    def paths(nodes, cave, seen, taken):
        # if a path reaches the end, it counts
        if cave == "end":
            return 1
        # dont count paths that visit the same small cave twice
        if cave.islower() and cave in seen:
            if cave == "start" or taken:
                return 0
            taken = cave

        seen = seen | {cave}
        return sum(paths(nodes, c, seen, taken) for c in nodes[cave])

    return paths(nodes, "start", set(), None)


def part2_iter(nodes):
    num_paths = 0
    Q = deque([("start", {"start"}, None)])
    while Q:
        cave, seen, taken = Q.pop()
        if cave == "end":
            num_paths += 1
            continue
        for c in nodes[cave]:
            if c == "start":
                continue
            if c.isupper():
                Q.append((c, seen, taken))
            elif c.islower() and c not in seen:
                Q.append((c, seen | {c}, taken))
            elif c.islower() and c in seen and not taken:
                Q.append((c, seen, c))
            elif c.islower() and c in seen and taken:
                continue
    return num_paths


def main():
    test1_input = read_input("test1.in")
    test2_input = read_input("test2.in")
    test3_input = read_input("test3.in")
    real_input = read_input("input.in")

    assert part1_rec(test1_input) == 10
    assert part1_rec(test2_input) == 19
    assert part1_rec(test3_input) == 226
    assert part1_rec(real_input) == 3230
    print(benchmark(part1_rec, 10)(real_input))

    assert part1_iter(test1_input) == 10
    assert part1_iter(test2_input) == 19
    assert part1_iter(test3_input) == 226
    assert part1_iter(real_input) == 3230
    print(benchmark(part1_iter, 10)(real_input))

    assert part2_rec(test1_input) == 36
    assert part2_rec(test2_input) == 103
    assert part2_rec(test3_input) == 3509
    assert part2_rec(real_input) == 83475
    print(benchmark(part2_rec)(real_input))

    assert part2_iter(test1_input) == 36
    assert part2_iter(test2_input) == 103
    assert part2_iter(test3_input) == 3509
    assert part2_iter(real_input) == 83475
    print(benchmark(part2_iter)(real_input))
# https://teddit.net/r/adventofcode/comments/rehj2r/2021_day_12_solutions/

if __name__ == "__main__":
    main()
