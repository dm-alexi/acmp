with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    k = int(f.readline())
    t = [[0 for j in range(m)] for i in range(n)]
    s = 0
    for i in range(k):
        p, y, x = (int(a) - 1 for a in f.readline().split())
        if x >= 0 and y >= 0 and x < m - 1 and y < n - 1:
            if p == 0 and t[y][x + 1] + t[y + 1][x] + t[y + 1][x + 1] == 0:
                t[y][x + 1], t[y + 1][x], t[y + 1][x + 1], s = 1, 1, 1, s + 3
            elif p == 1 and t[y][x] + t[y + 1][x] + t[y + 1][x + 1] == 0:
                t[y][x], t[y + 1][x], t[y + 1][x + 1], s = 1, 1, 1, s + 3
            elif p == 2 and t[y][x] + t[y][x + 1] + t[y + 1][x + 1] == 0:
                t[y][x], t[y][x + 1], t[y + 1][x + 1], s = 1, 1, 1, s + 3
            elif p == 3 and t[y][x] + t[y][x + 1] + t[y + 1][x] == 0:
                t[y][x], t[y][x + 1], t[y + 1][x], s = 1, 1, 1, s + 3
    q.write(str(s))
