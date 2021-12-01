# tags: sliding-window

from compytetive.util import benchmark
from compytetive import sliding_window


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.readlines()
        data = [int(d) for d in data]
    return data


def part1(data):
    increases = 0

    for w in sliding_window(data, 2):
        if w[1] > w[0]:
            increases += 1

    return increases


def part2(data):
    increases = 0
    previous = None
    for w in sliding_window(data, 3):
        if previous:
            if sum(w) > previous:
                increases += 1
        previous = sum(w)

    return increases


def main():
    data = read_input("input.in")
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    main()


test1_input = read_input("test1.in")
assert part1(test1_input) == 7
assert part2(test1_input) == 5

real_input = read_input("input.in")
assert part1(real_input) == 1665
assert part2(real_input) == 1702
