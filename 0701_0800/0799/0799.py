with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(x) for x in f.readline().split()]
    s = [p[i] if p[i] % 10 == 5 and p[i] > p[i + 1] else 0 for i in range(p.index(max(p)) + 1, n - 1)]
    r = max(s) if s else 0
    if r:
        p.sort(reverse=True)
        r = p.index(r) + 1
    q.write(str(r))
