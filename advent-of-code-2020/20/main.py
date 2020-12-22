# tags: grid, greedy matching

from typing import Any, List, Dict, Callable

import re
import math
import operator as op
from collections import defaultdict
from functools import reduce

from compytetive.util import benchmark


TileID = int
Tile = List[str]
Edge = str
Grid = List[List[Any]]


def read_input(filename):
    with open(filename) as f:
        data = f.read()
        raw_tiles = data.split("\n\n")
        raw_tiles = [r.split("\n") for r in raw_tiles]

        tiles = defaultdict(list)
        for raw_tile in raw_tiles:
            tile_id = int(re.search(r"Tile (\d+):", raw_tile[0])[1])

            # NOTE: why are tiles parsed reversed?
            # we have to vertically flip the tiles to make sure they are right-side-up,
            # and why does it have any effect on the result?
            # without this part2 with real input fails
            tiles[tile_id] = tuple(raw_tile[1:][::-1])

        return tiles


def print_tile(tile: Tile) -> None:
    for row in tile:
        print(row)


def left_edge(tile: Tile) -> Edge:
    return "".join([line[0] for line in tile])


assert left_edge(["AB", "CD"]) == "AC"


def right_edge(tile: Tile) -> Edge:
    return "".join([line[-1] for line in tile])


assert right_edge(["AB", "CD"]) == "BD"


def top_edge(tile: Tile) -> Edge:
    return tile[0]


assert top_edge(["AB", "CD"]) == "AB"


def bottom_edge(tile: Tile) -> Edge:
    return tile[-1]


assert bottom_edge(["AB", "CD"]) == "CD"


def edges(tile: Tile) -> List[Edge]:
    """Return a list of edges of the current transform for TILE"""
    return [top_edge(tile), bottom_edge(tile), left_edge(tile), right_edge(tile)]


assert edges(["AB", "CD"]) == ["AB", "CD", "AC", "BD"]


def all_edges(tile: Tile) -> List[Edge]:
    """Return a list of edges for all transformations of TILE"""
    tile_edges = edges(tile)
    # the only transformation that can change out representation of a side,
    # is by rotating by 180°, which reverses the string
    tile_edges = tile_edges + [e[::-1] for e in tile_edges]

    return tile_edges


assert all_edges(["AB", "CD"]) == ["AB", "CD", "AC", "BD", "BA", "DC", "CA", "DB"]


def rotate_left(tile: Tile) -> Tile:
    """Return a tile which is a counter-clockwise view of TILE"""
    line_len = len(tile[0])

    lines = []
    for i in range(line_len):
        # the last element in the first line of the tile,
        # becomes the first element in the first line of the rotated tile,
        # and likewise, the last element of the second line,
        # becomes the second element of the first line
        newline = [line[line_len - i - 1] for line in tile]
        lines.append("".join(newline))

    return lines


_start = ["..#", "#..", ".#."]
assert rotate_left(_start) == ["#..", "..#", ".#."]
assert rotate_left(["#..", "..#", ".#."]) == [".#.", "..#", "#.."]
assert rotate_left([".#.", "..#", "#.."]) == [".#.", "#..", "..#"]
assert rotate_left([".#.", "#..", "..#"]) == _start


def flip_vertical(tile: Tile) -> Tile:
    """Return a tile which is the result of flipping TILE along the vertical axis"""
    return tile[::-1]


assert flip_vertical(["..#.#....#", "#...###..."]) == [
    "#...###...",
    "..#.#....#",
]
assert flip_vertical(["#...###...", "..#.#....#"]) == [
    "..#.#....#",
    "#...###...",
]


def flip_horizontal(tile: Tile) -> Tile:
    """Return a tile which is the result of flipping TILE along the horizontal axis"""
    return [t[::-1] for t in tile]


assert flip_horizontal(["..#.#....#", "#...###..."]) == [
    "#....#.#..",
    "...###...#",
]
assert flip_horizontal(["#....#.#..", "...###...#"]) == [
    "..#.#....#",
    "#...###...",
]


def all_transforms(tile: Tile) -> List[Tile]:
    """
    Return a list of all transforms of TILE
    """
    transforms = []

    # since we can't turn the image inside out,
    # there are only 8 states the image can end up in.
    # each of the front-face and back-face (mirrored) has 4 rotations.
    # flipping the tile turns the back-face up

    # get states in all front rotations of the tile

    rotated = tile
    for _ in range(4):
        rotated = rotate_left(rotated)
        transforms.append(rotated)

    # get states in back-face rotations of the tile
    transforms.append(flip_horizontal(tile))
    transforms.append(rotate_left(flip_horizontal(tile)))

    transforms.append(flip_vertical(tile))
    transforms.append(rotate_left(flip_vertical(tile)))

    # you could achieve the same result by only flipping either horizontally,
    # or vertically, and rotating 4 times

    assert len(transforms) == 8
    return transforms


_A = set()
for xf in all_transforms(["ABC", "DEF", "GHI"]):
    _A.add(tuple(xf))


_B = set()
for xf in all_transforms(flip_vertical(["ABC", "DEF", "GHI"])):
    _B.add(tuple(xf))

assert _A == _B


def build_edge_map(tiles: Dict[TileID, Tile]) -> Dict[Edge, List[TileID]]:
    """
    Return a mapping from edges to the tiles that have them
    """
    edge_map = defaultdict(list)

    for tile_id, tile in tiles.items():
        for edge in all_edges(tile):
            edge_map[edge].append(tile_id)

    return edge_map


