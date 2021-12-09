# tags: graphs, connected components, flood fill, bfs

import math
import heapq as hq
from collections import deque

import networkx as nx

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        data = data.split("\n")
        data = list(map(int, list(d)) for d in data if d)
        data = [[*d] for d in data]
        return data


def find_low_points(grid):
    """
    grid is 100x100, so we can easily run through all nodes in the grid,
    and check if they are strictly smaller than their neighbours
    """
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    max_y, max_x = len(grid), len(grid[0])

    for y in range(max_y):
        for x in range(max_x):
            neighbours = (
                (x + dx, y + dy)
                for dx, dy in directions
                if 0 <= x + dx < max_x and 0 <= y + dy < max_y
            )
            if all(grid[y][x] < grid[n_y][n_x] for n_x, n_y in neighbours):
                yield (x, y)


def part1(grid):
    return sum(grid[y][x] + 1 for x, y in find_low_points(grid))


def part2_nx(grid):
    """
    smoke flows down from height 9 to the basins at 0,
    all we have to do is split the graph at the ridges where the height is 9,
    which splits the graph into several components, then find the three largest
    """
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    max_y, max_x = len(grid), len(grid[0])
    G = nx.Graph()

    for y in range(max_y):
        for x in range(max_x):
            # if we're at peak, cut it out of the components by ignoring it
            if grid[y][x] == 9:
                continue
            neighbours = (
                (x + dx, y + dy)
                for dx, dy in directions
                if 0 <= x + dx < max_x and 0 <= y + dy < max_y
            )
            for n_x, n_y in neighbours:
                if grid[n_y][n_x] < 9:
                    G.add_edge((x, y), (n_x, n_y))

    basins = (len(c) for c in nx.connected_components(G))
    return math.prod(hq.nlargest(3, basins))


def part2(grid):
    """
    if we split the grid at nodes with height 9, we end up with disconnected basins.
    to find the size of the regions, we find all the lowest points as in part 1,
    then do a flood fill with BFS to find all the nodes in each basin
    """
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    max_y, max_x = len(grid), len(grid[0])
    basins = []

    for x, y in find_low_points(grid):
        nodes = deque([(x, y)])
        seen = set()
        while nodes:
            x, y = nodes.pop()
            seen.add((x, y))

            neighbours = (
                (x + dx, y + dy)
                for dx, dy in directions
                if 0 <= x + dx < max_x and 0 <= y + dy < max_y
            )

            nodes.extend(
                (x, y) for x, y in neighbours if (x, y) not in seen and grid[y][x] < 9
            )

        basins.append(seen)

    basins = [len(c) for c in basins]
    return math.prod(hq.nlargest(3, basins))


def main():
    test_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test_input) == 15
    assert part1(real_input) == 631
    print(benchmark(part1, 10)(real_input))

    assert part2_nx(test_input) == 1134
    assert part2_nx(real_input) == 821560
    print(benchmark(part2_nx, 10)(real_input))

    assert part2(test_input) == 1134
    assert part2(real_input) == 821560
    print(benchmark(part2, 10)(real_input))


if __name__ == "__main__":
    main()
