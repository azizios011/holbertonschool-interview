
---

# Prime Game

This Python script implements a solution to the **Prime Game**, a combinatorial game played between two players, Maria and Ben. In each round, given a set of consecutive integers starting from 1 up to a number `n`, the players take turns picking a prime number and removing that prime and all of its multiples from the set. Maria always goes first, and both players play optimally. A player loses if they cannot make a valid move (i.e., no prime numbers are left to choose from).

The problem is to determine who wins the most rounds after playing `x` rounds of the game, where `n` varies in each round. If Maria wins the most rounds, the function returns "Maria". If Ben wins the most rounds, the function returns "Ben". If the winner cannot be determined (i.e., both win the same number of rounds), it returns `None`.

## Code Explanation:

### Prime Number Generation (Sieve of Eratosthenes):

The script begins by precomputing prime numbers up to the largest possible value of `n` in any round. This is done using the **Sieve of Eratosthenes**, which efficiently marks non-prime numbers in a boolean array.

```python
def sieve_of_eratosthenes(max_n):
    """Generates a list of primes up to max_n using the Sieve of Eratosthenes"""
    is_prime = [True] * (max_n + 1)
    is_prime[0] = is_prime[1] = False  # 0 and 1 are not primes

    for i in range(2, int(max_n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, max_n + 1, i):
                is_prime[j] = False

    primes = [i for i in range(2, max_n + 1) if is_prime[i]]
    return primes, is_prime
```

- **is_prime**: A boolean list where `True` indicates the number is prime. Initially, all numbers from 2 to `max_n` are assumed to be prime.
- For each prime `i`, all its multiples are marked as `False` (non-prime).
- The list of primes is then extracted and returned.

### Main Function: `isWinner`

This function determines the winner of the game based on the number of rounds played (`x`) and the list of values (`nums`) which represent the upper bound `n` for each round.

```python
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
```

- If no rounds are played (`x <= 0`), or the input list is empty, the function immediately returns `None`.

### Precompute Primes:

The script computes all the primes up to the largest number in `nums` to avoid recalculating primes in each round.

```python
    max_n = max(nums)
    primes, is_prime = sieve_of_eratosthenes(max_n)
```

- The **sieve_of_eratosthenes** function is called to compute the primes and an array (`is_prime`) to check if a number is prime.

### Game Simulation:

For each round, the game is simulated by counting how many prime numbers can be picked before no more moves are possible. Maria wins if an odd number of primes are picked, and Ben wins if an even number of primes are picked.

```python
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
```

- For each round, a `used` array tracks which numbers have been removed from the set.
- The primes are iterated over, and if a prime has not been used, it's picked and marked along with all its multiples.
- If the number of primes picked is odd, Maria wins the round; otherwise, Ben wins.

### Determine the Overall Winner:

At the end of all rounds, the function compares how many rounds each player won.

```python
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
```

- If Maria wins more rounds than Ben, the function returns `"Maria"`.
- If Ben wins more rounds, the function returns `"Ben"`.
- If both win the same number of rounds, the function returns `None`.

### Example Usage:

You can test the solution using the following example:

```python
# Example Test Case
x = 3
nums = [4, 5, 1]
print("Winner: {}".format(isWinner(x, nums)))
# Expected output: "Ben"
```
