with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    q.write(str(n * n - 3 * n + 2))
