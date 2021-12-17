# tags: graphs, path finding

import re
import heapq as hq
from collections import defaultdict, deque

import networkx as nx
import compytetive as C
from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        return C.parse_grid_to_dict(data)


def part1(data):
    G = nx.DiGraph()
    for x, y in data.keys():
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            xn, yn = x + dx, y + dy
            if (xn, yn) in data.keys():
                G.add_edge((x, y), (xn, yn), weight=data[(xn, yn)])

    maxx = max(x for x, y in data.keys())
    maxy = max(y for x, y in data.keys())

    path = nx.astar_path(G, (0, 0), (maxx, maxy), weight="weight")
    risk = sum(data[p] for p in path) - data[(0, 0)]
    return risk


def part2(data):
    data = data.copy()
    maxx = max(x for x, y in data.keys())
    maxy = max(y for x, y in data.keys())

    # fill first column
    for x, y in data.copy().keys():
        for yy in range(1, 5):
            old_weight = data[(x, y)]
            new_weight = old_weight + yy
            if new_weight > 9:
                new_weight = (new_weight % 10) + 1
            data[(x, y + (maxy + 1) * yy)] = new_weight

    # fill all rows
    for x, y in data.copy().keys():
        for yy in range(0, 5):
            for xx in range(1, 5):
                nextx = x + (maxx + 1) * xx
                thisx = x + (maxx + 1) * (xx - 1)
                old_weight = data[(thisx, y)]
                new_weight = old_weight + 1
                if new_weight > 9:
                    new_weight = (new_weight % 10) + 1
                data[(nextx, y)] = new_weight

    # recalculate min/max values
    maxx = max(x for x, y in data.keys())
    maxy = max(y for x, y in data.keys())

    G = nx.DiGraph()
    for x, y in data.keys():
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            xn, yn = x + dx, y + dy
            if (xn, yn) in data.keys():
                G.add_edge((x, y), (xn, yn), weight=data[(xn, yn)])

    path = nx.astar_path(G, (0, 0), (maxx, maxy), weight="weight")
    risk = sum(data[p] for p in path) - data[(0, 0)]
    return risk


def main():
    test_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test_input) == 40
    assert part1(real_input) == 656
    print(benchmark(part1)(real_input))

    assert part2(test_input) == 315
    assert part2(real_input) == 2979
    print(benchmark(part2)(real_input))


if __name__ == "__main__":
    main()
