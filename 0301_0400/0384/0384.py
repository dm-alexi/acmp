def fiblast(a):
    if a == 0:
        return 0
    if a < 3:
        return 1
    r1, r2, i = 1, 1, 2
    while i < a:
        r1, r2, i = (r1 + r2) % 1000000000, r1, i + 1
    return r1  

from math import gcd
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = (int(x) for x in f.readline().split())
    q.write(str(fiblast(gcd(a, b))))
        
