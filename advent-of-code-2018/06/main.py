# tags: grid, manhatten distance

import re
import numpy as np
from scipy.spatial import distance
import compytetive as C
from compytetive.util import benchmark


def read_input(filename):
    points = np.loadtxt(filename, delimiter=", ", dtype=int)
    return (points, list(points))


def part1(data):
    array, points = data

    # create a grid that fits all points
    max_x, max_y = array.max(axis=0) + 2
    grid = np.zeros((max_y + 1, max_x + 1), dtype=int)

    for i, (x, y) in enumerate(points, 1):
        grid[y, x] = i

    rows, columns = grid.shape
    for y in range(0, rows):
        for x in range(0, columns):
            best = np.inf
            best_i = -1
            # for x,y in grid, calculate the manhatten distance to all points
            for i, p in enumerate(points, 1):
                dist = C.manhatten_dist((x, y), p)
                if dist < best:
                    best = dist
                    best_i = i
                # if multiple points reach the same x,y in the same distance, null it.
                elif dist == best:
                    best_i = -1
            grid[y, x] = best_i

    # remove infinite regions
    # all x,y on the edge of the grid reach out into infinity,
    # so any point that can reach the edge, covers an infinite region.
    borders = np.hstack([grid[0], grid[-1], grid[:, 0], grid[:, -1]])
    borders = np.unique(borders)
    grid[np.isin(grid, borders)] = 0

    # find the biggest region of the remaining points, discarding the nulled points
    bins = np.bincount(grid.ravel())
    return np.max(bins[1:])


def part1_alt(data):
    array, points = data

    max_x, max_y = array.max(axis=0)
    grid = np.zeros((max_y + 1, max_x + 1), dtype=int)

    for i, (x, y) in enumerate(points, 1):
        grid[y, x] = i

    while points:
        seen = set()
        next_points = []
        for x, y in points:
            i = grid[y, x]
            for nx, ny in C.neighbours(x, y, C.DIRECTIONS_STRAIGHT):
                if 0 <= nx <= max_x and 0 <= ny <= max_y:
                    # if a neighbour has not been marked or seen before,
                    # mark it by the point that reached it,
                    # and add it to the next iteration
                    if grid[ny, nx] == 0:
                        grid[ny, nx] = i
                        seen.add((nx, ny))
                        next_points.append((nx, ny))
                    # otherwise, if a neighbour is reached by multiple points, null it
                    elif grid[ny, nx] != i and (nx, ny) in seen:
                        grid[ny, nx] = -1
        points = next_points

    # ignore all regions that can reach the border
    borders = np.hstack([grid[0], grid[-1], grid[:, 0], grid[:, -1]])
    borders = np.unique(borders)
    grid[np.isin(grid, borders)] = 0
    # count up remaining regions, and return the largest
    bins = np.bincount(grid.ravel())
    return np.max(bins[1:])


def part1_numpy(data):
    array, points = data
    null = len(points) + 1

    # create grid that fits our data
    min_x, min_y = array.min(axis=0) - 1
    max_x, max_y = array.max(axis=0) + 2
    ygrid, xgrid = np.mgrid[min_x:max_x, min_y:max_y]
    # roll all grid points into a 1d array
    grid_points = np.dstack([xgrid, ygrid]).reshape(-1, 2)
    # calculate L1 distance between ids and all points on grid
    manhatten = distance.cdist(array, grid_points, metric="cityblock")

    # the resulting array is (ids, grid_points)
    grid = np.argmin(manhatten, axis=0)

    # null points on the grid that are rechable from input points in the same distance
    distances = np.min(manhatten, axis=0)
    overlaps = (manhatten == distances).sum(axis=0) > 1
    grid[overlaps] = null

    # all points around the edge continue out into the infinite,
    # so any id that can reach the edge, covers an infinite region
    # null points where multiple ids reach it in the same distance
    grid = grid.reshape((max_x - min_x, max_y - min_y))
    edge = np.concatenate([grid[0], grid[-1], grid[:, 0], grid[:, -1]])
    infinities = np.unique(edge)
    grid[np.isin(grid, infinities)] = null

    # index out null before picking the largest region
    bins = np.bincount(grid.ravel())
    return np.max(bins[:-1])


def part2(data, gap):
    array, points = data
    max_x, max_y = array.max(axis=0) + 2
    grid = np.zeros((max_y + 1, max_x + 1), dtype=int)

    # for every point in grid sum the manhatten distance to all points in input
    rows, columns = grid.shape
    for y in range(0, rows):
        for x in range(0, columns):
            for p in points:
                grid[y, x] += C.manhatten_dist((x, y), p)

    # find the region of values < gap,
    # this will be centered around the median of the input points
    grid[grid >= gap] = 0
    return np.count_nonzero(grid)


def part2_numpy(data, gap):
    array, _ = data

    min_x, min_y = array.min(axis=0) - 1
    max_x, max_y = array.max(axis=0) + 2
    ygrid, xgrid = np.mgrid[min_x:max_x, min_y:max_y]
    grid_points = np.dstack([xgrid, ygrid]).reshape(-1, 2)

    manhatten = distance.cdist(array, grid_points, metric="cityblock")

    # sum the L1 distance for each possible grid point
    distances = manhatten.sum(axis=0)

    # we just need the size of the region,
    # so mark any point in the region, and count it's size
    return np.where(distances < gap, 1, 0).sum()


def main():
    test_input = read_input("test.in")
    real_input = read_input("input.in")

    assert part1(test_input) == 17
    assert part1_alt(test_input) == 17
    assert part1_numpy(test_input) == 17
    assert part1(real_input) == 3293
    assert part1_alt(real_input) == 3293
    assert part1_numpy(real_input) == 3293
    print(benchmark(part1)(real_input))
    print(benchmark(part1_alt)(real_input))
    print(benchmark(part1_numpy, 10)(real_input))

    assert part2(test_input, 32) == 16
    assert part2_numpy(test_input, 32) == 16
    assert part2(real_input, 10000) == 45176
    assert part2_numpy(real_input, 10000) == 45176
    print(benchmark(part2)(real_input, 10000))
    print(benchmark(part2_numpy, 10)(real_input, 10000))


if __name__ == "__main__":
    main()
