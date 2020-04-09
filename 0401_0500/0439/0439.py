with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, p = (int(x) for x in f.readline().split())
    q.write(str(1 / ((1 - p / 100) / n + p / 100)))
