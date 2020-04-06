def dist(a, b):
    return ((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1])) ** 0.5

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = (0, 0)
    t = 0
    for s in f.readlines()[1:]:
        b = tuple(int(x) for x in s.split())
        t += dist(a, b)
        a = b
    q.write(f"{t + dist(a, (0, 0)):.3f}")
