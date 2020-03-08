with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    s = 0
    p = []
    for i in range(n):
        p.append([int(x) for x in f.readline().split()])
    row = [min(p[i][j] for j in range(m)) for i in range(n)]
    col = [max(p[i][j] for i in range(n)) for j in range(m)]
    for i in range(n):
        for j in range(m):
            if p[i][j] == row[i] and p[i][j] == col[j]:
                s += 1
    q.write(str(s))
