with open("input.txt", "r") as f, open("output.txt", "w") as q:
    k = float(f.read())
    n, s = 2, 0
    while s < k:
        s += 1 / n
        n += 1
    q.write(str(n - 2) + " card(s)")
