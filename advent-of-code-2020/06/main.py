# tags: sets

import sys


def read_input():
    input = sys.stdin.read()
    input = input.split("\n\n")

    for batch in input:
        yield [list(person) for person in batch.split()]


def part1(input):
    answer = 0
    for batch in input:
        sets = map(set, batch)
        answer += len(set.union(*sets))

    return answer


def part2(input):
    answer = 0
    for batch in input:
        sets = map(set, batch)
        answer += len(set.intersection(*sets))

    return answer


def main():
    input = list(read_input())
    print(part1(input))
    print(part2(input))


if __name__ == "__main__":
    main()
