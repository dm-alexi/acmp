def dist(a, b):
    return ((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1])) ** 0.5

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    g = tuple(int(x) for x in f.readline().split())
    d = tuple(int(x) for x in f.readline().split())
    n = int(f.readline())
    i = 1
    while i <= n:
        t = tuple(int(x) for x in f.readline().split())
        if (2 * dist(g, t) <= dist(d, t)):
            break
        i += 1
    q.write("NO" if i > n else f"{i}")
