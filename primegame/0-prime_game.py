#!/usr/bin/python3

def sieve_of_eratosthenes(max_n):
    """
    Generates a list of primes up to
    max_n using the Sieve of Eratosthenes
    """
    is_prime = [True] * (max_n + 1)
    is_prime[0] = is_prime[1] = False  # 0 and 1 are not primes

    for i in range(2, int(max_n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, max_n + 1, i):
                is_prime[j] = False

    primes = [i for i in range(2, max_n + 1) if is_prime[i]]
    return primes, is_prime


def isWinner(x, nums):
    """
    Determines the winner of each round based on prime removal strategy.

    Args:
        x (int): The number of rounds to play.
        nums (list): A list of n values for each round.

    Returns:
        str: Name of the player who won the most rounds ("Maria" or "Ben"),
             or None if the result is inconclusive.
    """
    if x <= 0 or not nums:
        return None

    max_n = max(nums)
    primes, is_prime = sieve_of_eratosthenes(max_n)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        primes_count = 0
        used = [False] * (n + 1)

        for prime in primes:
            if prime > n:
                break

            if not used[prime]:
                primes_count += 1

                for multiple in range(prime, n + 1, prime):
                    used[multiple] = True

        if primes_count % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
