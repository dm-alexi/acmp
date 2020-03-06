with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    if n == 1:
        q.write(f"1\n{f.readline()}")
    else:
        p = [int(x) for x in f.readline().split()]
        a = [None for i in range(n)]
        a[n - 1] = p[n - 1]
        for i in range(n - 2, 0, -1):
            a[i] = p[i] if p[i] > a[i + 1] else a[i + 1]
        s = [p[0]]
        m = p[0]
        for i in range(1, n - 1):
            if p[i] > m:
                m = p[i]
            if p[i] >= m or p[i] >= a[i]:
                s.append(p[i])
        s.append(p[n - 1])
        q.write(str(len(s)) + '\n' + ' '.join(str(x) for x in s))
