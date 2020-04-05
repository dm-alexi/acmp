with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, k = (int(x) for x in f.read().split())
    for i in range(n - 1):
        m, k = k - m, m
    q.write(f"{m} {k}")
