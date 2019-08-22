with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    d = n
    s = sum(int(x) for x in str(n))
    for i in (x for x in range(2, n // 2 + 1) if n % x == 0):
        t = sum(int(x) for x in str(i))
        if t > s or t == s and i < d:
            d, s = i, t
    q.write(str(d))
