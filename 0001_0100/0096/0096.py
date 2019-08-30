with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, y, x = (int(x) for x in f.read().split())
    k = 0
    while y != 1 and y != n and x != 1 and x != m:
        k += 2 * (m + n - 2)
        x, y = x - 1, y - 1
        n, m = n - 2, m - 2
    k += x if y == 1 else m + y - 1 if x == m else 2 * m + n - 1 - x if y == n else 2 * (m + n - 1) - y
    q.write(str(k))
