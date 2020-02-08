from math import gcd
from functools import reduce
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    r = 1
    if n > 1:
        p = [int(x) - 1 for x in f.readline().split()]
        t = [1] * n
        for i in range(n):
            if p[i] != i:
                j = p[i]
                t[i] = 2
                while p[j] != i:
                    j = p[j]
                    t[i] += 1
        r = reduce(lambda x, y: x * y // gcd(x, y), t)
    q.write(str(r))
