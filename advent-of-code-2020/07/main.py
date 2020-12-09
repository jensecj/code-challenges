import sys
import re
from collections import deque
from compytetive.util import time


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()

    bags = {}
    for b in data:
        bag = re.search(r"(.+?) bag", b).group(1)
        contains = re.findall(r"(\d+) (.+?) bag", b)
        bags[bag] = [(int(c), b) for c, b in contains]

    return bags


def contains_bag(bag, bags):
    """Return the subset of BAGS which contain BAG"""
    contains = []
    for b, children in bags.items():
        if bag in [c for _, c in children]:
            contains.append(b)

    return contains


@time
def part1(bags):
    """
    To find the set of bags which contain a shiny gold bag, directly or indirectly, we start at
    the shiny gold bag and move backwards, and lookup all bags which contain it, then we look up
    all the bags that contain those bags, etc. While keeping track of the bags we have seen.
    """
    seen = set()
    to_check = deque(["shiny gold"])

    while to_check:
        b = to_check.pop()

        for bb in contains_bag(b, bags):
            seen.add(bb)
            to_check.append(bb)

    return len(seen)


@time
def part2(bags):
    """
    To find the number of bags that a bag contain, we start at our shiny gold bag, then iterate
    down through all the bags it contains, then the bags those bags contain, all while keeping
    track of the factor between the current bag and its parent, which we add to an accumulator.
    """
    to_check = deque([(1, "shiny gold")])
    acc = 0

    while to_check:
        v, b = to_check.pop()

        if e := bags.get(b):
            for bv, bb in e:
                factor = v * bv
                acc += factor
                to_check.append((factor, bb))

    return acc


def main():
    data = read_input("input.in")
    print(part1(data))
    print(part2(data))


if __name__ == "__main__":
    main()


real_input = read_input("input.in")
test1_input = read_input("test1.in")
test2_input = read_input("test2.in")

print("\ntesting...", file=sys.stderr)
assert part1(test1_input) == 4
assert part1(real_input) == 287
assert part2(test1_input) == 32
assert part2(test2_input) == 126
assert part2(real_input) == 48160
