# tags: hexagons, game of life

from typing import Tuple, List

from collections import defaultdict
from functools import lru_cache

from compytetive.util import benchmark


Point = Tuple[int, int]


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()
        data = [d.strip() for d in data]
    return data


DIRECTIONS = {
    "ne": (0, 1),
    "nw": (-1, 1),
    "se": (1, -1),
    "sw": (0, -1),
    "e": (1, 0),
    "w": (-1, 0),
}


def parse(directions: str) -> List[Point]:
    D = []

    while directions:
        # if a direction starts with n/s, it is a two-value direction
        if directions[0] in "ns":
            d = directions[:2]
            D.append(DIRECTIONS[d])
        elif directions[0] in "ew":
            d = directions[:1]
            D.append(DIRECTIONS[d])

        directions = directions.removeprefix(d)

    return D


def move(point: Point, directions: List[Point]):
    x, y = point
    for dx, dy in directions:
        x += dx
        y += dy

    return (x, y)


def build_tiles(data):
    tiles = defaultdict(bool)
    for dirs in data:
        p = move((0, 0), parse(dirs))
        tiles[p] = not tiles[p]

    return tiles


def part1(data):
    tiles = build_tiles(data)
    black_tiles = set(k for k, v in tiles.items() if v)
    return len(black_tiles)


@lru_cache(maxsize=None)
def neighbours(point: Point) -> List[Point]:
    x, y = point
    return [(x + dx, y + dy) for dx, dy in DIRECTIONS.values()]


def part2(data):
    tiles = build_tiles(data)
    black_tiles = set(k for k, v in tiles.items() if v)

    for _ in range(100):
        new_black_tiles = set()

        for t in black_tiles:
            for n in neighbours(t):
                black_neighbours = len([bn for bn in neighbours(n) if bn in black_tiles])

                if n in black_tiles:
                    if not (black_neighbours == 0 or black_neighbours > 2):
                        new_black_tiles.add(n)
                else:
                    if black_neighbours == 2:
                        new_black_tiles.add(n)

        black_tiles = new_black_tiles

    return len(black_tiles)


def main():
    data = read_input("input.in")
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    main()


test1_input = read_input("test1.in")
assert part1(test1_input) == 10
assert part2(test1_input) == 2208

real_input = read_input("input.in")
assert part1(real_input) == 500
assert part2(real_input) == 4280
