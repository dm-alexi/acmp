def upd(p, n, m, x, y):
    if x >= 0 and y >= 0 and x < m and y < n and p[y][x] != '*':
        p[y][x] += 1

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, k = (int(x) for x in f.readline().split())
    p = [[0 for j in range(m)] for i in range(n)]
    for i in range(k):
        y, x = (int(a) - 1 for a in f.readline().split())
        p[y][x] = '*'
        upd(p, n, m, x - 1, y - 1);
        upd(p, n, m, x - 1, y);
        upd(p, n, m, x - 1, y + 1);
        upd(p, n, m, x, y - 1);
        upd(p, n, m, x, y + 1);
        upd(p, n, m, x + 1, y - 1);
        upd(p, n, m, x + 1, y);
        upd(p, n, m, x + 1, y + 1);
    for l in p:
        for i in range(m):
            l[i] = '.' if l[i] == 0 else str(l[i])
    q.write('\n'.join(''.join(x) for x in p))
