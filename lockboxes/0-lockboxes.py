#!/usr/bin/python3


"""
Module for the canUnlockAll function
"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.

    Args:
    - boxes: A list of lists where each box contains keys to other boxes.

    Returns:
    - True if all boxes can be opened, else False.
    """
    for key in range(1, len(boxes)):
        flag = False
        for box in range(len(boxes)):
            if key in boxes[box] and box != key:
                flag = True
                break
        if not flag:
            return False

    return True
