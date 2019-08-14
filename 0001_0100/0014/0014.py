with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = (int(x) for x in f.read().split())
    m, n = a, b
    while m and n:
        if m > n:
            m %= n
        else:
            n %= m
    q.write(str(a // (n + m) * b))
