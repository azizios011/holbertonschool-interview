#!/usr/bin/python3
"""a method that calculates the fewest number of operations needed to result in exactly n H characters in the file. """
def minOperations(n):
    """A minOperations Method"""
    if n <= 1:
        return 0

    operations = 0
    factor = 2

    while factor * factor <= n:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    if n > 1:
        operations += n

    return operations
