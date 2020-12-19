# tags: dynamic programming

import re
from functools import lru_cache

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.read()
        raw_rules, raw_messages = data.split("\n\n")

        terminals = {}
        for name, term in re.findall(r'(\d+): "(\w)"', raw_rules):
            terminals[name] = term

        rules = {}
        for name, rule in re.findall(r"(\d+): ([\d |]+)", raw_rules):
            rules[name] = [r.split() for r in rule.split(" | ")]

        messages = [m.strip() for m in raw_messages.split("\n")]

    return rules, terminals, messages


# rules: Dict[str, List[List[str]]] = {0: [[4,1,5]], 1: [[2,3],[3,2]]}
# terminals: Dict[str, str] = {4: "a", 5: "b"}
# messages: List[str] = ["ababb", "abbabaa"]


def solve(rules, terminals, messages):
    def match_part(msg, beg, end, parts):
        # if there is no more message to look at,
        # and there are no more parts of a rule to match,
        # then we have successfully matched the message
        if beg == end and not parts:
            return True

        # if we reach the end of the message,
        # but we are still trying to match more of a rule,
        # then the match was unsuccessful
        if beg == end:
            return False

        # if there is more message,
        # but there are no more parts of a rule,
        # then the match is unsuccessful
        if not parts:
            return False

        # if there is more message to match, and more parts of a rule,
        # we try to recursively match the rest of the message
        # starting at the left-most part
        for i in range(beg + 1, end + 1):
            # check if the current part of the message matches the current part of the rule,
            # and if the rest of the message matches the rest of the rule
            if match(msg, beg, i, parts[0]) and match_part(msg, i, end, parts[1:]):
                return True

        return False

    @lru_cache(maxsize=None)
    def match(msg, beg, end, rule):
        # if the rule is a terminal, check if this part matches
        if rule in terminals:
            return msg[beg:end] == terminals[rule]

        # if the rule is not a terminal, it can have many parts
        # check if the message matches any part of the rule
        for parts in rules[rule]:
            if match_part(msg, beg, end, parts):
                return True

        return False

    valid = 0
    for msg in messages:
        # we only need to keep a cache per message,
        # this greatly reduces the memory required,
        # and saves on extra probing overhead
        match.cache_clear()

        # we start by looking for a match for the whole message, using rule 0
        if match(msg, 0, len(msg), "0"):
            valid += 1

    return valid


def part1(data):
    return solve(*data)


def part2(data):
    rules, terminals, messages = data

    rules["8"] = [["42"], ["42", "8"]]
    rules["11"] = [["42", "31"], ["42", "11", "31"]]

    return solve(rules, terminals, messages)


def main():
    benchmark(part1)(read_input("../input.in"))
    benchmark(part2)(read_input("../input.in"))

    # print(part1(read_input("../test1.in")))
    # print(part2(read_input("../test2.in")))


if __name__ == "__main__":
    main()

assert part1(read_input("../test1.in")) == 2
assert part2(read_input("../test2.in")) == 12

real_input = read_input("../input.in")
assert part1(real_input) == 182
assert part2(real_input) == 334
