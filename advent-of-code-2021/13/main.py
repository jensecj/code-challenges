# tags: grid, counting

import re

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        points = set()
        for x, y in re.findall(r"(\d+),(\d+)", data):
            points.add((int(x), int(y)))

        axis = []
        for a, v in re.findall(r"fold along ([a-z])=(\d+)", data):
            axis.append((a, int(v)))
    return (points, axis)


def fold(points, axis, n):
    new_points = set()
    for x, y in points:
        if axis == "y" and y > n:
            new_points.add((x, n - (y - n)))
        elif axis == "x" and x > n:
            new_points.add((n - (x - n), y))
        else:
            new_points.add((x, y))

    return new_points


def part1(data):
    points, axis = data

    a, n = axis[0]
    points = fold(points, a, n)

    return len(points)


def part2(data):
    points, axis = data

    for a, n in axis:
        points = fold(points, a, n)

    minx = min(x for x, y in points)
    maxx = max(x for x, y in points)
    minx = min(y for x, y in points)
    maxy = max(y for x, y in points)
    for y in range(minx, maxy + 1):
        print("".join("█" if (x, y) in points else " " for x in range(minx, maxx + 1)))

    return len(points)


def main():
    test_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test_input) == 17
    assert part1(real_input) == 618
    print(benchmark(part1, 10)(real_input))

    assert part2(real_input) == 98  # number of points, not actual answer, ALREKFKO
    print(benchmark(part2)(real_input))


if __name__ == "__main__":
    main()
