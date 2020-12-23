# tags: linked-list, circular

from compytetive.util import benchmark


class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next


def build_circular_list(coll):
    """
    Return a mapping from x in COLL to its node,
    nodes are connected via a next link, which forms a circular linked-list
    """
    previous = Node(coll[0])
    nodes = {}
    nodes[coll[0]] = previous

    for i in range(1, len(coll)):
        node = Node(coll[i])
        # create mapping from number to node,
        # then link previous Node to this Node,
        # then make this Node the next previous-node
        nodes[coll[i]] = previous.next = previous = node

    # complete the circle by making the last node point to the first one
    previous.next = nodes[coll[0]]

    return nodes


def play_cups(cups, rounds):
    end = max(cups)

    nodes = build_circular_list(cups)

    current = nodes[cups[0]]
    for _ in range(rounds):
        # pick the next three cups after the current one
        picks = [current.next, current.next.next, current.next.next.next]

        # remove the picks from the circle
        current.next = picks[-1].next

        # find the destination to insert picks
        # wrap around if we hit 0
        dest = current.value - 1 or end
        while nodes[dest] in picks:
            dest = dest - 1 or end

        destination = nodes[dest]

        # move nodes around so such that:
        # that the last node in picks point to the node after destination
        # destination points to the first point in picks
        picks[-1].next = destination.next
        destination.next = picks[0]

        current = current.next

    return nodes


def part1(cups):
    cups = [int(i) for i in cups]

    cups = play_cups(cups, 100)

    # start from the node after '1'
    node = cups[1].next

    # iterate through all links from '1' in the circle,
    # outputting the value of each node
    output = ""
    while node.value != 1:
        output += str(node.value)
        node = node.next

    return output


def part2(cups):
    cups = [int(i) for i in cups]

    # we start adding new cups after the highest cup in our starting list
    # each number from one to one million should be present
    start, end = max(cups), 1_000_000
    cups = cups.copy() + [*range(start + 1, end + 1)]

    nodes = play_cups(cups, 10_000_000)

    # return the product of the two nodes after '1'
    return nodes[1].next.value * nodes[1].next.next.value


def main():
    print(benchmark(part1)("318946572"))
    print(benchmark(part2)("318946572"))


if __name__ == "__main__":
    main()


assert part1("389125467") == "67384529"
assert part2("389125467") == 149245887792

assert part1("318946572") == "52864379"
assert part2("318946572") == 11591415792
