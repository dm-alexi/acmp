with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = map(int, f.readline().split())
    k = [int(x) for x in f.read().split()]
    p = [0] * (m * n)
    p[0] = 1
    for i in range(n * m - 1):
        if p[i] and i % m + k[i] < m:
            p[k[i] + i] += p[i]
        if p[i] and i / m + k[i] < n:
            p[k[i] * m + i] += p[i]
    q.write(str(p[-1]))
