with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    i = int(((n * 8 - 3) ** 0.5 - 1) // 2 + 1)
    while i > 1 and not (n > (i - 1) * i / 2 and (n - ((i - 1) * i / 2)) % i == 0):
        i -= 1
    q.write(str(i))
