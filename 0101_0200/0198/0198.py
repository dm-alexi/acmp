from math import floor
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = [[float(x) for x in f.readline().split()] for i in range(n)]
    a = [None for i in range(n)]
    for i in range(n):
        if m[i][i] == 0:
            for j in range(i + 1, n):
                if m[j][i] != 0:
                    m[i], m[j] = m[j], m[i]
                    break
        for j in range(i + 1, n + 1):
            m[i][j] /= m[i][i]
        m[i][i] = 1
        for j in range(i + 1, n):
            t = m[j][i]
            for k in range(i + 1, n + 1):
                m[j][k] -= m[i][k] * t
            m[j][i] = 0
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n):
            m[i][n] -=m[i][j] * a[j]
        a[i] = floor(m[i][n] + 0.5)
    q.write(' '.join(str(x) for x in a))
