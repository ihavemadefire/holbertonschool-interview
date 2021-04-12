#!/usr/bin/python3
"""
This module contains a function to count rain.
"""

def rain(walls):
    '''This function counts rain'''
    rain = 0
    l_max = 0
    r_max = 0
    low = 0
    high = len(walls) - 1
    if walls:
        i = 0
        while (low <= high):
            if(walls[low] < walls[high]):
                if(walls[low] > l_max):
                    l_max = walls[low]
                else:
                    rain+= l_max - walls[low]
                low += 1
            else:
                if(walls[high] > r_max):
                    r_max = walls[high]
                else:
                    rain+= r_max - walls[high]
                high -= 1
            i += 1
        return rain
    return 0