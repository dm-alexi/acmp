with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [0, 1] * n
    i = 3
    while i * i < 2 * n:
        if p[i]:
            for j in range(i * i, 2 * n, 2 * i):
                p[j] = 0
        i += 2
    q.write(str(sum(p[n + 1 :])))
