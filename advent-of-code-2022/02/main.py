# tags: dictionary

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read().strip()
        data = data.split("\n")
    return data


rock, paper, scissors = 1, 2, 3
win, tie, lose = 6, 3, 0


def part1(data):
    # A, B, C = ROCK, PAPER, SCISSORS
    # X, Y, Z = ROCK, PAPER, SCISSORS
    # x,y,z tells us what hand we played, figure out if we won
    MOVES = {
        "A X": rock + tie,
        "A Y": paper + win,
        "A Z": scissors + lose,
        "B X": rock + lose,
        "B Y": paper + tie,
        "B Z": scissors + win,
        "C X": rock + win,
        "C Y": paper + lose,
        "C Z": scissors + tie,
    }
    return sum(MOVES[d] for d in data)


def part2(data):
    # A, B, C = ROCK, PAPER, SCISSORS
    # X, Y, Z = LOSE, TIE, WIN
    # x,y,z tells us how we want the game to end, pick hand based on it
    MOVES = {
        "A X": lose + scissors,
        "A Y": tie + rock,
        "A Z": win + paper,
        "B X": lose + rock,
        "B Y": tie + paper,
        "B Z": win + scissors,
        "C X": lose + paper,
        "C Y": tie + scissors,
        "C Z": win + rock,
    }
    return sum(MOVES[d] for d in data)


def main():
    test1_input = read_input("test1.in")
    real_input = read_input("input.in")

    print(benchmark(part1, 50)(real_input))
    print(benchmark(part2, 50)(real_input))

    assert part1(test1_input) == 15
    assert part2(test1_input) == 12
    assert part1(real_input) == 15632
    assert part2(real_input) == 14416


if __name__ == "__main__":
    main()
