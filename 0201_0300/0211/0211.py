def add(p, x, y, w, h, step, que):
    if x > 0 and p[y][x - 1] == 0:
        que.append((y, x - 1, step))
        p[y][x - 1] = step
    if x < w - 1 and p[y][x + 1] == 0:
        que.append((y, x + 1, step))
        p[y][x + 1] = step
    if y > 0 and p[y - 1][x] == 0:
        que.append((y - 1, x, step))
        p[y - 1][x] = step
    if y < h - 1 and p[y + 1][x] == 0:
        que.append((y + 1, x, step))
        p[y + 1][x] = step

from collections import deque
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    w, h = (int(x) + 2 for x in f.readline().split())
    p = [[0 for j in range(w)] for i in range(h)]
    for i in range(1, h - 1):
        s = f.readline()
        for j in range(1, w - 1):
            if s[j - 1] == 'X':
                p[i][j] = -1
    que = deque()
    x1, y1, x2, y2 = (int(x) for x in f.readline().split())
    while x1:
        res = 1 if (x1 == x2 and abs(y1 - y2) == 1) or (y1 == y2 and abs(x1 - x2) == 1) else 0
        if res == 0:
            que.clear()
            add(p, x1, y1, w, h, 1, que)
            while que:
                y, x, dist = que.popleft()
                if (x == x2 and abs(y - y2) == 1) or (y == y2 and abs(x - x2) == 1):
                    res = dist + 1
                    break
                add(p, x, y, w, h, dist + 1, que)
            for i in range(h):
                for j in range(w):
                    if p[i][j] > 0:
                        p[i][j] = 0
        q.write(f"{res}\n")
        x1, y1, x2, y2 = (int(x) for x in f.readline().split())
