with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    p = [int(x) for x in f.readline().split() if int(x) > 0]
    p.sort()
    n = len(p)
    s = sum(p) if m >= n else sum(p[n - m:])
    q.write(str(s))
