with open("input.txt", "r") as f, open("output.txt", "w") as q:
    x1, y1, x2, y2, x3, y3 = (float(x) for x in f.read().split())
    q.write(str(abs(((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2)))
