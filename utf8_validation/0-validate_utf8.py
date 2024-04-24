#!/usr/bin/python3
"""
    a method that determines if a given data
    set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    num_bytes = 0

    for num in data:

        num &= 0xFF

        if num_bytes == 0:
            if num >> 7 == 0b00:

                continue

            elif num >> 3 == 0b11110:
                num_bytes = 3
            elif num >> 4 == 0b1110:
                num_bytes = 2
            elif num >> 5 == 0b110:
                num_bytes = 1
            else:
                return False
        for _ in range(num_bytes):
            num = next(data, None)
            if num in None or num >> 6 != 0b10:
                return False

    return num_bytes == 0
