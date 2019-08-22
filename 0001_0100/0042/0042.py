with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    k = 1
    while n > 4:
        k *= 3
        n -= 3
    q.write(str(k * n))
