# tags: simulation

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        data = [int(c) for c in data.split(",")]
    return data


def sim_fish(data, days):
    fish = [0] * 9
    for f in data:
        fish[f] += 1

    for _ in range(days):
        # by popping the first element and inserting at the back
        # we're moving each count of days leftwards through the list by 1
        f = fish.pop(0)
        fish[6] += f
        fish.append(f)

    return sum(fish)


def part1(data):
    return sim_fish(data, 80)


def part2(data):
    return sim_fish(data, 256)


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    assert part1(test1_input) == 5934
    assert part2(test1_input) == 26984457539
    assert part1(real_input) == 354564
    assert part2(real_input) == 1609058859115

    print(benchmark(part1)(real_input))
    print(benchmark(part2)(real_input))


if __name__ == "__main__":
    main()
