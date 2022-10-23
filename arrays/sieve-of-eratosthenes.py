from math import sqrt, floor

n = int(input("Enter range: "))

primes = [True] * (n + 1)
primes[0], primes[1] = False, False

for i in range(2, round(sqrt(n)) + 1):
    if primes[i]:
        for j in range(i + i, n + 1, i):
            primes[j] = False

for i in range(n + 1):
    if primes[i]:
        print(f"{i}", end=" ")
print()
