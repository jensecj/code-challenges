import sys


def read_line(line):
    """Format a CSV line into a list of commands."""
    return line.replace(",", " ").strip().split()


def get_points(p, cmd):
    """Generate all intermediate points resulting from applying CMD to the point P."""
    x, y = p
    C = cmd[0]
    n = int(cmd[1:])
    if C == "L":
        for i in range(1, n + 1):
            yield (x - i, y)
    elif C == "R":
        for i in range(1, n + 1):
            yield (x + i, y)
    elif C == "U":
        for i in range(1, n + 1):
            yield (x, y + i)
    elif C == "D":
        for i in range(1, n + 1):
            yield (x, y - i)


def manhatten_dist(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])


input = sys.stdin.readlines()

A = read_line(input[0])
B = read_line(input[1])

D = {}

steps = 0
cur = (0, 0)
for c in A:
    points = list(get_points(cur, c))
    cur = points[-1]

    for p in points:
        steps += 1
        # save the number of steps it took to get here, unless we have already been here
        if not D.get(p):
            D[p] = steps


cross_dists = []
cross_steps = []

steps = 0
cur = (0, 0)
for c in B:
    points = list(get_points(cur, c))
    cur = points[-1]

    for p in points:
        steps += 1

        # if this point already exists in D, this is a wire-crossing
        if s := D.get(p):
            # for each crossing we save the manhatten distance from the origin
            cross_dists.append(manhatten_dist((0, 0), p))
            # and the combined number of steps it took to get here
            cross_steps.append(s + steps)


print(min(cross_dists))  # part 1
print(min(cross_steps))  # part 2
