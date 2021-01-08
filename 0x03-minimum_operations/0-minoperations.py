#!/usr/bin/python3
"""Docstring"""


def minOperations(n):
    ret = 0
    for i in range(2, n):
        while n % i == 0:
            ret += i
            n = n / i
    return ret
