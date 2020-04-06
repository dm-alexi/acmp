with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    q.write(str(n if n < 3 else n *(n - 1) * (n - 2)))
