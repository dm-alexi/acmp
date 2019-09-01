def dist(a, b):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5
 
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, c, p = (int(x) for x in f.readline().split())
    dots = []
    for i in range(n + 1):
        dots.append([int(x) for x in f.readline().split()])
    xs = [x[0] for x in dots]
    ys = [x[1] for x in dots]
    a = (sum(xs) / n, sum(ys) / n)
    m = (dots[0], dist(dots[0], a))
    for dot in dots[1:-1]:
        if dist(dot, a) < m[1]:
            m = (dot, dist(dot, a))
    q.write("YES" if (sum(dist(m[0], dot) for dot in dots) * c <= p) else "NO")
