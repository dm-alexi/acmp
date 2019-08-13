def bet(w):
    x, y, x1, y1, x2, y2, x3, y3 = [int(x) for x in w]
    if x1 == x2:
        return x <= x1 and x >= x3 or x >= x1 and x <= x3
    if y1 == y2:
        return y <= y1 and y >= y3 or y >= y1 and y <= y3
    k = (y2 - y1) / (x2 - x1)
    return (k * (x - x1) - (y - y1)) * (k * (x - x3) - (y - y3)) <= 0

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [x.split() for x in f.readlines()[1:]]
    k = 0
    for t in s:
        if bet(t[:8]) and bet(t[:4] + t[8:] + t[4:6]):
            k += 1
    q.write(str(k))
