# tags: parsing

import math
import operator as op

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read().strip()
    return data


def parse_hex(h):
    t = {
        "0": "0000",
        "1": "0001",
        "2": "0010",
        "3": "0011",
        "4": "0100",
        "5": "0101",
        "6": "0110",
        "7": "0111",
        "8": "1000",
        "9": "1001",
        "A": "1010",
        "B": "1011",
        "C": "1100",
        "D": "1101",
        "E": "1110",
        "F": "1111",
    }
    return "".join(t[c] for c in h)


assert parse_hex("D2FE28") == "110100101111111000101000"
assert parse_hex("38006F45291200") == "00111000000000000110111101000101001010010001001000000000"


def read_literal(data):
    literal = ""
    while len(data) > 0:
        sign, data = data[0], data[1:]
        literal, data = literal + data[0:4], data[4:]
        if sign == "0":
            break
    return int(literal, 2), data


assert read_literal("101111111000101000") == (2021, "000")


def read_operator(data):
    """
    LengthTypeId
    L 0 -> next 15 bits are total length in bits of sub-packets
    L 1 -> next 11 bits are number of sub-packets
    """
    L, data = data[0], data[1:]
    subs = []

    if L == "0":
        bits, data = int(data[:15], 2), data[15:]
        # keep reading sub-packets until we have read the required number of bits
        start = len(data)
        while start - len(data) < bits:
            *pkg, data = read_packet(data)
            subs.append((*pkg, data))

    if L == "1":
        num, data = int(data[:11], 2), data[11:]
        for _ in range(num):
            *pkg, data = read_packet(data)
            subs.append((*pkg, data))

    return L, subs, data


def read_packet(data):
    """
    version (4 bits)
    id (4 bits)
    ---
    id 4    -> literal value (binary)
    id != 4 -> operator (with subpackets)
    """
    V, data = int(data[0:3], 2), data[3:]
    ID, data = int(data[0:3], 2), data[3:]
    subs = []
    if ID == 4:
        L, data = read_literal(data)
    else:
        L, subs, data = read_operator(data)

    return V, ID, L, subs, data


def count(packet):
    V, ID, L, subs, rest = packet
    return V + sum(count(pkg) for pkg in subs)


def part1(data):
    return count(read_packet(parse_hex(data)))


def value(packet):
    V, ID, L, subs, rest = packet

    dispatch = {
        0: sum,
        1: math.prod,
        2: min,
        3: max,
        4: lambda _: L,
        5: lambda p: op.gt(*p),
        6: lambda p: op.lt(*p),
        7: lambda p: op.eq(*p),
    }

    return dispatch[ID](value(s) for s in subs)


def part2(data):
    return value(read_packet(parse_hex(data)))


def main():
    real_input = read_input("input.in")

    assert part1("8A004A801A8002F478") == 16
    assert part1("620080001611562C8802118E34") == 12
    assert part1("C0015000016115A2E0802F182340") == 23
    assert part1("A0016C880162017C3686B18A3D4780") == 31
    assert part1(real_input) == 979
    print(benchmark(part1, 10)(real_input))

    assert part2("C200B40A82") == 3
    assert part2("04005AC33890") == 54
    assert part2("880086C3E88112") == 7
    assert part2("CE00C43D881120") == 9
    assert part2("D8005AC2A8F0") == 1
    assert part2("F600BC2D8F") == 0
    assert part2("9C005AC2F8F0") == 0
    assert part2("9C0141080250320F1802104A08") == 1
    assert part2(real_input) == 277110354175
    print(benchmark(part2, 10)(real_input))


if __name__ == "__main__":
    main()
