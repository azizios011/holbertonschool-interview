#!/usr/bin/python3
"""
an n x n 2D matrix, rotate it 90 degrees clockwise.

"""


def rotate_2d_matrix(matrix):

    """
    rotate_2d_matrix - rotate a 2D matrix 90 degrees clockwise
    """

    n = len(matrix)

    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    for i in range(n):
        matrix[i].reverse()
