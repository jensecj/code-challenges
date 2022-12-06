# tags: sliding window

from compytetive.util import benchmark
from compytetive import sliding_window


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
    return data


def part1(data):
    for i, w in enumerate(sliding_window(data, 4, 1)):
        if len(set(w)) == len(w):
            return i + 4


def part2(data):
    for i, w in enumerate(sliding_window(data, 14, 1)):
        if len(set(w)) == len(w):
            return i + 14


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    print(benchmark(part1, 50)(real_input))
    print(benchmark(part2, 50)(real_input))

    assert part1(test1_input) == 7
    assert part2(test1_input) == 19
    assert part1(real_input) == 1175
    assert part2(real_input) == 3217


if __name__ == "__main__":
    main()
