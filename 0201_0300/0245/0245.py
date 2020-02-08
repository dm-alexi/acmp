with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = 0
    n = int(f.readline())
    if n > 0:
        p = [int(x) for x in f.read().split()]
        p.sort()
        s = p[0]
        if n > 1:
            s += p[1]
            c = s
            i, j = 2, 0
            while i < n:
                if p[i] <= p[j] + p[j + 1]:
                    c, i = c + p[i], i + 1
                else:
                    if c > s:
                        s = c
                    c, j = c - p[j], j + 1
            if c > s:
                s = c
    q.write(str(s))
