import os
import sys
import math
import timeit


def get_fuel(mass):
    d = mass / 3
    r = math.floor(d)
    f = r - 2
    return f


assert get_fuel(12) == 2
assert get_fuel(14) == 2
assert get_fuel(1969) == 654
assert get_fuel(100756) == 33583


def part1(input):
    fuel = 0
    for m in input:
        fuel += get_fuel(m)

    return fuel


def get_inclusive_fuel(mass):
    # there's not really a need to optimize this, `get_fuel' trends down very, very quickly

    fuel = 0
    while True:
        f = get_fuel(mass)

        if f <= 0:
            break

        fuel += f
        mass = f

    return fuel


assert get_inclusive_fuel(14) == 2
assert get_inclusive_fuel(1969) == 966
assert get_inclusive_fuel(100756) == 50346


def part2(input):
    fuel = 0
    for m in input:
        fuel += get_inclusive_fuel(m)

    return fuel


def main():
    if len(sys.argv) <= 1:
        panic("usage: python 01.py <input file>")

    input_file_path = str(sys.argv[1])

    if not os.path.isfile(input_file_path):
        panic("Cannot find input file: " + input_file_path)

    with open(input_file_path, "r") as input_file:
        input_data = input_file.read()

    input_data = input_data.split("\n")
    input_data = [s for s in input_data if s]  # remove empty entries
    input_data = [int(s) for s in input_data]  # integer only input

    print(part1(input_data))
    print(part2(input_data))


if __name__ == "__main__":
    main()
