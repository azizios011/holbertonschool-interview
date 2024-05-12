#!/usr/bin/python3
"""
This program solves the N queens problem, which involves placing N non-attacking queens on an N×N chessboard.
"""

import sys


def nqueens(N):
    """
    Solves the N queens problem and prints the solutions.
    """
    if not N.isdigit():
        print("N must be a number", file=sys.stderr)
        sys.exit(1)
    
    N = int(N)
    if N < 4:
        print("N must be at least 4", file=sys.stderr)
        sys.exit(1)
    
    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []
    solve(board, 0, solutions)
    if not solutions:
        print("No solution", file=sys.stderr)
        sys.exit(1)
    else:
        for solution in solutions:
            print(solution, file=sys.stderr)

    sys.exit(0)

def solve(board, col, solutions):
    """
    Recursively finds solutions to the N queens problem.
    """
    if col >= len(board):
        solutions.append([[i, j] for i, row in enumerate(board) for j, val in enumerate(row) if val == 1])
        return
    for row in range(len(board)):
        if is_safe(board, row, col):
            board[row][col] = 1
            solve(board, col + 1, solutions)
            board[row][col] = 0

def is_safe(board, row, col):
    """
    Checks whether it's safe to place a queen at the given position.
    """
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

