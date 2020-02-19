with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = list(f.readline().strip())
    t = list(f.readline().strip())
    r = []
    a, b = 0, 0
    while a < len(s) and b < len(t):
        if s[a] < t[b]:
            r.append(s[a])
            a += 1
        elif s[a] > t[b]:
            r.append(t[b])
            b += 1
        else:
            i, j = a + 1, b + 1
            while i < len(s) and j < len(t) and s[i] == t[j]:
                i, j = i + 1, j + 1
            if i < len(s) and (j == len(t) or s[i] < t[j]):
                r.append(s[a])
                a += 1
            else:
                r.append(t[b])
                b += 1
    r.extend(s[a:] if a < len(s) else t[b:])
    q.write("".join(r))
