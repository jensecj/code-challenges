# tags: parsing, trees

from copy import copy

from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        data = f.read()
        data = [int(c) for c in data.split(" ")]
    return data


class Node:
    def __init__(self):
        self.children = []
        self.metadata = []


def eat_metadata(data):
    meta = data.pop(0)
    return meta


def eat_node(data):
    num_children = data.pop(0)
    num_metadata = data.pop(0)

    n = Node()
    for _ in range(num_children):
        n.children.append(eat_node(data))

    for _ in range(num_metadata):
        n.metadata.append(eat_metadata(data))

    return n


def part1(data):
    root = eat_node(copy(data))

    val = 0
    nodes = [root]
    while nodes:
        node = nodes.pop()
        val += sum(node.metadata)
        nodes.extend(node.children)

    return val


def value(n):
    if len(n.children) == 0:
        return sum(n.metadata)

    val = 0
    for i in n.metadata:
        if 0 <= i - 1 < len(n.children):
            val += value(n.children[i - 1])

    return val


def part2(data):
    root = eat_node(copy(data))
    return value(root)


def main():
    test_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test_input) == 138
    assert part1(real_input) == 40984
    print(benchmark(part1)(real_input))

    assert part2(test_input) == 66
    assert part2(real_input) == 37067
    print(benchmark(part2)(real_input))


if __name__ == "__main__":
    main()
