with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    p = [[int(x) for x in f.readline().split()] for i in range(n)]
    w = sum(p[i][j] != p[i + 1][j] for j in range(m) for i in range(n - 1)) + sum(p[i][j] != p[i][j + 1] for j in range(m - 1) for i in range(n))
    c = sum(p[i][j] != p[i + 1][j] or p[i][j] != p[i][j + 1] or p[i][j] != p[i + 1][j + 1] for j in range(m - 1) for i in range(n - 1))
    q.write(str((0.8 * w + 0.2 * c) * 0.6))
    
