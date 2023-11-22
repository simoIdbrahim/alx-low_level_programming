#!/usr/bin/python3
""" Defines island_perimeter func"""


def island_perimeter(grid):
    """Return size

    Args:
        grid:list of list of int.
    Returns:
        The perimeter of the island.
    """
    the_width = len(grid[0])
    the_height = len(grid)
    size = 0
    edges = 0

    for i in range(the_height):
        for j in range(the_width):
            if grid[i][j] == 1:
                size += 1
                if j > 0 and grid[i][j - 1] == 1:
                    edges += 1
                if i > 0 and grid[i - 1][j] == 1:
                    edges += 1
    return size * 4 - edges * 2
