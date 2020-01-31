from math import inf
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = [int(x) if x != '0' else inf for x in f.read().split()]
    for i in range(n):
        if m[i * n + i] > 0:
            m[i * n + i] = 0
    r = ['1' for i in range(n * n)]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if m[i * n + k] < inf and m[k * n + j] < inf and m[i * n + k] + m[k * n + j] < m[i * n + j]:
                    m[i * n + j] = m[i * n + k] + m[k * n + j]
    for i in range(n):
        for j in range(n):
            if m[i * n + j] == inf:
                r[i * n + j] = '0'
            elif any(m[k * n + k] < 0 and m[i * n + k] < inf and m[k * n + j] < inf for k in range(n)):
                r[i * n + j] = '2'
    q.write("\n".join((" ".join(r[i * n + j] for j in range(n))) for i in range(n)))
