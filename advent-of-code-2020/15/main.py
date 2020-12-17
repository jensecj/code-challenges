# tags: number theory

from typing import List

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.read()

    return [int(i) for i in data.split(",")]


def _run(data: List[int], pick: int) -> int:
    """
    Keep a map to track the index of the last time a number was spoken out.
    """
    # fill the map of seen values from input
    prev = {}
    for i, d in enumerate(data[:-1]):
        prev[d] = i

    last = data[-1]

    for i in range(len(data), pick):
        # if last number has not appeared before, current number is 0
        if last not in prev:
            num = 0
        else:  # otherwise, current number is (current index) - (latest index of last number)
            idx = prev[last]
            num = i - idx - 1  # -1 because we are zero indexed

        # we only update the map for the last entry we see,
        # if we updated the current num, we would have seen it in the next iteration
        prev[last] = i - 1
        last = num

    return last


def run(data: List[int], pick: int) -> int:
    """
    Alternatively, you can avoid hashing alltogether by using a list of indexes,
    because the upper bound for an index is the number of turns we iterate.
    """

    # fill the map of seen values from input
    prev = [-1] * pick
    for i, d in enumerate(data[:-1]):
        prev[d] = i

    last = data[-1]

    for i in range(len(data), pick):
        # if last number has not appeared before, current number is 0
        if prev[last] == -1:
            num = 0
        else:  # otherwise, current number is (current index) - (latest index of last number)
            idx = prev[last]
            num = i - idx - 1  # -1 because we are zero indexed

        # we only update the map for the last entry we see,
        # if we updated the current num, we would have seen it in the next iteration
        prev[last] = i - 1
        last = num

    return last


def van_eck(data, N):
    seen = {}
    for i, e in enumerate(data[:-1]):
        seen[e] = i

    val = data[-1]

    for i in range(len(data) - 1, N - 1):
        last = {val: i}
        val = i - seen.get(val, i)
        seen.update(last)

    return val


# assert list(van_eck([0, 3, 6], 10)) == [0, 3, 3, 1, 0, 4, 0, 2]
assert van_eck([0, 3, 6], 2020) == 436
assert van_eck([1, 3, 2], 2020) == 1
assert van_eck([2, 1, 3], 2020) == 10
assert van_eck([1, 2, 3], 2020) == 27
assert van_eck([2, 3, 1], 2020) == 78
assert van_eck([3, 2, 1], 2020) == 438
assert van_eck([3, 1, 2], 2020) == 1836


def part1(data):
    return run(data, 2020)


def part2(data):
    return run(data, 30000000)


def main():
    data = read_input("input.in")

    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        pass

assert part1([0, 3, 6]) == 436
assert part1([1, 3, 2]) == 1
assert part1([2, 1, 3]) == 10
assert part1([1, 2, 3]) == 27
assert part1([2, 3, 1]) == 78
assert part1([3, 2, 1]) == 438
assert part1([3, 1, 2]) == 1836

assert part2([0, 3, 6]) == 175594
assert part2([1, 3, 2]) == 2578
assert part2([2, 1, 3]) == 3544142
assert part2([1, 2, 3]) == 261214
assert part2([2, 3, 1]) == 6895259
assert part2([3, 2, 1]) == 18
assert part2([3, 1, 2]) == 362


real_input = read_input("input.in")
assert part1(real_input) == 276
assert part2(real_input) == 31916
