with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    p = [f.readline().strip() for i in range(n)]
    s = sum(1 if p[i][j] == '#' and (i == 0 or p[i - 1][j] == '.') and (j == 0 or p[i][j - 1] == '.') else 0 for j in range(m) for i in range(n))
    q.write(str(s))
