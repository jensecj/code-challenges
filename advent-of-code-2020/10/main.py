import networkx as nx  # type: ignore
from compytetive.util import time
from collections import defaultdict


def read_input(filename):
    with open(filename) as f:
        data = f.readlines()
        data = [a.strip() for a in data]
        data = [int(a) for a in data]

    # each entry only cares about the entries that are within 3 jolts of it self,
    # so sorting make great sense
    return sorted(data)


def get_built_in_joltage(data):
    return max(data) + 3


@time
def part1(data):
    built_in_joltage = get_built_in_joltage(data)

    # append source and sink to the data
    data = [0] + data + [built_in_joltage]

    # since we need to maximize the number of adapters we pick, we can just always pick the
    # next available adapter, because that will be able to reach all the adapters that the
    # previous one could reach.
    d1 = d3 = 0
    for i in range(len(data) - 1):
        diff = data[i + 1] - data[i]
        d1 += 1 if diff == 1 else 0
        d3 += 1 if diff == 3 else 0

    return d1 * d3


def build_graph(data):
    """
    Build a directed graph from DATA.

    There will be no cycles in the resulting graph.
    Weights are negative because we want to maximize the number of adapters we pick, and thus pick
    the longest possible path.
    """
    G = nx.DiGraph()

    for n in data:
        for i in range(1, 4):
            if n + i in data:
                # since we need to take the longest path in the graph, to use as many adapters
                # as possible, we weigh the edges between nodes so a longer path is preferred
                G.add_edge(n, n + i, weight=-(3 - i))

    return G


@time
def part1_graph(data):
    """
    The problem can also be modeled as a graph, and solved using
    negative-weight shortest path.
    """
    built_in_joltage = get_built_in_joltage(data)

    # append source and sink to the data
    data = [0] + data + [built_in_joltage]

    G = build_graph(data)

    # use bellman-ford shortest path because we have edges with negative weights
    path = nx.bellman_ford_path(G, 0, built_in_joltage)

    d1 = d3 = 0
    for i in range(len(path) - 1):
        diff = path[i + 1] - path[i]
        d1 += 1 if diff == 1 else 0
        d3 += 1 if diff == 3 else 0

    return d1 * d3


@time
def part2(data):
    """
    The problem can be solved using dynamic programming.

    We know that the first adapter only has a single path to it,
    we then iterate through all other adapters in sorted order,
    the number of paths to an adapter is the sum of the paths to the three adapters
    that can reach it.
    """
    built_in_joltage = get_built_in_joltage(data)

    # append the final state
    data = data + [built_in_joltage]

    table = defaultdict(int)
    table[0] = 1

    for n in data:
        table[n] = table[n - 1] + table[n - 2] + table[n - 3]

    # NOTE: this is also commonly known as the 1-2-3 stairs dynamic-programming problem

    return table[built_in_joltage]


@time
def part2_graph(data):
    """
    This is the is the graph theoretic solution to the problem.

    NOTE: this is not tennable for the real challenge input, as noted in the problem, there exists
    a more efficient solution.
    """
    built_in_joltage = get_built_in_joltage(data)

    # append source and sink to the data
    data = [0] + data + [built_in_joltage]

    G = build_graph(data)

    paths = nx.all_simple_paths(G, 0, built_in_joltage)
    return len(list(paths))


def main():
    data = read_input("input.in")
    print(part1(data))
    print(part2(data))
    # print(part1_graph(data))
    # print(part2_graph(data))


if __name__ == "__main__":
    main()


test1_input = read_input("test1.in")
assert part1(test1_input) == part1_graph(test1_input) == 7 * 5
assert part2(test1_input) == part2_graph(test1_input) == 8

test2_input = read_input("test2.in")
assert part1(test2_input) == part1_graph(test2_input) == 22 * 10
assert part2_graph(test2_input) == 19208

real_input = read_input("input.in")
assert part1(real_input) == part1_graph(real_input) == 68 * 30
assert part2(real_input) == 28346956187648
