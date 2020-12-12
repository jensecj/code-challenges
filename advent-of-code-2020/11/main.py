from typing import Any, Tuple, List, Callable

import copy

from compytetive.util import benchmark

Board = List[List[Any]]
Seat = Tuple[int, int]


FLOOR, FREE, OCCUPIED = ".", "L", "#"

directions = [
    (-1, -1),
    (-1, 0),
    (-1, +1),
    (0, -1),
    (0, +1),
    (+1, -1),
    (+1, 0),
    (+1, +1),
]


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()
        data = [d.strip() for d in data]
        data = [list(line) for line in data]
    return data


def print_board(board: Board) -> None:
    for r in board:
        print("".join(r))
    print()


def adjacent_occupied_neighbours(board: Board, seat: Seat) -> int:
    H, W = len(board), len(board[0])
    sr, sc = seat

    occupied = 0
    for dr, dc in directions:
        r, c = sr + dr, sc + dc
        if 0 <= r < H and 0 <= c < W:
            if board[r][c] == OCCUPIED:
                occupied += 1

    return occupied


def sight_occupied_neighbours(board: Board, seat: Seat) -> int:
    H, W = len(board), len(board[0])
    sr, sc = seat

    occupied = 0
    for dr, dc in directions:
        r, c = sr + dr, sc + dc
        while 0 <= r < H and 0 <= c < W:
            # any time we see a chair, free or occupied,
            # it blocks our vision beyond that chair, so we need to break

            if board[r][c] == FREE:
                break

            if board[r][c] == OCCUPIED:
                occupied += 1
                break

            r, c = r + dr, c + dc

    return occupied


def step_state(state: Board, free_rule: Callable, occupied_rule: Callable) -> Board:
    board = copy.deepcopy(state)
    H, W = len(board), len(board[0])

    for r in range(H):
        for c in range(W):
            seat = (r, c)
            val = board[r][c]

            if val == FREE and free_rule(state, seat):
                board[r][c] = OCCUPIED

            if val == OCCUPIED and occupied_rule(state, seat):
                board[r][c] = FREE

    return board


@benchmark
def part1(data: Board) -> int:
    board = copy.deepcopy(data)
    lastboard = None

    def free_rule(state, seat):
        return adjacent_occupied_neighbours(state, seat) == 0

    def occupied_rule(state, seat):
        return adjacent_occupied_neighbours(state, seat) >= 4

    while lastboard != board:
        lastboard = board
        board = step_state(board, free_rule, occupied_rule)

    return sum([row.count(OCCUPIED) for row in board])


@benchmark
def part2(data: Board) -> int:
    board = copy.deepcopy(data)
    lastboard = None

    def free_rule(state, seat):
        return sight_occupied_neighbours(state, seat) == 0

    def occupied_rule(state, seat):
        return sight_occupied_neighbours(state, seat) >= 5

    while lastboard != board:
        lastboard = board
        board = step_state(board, free_rule, occupied_rule)

    return sum([row.count(OCCUPIED) for row in board])


def main():
    data = read_input("input.in")
    print(part1(data))
    print(part2(data))


if __name__ == "__main__":
    main()


test1_input = read_input("test1.in")
assert part1(test1_input) == 37
assert part2(test1_input) == 26

real_input = read_input("input.in")
assert part1(real_input) == 2113
assert part2(real_input) == 1865
