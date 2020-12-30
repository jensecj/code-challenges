from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.read()

    return data


def part1(data):
    go_up = data.count("(")
    go_down = data.count(")")

    return go_up - go_down


def part2(data):
    floor = 0

    pc = 0
    while floor >= 0:
        if data[pc] == "(":
            floor += 1
        elif data[pc] == ")":
            floor -= 1

        pc += 1

    return pc


def main():
    data = read_input("input.in")
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    main()


real_input = read_input("input.in")
assert part1(real_input) == 280
assert part2(real_input) == None
