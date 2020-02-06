from math import gcd
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, x, y = (int(x) for x in f.readline().split())
    x, y = (y, x) if x > y else (x, y)
    n -= 1
    p = x * y // gcd(x, y)
    k = p // y  + p // x
    t = x + n // k * p
    n %= k
    p = 0
    while n:
        if n * x - p <= y:
            t += n * x - p
            break
        else:
            t += y
            n -= 1 + (y + p) // x
            p = (y + p) % x
    q.write(str(t))
