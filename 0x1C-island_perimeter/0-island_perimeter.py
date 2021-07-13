#!/usr/bin/python3
"""
This module contains the island_perimeter function
"""

def island_perimeter(grid):
    """Returns the perimeter of the island in grid
    Args:
        grid: matrix of binary
    Returns: perimeter of island
    """
    ret = 0
    l = len(grid) - 1
    w = len(grid[0]) - 1

    for i, r in enumerate(grid):
        for j, n in enumerate(r):
            if n == 1:
                if i == 0 or grid[i - 1][j] != 1:
                    ret += 1
                if j == 0 or grid[i][j - 1] != 1:
                    ret += 1
                if j == w or grid[i][j + 1] != 1:
                    ret += 1
                if i == l or grid[i + 1][j] != 1:
                    ret += 1
    return ret
