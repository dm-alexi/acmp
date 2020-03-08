with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    s = [f.readline().strip() for i in range(n)]
    q.write(str(sum(1 if s[i][j] != '*' and (i == 0 or s[i - 1][j] != '*') and (i == n - 1 or s[i + 1][j] != '*') and (j == 0 or s[i][j - 1] != '*') and (j == m - 1 or s[i][j + 1] != '*') else 0 for j in range(m) for i in range(n))))
