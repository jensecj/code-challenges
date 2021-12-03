# tags: transpose, bits, popcount

import numpy as np
from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.readlines()
        data = [d.strip() for d in data]
    return data


def transpose(lst):
    return list(zip(*lst))


def part1(data):
    e = g = ""

    for t in transpose(data):
        zeroes = t.count("0")
        e += "0" if zeroes > len(t) / 2 else "1"
        g += "0" if zeroes <= len(t) / 2 else "1"

    return int(e, 2) * int(g, 2)


def part1_numpy(data):
    data = [list(d) for d in data]
    data = np.array(data, dtype=int)

    g = e = ""
    for c in data.T:
        counts = np.bincount(c)
        e += "1" if counts[1] > counts[0] else "0"
        g += "1" if counts[1] <= counts[0] else "0"

    return int(e, 2) * int(g, 2)


def part2(data):
    os = cs = data

    for i in range(len(data)):
        t = transpose(os)[i]
        zeroes = t.count("0")
        most = "0" if zeroes > len(t) / 2 else "1"
        os = [o for o in os if o[i] == most]
        if len(os) == 1:
            break

    for i in range(len(data)):
        t = transpose(cs)[i]
        zeroes = t.count("0")
        least = "0" if zeroes <= len(t) / 2 else "1"
        cs = [c for c in cs if c[i] == least]
        if len(cs) == 1:
            break

    return int(os[0], 2) * int(cs[0], 2)


def part2_numpy(data):
    data = [list(d) for d in data]
    data = np.array(data, dtype=int)

    os = cs = data

    for i in range(data.shape[1]):
        c = os.T[i]
        if c.shape[0] == 1:
            break

        counts = np.bincount(c)
        most = 0 if counts[0] > counts[1] else 1
        os = os[np.where(c == most)]

    for i in range(data.shape[1]):
        c = cs.T[i]
        if c.shape[0] == 1:
            break

        counts = np.bincount(c)
        least = 0 if counts[0] <= counts[1] else 1
        cs = cs[np.where(c == least)]

    # convert binary arrays to decimals
    os = os.dot(1 << np.arange(os.size)[::-1])[0]
    cs = cs.dot(1 << np.arange(cs.size)[::-1])[0]
    return os * cs


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    assert part1(test1_input) == 198
    assert part1_numpy(test1_input) == 198
    assert part2(test1_input) == 230
    assert part2_numpy(test1_input) == 230

    assert part1(real_input) == 3148794
    assert part1_numpy(real_input) == 3148794
    assert part2(real_input) == 2795310
    assert part2_numpy(real_input) == 2795310

    print(benchmark(part1, 10)(real_input))
    print(benchmark(part1_numpy, 10)(real_input))
    print(benchmark(part2, 10)(real_input))
    print(benchmark(part2_numpy, 10)(real_input))


if __name__ == "__main__":
    main()
