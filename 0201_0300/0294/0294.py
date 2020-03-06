with open("input.txt", "r") as f, open("output.txt", "w") as q:
    k1, l1, m1, k2, l2, m2 = (int(x) for x in f.read().split())
    a = min(k1 * (100 - l1), k2 * (100 - l2)) // 100
    q.write(str((k1 - a) * m1 + (k2 - a) * m2))
