with open("input.txt", "r") as f, open("output.txt", "w") as q:
    p = [int(x) for x in f.read().split()[1:]]
    s = 0
    while p:
        m = p.index(max(p))
        s += (m + 1) * p[m]
        p = p[m + 1:]
    q.write(str(s))
