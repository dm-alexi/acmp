with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = (int(x) for x in f.readline().split())
    m = [[0, set()] for x in range(n + 1)]
    s = [int(x) for x in f.read().split()]
    i = 0
    while s[i] != 0:
        a, b = s[i] if m[s[i]][0] == 0 else m[s[i]][0], s[i + 1]
        i += 2
        for x in m[b][1]:
            m[x][0] = a
        m[b][0] = a
        m[a][1].add(b)
        m[a][1] = set.union(m[a][1], m[b][1])
        set.clear(m[b][1])
    q.write("Yes" if len(m[k][1]) == n - 1 else "No")
