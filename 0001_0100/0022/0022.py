with open("input.txt", "r") as f, open("output.txt", "w") as q:
    x = int(f.read())
    n = 0
    while x:
        n += x % 2
        x //= 2
    q.write(str(n))
