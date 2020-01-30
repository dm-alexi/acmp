with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = [int(x) for x in f.read().split()]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if m[i * n + k] >=0 and m[k * n + j] >= 0 and \
                   (m[i * n + j] < 0 or m[i * n + k] + m[k * n + j] < m[i * n + j]):
                    m[i * n + j] = m[i * n + k] + m[k * n + j]
    q.write(str(max(m)))
