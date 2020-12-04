import sys
from functools import reduce


def count_trees(slopes, x_step, y_step):
    H = len(slopes)
    W = len(slopes[0])

    x = 0
    y = 0

    trees = 0
    while y < H:
        if slopes[y][x] == "#":
            trees += 1

        y += y_step
        x = (x + x_step) % (W - 1)

    return trees


def main():
    input = sys.stdin.readlines()

    print(count_trees(input, 3, 1))  # part 1

    # part 2
    trees = [
        count_trees(input, 1, 1),
        count_trees(input, 3, 1),
        count_trees(input, 5, 1),
        count_trees(input, 7, 1),
        count_trees(input, 1, 2),
    ]
    print(reduce(lambda a, x: a * x, trees))


if __name__ == "__main__":
    main()
