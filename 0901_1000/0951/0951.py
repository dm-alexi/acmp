def dist(a, b):
    return (a[0] - b[0] if a[0] > b[0] else b[0] - a[0]) + (a[1] - b[1] if a[1] > b[1] else b[1] - a[1])

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    tmp = [int(x) for x in f.readline().split()]
    s = []
    for i in range(tmp[0]):
        s.append((tmp[2 * i + 1], tmp[2 * i + 2]))
    r = 0
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            p = dist((i, j), s[0])
            if p <= r:
                continue
            for k in s[1:]:
                t = dist((i, j), k)
                if t < p:
                    p = t
                if p <= r:
                    break
            if p > r:
                r = p
    q.write(str(r))
