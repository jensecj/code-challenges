# tags: grid

import re
import numpy as np
from collections import defaultdict
from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        lines = []
        for line in re.findall(r"(\d+),(\d+) -> (\d+),(\d+)", data):
            lines.append(tuple(int(n) for n in line))
    return lines


def sign(x):
    if x < 0:
        return -1
    if x > 0:
        return 1
    return 0


def get_straight_line(ax, ay, bx, by):
    points = []
    if ax == bx or ay == by:
        dx, dy = sign(bx - ax), sign(by - ay)
        for d in range(abs(bx - ax) + abs(by - ay) + 1):
            points.append((ax + dx * d, ay + dy * d))
    return points


def get_diagonal_line(ax, ay, bx, by):
    points = []
    if ax != bx and ay != by:
        dx, dy = sign(bx - ax), sign(by - ay)
        for d in range(abs(bx - ax) + 1):
            points.append((ax + dx * d, ay + dy * d))
    return points


def part1(data):
    grid = defaultdict(int)

    for points in data:
        lines = get_straight_line(*points)
        for x, y in lines:
            grid[x, y] += 1

    return sum(1 for x, y in grid if grid[x, y] > 1)


def part2(data):
    grid = defaultdict(int)

    for points in data:
        for x, y in get_straight_line(*points) + get_diagonal_line(*points):
            grid[x, y] += 1

    return sum(1 for x, y in grid if grid[x, y] > 1)


def mark_straight_lines(grid, points):
    for ax, ay, bx, by in points:
        # xs or ys have to line up for straight lines
        if ax == bx or ay == by:
            ax, bx = min(ax, bx), max(ax, bx)
            ay, by = min(ay, by), max(ay, by)
            grid[ay : by + 1, ax : bx + 1] += 1
    return grid


def mark_diagonal_lines(grid, points):
    for ax, ay, bx, by in points:
        # xs and ys cant line up for diagonal lines
        if ax != bx and ay != by:
            dx = np.sign(bx - ax)
            dy = np.sign(by - ay)
            xs = np.arange(ax, bx + dx, dx)
            ys = np.arange(ay, by + dy, dy)
            grid[ys, xs] += 1
    return grid


def part1_numpy(data):
    points = np.array(data)
    max_x = points[:, [0, 2]].max()  # ax,bx are indices 0,2
    max_y = points[:, [1, 3]].max()  # ay,by are indices 1,3
    grid = np.full((max_y + 1, max_x + 1), 0)

    grid = mark_straight_lines(grid, points)

    return np.sum(grid >= 2)


def part2_numpy(data):
    points = np.array(data)
    max_x = points[:, [0, 2]].max()
    max_y = points[:, [1, 3]].max()
    grid = np.full((max_y + 1, max_x + 1), 0)

    grid = mark_straight_lines(grid, points)
    grid = mark_diagonal_lines(grid, points)

    return np.sum(grid >= 2)


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    assert part1(test1_input) == 5
    assert part1_numpy(test1_input) == 5
    assert part1(real_input) == 5147
    assert part1_numpy(real_input) == 5147

    assert part2(test1_input) == 12
    assert part2_numpy(test1_input) == 12
    assert part2(real_input) == 16925
    assert part2_numpy(real_input) == 16925

    print(benchmark(part1, 3)(real_input))
    print(benchmark(part1_numpy, 10)(real_input))
    print(benchmark(part2, 3)(real_input))
    print(benchmark(part2_numpy, 10)(real_input))


if __name__ == "__main__":
    main()
