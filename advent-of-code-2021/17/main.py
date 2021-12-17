# tags: simulation, analysis

import re
from math import sqrt

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read().strip()
        xs = re.search(r"x=(-?\d+)\.\.(-?\d+)", data)
        ys = re.search(r"y=(-?\d+)\.\.(-?\d+)", data)
    return (int(xs.group(1)), int(xs.group(2)), int(ys.group(1)), int(ys.group(2)))


def simulate(data):
    min_x, max_x, min_y, max_y = data
    P = []

    # the art is in tightening the bounds
    # for x:
    #  any velocity in n*(n+1)/2 < min_x will never hit
    #  any velocity greater than max_x will shoot past
    # for y:
    #  any velocity lower than min_y will shoot below area
    #  when shooting up, the drone comes back down with opposite velocity
    #  any velocity where the returning velocity is greater than -min_y will overshoot the area
    for x in range(round(sqrt(min_x * 2)), max_x + 1):
        # NOTE: min_y is negative in the input, so y is growing
        for y in range(min_y, -min_y):
            px, py, vx, vy = 0, 0, x, y
            path = [(0, 0)]
            hit = False
            while px <= max_x and py >= min_y:
                px, py = px + vx, py + vy
                path.append((px, py))
                if min_x <= px <= max_x and min_y <= py <= max_y:
                    hit = True
                    break

                if vx > 0:
                    vx -= 1
                elif vx < 0:
                    vx += 1
                vy -= 1

            if hit:
                P.append(path)
    return P


def part1(data):
    P = simulate(data)
    highest = 0
    for p in P:
        highest = max(highest, max(y for x, y in p))
    return highest


def part2(data):
    P = simulate(data)
    return len(P)


def main():
    test_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test_input) == 45
    assert part1(real_input) == 30628
    print(benchmark(part1)(real_input))

    assert part2(test_input) == 112
    assert part2(real_input) == 4433
    print(benchmark(part2)(real_input))


if __name__ == "__main__":
    main()
