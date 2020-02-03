from math import inf
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = [[int(x) if x != "100000" else inf for x in f.readline().split()] for i in range(n)]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if m[i][k] < inf and m[k][j] < inf and m[i][k] + m[k][j] < m[i][j]:
                    m[i][j] = m[i][k] + m[k][j]
    q.write("YES" if any(m[i][i] < 0 for i in range(n)) else "NO")
