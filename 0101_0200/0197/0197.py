with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    d = len(str(n * n))
    v = False
    x, y = 0, 0
    t = [[None] * n for i in range(n)]
    for i in range(1, n * n + 1):
        t[x][y] = i
        if v:
            x, y, v = (x + 1, y, not v) if y == n - 1 else (x, y + 1, not v) if x == 0 else (x - 1, y + 1, v)
        else:
            x, y, v = (x, y + 1, not v) if x == n - 1 else (x + 1, y, not v) if y == 0 else (x + 1, y - 1, v)
    q.write("\n".join(" ".join("{:{}d}".format(x, d) for x in line) for line in t))
