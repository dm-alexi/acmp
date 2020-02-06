V = "IVXLCDM/"
M = [1, 5, 10, 50, 100, 500, 1000]

def derome(s):
    i, n = len(s) - 1, 0
    while i >= 0:
        k, g = V.find(s[i]), V.find(s[i - 1])
        n += M[k]
        if i and g < k:
            n -= M[g]
            i -= 1
        i -= 1
    return n

def rome(n):
    s = []
    for i in range(6, -1, -1):
        if n >= M[i]:
            s.extend(V[i] * (n // M[i]))
            n %= M[i]
        for j in range(0, 5, 2):
            if n > M[j] and n + M[j] >= M[i]:
                s.extend((V[j], V[i]))
                n -= M[i] - M[j]
    return "".join(s)
            
from math import gcd
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    if s.count("/") != 1 or not set(s).issubset(set(V)):
        q.write("ERROR")
    else:
        a, b = (derome(x) for x in s.split("/"))
        d = gcd(a, b)
        a, b = a // d, b // d
        q.write("/".join((rome(a), rome(b))) if b > 1 else rome(a))
        
