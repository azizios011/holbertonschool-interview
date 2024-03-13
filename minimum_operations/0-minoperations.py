#!/usr/bin/python3
"""
   Calculate the fewest number of operations needed to achieve 'n' 'H' characters in the file.
"""
def minOperations(n):
    if n <= 1:
        return 0

    # Initialize an array to store the minimum number of operations for each index
    dp = [float('inf')] * (n + 1)

    # Base case: It takes 0 operations to have 1 'H' in the file
    dp[1] = 0

    # Iterate through each index from 2 to n
    for i in range(2, n + 1):
        # Check if i is a divisor of n
        if n % i == 0:
            # If i is a divisor, calculate the minimum operations by copying i characters and pasting n // i times
            dp[i] = min(dp[i], dp[n // i] + n // i)

    # The final result is the minimum number of operations for n characters
    return dp[n] if dp[n] != float('inf') else 0
