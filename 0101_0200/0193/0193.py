with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, k = (int(x) for x in f.readline().split())
    p = [None for i in range(k)]
    for i in range(n):
        s = [int(x) for x in f.readline().split()]
        for j in range(m):
            if s[j] > 0:
                a = s[j] - 1
                if not p[a]:
                    p[a] = [j, n - i - 1, j + 1, n - i]
                    d = a
                    continue
                if j < p[a][0]:
                    p[a][0] = j
                if j + 1 > p[a][2]:
                    p[a][2] = j + 1
                if n - i - 1 < p[a][1]:
                    p[a][1] = n - i -1
    q.write("\n".join(" ".join(str(x) for x in line) if line else " ".join(str(x) for x in p[d]) for line in p))
