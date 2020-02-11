with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    op, m = 0, 0
    p = [(0, -2), (1440, 2)]
    for i in range(n):
        s = [int(x) for x in f.readline().split()]
        a, b = s[0] * 60 + s[1], s[2] * 60 + s[3]
        if a != b:
            p.extend([(a, 1), (b, -1)])
        if a >= b:
            op += 1
    p.sort()
    k = len(p)
    for i in range(1, k):
        if op == n:
            m += p[i][0] - p[i - 1][0]
        op += p[i][1]
    q.write(str(m))
