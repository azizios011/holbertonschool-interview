#!/usr/bin/python3
"""
a program that solves the N queens problem.
"""
import sys


"""
a method that solves the N queens problem and
returns the result of the solution.
"""


def nqueens():
    if len(sys.argv) != 2:
        print("Usage: nqueens.py <number of queens>")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("<number of queens> must be a positive integer")
        sys.exit(1)
    if n < 1:
        print("<number of queens> must be a positive integer")
        sys.exit(1)
    board = []
    for i in range(n):
        board.append([0] * n)
    if not solve(board, 0):
        print("No solution")


"""
A method to give a solution to put
a the queens away from each other sigth.
"""


def solve(board, col):
    if col >= len(board):
        return True
    for row in range(len(board)):
        if is_safe(board, row, col):
            board[row][col] = 1
            if solve(board, col + 1):
                return True
            board[row][col] = 0
    return False


"""
a Method to check whether the given there's no
queen in the board by checking the row and col.
"""


def is_safe(board, row, col):
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, len(board), 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


if __name__ == "__main__":
    nqueens()
