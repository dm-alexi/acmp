with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = map(int, f.readline().split())
    maxmin = -1000
    d = [-1000] * m
    while n:
        n -= 1
        p = [int(x) for x in f.readline().split()]
        maxmin = max(maxmin, min(p))
        for i in range(m):
            if p[i] > d[i]:
                d[i] = p[i]
    q.write(' '.join((str(maxmin), str(min(d)))))
