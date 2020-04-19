with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    a, n = n // 144, n % 144
    if n > 133:
        a, n = a + 1, 0
    b, n = n // 12, n % 12
    if n > 9:
        b, n = b + 1, 0
    q.write(f"{a} {b} {n}")
