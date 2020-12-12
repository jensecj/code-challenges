from typing import List, Tuple

from compytetive.algorithms import manhatten_dist
from compytetive.util import benchmark


Point = Tuple[int, int]
Command = Tuple[str, int]
Program = List[Command]
Direction = str

DIRECTIONS = ["N", "E", "S", "W"]


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()
        data = [(s[0], s[1:].strip()) for s in data]
        data = [(a, int(b)) for a, b in data]
    return data


def translate_move(heading: Direction, direction: Direction, value: int) -> Point:
    assert heading in DIRECTIONS
    assert direction in DIRECTIONS + ["F"]

    if direction == "F":
        direction = heading

    if direction == "N":
        return (0, value)
    if direction == "E":
        return (value, 0)
    if direction == "S":
        return (0, -value)
    if direction == "W":
        return (-value, 0)

    raise Exception("Unable to translate move")


assert translate_move("N", "F", 1) == translate_move("N", "N", 1) == (0, 1)
assert translate_move("N", "E", 1) == translate_move("E", "F", 1) == (1, 0)
assert translate_move("N", "S", 1) == (0, -1)
assert translate_move("N", "W", 1) == (-1, 0)


def change_direction(heading: Direction, direction: Direction, value) -> Direction:
    assert heading in DIRECTIONS
    assert direction in ["L", "R"]
    assert value % 90 == 0

    idx = DIRECTIONS.index(heading)
    turn = value // 90

    if direction == "L":
        turn = -turn

    return DIRECTIONS[(idx + turn) % len(DIRECTIONS)]


assert change_direction("N", "L", 90) == "W"
assert change_direction("N", "L", 180) == "S"
assert change_direction("W", "L", 90) == "S"
assert change_direction("S", "L", 90) == "E"
assert change_direction("E", "L", 90) == "N"

assert change_direction("N", "R", 90) == "E"
assert change_direction("N", "R", 360) == "N"
assert change_direction("N", "R", 180) == "S"
assert change_direction("E", "R", 90) == "S"
assert change_direction("S", "R", 90) == "W"
assert change_direction("W", "R", 90) == "N"


@benchmark
def part1(program):
    direction = "E"
    x, y = (0, 0)

    for cmd, value in program:
        if cmd in ["L", "R"]:
            direction = change_direction(direction, cmd, value)
        elif cmd in ["F", "N", "E", "S", "W", "B"]:
            nx, ny = translate_move(direction, cmd, value)
            x, y = x + nx, y + ny

    return manhatten_dist((0, 0), (x, y))


def rotate_point(point: Point, direction: Direction, value: int) -> Point:
    x, y = point

    if direction in "L":
        for _ in range(value // 90):
            x, y = -y, x

    elif direction == "R":
        for _ in range(value // 90):
            x, y = y, -x

    return x, y


assert (
    rotate_point((10, 4), "R", 0)
    == rotate_point((10, 4), "L", 0)
    == rotate_point((10, 4), "R", 360)
    == rotate_point((10, 4), "L", 360)
    == (10, 4)
)

assert rotate_point((10, 4), "R", 90) == rotate_point((10, 4), "L", 270) == (4, -10)
assert rotate_point((10, 4), "R", 180) == rotate_point((10, 4), "L", 180) == (-10, -4)
assert rotate_point((10, 4), "R", 270) == rotate_point((10, 4), "L", 90) == (-4, 10)


@benchmark
def part2(program):
    x, y = (0, 0)
    wx, wy = (10, 1)
    direction = "E"  # never changes in part2

    for cmd, value in program:
        if cmd in ["L", "R"]:
            wx, wy = rotate_point((wx, wy), cmd, value)
        elif cmd in DIRECTIONS:
            nx, ny = translate_move(direction, cmd, value)
            wx, wy = wx + nx, wy + ny
        elif cmd == "F":
            x, y = x + value * wx, y + value * wy

    return manhatten_dist((0, 0), (x, y))


@benchmark
def part2_complex(data):
    """
    The problem can also be solved using real numbers.
    A complex number multiplied with 1j (a complex number with an imaginary unit of 1),
    corresponds to a counter-clockwise rotation of 90°,
    a multiplication of -1j corresponds to a clockwise rotation of 90°.
    """
    ship = complex(0, 0)
    waypoint = complex(10, 1)

    for cmd, value in data:
        if cmd == "N":
            waypoint += complex(0, value)
        elif cmd == "S":
            waypoint += complex(0, -value)
        elif cmd == "E":
            waypoint += complex(value, 0)
        elif cmd == "W":
            waypoint += complex(-value, 0)
        elif cmd == "F":
            ship += waypoint * value
        elif cmd == "R":
            turns = value // 90
            rotation = complex(0, -1) ** turns
            waypoint *= rotation
        elif cmd == "L":
            turns = value // 90
            rotation = complex(0, 1) ** turns
            waypoint *= rotation

    return manhatten_dist((0, 0), (ship.real, ship.imag))


def main():
    data = read_input("input.in")
    print(part1(data))
    print(part2(data))
    print(part2_complex(data))


if __name__ == "__main__":
    main()


test1_input = read_input("test1.in")
assert part1(test1_input) == 25
assert part2(test1_input) == part2_complex(test1_input) == 286

real_input = read_input("input.in")
assert part1(real_input) == 1294
assert part2(real_input) == part2_complex(real_input) == 20592
