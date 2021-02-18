#!/usr/bin/python3
'''DOCSTRING'''


def validUTF8(data):
    flag = 0

    for i in data:
        flat = i & 0b00000000000000000000000011111111
        if (flat > 0 and flat < 255):
            flag += 0
        else:
            flag += 1

    if flag > 0:
        return False
    else:
        return True
