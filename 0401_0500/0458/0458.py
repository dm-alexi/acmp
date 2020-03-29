with open("input.txt", "r", encoding="koi8_r") as f, open("output.txt", "w", encoding="koi8_r") as q:
    n = int(f.readline())
    p = [int(x) - 1 for x in f.readline().split()]
    s = f.readline().strip()
    m = len(s)
    t = [None for i in range(m)]
    g = (x for x in s)
    for i in range(n):
        for j in range(p[i], m, n):
            t[j] = next(g)
    q.write(''.join(t))
