# tags: set operations

from compytetive.util import benchmark
from compytetive import sliding_window


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.readlines()
        data = [d.strip() for d in data]
    return data


def priority(c):
    abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    return abc.index(c) + 1


def part1(data):
    score = 0
    for d in data:
        # split each string into halfs
        l, r = d[: len(d) // 2], d[len(d) // 2 :]
        # explode halfs into sets
        l, r = set([*l]), set([*r])

        for i in set.intersection(l, r):
            score = score + priority(i)
    return score


def part2(data):
    score = 0
    for w in sliding_window(data, size=3, step=3):
        # explode strings into sets
        ls = [set([*l]) for l in w]

        for i in set.intersection(*ls):
            score = score + priority(i)

    return score


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    print(benchmark(part1, 50)(real_input))
    print(benchmark(part2, 50)(real_input))

    assert part1(test1_input) == 157
    assert part2(test1_input) == 70
    assert part1(real_input) == 8039
    assert part2(real_input) == 2510


if __name__ == "__main__":
    main()
