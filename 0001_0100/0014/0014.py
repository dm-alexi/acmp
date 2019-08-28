with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = (int(x) for x in f.read().split())
    m, n = a, b
    while n:
        m, n = n, m % n
    q.write(str(a // m * b))
