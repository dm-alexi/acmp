with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = 2 * int(f.readline())
    d = [int(x) for x in f.read().split()]
    p = [(d[i], -1 if i % 2 else 1) for i in range(n)]
    p.sort()
    s = p[0][1]
    l = 0
    for i in range(1, n):
        if s > 0:
            l += p[i][0] - p[i - 1][0]
        s += p[i][1]
    q.write(str(l))
    
