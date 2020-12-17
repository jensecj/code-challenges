# tags: graph theory

import re

import networkx as nx  # type: ignore

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.read()
        raw_rules, raw_ticket, raw_others = data.split("\n\n")

        rules = []
        for rule in re.findall(r"(.+): (\d+)-(\d+) or (\d+)-(\d+)", raw_rules):
            a = set(range(int(rule[1]), int(rule[2]) + 1))
            b = set(range(int(rule[3]), int(rule[4]) + 1))
            rules.append((rule[0], a | b))

        my_ticket = re.search(r"your ticket:\s([\d,]+)", raw_ticket).group(1)
        my_ticket = [int(n) for n in my_ticket.split(",")]

        nearby_tickets = []
        for t in re.findall(r"([\d,]+)", raw_others):
            nearby_tickets.append(tuple(int(n) for n in t.split(",")))

        return rules, my_ticket, nearby_tickets


def part1(data):
    rules, _, tickets = data

    values = set.union(*[ranges for _, ranges in rules])

    errors = []
    for t in tickets:
        for n in t:
            if n not in values:
                errors.append(n)

    # print(f"{errors=}")
    return sum(errors)


def validate(rules, tickets):
    # create a single set which contain all ranges
    values = set.union(*[ranges for _, ranges in rules])

    # if a value in a ticket is a member of the big set, its a valid value
    valid = []
    for t in tickets:
        if set(t).issubset(values):
            valid.append(t)

    invalid = [t for t in tickets if t not in valid]

    return valid, invalid


_rules, *_, _tickets = read_input("test1.in")
# print(f"{validate(_rules, _tickets)=}")
assert validate(_rules, _tickets) == (
    [(7, 3, 47)],
    [(40, 4, 50), (55, 2, 20), (38, 6, 12)],
)

_rules, *_, _tickets = read_input("test2.in")
# print(f"{validate(_rules, _tickets)=}")
assert validate(_rules, _tickets) == ([(3, 9, 18), (15, 1, 5), (5, 14, 9)], [])


def transpose(coll):
    columns = []
    for i in range(len(coll[0])):
        C = set()
        for t in coll:
            C.add(t[i])

        columns.append(C)

    return columns


def bipartite_matching(rules, tickets):
    valid, invalid = validate(rules, tickets)

    # print(f"{tickets=}")
    # print(f"{invalid=}")
    # print(f"{valid=}")

    columns = transpose(valid)
    # print(f"{columns=}")

    G = nx.DiGraph()

    # if a column in nearby tickets is a subset of a rules range,
    # that column could belong to the rule,
    # so we create an edge from rule -> column in the bipartite graph
    for name, values in rules:
        for i, column in enumerate(columns):
            if column.issubset(values):
                G.add_edge(name, i)

    matching = nx.bipartite.maximum_matching(G)
    # print(f"{matching=}")

    return matching


def part2(data):
    rules, ticket, tickets = data
    matching = bipartite_matching(rules, tickets)

    prod = 1
    for d in [
        "departure location",
        "departure station",
        "departure platform",
        "departure track",
        "departure date",
        "departure time",
    ]:
        prod *= ticket[matching[d]]

    return prod


def main():
    data = read_input("input.in")
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))

    # print(part1(read_input("test1.in")))
    # print(part2(read_input("test2.in")))


if __name__ == "__main__":
    main()


assert part1(read_input("test1.in")) == 71
# assert part2(read_input("test2.in")) == 12 * 11 * 13

real_input = read_input("input.in")
assert part1(real_input) == 26941
assert part2(real_input) == 634796407951
