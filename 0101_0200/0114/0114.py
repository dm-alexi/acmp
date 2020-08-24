with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = map(int, f.read().split())
    r, m = (k - 1) * (k - 1), k - 1
    for i in range(n - 2):
        m, r = r, (r + m) * (k - 1)
    q.write(str(r + m))
