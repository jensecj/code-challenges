# tags: sets

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.read()
        data = data.split("\n\n")

    for batch in data:
        yield [list(person) for person in batch.split()]


def part1(data):
    answer = 0
    for batch in data:
        sets = map(set, batch)
        answer += len(set.union(*sets))

    return answer


def part2(data):
    answer = 0
    for batch in data:
        sets = map(set, batch)
        answer += len(set.intersection(*sets))

    return answer


def main():
    data = list(read_input("input.in"))
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    main()

real_input = list(read_input("input.in"))
assert part1(real_input) == 6726
assert part2(real_input) == 3316
