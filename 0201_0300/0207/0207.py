with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    S = 2 ** -0.5
    p = [0, 0, 0, 0]
    for i in range(n):
        a, b = (int(x) for x in f.readline().split())
        if a < 5:
            p[a - 1] += b
        else:
            p[(a - 1) % 4] -= b
    q.write("{:.3f} {:.3f}".format(p[2] + S * (p[1] + p[3]), p[0] + S * (p[1] - p[3])))
