with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = []
    k = 0
    for i in range(n):
        m.extend(int(x) for x in f.readline().split())
    p = [int(x) for x in f.read().split()]
    for i in range(n - 1):
        for j in range(i + 1, n):
            if m[i * n + j] and p[i] != p[j]:
                k += 1
    q.write(str(k))
