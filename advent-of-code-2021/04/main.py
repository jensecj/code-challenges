# tags: grid

import numpy as np
from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        raw_calls, *raw_grids = data.split("\n\n")

        calls = [int(c) for c in raw_calls.split(",") if c]

        grids = []
        for raw_grid in raw_grids:
            grid = []
            for g in raw_grid.strip().split("\n"):
                grid.append([int(c) for c in g.split(" ") if c])

            # store rows and columns as sets
            gridsets = []
            for line in grid:
                gridsets.append([i for i in line])
            for line in list(zip(*grid)):
                gridsets.append([i for i in line])

            grids.append(gridsets)

        cells = []
        for grid in grids:
            cell = set.union(*(set(s) for s in grid))
            cells.append(cell)

    return (calls, grids, cells)


def get_winners(calls, grids):
    indices = set(range(len(grids)))
    found = set()

    for i in range(5, len(calls)):
        remaining = indices - found
        if not remaining:
            break

        call = calls[:i]

        for g in remaining:
            for line in grids[g]:
                if set(line) <= set(call):
                    found.add(g)
                    yield (g, call)
                    break


def part1(data):
    calls, grids, cells = data

    winner, winning_call = next(get_winners(calls, grids))

    rest_sum = sum(cells[winner])
    for i in winning_call:
        if i in cells[winner]:
            rest_sum -= i

    return winning_call[-1] * rest_sum


def part2(data):
    calls, grids, cells = data

    *_, winner = get_winners(calls, grids)
    winner, winning_call = winner

    rest_sum = sum(cells[winner])
    for i in winning_call:
        if i in cells[winner]:
            rest_sum -= i

    return winning_call[-1] * rest_sum


def read_input_numpy(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        raw_calls, *raw_grids = data.split("\n\n")

    calls = [int(c) for c in raw_calls.split(",") if c]
    grids = np.loadtxt(raw_grids, dtype=int).reshape(-1, 5, 5)

    return calls, grids


def get_wins(calls, grids):
    for c in calls:
        # mark all numbers in 3darray that match the called number
        grids[grids == c] = -1

        # get the 3darray of only marked numbers
        marked = grids == -1

        # test each grid in the 3darray for fully marked rows / columns,
        # then reduce results for all grids to a 1darray
        full_rows = marked.all(1)
        full_cols = marked.all(2)
        combined = full_rows | full_cols
        winner = combined.any(1)

        if any(winner):
            # ignore marked numbers when calculating score
            grids_sans_marks = grids * ~marked
            winning_grid = grids_sans_marks[winner]
            score = winning_grid.sum() * c
            yield score
            # the winning grid will keep winning for any further calls,
            # since we dont need to know if it will win in other ways, remove it
            grids = grids[~winner]


def part1_numpy(data):
    calls, grids = data
    return next(get_wins(calls, grids))


def part2_numpy(data):
    calls, grids = data
    *_, win = get_wins(calls, grids)
    return win


def main():
    test1_input = read_input("test1.in")
    test1_input_numpy = read_input_numpy("test1.in")
    real_input = read_input("input.in")
    real_input_numpy = read_input_numpy("input.in")

    assert part1(test1_input) == 4512
    assert part1_numpy(test1_input_numpy) == 4512
    assert part2(test1_input) == 1924
    assert part2_numpy(test1_input_numpy) == 1924
    assert part1(real_input) == 4662
    assert part1_numpy(real_input_numpy) == 4662
    assert part2(real_input) == 12080
    assert part2_numpy(real_input_numpy) == 12080

    print(benchmark(part1, 5)(real_input))
    print(benchmark(part1_numpy, 5)(real_input_numpy))
    print(benchmark(part2, 5)(real_input))
    print(benchmark(part2_numpy, 5)(real_input_numpy))


if __name__ == "__main__":
    main()
