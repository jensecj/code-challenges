import os
import sys
import math
import timeit


def panic(msg):
    print(msg)
    sys.exit(1)


def deref(program, ptr):
    return program[program[ptr]]


def put(program, ptr, val):
    loc = program[ptr]
    program[loc] = val
    return program


def add(program, pc):
    # print(f"add: {pc}")
    p1 = deref(program, pc + 1)
    p2 = deref(program, pc + 2)
    put(program, pc + 3, p1 + p2)
    return pc + 4


def mul(program, pc):
    # print(f"mul: {pc}")
    p1 = deref(program, pc + 1)
    p2 = deref(program, pc + 2)
    put(program, pc + 3, p1 * p2)
    return pc + 4


def intcode_computer(program):
    pc = 0

    while pc < len(program):
        if program[pc] == 99:
            return program

        elif program[pc] == 1:
            pc = add(program, pc)

        elif program[pc] == 2:
            pc = mul(program, pc)

        else:
            print("something went wrong")
            break

        # print(program)

    # print("program terminated unusually")


def part1(input):
    input[1] = 12
    input[2] = 2
    program = intcode_computer(input)
    return program[0]


def part2(input):
    for i in range(0, 100):
        for j in range(0, 100):
            program = input.copy()
            program[1] = i
            program[2] = j
            # print(program)
            output = intcode_computer(program)
            if output and output[0] == 19690720:
                return (i, j), 100 * i + j


def main():
    if len(sys.argv) <= 1:
        panic("usage: python 02.py <input file>")

    input_file_path = str(sys.argv[1])

    if not os.path.isfile(input_file_path):
        panic("Cannot find input file: " + input_file_path)

    with open(input_file_path, "r") as input_file:
        input_data = input_file.read()

    input_data = input_data.split(",")
    input_data = [s for s in input_data if s]  # remove empty entries
    input_data = [int(s) for s in input_data]  # integer only input

    print(part1(input_data.copy()))  # 3562672
    print(part2(input_data.copy()))  # ((82, 50), 8250)


if __name__ == "__main__":
    main()
