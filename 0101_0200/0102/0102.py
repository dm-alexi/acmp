def same_side(g, h, s, t):
    a, b, c = t[1] - s[1], s[0] - t[0], t[0] * s[1] - t[1] * s[0]
    return (a * g[0] + b * g[1] + c) * (a * h[0] + b * h[1] + c) >= 0

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = [int(x) for x in f.readline().split()]
    b = [int(x) for x in f.readline().split()]
    c = [int(x) for x in f.readline().split()]
    d = [int(x) for x in f.readline().split()]
    q.write("In" if same_side(d, a, b, c) and same_side(d, b, c, a) and same_side(d, c, a, b) else "Out")
