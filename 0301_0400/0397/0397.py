with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    n, a, b = len(s), min(s), max(s)
    if a != b:
        l = [(i, 0) for i in range(n) if s[i] == a]
        l.extend((i, 1) for i in range(n) if s[i] == b)
        l.sort()
        for i in range(1, len(l)):
            if l[i][1] != l[i - 1][1] and l[i][0] - l[i - 1][0] < n:
                n, d = l[i][0] - l[i - 1][0], i - 1
        a = s[l[d][0] : l[d + 1][0] + 1]
    q.write(a)
