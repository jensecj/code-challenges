# tags: analysis, order-independent

import re
from collections import defaultdict, Counter

import compytetive as C
from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        template = re.search("[A-Z]+\n\n", data).group(0).strip()
        insertions = {}
        for f, t in re.findall("([A-Z]+) -> ([A-Z]+)", data):
            insertions[f] = t
    return (template, insertions)


def part1_naive(data):
    template, insertions = data
    for _ in range(10):
        idx = 0
        while idx < len(template) - 1:
            w = template[idx] + template[idx + 1]
            if w in insertions:
                before = template[: idx + 1]
                after = template[idx + 1 :]
                insertion = insertions[w]
                template = before + insertion + after
                idx += 1
            idx += 1
    c = Counter(template)
    return c.most_common()[0][1] - c.most_common()[-1][1]


# the naive solution will not work for part 2,
# which gives the hint that the the string will be larger than 10^12


def simulate(data, steps):
    """
    turns out we dont need to keep the entire string in memory,
    we just need to keep count of the number of pairs we have encountered.
    when we see a replacement 'AB -> C':
    - remove the 'AB' pair we break up by inserting a character in between
    - add the 'AC' and 'CB' pairs that are created
    and to speed things up at the end, we can also keep a count of the chars we insert,
    so we dont have to loop through all pairs and count their characters
    """
    template, insertions = data

    # count initial pairs in template
    pairs = defaultdict(int)
    for a, b in C.sliding_window(template, 2):
        pairs[a + b] += 1

    # count initial singles in template
    singles = defaultdict(int)
    for c in template:
        singles[c] += 1

    for _ in range(steps):
        # replace all matching pairs at the same time,
        # by incrementing/decrementing with `count'
        for (before, after), count in pairs.copy().items():
            replacement = insertions[before + after]
            pairs[before + after] -= count
            pairs[before + replacement] += count
            pairs[replacement + after] += count
            singles[replacement] += count

    return max(singles.values()) - min(singles.values())


def part1(data):
    return simulate(data, 10)


def part2(data):
    return simulate(data, 40)


def main():
    test_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1_naive(test_input) == 1588
    assert part1_naive(real_input) == 2360
    print(benchmark(part1_naive, 10)(real_input))

    assert part1(test_input) == 1588
    assert part1(real_input) == 2360
    print(benchmark(part1, 10)(real_input))

    assert part2(test_input) == 2188189693529
    assert part2(real_input) == 2967977072188
    print(benchmark(part2, 10)(real_input))


if __name__ == "__main__":
    main()
