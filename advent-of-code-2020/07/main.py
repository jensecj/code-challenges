from collections import deque


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()

    for d in data:
        # split lines into (container, children)
        split = d.split("contain")

        # normalize the bag names
        split = [
            s.replace("bags.", "bag")
            .replace("bags", "bag")
            .replace("bag.", "bag")
            .strip()
            for s in split
        ]

        lhs = split[0].strip()  # the container bag
        rhs = [s.strip() for s in split[1].split(",")]  # the bags that it contains

        # indicate the bags which can hold no other bags
        rhs = rhs if "no other bag" not in rhs else None

        # convert bags representation into tuples of (bag, count) where count is the number of
        # times that the bag occurs
        rhs = [(s[2:], int(s[0])) for s in rhs] if rhs else None

        yield lhs, rhs


def bag_in_children(bag, cdr):
    return bag in [k for k, _ in cdr]


def contains_bag(bag, all_bags):
    """Return the subset of ALL_BAGS which contain BAG"""
    bags = []
    for k, v in all_bags:
        if v and bag_in_children(bag, v):
            bags.append(k)

    return bags


def part1(data):
    """
    To find the set of bags which, in any way, contain a shiny gold bag,
    we start at the shiny gold bag and move backwards, and lookup all bags which contain it,
    then we look up all the bags that contain those bags, etc.
    keeping track of the bags we have seen.
    """
    seen = set()
    to_check = deque(["shiny gold bag"])
    while to_check:
        b = to_check.pop()
        for bb in contains_bag(b, data):
            seen.add(bb)
            to_check.append(bb)

    return len(seen)


def part2(data):
    """
    To find the number of bags that a bag contain, we start at our shiny gold bag, then iterate
    down through all the bags it contains, then the bags those bags contain, all while keeping
    track of the factor between the current bag and its parent, which we add to an accumulator.
    """
    d = dict(data)

    to_check = deque([("shiny gold bag", 1)])

    acc = 0
    while to_check:
        k, v = to_check.pop()
        # print(f"current: {k}")

        if e := d.get(k):
            for bb, bv in e:
                # print(f"contains {bv} {bb}")
                factor = v * bv
                acc += factor
                to_check.append((bb, factor))

    return acc


def main():
    data = list(read_input("input.in"))
    print(part1(data))
    print(part2(data))


if __name__ == "__main__":
    main()
