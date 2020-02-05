from math import gcd
from functools import reduce

def get_primes(a, b):
    dct = {x: True for x in range(a, b + 1)}
    while a * a <= b:
        if dct[a]:
            y = a * a
            while y <= b:
                dct[y] = False
                y += a
        a += 1
    lst = [x for x, y in dct.items() if y]
    return lst

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    for n in [int(x) for x in f.read().split()][1:]:
        p = get_primes(2, 9999)
        l = []
        for i in p:
            k = 0
            while n % i == 0:
                n, k = n // i, k + 1
            if k:
                l.append(k)
            if n < i:
                break
        q.write("YES\n" if n == 1 and reduce(gcd, l) > 1 else "NO\n")
            
