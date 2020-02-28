with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, d, k = (int(x) for x in f.readline().split())
    q.write(str(d * (k * (m + n) - d * m * n)))
