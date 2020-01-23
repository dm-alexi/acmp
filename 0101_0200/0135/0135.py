with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = [int(x) for x in f.read().split()]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if m[i * n + k] + m[k * n + j] < m[i * n + j]:
                    m[i * n + j] = m[i * n + k] + m[k * n + j]
    q.write("\n".join((" ".join(str(m[i * n + j]) for j in range(n))) for i in range(n)))
