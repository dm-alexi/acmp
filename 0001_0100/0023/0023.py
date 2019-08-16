with open("input.txt", "r") as f, open("output.txt", "w") as q:
    x = int(f.read())
    n = 0
    for i in range(1, x // 2 + 1):
        if not x % i:
            n += i
    q.write(str(n + x))
