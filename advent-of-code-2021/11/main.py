# tags: game of life, simulation

from copy import deepcopy

import compytetive as C
from compytetive.util import *


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        return C.parse_grid_to_grid(f.read())


DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0), (-1, -1), (1, 1), (1, -1), (-1, 1)]


def simulate(grid):
    rows, columns = len(grid), len(grid[0])

    # take a single step, and increment all cells by 1
    for r in range(rows):
        for c in range(columns):
            grid[r][c] += 1

    # collect all the cells that are going to flash
    flashing = []
    for r in range(rows):
        for c in range(columns):
            if grid[r][c] > 9:
                flashing.append((r, c))

    # cells with a value > 9 are going to flash,
    # so increment all its neighbours by 1, keep going as new cells flash
    seen = set()
    while flashing:
        r, c = flashing.pop()
        grid[r][c] = 0
        seen.add((r, c))

        for nr, nc in [(r + dr, c + dc) for dr, dc in DIRECTIONS]:
            if 0 <= nr < rows and 0 <= nc < columns:
                # there is no reason to count cells that have already flashed
                if (nr, nc) in seen:
                    continue

                grid[nr][nc] += 1

                # if we increment a neighbour to the point where it flashes,
                # put it into the flashing queue
                if grid[nr][nc] == 10:
                    flashing.append((nr, nc))

    return grid


def part1(grid):
    grid = deepcopy(grid)
    flashes = 0
    for _ in range(100):
        grid = simulate(grid)
        for row in grid:
            flashes += sum(1 for c in row if c == 0)

    return flashes


def part2(grid):
    grid = deepcopy(grid)
    run = 0
    while grid := simulate(grid):
        run += 1
        if sum(sum(row) for row in grid) == 0:
            break

    return run


def main():
    test_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test_input) == 1656
    assert part1(real_input) == 1675
    print(benchmark(part1, 10)(real_input))

    assert part2(test_input) == 195
    assert part2(real_input) == 515
    print(benchmark(part2, 10)(real_input))


if __name__ == "__main__":
    main()
