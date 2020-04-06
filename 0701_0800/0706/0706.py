with open("input.txt", "r") as f, open("output.txt", "w") as q:
    r, x, y = (int(x) for x in f.read().split())
    q.write(str(abs(x * r / (2 * r - y))))
