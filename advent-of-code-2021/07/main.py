# tags: mean, median, triangle numbers

import numpy as np
from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        data = [int(c) for c in data.split(",")]
    return data


def part1(data):
    """
    Given a list of positions of crabs,
    if all items in the list have to move to the same index,
    then which index requires the smallest number of moves?
    """
    # the best position for each crab is the mean of all positions,
    # since the mean is closest number to all the numbers
    mean = np.round(np.median(data))
    distances = np.abs(mean - data)
    return int(np.sum(distances))


def nth_triangle_number(n):
    return (n * (n + 1)) // 2


cost = np.vectorize(nth_triangle_number)


def part2(data):
    """
    Same as part 1, except:
    for every crab, the next move will cost one more that this move.
    """
    # usually the data in aoc lines up with simple solutions,
    # but here we end in a case where the mean is always
    # within 0.5 of the real solution
    # to solve this, we just look at the solution for both the floor and ceil cases
    mean = np.mean(data)
    cmean, fmean = np.ceil(mean), np.floor(mean)
    cdist, fdist = np.abs(cmean - data), np.abs(fmean - data)
    ccost, fcost = cost(cdist), cost(fdist)
    return int(min(np.sum(ccost), np.sum(fcost)))


def main():
    test1_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test1_input) == 37
    assert part1(real_input) == 348664

    assert part2(test1_input) == 168
    assert part2(real_input) == 100220525

    print(benchmark(part1, 10)(real_input))
    print(benchmark(part2, 10)(real_input))


if __name__ == "__main__":
    main()
