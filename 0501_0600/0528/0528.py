with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = (int(x) for x in f.read().split())
    q.write(str(n + (2 + (2 + k) * (n - 2)) * (k - 1) // 2))
