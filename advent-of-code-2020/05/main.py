import sys


def decode_seat(seat):
    """decode a seat-string into a seat (row,column,id)"""

    # we can directly convert the seat string into its location because it already uses a
    # binary partitioning system for locating seats
    front = seat[:7].replace("B", "1").replace("F", "0")
    back = seat[-3:].replace("R", "1").replace("L", "0")

    row = int(front, 2)
    col = int(back, 2)
    return row, col, (row * 8) + col


assert decode_seat("FBFBBFFRLR") == (44, 5, 357)  # row 44, column 5, seat ID 357
assert decode_seat("BFFFBBFRRR") == (70, 7, 567)
assert decode_seat("FFFBBBFRRR") == (14, 7, 119)
assert decode_seat("BBFFBBFRLL") == (102, 4, 820)

assert decode_seat("FFFFFFFLLL") == (0, 0, 0 * 8)
assert decode_seat("BBBBBBBLLL") == (127, 0, 127 * 8)
assert decode_seat("FBBBBBBLLL") == (63, 0, 63 * 8)

assert decode_seat("BBBFBBBRRR") == (119, 7, 119 * 8 + 7)


def read_input():
    input = sys.stdin.readlines()
    for s in input:
        yield decode_seat(s.strip())


def part1(input):
    """Return the seat with the highest Seat ID"""
    return max(input, key=lambda x: x[-1])


def part2(input):
    """
    Return the empty seat somewhere in the plane,
    but not in the beginning or end of the plane
    """

    # this problem only needs to work on the seat ids
    s = set([i[-1] for i in input])

    # the empty seat must be between two occupied seats, this way it is also not in the
    # beginning of the end of the plane, because we know there are occupied seats before or
    # after our seat
    for i in s:
        if (i + 1) not in s and (i + 2) in s:
            return i + 1
        if (i - 1) not in s and (i - 2) in s:
            return i - 1


def main():
    input = list(read_input())
    print(part1(input))
    print(part2(input))


if __name__ == "__main__":
    main()
