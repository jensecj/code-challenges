# tags: simulation

def read_input(filename):
    def _read():
        with open(filename) as f:
            data = f.readlines()
            data = [s.strip() for s in data]
            for cmd, val in [s.split() for s in data]:
                yield cmd, int(val)

    return list(_read())


def run(program):
    pc = 0
    acc = 0

    terminates = None
    seen = set()

    while True:
        # if we end up back at an instruction we have already executed, we are in a loop
        if pc in seen:
            terminates = False
            break

        # if the program tries to execute an instruction on the location after the end of the
        # program, treat it as the program terminating
        if pc == len(program):
            terminates = True
            break

        seen.add(pc)

        cmd, val = program[pc]

        if cmd == "acc":
            acc += val

        if cmd == "jmp":
            pc += val
            continue

        pc += 1

    return acc, terminates


def part1(program):
    """
    The program exits at the first sign of an infinite loop,
    so just return the accumulator in that state.
    """
    acc, _ = run(program)
    return acc


def part2(program):
    """
    Run through all instructions, and flip jmp <-> nop instructions as they occur,
    then run the changed program and check if it terminates.
    """
    for i in range(len(program)):
        P = program.copy()
        cmd, val = P[i]
        if cmd in ["nop", "jmp"]:
            cmd = "nop" if cmd == "jmp" else "jmp"
            P[i] = (cmd, val)
            acc, term = run(P)

            if term:
                return acc

    return None


def main():
    data = read_input("input.in")
    print(part1(data))
    print(part2(data))


if __name__ == "__main__":
    main()


real_input = read_input("input.in")
assert part1(real_input) == 1727
assert part2(real_input) == 552
