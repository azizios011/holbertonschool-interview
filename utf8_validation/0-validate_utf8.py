#!/usr/bin/python3
"""A method that determines if a given data set represents a valid UTF-8 encoding."""


def validUTF8(data):


    """Checks if the given data set represents a valid UTF-8 encoding."""
    num_bytes = 0

    for num in data:
        if num_bytes == 0:
            if num >> 7 == 0b0:
                continue
            elif num >> 4 == 0b1110:
                num_bytes = 2
            elif num >> 5 == 0b110:
                num_bytes = 1
            elif num >> 3 == 0b11110:
                num_bytes = 3
            else:
                return False
        else:
            if num >> 6 != 0b10:
                return False
            num_bytes -= 1

    return num_bytes == 0
