import re
from collections import Counter

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.read()

        for s in re.findall(r"(\d+)-(\d+) (.): (.+)", data):
            yield int(s[0]), int(s[1]), s[2], s[3].strip()


def part1(data):
    valid = 0
    for line in data:
        low, high, c, pw = line

        counter = Counter(pw)
        count = counter.get(c)
        if count and low <= count <= high:
            valid += 1

    return valid


def part2(data):
    valid = 0
    for line in data:
        a, b, c, pw = line
        a -= 1
        b -= 1

        if (a < len(pw) and pw[a] == c) ^ (b < len(pw) and pw[b] == c):
            valid += 1

    return valid


def main():
    data = list(read_input("../input.in"))
    print(benchmark(part1)(data.copy()))
    print(benchmark(part2)(data.copy()))


if __name__ == "__main__":
    main()


real_input = list(read_input("../input.in"))
assert part1(real_input.copy()) == 538
assert part2(real_input.copy()) == 489
