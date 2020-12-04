import sys
import itertools
from collections import Counter

from ubench import *


def generate_passwords(x, y):
    """
    Generate all number-only passwords of length 6,
    with subsequent numbers never decreasing
    """
    for a in range(int(x[0]), 10):
        for b in range(a, 10):
            for c in range(b, 10):
                for d in range(c, 10):
                    for e in range(d, 10):
                        for f in range(e, 10):
                            yield (a, b, c, d, e, f)


def check(x, y, a, b, c, d, e, f):
    """
    Check if the string a+b+c+d+e+f is a valid password

    a password is valid if it follows all of the following rules:
    rule #1: subsequent numbers must be never-decreasing
    rule #2: the number n=`abcdef' must be in range the range x < n < y
    rule #3: the password must contain at least one occurance where a digit repeats two or more times
    part 2 rule #4: the password must contain exactly one occurance where a digit repeats two times
    """
    if a <= b <= c <= d <= e <= f:  # rule #1

        valid_a = 0
        valid_b = 0
        s = f"{a}{b}{c}{d}{e}{f}"
        if int(x) <= int(s) <= int(y):  # rule #2

            # since the only legal chars in the password are numbers, and
            # each char must be the same or increasing, we can simply count
            # the occurance of each character

            # rule #3
            if any([s.count(chr) >= 2 for chr in set(s)]):
                valid_a += 1

            # part 2 rule #4
            if any([s.count(chr) == 2 for chr in set(s)]):
                valid_b += 1

        return valid_a, valid_b


@time
def main():
    input = sys.stdin.readline()
    x, y = input.split("-")

    valid_part2 = 0
    valid_part1 = 0

    for a, b, c, d, e, f in generate_passwords(x, y):
        v1, v2 = check(x, y, a, b, c, d, e, f)
        valid_part1 += v1
        valid_part2 += v2

    print(valid_part1)
    print(valid_part2)


if __name__ == "__main__":
    main()
