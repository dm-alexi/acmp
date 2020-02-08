with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(x) for x in f.read().split()]
    i = n - 1
    while i > 0 and p[i] < p[i - 1]:
        i -= 1
    if i:
        k = p.index(min(x for x in p[i:] if x > p[i - 1]))
        p[k], p[i - 1] = p[i - 1], p[k]
        p, s = p[:i], p[i:]
        s.sort()
        p.extend(s)
    else:
        p.reverse()
    q.write(" ".join(str(x) for x in p))
