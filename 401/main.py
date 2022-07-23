from math import factorial as f

def choose(n, k):
    return f(n) // (f(k) * f(n - k))

def solve(n, k):
    k += 1
    return choose(n + k - 1, n)

n, a, b = map(int, input().split())

print(solve(a, n) * solve(b, n))
