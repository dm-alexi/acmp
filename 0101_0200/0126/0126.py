with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = [int(x) for x in f.read().split()]
    s = m[1] + m[2] + m[n + 2]
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1, n):
                if m[i * n + j] + m[j * n + k] + m[k * n + i] < s:
                    s = m[i * n + j] + m[j * n + k] + m[k * n + i]
    q.write(str(s))
