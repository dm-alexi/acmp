with open("input.txt", "r") as f, open("output.txt", "w") as q:
    m, n = (int(x) for x in f.read().split())
    while n:
        m, n = n, m % n
    q.write(str(m))
