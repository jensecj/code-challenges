# tags: graphs, bipartite matching

import re
from collections import defaultdict

import networkx as nx  # type: ignore

from compytetive.util import benchmark


def read_input(filename):
    with open(filename) as f:
        data = f.read()

        lines = []
        for I_raw, A_raw in re.findall(r"([\w ]+) \(contains ([\w, ]+)\)", data):
            ingredients = set(i.strip() for i in I_raw.split())
            allergens = set(a.strip() for a in A_raw.split(","))

            lines.append((ingredients, allergens))

        return lines


def build_allergen_map(data):
    """
    Return a map from allagens to the ingredients that could have them
    """
    allergen_map = defaultdict(list)

    for ingredients, allergens in data:
        for a in allergens:
            allergen_map[a].append(ingredients)

    return allergen_map


def build_ingredients(data):
    """
    Return a set of all ingredients, and a list of all used ingredients,
    where each ingredient occurs the number of tiles it has been used
    """
    all_ingredients = []
    ingredients_set = set()

    for ingredients, _ in data:
        for i in ingredients:
            ingredients_set.add(i)
            all_ingredients.append(i)

    return ingredients_set, all_ingredients


def find_safe_ingredients(ingredients_set, allergen_map):
    # to find a set of safe ingredients
    # we start with the set of all ingredients
    safe_ingredients = ingredients_set
    for ingredients in allergen_map.values():
        # and remove the ones we know are bad
        cap = set.intersection(*ingredients)
        safe_ingredients -= cap

    return safe_ingredients


def build_graph(allergen_map):
    """
    Return a bipartite graph from allagens to the ingredients that could contain them
    """
    G = nx.DiGraph()

    for k, v in allergen_map.items():
        for a in v:
            G.add_edge(k, a)

    return G


def part1(data):
    allergen_map = build_allergen_map(data)
    ingredients_set, all_ingredients = build_ingredients(data)

    safe_ingredients = find_safe_ingredients(ingredients_set, allergen_map)

    # count the number of times a safe ingredient has been used
    count = 0
    for i in safe_ingredients:
        count += all_ingredients.count(i)

    return count


def part2(data):
    ingredients_set, _ = build_ingredients(data)
    allergen_map = build_allergen_map(data)

    safe_ingredients = find_safe_ingredients(ingredients_set, allergen_map)

    # construct a map of allergens -> dangerous ingredients,
    # where we remove all the ingredients we know are safe from the allergen map
    dangerous_map = {}
    for k in allergen_map.keys():
        dangerous_map[k] = set.intersection(*allergen_map[k]) - safe_ingredients

    # find a mapping from allergens -> dangerous ingredient
    G = build_graph(dangerous_map)
    matching = nx.bipartite.maximum_matching(G)

    # output the dangerous ingredients sorted by the allergen they contain
    output = []
    for k in sorted(allergen_map.keys()):
        output.append(matching[k])

    return ",".join(output)


def main():
    data = read_input("input.in")
    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    main()


test1_input = read_input("test1.in")
assert part1(test1_input) == 5
assert part2(test1_input) == "mxmxvkd,sqjhc,fvjkl"

real_input = read_input("input.in")
assert part1(real_input) == 2517
assert part2(real_input) == "rhvbn,mmcpg,kjf,fvk,lbmt,jgtb,hcbdb,zrb"
