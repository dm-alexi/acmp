def same_side(g, h, s):
    a, b, c = s[3] - s[1], s[0] - s[2], s[2] * s[1] - s[3] * s[0]
    return (a * g[0] + b * g[1] + c) * (a * h[0] + b * h[1] + c) > 0

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    t = [int(x) for x in f.readline().split()]
    n = int(f.readline())
    p = []
    for i in range(n):
        a = [int(x) for x in f.readline().split()]
        if same_side(t, a[:2], a[2:]) and same_side(t, a[4:], a[:4]) and same_side(t, a[2:4], a[:2] + a[4:]):
            p.append(str(i + 1))
    q.write(str(len(p)) + "\n" + " ".join(x for x in p))
