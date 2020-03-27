with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    d = 1000 * m + 1
    for _ in range(n):
        t = f.readline().strip()
        g = sum(int(x) for x in f.readline().split())
        if g < d:
            d, s = g, t
    q.write(s)
