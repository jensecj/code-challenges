# tags: parsing parens, stacks

from collections import deque

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.readlines()
        data = [d.strip() for d in data]
    return data


def part1(data):
    points = {")": 3, "]": 57, "}": 1197, ">": 25137}
    open_to_close = {"(": ")", "{": "}", "[": "]", "<": ">"}
    close_to_open = {v: k for k, v in open_to_close.items()}

    score = 0
    for line in data:
        stack = deque()
        for c in line:
            if c in "<{[(":
                stack.append(c)
            else:
                o = stack.pop()
                if o == close_to_open[c]:
                    continue

                score += points[c]
                break

    return score


def part2(data):
    points = {")": 1, "]": 2, "}": 3, ">": 4}
    open_to_close = {"(": ")", "{": "}", "[": "]", "<": ">"}
    close_to_open = {v: k for k, v in open_to_close.items()}

    scores = []
    for line in data:
        stack = deque()
        for c in line:
            if c in "<{[(":
                stack.append(c)
            else:
                o = stack.pop()
                if o != close_to_open[c]:
                    stack = None
                    break

        if not stack:
            continue

        score = 0
        while stack:
            e = stack.pop()
            score *= 5
            score += points[open_to_close[e]]
        scores.append(score)

    scores = sorted(scores)
    return scores[len(scores) // 2]


def main():
    test_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test_input) == 26397
    assert part1(real_input) == 464991
    print(benchmark(part1, 50)(real_input))

    assert part2(test_input) == 288957
    assert part2(real_input) == 3662008566
    print(benchmark(part2, 50)(real_input))


if __name__ == "__main__":
    main()
