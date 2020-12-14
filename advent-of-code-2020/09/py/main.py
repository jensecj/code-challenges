# tags: greedy, window

from more_itertools import windowed

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()
        data = [int(s.strip()) for s in data]
    return data


def two_sum(data: list[int], num: int):  # type: ignore
    """
    To test is any two numbers in a list sums to a third number N, you can iterate through
    the numbers in the list and check if (N - number) is in the list.
    """
    for i in data:
        if num - i in data:
            return True

    return False


def validate(previous: int, data: list[int]):  # type: ignore
    result = [None] * (len(data) - previous)
    for i in range(len(data) - previous):
        element = data[i + previous]
        preamble = data[i : i + previous]
        result[i] = two_sum(preamble, element)

    return result


def locate_failing_state(states):
    return states.index(False) if False in states else None


def part1(data, preamble):
    states = validate(preamble, data)

    if idx := locate_failing_state(states):
        return data[preamble + idx]

    return None


def part2(data, num):
    """
    Bruteforce approach:
    generate sliding windows of all lengths from 2 -> length of input,
    then test if any of them sum to NUM.
    """
    for i in range(2, len(data) - 1):
        for w in windowed(data, n=i, step=1):
            if sum(w) == num:
                return min(w) + max(w)

    return None


def part2_faster(data, num):
    """
    The problem can be solved using a sliding window over the data,
    expanding to the left when the sum of the window is less than the number we're
    looking for, and contracting from the left when the sum is bigger.
    """
    left, right = 0, 1
    window = data[left:right]

    while (s := sum(window)) != num:
        if s > num:
            left += 1
        if s < num:
            right += 1

        window = data[left:right]

    return min(window) + max(window)


def main():
    data = read_input("../input.in")
    preamble = 25

    invalid_number = benchmark(part1)(data, preamble)
    print(invalid_number)
    print(benchmark(part2)(data, invalid_number))
    print(benchmark(part2_faster)(data, invalid_number))


if __name__ == "__main__":
    main()


test1_input = read_input("../test1.in")
assert part1(test1_input, 5) == 127
assert part2(test1_input, 127) == 62
assert part2_faster(test1_input, 127) == 62


real_input = read_input("../input.in")
assert part1(real_input, 25) == 31161678
assert part2(real_input, 31161678) == 5453868
assert part2_faster(real_input, 31161678) == 5453868
