#!/usr/bin/python3
"""
DOCSTRING
"""


def pascal_triangle(n):
    """
    Create a series of arrays representing
    pascal's triangle to level n
    """
    if n <= 0:
        return []
    if n == 1:
        return [[1]]

    prev_triangle = pascal_triangle(n - 1)
    last = prev_triangle[-1]

    current = []
    acc = 0
    for x in last:
        current.append(acc + x)
        acc = x
    current.append(1)

    prev_triangle.append(current)

    return prev_triangle
    