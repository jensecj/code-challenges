# tags: parsing

from itertools import accumulate
from collections import defaultdict

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.readlines()
        data = [d.strip() for d in data]
    return data


def calc_sizes(data):
    path = []
    sizes = defaultdict(int)
    for line in data:
        match line.split():
            case "$", "cd", "..":
                path.pop()
            case "$", "cd", d:
                path.append(d)
            case ["dir", _] | ["$", "ls"]:
                # we can ignore 'dir' lines, because we only care about the sizes of
                # directories, which we only get information about on 'ls' calls.  we can
                # ignore the 'ls' command, because each line with information about file sizes
                # must belong to the directory we last cd'ed into, unlike the real `ls', this
                # one takes no args.
                pass
            case size, _:
                # for each file, we add its size to the current dir, and all its parents
                # dont actually need the lambda here, because all paths are mysteriously unique
                for p in accumulate(path, lambda a, b: "/".join((a, b))):
                    sizes[p] += int(size)
    return sizes


def part1(data):
    sizes = calc_sizes(data)

    # find sums of all directories whose size is smaller then 100000
    return sum(v for v in sizes.values() if v <= 100000)


def part2(data):
    sizes = calc_sizes(data)

    used_space = sizes["/"]
    update_size = 70000000 - 30000000
    delete_size = used_space - update_size

    # find the smallest dir to delete to free up enough space to update
    return min(v for v in sizes.values() if v >= delete_size)


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    print(benchmark(part1, 50)(real_input))
    print(benchmark(part2, 50)(real_input))

    assert part1(test1_input) == 95437
    assert part2(test1_input) == 24933642
    assert part1(real_input) == 1423358
    assert part2(real_input) == 545729


if __name__ == "__main__":
    main()
