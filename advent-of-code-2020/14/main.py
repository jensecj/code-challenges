# tags: simulation, bitmasking

from typing import Generator

import re
import itertools as it

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()
        commands = []
        for line in data:
            if cmd := re.search(r"^mask = ([01X]+)$", line):
                commands.append(("mask", cmd.group(1)))
            elif cmd := re.search(r"^mem\[(\d+)\] = (\d+)$", line):
                commands.append(("mem", int(cmd.group(1)), int(cmd.group(2))))

    return commands


def int_to_bitstring(n: int, length: int = 36) -> str:
    """Convert N into a bitstring of LENGTH, padding with 0's as needed."""
    return f"{n:0{length}b}"


def bitstring_to_int(bits: str) -> int:
    return int(bits, 2)


def overlay_mask(mask: str, overlay: str, ignore: str) -> str:
    """Place OVERLAY over MASK, ignoring bits in MASK where bit == IGNORE."""
    assert len(mask) == len(overlay)

    bits = list(mask)
    for i, bit in enumerate(overlay):
        if bit != ignore:
            bits[i] = bit

    return "".join(bits)


assert overlay_mask("101010", "X1001X", "0") == "X1101X"
assert overlay_mask("101010", "X1001X", "X") == "110010"


def make_or_mask(mask: str):
    return int(mask.replace("X", "0"), 2)


def make_and_mask(mask: str):
    return int(mask.replace("1", "0").replace("X", "1"), 2)


def int_bitmask(n: int, mask: str):
    return (n & make_and_mask(mask)) | make_or_mask(mask)


def part1(data):
    memory = {}
    mask = "X" * 36

    for line in data:
        cmd, *rest = line

        if cmd == "mask":
            mask = rest[0]
        elif cmd == "mem":
            mem, val = rest
            m = overlay_mask(int_to_bitstring(val), mask, "X")
            memory[mem] = int(m, 2)
            # memory[mem] = int_bitmask(val, mask)

    return sum(memory.values())


def gen_masks_q(mask: str) -> Generator[int, None, None]:
    """
    Generate all bitstring permutations of MASK, by essentiallty doing DFS,
    expanding masks until they contain no more X's, and collection the leaves.
    """
    q = [mask]

    # iteratively generate all possible masks from MASK
    while q:
        m = q.pop()

        # a mask is complete once there are no more X's to replace
        if "X" not in m:
            yield int(m, 2)
        else:
            # for each X, replace it with both 0 and 1
            q.append(m.replace("X", "1", 1))
            q.append(m.replace("X", "0", 1))


def gen_masks_p(mask: str) -> Generator[int, None, None]:
    """
    Itertools.product can also be used to generate the bitstring permutations
    """
    args = [i.replace("X", "01") for i in list(mask)]
    for p in it.product(*args):
        yield int("".join(p), 2)


def gen_masks_b(mask: str) -> Generator[int, None, None]:
    """
    The permutations can also be enumerated directly as integers using bitwise operators.
    """
    omask = make_or_mask(mask)
    amask = make_and_mask(mask)

    n = 0

    yield n | omask
    while n := (n + ~amask + 1) & amask:
        yield n | omask


# print("gen_masks_b(X1001X) =\t%s" % [*gen_masks_b("X1001X")])
# print("correct =\t\t%s" % [int(s, 2) for s in ["010010", "010011", "110010", "110011"]])
# print("correct =\t\t%s" % [int_to_bitstring(i, 6) for i in gen_masks_b("X1001X")])

M = "X1001X"
R = [18, 19, 50, 51]

assert list(gen_masks_q(M)) == R
assert list(gen_masks_p(M)) == R
assert list(gen_masks_b(M)) == R


M = "X1001X10000111001011X1101011X0110110"
R = [
    19894332214,
    19894332342,
    19894364982,
    19894365110,
    20968074038,
    20968074166,
    20968106806,
    20968106934,
    54254070582,
    54254070710,
    54254103350,
    54254103478,
    55327812406,
    55327812534,
    55327845174,
    55327845302,
]

assert list(benchmark(gen_masks_q)(M)) == R
assert list(benchmark(gen_masks_p)(M)) == R
assert list(benchmark(gen_masks_b)(M)) == R


def part2(data):
    memory = {}
    mask = "0" * 36

    for line in data:
        cmd, *rest = line
        if cmd == "mask":
            mask = rest[0]
        elif cmd == "mem":
            mem, val = rest
            o = overlay_mask(int_to_bitstring(mem), mask, "0")
            for m in gen_masks_b(o):
                memory[m] = val

    return sum(memory.values())


def main():
    data = read_input("input.in")
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    main()


assert part1(read_input("test1.in")) == 165
assert part2(read_input("test2.in")) == 208

real_input = read_input("input.in")
assert part1(real_input) == 13105044880745
assert part2(real_input) == 3505392154485
