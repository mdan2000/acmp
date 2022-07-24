from math import factorial as f

n = int(input())


def choose(n, k):
    return f(n) // (f(k) * f(n - k))

ans = 0

sign = 1

for i in range (n, 0, -1):
    ans += f(i) * choose(n, i) * sign
    sign = -sign

print(ans + sign)
