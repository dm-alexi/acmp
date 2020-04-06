with open("input.txt", "r") as f, open("output.txt", "w") as q:
    x1, y1, x2, y2 = (int(x) for x in f.read().split())
    q.write(f"{((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ** 0.5:.5f}")
