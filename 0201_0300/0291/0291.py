with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    t = []
    for i in range(n + 1):
        s = f.readline().strip()
        t.append({x : s.count(x) for x in s})
    q.write(str(sum((False not in (l in t[n] and x[l] <= t[n][l] for l in x)) for x in t[:n])))
