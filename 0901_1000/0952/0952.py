with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.read().split())
    q.write("Impossible" if m and n == 0 else f"{max(m, n)} {n + m - 1 if m > 0 else n}")
