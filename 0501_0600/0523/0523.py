def vc(a, p):
    v, s = 1, 0
    for x in a:
        s += x
        if s > p:
            v, s = v + 1, x
    return v

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    a = [int(x) for x in f.readline().split()]
    k = int(f.read())
    l, r = max(a), sum(a)
    p, pmax = (l + r) // 2, l
    while l < r:
        c = vc(a, p)
        if c == k:
            break
        elif c > k and vc(a, p + 1) <= k:
            p += 1
            break
        elif c < k:
            l, p = p + 1, (p + r) // 2
        else:
            r, p = p, (p + l) // 2
    while p > pmax and vc(a, p -1) <= k:
        p -= 1
    q.write(str(p))
