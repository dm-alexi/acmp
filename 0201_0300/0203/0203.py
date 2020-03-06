def kmp(s, t):
    n, m = len(s), len(t)
    p = [0]
    k = 0
    for i in range(1, n):
        while k > 0 and s[i] != s[k]:
            k = p[k - 1]
        if s[i] == s[k]:
            k += 1
        p.append(k)
    k = 0
    for i in range(m):
        while k > 0 and (k >= n or s[k] != t[i]):
            k = p[k - 1]
        if s[k] == t[i]:
            k += 1
        if k == n:
            return i - n + 1
    return -1

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, t = f.read().split()
    t += t[:len(s)]
    q.write(str(kmp(s, t)))
    
