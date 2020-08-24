with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = map(int, f.readline().split())
    t = [[int(x) for x in f.readline().split()] for i in range(n)]
    for i in range(1, n):
        t[i][0] += t[i - 1][0]
    for i in range(1, m):
        t[0][i] += t[0][i - 1]
    for i in range(1, n):
        for j in range(1, m):
            t[i][j] += min(t[i - 1][j], t[i][j - 1])
    q.write(str(t[n - 1][m - 1]))
