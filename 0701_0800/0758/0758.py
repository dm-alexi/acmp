with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(x) for x in f.readline().split()]
    p.sort()
    if n < 3:
        t = p[n - 1]
    else:
        t = 0
        while n > 3:
            t += min(p[0] + 2 * p[1] + p[n - 1], p[n - 1] + p[n - 2] + 2 * p[0])
            n -= 2
        t += p[0] + p[1] + p[2] if n == 3 else p[1]
    q.write(str(t))
