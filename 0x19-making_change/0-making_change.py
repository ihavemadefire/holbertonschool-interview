#!/usr/bin/python3
""" This module makes change """


def makeChange(coins, total):
    """ 
    this funtion determines the lowest number of coins needed
    to make change given a random pile of coins.
    """
    if total <= 0:
        return 0
    change = 0
    count = 0
    i = 0
    sorted_ = sorted(coins, reverse=True)
    # loop over each coin as long as less than total 
    while(change < total and i < len(coins)):
        if (change + sorted_[i] <= total):
            change += sorted_[i]
            count += 1
        else:
            i += 1
    if change == total:
        return count
    return -1