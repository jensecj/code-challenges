# tags: parsing

import re
from collections import defaultdict

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.readlines()
        data = [d.strip() for d in data]
    return data


def part1(data):
    i = 0
    path = []
    sizes = defaultdict(int)

    while i < len(data):
        cmd = data[i]
        if cmd == "$ cd ..":
            path.pop()
        elif c := re.search(r"\$ cd (.+)", cmd):
            path.append(c.group(1))
        elif cmd == "$ ls":
            # keep popping ls-lines until we hit the next command
            while i + 1 < len(data) and not data[i + 1].startswith("$"):
                i += 1
                # for each ls-line we update the size of the current directory
                # and all its parents, so we can just ignore 'dir' lines
                if data[i].startswith("dir"):
                    continue
                size = data[i].split(" ")[0]
                for r in range(len(path), 0, -1):
                    part = "/".join(path[:r])
                    sizes[part] += int(size)
        i += 1

    # find sums of all directories whose size is smaller then 100000
    val = 0
    for v in sizes.values():
        if v <= 100000:
            val += v

    return val


def part2(data):
    i = 0
    path = []
    sizes = defaultdict(int)

    while i < len(data):
        cmd = data[i]
        if cmd == "$ cd ..":
            path.pop()
        elif c := re.search(r"\$ cd (.+)", cmd):
            path.append(c.group(1))
        elif cmd == "$ ls":
            # keep popping ls-lines until we hit the next command
            while i + 1 < len(data) and not data[i + 1].startswith("$"):
                i += 1
                # for each ls-line we update the size of the current directory
                # and all its parents, so we can just ignore 'dir' lines
                if data[i].startswith("dir"):
                    continue
                size = data[i].split(" ")[0]
                for r in range(len(path), 0, -1):
                    part = "/".join(path[:r])
                    sizes[part] += int(size)
        i += 1

    used_space = sizes["/"]
    update_size = 70000000 - 30000000
    delete_size = used_space - update_size

    # find the smallest dir to delete to free up enough space to update
    target = 2147483647
    for v in sizes.values():
        if v >= delete_size:
            target = min(target, v)

    return target


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
