# tags: simulation

from copy import deepcopy

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.read().split("\n\n")
        data = [d.split("\n") for d in data]
        p1 = [int(i) for i in data[0][1:] if i]
        p2 = [int(i) for i in data[1][1:] if i]

        return p1, p2


def play_combat(p1, p2):
    while p1 and p2:
        p1c, p2c = p1.pop(0), p2.pop(0)

        if p1c > p2c:
            p1 += [p1c, p2c]
        else:
            p2 += [p2c, p1c]

    if p1:
        winner = p1
    else:
        winner = p2

    L = len(winner)
    P = 0
    for i in range(L):
        P += winner[i] * (L - i)

    return P


def part1(data):
    p1, p2 = deepcopy(data)

    return play_combat(p1, p2)


def play_recursive_combat(p1, p2):
    # each game has its own set of previously seen configurations
    prev = set()

    while 1:
        p1t = (1, tuple(p1))
        p2t = (2, tuple(p2))

        # if either player has a deck they have seen before, player 1 wins
        if p1t in prev or p2t in prev:
            return 1

        prev.add(p1t)
        prev.add(p2t)

        # if either player is out of cards, the other player wins
        if len(p2) == 0:
            return 1

        if len(p1) == 0:
            return 2

        p1c, p2c = p1.pop(0), p2.pop(0)

        # if both players have enough cards (>= the card they pulled)
        # play a sub-game with remaining cards
        if len(p1) >= p1c and len(p2) >= p2c:
            p1cs = p1[:p1c].copy()
            p2cs = p2[:p2c].copy()

            winner = play_recursive_combat(p1cs, p2cs)

            if winner == 1:
                p1 += [p1c, p2c]
            else:
                p2 += [p2c, p1c]

        # otherwise, play a normal round of combat
        else:
            if p1c > p2c:
                p1 += [p1c, p2c]
            else:
                p2 += [p2c, p1c]


def part2(data):
    p1, p2 = deepcopy(data)

    winner = play_recursive_combat(p1, p2)

    if winner == 1:
        winner = p1
    elif winner == 2:
        winner = p2

    L = len(winner)
    P = 0
    for i in range(L):
        P += winner[i] * (L - i)

    return P


def main():
    data = read_input("input.in")
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    main()


test1_input = read_input("test1.in")
assert part1(test1_input) == 306
assert part2(test1_input) == 291

real_input = read_input("input.in")
assert part1(real_input) == 33680
assert part2(real_input) == 33683
