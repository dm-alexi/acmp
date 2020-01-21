with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, a, b = (int(x) for x in f.read().split())
    while a != b:
        if a > b:
            a //= 2
        else:
            b //= 2
    q.write(str(a))
