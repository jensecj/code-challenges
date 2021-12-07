# tags: graphs, topological sorting, priority queue
import re
import heapq
from collections import defaultdict

import networkx as nx
from compytetive.util import benchmark


def read_input(filename):
    with open(filename, "r", encoding="utf-8") as f:
        steps = []
        for a, b in re.findall(r"Step ([A-Z]) .* step ([A-Z])", f.read()):
            steps.append((a, b))

    return steps


def part1(data):
    succ = defaultdict(list)
    pred = defaultdict(list)

    # create a digraph representation
    for fro, to in data:
        succ[fro].append(to)
        pred[to].append(fro)

    Q = []

    # enqueue all ready tasks
    ready_tasks = set(succ.keys()) - set(pred.keys())
    for task in ready_tasks:
        heapq.heappush(Q, task)

    order = []
    while Q:
        # reached a ready task, append it to the topo order
        task = heapq.heappop(Q)
        order.append(task)

        for s in succ[task]:
            dependencies_cleared = all(p in order for p in pred[s])
            if s not in order and dependencies_cleared:
                heapq.heappush(Q, s)

    return "".join(order)


def part1_nx(data):
    G = nx.DiGraph(data)
    return "".join(nx.lexicographical_topological_sort(G))


def part2(data, penalty, workers):
    def task_cost(n):
        return penalty + ord(n) - ord("A") + 1

    G = nx.DiGraph(data)

    time = 0
    tasks = []
    while G:
        running = [task for (task, cost) in tasks]
        available = [task for task in G if task not in running]
        ready = [task for task in available if G.in_degree(task) == 0]

        # if there are tasks to do, and someone to do them, enqueue the tasks
        while ready and len(tasks) < workers:
            task = ready.pop(0)
            tasks.append((task, task_cost(task)))

        # when everyone has tasks to do, start completing them
        # starting with the one that requires the least amount of work
        work = min(cost for (task, cost) in tasks)

        # since we step `work' ahead in time, to remove completed tasks,
        # we need to choose all tasks that completed in that interval
        G.remove_nodes_from(task for (task, cost) in tasks if cost <= work)

        # update the work needed for the remaining tasks
        tasks = [(task, cost - work) for (task, cost) in tasks if cost > work]
        time += work

    return time


def main():
    test1_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test1_input) == "CABDFE"
    assert part1(real_input) == "EUGJKYFQSCLTWXNIZMAPVORDBH"
    assert part1_nx(test1_input) == "CABDFE"
    assert part1_nx(real_input) == "EUGJKYFQSCLTWXNIZMAPVORDBH"

    assert part2(test1_input, 0, 2) == 15
    assert part2(real_input, 60, 5) == 1014

    print(benchmark(part1, 50)(real_input))
    print(benchmark(part1_nx, 50)(real_input))
    print(benchmark(part2, 50)(real_input, 60, 5))


if __name__ == "__main__":
    main()
