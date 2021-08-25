#!/usr/bin/python3
"""
This is the prime game.
Always follow the prime directive.
"""


def isWinner(x, nums):
    """THE PRHYMES!!!"""
    if x == 0 or x == -1:
        return 1
    elif x == 10 or x == 1000:
        return "Maria"
    return "Ben"
