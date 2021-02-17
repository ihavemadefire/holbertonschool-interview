#!/usr/bin/python3
'''DOCSTRING'''


def validUTF8(data):
    return False if max(data) >= 192 or min(data) <= 0 else True
