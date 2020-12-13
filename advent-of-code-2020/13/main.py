import math
import itertools as it
import operator as op
from functools import reduce

from compytetive.util import benchmark


def is_prime(n):
    if n > 1:
        for i in range(2, n // 2):
            if (n % i) == 0:
                return False

    return True


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()
        arrival = int(data[0])
        # replace x's with -1
        data = [x.replace("x", "-1") for x in data]
        busses = [int(x) for x in data[1].split(",")]

        # NOTE: all bus periods are prime
        assert all([is_prime(n) for n in busses if n > 0])

    return arrival, busses


def part1(data):
    """
    Bruteforce approach.

    For each bus, calculate the first departure time that is later than our arrival time.
    """
    arrival, busses = data

    times = {}
    for bus in [b for b in busses if b > 0]:
        for t in it.count():
            if (b := bus * t) >= arrival:
                times[b] = bus
                break

    earliest_bus = min(times.keys())
    earliest_bus_id = times[earliest_bus]

    return (earliest_bus - arrival) * earliest_bus_id


def part1_faster(data):
    """
    For each bus, the next departure time can be calculated directly.
    """
    arrival, busses = data

    shortest_wait = math.inf
    earliest_bus = None

    # ignore all invalid busses from input
    for bus in [b for b in busses if b > 0]:
        # if bus b has a round-time of b, then by the time of our arrival,
        # the bus would have completed n=(arrival / b) rounds
        completed_rounds = math.ceil(arrival / bus)

        # the next departure time of the bus b, will then be
        # (bus round time * completed number of rounds)
        next_departure = completed_rounds * bus

        wait = next_departure - arrival
        if wait < shortest_wait:
            shortest_wait = wait
            earliest_bus = bus

    return shortest_wait * earliest_bus


def fits_busses(timestamp, busses):
    """
    Return True if TIMESTAMP is a valid start time for all BUSSESn,
    such that each subsequent bus j1,...jn takes off at timestamp+j1,...,timestamp+jn.

    This can be checked by seeing if the timestamp is evenly divided
    by the minute where the bus takes off (which is also its id).
    """
    for i, bus in enumerate(busses):

        if bus == -1:
            continue

        if (timestamp + i) % bus != 0:
            return False

    return True


assert fits_busses(1068781, [7, 13, -1, -1, 59, -1, 31, 19])

assert fits_busses(3417, [17, -1, 13, 19])
assert fits_busses(754018, [67, 7, 59, 61])
assert fits_busses(779210, [67, -1, 7, 59, 61])
assert fits_busses(1261476, [67, 7, -1, 59, 61])
assert fits_busses(1202161486, [1789, 37, 47, 1889])

assert fits_busses(1068781, [7, 13, -1, -1, 59, -1, 31, 19])


def part2_bruteforce(data):
    """
    For each possible take-off time for the first bus, check if the timestamp fits all other
    busses. (i.e bus+1 takes off at timestamp+1, ...)

    Not tennable, since the solution can end up in the 100,000,000,000,000 range.
    """
    _, busses = data

    earliest_bus = busses[0]
    for i in it.count(0):
        timestamp = earliest_bus * i

        if fits_busses(timestamp, busses):
            return timestamp

    return None


def part2(data):
    """
    Instead of bruceforcing, and trying all possible departure times for all timestamps,
    we realize that for each timestamp, we can can increase the step size for checking the
    next timestamp, because the next timestamp will need to be evenly divisible by the ones
    that have come before it, so we increase the step size with the lowest common multiple
    of the current step size, and the bus we have just found to fit.
    """
    _, busses = data

    timestamp = 0
    step = 1
    for i, bus in enumerate(busses):
        for timestamp in it.count(timestamp, step):
            if (timestamp + i) % bus == 0:
                break

        step = math.lcm(step, bus)

    return timestamp


def chinese_remainder(moduli, residues):
    """Return the unique solution N for the system of congruences from RESIDUES and MODULI."""
    total = 0
    N = reduce(op.mul, moduli)

    for m, r in zip(moduli, residues):
        p = N // m
        total += r * pow(p, -1, m) * p

    return total % N


def part2_crt(data):
    """
    The problem can also be solved using the Chinese Remainder Theorem, which stipulates that
    for a system of congruences where the moduli are coprime, there exists a single solution.
    """
    _, busses = data

    moduli = []
    residues = []
    for i, bus in enumerate(busses):
        if bus == -1:
            continue

        moduli.append(bus)
        residues.append(bus - i)

    return chinese_remainder(moduli, residues)


def main():
    data = read_input("input.in")

    print(benchmark(part1)(data))
    print(benchmark(part1_faster)(data))
    # print(part2_bruteforce(data))
    print(benchmark(part2)(data))
    print(benchmark(part2_crt)(data))


if __name__ == "__main__":
    main()


test1_input = read_input("test1.in")
assert part1(test1_input) == 295
assert part1_faster(test1_input) == 295

assert part2(test1_input) == 1068781
assert part2_crt(test1_input) == 1068781

assert part2((-1, [17, -1, 13, 19])) == 3417
assert part2((-1, [67, 7, 59, 61])) == 754018
assert part2((-1, [67, -1, 7, 59, 61])) == 779210
assert part2((-1, [67, 7, -1, 59, 61])) == 1261476
assert part2((-1, [1789, 37, 47, 1889])) == 1202161486

real_input = read_input("input.in")
assert part1(real_input) == 2095
assert part1_faster(real_input) == 2095

assert part2(real_input) == 598411311431841
assert part2_crt(real_input) == 598411311431841
