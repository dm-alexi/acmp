with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read()
    k = 0
    for x in (">>-->", "<--<<"):
        n = s.find(x, 0)
        while n > -1:
            k += 1
            n = s.find(x, n + 1)
    q.write(str(k))
