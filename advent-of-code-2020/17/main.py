# tags: simulation, n-dimensional

import itertools as it
from collections import defaultdict

from compytetive.util import benchmark


ACTIVE, INACTIVE = "#", "."


def directions(dimensions=3):
    """Return directions to neighbours of origin in DIMENSIONS"""
    points = list(it.product([-1, 0, 1], repeat=dimensions))

    # remove the origin (point of all zeroes)
    x = tuple([0] * dimensions)
    points.remove(x)

    return points


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()
        data = [d.strip() for d in data]
    return data


def read_board(data, dimensions=3):
    board = defaultdict(lambda: ".")

    # we read the x,y values from the input board
    for y, line in enumerate(data):
        for x, coord in enumerate(line):
            # the remaining dimensions have an initial value of 0
            empty = [0] * (dimensions - 2)
            board[(x, y, *empty)] = coord

    return board


assert read_board([".#.", "..#", "###"]) == {
    (0, 0, 0): ".",
    (1, 0, 0): "#",
    (2, 0, 0): ".",
    (0, 1, 0): ".",
    (1, 1, 0): ".",
    (2, 1, 0): "#",
    (0, 2, 0): "#",
    (1, 2, 0): "#",
    (2, 2, 0): "#",
}


def adjacent_neighbours(point, dimensions=3):
    points = []
    for p in directions(dimensions):
        # tuple addition, only works on tuples of same size
        n = tuple(map(lambda i, j: i + j, point, p))
        points.append(n)

    return points


def adjacent_active_neighbours(board, point, dimensions=3) -> int:
    active = 0
    for n in adjacent_neighbours(point, dimensions):
        if board.get(n) == ACTIVE:
            active += 1

    return active


def print_board(board) -> None:
    # TODO: only print region with active cells
    width = max(3, *[max(p) for p in board.keys()])

    print()
    for z in range(-1, 2):
        print(f"{z=}")
        for y in range(width):
            xs = [board[(x, y, z)] for x in range(width)]
            print("".join(xs))
        print()
    print()


def step(board, dimensions=3):
    new_board = board.copy()

    # we need to check all neighbours of currently active cells
    neighbours = set()
    for p in board.keys():
        for n in adjacent_neighbours(p, dimensions):
            neighbours.add(n)

    for point in neighbours:
        cell = board[point]
        active_neighbours = adjacent_active_neighbours(board, point, dimensions)
        if cell == ACTIVE:
            if active_neighbours not in [2, 3]:
                new_board[point] = INACTIVE
        elif cell == INACTIVE:
            if active_neighbours == 3:
                new_board[point] = ACTIVE

    return new_board


def part1(data):
    board = read_board(data)

    for _ in range(1, 6 + 1):
        board = step(board)

    active = [*board.values()].count("#")
    return active


def part2(data):
    board = read_board(data, 4)

    for _i in range(1, 6 + 1):
        board = step(board, 4)

    active = [*board.values()].count("#")
    return active


def main():
    data = read_input("input.in")
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    main()


test1_input = read_input("test1.in")
assert part1(test1_input) == 112
assert part2(test1_input) == 848

real_input = read_input("input.in")
assert part1(real_input) == 346
assert part2(real_input) == 1632
