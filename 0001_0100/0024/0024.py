with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.read().split())
    q.write(str(1 if m == 0 else n if m == 1 else n // (m - 1) * (2 * n - m + 1 + n // (m - 1) * (1 - m)) // 2))
