with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, p, l = (int(x) for x in f.readline().split())
    q.write(f"{m + p + l - n} {n - p - l} {n - m - l}")
