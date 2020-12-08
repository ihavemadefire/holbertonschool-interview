#!/usr/bin/python3
'''DOCSTRING'''


def canUnlockAll(boxes):
    # maintain a bool list of all rooms initialized to False
    # once visited, flip to true
    visited = [False] * len(boxes)
    # the first room is open
    visited[0] = True
    # make a stack of keys to be worked through for each room opened
    # Since the first room is open and to get the stack started we assign
    # the stack an initial value of 0
    stackKeys = [0]
    # are you still holding keys? Then loop!
    while stackKeys:
        # grab the key on top
        node = stackKeys.pop()
        # and go to that room
        # for each key found in the room opened by the previous key
        for nextKey in boxes[node]:
            # if we haven't been there before
            if not visited[nextKey]:
                # then flip the bool for that room
                visited[nextKey] = True
                # stick the next key on the pile
                stackKeys.append(nextKey)
    # return true or false of whole list
    return all(visited)
