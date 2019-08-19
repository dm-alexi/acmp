with open("input.txt", "r") as f, open("output.txt", "w") as q:
    x1, y1, x2, y2, xa, ya = map(int, f.read().split())
    a = (2 * x1 - xa, ya) if x1 == x2 else (xa, 2 * y1 - ya)
    q.write(str(a[0]) + ' ' + str(a[1]))
