# tags: adding numbers

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read().strip()
        data = data.split("\n\n")
        data = [d.split("\n") for d in data]
        groups = []
        for d in data:
            groups.append([int(i) for i in d])

    return groups


def part1(data):
    # find the elfs carrying most calories
    return max(sum(group) for group in data)


def part2(data):
    # find the three elfs carrying most calories
    elfs = sorted(sum(group) for group in data)
    return sum(elfs[-3:])


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    print(benchmark(part1, 50)(real_input))
    print(benchmark(part2, 50)(real_input))

    assert part1(test1_input) == 24000
    assert part2(test1_input) == 45000
    assert part1(real_input) == 68923
    assert part2(real_input) == 200044


if __name__ == "__main__":
    main()
