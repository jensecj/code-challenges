# tags: simulation, bitmasking

from typing import Set

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


def bitstr(n: int, length: int = 36) -> str:
    """Convert N into a bitstring of LENGTH, padding with 0's as needed."""
    bits = f"{n:b}"
    assert length >= len(bits)

    bits = "0" * (length - len(bits)) + bits
    return bits


assert bitstr(1, 3) == "001"
assert bitstr(2, 3) == "010"
assert bitstr(3, 3) == "011"
assert bitstr(4, 3) == "100"
assert bitstr(42, 6) == "101010"
assert bitstr(42, 8) == "00101010"


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


def part1(data):
    memory = {}
    mask = "X" * 36

    for line in data:
        cmd, *rest = line

        if cmd == "mask":
            mask = rest[0]
        elif cmd == "mem":
            mem, val = rest
            m = overlay_mask(bitstr(val), mask, "X")
            memory[mem] = int(m, 2)

    return sum(memory.values())


def gen_masks_q(mask: str) -> Set[int]:
    """
    Generate all bitstring permutations of MASK, by essentiallty doing DFS,
    expanding masks until they contain no more X's, and collection the leaves.
    """
    q = [mask]
    locations = set()

    # iteratively generate all possible masks from MASK
    while q:
        m = q.pop()

        # a mask is complete once there are no more X's to replace
        if "X" not in m:
            locations.add(m)
        else:
            # for each X, replace it with both 0 and 1
            q.append(m.replace("X", "0", 1))
            q.append(m.replace("X", "1", 1))

    # remember to convert the bitstrings to integer memory locations
    return set(int(m, 2) for m in locations)


def gen_masks(mask: str) -> Set[int]:
    """
    Itertools.product can also be used to generate the bitstring permutations
    """
    args = [i.replace("X", "01") for i in list(mask)]  # mask -> product args
    permutations = list(it.product(*args))  # product args -> permutations
    s = ["".join(s) for s in permutations]  # permutations -> bit strings
    ns = [int(i, 2) for i in s]  # bit strings -> numbers

    return set(ns)


assert gen_masks(overlay_mask(bitstr(42, 6), "X1001X", "0")) == set([26, 27, 58, 59])
assert gen_masks(
    overlay_mask(bitstr(25508), "X1001X10000111001011X1001011X0010110", "0")
) == set(
    [
        20968074038,
        54254103350,
        19894364982,
        55327845174,
        20968106934,
        54254070710,
        20968106806,
        19894332342,
        54254103478,
        54254070582,
        19894365110,
        55327812534,
        19894332214,
        20968074166,
        55327812406,
        55327845302,
    ]
)


def part2(data):
    memory = {}
    mask = "0" * 36

    for line in data:
        cmd, *rest = line
        if cmd == "mask":
            mask = rest[0]
        elif cmd == "mem":
            mem, val = rest
            o = overlay_mask(bitstr(mem), mask, "0")
            for m in gen_masks(o):
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
