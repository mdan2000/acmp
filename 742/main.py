from math import factorial as f

def choose(n, k):
    return f(n) // (f(k) * f(n - k))


n = int(input())
p = choose(n, 2)
print(3**p)
