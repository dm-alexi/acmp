with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    b = 0
    if n:
        n -= 1
        a, b = 0, 1
        while n:
            a, b = b, a + b
            n -= 1
    q.write(str(b))
