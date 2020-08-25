with open("input.txt", "r") as f, open("output.txt", "w") as q:
    t = [[0] * 101 for i in range(101)]
    d = ((0, 1), (1, 0), (0, -1), (-1, 0))
    x, y, k, l = 50, 50, 0, 0
    t[x][y] = 1
    for c in f.read().strip():
        if c == 'L':
            l = (l + 3) % 4
        elif c == 'R':
            l = (l + 1) % 4
        else:
            x += d[l][0]
            y += d[l][1]
            t[x][y] += 1
            k += 1
            if t[x][y] > 1:
                break
    q.write(str(k) if t[x][y] > 1 else "-1")
