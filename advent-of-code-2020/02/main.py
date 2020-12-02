import sys
from collections import Counter


def read_input():
    input = sys.stdin.readlines()
    for l in input:
        o = l.replace(":", "").replace("-", " ").strip()
        o = o.split()
        a, b, c, pw = int(o[0]), int(o[1]), o[2], o[3]
        yield (a, b, c, pw)


def part1(input):
    valid = 0
    for line in input:
        low, high, c, pw = line

        counter = Counter(pw)
        count = counter.get(c)
        if count and count >= low and count <= high:
            valid += 1

    print(valid)


def part2(input):
    valid = 0
    for line in input:
        a, b, c, pw = line
        a -= 1
        b -= 1

        if (a < len(pw) and pw[a] == c) ^ (b < len(pw) and pw[b] == c):
            valid += 1

    print(valid)


input = list(read_input())
part1(input.copy())
part2(input.copy())
