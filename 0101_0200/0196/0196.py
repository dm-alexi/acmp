with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    d = len(str(n * n))
    s = 1
    t = [[None] * n for i in range(n)]
    for l in range(n // 2 + 1):
        for i in range(l, n - l):
            t[l][i], s = s, s + 1
        for i in range(l + 1, n - l):
            t[i][n - l - 1], s = s, s + 1
        for i in range(n - l - 2, l - 1, -1):
            t[n - l - 1][i], s = s, s + 1
        for i in range(n - l - 2, l, -1):
            t[i][l], s = s, s + 1
    q.write("\n".join(" ".join("{:{}d}".format(x, d) for x in line) for line in t))
