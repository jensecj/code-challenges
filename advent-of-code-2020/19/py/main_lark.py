# tags: context-free-grammar, parsing

import re

from lark import Lark  # type: ignore

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.read()
        rules, messages = data.split("\n\n")

    return rules, messages.split()


def part1(data):
    rules, messages = data

    # rename the rules because rules cant be numbers in lark
    rules = re.sub(r"(\d+)", r"t\1", rules)

    # start at rule 0, which was mapped to t0
    parser = Lark(rules, start="t0")

    total = 0
    for msg in messages:
        try:
            parser.parse(msg)
            total += 1
        except Exception:
            pass
    return total


def part2(data):
    rules, messages = data

    rules = rules.replace("8: 42", "8: 42 | 42 8")
    rules = rules.replace("11: 42 31", "11: 42 31 | 42 11 31")

    rules = re.sub(r"(\d+)", r"t\1", rules)

    parser = Lark(rules, start="t0")

    total = 0
    for msg in messages:
        try:
            parser.parse(msg)
            total += 1
        except Exception:
            pass
    return total


def main():
    data = read_input("../input.in")
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))

    # print(part1(read_input("../test1.in")))
    # print(part2(read_input("../test2.in")))


if __name__ == "__main__":
    main()


assert part1(read_input("../test1.in")) == 2
assert part2(read_input("../test2.in")) == 12

real_input = read_input("../input.in")
assert part1(real_input) == 182
assert part2(real_input) == 334