def find_corners(tiles: Dict[TileID, Tile], edge_map: Dict[Edge, List[TileID]]) -> List[TileID]:
    """
    Return the ID's of the four corner tiles
    """
    corners = []
    for tile_id, tile in tiles.items():
        connections = 0
        for edge in edges(tile):
            connections += len(edge_map[edge]) - 1

        # a corner is a tile that has only two connections to other tiles,
        # (a side tile has 3, an inner tile has 4)
        if connections == 2:
            corners.append(tile_id)

    return corners


def part1(tiles: Dict[TileID, Tile]) -> int:
    """
    The simple way to solve this part is to notice that we're just looking for the four corners
    tiles, and we're told that all border tiles have sides that do not connect to any other
    tiles.

    This tells us that the four corner tiles will be the only four tiles that have two sides
    which to not connect to any other sides of any other tiles.

    We can generate all sides of all tiles, and for each tile, check now many edges do not
    connect to other tiles.
    """
    edge_map = build_edge_map(tiles)
    corners = find_corners(tiles, edge_map)

    return reduce(op.mul, corners)


def strip_borders(grid: Grid) -> Grid:
    """
    Return a grid of tiles, where each tile has its outer edges removed.
    """
    N = len(grid)
    stripped_grid = [[None] * N for _ in range(N)]

    for i, row in enumerate(grid):
        # skip the tile id
        for j, (_, tile) in enumerate(row):
            #                    remove top / bottom edges ↓
            # remove left / right edges ↓
            stripped_grid[i][j] = [t[1:-1] for t in tile[1:-1]]

    return stripped_grid


def tile_from_grid(grid: Grid) -> Tile:
    """Convert a grid of tiles into a single tile"""
    tile = []

    for row in grid:
        for i in range(len(row[0])):
            tile += ["".join(col[i] for col in row)]

    return tile


MONSTER = [
    "                  O ",
    "O    OO    OO    OOO",
    " O  O  O  O  O  O   ",
]


def check_monster_at(tile: Tile, x: int, y: int) -> bool:
    """Return true if there is a monster beginning at X,Y in TILE"""

    # this call takes up a lot of the time of the solution,
    # and since the monster and the map are each only made up of 2 symbols,
    # this can probably be optimized by using bitmasks

    for dy in range(len(MONSTER)):
        for dx in range(len(MONSTER[dy])):
            # if any index differs from a monster, there is no monster
            if MONSTER[dy][dx] == "O" and tile[y + dy][x + dx] != "#":
                return False

    # all indices match a monster, so there must be one
    return True


def count_monsters(tile: Tile) -> int:
    """Return the number of monsters found in TILE"""
    num_monsters = 0

    for t in all_transforms(tile):
        for y in range(len(t) - len(MONSTER)):
            for x in range(len(t) - len(MONSTER[0])):
                # Check if there's a monster starting at this position
                num_monsters += check_monster_at(t, x, y)

    return num_monsters


def match(
    tiles: Dict[TileID, Tile],
    edge_map: Dict[Edge, List[TileID]],
    tile_id: TileID,
    edge: Edge,
    edge_fn: Callable[[Tile], Edge],
):
    """
    Find some transform of a tile, M, such that it matches the tile T with TILE_ID.
    The match should at EDGE of T, and at the edge described by EDGE_FAN(M).
    """

    # find the tile that has an edge that match EDGE,
    # excluding the tile we're trying to match up against
    matching_tiles = [t for t in edge_map[edge] if t != tile_id]

    # we have been told that there is one unique matching for all tiles,
    # knowing this we can assemble the puzzle greedily, and avoid backtracking
    assert len(matching_tiles) == 1

    match_id = matching_tiles[0]
    match_tile = tiles[match_id]

    # find the transform of the tile that match EDGE
    for match_tile in all_transforms(match_tile):
        if edge == edge_fn(match_tile):
            break

    return match_id, match_tile


def part2(tiles: Dict[TileID, Tile]):
    edge_map = build_edge_map(tiles)
    corners = find_corners(tiles, edge_map)

    # we decide to start matching tiles from the top-left tile
    # any corner could be top-left, it just a matter of rotation and flipping,
    # so pick one of them, and rotate/flip it until the free edges face left/up
    corner = corners[0]
    top_left = tiles[corner]

    while len(edge_map[left_edge(top_left)]) == 2:
        top_left = rotate_left(top_left)

    # the number of tiles to an edge in the resulting grid
    N = int(math.sqrt(len(tiles)))

    # create an empty grid, and place our first tile in the top-left corner
    # each entry in the grid is a tuple of (TileID, Tile),
    # because we need to keep track of which transform of TileID we've used
    match_grid: List[List[Any]] = [[None] * N for _ in range(N)]
    match_grid[0][0] = corner, top_left

    # work through the columns and fill
    for col in range(0, N):
        # we only need to match columns > 0, because we place the first tile in column 0
        if col > 0:
            tile_id, tile = match_grid[col - 1][0]
            match_grid[col][0] = match(tiles, edge_map, tile_id, bottom_edge(tile), top_edge)

        # after placing the first tile at the left edge, we place each tile in the row
        for row in range(1, N):
            tile_id, tile = match_grid[col][row - 1]
            match_grid[col][row] = match(tiles, edge_map, tile_id, right_edge(tile), left_edge)

    stripped_grid = strip_borders(match_grid)
    big_tile = tile_from_grid(stripped_grid)
    num_monsters = count_monsters(big_tile)

    pounds = "".join(big_tile).count("#")
    monster_size = "".join(MONSTER).count("O")

    return pounds - monster_size * num_monsters


def main():
    data = read_input("test1.in")

    print(benchmark(part1)(data))
    print(benchmark(part2)(data))


if __name__ == "__main__":
    main()


test1_input = read_input("test1.in")
assert part1(test1_input) == 20899048083289
assert part2(test1_input) == 273

real_input = read_input("input.in")
assert part1(real_input) == 27803643063307
assert part2(real_input) == 1644
