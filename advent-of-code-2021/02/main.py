# tags: 2d grid

import re
from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = []
        for line in f.readlines():
            if cmd := re.search(r"^(forward|up|down) ([0-9]+)$", line):
                data.append((cmd.group(1), int(cmd.group(2))))
    return data


def part1(commands):
    horiz, depth = 0, 0
    for cmd, X in commands:
        if cmd == "forward":
            horiz += X
        elif cmd == "down":
            depth += X
        elif cmd == "up":
            depth -= X

    return horiz * depth


def part2(commands):
    horiz, depth, aim = 0, 0, 0

    for cmd, X in commands:
        if cmd == "forward":
            horiz += X
            depth += aim * X
        elif cmd == "down":
            aim += X
        elif cmd == "up":
            aim -= X

    return horiz * depth


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    print(benchmark(part1, 100)(real_input))
    print(benchmark(part2, 100)(real_input))

    assert part1(test1_input) == 150
    assert part2(test1_input) == 900
    assert part1(real_input) == 1815044
    assert part2(real_input) == 1739283308


if __name__ == "__main__":
    main()
