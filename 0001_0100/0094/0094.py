with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, k = (int(x) for x in f.read().split())
    q.write("1" if n >= m else "NO" if n <= k else str((m - n - 1) // (n - k) + 2))
