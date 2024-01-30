#!/usr/bin/python3
"""define a method named 'canUnlockAll(boxes)'."""

def canUnlockAll(boxes):
    """a method that determines if all the boxes can be opened."""

    for key in range(1, len(boxes)):
        flag = False
        for box in range(len(boxes)):
            if key in boxes[box] and box != key:
                flag = True
                break
        if not flag:        
            return False

    return True
