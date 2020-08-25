with open("input.txt", "r") as f, open("output.txt", "w") as q:
    k, n = map(int, f.read().split())
    l = (0, 0, 0, 5, 5, 9, 10, 10, 14, 15, 18, 19, 20, 23, 24, 27, 28, 29, 32, 33)
    p = [k, 0, 0]
    for i in range(n - 1):
        p = [l[k] if k < 20 else (k // 10 - 1) * 18 + l[k % 20 + 10] if k % 20 < 10 else k // 20 * 36 + l[k % 20], p[0], p[1]]
        k = sum(p)
    q.write(str(k))
