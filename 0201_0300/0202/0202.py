with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, t = f.read().split()
    n, m = len(s), len(t)
    p = [0]
    k = 0
    d = []
    for i in range(1, m):
        while k > 0 and t[i] != t[k]:
            k = p[k - 1]
        if t[i] == t[k]:
            k += 1
        p.append(k)
    k = 0
    for i in range(n):
        while k > 0 and (k >= m or t[k] != s[i]):
            k = p[k - 1]
        if t[k] == s[i]:
            k += 1
        if k == m:
            d.append(str(i - m + 1))
    q.write(' '.join(d))
