def eq(s, n, p, t, m):
    j = 0;
    for i in range(m):
        if p + j >= n:
            return False
        if t[i].isspace() and s[p + j].isspace():
            while p + j + 1 < n and s[p + j + 1].isspace():
                j += 1
        elif t[i] != s[p + j].lower():
            return False
        j += 1
    return True

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    t = f.readline().strip().lower()
    s = [x for x in f.read()]
    m, n = len(t), len(s)
    p = 0
    while p < n - m:
        if eq(s, n, p, t, m):
            s.insert(p, "@")
            n += 1
            p += 1
        p += 1
        while p < n and s[p].isspace():
            p += 1
    q.write(''.join(s))
