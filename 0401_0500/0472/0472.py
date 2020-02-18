from collections import Counter
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    d = Counter(int(x) for x in f.read().split())
    p = sorted(list(d.keys()))
    for i in range(1, len(p)):
        if m <= (p[i] - p[i - 1]) * d[p[i - 1]]:
            s = p[i - 1] + m // d[p[i - 1]]
            m = 0
            break
        m -= (p[i] - p[i - 1]) * d[p[i - 1]]
        d[p[i]] = d[p[i]] + d[p[i - 1]]
    if m:
        s = p[-1] + m // n
    q.write(str(s))
